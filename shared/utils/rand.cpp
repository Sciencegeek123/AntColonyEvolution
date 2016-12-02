#include "utils/utils.h"

using namespace std;

using namespace utils::rand;

unique_ptr<random_device> utils::rand::randomDevice;
unique_ptr<default_random_engine> utils::rand::randomEngine;

void utils::rand::initDistribution() {
  if (!randomDevice) {
    randomDevice.reset(new random_device());
  }

  if (!randomEngine) {
    randomEngine.reset(new default_random_engine());
    randomEngine->seed((*randomDevice)());
  }
}

void utils::rand::setGeneratorSeed(unsigned int seed) {
  randomEngine->seed(seed);
}