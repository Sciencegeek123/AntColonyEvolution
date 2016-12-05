// Project Includes
#include "tests/tests.h"
#include "ai/ai_random.h"
#include "environment/environment.h"
#include "simulation/simulation.h"
#include "utils/utils.h"

// STL Includes
#include <chrono>
#include <memory>

// Using
using namespace std;
using namespace std::chrono;

#define SIM_COUNT 1

void runRandomTestSimulation()
{
    high_resolution_clock myClock;
    auto start = myClock.now();

    cout << "Running test: Random Simulation Test - Speed Check" << endl;

    for (int i = 0; i < SIM_COUNT; i++)
    {
        shared_ptr<Environment> env = shared_ptr<Environment>(new Environment());
        shared_ptr<AI> ai = Random_AI::createRandom();
        shared_ptr<Simulation> sim =
            shared_ptr<Simulation>(new Simulation(env, ai));

        sim->Run(Settings.SIM_DURATION);
        sim->Report();
        cout.flush();
    }
    cout << endl;

    double time =
        (double)duration_cast<milliseconds>(myClock.now() - start).count() /
        1000.0f;

    cout << endl
         << "Took: " << time << "s for " << SIM_COUNT << " simulations." << endl
         << "Took: " << time / (double)SIM_COUNT << "s per simulation." << endl;
}