#include <iostream>
#include <sstream>
#include <vector>

const std::string WHITESPACE = " \n\r\t\f\v";
 
std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

std::string last_parse(std::string last,char tok) {
    std::string ns;
    int istring = 0;
    for (int i = 0;
     i < last.length() ; ++ i) {
        if (last[i] == '"' && istring == 0) {
            // std::cout << "Beginning of string" << std::endl;
            istring = 1;
            ns = ns + last[i];
        }
        else if (last[i] == '"' && istring == 1) {
            // std::cout << "End of String, value: " << last[i] << std::endl;
            istring = 2;
            ns = ns + last[i];
        }
        else if (last[i] == tok && istring == 2) {
            std::cout << "Signal Stop, end " << ns << std::endl; 
            istring = 3; 
            break;
        } else {
            ns = ns + last[i];
        }
        
    }
    return ns;
}
bool endsWithR(std::string const&FS, std::string const&e) {
    if (FS.length() >= e.length()) {
        return (0 == FS.compare(FS.length() - e.length(), e.length(), e));
    } else {
        return false;
    }
}
std::vector<std::string>last_arg(std::string cd, char spop = ',') {
    std::string cdd = "";
    bool once = false;
    std::vector<std::string>RETEUN{};
    int state = 0;
    std::cout << cd << std::endl;
    for (int i = 0; i < cd.length() ; i ++)
    {
        
        //  if (trim(cd).find(',') == std::string::npos && state == 0) {
        //     RETEUN.push_back(cd);
        //     return RETEUN;
        // }

        if (cd[i] == '"' && state == 0) { /* if it's a quote "string" */
        // std::cout << "Quote opening\n" << cd[i++];
            state = 1;
            cdd = cdd + cd[i];
        } else if (cd[i] == spop && state == 0) { /* if the character's the delimiter and not in a string */
        // std::cout << "Quote openinCg\n" << cd[i++];
        std::cout << "Adding " << cdd << std::endl;
            RETEUN.push_back(trim(cdd));
            cdd[0] = '\0';
            continue;
        } else if (cd[i] == spop && state == 1) { /* if the character's the delimiter and is in a string */
            cdd = cdd + cd[i];
        } else if (cd[i] == '"' && state == 1) {  /* if it's closing the string */ 
            cdd = cdd + '"';
            state = 0;
        }
        else {
            cdd = cdd + cd[i];
        }
            
    }
    std::cout << RETEUN[0] << " : " << RETEUN[1] << std::endl;
    // std::cout << cdd << std::endl;
    return RETEUN;
}
