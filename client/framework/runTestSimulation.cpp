//Project Includes
#include "../../shared/ffnn/ffnn.h"
#include "../../shared/environment/environment.h"
#include "../../shared/simulation/simulation.h"

//STL Includes
#include <memory>

//Using
using namespace std;

void runTestSimulation() {
    shared_ptr<Environment> env = shared_ptr<Environment>(new Environment());
    shared_ptr<AI> ai = Random_AI::createRandom();
}
