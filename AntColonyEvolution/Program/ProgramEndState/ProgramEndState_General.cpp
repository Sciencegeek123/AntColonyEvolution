#include "Program\Program.h"
#include <iostream>

std::unique_ptr<Program::ProgramEndState> Program::ProgramEndState::Create(std::shared_ptr<FSM> owner, const std::string origin, std::shared_ptr<Program> program) {
	return std::unique_ptr<Program::ProgramEndState>(new Program::ProgramEndState(owner, origin, program));
}

Program::ProgramEndState::ProgramEndState(std::shared_ptr<FSM> Owner, const std::string Origin, std::shared_ptr<Program> Program) :
	State(Owner, Origin) {
	program = Program;
}

void Program::ProgramEndState::Initialize() {
	std::cout << "Initialized " << GetStateName() << std::endl;
}

void Program::ProgramEndState::EnterActiveState() {
	std::cout << "Enter Active State " << GetStateName() << std::endl;
}

void Program::ProgramEndState::UpdateActiveState() {
	std::cout << "Update Active State " << GetStateName() << std::endl;
}

void Program::ProgramEndState::UpdateInactiveState() {
	std::cout << "Update Inactive State " << GetStateName() << std::endl;
}

void Program::ProgramEndState::ExitActiveState() {
	std::cout << "Exit Active State  " << GetStateName() << std::endl;
}

void Program::ProgramEndState::Finalize() {
	std::cout << "Finalize " << GetStateName() << std::endl;
}


