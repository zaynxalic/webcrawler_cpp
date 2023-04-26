#include "webcrawler.h"
#include "crawler_utils.h"
#include <iostream>

namespace crawler
{
void WebCrawler::fetchContent()
{
    std::string response = to_string(_response);
    std::string response_body = extract_body(response);
    std::cout << response_body << std::endl;
}

void WebCrawler::run()
{
    std::cout << "WebCrawler::run()" << std::endl;
}


}