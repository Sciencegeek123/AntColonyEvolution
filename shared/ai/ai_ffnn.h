#pragma once
#include "ai/ai.h"

class Layer;

class FFNN_AI : public AI
{
private:
  FFNN_AI(std::string input);
  Layer *layers;

public:
  std::string getTypeName()
  {
    return std::move("FFNN_AI");
  }
  static std::shared_ptr<AI> createRandom();
  static std::shared_ptr<AI> createFrom(std::string &input);
  OutputActions get(ACSData input);
  std::shared_ptr<AI> reproduce(std::shared_ptr<std::set<std::shared_ptr<Ant>, AntComparator>> parents) { return createRandom(); }
};