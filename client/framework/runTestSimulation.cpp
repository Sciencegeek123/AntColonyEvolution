// Project Includes
#include "../../shared/ai/ai_random.h"
#include "../../shared/environment/environment.h"
#include "../../shared/simulation/simulation.h"

// STL Includes
#include <chrono>
#include <memory>

// Using
using namespace std;
using namespace std::chrono;

#define SIM_COUNT 50

void runTestSimulation() {
  high_resolution_clock myClock;
  auto start = myClock.now();

  for (int i = 0; i < SIM_COUNT; i++) {
    shared_ptr<Environment> env = shared_ptr<Environment>(new Environment());
    shared_ptr<AI> ai = Random_AI::createRandom();
    shared_ptr<Simulation> sim =
        shared_ptr<Simulation>(new Simulation(env, ai));

    sim->Run(SIM_DURATION);
    sim->Report();

    cout << ".";
    cout.flush();
    if ((i + 1) % 10 == 0) {
      cout << endl;
    }
  }

  double time =
      (double)duration_cast<milliseconds>(myClock.now() - start).count() /
      1000.0f;

  cout << endl
       << "Took: " << time << "s for " << SIM_COUNT << " simulations." << endl;
  cout << "Took: " << time / (double)SIM_COUNT << "ms for " << SIM_COUNT
       << " simulations." << endl;
}
