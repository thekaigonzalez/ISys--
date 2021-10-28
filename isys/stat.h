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

#define ISPP_VECTOR std::vector<std::string>

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
            std::string ent;
            getline(STAT_STREAM, ent);
            // std::cout << "Simple: " << STAT_STREAM.str() << std::endl;
            // std::string name;
            // std::string value;
            // STAT_STREAM >> name;
            // std::string ptr;
            
            // getline(STAT_STREAM, ptr, '=');
            // getline(STAT_STREAM, value, '\n');
            // // if (IsString(trim(value))) {
            // //     value = PrettyPrint(trim(value)); // turn value into C string
            // // }
            
            // value = ISys_Interp(trim(value));
            // std::cout << value << std::endl;
            // // std::cout << "adding " << value << std::endl;
            

            std::vector<std::string>vpal = last_var(ent);
            if (trim(vpal[1])[0] == '[') {
                std::string vp1 = trim(vpal[1]);
                std::string vp2 = last_parse(vp1, ']');
                std::string vp0 = trim(vpal[0]);
                // std::cout << vp2 << std::endl;
                std::vector<std::string>argsv = last_arg(vp1, ',', '[', ']');
                for (int i = 0 ; i < argsv.size() ; i ++) {
                    argsv[i] = ISys_Interp(trim(argsv[i]));
                    // std::cout << argsv[i] << std::endl;
                }
                // std::cout << "Adding array " << trim(vpal[0]) << std::endl;
                arraymem[trim(vpal[0])] = argsv;

                return "ARRAY";
            }
            // std::cout << vpal[0];
            varmem[trim(vpal[0])] = ISys_Interp(trim(vpal[1]));
            return ""; // value is return code
        }
    } else if (UType(trim(sss)) == E_OTHER) {
        if (trim(sss)[0] == '"') {
            CString ns(sss);
            return ns.Parse();
        }
        std::string fname;
        getline(STAT_STREAM, fname, '(');
        std::string fargs = last_parse(STAT_STREAM.str().substr(STAT_STREAM.str().find("(")), ')');
        
        // std::cout << "Before/After Segfault" << std::endl;
        std::vector<std::string>argsv = last_arg(fargs);
        for (int i = 0; i < argsv.size() ; ++ i) {
            // std::cout << "arg: " <<  trim(argsv[i]) << std::endl;
            argsv[i] = ISys_Interp(trim(argsv[i]));
        }

        if (fname.find('.') != std::string::npos)
        {
            STAT_STREAM.clear();
            STAT_STREAM.seekg(0);

            std::string cname;
            getline(STAT_STREAM, cname, '.');

            cname = trim(cname);

            std::string fnameC;
            getline(STAT_STREAM, fnameC, '(');

            if (classmem.find(cname) != classmem.end()) {
                if (classmem[cname].find(fnameC) != classmem[cname].end()) {
                    return classmem[cname][fnameC](argsv);
                } else {
                    std::cout << "Class " << cname << " has no function member " << fnameC << std::endl; 
                    return "none";
                }
            } else {
                std::cout << "Error: no such class " << cname << std::endl;
                return "none";
            }
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
        } else if (trim(sss).find("[") != std::string::npos) {
            STAT_STREAM.clear();
            STAT_STREAM.seekg(0);
            std::string arrayname;

            getline(STAT_STREAM, arrayname, '[');

            arrayname = trim(arrayname);

            std::string pos;

            getline(STAT_STREAM, pos, ']');

            pos = trim(pos);

            int acpos = std::stoi(pos);
            // std::cout << "Get " << acpos << " from array name: " << arrayname << std::endl;
            return arraymem[arrayname][acpos];
        } else {
                /* if (trim(fargs)[0] != '\"') 
                    if (varmem.find(split(fargs, ' ')[0]) != varmem.end()) {
                        fargs = "\"" + varmem[split(fargs, ' ')[0]] + "\"";
                    }
                } 
                */ // c
            if (varmem.find(split(trim(sss), ' ')[0]) != varmem.end()) {
                
                return varmem[split(trim(sss), ' ')[0]];
            } else if (arraymem.find(split(trim(sss), ' ')[0]) != arraymem.end()) {
                std::cout << "[";
                for (const auto& i : arraymem[split(trim(sss), ' ')[0]]) { 
                    std::cout << i << ",";
                };
                std::cout << "]"<<std::endl;
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
        // getline(STAT_STREAM, var, '=');
        // var = trim(var);
        getline(STAT_STREAM, value, '{');
        std::string satts;
        getline(STAT_STREAM, satts, '}');

        satts = trim(satts);
        // var = ISys_Interp(var);
        value = ISys_Interp(trim(value));

        // std::cout << "If the value " << var << "is " << value << " then execute: " << satts << std::endl;
        std::string fcontents = satts;
        std::vector<std::string>Stats = split(fcontents, ';');
        if (value == "1") {
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
    } else if (UType(trim(sss)) == E_COMP) {
        std::string valueone;
        std::string dummy;
        std::string valuetwo;
        // std::cout << "Ecomp\n";
        getline(STAT_STREAM, valueone, '=');
        // std::cout << "v: " << valueone << std::endl;
        getline(STAT_STREAM, dummy, '=');
        getline(STAT_STREAM, valuetwo, '\n');

        valueone = ISys_Interp(trim(valueone));

        valuetwo = ISys_Interp(trim(valuetwo));

        if (valueone == valuetwo) {
            return "1";
        } else {
            ifstate = 1;
            return "0";
        }
    }
    else if (UType(trim(sss)) == E_FOR) { // for i in array { println(i); }
        STAT_STREAM >> keywd;
        std::string vname;
        std::string inw;
        std::string varname;

        STAT_STREAM >> vname;

        STAT_STREAM >> inw;

        if (inw == "in") {
            STAT_STREAM >> varname;
            varname = trim(varname);
            getline(STAT_STREAM, keywd, '{');
            keywd = trim(keywd);
            std::string stats;

            getline(STAT_STREAM, stats, '}');

            std::vector<std::string>Statts = split(stats, ';');

            if (arraymem.find(varname) != arraymem.end()) {
                for (const auto& i : arraymem[varname]) {
                    for (uint ic = 0 ; ic < Statts.size(); ic++) {
                        if (Statts[ic].length() < 0) {
                            continue;
                        }
                        varmem[vname] = i;

                        ISys_Interp(Statts[ic]);
                    }
                }
            } else {
                std::cout << "Invalid operation 'it::iterate_ispp_array()' on 'non-array-mutable'" << std::endl;
            }
        }
    } else if (UType(trim(sss)) == E_WHILE) {
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
        while (ISys_Interp(var) == value) {
            std::cout << var << std::endl;
            for (int i =0; i < Stats.size() ; ++ i) {

                Stats[i] = trim(Stats[i]);
                for (const auto& stat : Stats) {
                    if (stat.length() > 0) {
                        ISys_Interp(stat);
                        var = ISys_Interp(trim(var));
                        value = ISys_Interp(trim(value));
                    }
                }
            }
            var = ISys_Interp(trim(var));
            value = ISys_Interp(trim(value));
        } 
        // } else {
        //     ifstate = 1;
        // }
    } else if (UType(trim(sss)) == E_ISO) {
        std::string stat = trim(sss).substr(trim(sss).find("(")+1, trim(sss).find_last_of(")")-1);
        // std::cout << "Executing :" << stat << ":" <<std::endl;
        return ISys_Interp(trim(stat));
    } else if (UType(trim(sss)) == E_RETURN) {
        std::string data;

        STAT_STREAM >> keywd;

        getline(STAT_STREAM, data, '\n');

        // std::cout << ISys_Interp(data) << std::endl;
        return ISys_Interp(data);
    } else if (UType(trim(sss)) == E_ARRAY) {
        return trim(sss);
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