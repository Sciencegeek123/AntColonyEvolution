//Project Includes
#include "./ai.h"

//STL Includes
#include <random>

//Using
using namespace std;

Random_AI::Random_AI() : AI() { }

shared_ptr<AI> Random_AI::createRandom() {
    return shared_ptr<AI>(new Random_AI());
}

shared_ptr<AI> Random_AI::createFrom(std::string &input) {
    return shared_ptr<AI>(new Random_AI());
}

static std::random_device rd;
static std::default_random_engine generator;
static std::uniform_int_distribution<int> distribution(0,63);

OutputActions Random_AI::get(std::array<unsigned char, 64> input) {
    return (OutputActions)distribution(generator);
}