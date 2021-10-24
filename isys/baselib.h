#include <iostream>
#include <vector>
#include <fstream>
#ifdef USE_READLINE
#include <readline/readline.h>
#include <readline/history.h>
#endif

#include "newlexer.h"

#include "cstrings.h"
/*
 std::string foo() { return "Foo"; }
  std::string bar() { return "Bar"; }

  int main()
  {
      std::map<std::string, std::string (*)()> m;

      // Map the functions to the names
      m["foo"] = &foo;
      m["bar"] = &bar;

      // Display all of the mapped functions
      std::map<std::string, std::string (*)()>::const_iterator it = m.begin();
      std::map<std::string, std::string (*)()>::const_iterator end = m.end();

      while ( it != end ) {
          std::cout<< it->first <<"\t\""
              << (it->second)() <<"\"\n";
          ++it;
      }

*/

int b_print(std::vector<std::string> argv) {
    std::cout << PrettyPrint(argv[0]);
    return 1;
}

/* println(str) */
int b_println(std::vector<std::string> argv) {
    // std::cout << argv[0] << std::endl;
    std::cout << PrettyPrint(argv[0]) << std::endl;
    return 1;
}

/* length of string */
std::string b_len(std::vector<std::string> argv) {
    return std::to_string(PrettyPrint(argv[0]).length());
}

/* coming soon */
int b_printf(std::vector<std::string> argv) {
    return 1;
}

/* coming soon */
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
