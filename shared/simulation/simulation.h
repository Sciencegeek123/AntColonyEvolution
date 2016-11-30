#pragma once

//Project Includes
#include "../logging/logging.h"
#include "../ant/ant.h"
#include "../config.h"

//STL Includes
#include <string>
#include <array>
#include <memory>
#include <vector>

class Environment;
class AI;

class Simulation {
private:    
    std::shared_ptr<Environment> environment;
    std::vector<std::shared_ptr<Ant>> ants;

public:
    Simulation(std::shared_ptr<Environment> e, std::shared_ptr<AI> a) {
        environment = e;
        ants.push_back(std::shared_ptr<Ant>(new Ant(a)));
    }
};