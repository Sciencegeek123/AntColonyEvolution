#include "Program.h"

void Program::StartProgram(std::shared_ptr<FSM> MainFSM) {
	std::shared_ptr<Program> programPointer = std::shared_ptr<Program>(new Program());
	MainFSM->PushImmediate(ProgramStartState::Create(MainFSM, "Start Program", programPointer), true);
}