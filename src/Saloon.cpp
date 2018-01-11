#include "Saloon.h"
#include "Agent.h"

Saloon::Saloon() {
	location = Vector2D(7 * CELL_SIZE, 20 * CELL_SIZE);
}

Saloon::~Saloon() {

}

void Saloon::Enter(Agent* agent) {
	cout << "Saloon" << endl;
	agent->path = agent->apuntero(agent->getPosition(), location);
	agent->changePath = true;
}

void Saloon::Update(Agent* agent) {
	
	if (agent->calcularDistancia(agent->getPosition(), location)) {
		if (agent->thirst > 0) agent->thirst--;
		agent->wealth--;
		if ((agent->thirst <= 0 || agent->wealth <= 0) && (agent->wealth + agent->pocket <= agent->maxWealth)) Exit(agent, agent->st_mine);
		if (agent->tired >= agent->maxTired) Exit(agent, agent->st_home);
	}

}

void Saloon::Exit(Agent* agent, State* nextState) {
	agent->changeState(nextState);
}