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

struct Environment
{
private:
  std::array<Tile *, ENV_SIZE> map;
  std::array<float, ENV_SIZE> colonyActiveScent;
  std::array<float, ENV_SIZE> colonyPassiveScent;
  void PopulateTiles(int seed);

public:
  Environment();                  // Generate rfandom Environment
  Environment(unsigned int seed); // Generate Environment from seed.
  ColonyTile *colony;
  unsigned int iteration = 0;

  inline Tile *&get(const byte &x, const byte &y)
  {
    return map.at(x + y * ENV_SIDE);
  }

  inline Tile *&get(const std::pair<byte, byte> &P)
  {
    return map.at(P.first + P.second * ENV_SIDE);
  }

  // Get scents
  byte getColonyScent(ScentTypes type, int x, int y);

  ACSData GetInput(std::shared_ptr<Ant> &ant);
  bool EvaluateAction(OutputActions oa, std::shared_ptr<Ant> &ant);

  void ReleaseSmallScentC(std::shared_ptr<Ant> &);
  void ReleaseLargeScentC(std::shared_ptr<Ant> &);

  void Step();

  void Print();
};
