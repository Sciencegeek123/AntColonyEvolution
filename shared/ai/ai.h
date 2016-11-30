#pragma once

//Project Includes
#include "../logging/logging.h"

//STL Includes
#include <string>
#include <array>
#include <memory>

enum InputVars
{
    CurrentFoodMagnitude = 0,
    ColonyFoodMagnitude,
    Age,
    InverseAge,
    MovingPersonalFoodTrend,
    LifetimePersonalFoodTrend,
    MovingColonyFoodTrend,
    LifetimeColonyFoodTrend,
    PersonalTimerA,
    PersonalTimerB,
    ColonyTimerA,
    ColonyTimerB,
    TileTypeO,
    TileTypePP,
    TileTypePN,
    TileTypeNP,
    TileTypeNN,
    TileHeightO,
    TileHeightPP,
    TileHeightPN,
    TileHeightNP,
    TileHeightNN,
    TileAntCountO,
    TileAntCountPP,
    TileAntCountPN,
    TileAntCountNP,
    TileAntCountNN,
    PersonalDecayingMemoryA,
    PersonalDecayingMemoryB,
    PersonalDecayingMemoryC,
    PersonalDecayingMemoryD,
    PersonalStaticMemoryA,
    PersonalStaticMemoryB,
    PersonalStaticMemoryC,
    PersonalStaticMemoryD,
    ColonyStaticMemoryA,
    ColonyStaticMemoryB,
    ColonyStaticMemoryC,
    ColonyStaticMemoryD,
    PersonalPassiveScentO,
    PersonalPassiveScentPP,
    PersonalPassiveScentPN,
    PersonalPassiveScentNP,
    PersonalPassiveScentNN,
    PersonalActiveScentAO,
    PersonalActiveScentAPP,
    PersonalActiveScentAPN,
    PersonalActiveScentANP,
    PersonalActiveScentANN,
    PersonalActiveScentBO,
    PersonalActiveScentBPP,
    PersonalActiveScentBPN,
    PersonalActiveScentBNP,
    PersonalActiveScentBNN,
    ColonyPassiveScentO,
    ColonyPassiveScentPP,
    ColonyPassiveScentPN,
    ColonyPassiveScentNP,
    ColonyPassiveScentNN,
    ColonyActiveScentCO,
    ColonyActiveScentCPP,
    ColonyActiveScentCPN,
    ColonyActiveScentCNP,
    ColonyActiveScentCNN
};

enum OutputActions
{
    NoOP = 0,
    MoveUP,
    MoveDOWN,
    MoveLEFT,
    MoveRIGHT,
    HarvestFood,
    GiveFood,
    TakeFood,
    WorkTile,
    CultivateTile,
    BuildRoad,
    RaiseHeight,
    LowerHeight,
    ProduceOffspring,
    ADecrementPDMA,
    BDecrementPDMA,
    AIncrementPDMA,
    BIncrementPDMA,
    ADecrementPDMB,
    BDecrementPDMB,
    AIncrementPDMB,
    BIncrementPDMB,
    ADecrementPDMC,
    BDecrementPDMC,
    AIncrementPDMC,
    BIncrementPDMC,
    ADecrementPDMD,
    BDecrementPDMD,
    AIncrementPDMD,
    BIncrementPDMD,
    ADecrementPSMA,
    BDecrementPSMA,
    AIncrementPSMA,
    BIncrementPSMA,
    ADecrementPSMB,
    BDecrementPSMB,
    AIncrementPSMB,
    BIncrementPSMB,
    ADecrementPSMC,
    BDecrementPSMC,
    AIncrementPSMC,
    BIncrementPSMC,
    ADecrementPSMD,
    BDecrementPSMD,
    AIncrementPSMD,
    BIncrementPSMD,
    VoteIncrementCSMA,
    VoteIncrementCSMB,
    VoteIncrementCSMC,
    VoteIncrementCSMD,
    VoteDecrementCSMA,
    VoteDecrementCSMB,
    VoteDecrementCSMC,
    VoteDecrementCSMD,
    ReleaseSmallScentA,
    ReleaseLargeScentA,
    ReleaseSmallScentB,
    ReleaseLargeScentB,
    ReleaseSmallScentC,
    ReleaseLargeScentC,
    ResetPersonalTimerA,
    ResetPersonalTimerB,
    VoteResetColonyTimerA,
    VoteResetColonyTimerB
};

enum AITypes
{

};

class AI
{
  protected:
    AI(std::string &input){};
    AI(){};

  public:
    virtual std::string getTypeName() { return std::move("BASE"); }
    static std::shared_ptr<AI> createRandom() { return std::shared_ptr<AI>(new AI()); }
    static std::shared_ptr<AI> createFrom(std::string &input) { return std::shared_ptr<AI>(new AI(input)); }
    virtual OutputActions get(std::array<unsigned char, 64> input) { return OutputActions::NoOP; }
};

class Random_AI : public AI
{
private: 
    Random_AI();
  public:
    std::string getTypeName() { return std::move("Random_AI"); }
    static std::shared_ptr<AI> createRandom();
    static std::shared_ptr<AI> createFrom(std::string &input);
    OutputActions get(std::array<unsigned char, 64> input);
};

//class FFNN_AI : public AI { }