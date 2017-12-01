#pragma once

class State {
public:
	State();
	~State();

	virtual void Enter();
	virtual void Update();
	virtual void Exit();

private:

};