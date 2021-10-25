#include <iostream>
#include <fstream>

extern "C" {
int isp_voke() {
    std::cout << "Welcome to my library!" << std::endl;
    return 1;
}
}