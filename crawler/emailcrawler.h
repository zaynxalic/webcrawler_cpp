#pragma once
#include "crawler.h"
#include <iostream>

namespace crawler
{
class EmailCrawler: public Crawler
{
    public:
        EmailCrawler(resp &response){};
        ~EmailCrawler(){};
        void fetchContent() override{
            std::cout << "EmailCrawler::fetchContent()" << std::endl;
        };
    protected:
        
        void run() override{
            std::cout << "EmailCrawler::run()" << std::endl;
        }

    private:
};
};
