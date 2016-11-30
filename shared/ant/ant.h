#pragma once

//Project Includes
#include "../logging/logging.h"
#include "../ai/ai.h"

//STL Includes
#include <string>
#include <array>
#include <memory>

class Ant {
    private:
        std::shared_ptr<Ant> myAnt;
    public:
        Ant(std::shared_ptr<AI> ai);
};