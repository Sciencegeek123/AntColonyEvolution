#include "ant/ant.h"

OutputActions Ant::GetOutput(ACSData input) {
  OutputActions selected = brain->get(std::move(input));
  return selected;
}