/*
* Titre :	RobotSelector.cpp - Travail Pratique #1 LOG2810
* Date :	29 octobre 2019
* Auteurs : Étienne Bourgoin		1955553
			Quy Hao Alexandre Dam	1949308
*/

#include "RobotSelector.h"

RobotSelector::RobotSelector() {
	robots_ = {};
	robotSelected_ = nullptr;
}

RobotSelector::RobotSelector(vector<Robot*> robots, Robot* robotSelected) {
	robots_ = robots;
	robotSelected_ = robotSelected;
}

vector<Robot*> RobotSelector::getRobots() {
	return robots_;
}

Robot* RobotSelector::getRobotSelected() {
	return robotSelected_;
}

Robot* RobotSelector::selectRobot() {
	return robotSelected_;
}