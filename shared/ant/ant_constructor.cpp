#include "ant/ant.h"

using namespace std;

Ant::Ant(std::shared_ptr<AI> ai) : GC(new ANT_GC(ai->GetGeneticString())) {
  brain = ai;
}