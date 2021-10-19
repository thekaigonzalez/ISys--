#include "isys/stat.h"

int main() {
    std::cout << "ISys++ 1.0 Copyright (C) Kai D. Gonzalez" << std::endl;
    while (true) {
        std::cout << ">>>";
        std::string stat;
        getline(std::cin, stat);
        if (stat.empty()) {
            std::cout << "Error: Empty Statement\n[C]: ?\n";
        } else {
            std::cout << ISys_Interp(trim(stat)) << std::endl;
        }
    }
}