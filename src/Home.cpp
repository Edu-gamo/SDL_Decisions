#include "Home.h"
#include "Agent.h"

Home::Home() {

}

Home::~Home() {

}

void Home::Enter(Agent* agent) {

	sleepTime = 10500;

}

void Home::Update(Agent* agent) {

	sleepTime--;
	if(sleepTime <= 0) Exit(agent, agent->st_mine);

}

void Home::Exit(Agent* agent, State nextState) {
	agent->changeState(&nextState);
}