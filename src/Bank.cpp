#include "Bank.h"
#include "Agent.h"

Bank::Bank() {
	location = Vector2D(33 * CELL_SIZE - CELL_SIZE / 2, 20 * CELL_SIZE - CELL_SIZE / 2);
}

Bank::~Bank() {

}

void Bank::Enter(Agent* agent) {
	cout << "Bank" << endl;
	//agent->path = agent->apuntero(agent->getPosition(), location);
	agent->setTarget(location);
	agent->changePath = true;
}

void Bank::Update(Agent* agent) {

	if (agent->calcularDistancia(agent->getPosition(), location)) {
		if (agent->getPosition() != location) agent->setPosition(location);
		agent->pocket--;
		agent->wealth++;//Lo que se resta de pocket se suma a wealth

		if (agent->wealth >= agent->maxWealth) {
			Exit(agent, agent->st_saloon);
		} else if (agent->pocket <= 0) {
			Exit(agent, agent->st_mine);
		}
		if (agent->tired >= agent->maxTired) Exit(agent, agent->st_home);
	}

}

void Bank::Exit(Agent* agent, State* nextState) {
	agent->changeState(nextState);
}