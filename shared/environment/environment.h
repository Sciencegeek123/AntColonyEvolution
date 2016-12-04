#pragma once

// Project Includes
#include "environment/tile.h"
#include "utils/utils.h"

// Dep Includes
#include <array>
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

// Declarations
class Ant;
class Simulation;

struct Environment {
 private:
  std::array<std::shared_ptr<Tile>, ENV_SIZE> map;
  void PopulateTiles(int seed);

 public:
  Environment();                   // Generate rfandom Environment
  Environment(unsigned int seed);  // Generate Environment from seed.
  std::shared_ptr<ColonyTile> colony;
  unsigned int iteration = 0;

  inline std::shared_ptr<Tile> get(const byte &x, const byte &y) {
    return map.at(x + y * ENV_SIDE);
  }

  ACSData GetInput(std::shared_ptr<Ant> &ant);
  void EvaluateAction(OutputActions oa, std::shared_ptr<Ant> &ant){};

  void Print();
};
