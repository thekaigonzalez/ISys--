#include <iostream>
#include <vector>
#include <map>

std::map<std::string, std::string> varmem;

std::map<std::string, std::vector<std::string>> arraymem;

#define add_variable(name, value) varmem[name] = value
#define add_array_variable(name, value) arraymem[name] = {value}
