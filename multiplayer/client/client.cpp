#include <SFML/Network/UdpSocket.hpp>
#include <iostream>
int main(){
    sf::UdpSocket socket;

    std::string data("Hello World!");

    // bind the socket to a port
    if (socket.bind(5000) != sf::Socket::Done)
    {
        std::cout << "bind error" << std::endl;
        // error...
    }
    sf::IpAddress recipient = "127.0.0.1";
    unsigned short port = 42069;
    if (socket.send(data.c_str(), data.size(), recipient, port) != sf::Socket::Done)
    {
        std::cout << "send error" << std::endl;
    }
}
