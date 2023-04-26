#include "crawler/crawlerfactory.h"
#include "connection/connection.h"

int main(int argc, char** argv)
{
    // Check command line arguments.
    std::string host = "www.ozbargain.com.au";
    auto const port = "443";
    auto const text = "/deals/popular";
    auto network = std::make_shared<Session>(host, port, text);
    network->run();
    resp net_res = network->getResponse();
    crawler::CrawlerFactory cf;
    cf.createCrawler("web",net_res) -> fetchContent();
}