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
  for (int i = 0; i < 64; i++)
  {
    actionCount[i] = 0;
  }

  int iteration = 1;

  do
  {
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
      }
      ant->ReflectAction(action, success);
      ant->Step();
    }
    environment->Step();

    if (++iteration % 100 == 0)
    {
      cout << ".";
      if (iteration % 1000 == 0)
        cout << endl;
      cout.flush();
    }

  } while (duration-- > 0);
}