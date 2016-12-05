#include "ant/ant.h"
#include "utils/utils.h"
using namespace std;

void Ant::Step()
{
    if (memory_decaying_a > 0)
        memory_decaying_a -= memory_decaying_a > GC->PersonalDecayingMemoryA_Decay ? GC->PersonalDecayingMemoryA_Decay : memory_decaying_a;
    if (memory_decaying_b > 0)
        memory_decaying_b -= memory_decaying_b > GC->PersonalDecayingMemoryB_Decay ? GC->PersonalDecayingMemoryB_Decay : memory_decaying_b;
    if (memory_decaying_c > 0)
        memory_decaying_c -= memory_decaying_c > GC->PersonalDecayingMemoryC_Decay ? GC->PersonalDecayingMemoryC_Decay : memory_decaying_c;
    if (memory_decaying_d > 0)
        memory_decaying_d -= memory_decaying_d > GC->PersonalDecayingMemoryD_Decay ? GC->PersonalDecayingMemoryD_Decay : memory_decaying_d;
    food_change_log.push_back(0);
}
