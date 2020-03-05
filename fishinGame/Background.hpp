#ifndef Background_HPP
#define Background_HPP

#include <SFML/Graphics.hpp>
#include <iostream>


class Background{
    public:
        sf::Sprite sprite;
        sf::Texture backgroundTexture;
        sf::Texture eatinBackgroundTexture;
        Background(){
            if(!backgroundTexture.loadFromFile("Background.png",sf::IntRect(0,0,1500,800))){
                    std::cout << "Can't load background" << std::endl;
            }
            if(!eatinBackgroundTexture.loadFromFile("Background_eatintime.png",sf::IntRect(0,0,1500,800))){
                    std::cout << "Can't load eatin background" << std::endl;
            }
            
            sprite.setTexture(backgroundTexture);
        }
        void activateEatinTime();
    private:
};

#endif