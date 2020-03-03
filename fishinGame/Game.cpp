#include "Game.hpp"

void Game::run(){
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    const float fps = 60.0f;
    sf::Time timePerFrame = sf::seconds(1.0f/fps);

    while (window.isOpen())
    {
        processEvents();
        processKeys();
        timeSinceLastUpdate += clock.restart();
        while(timeSinceLastUpdate > timePerFrame){
            timeSinceLastUpdate -= timePerFrame;
            update();
        }
        render();
        
    }

}
void Game::processEvents(){
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        
    }
}
void Game::processKeys(){
        //Fish Movement
        //Right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if ( fish.sprite.getPosition().x + 50 >= window.getSize().x ) { }
            else {
                fish.sprite.move(.1,0);
            }

            fish.sprite.setTextureRect(sf::IntRect(300, 0, -300, 300));;

        }
        //Left
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            if ( fish.sprite.getPosition().x <= 0 ) {
            }else{
                fish.sprite.move(-0.1,0);
            }
            fish.sprite.setTextureRect(sf::IntRect(0, 0, 300, 300));;
        }
        //Down
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            if ( fish.sprite.getPosition().y + 50 >= window.getSize().y ) { }
            else {
                fish.sprite.move(0,0.1);
            }
        }
        //Up
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            if ( fish.sprite.getPosition().y <= 0 ) {

            }
            else {
                fish.sprite.move(0,-0.1);
            }

        }
        //Fisherman Movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        {
            if ( fisherman.sprite.getPosition().x + 50 >= window.getSize().x ) { }
            else {
                fisherman.sprite.move(.1,0);
            }

            fisherman.sprite.setTextureRect(sf::IntRect(300, 0, -300, 300));;

        }
        //Left
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::J)){
            if ( fisherman.sprite.getPosition().x <= 0 ) {
            }else{
                fisherman.sprite.move(-0.1,0);
            }
            fisherman.sprite.setTextureRect(sf::IntRect(0, 0, 300, 300));;
        }
        //Down
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::K)){
            if ( fisherman.sprite.getPosition().y + 50 >= window.getSize().y ) { }
            else {
                fisherman.sprite.move(0,0.1);
            }
        }
        //Up
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::I)){
            if ( fisherman.sprite.getPosition().y <= 0 ) {

            }
            else {
                fisherman.sprite.move(0,-0.1);
            }

        }
}
void Game::update(){
    if(fish.sprite.getGlobalBounds().intersects(fisherman.sprite.getGlobalBounds())){
        std::cout << "Fish collided with fisherman!" << std::endl;
    }
}
void Game::render(){
        window.clear();
        window.draw(fish.sprite);
        window.draw(fisherman.sprite);
        window.display();
}