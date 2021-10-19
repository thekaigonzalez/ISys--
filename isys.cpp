#include "isys/stat.h"

int main() {
    std::cout << ISys_Interp(trim("println(\"hello\")")) << std::endl;
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