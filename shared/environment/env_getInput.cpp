// Project Includes
#include "environment/environment.h"
#include "utils/utils.h"
#include "ant/ant.h"

// STL Includes
#include <iostream>
#include <random>

using namespace std;

ACSData Environment::GetInput(std::shared_ptr<Ant> &ant)
{
    //Add the colony passive scent here
    if (colonyPassiveScent[ant->Pos.first + ant->Pos.second * ENV_SIDE] + ant->GC->SmallScent_Delta < 255)
    {
        colonyPassiveScent[ant->Pos.first + ant->Pos.second * ENV_SIDE] += ant->GC->SmallScent_Delta;
    }
    else
    {
        colonyPassiveScent[ant->Pos.first + ant->Pos.second * ENV_SIDE] = 255;
    }

    // Get the base info from the ant.
    ACSData input = ant->GetPersonalInput(iteration);

    {
        // Colony Food Magnitude
        (*input)[InputVars::ColonyFoodMagnitude] =
            (byte)(255 * ((float)colony->food_net /
                          (float)ant->GC->ColonyFood_Scale * 4.0f));
    }
    {
        // Moving Colony Food Trend

        unsigned int duration = (unsigned int)ant->GC->ColonyFoodTrend_Duration *
                                (unsigned int)ant->GC->ColonyFoodTrend_Duration;

        float change = 0;
        int i = duration;
        for (auto it = colony->food_change_log.begin();
             it != colony->food_change_log.end() && i-- > 0; it++)
        {
            change += *it;
        }

        (*input)[InputVars::MovingColonyFoodTrend] = change / duration;
    }
    {
        // Lifetime Colony Food Trend
        (*input)[InputVars::LifetimeColonyFoodTrend] =
            (colony->food_net / (iteration + 1));
    }

    { // ColonyTimerA
        float timerA = (float)(iteration - colony->ColonyTimerA) /
                       (float)((iteration - colony->ColonyTimerA) +
                               ant->GC->ColonyTimerA_Scale + 1);

        (*input)[InputVars::ColonyTimerA] = timerA > 255 ? 255 : (byte)timerA;
    }
    {
        // ColonyTimerB
        float timerB = (float)(iteration - colony->ColonyTimerB) /
                       (float)((iteration - colony->ColonyTimerB) +
                               ant->GC->ColonyTimerB_Scale + 1);

        (*input)[InputVars::ColonyTimerB] = timerB > 255 ? 255 : (byte)timerB;
    }
    { // TileTypeO
        (*input)[InputVars::TileTypeO] = get(ant->Pos.first, ant->Pos.second)->type;
    }
    {
        // TileTypePP
        (*input)[InputVars::TileTypePP] =
            get(ant->Pos.first + 1, ant->Pos.second + 1)->type;
    }
    {
        // TileTypePN
        (*input)[InputVars::TileTypePN] =
            get(ant->Pos.first + 1, ant->Pos.second - 1)->type;
    }
    {
        // TileTypeNP
        (*input)[InputVars::TileTypeNP] =
            get(ant->Pos.first - 1, ant->Pos.second + 1)->type;
    }
    {
        // TileTypeNN
        (*input)[InputVars::TileTypeNN] =
            get(ant->Pos.first - 1, ant->Pos.second - 1)->type;
    }
    {
        // TileHeightO
        (*input)[InputVars::TileHeightO] =
            get(ant->Pos.first, ant->Pos.second)->height;
    }
    {
        // TileHeightPP
        (*input)[InputVars::TileHeightPP] =
            get(ant->Pos.first + 1, ant->Pos.second + 1)->height;
    }
    {
        // TileHeightPN
        (*input)[InputVars::TileHeightPN] =
            get(ant->Pos.first + 1, ant->Pos.second - 1)->height;
    }
    {
        // TileHeightNP
        (*input)[InputVars::TileHeightNP] =
            get(ant->Pos.first - 1, ant->Pos.second + 1)->height;
    }
    {
        // TileHeightNN
        (*input)[InputVars::TileHeightNN] =
            get(ant->Pos.first - 1, ant->Pos.second - 1)->height;
    }
    {
        // TileAntCountO
        (*input)[InputVars::TileAntCountO] =
            get(ant->Pos.first, ant->Pos.second)->getNumAnts();
    }
    {
        // TileAntCountPP
        (*input)[InputVars::TileAntCountPP] =
            get(ant->Pos.first + 1, ant->Pos.second + 1)->getNumAnts();
    }
    {
        // TileAntCountPN
        (*input)[InputVars::TileAntCountPN] =
            get(ant->Pos.first + 1, ant->Pos.second - 1)->getNumAnts();
    }
    {
        // TileAntCountNP
        (*input)[InputVars::TileAntCountNP] =
            get(ant->Pos.first - 1, ant->Pos.second + 1)->getNumAnts();
    }
    {
        // TileAntCountNN
        (*input)[InputVars::TileAntCountNN] =
            get(ant->Pos.first - 1, ant->Pos.second - 1)->getNumAnts();
    }
    {
        // ColonyStaticMemoryA
        (*input)[InputVars::ColonyStaticMemoryA] = colony->memory_static_a;
    }
    {
        // ColonyStaticMemoryB
        (*input)[InputVars::ColonyStaticMemoryA] = colony->memory_static_b;
    }
    {
        // ColonyStaticMemoryC
        (*input)[InputVars::ColonyStaticMemoryA] = colony->memory_static_c;
    }
    {
        // ColonyStaticMemoryD
        (*input)[InputVars::ColonyStaticMemoryA] = colony->memory_static_d;
    }
    {
        // PersonalPassiveScentO
        (*input)[InputVars::PersonalPassiveScentO] = ant->PersonalScentP[(ant->Pos.first) + (ant->Pos.second) * ENV_SIDE];
    }
    {
        // PersonalPassiveScentPP
        (*input)[InputVars::PersonalPassiveScentPP] = ant->PersonalScentP[(ant->Pos.first + 1) + (ant->Pos.second + 1) * ENV_SIDE];
    }
    {
        // PersonalPassiveScentPN
        (*input)[InputVars::PersonalPassiveScentPN] = ant->PersonalScentP[(ant->Pos.first + 1) + (ant->Pos.second - 1) * ENV_SIDE];
    }
    {
        // PersonalPassiveScentNP
        (*input)[InputVars::PersonalPassiveScentNP] = ant->PersonalScentP[(ant->Pos.first - 1) + (ant->Pos.second + 1) * ENV_SIDE];
    }
    {
        // PersonalPassiveScentNN
        (*input)[InputVars::PersonalPassiveScentNN] = ant->PersonalScentP[(ant->Pos.first - 1) + (ant->Pos.second - 1) * ENV_SIDE];
    }
    {
        // PersonalActiveScentAO
        (*input)[InputVars::PersonalActiveScentAO] = ant->PersonalScentA[(ant->Pos.first) + (ant->Pos.second) * ENV_SIDE];
    }
    {
        // PersonalActiveScentAPP
        (*input)[InputVars::PersonalActiveScentAPP] = ant->PersonalScentA[(ant->Pos.first + 1) + (ant->Pos.second + 1) * ENV_SIDE];
    }
    {
        // PersonalActiveScentAPN
        (*input)[InputVars::PersonalActiveScentAPN] = ant->PersonalScentA[(ant->Pos.first + 1) + (ant->Pos.second - 1) * ENV_SIDE];
    }
    {
        // PersonalActiveScentANP
        (*input)[InputVars::PersonalActiveScentANP] = ant->PersonalScentA[(ant->Pos.first - 1) + (ant->Pos.second + 1) * ENV_SIDE];
    }
    {
        // PersonalActiveScentANN
        (*input)[InputVars::PersonalActiveScentANN] = ant->PersonalScentA[(ant->Pos.first - 1) + (ant->Pos.second - 1) * ENV_SIDE];
    }
    {
        // PersonalActiveScentBO
        (*input)[InputVars::PersonalActiveScentBO] = ant->PersonalScentB[(ant->Pos.first) + (ant->Pos.second) * ENV_SIDE];
    }
    {
        // PersonalActiveScentBPP
        (*input)[InputVars::PersonalActiveScentBPP] = ant->PersonalScentB[(ant->Pos.first + 1) + (ant->Pos.second + 1) * ENV_SIDE];
    }
    {
        // PersonalActiveScentBPN
        (*input)[InputVars::PersonalActiveScentBPN] = ant->PersonalScentB[(ant->Pos.first + 1) + (ant->Pos.second - 1) * ENV_SIDE];
    }
    {
        // PersonalActiveScentBNP
        (*input)[InputVars::PersonalActiveScentBNP] = ant->PersonalScentB[(ant->Pos.first - 1) + (ant->Pos.second + 1) * ENV_SIDE];
    }
    {
        // PersonalActiveScentBNN
        (*input)[InputVars::PersonalActiveScentBNN] = ant->PersonalScentB[(ant->Pos.first - 1) + (ant->Pos.second - 1) * ENV_SIDE];
    }
    {
        // ColonyPassiveScentO
        (*input)[InputVars::ColonyPassiveScentO] = colonyPassiveScent[(ant->Pos.first) + (ant->Pos.second) * ENV_SIDE];
    }
    {
        // ColonyPassiveScentPP
        (*input)[InputVars::ColonyPassiveScentPP] = colonyPassiveScent[(ant->Pos.first + 1) + (ant->Pos.second + 1) * ENV_SIDE];
    }
    {
        // ColonyPassiveScentPN
        (*input)[InputVars::ColonyPassiveScentPN] = colonyPassiveScent[(ant->Pos.first + 1) + (ant->Pos.second - 1) * ENV_SIDE];
    }
    {
        // ColonyPassiveScentNP
        (*input)[InputVars::ColonyPassiveScentNP] = colonyPassiveScent[(ant->Pos.first - 1) + (ant->Pos.second + 1) * ENV_SIDE];
    }
    {
        // ColonyPassiveScentNN
        (*input)[InputVars::ColonyPassiveScentNN] = colonyPassiveScent[(ant->Pos.first - 1) + (ant->Pos.second - 1) * ENV_SIDE];
    }
    {
        // ColonyActiveScentCO
        (*input)[InputVars::ColonyActiveScentCO] = colonyActiveScent[(ant->Pos.first) + (ant->Pos.second) * ENV_SIDE];
    }
    {
        // ColonyActiveScentCPP
        (*input)[InputVars::ColonyActiveScentCPP] = colonyActiveScent[(ant->Pos.first + 1) + (ant->Pos.second + 1) * ENV_SIDE];
    }
    {
        // ColonyActiveScentCPN
        (*input)[InputVars::ColonyActiveScentCPN] = colonyActiveScent[(ant->Pos.first + 1) + (ant->Pos.second - 1) * ENV_SIDE];
    }
    {
        // ColonyActiveScentCNP
        (*input)[InputVars::ColonyActiveScentCNP] = colonyActiveScent[(ant->Pos.first - 1) + (ant->Pos.second + 1) * ENV_SIDE];
    }
    {
        // ColonyActiveScentCNN
        (*input)[InputVars::ColonyActiveScentCNN] = colonyActiveScent[(ant->Pos.first - 1) + (ant->Pos.second - 1) * ENV_SIDE];
    }

    return move(input);
}