#include <cstring>
#include <iostream>
#include <set>
#include "tests/tests.h"
#include "utils/utils.h"

using namespace std;

int main(int argc, char** argv) {
  set<string> validArgs;
  validArgs.emplace("-s");
  validArgs.emplace("testRandSpeed");
  validArgs.emplace("testEnv");

  set<string> args;

  for (int i = 1; i < argc; i++) {
    if (validArgs.find(argv[i]) == validArgs.end()) {
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
      cout << endl << "Invalid argument: " << argv[i] << endl;
      cout << endl << "Valid arguments are: " << endl;
      for (auto it = validArgs.begin(); it != validArgs.end(); it++) {
        cout << '\t' << *it << endl;
      }
      cout << endl << "Please try again with correct arguments." << endl;
      cout << "Thank you! Have a nice day!" << endl;
      exit(-1);
    }
    args.emplace(argv[i]);
  }

  if (args.find("-s") == args.end()) {
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
  }

  utils::rand::initDistribution();

  if (args.find(string("testRandSpeed")) != args.end()) {
    runRandomTestSimulation();
  }

  if (args.find(string("testEnv")) != args.end()) {
    runEnvTest();
  }

  if (args.find("-s") == args.end()) {
    cout << "Thank you! Have a nice day!" << endl;
  }
}