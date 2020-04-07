#include "Game.hpp"

void Game::run(){
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    const float fps = 60.0f;
    sf::Time timePerFrame = sf::seconds(1.0f/fps);
    window.setPosition(sf::Vector2i(100,100));
    sf::Font font;
    if (!font.loadFromFile("assets/BarlowSemiCondensed-Regular.ttf"))
    {
        // error...
    }
    board.setFont(font);
    board.setCharacterSize(24);
    board.setFillColor(sf::Color::Green);
    board.setPosition(400,0);


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
    //Movement Using Controller
    bool connected = sf::Joystick::isConnected(0);
    unsigned int buttons = sf::Joystick::getButtonCount(0);
    switch (currentScene)
    {
    case STARTSCENE:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
            currentScene = GAMESCENE;
            backgroundMusic.play();
            background.startGame();
        }
        break;
    case GAMESCENE:
    if (connected) {
        //Controller Joystick Movement
        float xController = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
        float yController = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

        if (xController > 5.0f|| xController<-5.0f) {//Left & Right
            std::cout << yController << "=y  " << xController << "=x. X-control\n";//Debugging
            if (fishBounding.getPosition().x <= 0 || fishBounding.getPosition().x + 50 >= window.getSize().x) {
            }else {
                fishBounding.move(0.3 * (xController / 100.0),0);
                for (auto& fish : fishSwarm) {
                    fish.sprite.move(0.3 * (xController / 100.0),0);
                }
            }
            
        }
        if (yController > 5.0f || yController < -5.0f) {//Up & Down
            std::cout << yController << "=y  " << xController << "=x. Y-control\n";//Debugging
            if (fishBounding.getPosition().y <= 0 || fishBounding.getPosition().y + 50 >= window.getSize().y) {
            }else {

                fishBounding.move(0, 0.3 * (yController / 100.0));
                for (auto& fish : fishSwarm) {
                    fish.sprite.move(0, 0.3 * (yController / 100.0));
                }
                
            }
            
        }
        

        //Controller button push Movement
        if (sf::Joystick::isButtonPressed(0, 1)) {//down
            std::cout << "Button 1.\n";
            if (fishBounding.getPosition().y + 50 >= window.getSize().y) {}
            else {
                fishBounding.move(0, 0.3f);
                for (auto& fish : fishSwarm) {
                    fish.sprite.move(0, 0.3f);
                }
            }
        }
        if (sf::Joystick::isButtonPressed(0, 2)) {
            std::cout << "Button 2.\n";
        }
        if (sf::Joystick::isButtonPressed(0, 3)) {//up
            std::cout << "Button 3.\n";
            if (fishBounding.getPosition().y <= 0) {}
            else {
                fishBounding.move(0, -0.3f);
                for (auto& fish : fishSwarm) {
                    fish.sprite.move(0, -0.3f);
                }
            }
        }
        if (sf::Joystick::isButtonPressed(0, 4)) {//left
            std::cout << "Button 4.\n";
            if (fishBounding.getPosition().x <= 0) {
            }
            else {
                fishBounding.move(-0.3f, 0);
                for (auto& fish : fishSwarm) {
                    fish.sprite.move(-.3f, 0);
                    fish.sprite.setTextureRect(sf::IntRect(0, 0, 300, 300));;

                }
            }
        }
        if (sf::Joystick::isButtonPressed(0, 5)) {//right
            std::cout << "Button 5.\n";
            if (fishBounding.getPosition().x + 50 >= window.getSize().x) {}
            else {
                fishBounding.move(.3, 0);
                for (auto& fish : fishSwarm) {
                    fish.sprite.move(.3, 0);
                    fish.sprite.setTextureRect(sf::IntRect(300, 0, -300, 300));;

                }
            }
        }
        //NO USE for buttons 6-14
        
    }else {    //Fish Movement using keyboard
        //Right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (fishBounding.getPosition().x + 50 >= window.getSize().x) {}
            else {
                fishBounding.move(.3, 0);
                for (auto& fish : fishSwarm) {
                    if(fish.sprite.getPosition().x + 50 >= window.getSize().x){}
                    else{
                        fish.sprite.move(.3,0);                        
                    }
                    fish.sprite.setTextureRect(sf::IntRect(300, 0, -300, 300));;

                }
            }
        }
        //Left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            if (fishBounding.getPosition().x <= 0) {
            }
            else {
                fishBounding.move(-0.3, 0);
                for (auto& fish : fishSwarm) {
                    if(fish.sprite.getPosition().x <=0){}
                    else{
                        fish.sprite.move(-.3,0);
                    }
                    fish.sprite.setTextureRect(sf::IntRect(0, 0, 300, 300));;

                }
            }
        }
        //Down
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            if (fishBounding.getPosition().y + 50 >= window.getSize().y) {}
            else {
                fishBounding.move(0, 0.3);
                for (auto& fish : fishSwarm) {
                    if(fish.sprite.getPosition().y + 50 >= window.getSize().y ){}
                    else{
                        fish.sprite.move(0,0.3);

                    }
                }
            }
        }
        //Up
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            if (fishBounding.getPosition().y <= 0) {

            }
            else {
                fishBounding.move(0, -0.3);
                for (auto& fish : fishSwarm) {
                    if(fish.sprite.getPosition().y <= 0){}
                    else{
                        fish.sprite.move(0,-0.3);
                    }
                }
            }
        }
        //Fisherman Movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        {
            if (fisherman.sprite.getPosition().x + 50 >= window.getSize().x) {}
            else {
                fisherman.sprite.move(.13, 0);
            }
            fisherman.sprite.setTextureRect(sf::IntRect(300, 0, -300, 300));;
        }
        //Left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
            if (fisherman.sprite.getPosition().x <= 0) {
            }
            else {
                fisherman.sprite.move(-0.13, 0);
            }
            fisherman.sprite.setTextureRect(sf::IntRect(0, 0, 300, 300));;
        }
        //Down
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
            if (fisherman.sprite.getPosition().y + 50 >= window.getSize().y) {}
            else {
                fisherman.sprite.move(0, 0.13);
            }
        }
        //Up
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
            if (fisherman.sprite.getPosition().y <= 0) {

            }
            else {
                fisherman.sprite.move(0, -0.13);
            }

        }
    }
        break;
    default:
        break;
    }
    
}
void Game::update(){
    if(currentScene == GAMESCENE){
    int counter{0};
    for(auto& fish : fishSwarm){
        if(fish.sprite.getGlobalBounds().intersects(fisherman.sprite.getGlobalBounds())){
            std::cout << "Fish collided with fisherman!" << std::endl;
            if(!eatin){
                fishSwarm.erase(fishSwarm.begin() + counter);
            }else{
                fisherman.sprite.setScale(0,0);
                fishWin();
            }
            if(fishSwarm.size() == 0){
                fishermanWin();
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
    if(lastFoodTime >= foodFrequency && !eatin){
        spawnFood();
        lastFoodTime -= foodFrequency;
    }
    if(eatin){
        window.setPosition(sf::Vector2i(100 + rand() % 5, 100 + rand() % 5));
    }
    }

}
void Game::render(){
        window.clear();
        window.draw(background.sprite);
        switch (currentScene)
        {
        case STARTSCENE:
            /* code */
            break;
        case GAMESCENE:
            gameScene();
            break;
        default:
            break;
        }

        window.display();
}

void Game::startScene(){

}
void Game::gameScene(){
    for(auto &fish : fishSwarm){
        window.draw(fish.sprite);
    }
    for(auto &food : foodGroup){
        window.draw(food.sprite);
    }
    window.draw(fisherman.sprite);
    window.draw(board);
}

void Game::spawnFish(){
    fishSwarm.push_back(Fish{});
    srand (time(NULL));

    for(auto &fish: fishSwarm){
        if(!fish.sprite.getGlobalBounds().intersects(fishBounding.getGlobalBounds())){
            fish.sprite.setPosition(fishBounding.getPosition().x + ((rand() % 100 + 1) - (rand() % 200 + 1)), fishBounding.getPosition().y + (rand() % 100 + 1)- (rand() % 200 + 1));
        }

    }
    if(fishSwarm.size() == 10){
        startEatinTime();
    }
}
void Game::spawnFood(){
    foodGroup.push_back(Food{});
    auto &food = foodGroup.back();
    srand (time(NULL));
    food.sprite.setPosition(rand() % 1200 + 50, rand() % 700 + 50);
}
void Game::startEatinTime(){
    background.activateEatinTime();
    eatin = true;
}
void Game::fishWin(){
    board.setString("fish wins!");
}
void Game::fishermanWin(){
    board.setString("fisherman wins!");
}