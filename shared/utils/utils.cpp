#include "utils/utils.h"
#include <random>

using namespace std;

ACSData utils::newACSData() {
  return std::move(ACSData(new std::array<byte, 64>()));
}

string utils::randomString(int length) {
  string result = string(length, '\0');
  uniform_int_distribution<unsigned short> dist(0, 255);
  for (int i = 0; i < length; i++) {
    result[i] = (char)dist(*utils::rand::randomEngine);
  }
  return result;
}