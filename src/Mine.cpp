#include "Mine.h"
#include "Agent.h"

Mine::Mine() {

}

Mine::~Mine() {

}

void Mine::Enter(Agent* agent) {

}

void Mine::Update(Agent* agent) {

	agent->pocket++;
	agent->thirst++;

	if (agent->pocket >= agent->maxPocket) Exit(agent, agent->st_bank);
	if (agent->thirst >= agent->maxThirst) Exit(agent, agent->st_saloon);

}

void Mine::Exit(Agent* agent, State nextState) {
	agent->changeState(&nextState);
}