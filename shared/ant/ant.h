#pragma once

// Project Includes
#include "ai/ai.h"
#include "environment/environment.h"
#include "utils/utils.h"

// STL Includes
#include <array>
#include <list>
#include <memory>
#include <string>
#include <utility>

struct ANT_GC
{
public:
  ANT_GC(std::string input);
  const byte MyFood_Scale;
  const byte ColonyFood_Scale;
  const byte Age_Scale;
  const byte InverseAge_Scale;
  const byte PersonalFoodTrend_Duration;
  const byte ColonyFoodTrend_Duration;
  const byte PersonalTimerA_Scale;
  const byte PersonalTimerB_Scale;
  const byte ColonyTimerA_Scale;
  const byte ColonyTimerB_Scale;
  const byte PersonalDecayingMemoryA_Decay;
  const byte PersonalDecayingMemoryB_Decay;
  const byte PersonalDecayingMemoryC_Decay;
  const byte PersonalDecayingMemoryD_Decay;
  const byte PersonalPassiveScent_Decay;
  const byte PersonalActiveScentA_Decay;
  const byte PersonalActiveScentB_Decay;
  const byte ColonyPassiveScent_Decay;
  const byte ColonyActiveScent_Decay;
  const byte GiveFood_Amount;
  const byte TakeFood_Amount;
  const byte PersonalMemoryX_Delta;
  const byte PersonalMemoryY_Delta;
  const byte SmallScent_Delta;
  const byte LargeScent_Delta;
};

class Ant
{
  friend Environment;

public:
  // Alive
  bool alive = true;

  // Age
  const unsigned int creationTime = 0;

  // Food
  unsigned int food_income = 0;
  unsigned int food_expense = 0;
  unsigned int food_net = 0;
  std::list<int> food_change_log;

  // Timers
  unsigned int TimerA = 0;
  unsigned int TimerB = 0;

  // Decaying Memory
  float memory_decaying_a = 0;
  float memory_decaying_b = 0;
  float memory_decaying_c = 0;
  float memory_decaying_d = 0;

  // Static Memory
  float memory_static_a = 0;
  float memory_static_b = 0;
  float memory_static_c = 0;
  float memory_static_d = 0;

  std::shared_ptr<AI> brain;

  // Position
  std::pair<byte, byte> Pos;
  std::array<float, ENV_SIZE> PersonalScentA, PersonalScentB, PersonalScentP;

  Ant(std::shared_ptr<AI> ai, unsigned int startTime = 0);
  const std::unique_ptr<ANT_GC> GC;
  const unsigned int ID;
  OutputActions GetOutput(ACSData input);
  bool EvaluateAction(OutputActions action, int iteration);
  void ReflectAction(OutputActions action, bool success);

  bool checkFoodDelta(int delta);
  int registerFoodDelta(int delta);

  std::shared_ptr<Ant> produceOffspring(std::shared_ptr<std::set<std::shared_ptr<Ant>, AntComparator>> parents, unsigned int iteration);

  void Step();

  ACSData GetPersonalInput(unsigned int round);

  // Generic Actions
  void ReleaseSmallScentA();
  void ReleaseLargeScentA();
  void ReleaseSmallScentB();
  void ReleaseLargeScentB();
};