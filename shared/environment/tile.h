#pragma once

// Project Includes
#include "../config.h"
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

enum TileType {
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

const int TileTypeProbs[5] = {
    1,  // Food
    3,  // Plant
    5,  // Sand
    1,  // Trap
    90  // Grass
};

struct Tile {
 private:
  byte height;
  std::vector<std::shared_ptr<Ant>> ants;

 public:
  // Construction and data
  Tile(TileType t, byte h) : type(t), height(h){};
  const TileType type;
  byte getHeight() { return height; }

  const std::vector<std::shared_ptr<Ant>> getAnts();

  // Preparing Input
  virtual std::array<byte, 64> LayerInput(Ant &, Simulation &) {
    return std::array<byte, 64>();
  };

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