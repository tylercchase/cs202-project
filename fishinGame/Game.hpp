#ifndef Game_HPP
#define Game_HPP

#include <SFML/Graphics.hpp>
#include "Fish.hpp"

class Game {
    public:
        // Game();
        // ~Game();
        void run();
        Fish fish;
    private:
        void processEvents();
};

#endif