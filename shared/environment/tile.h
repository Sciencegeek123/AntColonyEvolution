#pragma once

// Project Includes
#include "utils/utils.h"
#include "ant/ant_comparator.h"

// Dep Includes
#include <array>
#include <iomanip>
#include <iostream>
#include <memory>
#include <set>
#include <map>
#include <list>

// Declarations
class Simulation;

enum TileType : byte
{
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
    100, // Grass
    400, // Plant I want plants to be able to spawn sooner, but also want a lot
         // of grass
    600, // Grass
    700, // Sand
    750, // Trap
    900, // Food
         // Grass
};

enum ScentTypes : byte
{
  PersonalPassiveScent,
  PersonalActiveScentA,
  PersonalActiveScentB,
  ColonyActiveScent,
  ColonyPassiveScent
};

struct Tile
{
public:
  byte height;
  std::shared_ptr<std::set<std::shared_ptr<Ant>, AntComparator>> ants;
  const int position;

  float ColonyActiveScent = 0, ColonyPassiveScent = 0;

  // Construction and data
  Tile(TileType t, byte h, int p)
      : type(t), height(h), position(p), ants(new std::set<std::shared_ptr<Ant>, AntComparator>()){};
  const TileType type;
  byte getHeight() { return height; }

  // Get ants
  byte getNumAnts() { return ants->size() > 255 ? 255 : ants->size(); }
  std::shared_ptr<std::set<std::shared_ptr<Ant>, AntComparator>> getAnts() { return ants; }

  // Get scents
  byte getScent(ScentTypes type, std::shared_ptr<Ant> &ant);

  void ReleaseSmallScentC(std::shared_ptr<Ant> &);
  void ReleaseLargeScentC(std::shared_ptr<Ant> &);

  bool CanRaise() { return height < 255; }
  bool CanLower() { return height > 0; }
  void LowerHeight(std::shared_ptr<Ant> &) { height--; }
  void RaiseHeight(std::shared_ptr<Ant> &) { height++; }

  // Actions that depend on Tile Type
  bool CanMoveTo(std::shared_ptr<Ant> &) { return true; }
  bool CanMoveFrom(std::shared_ptr<Ant> &) { return true; }
  void MoveTo(std::shared_ptr<Ant> &ant)
  {
    ants->insert(ant);
  }
  void MoveFrom(std::shared_ptr<Ant> &ant)
  {
    ants->erase(ant);
  }

  virtual int CanIdle(std::shared_ptr<Ant> &) { return -1; }
  virtual int CanHarvest(std::shared_ptr<Ant> &) { return -1; }
  virtual int CanGive(std::shared_ptr<Ant> &) { return -1; }
  virtual int CanTake(std::shared_ptr<Ant> &) { return -1; }
  virtual int CanWork(std::shared_ptr<Ant> &) { return -1; }
  virtual int CanCultivate(std::shared_ptr<Ant> &) { return -1; }
  virtual int CanBuild(std::shared_ptr<Ant> &) { return -1; }

  virtual void Idle(std::shared_ptr<Ant> &) {}
  virtual void Harvest(std::shared_ptr<Ant> &) {}
  virtual void Give(std::shared_ptr<Ant> &) {}
  virtual void Take(std::shared_ptr<Ant> &) {}
  virtual void Work(std::shared_ptr<Ant> &) {}
  virtual void Cultivate(std::shared_ptr<Ant> &) {}
  virtual void Build(std::shared_ptr<Ant> &) {}

  inline void StepScents()
  {
    if (ColonyPassiveScent > 0)
      ColonyPassiveScent -= ColonyPassiveScent < Settings.ColonyPassiveScent_Decay ? Settings.ColonyPassiveScent_Decay : ColonyPassiveScent;
    if (ColonyActiveScent > 0)
      ColonyActiveScent -= ColonyActiveScent < Settings.ColonyActiveScent_Decay ? Settings.ColonyActiveScent_Decay : ColonyActiveScent;
  }
  virtual void Step() { StepScents(); }
};

struct ColonyTile : public Tile
{
public:
  ColonyTile(byte h, int p) : Tile(TileType::Colony, h, p){};
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

struct FoodTile : public Tile
{
public:
  FoodTile(byte h, int p) : Tile(TileType::Food, h, p){};
};

struct PlantTile : public Tile
{
public:
  PlantTile(byte h, int p) : Tile(TileType::Plant, h, p){};
};

struct RoadTile : public Tile
{
public:
  RoadTile(byte h, int p) : Tile(TileType::Road, h, p){};
};

struct GrassTile : public Tile
{
public:
  GrassTile(byte h, int p) : Tile(TileType::Grass, h, p){};
};

struct SandTile : public Tile
{
public:
  SandTile(byte h, int p) : Tile(TileType::Sand, h, p){};
};

struct TrapTile : public Tile
{
public:
  TrapTile(byte h, int p) : Tile(TileType::Trap, h, p){};
};

struct WallTile : public Tile
{
public:
  WallTile(byte h, int p) : Tile(TileType::Wall, h, p){};
  bool CanMoveTo(std::shared_ptr<Ant> &) { return false; }
  bool CanMoveFrom(std::shared_ptr<Ant> &) { return false; }
};