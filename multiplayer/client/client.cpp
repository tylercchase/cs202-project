#include <SFML/Network/UdpSocket.hpp>

int main(){
    sf::UdpSocket socket;

    std::string data("Hello RAWR XD owo *nuzzles  forehead uwu**");

    // bind the socket to a port
    if (socket.bind(54000) != sf::Socket::Done)
    {
        // error...
    }
    sf::IpAddress recipient = "165.227.5.237";
    unsigned short port = 54000;
    if (socket.send(data.c_str(), data.size(), recipient, port) != sf::Socket::Done)
    {
        // error...
    }
}