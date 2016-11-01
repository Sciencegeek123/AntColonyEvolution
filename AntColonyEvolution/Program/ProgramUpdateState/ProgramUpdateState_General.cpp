#include "Program\Program.h"
#include <iostream>

std::unique_ptr<Program::ProgramUpdateState> Program::ProgramUpdateState::Create(std::shared_ptr<FSM> owner, const std::string origin, std::shared_ptr<Program> program) {
	return std::unique_ptr<Program::ProgramUpdateState>(new Program::ProgramUpdateState(owner, origin, program));
}

Program::ProgramUpdateState::ProgramUpdateState(std::shared_ptr<FSM> Owner, const std::string Origin, std::shared_ptr<Program> Program) :
	State(Owner, Origin) {
	program = Program;
}

void Program::ProgramUpdateState::Initialize() {
	std::cout << "Initialized " << GetStateName() << std::endl;
}

void Program::ProgramUpdateState::EnterActiveState() {
	std::cout << "Enter Active State " << GetStateName() << std::endl;
}

void Program::ProgramUpdateState::UpdateActiveState() {
	std::cout << "Update Active State " << GetStateName() << std::endl;
}

void Program::ProgramUpdateState::UpdateInactiveState() {
	std::cout << "Update Inactive State " << GetStateName() << std::endl;
}

void Program::ProgramUpdateState::ExitActiveState() {
	std::cout << "Exit Active State  " << GetStateName() << std::endl;
}

void Program::ProgramUpdateState::Finalize() {
	std::cout << "Finalize " << GetStateName() << std::endl;
}