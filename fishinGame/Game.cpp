#include "Game.hpp"

void Game::run(){
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");

    while (window.isOpen())
    {
        processEvents();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }
        
        window.clear();
        window.draw(fish.sprite);
        window.display();
    }

}

void Game::processEvents(){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
             fish.sprite.move(.1,0);
        }
}