#pragma once

// Project Includes
#include "utils/utils.h"

// Dep Includes
#include <array>
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <list>

// Declarations
class Ant;
class Simulation;

enum TileType : byte {
  Colony = 255,
  Food = 127,
  Plant = 63,
  Road = 31,
  Grass = 15,
  Sand = 7,
  Trap = 3,
  Wall = 1,
  Null = 0
};

// These are the thresholds.
const int TileTypeProbs[6] = {
    100,  // Grass
    400,  // Plant I want plants to be able to spawn sooner, but also want a lot
          // of grass
    600,  // Grass
    700,  // Sand
    750,  // Trap
    900,  // Food
          // Grass
};

enum ScentTypes : byte {
  PersonalPassiveScent,
  PersonalActiveScentA,
  PersonalActiveScentB,
  ColonyPassiveScent,
  ColonyActiveScent,
};

struct Tile {
 private:
  struct AntComparator
      : public std::binary_function<std::shared_ptr<Ant>, std::shared_ptr<Ant>,
                                    bool> {
    bool operator()(const std::shared_ptr<Ant> &lhs,
                    const std::shared_ptr<Ant> &rhs) const;
  };

 public:
  byte height;
  std::vector<std::shared_ptr<Ant>> ants;
  std::map<ScentTypes, std::map<std::shared_ptr<Ant>, float, AntComparator>>
      scentMaps;

  // Construction and data
  Tile(TileType t, byte h) : type(t), height(h){};
  const TileType type;
  byte getHeight() { return height; }

  // Get ants
  byte getNumAnts() { return ants.size() > 255 ? 255 : ants.size(); }
  std::vector<std::shared_ptr<Ant>> getAnts();

  // Get scents
  byte getScent(ScentTypes type, std::shared_ptr<Ant> &ant);

  // Generic Actions
  bool ReleaseSmallScentA(Ant &, Simulation &);
  bool ReleaseLargeScentA(Ant &, Simulation &);
  bool ReleaseSmallScentB(Ant &, Simulation &);
  bool ReleaseLargeScentB(Ant &, Simulation &);
  bool ReleaseSmallScentC(Ant &, Simulation &);
  bool ReleaseLargeScentC(Ant &, Simulation &);
  bool LowerHeight(Ant &, Simulation &);
  bool RaiseHeight(Ant &, Simulation &);

  // Actions that depend on Tile Type
  bool MoveTo(Ant &, Simulation &) { return false; }
  bool MoveFrom(Ant &, Simulation &) { return false; }
  bool Idle(Ant &, Simulation &) { return false; }
  bool Harvest(Ant &, Simulation &) { return false; };
  bool Give(Ant &, Simulation &) { return false; };
  bool Take(Ant &, Simulation &) { return false; };
  bool Work(Ant &, Simulation &) { return false; };
  bool Build(Ant &, Simulation &) { return false; };
};

struct ColonyTile : public Tile {
 public:
  ColonyTile(byte h) : Tile(TileType::Colony, h){};
  byte memory_static_a = 0;
  byte memory_static_b = 0;
  byte memory_static_c = 0;
  byte memory_static_d = 0;
  unsigned int ColonyTimerA;
  unsigned int ColonyTimerB;

  // Food
  unsigned int food_income = 0;
  unsigned int food_expense = 0;
  unsigned int food_net = 0;
  std::list<int> food_change_log;
};

struct FoodTile : public Tile {
 public:
  FoodTile(byte h) : Tile(TileType::Food, h){};
};

struct PlantTile : public Tile {
 public:
  PlantTile(byte h) : Tile(TileType::Plant, h){};
};

struct RoadTile : public Tile {
 public:
  RoadTile(byte h) : Tile(TileType::Road, h){};
};

struct GrassTile : public Tile {
 public:
  GrassTile(byte h) : Tile(TileType::Grass, h){};
};

struct SandTile : public Tile {
 public:
  SandTile(byte h) : Tile(TileType::Sand, h){};
};

struct TrapTile : public Tile {
 public:
  TrapTile(byte h) : Tile(TileType::Trap, h){};
};

struct WallTile : public Tile {
 public:
  WallTile(byte h) : Tile(TileType::Wall, h){};
};