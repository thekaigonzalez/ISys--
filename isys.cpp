#include "isys/stat.h"

int main(int argc, char* * argv) {
    bool returncodes;
    if (argc > 1) {
        if (std::string(argv[1]) == "-returns") {
            returncodes = true;
        }
    }

    std::cout << "ISys++ 1.0 Copyright (C) Kai D. Gonzalez" << std::endl;
    while (true) {
        std::cout << ">>>";
        std::string stat;
        getline(std::cin, stat);
        if (stat.empty()) {
            std::cout << "Error: Empty Statement\n[C]: ?\n";
        } else {
            if (returncodes) {
                std::cout << ISys_Interp(trim(stat)) << std::endl;
            } else {
                ISys_Interp(trim(stat));
            }
        }
    }
}