#pragma once 
#include <string>
#include "../connection/connection.h"
namespace crawler
{
class Crawler
{
    public:
        Crawler(resp &response){};
        Crawler() = default;
        ~Crawler() = default;
        virtual void fetchContent() = 0;
    protected:
        virtual void run() = 0;
        
    };
};