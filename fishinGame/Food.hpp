#ifndef Food_HPP
#define Food_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

static sf::Texture foodTexture;

class Food {
    public:
        int x;
        int y;
        float rotation; 
        sf::RectangleShape shape;
        sf::Sprite sprite;

        Food(){
            if(!foodTexture.loadFromFile("food.png")){
                    std::cout << "Can't load food" << std::endl;
            }
            sprite.setTexture(foodTexture);
            sprite.setScale(0.15,0.15);
        }
        
    private:
};

#endif