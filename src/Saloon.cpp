#include "Saloon.h"
#include "Agent.h"

Saloon::Saloon() {

}

Saloon::~Saloon() {

}

void Saloon::Enter(Agent* agent) {

}

void Saloon::Update(Agent* agent) {

	agent->thirst--;
	if (agent->thirst <= 0) Exit(agent, agent->st_mine);

}

void Saloon::Exit(Agent* agent, State nextState) {
	agent->changeState(&nextState);
}