//
// Created by LD on 31.08.2022.
//

#ifndef EVOLUTIONSIMULATION_GAME_H
#define EVOLUTIONSIMULATION_GAME_H

#include "SFML/Graphics.hpp"
#include "entt/entt.hpp"
#include <iostream>

class Game {
public:
    Game(sf::String title, sf::Vector2u windowSize);

    void run();

    void cleanup();

private:
    sf::RenderWindow window;
    sf::Clock clock;

    entt::registry registry;

    void handleEvents(sf::Event event);

    void update();

    void draw();
};


#endif //EVOLUTIONSIMULATION_GAME_H
