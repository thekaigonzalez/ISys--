#include "isys/stat.h"

void repl(bool returncodes =false) {
    std::cout << "ISys++ 1.0 Copyright (C) Kai D. Gonzalez" << std::endl;
    while (true) {
        
        #ifndef USE_READLINE
            std::string stat;
            std::cout << ">>>";
            getline(std::cin, stat);
        #elif defined USE_READLINE
            std::string stat = readline(">>>");
            add_history(stat.c_str());
        #endif
        if (stat.empty()) {
            std::cout << "Error: Empty Statement\n[C]: ?\n";
        } else {
            if (returncodes == true) {
                std::cout << ISys_Interp(trim(stat)) << std::endl;
            } else {
                ISys_Interp(trim(stat));
            }
        }
    }
}

int main(int argc, char* * argv) {
    bool returncodes = false;
    if (argc > 1) {
        if (std::string(argv[1]) == "-returns") {
            returncodes = true;
            repl(returncodes);
        } else {
            std::ifstream File(argv[1]);
            
            if (!File) {
                std::cout << "isyspp: file not found (stdc++: -std::ifstream returned false)" << std::endl;
            } else {
                std::stringstream buf;
                std::string stat;
                while (getline(File, stat) ) {
                    if (stat[0] == '#') {
                        continue;
                    } else {
                        buf << stat;
                    }
                }
                std::string fcontents = buf.str();
                std::vector<std::string>Stats = split(fcontents, ';');
                for (int i =0; i < Stats.size() ; ++ i)
                    Stats[i] = trim(Stats[i]);
                for (const auto& stat : Stats) {
                    if (stat.length() > 0) {
                        ISys_Interp(stat);
                    }
                }
            }
        }
    } else {
        repl(returncodes);
    }
    
}