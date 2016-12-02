//Project Includes
#include "./simulation.h"

//Dep includes
#include "../deps/FastNoise/FastNoise.h"

//STL Includes
#include <random>
#include <iostream>

Simulation::Simulation(std::shared_ptr<Environment> e, std::shared_ptr<AI> a) {
    environment = e;
    ants.push_back(std::shared_ptr<Ant>(new Ant(a)));
}