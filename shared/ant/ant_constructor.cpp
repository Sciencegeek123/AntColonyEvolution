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

  for (int i = 0; i < 65; i++)
  {
    successfulActionCount[i] = 0;
    failedActionCount[i] = 0;
  }

  for (int i = 0; i < ENV_SIZE; i++)
  {
    PersonalScentA[i] = 0;
    PersonalScentB[i] = 0;
    PersonalScentP[i] = 0;
  }
  Pos.first = 128;
  Pos.second = 128;
}