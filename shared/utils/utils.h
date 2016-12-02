#pragma once

#include "ai/ai_enums.h"

#include <memory>
#include <random>
#include <string>
#include <cmath>

typedef unsigned char byte;
typedef std::unique_ptr<std::array<byte, 64>> ACSData;

namespace utils {
namespace rand {
extern std::unique_ptr<std::random_device> randomDevice;
extern std::unique_ptr<std::default_random_engine> randomEngine;

void initDistribution();
void setGeneratorSeed(unsigned int seed);
}
ACSData newACSData();
std::string randomString(int length);
}
