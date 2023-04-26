
#include "crawler_utils.h"
#include <boost/lexical_cast.hpp>

namespace crawler
{
std::string to_string(resp& response)
{
    return boost::lexical_cast<std::string>(response.base());
}   
}