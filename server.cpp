#include <boost/asio.hpp> 

#include <ctime> 

#include <iostream> 

#include <string> 

  

using boost::asio::ip::tcp; 

  

std::string QOTD() {  

return "blaaaa";}  

  

int main () { 

boost::asio::io_context io_context; 

  

tcp::acceptor acceptor (io_context,tcp::endpoint (tcp::v4(), 17)); 

  

while (true) { 

tcp::socket socket(io_context); 

acceptor.accept(socket); 

  

std::string message = QOTD(); 

boost::system::error_code ec; 

  

boost::asio::write(socket,boost::asio::buffer(message), ec); 
}
return 0; 
}
