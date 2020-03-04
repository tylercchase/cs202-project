#ifndef Fish_HPP
#define Fish_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

static sf::Texture fishTexture;

class Fish{
    public:
        sf::Sprite sprite;

        Fish(){
                if(!fishTexture.loadFromFile("fish.png")){
                        std::cout << "Can't load fish" << std::endl;
                }
            
            sprite.setTexture(fishTexture);
            sprite.setScale(0.2,0.2);
        }
        
    private:
};

#endif