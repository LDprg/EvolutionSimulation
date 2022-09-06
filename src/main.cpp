#include "Game.h"

int main() {
    Game EvolutionSimulation("Evolution Simulation", {1920, 1080});

    EvolutionSimulation.run();

    EvolutionSimulation.cleanup();

    return 0;
}