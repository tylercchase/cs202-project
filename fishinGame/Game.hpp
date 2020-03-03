#ifndef Game_HPP
#define Game_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include "Fish.hpp"
#include "Fisherman.hpp"
class Game {
    public:
        Game(){
            fisherman.sprite.setPosition(500,300);
            fishBounding.setOrigin(150,150);
            
        }
        // ~Game();
        void run();
        sf::CircleShape fishBounding;
        std::vector<Fish> fishSwarm{1};
        Fisherman fisherman;
        sf::RenderWindow window{sf::VideoMode(1500, 800), "Epic Fish Fighting Game"};
                
    private:
        void processKeys();
        void update();
        void render();
        void processEvents();
        void spawnFish();
};

#endif