// Project Includes
#include "simulation/simulation.h"

// Dep includes
#include "../deps/FastNoise/FastNoise.h"

// STL Includes
#include <iostream>
#include <random>

using namespace std;

json Simulation::GetJSON(std::string type)
{
    vector<json> children;

    for (auto a : ants)
    {
        children.push_back(a->GetJSON());
    }

    for (auto a : deadAnts)
    {
        children.push_back(a->GetJSON());
    }

    json retJson;
    retJson["type"] = type;
    retJson["lifetime"] = environment->iteration;
    retJson["netFood"] = environment->colony->food_net;
    retJson["posFood"] = environment->colony->food_income;
    retJson["negFood"] = environment->colony->food_expense;
    retJson["members"] = json(children);

    cdebug << "JSON: " << endl
         << retJson.dump() << endl;

    return retJson;
}