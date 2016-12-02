// Project Includes
#include "./environment.h"

// Dep includes
#include "../deps/FastNoise/FastNoise.h"

// STL Includes
#include <iostream>
#include <random>

using namespace std;

void Environment::Print() {
  for (int x = 0; x < ENV_SIDE; x++) {
    for (int y = 0; y < ENV_SIDE; y++) {
      std::cout << std::setw(3) << (int)this->get(x, y)->type << ',';
    }
    std::cout << '\n';
  }

  std::cout << std::endl << std::endl << std::endl;

  for (int x = 0; x < ENV_SIDE; x++) {
    for (int y = 0; y < ENV_SIDE; y++) {
      std::cout << std::setw(3) << (int)this->get(x, y)->getHeight() << ',';
    }
    std::cout << '\n';
  }

  std::cout << std::endl << std::endl << std::endl;
};