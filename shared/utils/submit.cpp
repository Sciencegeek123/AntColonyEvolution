#include "utils/utils.h"

#include <sstream>
#include <boost/asio.hpp>

using namespace std;
using namespace utils;

using namespace boost;
using namespace boost::asio;
using namespace boost::asio::ip;

void utils::submitJSON(json obj)
{
    string raw = obj.dump();
    cout << raw << endl;

    boost::asio::streambuf request;
    std::ostream request_stream(&request);

    request_stream << "POST /api/search/ HTTP/1.1 \r\n";
    request_stream << "Host:"
                   << "167.96.54.7:3001"
                   << "\r\n ";
    request_stream
        << "User-Agent: C/1.0";
    request_stream << "Content-Type: application/json; charset=utf-8 \r\n";
    request_stream << "Accept: */*\r\n";
    request_stream << "Content-Length: " << raw.length() << "\r\n";
    request_stream << "Connection: close\r\n\r\n"; //NOTE THE Double line feed
    request_stream << raw;

    boost::asio::ip::tcp::endpoint endpoint(
        boost::asio::ip::address::from_string("167.96.54.7"), 3001);

    static boost::asio::io_service myIOS;
    // Try each endpoint until we successfully establish a connection.
    tcp::socket socket(myIOS);

    cout << "Connecting" << endl;

    socket.connect(endpoint);

    cout << "Writing" << endl;

    boost::asio::write(socket, request);

    cout << "Closing" << endl;

    boost::system::error_code ec;
    socket.shutdown(tcp::socket::shutdown_both, ec);
    socket.close(ec);
}