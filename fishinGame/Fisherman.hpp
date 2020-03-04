#ifndef Fisherman_HPP
#define Fisherman_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Fisherman{
    public:
        sf::Sprite sprite;

        Fisherman(){
            if(!fishTexture.loadFromFile("fisherman.png")){
                std::cout << "Can't load fisherman" << std::endl;
            }
            sprite.setTexture(fishTexture);
            sprite.setScale(0.3,0.3);
        }
    private:
        sf::Texture fishTexture;
};

#endif