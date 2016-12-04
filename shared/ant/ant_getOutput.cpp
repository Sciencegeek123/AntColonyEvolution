#include "ant/ant.h"
#include <iostream>

OutputActions Ant::GetOutput(ACSData input) {
  OutputActions selected = brain->get(std::move(input));
  return selected;
}