#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>
#ifdef WINDOWS
#include <Windows.h>
#define sleep(x) Sleep((x) * 1000)
#endif
#ifdef LINUX
#include <unistd.h>
#endif
#ifdef USE_READLINE
#include <readline/readline.h>
#include <readline/history.h>
#endif

#include "newlexer.h"

#include "cstrings.h"
#include "var.h"

int b_print(std::vector<std::string> argv) {
    std::cout << PrettyPrint(argv[0]);
    return 1;
}

/* println(str) */
int b_println(std::vector<std::string> argv) {
    // std::cout << argv[0] << std::endl;
    // std::cout << PrettyPrint(argv[0]) << std::endl;
    for (const auto& i : argv) {
        if (i[0] != '"') {
            std::cout << i;
        } else {
            std::cout << PrettyPrint(i);
        }
    }
    std::cout << std::endl;
    return 1;
}

/* length of string */
std::string b_len(std::vector<std::string> argv) {
    return std::to_string(PrettyPrint(argv[0]).length());
}

/* format print */
/* printf("hello: ", name, " how are you today?"); */
int b_printf(std::vector<std::string> argv) {
    for (const auto& i : argv) {
        if (i[0] != '"') {
            std::cout << i;
        } else {
            std::cout << PrettyPrint(i);
        }
    }
    return 1;
}



/* Write text to a file */
int b_writetoFile(std::vector<std::string> argv) {
    
    std::ofstream file(PrettyPrint(argv[0]));
    file << PrettyPrint(argv[1]);
    file.close();
    return 1;
}

/* debugargs(str) */
int b_debugargs(std::vector<std::string> argv) {
    std::cout << "Evaluated argv[0]: " << argv[0] << "\n" << "argv[0] by themselves: " << std::endl;
    return 1;
}
/* system("Command") */
int b_system(std::vector<std::string> argv) {
    system(argv[0].c_str());
    return 1;
}
 
/* tostr(val) -> "val" */
std::string toString(std::vector<std::string> argv)
{
    return "\"" + argv[0] + "\"";
}

std::string b_read(std::vector<std::string> argv) {
    std::string ret;
    getline(std::cin, ret);
    return "\"" + ret + "\"";
}
#ifdef USE_READLINE
std::string b_readline(std::vector<std::string> argv) {
    std::string re = readline(PrettyPrint(argv[0]).c_str());

    return "\"" + re + "\"";
}
#endif

std::string b_sum(std::vector<std::string> argv) {
    int final_ = 0;

    for (const auto& num : argv)
        final_ = final_ + std::stoi(num);
    return std::to_string(final_);
}

std::string b_mul(std::vector<std::string> argv) {
    int final_ = 1;

    for (const auto& num : argv)
        final_ = final_ * std::stoi(num);
    return std::to_string(final_);
}

/* append "text" to variable. NOTE: this blindly places text onto stack. */
std::string b_append(std::vector<std::string> argv) {
    std::string varname = argv[0]; // append(var, data)
    std::string data = argv[1]; // could be numbers, strings, finishing strings, etc...
   
    return varmem[varname] + data;
}

/* limits string's text. Kind of like substring */
/* var xc = limit("xc the ultimate", 3) */
std::string b_limit(std::vector<std::string> argv) {
    std::string strtobedelimited = argv[0];
    std::string newdel = "";
    int numlimit = std::stoi(argv[1]);
    for (int i = 0; i < strtobedelimited.length() ; ++ i) {
        if (i == numlimit) {
            break;
        } else {
            newdel = newdel + strtobedelimited[i];
        }
    }

    return "\"" + PrettyPrint(newdel) + "\"";
}
/* locate("str", "r") -> 3 */
std::string b_locate(std::vector<std::string> argv) {
    std::string str = PrettyPrint(argv[0]);
    std::string text = PrettyPrint(argv[1]);
    return std::to_string(str.find_first_of(text));
}

std::string b_rlimit(std::vector<std::string>argv) {
    std::string str = PrettyPrint(argv[0]);
    int sub1 = std::stoi(argv[1]);
    int sub2 = std::stoi(argv[2]);

    return "\"" + str.substr(sub1, sub2) + "\"";
}

std::string b_strrm(std::vector<std::string>argv) {
    std::string str = PrettyPrint(argv[0]);
    std::string text = PrettyPrint(argv[1]);
    while (true) {
        auto n = str.find(text);
        if (n != std::string::npos) {
            str.erase(n, text.length());
        } else {
            break;
            // std::cerr << "Warning: string does not contain text." << std::endl;
        }
    }
    return str;
}

std::string b_strreplace(std::vector<std::string>argv) {
    std::string str = PrettyPrint(argv[0]);
    std::string ntext = PrettyPrint(argv[1]);
    std::string text = PrettyPrint(argv[2]);
    int index = 0;
    while (true) {
        index = str.find(ntext, index);
        if (index == std::string::npos) break;
        str.replace(index, text.length(), text);
        index += text.length();
    }
    return "\"" + str + "\"";
}

std::string os_sleep(std::vector<std::string>a) {
    sleep(std::stoi(a[0]));

    return "?";
}