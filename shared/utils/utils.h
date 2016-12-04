#pragma once

#include "ai/ai_enums.h"

#include <array>
#include <cmath>
#include <memory>
#include <random>
#include <string>

#define ENV_SIDE 256
#define ENV_SIZE 65536

typedef unsigned char byte;
typedef std::unique_ptr<std::array<byte, 64>> ACSData;

struct _Settings {
 public:
  std::string RD_HOST = "localhost";
  std::string RD_AUTH = "LetsMakeSomeAntsDoWorkForUs";

  int SIM_DURATION = 65536;

  int ANT_START_FOOD = 1000;
  int ANT_MAX_FOOD = 50000;

  int COLONY_START_FOOD = 5000;

  _Settings();
};

extern std::unique_ptr<_Settings> Settings;

namespace utils {
int getRandomInt();
ACSData newACSData();
std::string randomString(int length);
}
