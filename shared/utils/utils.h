#pragma once

#include "ai/ai_enums.h"

#include <array>
#include <cmath>
#include <memory>
#include <random>
#include <string>

#define ENV_SIDE 256
#define ENV_SIZE 65536

typedef unsigned char byte;
typedef std::unique_ptr<std::array<byte, 64>> ACSData;

struct _Settings
{
public:
  std::string RD_HOST = "localhost";
  std::string RD_AUTH = "LetsMakeSomeAntsDoWorkForUs";

  int SIM_DURATION = 1000;

  int ANT_START_FOOD = 1000;
  int ANT_MAX_FOOD = 50000;

  int COLONY_START_FOOD = 5000;

  int Ant_StepCost = 5;

  int Action_WalkFoodCostPerHeight = 1;
  int Action_WalkFoodCostBase = 5;
  int Action_PersonalMemoryChangeCost = 5;

  int Action_ReleaseSmallScentCost = 50;
  int Action_ReleaseLargeScentCost = 150;

  int Action_RaiseLower = 50;
  int Action_ProduceOffspring = 5000;

  int Action_ColonyTimerReset = 250;
  int Action_ColonyMemoryChangeCost = 50;

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
