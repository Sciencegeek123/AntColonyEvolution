#include "utils/utils.h"
#include <chrono>
#include <climits>
#include <iostream>

using namespace std;
using namespace std::chrono;

static unique_ptr<mt19937_64> randomEngine(new mt19937_64(high_resolution_clock::now().time_since_epoch().count()));
static unique_ptr<uniform_int_distribution<int>> uniformIntDistribution(new uniform_int_distribution<int>(INT_MAX, INT_MIN));

string utils::randomString(int length)
{
  string result = string(length, '\0');
  uniform_int_distribution<unsigned short> dist(0, 255);
  for (int i = 0; i < length; i++)
  {
    result[i] = (char)dist(*randomEngine);
  }
  return result;
}

void utils::initRandom()
{
  cout << "Testing random number generator." << endl;
  cout << "There is a bug in my logic or in the clib++ causing crashes." << endl;
  cout << "Engine: " << (bool)randomEngine << endl;
  cout << "Distri: " << (bool)uniformIntDistribution << endl;
  cout << "Random: " << (*uniformIntDistribution)(*randomEngine) << endl;
  cout << endl;
}

int utils::getRandomInt()
{
  return (*uniformIntDistribution)(*randomEngine);
}