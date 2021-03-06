#pragma once
#include "ai/ai.h"

class Random_AI : public AI
{
private:
  Random_AI(std::string input);

public:
  std::string getTypeName() { return std::move("Random_AI"); }
  static std::shared_ptr<AI> createRandom();
  static std::shared_ptr<AI> createFrom(std::string &input);
  OutputActions get(ACSData input);
  virtual std::shared_ptr<AI> reproduce(std::shared_ptr<std::set<std::shared_ptr<Ant>, AntComparator>> parents) { return createRandom(); }
};