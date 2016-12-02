// Project Includes
#include "ai/ai_random.h"

// STL Includes
#include <random>
#include <iostream>

// Using
using namespace std;

Random_AI::Random_AI(std::string input) : AI(input) {}

shared_ptr<AI> Random_AI::createRandom() {
  return shared_ptr<AI>(new Random_AI(utils::randomString(25)));
}

shared_ptr<AI> Random_AI::createFrom(std::string &input) {
  return shared_ptr<AI>(new Random_AI(input));
}

static std::random_device rd;
static std::default_random_engine generator;
static std::uniform_int_distribution<int> distribution(0, 63);

OutputActions Random_AI::get(ACSData input) {
  return (OutputActions)distribution(generator);
}