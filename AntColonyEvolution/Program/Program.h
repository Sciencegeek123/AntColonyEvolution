#pragma once
#include "ACS.h"

#include "FSM/FSM.h"

class Program {
private:
	class ProgramStartState : public State {
	private:
		std::shared_ptr<Program> program;
		ProgramStartState(std::shared_ptr<FSM> Owner, const std::string Origin, std::shared_ptr<Program> Program);
		
	public:
		static std::unique_ptr<ProgramStartState> Create(std::shared_ptr<FSM> Owner, const std::string Origin, std::shared_ptr<Program> Program);
		void Initialize();
		void EnterActiveState();
		void UpdateActiveState();
		void UpdateInactiveState();
		void ExitActiveState();
		void Finalize();
		inline const std::string GetStateName() { return std::string("Program Start State"); }
	};

	class ProgramUpdateState : public State {
	private:
		std::shared_ptr<Program> program;
		ProgramUpdateState(std::shared_ptr<FSM> Owner, const std::string Origin, std::shared_ptr<Program> Program);

	public:
		static std::unique_ptr<ProgramUpdateState> Create(std::shared_ptr<FSM> Owner, const std::string Origin, std::shared_ptr<Program> Program);
		void Initialize();
		void EnterActiveState();
		void UpdateActiveState();
		void UpdateInactiveState();
		void ExitActiveState();
		void Finalize();
		inline const std::string GetStateName() { return std::string("Program Start State"); }
	};

	class ProgramEndState : public State {
	private:
		std::shared_ptr<Program> program;
		ProgramEndState(std::shared_ptr<FSM> Owner, const std::string Origin, std::shared_ptr<Program> Program);

	public:
		static std::unique_ptr<ProgramEndState> Create(std::shared_ptr<FSM> Owner, const std::string Origin, std::shared_ptr<Program> Program);
		void Initialize();
		void EnterActiveState();
		void UpdateActiveState();
		void UpdateInactiveState();
		void ExitActiveState();
		void Finalize();
		inline const std::string GetStateName() { return std::string("Program Start State"); }
	};


public:
	static void StartProgram(std::shared_ptr<FSM> MainFSM);
};