#include "Mine.h"
#include "Agent.h"

Mine::Mine() {
	location = Vector2D(20 * CELL_SIZE, 3 * CELL_SIZE);
}

Mine::~Mine() {

}

void Mine::Enter(Agent* agent) {
	cout << "MINA" << endl;
	agent->path = agent->apuntero(agent->getPosition(), location);
	agent->changePath = true;
}

void Mine::Update(Agent* agent) {

	if (agent->calcularDistancia(agent->getPosition(), location)) {

		agent->pocket++;
		agent->thirst++;
		agent->tired++;

		if (agent->pocket >= agent->maxPocket) Exit(agent, agent->st_bank);
		if (agent->thirst >= agent->maxThirst) Exit(agent, agent->st_saloon);
		if (agent->tired >= agent->maxTired) Exit(agent, agent->st_home);

	}

}

void Mine::Exit(Agent* agent, State* nextState) {
	agent->changeState(nextState);
}