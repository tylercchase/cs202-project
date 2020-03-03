#ifndef Fisherman_HPP
#define Fisherman_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Fisherman{
    public:
        int x;
        int y;
        float rotation; 
        sf::RectangleShape shape;
        sf::Sprite sprite;

        Fisherman(){
            if(!fishTexture.loadFromFile("fish.png")){
                std::cout << "Can't load fish" << std::endl;
            }
            sprite.setTexture(fishTexture);
            sprite.setScale(0.2,0.2);
        }
    private:
        sf::Texture fishTexture;
};

#endif