#include "ant/ant.h"
#include "utils/utils.h"
using namespace std;

void Ant::ReflectAction(OutputActions action, bool success)
{
    if (success)
    {
        successfulActionCount[(int)action]++;
    }
    else
    {
        failedActionCount[(int)action]++;
    }
}