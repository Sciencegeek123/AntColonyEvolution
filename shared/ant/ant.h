#pragma once

// Project Includes
#include "ai/ai.h"
#include "environment/environment.h"
#include "utils/utils.h"

// STL Includes
#include <array>
#include <memory>
#include <string>

struct ANT_GC {
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

class Ant {
 private:
  std::shared_ptr<AI> brain;

 public:
  const std::shared_ptr<ANT_GC> GC;
  Ant(std::shared_ptr<AI> ai);
  OutputActions GetOutput(ACSData input);
  ACSData GetPersonalInput();
};