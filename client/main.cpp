#include <cstring>
#include <iostream>
#include <set>
#include <map>
#include "tests/tests.h"
#include "utils/utils.h"
#include <iomanip>

using namespace std;

int main(int argc, char **argv)
{
  set<string> validArgs;
  map<string, string> argDesc;

  validArgs.emplace("-s");
  argDesc.emplace("-s", "Silences filler text.");

  validArgs.emplace("testRandSpeed");
  argDesc.emplace("testRandSpeed", "Tests the speed of the simulation code.");

  validArgs.emplace("testFFNNSpeed");
  argDesc.emplace("testFFNNSpeed", "Tests the speed of the simulation code.");

  validArgs.emplace("testEnv");
  argDesc.emplace("testEnv", "Prints a random environment for analysis.");

  validArgs.emplace("runFFNNSearch");
  argDesc.emplace("runFFNNSearch", "Searches for 100 FFNN strings over the threshold of 10.");

  set<string> args;

  if (argc == 1)
  {
    cdebug << endl;
    cdebug << "#########################" << endl;
    cdebug << "# Ant Colony Simulation #" << endl;
    cdebug << "# LSU CSC  4444 Project #" << endl;
    cdebug << "#########################" << endl;
    cdebug << "# Created by:           #" << endl;
    cdebug << "#     W. Craig Jones    #" << endl;
    cdebug << "#     Sam Shresha       #" << endl;
    cdebug << "#     Mahdi Judeh       #" << endl;
    cdebug << "#     Sam Fadrigalan    #" << endl;
    cdebug << "#########################" << endl;
    cdebug << endl;
    cdebug << endl
         << "You must supply 1 argument (or 1 and the -s)." << endl;
    cdebug << endl
         << "Valid arguments are: " << endl;
    for (auto it = validArgs.begin(); it != validArgs.end(); it++)
    {
      cdebug << '\t' << *it << " : ";
      auto dit = argDesc.find(*it);
      if (dit == argDesc.end())
      {
        cdebug << "!! Missing Description. Contact Craig." << endl;
      }
      else
      {
        cdebug << dit->second << endl;
      }
    }
    cdebug << endl
         << "Please try again with correct arguments." << endl;
    cdebug << "Thank you! Have a nice day!" << endl;
    exit(-1);
  }

  for (int i = 1; i < argc; i++)
  {
    if (validArgs.find(argv[i]) == validArgs.end())
    {
      cdebug << endl;
      cdebug << "#########################" << endl;
      cdebug << "# Ant Colony Simulation #" << endl;
      cdebug << "# LSU CSC  4444 Project #" << endl;
      cdebug << "#########################" << endl;
      cdebug << "# Created by:           #" << endl;
      cdebug << "#     W. Craig Jones    #" << endl;
      cdebug << "#     Sam Shresha       #" << endl;
      cdebug << "#     Mahdi Judeh       #" << endl;
      cdebug << "#     Sam Fadrigalan    #" << endl;
      cdebug << "#########################" << endl;
      cdebug << endl;
      cdebug << endl
           << "Invalid argument: " << argv[i] << endl;
      cdebug << endl
           << "Valid arguments are: " << endl;
      for (auto it = validArgs.begin(); it != validArgs.end(); it++)
      {
        cdebug << '\t' << *it << endl;
      }
      cdebug << endl
           << "Please try again with correct arguments." << endl;
      cdebug << "Thank you! Have a nice day!" << endl;
      exit(-1);
    }
    args.emplace(argv[i]);
  }

  if (args.find("-s") == args.end())
  {
    cdebug << endl;
    cdebug << "#########################" << endl;
    cdebug << "# Ant Colony Simulation #" << endl;
    cdebug << "# LSU CSC  4444 Project #" << endl;
    cdebug << "#########################" << endl;
    cdebug << "# Created by:           #" << endl;
    cdebug << "#     W. Craig Jones    #" << endl;
    cdebug << "#     Sam Shresha       #" << endl;
    cdebug << "#     Mahdi Judeh       #" << endl;
    cdebug << "#     Sam Fadrigalan    #" << endl;
    cdebug << "#########################" << endl;
    cdebug << endl;
    //utils::initRandom();
  }

  if (args.find(string("runFFNNSearch")) != args.end())
  {
    runFFNNSearch();
  }

  if (args.find(string("testFFNNSpeed")) != args.end())
  {
    runFFNNTestSimulation();
  }

  if (args.find(string("testRandSpeed")) != args.end())
  {
    runRandomTestSimulation();
  }

  if (args.find(string("testEnv")) != args.end())
  {
    runEnvTest();
  }

  if (args.find("-s") == args.end())
  {
    cdebug << "Thank you! Have a nice day!" << endl;
  }
}