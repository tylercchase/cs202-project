#ifndef Game_HPP
#define Game_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <random>
#include<SFML/Window/Joystick.hpp>
#include "Fish.hpp"
#include "Fisherman.hpp"
#include "Food.hpp"
#include "Background.hpp"
class Game {
    public:
        Game(){
            fisherman.sprite.setPosition(500,300);
            fishBounding.setOrigin(150,150);
            fishBounding.setRadius(100.0f);
            if(!backgroundMusic.openFromFile("assets/background.ogg")){

            }
        }
        // ~Game();
        void run();
        void Init();
        sf::CircleShape fishBounding;
        sf::Time lastFoodTime;
        sf::Clock clock;
        sf::Time foodFrequency = sf::seconds(5);
        Background background;
        std::vector<Fish> fishSwarm{1};
        std::vector<Food> foodGroup;
        bool eatin{false};
        Fisherman fisherman;
        sf::RenderWindow window{sf::VideoMode(1500, 800), "Epic Fish Fighting Game",sf::Style::Titlebar|sf::Style::Close};
        sf::Text board;
        sf::Music backgroundMusic;
        float fishSpeed{0.2};
        float fishermanSpeed{0.15};
        enum sceneEnum{
            STARTSCENE,
            WINSCENE,
            GAMESCENE
        };
        sceneEnum currentScene{STARTSCENE};
        void startScene();
        void gameScene();
        void winScene();
                
    private:
        void processKeys();
        void update();
        void render();
        void processEvents();
        void spawnFish();
        void spawnFood();
        void startEatinTime();
        void fishWin();
        void fishermanWin();
};

#endif