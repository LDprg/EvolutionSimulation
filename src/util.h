//
// Created by LD on 01.09.2022.
//

#ifndef EVOLUTIONSIMULATION_UTIL_H
#define EVOLUTIONSIMULATION_UTIL_H

#include <random>

std::random_device rd;
std::default_random_engine eng(rd());

inline float randomFloat(float min, float max) {
    std::uniform_real_distribution<float> dist(min, max);
    return dist(eng);
}

inline sf::Uint8 randomUint8(sf::Uint8 min, sf::Uint8 max) {
    std::uniform_int_distribution<sf::Uint8> dist(min, max);
    return dist(eng);
}

#endif //EVOLUTIONSIMULATION_UTIL_H
