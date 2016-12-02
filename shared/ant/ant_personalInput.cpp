#include "ant/ant.h"
#include "utils/utils.h"
using namespace std;

ACSData Ant::GetPersonalInput(unsigned int round) {
  ACSData input = utils::newACSData();

  {  // CurrentFoodMagnitude
    (*input)[InputVars::CurrentFoodMagnitude] = food_net;
  }
  {  // Age

    float age = (round - creationTime);
    (*input)[InputVars::Age] =
        (byte)(age / (pow(GC->Age_Scale, 1.57079f) + age) * 255.0f);
  }
  {  // InverseAge

    float age = (round - creationTime);
    (*input)[InputVars::InverseAge] = (byte)(
        1.0f - (age / (pow(GC->InverseAge_Scale, 1.57079f) + age) * 255.0f));
  }
  {  // MovingPersonalFoodTrend

    unsigned int duration = (unsigned int)GC->PersonalFoodTrend_Duration *
                            (unsigned int)GC->PersonalFoodTrend_Duration;

    float change = 0;
    int i = duration;
    for (auto it = food_change_log.begin();
         it != food_change_log.end() && i-- > 0; it++) {
      change += *it;
    }

    (*input)[InputVars::MovingPersonalFoodTrend] = change / duration;
  }

  {  // LifetimePersonalFoodTrend
    (*input)[InputVars::LifetimeColonyFoodTrend] =
        (food_net / (round - creationTime + 1));
  }
  {
      // PersonalTimerA
  } {
      // PersonalTimerB
  } {
      // PersonalDecayingMemoryA
  } {
      // PersonalDecayingMemoryB
  } {
      // PersonalDecayingMemoryC
  } {
      // PersonalDecayingMemoryD
  } {
      // PersonalStaticMemoryA
  } {
      // PersonalStaticMemoryB
  } {
      // PersonalStaticMemoryC
  } {
      // PersonalStaticMemoryD
  } {
      // PersonalPassiveScentO
  } {
      // PersonalPassiveScentPP
  } {
      // PersonalPassiveScentPN
  } {
      // PersonalPassiveScentNP
  } {
      // PersonalPassiveScentNN
  } {
      // PersonalActiveScentAO
  } {
      // PersonalActiveScentAPP
  } {
      // PersonalActiveScentAPN
  } {
      // PersonalActiveScentANP
  } {
      // PersonalActiveScentANN
  } {
      // PersonalActiveScentBO
  } {
      // PersonalActiveScentBPP
  } {
      // PersonalActiveScentBPN
  } {
      // PersonalActiveScentBNP
  } {
      // PersonalActiveScentBNN
  } {
      // ColonyPassiveScentO
  } {
      // ColonyPassiveScentPP
  } {
      // ColonyPassiveScentPN
  } {
      // ColonyPassiveScentNP
  } {
      // ColonyPassiveScentNN
  } {
      // ColonyActiveScentCO
  } {
      // ColonyActiveScentCPP
  } {
      // ColonyActiveScentCPN
  } {
      // ColonyActiveScentCNP
  } {  // ColonyActiveScentCNN
  }

  return move(input);
}