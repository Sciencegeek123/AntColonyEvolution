#pragma once
#include "./ai.h"

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