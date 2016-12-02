// Project Includes
#include "simulation/simulation.h"

using namespace std;

Simulation::Simulation(shared_ptr<Environment> e, shared_ptr<AI> a) {
  environment = e;
  ants.push_back(shared_ptr<Ant>(new Ant(a)));
}