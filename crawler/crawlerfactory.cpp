#include "crawlerfactory.h"

namespace crawler
{
std::shared_ptr<Crawler> CrawlerFactory::createCrawler(std::string type, resp& response)
{
    if (type == "email")
    {
        return std::make_shared<EmailCrawler>(response);
    }
    else if (type == "web")
    {
        return std::make_shared<WebCrawler>(response);
    }
    else
    {
        return nullptr;
    }
}
}