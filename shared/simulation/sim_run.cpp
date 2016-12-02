// Project Includes
#include "simulation/simulation.h"

// Dep includes
#include "../deps/FastNoise/FastNoise.h"

// STL Includes
#include <iostream>
#include <random>

void Simulation::Run(int duration) {
  do {
    for (auto const &ant : ants) {
      environment->EvaluateAction(ant->GetOutput(environment->GetInput(ant)),
                                  ant);
    }
  } while (duration-- > 0);
}