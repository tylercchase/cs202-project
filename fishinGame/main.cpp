#include <SFML/Graphics.hpp>
#include "Fish.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    Fish f{};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
             f.sprite.move(.1,0);
        }
        window.clear();
        // window.draw(shape);
        window.draw(f.sprite);
        window.display();
    }

    return 0;
}