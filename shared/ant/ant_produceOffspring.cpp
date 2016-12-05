#include "ant/ant.h"
#include "ant/ant_comparator.h"
#include "utils/utils.h"
using namespace std;

std::shared_ptr<Ant> Ant::produceOffspring(std::shared_ptr<std::set<std::shared_ptr<Ant>, AntComparator>> parents, unsigned int iteration)
{
    auto newAnt = std::shared_ptr<Ant>(new Ant(brain->reproduce(parents), iteration));

    newAnt->Pos = Pos;

    return newAnt;
}