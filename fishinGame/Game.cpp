#include "Game.hpp"

void Game::run(){

    while (window.isOpen())
    {
        processKeys();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }
        
        
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
void Game::render(){
        window.clear();
        window.draw(fish.sprite);
        window.display();
}