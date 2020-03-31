#include "Background.hpp"

void Background::activateEatinTime(){
    sprite.setTexture(eatinBackgroundTexture);
}
Background::Background(){
    if(!backgroundTexture.loadFromFile("Background.png",sf::IntRect(0,0,1500,800))){
            std::cout << "Can't load background" << std::endl;
    }
    if(!eatinBackgroundTexture.loadFromFile("Background_eatintime.png",sf::IntRect(0,0,1500,800))){
            std::cout << "Can't load eatin background" << std::endl;
    }
    
    sprite.setTexture(backgroundTexture);
}