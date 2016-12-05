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

void runEnvTest()
{
  unique_ptr<Environment> env = unique_ptr<Environment>(new Environment());
  env->Print();
}
