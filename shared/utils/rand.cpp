#include "utils/utils.h"
#include <chrono>
#include <climits>

using namespace std;
using namespace std::chrono;

static unique_ptr<mt19937> randomEngine;
static unique_ptr<uniform_int_distribution<int>> uniformIntDistribution;

string utils::randomString(int length) {
  string result = string(length, '\0');
  uniform_int_distribution<unsigned short> dist(0, 255);
  for (int i = 0; i < length; i++) {
    result[i] = (char)dist(*randomEngine);
  }
  return result;
}

int utils::getRandomInt() {
  if (!randomEngine) {
    randomEngine.reset(
        new mt19937(high_resolution_clock::now().time_since_epoch().count()));
    uniformIntDistribution.reset(
        new uniform_int_distribution<int>(INT_MAX, INT_MIN));
  }

  return (*uniformIntDistribution)(*randomEngine);
}