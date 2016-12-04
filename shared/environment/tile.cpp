// Project Includes
#include "environment/environment.h"
#include "ant/ant.h"

// Dep Includes

// Generic Implementations

// Specific Implementations

bool Tile::AntComparator::operator()(const std::shared_ptr<Ant> &lhs,
                                     const std::shared_ptr<Ant> &rhs) const {
  return lhs->ID < rhs->ID;
}

byte Tile::getScent(ScentTypes type, std::shared_ptr<Ant> &ant) {
  auto it = scentMaps.find(type);
  if (it == scentMaps.end()) return 0;
  auto it2 = it->second.find(ant);
  if (it2 == it->second.end()) return 0;
  return it2->second;
}