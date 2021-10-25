#include <iostream>
#include <map>
#ifdef USE_STACK
#include "dlsearch.h"
#endif
#include "prims.h"
// #include "var.h" *&already included from baselib.h included from prims.h*
#include "vstr.h"
#include "recog.h"

//var cpp = "hello!"
//print("hello!")
//system("memes")

///somehow i need to find out how to implement a better arg parser.
//I basically need to turn this
// "i can use print('hello')" string)
//from this
// "i can use print('hello')"
//to
// "i can use print('hello')" string


int ifstate = 0;
int getLastIndex(const std::string &str, char ch) {
   for (int i = str.length() - 1; i >= 0; i--)
      if (str[i] == ch)
         return i;
   return -1;
}



#define create_glob_var(name, val) varmem[name] = val

std::string ISYSPP_INTERPRETER_VERSION(std::vector<std::string>) {
    return "Version 1.0.3-git-scm";
}
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
        if (trim(sss)[0] == '"') {
            CString ns(sss);
            return ns.Parse();
        }
        std::string fname;
        getline(STAT_STREAM, fname, '(');
        std::string fargs = last_parse(STAT_STREAM.str().substr(STAT_STREAM.str().find("(")), ')');
        // std::cout << fargs << std::endl;
        // std::cout << "Before/After Segfault" << std::endl;
        std::vector<std::string>argsv = last_arg(fargs);
        for (int i = 0; i < argsv.size() ; ++ i) {
            // std::cout << "arg: " <<  trim(argsv[i]) << std::endl;
            argsv[i] = ISys_Interp(trim(argsv[i]));
        }

       
        // fargs.pop_back();
        // fargs = trim(fargs);
        // std::cout << fargs << std::endl;
        if (fargs.empty())
            fargs = "None";
        int i = 0;
        //*NO LONGER TODO* implement ISys++ functions
        if (funcmem.find(fname) != funcmem.end()) { 
            funcmem[fname](argsv);
        } else {
            if (funcmemF.find(fname) != funcmemF.end()) { 
                // std::cout << "Found " << std::endl;
                return funcmemF[fname](argsv);
            } else {
                if (funcmemD.find(fname) != funcmemD.end()) { 
                    varglob["args"] = fargs;
                    std::string stat;
                    std::string fcontents = funcmemD[fname];
                    std::vector<std::string>Stats = split(fcontents, ';');
                    for (int i =0; i < Stats.size() ; ++ i)
                        Stats[i] = trim(Stats[i]);
                    for (const auto& stat : Stats) {
                        if (stat.length() > 0) {
                            ISys_Interp(stat);
                        }
                    }
                } else {
                    std::cout << "Error: no such function called '" << fname << "'" << std::endl;
                    return "Null";
                }
            }
        }
        return "<builtin function " + fname + ">";
    } else if (UType(trim(sss)) == E_STRING) {
        // std::cout << "string";
        CString s(trim(sss));
        return s.Parse();
    } else if (UType(trim(sss)) == E_INT) {
        if (varmem.find(split(trim(sss), ' ')[0]) != varmem.end()) {
           return varmem[split(trim(sss), ' ')[0]];
        } 
        return std::to_string((int)ToInt(sss));
    } else if (UType(trim(sss)) == E_LIKELY) {
        // std::cout << "other";
        if (sss == "true") {
            return "1";
        } else if (sss == "false") {
            return "0";
        } else {
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
        if (varmem.find(split(trim(sss), ' ')[0]) != varmem.end()) {
            return varmem[split(trim(sss), ' ')[0]];
        }
    } else if (UType(trim(sss)) == E_EVAL) {

        STAT_STREAM.str(sss.substr(sss.find("e")+1));
        return ISys_Interp(PrettyPrint(sss));
    } else if (UType(trim(sss)) == E_IF ) {
        
        STAT_STREAM >> keywd;
        std::string var;
        std::string value;
        getline(STAT_STREAM, var, '=');
        var = trim(var);
        getline(STAT_STREAM, value, '{');
        std::string satts;
        getline(STAT_STREAM, satts, '}');

        satts = trim(satts);
        var = ISys_Interp(var);
        value = ISys_Interp(trim(value));

        // std::cout << "If the value " << var << "is " << value << " then execute: " << satts << std::endl;
        std::string fcontents = satts;
        std::vector<std::string>Stats = split(fcontents, ';');
        if (var == value) {
            for (int i =0; i < Stats.size() ; ++ i)

                Stats[i] = trim(Stats[i]);
                for (const auto& stat : Stats) {
                    if (stat.length() > 0) {
                        ISys_Interp(stat);
                    }
                }
            ifstate = 2;
                
        } else {
            ifstate = 1;
        }
    } else if (UType(trim(sss)) == E_IMPORT) {
        STAT_STREAM >> keywd;
        std::string file;
        STAT_STREAM >> file;
        std::ifstream File(file);
        std::stringstream buf;
                std::string stat;
                while (getline(File, stat) ) {
                    if (stat[0] == '#') {
                        continue;
                    } else {
                        buf << stat;
                    }
                }
                std::string fcontents = buf.str();
                std::vector<std::string>Stats = split(fcontents, ';');
                for (int i =0; i < Stats.size() ; ++ i)
                    Stats[i] = trim(Stats[i]);
                for (const auto& stat : Stats) {
                    if (stat.length() > 0) {
                        ISys_Interp(stat);
                    }
                }
    } else if (UType(trim(sss)) == E_ELSE) {
        if (ifstate != 1) { /* if it's not in any sort of control tree */
            if (ifstate != 2) { /* if it's not after a successful IF */
                std::cout << "'else' without previous 'if'" << std::endl;
                return "Null";
            }

        } else {
            std::string value;
            getline(STAT_STREAM, value, '{');
            std::string satts;
            getline(STAT_STREAM, satts, '}');
            // std::cout << "If the value " << var << "is " << value << " then execute: " << satts << std::endl;
            std::string fcontents = satts;
            std::vector<std::string>Stats = split(fcontents, ';');

                for (int i =0; i < Stats.size() ; ++ i) {

                    Stats[i] = trim(Stats[i]);
                    for (const auto& stat : Stats) {
                        if (stat.length() > 0) {
                            ISys_Interp(stat);
                        }
                    }
                }
        }
    } else if (UType(trim(sss)) == E_DEF) {
        STAT_STREAM >> keywd;

        if (keywd == "def") {
            std::string fnameC;
            std::string dummy;
            getline(STAT_STREAM, fnameC, '(');
            fnameC = trim(fnameC);
            getline(STAT_STREAM, dummy,  ')');
            dummy = trim(dummy);
            std::string statstr;
            getline(STAT_STREAM, statstr, '{');
            getline(STAT_STREAM, statstr, '}');
            statstr = trim(statstr);
            funcmemD[fnameC] = statstr;
        }
    } 
    #ifdef USE_STACK
    else if (UType(trim(sss)) == E_STACK) {
        STAT_STREAM >> keywd;

        std::string file;

        STAT_STREAM >> file;

        run_ispp_lib(file.c_str(), "isp_voke");

    }
    #endif
    return "Null";
}