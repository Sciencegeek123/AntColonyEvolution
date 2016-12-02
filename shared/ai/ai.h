#pragma once

// Project Includes
#include "../logging/logging.h"
#include "./ai_enums.h"

// STL Includes
#include <array>
#include <memory>
#include <string>

class AI {
 protected:
  AI(std::string &input){};
  AI(){};

 public:
  virtual std::string getTypeName() { return std::move("BASE"); }
  static std::shared_ptr<AI> createRandom() {
    return std::shared_ptr<AI>(new AI());
  }
  static std::shared_ptr<AI> createFrom(std::string &input) {
    return std::shared_ptr<AI>(new AI(input));
  }
  virtual OutputActions get(std::array<unsigned char, 64> input) {
    return OutputActions::NoOP;
  }
};