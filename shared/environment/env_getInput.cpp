// Project Includes
#include "environment/environment.h"
#include "utils/utils.h"
#include "ant/ant.h"

// STL Includes
#include <iostream>
#include <random>

using namespace std;

ACSData Environment::GetInput(std::shared_ptr<Ant> &ant) {
  // Get the base info from the ant.
  ACSData input = ant->GetPersonalInput(iteration);

  {
    // Colony Food Magnitude
    (*input)[InputVars::ColonyFoodMagnitude] =
        (byte)(255 * ((float)colony->food_net /
                      (float)ant->GC->ColonyFood_Scale * 4.0f));
  }
  {
    // Moving Colony Food Trend

    unsigned int duration = (unsigned int)ant->GC->ColonyFoodTrend_Duration *
                            (unsigned int)ant->GC->ColonyFoodTrend_Duration;

    float change = 0;
    int i = duration;
    for (auto it = colony->food_change_log.begin();
         it != colony->food_change_log.end() && i-- > 0; it++) {
      change += *it;
    }

    (*input)[InputVars::MovingColonyFoodTrend] = change / duration;
  }
  {
    // Lifetime Colony Food Trend
    (*input)[InputVars::LifetimeColonyFoodTrend] =
        (colony->food_net / (iteration + 1));
  }

  {  // ColonyTimerA
    float timerA = (float)(iteration - colony->ColonyTimerA) /
                   (float)((iteration - colony->ColonyTimerA) +
                           ant->GC->ColonyTimerA_Scale + 1);

    (*input)[InputVars::ColonyTimerA] = timerA > 255 ? 255 : (byte)timerA;
  }
  {
    // ColonyTimerB
    float timerB = (float)(iteration - colony->ColonyTimerB) /
                   (float)((iteration - colony->ColonyTimerB) +
                           ant->GC->ColonyTimerB_Scale + 1);

    (*input)[InputVars::ColonyTimerB] = timerB > 255 ? 255 : (byte)timerB;
  }
  {  // TileTypeO
    (*input)[InputVars::TileTypeO] = get(ant->Pos.first, ant->Pos.second)->type;
  }
  {
    // TileTypePP
    (*input)[InputVars::TileTypePP] =
        get(ant->Pos.first + 1, ant->Pos.second + 1)->type;
  }
  {
    // TileTypePN
    (*input)[InputVars::TileTypePN] =
        get(ant->Pos.first + 1, ant->Pos.second - 1)->type;
  }
  {
    // TileTypeNP
    (*input)[InputVars::TileTypeNP] =
        get(ant->Pos.first - 1, ant->Pos.second + 1)->type;
  }
  {
    // TileTypeNN
    (*input)[InputVars::TileTypeNN] =
        get(ant->Pos.first - 1, ant->Pos.second - 1)->type;
  }
  {
    // TileHeightO
    (*input)[InputVars::TileHeightO] =
        get(ant->Pos.first, ant->Pos.second)->height;
  }
  {
    // TileHeightPP
    (*input)[InputVars::TileHeightPP] =
        get(ant->Pos.first + 1, ant->Pos.second + 1)->height;
  }
  {
    // TileHeightPN
    (*input)[InputVars::TileHeightPN] =
        get(ant->Pos.first + 1, ant->Pos.second - 1)->height;
  }
  {
    // TileHeightNP
    (*input)[InputVars::TileHeightNP] =
        get(ant->Pos.first - 1, ant->Pos.second + 1)->height;
  }
  {
    // TileHeightNN
    (*input)[InputVars::TileHeightNN] =
        get(ant->Pos.first - 1, ant->Pos.second - 1)->height;
  }
  {
    // TileAntCountO
    (*input)[InputVars::TileAntCountO] =
        get(ant->Pos.first, ant->Pos.second)->getNumAnts();
  }
  {
    // TileAntCountPP
    (*input)[InputVars::TileAntCountPP] =
        get(ant->Pos.first + 1, ant->Pos.second + 1)->getNumAnts();
  }
  {
    // TileAntCountPN
    (*input)[InputVars::TileAntCountPN] =
        get(ant->Pos.first + 1, ant->Pos.second - 1)->getNumAnts();
  }
  {
    // TileAntCountNP
    (*input)[InputVars::TileAntCountNP] =
        get(ant->Pos.first - 1, ant->Pos.second + 1)->getNumAnts();
  }
  {
    // TileAntCountNN
    (*input)[InputVars::TileAntCountNN] =
        get(ant->Pos.first - 1, ant->Pos.second - 1)->getNumAnts();
  }
  {
    // ColonyStaticMemoryA
    (*input)[InputVars::ColonyStaticMemoryA] = colony->memory_static_a;
  }
  {
    // ColonyStaticMemoryB
    (*input)[InputVars::ColonyStaticMemoryA] = colony->memory_static_b;
  }
  {
    // ColonyStaticMemoryC
    (*input)[InputVars::ColonyStaticMemoryA] = colony->memory_static_c;
  }
  {
    // ColonyStaticMemoryD
    (*input)[InputVars::ColonyStaticMemoryA] = colony->memory_static_d;
  }
  {
    // PersonalPassiveScentO
    (*input)[InputVars::PersonalPassiveScentO] =
        get(ant->Pos.first, ant->Pos.second)
            ->getScent(ScentTypes::PersonalPassiveScent, ant);
  }
  {
    // PersonalPassiveScentPP
    (*input)[InputVars::PersonalPassiveScentPP] =
        get(ant->Pos.first + 1, ant->Pos.second + 1)
            ->getScent(ScentTypes::PersonalPassiveScent, ant);
  }
  {
    // PersonalPassiveScentPN
    (*input)[InputVars::PersonalPassiveScentPN] =
        get(ant->Pos.first + 1, ant->Pos.second - 1)
            ->getScent(ScentTypes::PersonalPassiveScent, ant);
  }
  {
    // PersonalPassiveScentNP
    (*input)[InputVars::PersonalPassiveScentNP] =
        get(ant->Pos.first - 1, ant->Pos.second + 1)
            ->getScent(ScentTypes::PersonalPassiveScent, ant);
  }
  {
    // PersonalPassiveScentNN
    (*input)[InputVars::PersonalPassiveScentNN] =
        get(ant->Pos.first - 1, ant->Pos.second - 1)
            ->getScent(ScentTypes::PersonalPassiveScent, ant);
  }
  {
    // PersonalActiveScentAO
    (*input)[InputVars::PersonalActiveScentAO] =
        get(ant->Pos.first, ant->Pos.second)
            ->getScent(ScentTypes::PersonalActiveScentA, ant);
  }
  {
    // PersonalActiveScentAPP
    (*input)[InputVars::PersonalActiveScentAPP] =
        get(ant->Pos.first + 1, ant->Pos.second + 1)
            ->getScent(ScentTypes::PersonalActiveScentA, ant);
  }
  {
    // PersonalActiveScentAPN
    (*input)[InputVars::PersonalActiveScentAPN] =
        get(ant->Pos.first + 1, ant->Pos.second - 1)
            ->getScent(ScentTypes::PersonalActiveScentA, ant);
  }
  {
    // PersonalActiveScentANP
    (*input)[InputVars::PersonalActiveScentANP] =
        get(ant->Pos.first - 1, ant->Pos.second + 1)
            ->getScent(ScentTypes::PersonalActiveScentA, ant);
  }
  {
    // PersonalActiveScentANN
    (*input)[InputVars::PersonalActiveScentANN] =
        get(ant->Pos.first - 1, ant->Pos.second - 1)
            ->getScent(ScentTypes::PersonalActiveScentA, ant);
  }
  {
    // PersonalActiveScentBO
    (*input)[InputVars::PersonalActiveScentBO] =
        get(ant->Pos.first, ant->Pos.second)
            ->getScent(ScentTypes::PersonalActiveScentA, ant);
  }
  {
    // PersonalActiveScentBPP
    (*input)[InputVars::PersonalActiveScentBPP] =
        get(ant->Pos.first + 1, ant->Pos.second + 1)
            ->getScent(ScentTypes::PersonalActiveScentA, ant);
  }
  {
    // PersonalActiveScentBPN
    (*input)[InputVars::PersonalActiveScentBPN] =
        get(ant->Pos.first + 1, ant->Pos.second - 1)
            ->getScent(ScentTypes::PersonalActiveScentA, ant);
  }
  {
    // PersonalActiveScentBNP
    (*input)[InputVars::PersonalActiveScentBNP] =
        get(ant->Pos.first - 1, ant->Pos.second + 1)
            ->getScent(ScentTypes::PersonalActiveScentA, ant);
  }
  {
    // PersonalActiveScentBNN
    (*input)[InputVars::PersonalActiveScentBNN] =
        get(ant->Pos.first - 1, ant->Pos.second - 1)
            ->getScent(ScentTypes::PersonalActiveScentA, ant);
  }
  {
    // ColonyPassiveScentO
    (*input)[InputVars::ColonyPassiveScentO] =
        get(ant->Pos.first, ant->Pos.second)
            ->getScent(ScentTypes::ColonyPassiveScent, ant);
  }
  {
    // ColonyPassiveScentPP
    (*input)[InputVars::ColonyPassiveScentPP] =
        get(ant->Pos.first + 1, ant->Pos.second + 1)
            ->getScent(ScentTypes::ColonyPassiveScent, ant);
  }
  {
    // ColonyPassiveScentPN
    (*input)[InputVars::ColonyPassiveScentPN] =
        get(ant->Pos.first + 1, ant->Pos.second - 1)
            ->getScent(ScentTypes::ColonyPassiveScent, ant);
  }
  {
    // ColonyPassiveScentNP
    (*input)[InputVars::ColonyPassiveScentNP] =
        get(ant->Pos.first - 1, ant->Pos.second + 1)
            ->getScent(ScentTypes::ColonyPassiveScent, ant);
  }
  {
    // ColonyPassiveScentNN
    (*input)[InputVars::ColonyPassiveScentNN] =
        get(ant->Pos.first - 1, ant->Pos.second - 1)
            ->getScent(ScentTypes::ColonyPassiveScent, ant);
  }
  {
    // ColonyActiveScentCO
    (*input)[InputVars::ColonyActiveScentCO] =
        get(ant->Pos.first, ant->Pos.second)
            ->getScent(ScentTypes::ColonyActiveScent, ant);
  }
  {
    // ColonyActiveScentCPP
    (*input)[InputVars::ColonyActiveScentCPP] =
        get(ant->Pos.first + 1, ant->Pos.second + 1)
            ->getScent(ScentTypes::ColonyActiveScent, ant);
  }
  {
    // ColonyActiveScentCPN
    (*input)[InputVars::ColonyActiveScentCPN] =
        get(ant->Pos.first + 1, ant->Pos.second - 1)
            ->getScent(ScentTypes::ColonyActiveScent, ant);
  }
  {
    // ColonyActiveScentCNP
    (*input)[InputVars::ColonyActiveScentCNP] =
        get(ant->Pos.first - 1, ant->Pos.second + 1)
            ->getScent(ScentTypes::ColonyActiveScent, ant);
  }
  {
    // ColonyActiveScentCNN
    (*input)[InputVars::ColonyActiveScentCNN] =
        get(ant->Pos.first - 1, ant->Pos.second - 1)
            ->getScent(ScentTypes::ColonyActiveScent, ant);
  }

  return move(input);
}