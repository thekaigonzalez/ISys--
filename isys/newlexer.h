#include <iostream>
#include <sstream>


std::string last_parse(std::string last,char tok) {
    std::string ns;
    int istring = 0;
    for (int i = 0;
     i < last.length() ; ++ i) {
        if (last[i] == '"' && istring == 0) {
            // std::cout << "Beginning of string" << std::endl;
            istring = 1;
            ns = ns + last[i];
        }
        else if (last[i] == '"' && istring == 1) {
            // std::cout << "End of String, value: " << last[i] <<std::endl;
            istring = 2;
            ns = ns + last[i];
        }
        else if (last[i] == tok && istring == 2) {
            // std::cout << "Signal Stop, end " << ns << std::endl;
            break;
        } else {
            ns = ns + last[i];
        }

    }
    return ns;
}

