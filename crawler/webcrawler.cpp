#include "webcrawler.h"
#include "crawler_utils.h"
#include <iostream>

namespace crawler
{
void WebCrawler::fetchContent()
{
    std::cout << to_string(_response);
}

void WebCrawler::run()
{
    std::cout << "WebCrawler::run()" << std::endl;
}


}