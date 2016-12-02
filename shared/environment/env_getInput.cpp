// Project Includes
#include "environment/environment.h"
#include "utils/utils.h"
#include "ant/ant.h"

// STL Includes
#include <iostream>
#include <random>

using namespace std;

ACSData Environment::GetInput(const std::shared_ptr<Ant> &ant) {
  // Get the base info from the ant.
  ACSData input = ant->GetPersonalInput(round);

  // CurrentFoodMagnitude
  // ColonyFoodMagnitude
  // Age
  // InverseAge
  // MovingPersonalFoodTrend
  // LifetimePersonalFoodTrend
  // MovingColonyFoodTrend
  // LifetimeColonyFoodTrend
  // PersonalTimerA
  // PersonalTimerB
  // ColonyTimerA
  // ColonyTimerB
  // TileTypeO
  // TileTypePP
  // TileTypePN
  // TileTypeNP
  // TileTypeNN
  // TileHeightO
  // TileHeightPP
  // TileHeightPN
  // TileHeightNP
  // TileHeightNN
  // TileAntCountO
  // TileAntCountPP
  // TileAntCountPN
  // TileAntCountNP
  // TileAntCountNN
  // PersonalDecayingMemoryA
  // PersonalDecayingMemoryB
  // PersonalDecayingMemoryC
  // PersonalDecayingMemoryD
  // PersonalStaticMemoryA
  // PersonalStaticMemoryB
  // PersonalStaticMemoryC
  // PersonalStaticMemoryD
  // ColonyStaticMemoryA
  // ColonyStaticMemoryB
  // ColonyStaticMemoryC
  // ColonyStaticMemoryD
  // PersonalPassiveScentO
  // PersonalPassiveScentPP
  // PersonalPassiveScentPN
  // PersonalPassiveScentNP
  // PersonalPassiveScentNN
  // PersonalActiveScentAO
  // PersonalActiveScentAPP
  // PersonalActiveScentAPN
  // PersonalActiveScentANP
  // PersonalActiveScentANN
  // PersonalActiveScentBO
  // PersonalActiveScentBPP
  // PersonalActiveScentBPN
  // PersonalActiveScentBNP
  // PersonalActiveScentBNN
  // ColonyPassiveScentO
  // ColonyPassiveScentPP
  // ColonyPassiveScentPN
  // ColonyPassiveScentNP
  // ColonyPassiveScentNN
  // ColonyActiveScentCO
  // ColonyActiveScentCPP
  // ColonyActiveScentCPN
  // ColonyActiveScentCNP
  // ColonyActiveScentCNN

  return move(input);
}