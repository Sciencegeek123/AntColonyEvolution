#include <iostream>
#include <memory>

using namespace std;

int main() {
  shared_ptr<int> id(new int(0));
  while (*id < 10) {
    (*id)++;
  }
  cout << "Hello world!" << endl;
}