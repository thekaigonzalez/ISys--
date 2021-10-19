#include <iostream>
#include <map>
#include "baselib.h"

std::map<std::string, int(*)(std::string)>funcmem = {
    // add a list of builtins here
    { "print", b_print },
    { "println", b_println },
    { "len"  , b_len}
};
