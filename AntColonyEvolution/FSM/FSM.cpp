#include "FSM.h"

FSM::FSM(std::string name, std::string origin) :
	Origin(name), Name(origin) { }

State::State(std::shared_ptr<FSM> _Owner, const std::string _Origin) :
	Owner(_Owner), Origin(_Origin) { }

std::unique_ptr<State> State::Create(std::shared_ptr<FSM> Owner, const std::string Origin) {
	return std::unique_ptr<State>(new State(Owner, Origin));
}

std::shared_ptr<FSM> FSM::Create(std::string name, std::string origin) {
	return std::shared_ptr<FSM>(new FSM(name, origin));
}

void FSM::PushImmediate(std::unique_ptr<State> state, bool hasInactiveUpdates) {
	if (StateStack.size() > 0) {
		StateStack.back().first->ExitActiveState();
	}
	StateStack.push_back(
		StateStackEntry(
			std::move(state), 
			hasInactiveUpdates));
	StateStack.back().first->Initialize();
	StateStack.back().first->EnterActiveState();
}

void FSM::PopImmediate() {
	if (StateStack.size() > 0) {
		StateStack.back().first->ExitActiveState();
		StateStack.back().first->Finalize();
		delete StateStack.back().first.release();
		StateStack.pop_back();
		if (StateStack.size() > 0) {
			StateStack.back().first->EnterActiveState();
		}
	}
}

void FSM::TransitionImmediate(std::unique_ptr<State> state, bool hasInactiveUpdates) {
	PopImmediate();
	PushImmediate(std::move(state), hasInactiveUpdates);
}

void FSM::PushDelayed(std::unique_ptr<State> state, bool hasInactiveUpdates) {
	DelayStack.push(
		DelayedStateStackEntry(
			Action::PUSH, 
			StateStackEntry(
				std::move(state),
				hasInactiveUpdates)));
}

void FSM::PopDelayed() {
	DelayStack.push(
		DelayedStateStackEntry(
			Action::POP,
			StateStackEntry(
				std::unique_ptr<State>(nullptr),
				false)));
}

void FSM::TransitionDelayed(std::unique_ptr<State> state, bool hasInactiveUpdates) {
	PopDelayed();
	PushDelayed(std::move(state), hasInactiveUpdates);
}

FSM::~FSM() {
	if (StateStack.size() != 0) {
		Terminate();
	}
}

void FSM::Terminate() {
	while (StateStack.size() > 0) {
		StateStack.back().first->Finalize();
		delete StateStack.front().first.release();
		StateStack.pop_back();
	}
	delete this;
}

void FSM::RunForever() {
	while (StateStack.size() > 0 || DelayStack.size() > 0) {
		ProcessDelayed();
		RunOnce();
	}
}

void FSM::RunUntil(bool(*Control)()) {
	while (StateStack.size() > 0 || DelayStack.size() > 0) {
		ProcessDelayed();
		RunOnce();

		if (Control()) break;
	}
}

void FSM::RunOnce() {
	if (StateStack.size() > 0) {
		if (StateStack.size() > 1) {
			auto last = StateStack.end() - 1;
			for (auto it = StateStack.begin(); it != last; it++) {
				if (it->second) {
					it->first->UpdateInactiveState();
				}
			}
		}

		StateStack.back().first->UpdateActiveState();
	}
}

void FSM::ProcessDelayed() {
	while (DelayStack.size() > 0) {
		switch (DelayStack.front().first) {
		case Action::POP:
			PopImmediate();
			break;
		case Action::PUSH:
			PushImmediate(
				std::unique_ptr<State>(DelayStack.front().second.first.release()),
				DelayStack.front().second.second);
			break;
		case Action::TRANSITION:
			TransitionImmediate(
				std::unique_ptr<State>(DelayStack.front().second.first.release()),
				DelayStack.front().second.second);
			break;
		}

		DelayStack.pop();
	}
}