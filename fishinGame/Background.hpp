#ifndef Background_HPP
#define Background_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

static sf::Texture backgroundTexture;

class Background{
    public:
        sf::Sprite sprite;

        Background(){
            if(!backgroundTexture.loadFromFile("background.png",sf::IntRect(0,0,1500,800))){
                    std::cout << "Can't load background" << std::endl;
            }
            
            sprite.setTexture(backgroundTexture);
        }
        
    private:
};

#endif