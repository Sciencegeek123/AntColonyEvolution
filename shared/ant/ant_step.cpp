#include "ant/ant.h"
#include "utils/utils.h"
using namespace std;

void Ant::Step(unsigned int iteration)
{
    if (memory_decaying_a != 0)
        memory_decaying_a -= memory_decaying_a > GC->PersonalDecayingMemoryA_Decay ? GC->PersonalDecayingMemoryA_Decay : memory_decaying_a;
    if (memory_decaying_b != 0)
        memory_decaying_b -= memory_decaying_b > GC->PersonalDecayingMemoryB_Decay ? GC->PersonalDecayingMemoryB_Decay : memory_decaying_b;
    if (memory_decaying_c != 0)
        memory_decaying_c -= memory_decaying_c > GC->PersonalDecayingMemoryC_Decay ? GC->PersonalDecayingMemoryC_Decay : memory_decaying_c;
    if (memory_decaying_d != 0)
        memory_decaying_d -= memory_decaying_d > GC->PersonalDecayingMemoryD_Decay ? GC->PersonalDecayingMemoryD_Decay : memory_decaying_d;

    for (int i = 0; i < ENV_SIZE; i++)
    {
        if (PersonalScentA[i] != 0)
            PersonalScentA[i] -= PersonalScentA[i] > GC->PersonalActiveScentA_Decay ? GC->PersonalActiveScentA_Decay : PersonalScentA[i];
        if (PersonalScentB[i] != 0)
            PersonalScentB[i] -= PersonalScentB[i] > GC->PersonalActiveScentB_Decay ? GC->PersonalActiveScentB_Decay : PersonalScentB[i];
        if (PersonalScentP[i] != 0)
            PersonalScentP[i] -= PersonalScentP[i] > GC->PersonalPassiveScent_Decay ? GC->PersonalPassiveScent_Decay : PersonalScentP[i];
    }

    if (PersonalScentP[Pos.first + Pos.second * ENV_SIDE] + GC->SmallScent_Delta < 255)
        PersonalScentP[Pos.first + Pos.second * ENV_SIDE] += GC->SmallScent_Delta;
    else
        PersonalScentP[Pos.first + Pos.second * ENV_SIDE] = 0;

    food_change_log.push_back(0);

    if (food_net <= 0)
        alive = false;
    deathTime = iteration;
}
