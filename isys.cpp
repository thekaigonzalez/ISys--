#include "isys/stat.h"

void repl(bool returncodes) {
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

int main(int argc, char* * argv) {
    bool returncodes;
    if (argc > 1) {
        if (std::string(argv[1]) == "-returns") {
            returncodes = true;
        } else {
            std::ifstream File(argv[1]);
            
            if (!File) {
                std::cout << "isyspp: file not found (stdc++: -std::ifstream returned false)" << std::endl;
            } else {
                std::stringstream buf;
                buf << File.rdbuf();
                std::string fcontents = buf.str();
                std::vector<std::string>Stats = split(fcontents, ';');
                for (int i =0; i < Stats.size() ; ++ i)
                    Stats[i] = trim(Stats[i]);
                for (const auto& stat : Stats) {
                    ISys_Interp(stat);
                }
            }
        }
    } else {
        repl(returncodes);
    }
    
}