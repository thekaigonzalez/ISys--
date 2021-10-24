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
    { "debugargs" , b_debugargs },
    { "system" , b_system },
    { "open_and_write" , b_writetoFile },
    { "version", version }
};

std::map<std::string, std::string(*)(std::string, std::string)>funcmemF = {
    // add a list of builtins here
    { "tostr" , toString },
    { "read" , b_read },
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
