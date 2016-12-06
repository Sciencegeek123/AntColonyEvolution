// Project Includes
#include "environment/environment.h"
#include "ant/ant.h"

using namespace std;

// Dep Includes

// Generic Implementations

// Specific Implementations

void FoodTile::Harvest(shared_ptr<Ant> &ant)
{
    if (foodContained > Settings.Tile_FoodTransferAmount)
    {
        foodContained -= Settings.Tile_FoodTransferAmount;
        ant->registerFoodDelta(Settings.Tile_FoodTransferAmount);
    }
    else
    {
        foodContained = 0;
        ant->registerFoodDelta(foodContained);
    }
}

void PlantTile::Harvest(shared_ptr<Ant> &ant)
{
    ant->registerFoodDelta(Settings.Tile_FoodTransferAmount);
}

void GrassTile::Cultivate(shared_ptr<Ant> &ant)
{
    ant->registerFoodDelta(Settings.Tile_GrassCultivateAmount);
}

void GrassTile::Work(shared_ptr<Ant> &ant)
{
    ant->registerFoodDelta(-Settings.Tile_GrassWorkCost);
    if (utils::getRandomInt() % Settings.Tile_GrassWorkProbability == 0)
    {
        upgradeToFood = true;
    }
}

void GrassTile::Build(shared_ptr<Ant> &ant)
{
    ant->registerFoodDelta(-Settings.Tile_GrassBuildCost);
    upgradeToRoad = true;
}

void SandTile::Work(shared_ptr<Ant> &ant)
{
    ant->registerFoodDelta(-Settings.Tile_SandWorkCost);
    if (utils::getRandomInt() % Settings.Tile_SandWorkProbability == 0)
    {
        upgradeToGrass = true;
    }
}

void TrapTile::Work(shared_ptr<Ant> &ant)
{
    ant->registerFoodDelta(-Settings.Tile_TrapWorkCost);
    hunger -= Settings.Tile_TrapWorkDelta;
}

bool ColonyTile::checkFoodDelta(int delta)
{
    return delta > 0 ? true : -delta < food_net;
}
int ColonyTile::registerFoodDelta(int delta)
{
    if (delta < 0)
    {
        delta *= -1;
        food_expense += delta;
        *(food_change_log.rbegin()) -= delta;
        food_net -= delta;
        cdebug << "* -CFood: " << delta << endl;
        return -delta;
    }
    else
    {
        food_net += delta;
        *(food_change_log.rbegin()) += delta;
        food_income += delta;
        cdebug << "* +CFood: " << delta << endl;
        return delta;
    }
    return 0;
}

// *********** STEP

Tile *ColonyTile::Step()
{
    for (auto ant : *ants)
    {
        ant->registerFoodDelta(-Settings.Tile_ColonyIdleCost);
    }
    registerFoodDelta(-Settings.Tile_ColonyFoodConsumption);
    return nullptr;
}

Tile *FoodTile::Step()
{
    for (auto ant : *ants)
    {
        ant->registerFoodDelta(-Settings.Tile_FoodIdleCost);
    }

    if (foodContained <= 0)
    {
        return new GrassTile(height, position);
    }
    else
    {
        return nullptr;
    }
}

Tile *PlantTile::Step()
{
    for (auto ant : *ants)
    {
        ant->registerFoodDelta(-Settings.Tile_PlantIdleCost);
    }
    return nullptr;
}

Tile *RoadTile::Step()
{
    for (auto ant : *ants)
    {
        ant->registerFoodDelta(-Settings.Tile_RoadIdleCost);
    }
    return nullptr;
}

Tile *GrassTile::Step()
{
    if (upgradeToFood)
    {
        return new FoodTile(height, position);
    }
    else if (upgradeToRoad)
    {
        return new RoadTile(height, position);
    }
    for (auto ant : *ants)
    {
        ant->registerFoodDelta(-Settings.Tile_GrassIdleCost);
    }
    return nullptr;
}

Tile *SandTile::Step()
{

    if (upgradeToGrass)
    {
        return new GrassTile(height, position);
    }

    for (auto ant : *ants)
    {
        ant->registerFoodDelta(-Settings.Tile_SandIdleCost);
    }

    if (utils::getRandomInt() % Settings.Tile_TrapProbability == 0)
    {
        return new TrapTile(height, position);
    }
    return nullptr;
}

Tile *TrapTile::Step()
{
    for (auto ant : *ants)
    {
        int delta = ant->registerFoodDelta(-Settings.Tile_TrapIdleCost);
        hunger -= delta;
    }

    lifetime--;

    if (hunger <= 0 || lifetime <= 0)
    {
        return new SandTile(height, position);
    }
    else
    {
        return nullptr;
    }
}