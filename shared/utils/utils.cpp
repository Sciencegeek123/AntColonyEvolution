#include "utils/utils.h"
#include <random>

using namespace std;

unique_ptr<_Settings> Settings = unique_ptr<_Settings>(new _Settings());

ACSData utils::newACSData() {
  return std::move(ACSData(new std::array<byte, 64>()));
}

_Settings::_Settings() {
  // This will eventually load settings from a config file or Redis
}