// Project Includes
#include "environment/environment.h"
#include "utils/utils.h"
#include "ant/ant.h"

// STL Includes
#include <iostream>
#include <random>

using namespace std;

void Environment::Step()
{
  for (int i = 0; i < ENV_SIZE; i++)
  {
    Tile *replace = map[i]->Step();
    if (replace != nullptr)
    {
      replace->ants = map[i]->ants;
      delete map[i];
      map[i] = replace;
    }
    if (colonyPassiveScent[i] > 0)
      colonyPassiveScent[i] -= colonyPassiveScent[i] < Settings.ColonyPassiveScent_Decay ? Settings.ColonyActiveScent_Decay : colonyPassiveScent[i];
    if (colonyActiveScent[i] > 0)
      colonyActiveScent[i] -= colonyActiveScent[i] < Settings.ColonyActiveScent_Decay ? Settings.ColonyActiveScent_Decay : colonyActiveScent[i];
  }
  iteration++;
}