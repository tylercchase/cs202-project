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
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::V){
            spawnFood();
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
                    fish.sprite.setTextureRect(sf::IntRect(300, 0, -300, 300));;

                }
            }


        }
        //Left
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            if ( fishBounding.getPosition().x <= 0 ) {
            }else{
                fishBounding.move(-0.1,0);
                for(auto &fish: fishSwarm){
                    fish.sprite.move(-.1,0);
                    fish.sprite.setTextureRect(sf::IntRect(0, 0, 300, 300));;

                }
            }
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
                fisherman.sprite.move(.08,0);
            }

            fisherman.sprite.setTextureRect(sf::IntRect(300, 0, -300, 300));;

        }
        //Left
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::J)){
            if ( fisherman.sprite.getPosition().x <= 0 ) {
            }else{
                fisherman.sprite.move(-0.08,0);
            }
            fisherman.sprite.setTextureRect(sf::IntRect(0, 0, 300, 300));;
        }
        //Down
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::K)){
            if ( fisherman.sprite.getPosition().y + 50 >= window.getSize().y ) { }
            else {
                fisherman.sprite.move(0,0.08);
            }
        }
        //Up
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::I)){
            if ( fisherman.sprite.getPosition().y <= 0 ) {

            }
            else {
                fisherman.sprite.move(0,-0.08);
            }

        }
        
}
void Game::update(){
    int counter{0};
    for(auto& fish : fishSwarm){
        if(fish.sprite.getGlobalBounds().intersects(fisherman.sprite.getGlobalBounds())){
            std::cout << "Fish collided with fisherman!" << std::endl;
            fishSwarm.erase(fishSwarm.begin() + counter);
            if(fishSwarm.size() == 0){
                //Initiate fisherman win
            }
        }
        int counterFood{0};
        for(auto &food : foodGroup){
            if(fish.sprite.getGlobalBounds().intersects(food.sprite.getGlobalBounds())){
                std::cout << "Fish collided with food!" << std::endl;
                foodGroup.erase(foodGroup.begin() + counterFood);
                spawnFish();
            }
            counterFood++;
        }
        while(!fish.sprite.getGlobalBounds().intersects(fishBounding.getGlobalBounds())){
            fish.sprite.setPosition(fishBounding.getPosition().x, fishBounding.getPosition().y);
        }
        counter++;
    }
    lastFoodTime += clock.restart();
    if(lastFoodTime >= foodFrequency){
        spawnFood();
        std::cout << "SPAWNING FOOD: " << std::endl;
        lastFoodTime -= foodFrequency;
    }
    
}
void Game::render(){
        window.clear();
        fishBounding.setRadius(100.0f);
        for(auto &fish : fishSwarm){
            window.draw(fish.sprite);
        }
        for(auto &food : foodGroup){
            window.draw(food.sprite);
        }
        window.draw(fisherman.sprite);
        window.display();
}
void Game::spawnFish(){
    fishSwarm.push_back(Fish{});
    srand (time(NULL));

    for(auto &fish: fishSwarm){
        if(!fish.sprite.getGlobalBounds().intersects(fishBounding.getGlobalBounds())){
            fish.sprite.setPosition(fishBounding.getPosition().x + ((rand() % 100 + 1) - (rand() % 200 + 1)), fishBounding.getPosition().y + (rand() % 100 + 1)- (rand() % 200 + 1));
        }

    }
}
void Game::spawnFood(){
    foodGroup.push_back(Food{});
    auto &food = foodGroup.back();
    srand (time(NULL));
    food.sprite.setPosition(rand() % 1200 + 50, rand() % 700 + 50);
}