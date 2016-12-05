// Project Includes
#include "environment/environment.h"
#include "ant/ant.h"

// Dep Includes

// Generic Implementations

// Specific Implementations

void FoodTile::Harvest(std::shared_ptr<Ant> &ant)
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

void PlantTile::Harvest(std::shared_ptr<Ant> &ant)
{
    ant->registerFoodDelta(Settings.Tile_FoodTransferAmount);
}

// *********** STEP

Tile *ColonyTile::Step()
{
    for (auto ant : *ants)
    {
        ant->registerFoodDelta(-Settings.Tile_ColonyIdleCost);
    }
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
    for (auto ant : *ants)
    {
        ant->registerFoodDelta(-Settings.Tile_GrassIdleCost);
    }
    return nullptr;
}

Tile *SandTile::Step()
{
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