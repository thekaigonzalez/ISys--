#include <iostream>
#include <fstream>
#include "tinyexpr.h"

/*

#include "exprtk.hpp"

int main()
{
   typedef exprtk::expression<double> expression_t;
   typedef exprtk::parser<double>         parser_t;

   std::string expression_string = "3 + sqrt(5) + pow(3,2) + log(5)";

   expression_t expression;

   parser_t parser;

   if (parser.compile(expression_string,expression))
   {
     double result = expression.value();

     printf("Result: %19.15\n",result);
   }
   else
     printf("Error in expression\n.");

   return 0;
}

*/

double ToInt(std::string s) {
    try {
        return te_interp(s.c_str(), 0);
    } catch (std::exception e) {
        return -1;
    }
}

bool IsInt(std::string c) {
    return te_interp(c.c_str(), 0) != NAN;
}