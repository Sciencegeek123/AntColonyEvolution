#pragma once

// Project Includes
#include "../ant/ant.h"
#include "utils/utils.h"

// STL Includes
#include <array>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <iostream>

//deps
#include "deps/json.hpp"
using nlohmann::json;

class Environment;
class AI;
class Ant;

class Simulation
{
private:
  std::shared_ptr<Environment> environment;
  std::vector<std::shared_ptr<Ant>> ants, deadAnts;

public:
  Simulation(std::shared_ptr<Environment> e, std::shared_ptr<AI> a);
  int actionCount[OutputActions::OutputActionsSize];

  void Run(int duration);
  void Report();
  void SubmitSearch();
  json GetJSON(std::string type);
  bool IsOverThreshold(int threshold = 10)
  {

    if (environment->colony->food_income > 0)
      return true;

    for (auto a : ants)
    {
      if (a->food_income > threshold)
        return true;
    }

    for (auto a : deadAnts)
    {
      if (a->food_income > threshold)
        return true;
    }

    return false;
  }
};