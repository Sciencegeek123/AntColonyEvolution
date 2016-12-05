// Project Includes
#include "simulation/simulation.h"

// Dep includes
#include "../deps/FastNoise/FastNoise.h"

// STL Includes
#include <iostream>
#include <random>

using namespace std;

void Simulation::Report()
{
    for (auto i = (int)OutputActions::NoOP; i < (int)OutputActions::OutputActionsSize; i++)
    {
        cout << OutputStrings[i] << " : " << actionCount[i] << endl;
    }
}