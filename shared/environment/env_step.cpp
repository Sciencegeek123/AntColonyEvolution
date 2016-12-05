// Project Includes
#include "environment/environment.h"
#include "utils/utils.h"
#include "ant/ant.h"

// STL Includes
#include <iostream>
#include <random>

using namespace std;

void Environment::Step()
{
  for (int i = 0; i < ENV_SIZE; i++)
  {
    map[i]->Step();
  }
  iteration++;
}