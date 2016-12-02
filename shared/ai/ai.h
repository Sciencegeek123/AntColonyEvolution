#pragma once

// Project Includes
#include "utils/utils.h"
#include "ai/ai_enums.h"

// STL Includes
#include <array>
#include <memory>
#include <string>

class AI {
 protected:
  AI(std::string input);
  std::string GeneticString;

 public:
  virtual std::string getTypeName();
  static std::shared_ptr<AI> createRandom();
  static std::shared_ptr<AI> createFrom(std::string &input);

  virtual std::string GetGeneticString();

  virtual OutputActions get(ACSData input);
};