// Project Includes
#include "simulation/simulation.h"

using namespace std;

Simulation::Simulation(shared_ptr<Environment> e, shared_ptr<AI> a)
{
  environment = e;
  auto ant = shared_ptr<Ant>(new Ant(a));
  ant->Pos.first = 128;
  ant->Pos.second = 128;
  ants.push_back(ant);
  e->colony->ants->insert(ant);
}