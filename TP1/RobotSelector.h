/*
* Titre :	RobotSelector.h - Travail Pratique #1 LOG2810
* Date :	29 octobre 2019
* Auteurs : Étienne Bourgoin		1955553
			Quy Hao Alexandre Dam	1949308
*/

#pragma once

#include "PathSelector.h"
#include "Robot.h"

class RobotSelector {
public:
	RobotSelector();
	RobotSelector(vector<Robot*> robots, Robot* robotSelected);
	vector<Robot*> getRobots();
	Robot* getRobotSelected();
	Robot* selectRobot();

private:
	vector<Robot*> robots_;
	Robot* robotSelected_;
};
