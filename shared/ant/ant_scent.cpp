#include "ant/ant.h"
#include "utils/utils.h"
using namespace std;

void Ant::ReleaseSmallScentA()
{
    if (PersonalScentA[Pos.first + Pos.second * ENV_SIDE] + GC->SmallScent_Delta < 255)
    {
        PersonalScentA[Pos.first + Pos.second * ENV_SIDE] += GC->SmallScent_Delta;
    }
    else
    {
        PersonalScentA[Pos.first + Pos.second * ENV_SIDE] = 255;
    }
}
void Ant::ReleaseLargeScentA()
{
    if (PersonalScentA[Pos.first + Pos.second * ENV_SIDE] + GC->LargeScent_Delta < 255)
    {
        PersonalScentA[Pos.first + Pos.second * ENV_SIDE] += GC->LargeScent_Delta;
    }
    else
    {
        PersonalScentA[Pos.first + Pos.second * ENV_SIDE] = 255;
    }
}
void Ant::ReleaseSmallScentB()
{
    if (PersonalScentB[Pos.first + Pos.second * ENV_SIDE] + GC->SmallScent_Delta < 255)
    {
        PersonalScentB[Pos.first + Pos.second * ENV_SIDE] += GC->SmallScent_Delta;
    }
    else
    {
        PersonalScentB[Pos.first + Pos.second * ENV_SIDE] = 255;
    }
}
void Ant::ReleaseLargeScentB()
{
    if (PersonalScentB[Pos.first + Pos.second * ENV_SIDE] + GC->LargeScent_Delta < 255)
    {
        PersonalScentB[Pos.first + Pos.second * ENV_SIDE] += GC->LargeScent_Delta;
    }
    else
    {
        PersonalScentB[Pos.first + Pos.second * ENV_SIDE] = 255;
    }
}