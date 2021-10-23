#include <iostream>
#include <fstream>
#ifdef USE_READLINE
#include <readline/readline.h>
#include <readline/history.h>
#endif

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

int b_print(std::string arguments, std::string) {
    std::cout << PrettyPrint(arguments);
    return 1;
}

/* println(str) */
int b_println(std::string arguments, std::string) {
    std::cout << PrettyPrint(arguments) << std::endl;
    return 1;
}

/* length of string */
std::string b_len(std::string arguments, std::string aVal) {
    return std::to_string(PrettyPrint(arguments).length());
}
/* coming soon */
int b_printf(std::string arguments, std::string) {
    return 1;
}

/* coming soon */
int b_writetoFile(std::string arguments, std::string argVal) {
    return 1;
}

/* debugargs(str) */
int b_debugargs(std::string arguments, std::string argVal) {
    std::cout << "Evaluated Arguments: " << arguments << "\n" << "Arguments by themselves: " << argVal << std::endl;
    return 1;
}
/* system("Command") */
int b_system(std::string arguments, std::string argVal) {
    system(arguments.c_str());
    return 1;
}
 
/* tostr(val) -> "val" */
std::string toString(std::string arguments, std::string argVal)
{
    return "\"" + arguments + "\"";
}

std::string b_read(std::string arguments, std::string argVal) {
    std::string ret;
    getline(std::cin, ret);
    return "\"" + ret + "\"";
}
#ifdef USE_READLINE
std::string b_readline(std::string arguments, std::string argVal) {
    std::string re = readline(PrettyPrint(arguments).c_str());

    return "\"" + re + "\"";
}
#endif
