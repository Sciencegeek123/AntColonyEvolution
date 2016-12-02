#include "ant/ant.h"

using namespace std;

static unsigned int numAnts = 0;

Ant::Ant(std::shared_ptr<AI> ai, unsigned int startTime)
    : GC(new ANT_GC(ai->GetGeneticString())),
      ID(numAnts++),
      creationTime(startTime) {
  brain = ai;
}