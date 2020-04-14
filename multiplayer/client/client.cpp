#include <SFML/Network.hpp>
#include <iostream>
int main(){
    char data[100] = "hello world!";
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("134.209.140.123", 42069);
    if (status != sf::Socket::Done)
    {
        std::cout << "Can't connect" << std::endl;
        // error...
    }
    char data1[100];
    std::size_t received;
    std::cout << "Connected" << std::endl;
    // TCP socket:
    if (socket.receive(data1, 100, received) != sf::Socket::Done)
    {
        // error...
        std::cout << "Couldn't recieve" << std::endl;
    }
    std::cout << "Couldn't recieve" ;
}
