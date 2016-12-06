#include "ant/ant.h"
#include "utils/utils.h"
using namespace std;

bool Ant::checkFoodDelta(int delta)
{
  return delta > 0 ? true : -delta < food_net;
}
int Ant::registerFoodDelta(int delta)
{
  if (delta < 0)
  {
    delta *= -1;
    if (food_net < delta)
      delta = food_net;
    food_expense += delta;
    *(food_change_log.rbegin()) -= delta;
    food_net -= delta;
    cdebug << "* -Food: " << delta << endl;
    return -delta;
  }
  else
  {
    if (food_net + delta > Settings.ANT_MAX_FOOD)
      delta = Settings.ANT_MAX_FOOD - food_net;

    food_net += delta;
    *(food_change_log.rbegin()) += delta;
    food_income += delta;
    cdebug << "* +Food: " << delta << endl;
    return delta;
  }
  return 0;
}