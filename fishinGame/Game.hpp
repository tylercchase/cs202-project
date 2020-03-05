#ifndef Game_HPP
#define Game_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include "Fish.hpp"
#include "Fisherman.hpp"
#include "Food.hpp"
#include "Background.hpp"
class Game {
    public:
        Game(){
            fisherman.sprite.setPosition(500,300);
            fishBounding.setOrigin(150,150);
        }
        // ~Game();
        void run();
        sf::CircleShape fishBounding;
        sf::Time lastFoodTime;
        sf::Clock clock;
        sf::Time foodFrequency = sf::seconds(5);
        Background background;
        std::vector<Fish> fishSwarm{1};
        std::vector<Food> foodGroup;
        bool eatin{false};
        Fisherman fisherman;
        sf::RenderWindow window{sf::VideoMode(1500, 800), "Epic Fish Fighting Game"};
                
    private:
        void processKeys();
        void update();
        void render();
        void processEvents();
        void spawnFish();
        void spawnFood();
        void startEatinTime();
};

#endif