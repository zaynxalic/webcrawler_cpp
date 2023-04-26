#pragma once
#include "crawler.h"
#include <string>
#include <iostream>
#include <vector>

namespace crawler
{
class WebCrawler: public Crawler
{
    public:
        WebCrawler(resp &response, int num_of_info = 3)
        :Crawler(response)
        ,_num_of_info(num_of_info)
        , _response(response)
        {
        }
        ~WebCrawler(){};
        void fetchContent() override;
    protected:
        void run() override;

    private:
        resp _response;
        std::string _result;
        int _num_of_info; 
};
};
