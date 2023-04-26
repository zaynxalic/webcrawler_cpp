#pragma once
#include "../connection/connection.h"
#include <string>
namespace crawler
{
    std::string to_string(resp& response);

    std::string extract_body(std::string& response);
    
}