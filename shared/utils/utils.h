#pragma once

#include <array>
#include <cmath>
#include <memory>
#include <random>
#include <string>

#define ENV_SIDE 256
#define ENV_SIZE 65536

typedef unsigned char byte;
typedef std::unique_ptr<std::array<byte, 64>> ACSData;

#include "utils/enums.h"

struct _Settings
{
public:
  std::string RD_HOST = "localhost";
  std::string RD_AUTH = "LetsMakeSomeAntsDoWorkForUs";

  int SIM_DURATION = 1000;

  int ANT_START_FOOD = 1000;
  int ANT_MAX_FOOD = 5000;

  int COLONY_START_FOOD = 5000;

  int Ant_StepCost = 5;

  int Action_WalkFoodCostPerHeight = 1;
  int Action_WalkFoodCostBase = 5;
  int Action_PersonalMemoryChangeCost = 5;

  int Tile_GrassIdleCost = 3;
  int Tile_ColonyIdleCost = 1;
  int Tile_RoadIdleCost = 1;
  int Tile_PlantIdleCost = 5;
  int Tile_SandIdleCost = 10;
  int Tile_FoodIdleCost = 10;
  int Tile_TrapIdleCost = 50;
  int Tile_WallIdleCost = ANT_MAX_FOOD;

  int Tile_FoodStartCapacity = 25000;
  int Tile_FoodTransferAmount = 500;

  int Tile_PlantTransferAmount = 100;

  int Tile_TrapFoodDesire = 5000;
  int Tile_TrapLifetime = 250;

  int Tile_TrapProbability = 1000;

  int Action_ReleaseSmallScentCost = 50;
  int Action_ReleaseLargeScentCost = 150;

  int Action_RaiseLower = 50;
  int Action_ProduceOffspring = 1500;

  int Action_ColonyTimerReset = 250;
  int Action_ColonyMemoryChangeCost = 50;

  int Action_FailedActionCost = 100;

  float ColonyActiveScent_Decay = 0.5f;
  float ColonyPassiveScent_Decay = 0.5f;

  _Settings();
};

extern const _Settings Settings;

namespace utils
{
int getRandomInt();
void initRandom();
ACSData newACSData();
std::string randomString(int length);
}
