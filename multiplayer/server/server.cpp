#include <SFML/Network/UdpSocket.hpp>
#include <iostream>

int main(){

    while(true){
        sf::UdpSocket socket;
        // bind the socket to a port
        if (socket.bind(54000) != sf::Socket::Done)
        {
            // error...
        }
        std::string data = "";
        data.resize(512);
        std::size_t received;

        sf::IpAddress sender;
        unsigned short port;
        if (socket.receive(&data, 512, received, sender, port) != sf::Socket::Done)
        {
            // error...
        }
        std::cout << "Received " << received << " bytes from " << sender << " on port " << port << std::endl;

    }
}