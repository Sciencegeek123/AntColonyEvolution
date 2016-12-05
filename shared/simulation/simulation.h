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
};