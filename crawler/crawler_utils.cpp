
#include "crawler_utils.h"
#include <sstream>
#include <regex>
#include <iostream>
namespace crawler
{
std::string to_string(resp& response)
{
    std::ostringstream oss;
    oss << response;
    return oss.str();
}   

std::string extract_body(std::string& response)
{
    if (response.empty())
    {
        return "";
    }
    std::regex body_regex("<body.*");
    std::smatch body_match;
    if (std::regex_search(response, body_match, body_regex)) 
    {
        std::cout << body_match[0].str();

    } 
    return "";
}
}