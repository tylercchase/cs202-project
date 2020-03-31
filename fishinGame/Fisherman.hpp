#ifndef Fisherman_HPP
#define Fisherman_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Fisherman{
    public:
        sf::Sprite sprite;

        Fisherman();
    private:
        sf::Texture fishTexture;
};

#endif