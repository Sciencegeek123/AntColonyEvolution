// Project Includes
#include "environment/environment.h"
#include "ant/ant.h"

// Dep Includes

// Generic Implementations

// Specific Implementations

byte Tile::getScent(ScentTypes type, std::shared_ptr<Ant> &ant)
{
  switch (type)
  {
  case ScentTypes::ColonyActiveScent:
    return ColonyActiveScent;
  case ScentTypes::ColonyPassiveScent:
    return ColonyPassiveScent;
  case ScentTypes::PersonalPassiveScent:
    return ant->PersonalScentPassive[position];
  case ScentTypes::PersonalActiveScentA:
    return ant->PersonalScentA[position];
  case ScentTypes::PersonalActiveScentB:
    return ant->PersonalScentB[position];
  default:
    return 0;
    break;
  }
}
void Tile::ReleaseSmallScentC(std::shared_ptr<Ant> &ant)
{
  if (ColonyActiveScent + ant->GC->SmallScent_Delta > 255)
  {
    ColonyActiveScent = 255;
  }
  else
  {
    ColonyActiveScent += ant->GC->SmallScent_Delta;
  }
}
void Tile::ReleaseLargeScentC(std::shared_ptr<Ant> &ant)
{
  if (ColonyActiveScent + ant->GC->LargeScent_Delta > 255)
  {
    ColonyActiveScent = 255;
  }
  else
  {
    ColonyActiveScent += ant->GC->LargeScent_Delta;
  }
}