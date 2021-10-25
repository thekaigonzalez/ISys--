#include <iostream>
#include <map>
#include "baselib.h"

#define add_c_func(name, func) funcmem[name] =  &func
#define add_c_return_func(name, func) funcmemF[name] =  &func

int version(std::vector<std::string>) {
    std::cout << "Version 1.0.2-git-scm" << std::endl;
    return 1;
}

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
