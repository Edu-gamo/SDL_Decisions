#include "Bank.h"
#include "Agent.h"

Bank::Bank() {

}

Bank::~Bank() {

}

void Bank::Enter(Agent* agent) {

}

void Bank::Update(Agent* agent) {

	agent->pocket--;
	agent->wealth++;//Lo que se resta de pocket se suma a wealth

	if (agent->pocket <= 0) {
		if (agent->wealth >= agent->maxWealth) {
			Exit(agent, agent->st_home);
		} else {
			Exit(agent, agent->st_mine);
		}
	}

}

void Bank::Exit(Agent* agent, State nextState) {
	agent->changeState(&nextState);
}