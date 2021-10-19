#include <iostream>
#include <map>
#include "baselib.h"

std::map<std::string, int(*)(std::string, std::string)>funcmem = {
    // add a list of builtins here
    { "print", b_print },
    { "println", b_println },
    { "len"  , b_len},
    { "debugargs" , b_debugargs}
};
