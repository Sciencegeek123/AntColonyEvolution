#pragma once

// Project Includes
#include "../ai/ai.h"
#include "../logging/logging.h"

// STL Includes
#include <array>
#include <memory>
#include <string>

class Ant {
 private:
  std::shared_ptr<AI> brain;

 public:
  Ant(std::shared_ptr<AI> ai);
};