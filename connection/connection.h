#pragma once
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>

namespace beast = boost::beast; // from <boost/beast.hpp>
namespace http = beast::http;   // from <boost/beast/http.hpp>
namespace net = boost::asio;    // from <boost/asio.hpp>
namespace ssl = net::ssl;       // from <boost/asio/ssl.hpp>
using tcp = net::ip::tcp;       // from <boost/asio/ip/tcp.hpp>
using resp = http::response<http::dynamic_body>;

class Session
{
    public:
        Session(
            std::string host,
            std::string port,
            std::string text,
            int version = 11
        )
        :_version(version)
        ,_host(host) 
        , _port(port)
        , _text(text)
        {}
        void run();

        http::response<http::dynamic_body> getResponse()
        {
            return _res;
        }

        std::string getHost()
        {
            return _host;
        }

        std::string getPort()
        {
            return _port;
        }

        std::string getText()
        {
            return _text;
        }

    private:
        int _version;
        std::string _host;
        std::string _port;
        std::string _text;
        beast::flat_buffer _buffer;
        net::io_context _ioc;
        ssl::context _ctx{ssl::context::tlsv12_client};
        tcp::resolver resolver {_ioc};
        http::response<http::dynamic_body> _res;
        // Set up an HTTP GET request message
        http::request<http::string_body> _req{http::verb::get, _text, _version};
        beast::ssl_stream<beast::tcp_stream> _stream{_ioc, _ctx};
        beast::error_code _ec;
        void setSSNI();
        void handshake();
        void write();
        void read();
};