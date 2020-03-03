#include "Game.hpp"

void Game::run(){
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");

    while (window.isOpen())
    {
        processKeys();
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

void Game::processKeys(){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
             fish.sprite.move(.1,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            fish.sprite.move(-0.1,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            fish.sprite.move(0,0.1);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            fish.sprite.move(0,-0.1);
        }
}
void Game::update(){
    
}