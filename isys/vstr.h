#include <iostream>

bool IsString(std::string str) {
    if (str[0] == '\"') return true; else return false; 
}