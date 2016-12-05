#include "ant/ant.h"

using namespace std;

// 0 is colony.
static unsigned int numAnts = 1;

Ant::Ant(std::shared_ptr<AI> ai, unsigned int startTime)
    : GC(new ANT_GC(ai->GetGeneticString())),
      ID(numAnts++),
      creationTime(startTime)
{
  brain = ai;
  food_net = Settings.ANT_START_FOOD;
}