#include "Home.h"
#include "Agent.h"

Home::Home() {
	location = Vector2D(20 * CELL_SIZE - CELL_SIZE / 2, 20 * CELL_SIZE - CELL_SIZE / 2);
}

Home::~Home() {

}

void Home::Enter(Agent* agent) {
	cout << "Home" << endl;
	//agent->path = agent->apuntero(agent->getPosition(), location);
	agent->setTarget(location);
	agent->changePath = true;
}

void Home::Update(Agent* agent) {

	if (agent->calcularDistancia(agent->getPosition(), location)) {
		if (agent->getPosition() != location) agent->setPosition(location);
		agent->tired--;
		if (agent->pocket >= agent->maxPocket) Exit(agent, agent->st_bank);
		if (agent->thirst >= agent->maxThirst) Exit(agent, agent->st_saloon);
		if (agent->tired <= 0) Exit(agent, agent->st_mine);
	}

}

void Home::Exit(Agent* agent, State* nextState) {
	agent->changeState(nextState);
}