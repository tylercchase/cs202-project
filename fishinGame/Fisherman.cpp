#include "Fisherman.hpp"
Fisherman::Fisherman(){
    {
            if(!fishTexture.loadFromFile("assets/fisherman.png")){
                std::cout << "Can't load fisherman" << std::endl;
            }
            sprite.setTexture(fishTexture);
            sprite.setScale(0.3,0.3);
        }
}