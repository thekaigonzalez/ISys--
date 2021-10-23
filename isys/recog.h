#include <iostream>
#include <math.h>
#include <fstream>
#include "enum.h"

#include "integer.h"
#include "string.h"
//TODO: implement control
// if VAR is 1 (number)
int UType(const std::string& c) {
    if (split(c, ' ')[0] == "var") {
        return E_VAR;
    } else if (c.find("(") != std::string::npos)
        return E_OTHER;
    else if (c[0] == '"') {
        return E_STRING;
    } else if (IsInt(c)) {
        return E_INT;
    } else if (IsInt(c) == false) { /* if not integer, then it's likely a var decl. */
        return E_LIKELY;
    } else if (c[0] == 'e') {
        return E_EVAL;
    } else if (c[0] == '#') {
        return E_COMMENT;
    }
    return E_NULL;
}