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
        std::shared_ptr<AI> brain;
    public:
        Ant(std::shared_ptr<AI> ai);
};