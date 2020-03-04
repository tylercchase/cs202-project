#ifndef Food_HPP
#define Food_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

static sf::Texture foodTexture;

class Food {
    public:
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