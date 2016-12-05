// Project Includes
#include "environment/environment.h"
#include "utils/utils.h"
#include "ant/ant.h"

// STL Includes
#include <iostream>
#include <random>

using namespace std;

bool Environment::EvaluateAction(OutputActions action,
                                 std::shared_ptr<Ant> &ant)
{
  cout << "Iteration: " << iteration << endl;
  cout << "* Action: " << OutputStrings[(int)action] << endl;

  switch (action)
  {
  case OutputActions::NoOP:
  {
    return true;
    break;
  }
  case OutputActions::MoveUP:
  {
    Tile *from = get(ant->Pos);
    Tile *to = get(ant->Pos.second + 1, ant->Pos.first);
    int cost = to->height - from->height;

    if (cost < 0)
      cost *= -1;

    cost = -1 * (Settings.Action_WalkFoodCostBase +
                 Settings.Action_WalkFoodCostPerHeight * cost);

    if (ant->checkFoodDelta(cost) && to->CanMoveTo(ant) &&
        from->CanMoveFrom(ant))
    {
      ant->registerFoodDelta(cost);
      to->MoveTo(ant);
      from->MoveFrom(ant);
      return true;
    }
    else
    {
      return false;
    }
  }
  case OutputActions::MoveDOWN:
  {
    Tile *from = get(ant->Pos);
    Tile *to = get(ant->Pos.second - 1, ant->Pos.first);
    int cost = to->height - from->height;

    if (cost < 0)
      cost *= -1;

    cost = -1 * (Settings.Action_WalkFoodCostBase +
                 Settings.Action_WalkFoodCostPerHeight * cost);

    if (ant->checkFoodDelta(cost) && to->CanMoveTo(ant) &&
        from->CanMoveFrom(ant))
    {
      ant->registerFoodDelta(cost);
      to->MoveTo(ant);
      from->MoveFrom(ant);
      return true;
    }
    else
    {
      return false;
    }
  }
  case OutputActions::MoveLEFT:
  {
    Tile *from = get(ant->Pos);
    Tile *to = get(ant->Pos.second, ant->Pos.first - 1);
    int cost = to->height - from->height;

    if (cost < 0)
      cost *= -1;

    cost = -1 * (Settings.Action_WalkFoodCostBase +
                 Settings.Action_WalkFoodCostPerHeight * cost);

    if (ant->checkFoodDelta(cost) && to->CanMoveTo(ant) &&
        from->CanMoveFrom(ant))
    {
      ant->registerFoodDelta(cost);
      to->MoveTo(ant);
      from->MoveFrom(ant);
      return true;
    }
    else
    {
      return false;
    }
  }
  case OutputActions::MoveRIGHT:
  {
    Tile *from = get(ant->Pos);
    Tile *to = get(ant->Pos.second + 1, ant->Pos.first + 1);
    int cost = to->height - from->height;

    if (cost < 0)
      cost *= -1;

    cost = -1 * (Settings.Action_WalkFoodCostBase +
                 Settings.Action_WalkFoodCostPerHeight * cost);

    if (ant->checkFoodDelta(cost) && to->CanMoveTo(ant) &&
        from->CanMoveFrom(ant))
    {
      ant->registerFoodDelta(cost);
      to->MoveTo(ant);
      from->MoveFrom(ant);
      return true;
    }
    else
    {
      return false;
    }
  }
  case OutputActions::HarvestFood:
  {
    Tile *here = get(ant->Pos);
    int cost = here->CanHarvest(ant);
    if (cost >= 0 && ant->checkFoodDelta(-cost))
    {
      here->Harvest(ant);
      ant->registerFoodDelta(-cost);
      return true;
    }
    return false;

    break;
  }
  case OutputActions::GiveFood:
  {
    Tile *here = get(ant->Pos);
    int cost = here->CanGive(ant);
    if (cost >= 0 && ant->checkFoodDelta(-cost))
    {
      here->Give(ant);
      ant->registerFoodDelta(-cost);
      return true;
    }
    return false;

    break;
  }
  case OutputActions::TakeFood:
  {
    Tile *here = get(ant->Pos);
    int cost = here->CanTake(ant);
    if (cost >= 0 && ant->checkFoodDelta(-cost))
    {
      here->Take(ant);
      ant->registerFoodDelta(-cost);
      return true;
    }
    return false;

    break;
  }
  case OutputActions::WorkTile:
  {
    Tile *here = get(ant->Pos);
    int cost = here->CanWork(ant);
    if (cost >= 0 && ant->checkFoodDelta(-cost))
    {
      here->Work(ant);
      ant->registerFoodDelta(-cost);
      return true;
    }
    return false;

    break;
  }
  case OutputActions::CultivateTile:
  {
    Tile *here = get(ant->Pos);
    int cost = here->CanCultivate(ant);
    if (cost >= 0 && ant->checkFoodDelta(-cost))
    {
      here->Cultivate(ant);
      ant->registerFoodDelta(-cost);
      return true;
    }
    return false;

    break;
  }
  case OutputActions::BuildRoad:
  {
    Tile *here = get(ant->Pos);
    int cost = here->CanBuild(ant);
    if (cost >= 0 && ant->checkFoodDelta(-cost))
    {
      here->Build(ant);
      ant->registerFoodDelta(-cost);
      return true;
    }
    return false;
    break;
  }
  case OutputActions::RaiseHeight:
  {
    Tile *here = get(ant->Pos);
    if (here->CanRaise() && ant->checkFoodDelta(-Settings.Action_RaiseLower))
    {
      ant->registerFoodDelta(-Settings.Action_RaiseLower);
      here->RaiseHeight(ant);
      return true;
    }
    return false;
    break;
  }
  case OutputActions::LowerHeight:
  {
    Tile *here = get(ant->Pos);
    if (here->CanLower() && ant->checkFoodDelta(-Settings.Action_RaiseLower))
    {
      ant->registerFoodDelta(-Settings.Action_RaiseLower);
      here->LowerHeight(ant);
      return true;
    }
    return false;
    break;
  }
  case OutputActions::ProduceOffspring:
  {
    if (ant->checkFoodDelta(-Settings.Action_ProduceOffspring))
    {
      ant->registerFoodDelta(-Settings.Action_ProduceOffspring);
      //Simulation produces the offspring
      return true;
    }
    return false;
    break;
  }
  case OutputActions::IncrementCSMA:
  {
    if (!ant->checkFoodDelta(-Settings.Action_ColonyMemoryChangeCost))
      return false;
    ant->registerFoodDelta(-Settings.Action_ColonyMemoryChangeCost);
    colony->memory_static_a++;
    return true;
    break;
  }
  case OutputActions::IncrementCSMB:
  {
    if (!ant->checkFoodDelta(-Settings.Action_ColonyMemoryChangeCost))
      return false;
    ant->registerFoodDelta(-Settings.Action_ColonyMemoryChangeCost);
    colony->memory_static_b++;
    return true;
    break;
  }
  case OutputActions::IncrementCSMC:
  {
    if (!ant->checkFoodDelta(-Settings.Action_ColonyMemoryChangeCost))
      return false;
    ant->registerFoodDelta(-Settings.Action_ColonyMemoryChangeCost);
    colony->memory_static_c++;
    return true;
    break;
  }
  case OutputActions::IncrementCSMD:
  {
    if (!ant->checkFoodDelta(-Settings.Action_ColonyMemoryChangeCost))
      return false;
    ant->registerFoodDelta(-Settings.Action_ColonyMemoryChangeCost);
    colony->memory_static_d++;
    return true;
    break;
  }
  case OutputActions::DecrementCSMA:
  {
    if (!ant->checkFoodDelta(-Settings.Action_ColonyMemoryChangeCost))
      return false;
    ant->registerFoodDelta(-Settings.Action_ColonyMemoryChangeCost);
    colony->memory_static_a--;
    return true;
    break;
  }
  case OutputActions::DecrementCSMB:
  {
    if (!ant->checkFoodDelta(-Settings.Action_ColonyMemoryChangeCost))
      return false;
    ant->registerFoodDelta(-Settings.Action_ColonyMemoryChangeCost);
    colony->memory_static_b--;
    return true;
    break;
  }
  case OutputActions::DecrementCSMC:
  {
    if (!ant->checkFoodDelta(-Settings.Action_ColonyMemoryChangeCost))
      return false;
    ant->registerFoodDelta(-Settings.Action_ColonyMemoryChangeCost);
    colony->memory_static_c--;
    return true;
    break;
  }
  case OutputActions::DecrementCSMD:
  {
    if (!ant->checkFoodDelta(-Settings.Action_ColonyMemoryChangeCost))
      return false;
    ant->registerFoodDelta(-Settings.Action_ColonyMemoryChangeCost);
    colony->memory_static_d--;
    return true;
    break;
  }
  case OutputActions::ReleaseSmallScentA:
  {
    if (!ant->checkFoodDelta(-Settings.Action_ReleaseSmallScentCost))
      return false;
    ant->registerFoodDelta(-Settings.Action_ReleaseSmallScentCost);
    ant->ReleaseSmallScentA();
    return true;
    break;
  }
  case OutputActions::ReleaseLargeScentA:
  {
    if (!ant->checkFoodDelta(-Settings.Action_ReleaseLargeScentCost))
      return false;
    ant->registerFoodDelta(-Settings.Action_ReleaseLargeScentCost);
    ant->ReleaseLargeScentA();
    return true;
    break;
  }
  case OutputActions::ReleaseSmallScentB:
  {
    if (!ant->checkFoodDelta(-Settings.Action_ReleaseSmallScentCost))
      return false;
    ant->registerFoodDelta(-Settings.Action_ReleaseSmallScentCost);
    ant->ReleaseSmallScentB();
    return true;
    break;
  }
  case OutputActions::ReleaseLargeScentB:
  {
    if (!ant->checkFoodDelta(-Settings.Action_ReleaseLargeScentCost))
      return false;
    ant->registerFoodDelta(-Settings.Action_ReleaseLargeScentCost);
    ant->ReleaseLargeScentB();
    return true;
    break;
  }
  case OutputActions::ReleaseSmallScentC:
  {
    if (!ant->checkFoodDelta(-Settings.Action_ReleaseSmallScentCost))
      return false;
    ant->registerFoodDelta(-Settings.Action_ReleaseSmallScentCost);
    ReleaseSmallScentC(ant);
    return true;
    break;
  }
  case OutputActions::ReleaseLargeScentC:
  {
    if (!ant->checkFoodDelta(-Settings.Action_ReleaseLargeScentCost))
      return false;
    ant->registerFoodDelta(-Settings.Action_ReleaseLargeScentCost);
    ReleaseLargeScentC(ant);
    return true;
    break;
  }
  case OutputActions::ResetColonyTimerA:
  {
    if (!ant->checkFoodDelta(-Settings.Action_ColonyTimerReset))
      return false;
    ant->registerFoodDelta(-Settings.Action_ColonyTimerReset);
    colony->ColonyTimerA = iteration;
    return true;
    break;
  }
  case OutputActions::ResetColonyTimerB:
  {
    if (!ant->checkFoodDelta(-Settings.Action_ColonyTimerReset))
      return false;
    ant->registerFoodDelta(-Settings.Action_ColonyTimerReset);
    colony->ColonyTimerB = iteration;
    return true;
    break;
  }
  default:
  {
    return ant->EvaluateAction(action, iteration);
  }
  }
  return true;
}