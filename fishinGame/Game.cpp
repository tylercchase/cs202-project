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
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::F){
            spawnFish();
        }
    }
}
void Game::processKeys(){
        //Fish Movement
        //Right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if ( fishBounding.getPosition().x + 50 >= window.getSize().x ) { }
            else {
                fishBounding.move(.1,0);
                for(auto &fish: fishSwarm){
                    fish.sprite.move(.1,0);
                }
            }

            fishBounding.setTextureRect(sf::IntRect(300, 0, -300, 300));;

        }
        //Left
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            if ( fishBounding.getPosition().x <= 0 ) {
            }else{
                fishBounding.move(-0.1,0);
                for(auto &fish: fishSwarm){
                    fish.sprite.move(-.1,0);
                }
            }
            fishBounding.setTextureRect(sf::IntRect(0, 0, 300, 300));;
        }
        //Down
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            if ( fishBounding.getPosition().y + 50 >= window.getSize().y ) { }
            else {
                fishBounding.move(0,0.1);
                for(auto &fish: fishSwarm){
                    fish.sprite.move(0,0.1);
                }
            }
        }
        //Up
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            if ( fishBounding.getPosition().y <= 0 ) {

            }
            else {
                fishBounding.move(0,-0.1);
                for(auto &fish: fishSwarm){
                    fish.sprite.move(0,-0.1);
                }
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
    for(auto& fish : fishSwarm){
        if(fish.sprite.getGlobalBounds().intersects(fisherman.sprite.getGlobalBounds())){
            std::cout << "Fish collided with fisherman!" << std::endl;
        }
        while(!fish.sprite.getGlobalBounds().intersects(fishBounding.getGlobalBounds())){
            fish.sprite.setPosition(fishBounding.getPosition().x, fishBounding.getPosition().y);
        }
    }
    
}
void Game::render(){
        window.clear();
        fishBounding.setFillColor(sf::Color::Green);
        fishBounding.setRadius(150.0f);
        window.draw(fishBounding);
        for(auto &fish : fishSwarm){
            window.draw(fish.sprite);
        }
        window.draw(fisherman.sprite);
        window.display();
}
void Game::spawnFish(){
    fishSwarm.push_back(Fish{});
    srand (time(NULL));

    for(auto &fish: fishSwarm){
        if(!fish.sprite.getGlobalBounds().intersects(fishBounding.getGlobalBounds())){
            fish.sprite.setPosition(fishBounding.getPosition().x + ((rand() % 150 + 1) - (rand() % 300 + 1)), fishBounding.getPosition().y + (rand() % 150 + 1)- (rand() % 300 + 1));
        }

    }
}