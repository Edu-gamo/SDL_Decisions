#include "Home.h"
#include "Agent.h"

Home::Home() {
	location = Vector2D(20 * CELL_SIZE, 20 * CELL_SIZE);
}

Home::~Home() {

}

void Home::Enter(Agent* agent) {
	cout << "Home" << endl;
	agent->path = agent->apuntero(agent->getPosition(), location);
	agent->changePath = true;
}

void Home::Update(Agent* agent) {

	if (agent->calcularDistancia(agent->getPosition(), location)) {
		agent->tired--;
		if (agent->pocket >= agent->maxPocket) Exit(agent, agent->st_bank);
		if (agent->thirst >= agent->maxThirst) Exit(agent, agent->st_saloon);
		if (agent->tired <= 0) Exit(agent, agent->st_mine);
	}

}

void Home::Exit(Agent* agent, State* nextState) {
	agent->changeState(nextState);
}