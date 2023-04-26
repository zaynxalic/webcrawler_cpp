
#include "../example/root_certificates.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include "connection.h"

// Performs an HTTP GET and prints the response
void Session::setSSNI()
{
    // This holds the root certificate used for verification
    load_root_certificates(_ctx);
    // Verify the remote server's certificate
    _ctx.set_verify_mode(ssl::verify_peer);
    // Set SNI Hostname (many hosts need this to handshake successfully)
    if(! SSL_set_tlsext_host_name(_stream.native_handle(), _host.c_str()))
    {
        beast::error_code ec{static_cast<int>(::ERR_get_error()), net::error::get_ssl_category()};
        throw beast::system_error{ec};
    }
}

void Session::handshake()
{
    // Look up the domain name
    auto const results = resolver.resolve(_host, _port);
    // Make the connection on the IP address we get from a lookup
    beast::get_lowest_layer(_stream).connect(results);
    // Perform the SSL handshake
    _stream.handshake(ssl::stream_base::client);
    _req.set(http::field::host, _host);
    _req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
}

void Session::write()
{
    // Send the HTTP request to the remote host
    http::write(_stream, _req);
}

void Session::read()
{
    // Receive the HTTP response
    http::read(_stream, _buffer, _res);
}

void Session::run()
{
    setSSNI();
    handshake();
    write();
    read();
}

// int main(int argc, char** argv)
// {
//     // Check command line arguments.
//     std::string host = "www.ozbargain.com.au";
//     auto const port = "443";
//     auto const text = "/deals/popular";
//     auto network = std::make_shared<Session>(host, port, text);
//     network->run();
//     std::cout << network->getResponse();
// }