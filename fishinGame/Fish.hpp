#ifndef Fish_HPP
#define Fish_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Fish{
    public:
        int x;
        int y;
        float rotation; 
        sf::RectangleShape shape;
        sf::Sprite sprite;
        sf::Texture fishTexture;

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