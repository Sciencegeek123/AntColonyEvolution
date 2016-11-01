#include "Program\Program.h"
#include "FSM\FSM.h"

#include <iostream>

int main() {
	std::shared_ptr<FSM> myProgram = FSM::Create("Primary Application", "Entry Point");
	Program::StartProgram(myProgram);
	myProgram->RunForever();

	//Remove for non-manual code.
	std::cout << "Program ended. Press enter to continue." << std::endl;
	while(std::cin.rdbuf()->in_avail() > 0) {
		std::cin.ignore();
	}
	std::cin.ignore();
}