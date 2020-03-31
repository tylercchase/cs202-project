#include "Food.hpp"
Food::Food(){
    if(!foodTexture.loadFromFile("food.png")){
            std::cout << "Can't load food" << std::endl;
    }
    sprite.setTexture(foodTexture);
    sprite.setScale(0.15,0.15);
}