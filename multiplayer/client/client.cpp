#include <SFML/Network.hpp>
#include <iostream>
int main(){
    char data[100] = "hello world!";
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("127.0.0.1", 42069);
    if (status != sf::Socket::Done)
    {
        // error...
    }
    char data1[100];
    std::size_t received;

    // TCP socket:
    if (socket.receive(data1, 100, received) != sf::Socket::Done)
    {
        // error...
    }
    std::cout << data1 << std::endl;
}
