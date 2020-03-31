#ifndef Background_HPP
#define Background_HPP

#include <SFML/Graphics.hpp>
#include <iostream>


class Background{
    public:
        sf::Sprite sprite;
        sf::Texture backgroundTexture;
        sf::Texture eatinBackgroundTexture;
        Background();
        void activateEatinTime();
    private:
};

#endif