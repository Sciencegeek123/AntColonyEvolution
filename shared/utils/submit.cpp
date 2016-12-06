#include "utils/utils.h"

#include <sstream>
#include <boost/asio.hpp>
#include <termios.h>
#include <iostream>

using namespace std;
using namespace utils;

using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

void utils::submitJSON(json obj)
{
    string raw = obj.dump();
    cout << raw << endl;

    static boost::asio::io_service myIOS;

    boost::asio::ip::tcp::iostream tcp_stream;

    cout << "Connecting" << endl;

    string server = "localhost";
    string port = "3001";

    tcp_stream.connect(server, port);

    if (!tcp_stream)
    {
        std::cout << "Unable to connect: " << tcp_stream.error().message() << "\n";
        return;
    }

    cout << "Writing" << endl;

    tcp_stream << "POST /api/search HTTP/1.1 \r\n";
    tcp_stream << "Host: "
               << server << ":" << port
               << "\r\n ";
    tcp_stream << "User-Agent: C/1.0";
    tcp_stream << "Content-Type: application/json; charset=utf-8 \r\n";
    tcp_stream << "Accept: */*\r\n";
    tcp_stream << "Content-Length: " << raw.length() << "\r\n";
    tcp_stream << "Connection: close\r\n\r\n"; //NOTE THE Double line feed
    tcp_stream << raw;

    cout << "Response" << endl;

    // Check that response is OK.
    std::string http_version;
    tcp_stream >> http_version;
    unsigned int status_code;
    tcp_stream >> status_code;
    std::string status_message;
    std::getline(tcp_stream, status_message);
    if (!tcp_stream || http_version.substr(0, 5) != "HTTP/")
    {
        std::cout << "Invalid response\n";
        std::cout << http_version << endl;
        return;
    }
    if (status_code != 200)
    {
        std::cout << "Response returned with status code " << status_code << "\n";
        return;
    }

    // Process the response headers, which are terminated by a blank line.
    std::string header;
    while (std::getline(tcp_stream, header) && header != "\r")
        std::cout << header << "\n";
    std::cout << "\n";

    // Write the remaining data to output.
    std::cout << tcp_stream.rdbuf();
}