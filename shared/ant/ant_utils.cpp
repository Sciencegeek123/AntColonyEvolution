#include "ant/ant.h"
#include "ant/ant_comparator.h"

using namespace std;

bool AntComparator::operator()(const shared_ptr<Ant> &lhs,
                               const shared_ptr<Ant> &rhs) const
{
    return lhs->ID < rhs->ID;
}