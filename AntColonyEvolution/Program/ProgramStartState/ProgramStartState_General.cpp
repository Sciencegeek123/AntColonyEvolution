#include "Program\Program.h"
#include <iostream>

std::unique_ptr<Program::ProgramStartState> Program::ProgramStartState::Create(std::shared_ptr<FSM> owner, const std::string origin, std::shared_ptr<Program> program) {
	return std::unique_ptr<Program::ProgramStartState>(new Program::ProgramStartState(owner, origin, program));
}

Program::ProgramStartState::ProgramStartState(std::shared_ptr<FSM> Owner, const std::string Origin, std::shared_ptr<Program> Program) :
	State(Owner, Origin) { program = Program; }

void Program::ProgramStartState::Initialize() {
	std::cout << "Initialized " << GetStateName() << std::endl;
}

void Program::ProgramStartState::EnterActiveState() {
	std::cout << "Enter Active State " << GetStateName() << std::endl;
}

void Program::ProgramStartState::UpdateActiveState() {
	std::cout << "Update Active State " << GetStateName() << std::endl;
}

void Program::ProgramStartState::UpdateInactiveState() {
	std::cout << "Update Inactive State " << GetStateName() << std::endl;
}

void Program::ProgramStartState::ExitActiveState() {
	std::cout << "Exit Active State  " << GetStateName() << std::endl;
}

void Program::ProgramStartState::Finalize() {
	std::cout << "Finalize " << GetStateName() << std::endl;
}


