#pragma once

// Project Includes
#include "utils/utils.h"

// STL Includes
#include <array>
#include <memory>
#include <string>
#include <set>

struct AntComparator;
class Ant;

class AI
{
protected:
  AI(std::string input);
  std::string GeneticString;

public:
  virtual std::string getTypeName();
  static std::shared_ptr<AI> createRandom();
  static std::shared_ptr<AI> createFrom(std::string &input);

  virtual std::shared_ptr<AI> reproduce(std::shared_ptr<std::set<std::shared_ptr<Ant>, AntComparator>> parents);

  virtual std::string GetGeneticString();

  virtual OutputActions get(ACSData input);
};