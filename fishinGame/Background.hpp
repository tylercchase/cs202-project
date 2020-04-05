#ifndef Background_HPP
#define Background_HPP

#include <SFML/Graphics.hpp>
#include <iostream>


class Background{
    public:
        sf::Sprite sprite;
        sf::Texture backgroundTexture;
        sf::Texture eatinBackgroundTexture;
        sf::Texture startBackground;
        Background();
        void activateEatinTime();
        void startGame();
        void menuScreen();
    private:
};

#endif