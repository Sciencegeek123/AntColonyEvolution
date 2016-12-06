// Project Includes
#include "tests/tests.h"
#include "ai/ai_random.h"
#include "ai/ai_ffnn.h"
#include "environment/environment.h"
#include "simulation/simulation.h"
#include "utils/utils.h"

// STL Includes
#include <chrono>
#include <memory>

// Using
using namespace std;
using namespace std::chrono;

#define SIM_COUNT 100

void runFFNNSearch()
{
    high_resolution_clock myClock;
    auto start = myClock.now();

    cout << "Running test: FFNN Simulation Test - Speed Check" << endl;

    for (int i = 0; i < SIM_COUNT;)
    {
        shared_ptr<Environment> env = shared_ptr<Environment>(new Environment());
        shared_ptr<AI> ai = FFNN_AI::createRandom();
        shared_ptr<Simulation> sim =
            shared_ptr<Simulation>(new Simulation(env, ai));

        sim->Run(Settings.SIM_DURATION);
        sim->Report();
        cout.flush();

        if (true || sim->IsOverThreshold())
        {
            i++;
            cout << "!!! Found " << i << " FFNN over threshold." << endl;
            utils::submitJSON(sim->GetJSON("FFNN_SEARCH"));
        }
    }
    cout << endl;

    double time =
        (double)duration_cast<milliseconds>(myClock.now() - start).count() /
        1000.0f;

    cout << endl
         << "Took: " << time << "s for " << SIM_COUNT << " simulations." << endl
         << "Took: " << time / (double)SIM_COUNT << "s per simulation." << endl;
}