#include "Fish.hpp"

Fish::Fish(){
    if(!fishTexture.loadFromFile("fish.png")){
            std::cout << "Can't load fish" << std::endl;
    }

    sprite.setTexture(fishTexture);
    sprite.setScale(0.2,0.2);
        
}