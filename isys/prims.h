#include <iostream>
#include <map>
#include "baselib.h"

int version(std::string, std::string) {
    std::cout << "Version 1.0.0-git-scm" << std::endl;
    return 1;
}

std::map<std::string, int(*)(std::string, std::string)>funcmem = {
    // add a list of builtins here
    { "print", b_print },
    { "println", b_println },
    { "len"  , b_len},
    { "debugargs" , b_debugargs },
    { "system" , b_system },
    { "version", version }
};

std::map<std::string, std::string(*)(std::string, std::string)>funcmemF = {
    // add a list of builtins here
    { "tostr" , toString },
    { "read" , b_read },
    #ifdef USE_READLINE
    { "greadline" , b_readline }
    #endif
};

