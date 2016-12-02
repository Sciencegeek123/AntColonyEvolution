#include "ant/ant.h"
using namespace std;

ANT_GC::ANT_GC(std::string input)
    : MyFood_Scale(input[0]),
      ColonyFood_Scale(input[1]),
      Age_Scale(input[2]),
      InverseAge_Scale(input[3]),
      PersonalFoodTrend_Duration(input[4]),
      ColonyFoodTrend_Duration(input[5]),
      PersonalTimerA_Scale(input[6]),
      PersonalTimerB_Scale(input[7]),
      ColonyTimerA_Scale(input[8]),
      ColonyTimerB_Scale(input[9]),
      PersonalDecayingMemoryA_Decay(input[10]),
      PersonalDecayingMemoryB_Decay(input[11]),
      PersonalDecayingMemoryC_Decay(input[12]),
      PersonalDecayingMemoryD_Decay(input[13]),
      PersonalPassiveScent_Decay(input[14]),
      PersonalActiveScentA_Decay(input[15]),
      PersonalActiveScentB_Decay(input[16]),
      ColonyPassiveScent_Decay(input[17]),
      ColonyActiveScent_Decay(input[18]),
      GiveFood_Amount(input[19]),
      TakeFood_Amount(input[20]),
      PersonalMemoryX_Delta(input[21]),
      PersonalMemoryY_Delta(input[22]),
      SmallScent_Delta(input[23]),
      LargeScent_Delta(input[24]){};