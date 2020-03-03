#ifndef Game_HPP
#define Game_HPP

#include <SFML/Graphics.hpp>
#include "Fish.hpp"
#include "Fisherman.hpp"
class Game {
    public:
        // Game();
        // ~Game();
        void run();
        Fish fish;
        Fisherman fisherman;
        sf::RenderWindow window{sf::VideoMode(1000, 600), "Epic Fish Fighting Game"};

    private:
        void processKeys();
        void update();
        void render();
        void processEvents();
};

#endif