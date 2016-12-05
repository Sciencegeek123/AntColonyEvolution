// Project Includes
#include "environment/environment.h"
#include "ant/ant.h"

// STL Includes
#include <iostream>
#include <random>

using namespace std;

void Environment::ReleaseSmallScentC(std::shared_ptr<Ant> &ant)
{
    if (colonyActiveScent[ant->Pos.first + ant->Pos.second * ENV_SIDE] + ant->GC->SmallScent_Delta < 255)
    {
        colonyActiveScent[ant->Pos.first + ant->Pos.second * ENV_SIDE] += ant->GC->SmallScent_Delta;
    }
    else
    {
        colonyActiveScent[ant->Pos.first + ant->Pos.second * ENV_SIDE] = 255;
    }
}
void Environment::ReleaseLargeScentC(std::shared_ptr<Ant> &ant)
{
    if (colonyActiveScent[ant->Pos.first + ant->Pos.second * ENV_SIDE] + ant->GC->LargeScent_Delta < 255)
    {
        colonyActiveScent[ant->Pos.first + ant->Pos.second * ENV_SIDE] += ant->GC->LargeScent_Delta;
    }
    else
    {
        colonyActiveScent[ant->Pos.first + ant->Pos.second * ENV_SIDE] = 255;
    }
}