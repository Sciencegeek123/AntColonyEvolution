#include <cstring>
#include <iostream>
#include "./framework/framework.h"

using namespace std;

int main(int argv, char** argc) {
  cout << "Ant Colony Simulation" << endl;
  cout << "Created for LSU CSC 4444" << endl;
  cout << "Created by:" << endl;
  cout << "\tW. Craig Jones" << endl;
  cout << "\tSam Shresha" << endl;
  cout << "\tMahdi Judeh" << endl;
  cout << "\tSam Fadrigalan" << endl;

  if (argv > 1 && strcmp(argc[1], "test1") == 0) {
    runTestSimulation();
  } else {
    cout << "No recognized arguments" << endl;
  }
}