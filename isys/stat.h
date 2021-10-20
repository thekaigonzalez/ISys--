#include <iostream>
#include <map>
#include "prims.h"
#include "vstr.h"
#include "recog.h"

//var cpp = "hello!"
//print("hello!")
//system("memes")

int getLastIndex(const std::string &str, char ch) {
   for (int i = str.length() - 1; i >= 0; i--)
      if (str[i] == ch)
         return i;
   return -1;
}

const std::string WHITESPACE = " \n\r\t\f\v";
 
std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

std::map<std::string, std::string> varmem;


std::string ISys_Interp(std::string sss) 
{
    std::istringstream STAT_STREAM(sss);
    std::string keywd;
    if (UType(trim(sss)) == E_VAR) {
        STAT_STREAM >> keywd;

        if (keywd == "var") { /* verify */
            std::string name;
            std::string value;
            STAT_STREAM >> name;
            std::string ptr;
            
            getline(STAT_STREAM, ptr, '=');
            getline(STAT_STREAM, value, '\n');
            // if (IsString(trim(value))) {
            //     value = PrettyPrint(trim(value)); // turn value into C string
            // }
            value = ISys_Interp(trim(value));
            varmem[name] = value;
            return trim(value); // value is return code
        }
    } else if (UType(trim(sss)) == E_OTHER) {
        std::string fname;
        getline(STAT_STREAM, fname, '(');
        std::string fargs = "";
        getline(STAT_STREAM, fargs, ')');
        fargs = trim(fargs);
        if (fargs.empty())
            fargs = "Empty";
        int i = 0;
        if (trim(fargs)[0] != '\"') {
            /*
            if ( m.find("f") == m.end() ) {
                // not found
            } else {
                // found
            }
            */
            fargs = trim(fargs); /* reset to root eval */
        }
        //TODO: implement ISys++ functions
        if (funcmem.find(fname) != funcmem.end()) { 
            funcmem[fname](ISys_Interp(trim(fargs)), fargs);
        } else {
            std::cout << "Error: no such function called '" << fname << "'" << std::endl;
            return "Null";
        }
        return "inbuilt";
    } else if (UType(sss) == E_STRING) {
        CString s(trim(sss));
        return s.Parse();
    } else if (UType(sss) == E_INT) {
        if (varmem.find(split(trim(sss), ' ')[0]) != varmem.end()) {
           return varmem[split(trim(sss), ' ')[0]];
        } 
        return "\"" + std::to_string((int)ToInt(sss)) + "\"";
    } else if (UType(sss) == E_LIKELY) {
        /* if (trim(fargs)[0] != '\"') 
            if (varmem.find(split(fargs, ' ')[0]) != varmem.end()) {
                fargs = "\"" + varmem[split(fargs, ' ')[0]] + "\"";
            }
        } 
        */ // c
       if (varmem.find(split(trim(sss), ' ')[0]) != varmem.end()) {
           return varmem[split(trim(sss), ' ')[0]];
       }
    }
    return "Null";
}