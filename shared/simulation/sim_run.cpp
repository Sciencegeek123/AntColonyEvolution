// Project Includes
#include "simulation/simulation.h"

// Dep includes
#include "../deps/FastNoise/FastNoise.h"

// STL Includes
#include <iostream>
#include <random>

using namespace std;

void Simulation::Run(int duration)
{
  for (int i = 0; i < (int)OutputActions::OutputActionsSize; i++)
  {
    actionCount[i] = 0;
  }

  int iteration = 1;

  do
  {
    for (int i = 0; i < ants.size(); i++)
    {
      if (!ants[i]->alive)
      {
        deadAnts.push_back(ants[i]);
        ants.erase(ants.begin() + i);
      }
    }

    for (auto &ant : ants)
    {

      OutputActions action = ant->GetOutput(environment->GetInput(ant));
      bool success = environment->EvaluateAction(action, ant);
      if (success)
      {
        if (action == OutputActions::ProduceOffspring)
        {
          ants.push_back(ant->produceOffspring(environment->get(ant->Pos)->getAnts(), environment->iteration));
        }
        actionCount[(int)action]++;
      }
      else
      {
        actionCount[(int)OutputActions::FailedAction]++;
        cdebug << "* Action Failed" << endl;
        ant->registerFoodDelta(-Settings.Action_FailedActionCost);
      }
      ant->ReflectAction(action, success);
      ant->Step();
    }
    environment->Step();
  } while (duration-- > 0 && ants.size() > 0);

  environment->colony->registerFoodDelta(-Settings.Tile_ColonyFoodConsumption * duration);

  cdebug << "Simulation ended with " << duration << " iterations left." << endl;
}