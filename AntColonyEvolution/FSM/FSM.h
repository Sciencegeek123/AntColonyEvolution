#pragma once

#include <string>
#include <memory>
#include <deque>
#include <queue>
#include <utility>

class FSM;

class State {
private:
	friend FSM;

protected:
	const std::string Origin;
	const std::shared_ptr<FSM> Owner;
	State(std::shared_ptr<FSM> Owner, const std::string Origin);
	std::unique_ptr<State> Create(std::shared_ptr<FSM> Owner, const std::string Origin);

public:
	virtual void Initialize() { };
	virtual void EnterActiveState() { };
	virtual void UpdateActiveState() { };
	virtual void UpdateInactiveState() { };
	virtual void ExitActiveState() { };
	virtual void Finalize() { };
	virtual const std::string GetStateName() { return std::string("Base State"); }
};


/*
	Delayed must be included so that I can push from within a state without having an absurd memory stack.
*/

class FSM {
private:
	//Actions for Delayed Processing
	enum Action {
		PUSH,
		POP,
		TRANSITION
	};

	typedef std::pair<std::unique_ptr<State>, bool> StateStackEntry;
	typedef std::pair<FSM::Action, StateStackEntry> DelayedStateStackEntry;

	//Properties
	std::deque<StateStackEntry> StateStack;
	std::queue<DelayedStateStackEntry> DelayStack;
	const std::string Origin, Name;
	FSM(std::string Name, std::string Origin);

	//Processed Delayed 
	void ProcessDelayed();

public:
	static std::shared_ptr<FSM> Create(std::string Name, std::string Origin);
	void PushImmediate(std::unique_ptr<State> State, bool HasInactiveUpdates = false);
	void PopImmediate();
	void TransitionImmediate(std::unique_ptr<State> State, bool hasInactiveUpdates);
	void PushDelayed(std::unique_ptr<State> State, bool HasInactiveUpdates = false);
	void PopDelayed();
	void TransitionDelayed(std::unique_ptr<State> State, bool HasInactiveUpdates = false);
	void Terminate();
	void RunForever();
	void RunUntil(bool (*Control)());
	void RunOnce();
	~FSM();
};