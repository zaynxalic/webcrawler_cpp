    #pragma once 
    #include <string>
    #include "emailcrawler.h"
    #include "webcrawler.h"

    namespace crawler
    {
    class CrawlerFactory
    {
        public:
            CrawlerFactory()=default;
            ~CrawlerFactory()=default;
            std::shared_ptr<Crawler> createCrawler(std::string type, resp& response);
    };
    }