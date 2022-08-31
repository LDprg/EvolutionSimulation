#include "SFML/Graphics.hpp"
#include <entt/entt.hpp>

int main() {
    entt::registry registry;
    const auto entity = registry.create();
    registry.emplace<int>(entity, 2.f);

    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}