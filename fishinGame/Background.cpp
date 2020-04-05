#include "Background.hpp"

void Background::activateEatinTime(){
    sprite.setTexture(eatinBackgroundTexture);
}
void Background::startGame(){
    sprite.setTexture(backgroundTexture);
}
void Background::menuScreen(){

}
Background::Background(){
    if(!backgroundTexture.loadFromFile("assets/Background.png",sf::IntRect(0,0,1500,800))){
            std::cout << "Can't load background" << std::endl;
    }
    if(!eatinBackgroundTexture.loadFromFile("assets/Background_eatintime.png",sf::IntRect(0,0,1500,800))){
            std::cout << "Can't load eatin background" << std::endl;
    }
    if(!startBackground.loadFromFile("assets/start.png",sf::IntRect(0,0,1500,800))){
        std::cout << "Can't load start menu background" << std::endl;
    }
    
    sprite.setTexture(startBackground);
}