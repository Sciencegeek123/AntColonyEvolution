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
        cdebug << OutputStrings[i] << " : " << actionCount[i] << endl;
    }
    cdebug << "CN: " << environment->colony->food_net << " It: " << environment->iteration << endl;

    vector<json> children;

    for (auto a : ants)
    {
        cdebug << "* ";
        a->print(cdebug);
    }

    for (auto a : deadAnts)
    {
        cdebug << "* ";
        a->print(cdebug);
    }
}