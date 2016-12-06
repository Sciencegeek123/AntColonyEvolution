#include "ant/ant.h"
#include "deps/base64.h"

using namespace std;

json Ant::GetJSON()
{
    json job;
    job["netFood"] = food_net;
    job["posFood"] = food_income;
    job["negFood"] = food_expense;
    job["creationTime"] = creationTime;
    job["deathTime"] = deathTime;

    //string rawData;

    //Base64 b64;
    //b64.Encode(brain->GeneticString, &rawData);

    //job["geneticDataB64"] = rawData;
    job["successfulActionCount"] = json(successfulActionCount);
    job["failedActionCount"] = json(failedActionCount);

    return job;
}