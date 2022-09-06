//
// Created by LD on 31.08.2022.
//

#include <Eigen/Core>

#include "Game.h"
#include "Comp.h"
#include "util.h"

Game::Game(sf::String title, sf::Vector2u windowSize)
        : window(sf::VideoMode(windowSize), title) {
    for (int i = 0; i < 250; ++i) {
        const auto entity = registry.create();
        sf::CircleShape shape(10.f);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition({randomFloat(0, (float)window.getSize().x), randomFloat(0, (float)window.getSize().y)});
        registry.emplace<core>(entity, shape);
    }
}

void Game::run() {
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            handleEvents(event);
        }

        update();

        window.clear();
        draw();
        window.display();

        float dt = clock.restart().asSeconds();
        std::cout << "Time: " << dt << "\tFPS: " << 1.f / dt << std::endl;
    }
}

void Game::cleanup() {
    registry.clear();
}

void Game::handleEvents(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            window.close();
        }
        if (event.key.code == sf::Keyboard::Space) {
            registry.view<core>().each([this](auto entity, auto &core) {
                core.shape.setPosition({randomFloat(0, (float)window.getSize().x), randomFloat(0, (float)window.getSize().y)});
            });
        }
    }
}

void Game::update() {
    registry.view<core>().each([this](auto entity, auto &core) {
//        core.shape.move({randomFloat(-1, 1), randomFloat(-1, 1)});
        core.shape.setFillColor(sf::Color::Green);
    });

    registry.view<core>().each([this](auto entity1, auto &core1) {
        Eigen::Vector2f pos1(core1.shape.getPosition().x, core1.shape.getPosition().y);

        for (auto [entity2, core2] : registry.view<core>().each()) {
            if(entity1 == entity2) return;

            Eigen::Vector2f pos2(core2.shape.getPosition().x, core2.shape.getPosition().y);

            Eigen::Vector2f dist = pos1 - pos2;
            dist = dist.cwiseAbs();
            float dist2 = dist.norm();

            if (dist2 < core1.shape.getRadius() + core2.shape.getRadius()) {

                core1.shape.setFillColor(sf::Color::Red);

                return;
            }
        }
    });
}

void Game::draw() {
    auto coreView = registry.view<core>();
    for (auto entity: coreView) {
        auto &coreComp = coreView.get<core>(entity);
        window.draw(coreComp.shape);
    }
}
