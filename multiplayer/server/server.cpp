#include <SFML/Network.hpp>
#include <iostream>

int main(){

        // sf::UdpSocket socket;
        sf::TcpListener listener;

        // bind the listener to a port
        if (listener.listen(42069) != sf::Socket::Done)
        {
            // error...
        }

        // accept a new connection
        sf::TcpSocket client;
        if (listener.accept(client) != sf::Socket::Done)
        {
            // error...
        }
        char data[100] = "Hello World!";
        if(client.send(data,100) != sf::Socket::Done){
            std::cout << "Couldn't send back" << std::endl;
        }
        
}