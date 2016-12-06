#include "ant/ant.h"
#include "utils/utils.h"
using namespace std;

ACSData Ant::GetPersonalInput(unsigned int iteration) {
  ACSData input = utils::newACSData();

  {  // CurrentFoodMagnitude
    (*input)[InputVars::CurrentFoodMagnitude] =
        (byte)(255 * ((float)food_net / (float)GC->MyFood_Scale * 4.0f));
  }
  {  // Age

    float age = (iteration - creationTime);
    (*input)[InputVars::Age] =
        (byte)(age / (pow(GC->Age_Scale, 1.57079f) + age) * 255.0f);
  }
  {  // InverseAge

    float age = (iteration - creationTime);
    (*input)[InputVars::InverseAge] = (byte)(
        1.0f - (age / (pow(GC->InverseAge_Scale, 1.57079f) + age) * 255.0f));
  }
  {  // MovingPersonalFoodTrend

    unsigned int duration = (unsigned int)GC->PersonalFoodTrend_Duration *
                                (unsigned int)GC->PersonalFoodTrend_Duration +
                            1;

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
        (food_net / (iteration - creationTime + 1));
  }
  {  // PersonalTimerA
    float timerA =
        (float)(iteration - PersonalTimerA) /
        (float)((iteration - PersonalTimerA) + GC->PersonalTimerA_Scale + 1);

    (*input)[InputVars::PersonalTimerA] = timerA > 255 ? 255 : (byte)timerA;
  }
  {
    // PersonalTimerB
    float timerB =
        (float)(iteration - PersonalTimerB) /
        (float)((iteration - PersonalTimerB) + GC->PersonalTimerB_Scale + 1);

    (*input)[InputVars::PersonalTimerB] = timerB > 255 ? 255 : (byte)timerB;
  }
  {
    // PersonalDecayingMemoryA
    (*input)[InputVars::PersonalTimerA] = memory_decaying_a;
  }
  {
    // PersonalDecayingMemoryB
    (*input)[InputVars::PersonalTimerA] = memory_decaying_b;
  }
  {
    // PersonalDecayingMemoryC
    (*input)[InputVars::PersonalTimerA] = memory_decaying_c;
  }
  {
    // PersonalDecayingMemoryD
    (*input)[InputVars::PersonalTimerA] = memory_decaying_d;
  }
  {
    // PersonalStaticMemoryA
    (*input)[InputVars::PersonalTimerA] = memory_static_a;
  }
  {
    // PersonalStaticMemoryB
    (*input)[InputVars::PersonalTimerA] = memory_static_b;
  }
  {
    // PersonalStaticMemoryC
    (*input)[InputVars::PersonalTimerA] = memory_static_c;
  }
  {
    // PersonalStaticMemoryD
    (*input)[InputVars::PersonalTimerA] = memory_static_d;
  }
  return move(input);
}