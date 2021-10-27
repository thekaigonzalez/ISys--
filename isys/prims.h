#include <iostream>
#include <map>
#include "baselib.h"

#define add_c_func(name, func) funcmem[name] =  &func
#define add_c_return_func(name, func) funcmemF[name] =  &func

int version(std::vector<std::string>) {
    std::cout << "Version 1.0.5-git-scm" << std::endl;
    return 1;
}

std::map<std::string, std::map<std::string, std::string(*)(std::vector<std::string>)>> classmem = {
    {"os", { 
            {"sleep", os_sleep}, 
            {"getenv", os_getenv}, 
            {"setenv", os_setenv},
            {"execute", os_execute}
            // {"system", b_system} 
        }
    },
    {
        "memory", {
            {"delvar", memory_deletevar},
            {"hop", memory_hop},
            {"all", memory_all},
            {"each", memory_each}
        }
    }
};

std::map<std::string, int(*)(std::vector<std::string>)>funcmem = {
    // add a list of builtins here
    { "print", b_print },
    { "println", b_println },
    { "debugargs" , b_debugargs },
    { "printf", b_printf },
    { "system" , b_system },
    { "open_and_write" , b_writetoFile },
    { "version", version }
};

std::map<std::string, std::string(*)(std::vector<std::string>)>funcmemF = {
    // add a list of builtins here
    { "tostr" , toString },
    { "read" , b_read },
    { "sum" , b_sum },
    { "mul" , b_mul },
    { "strremove" , b_strrm},
    { "strreplace" , b_strreplace},
    { "limit" , b_limit },
    { "substr" , b_rlimit },
    { "append" , b_append },
    { "locate" , b_locate },
    { "len"  , b_len},
    #ifdef USE_READLINE
    { "greadline" , b_readline }
    #endif
};



std::map<std::string, std::string>funcmemD = {
    {"test", "println(\"hello\"); print('l');"}
};


std::map<std::string, std::string> varglob = {
    {"args", "NoneYet"}
};
