#pragma once

class Agent;

class State {
public:
	State();
	~State();

	virtual void Enter(Agent* agent);
	virtual void Update(Agent* agent);
	virtual void Exit(Agent* agent, State nextState);

private:

};