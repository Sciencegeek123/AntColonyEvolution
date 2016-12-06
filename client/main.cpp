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
    cout << endl;
    cout << "#########################" << endl;
    cout << "# Ant Colony Simulation #" << endl;
    cout << "# LSU CSC  4444 Project #" << endl;
    cout << "#########################" << endl;
    cout << "# Created by:           #" << endl;
    cout << "#     W. Craig Jones    #" << endl;
    cout << "#     Sam Shresha       #" << endl;
    cout << "#     Mahdi Judeh       #" << endl;
    cout << "#     Sam Fadrigalan    #" << endl;
    cout << "#########################" << endl;
    cout << endl;
    cout << endl
         << "You must supply 1 argument (or 1 and the -s)." << endl;
    cout << endl
         << "Valid arguments are: " << endl;
    for (auto it = validArgs.begin(); it != validArgs.end(); it++)
    {
      cout << '\t' << *it << " : ";
      auto dit = argDesc.find(*it);
      if (dit == argDesc.end())
      {
        cout << "!! Missing Description. Contact Craig." << endl;
      }
      else
      {
        cout << dit->second << endl;
      }
    }
    cout << endl
         << "Please try again with correct arguments." << endl;
    cout << "Thank you! Have a nice day!" << endl;
    exit(-1);
  }

  for (int i = 1; i < argc; i++)
  {
    if (validArgs.find(argv[i]) == validArgs.end())
    {
      cout << endl;
      cout << "#########################" << endl;
      cout << "# Ant Colony Simulation #" << endl;
      cout << "# LSU CSC  4444 Project #" << endl;
      cout << "#########################" << endl;
      cout << "# Created by:           #" << endl;
      cout << "#     W. Craig Jones    #" << endl;
      cout << "#     Sam Shresha       #" << endl;
      cout << "#     Mahdi Judeh       #" << endl;
      cout << "#     Sam Fadrigalan    #" << endl;
      cout << "#########################" << endl;
      cout << endl;
      cout << endl
           << "Invalid argument: " << argv[i] << endl;
      cout << endl
           << "Valid arguments are: " << endl;
      for (auto it = validArgs.begin(); it != validArgs.end(); it++)
      {
        cout << '\t' << *it << endl;
      }
      cout << endl
           << "Please try again with correct arguments." << endl;
      cout << "Thank you! Have a nice day!" << endl;
      exit(-1);
    }
    args.emplace(argv[i]);
  }

  if (args.find("-s") == args.end())
  {
    cout << endl;
    cout << "#########################" << endl;
    cout << "# Ant Colony Simulation #" << endl;
    cout << "# LSU CSC  4444 Project #" << endl;
    cout << "#########################" << endl;
    cout << "# Created by:           #" << endl;
    cout << "#     W. Craig Jones    #" << endl;
    cout << "#     Sam Shresha       #" << endl;
    cout << "#     Mahdi Judeh       #" << endl;
    cout << "#     Sam Fadrigalan    #" << endl;
    cout << "#########################" << endl;
    cout << endl;
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
    cout << "Thank you! Have a nice day!" << endl;
  }
}