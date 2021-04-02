/*
* Titre :	Robot.cpp - Travail Pratique #1 LOG2810
* Date :	29 octobre 2019
* Auteurs : Étienne Bourgoin		1955553
			Quy Hao Alexandre Dam	1949308
*/

#include "Robot.h"

Robot::Robot() {
	constantAdded_ = 1.0;
	constantMultiplied_ = 1.0;
	mass_ = 0.0;
	maxMass_ = 10.0;
	k_ = 1.0;
	distance_ = 0.0;
	time_ = 0.0;
}

Robot::Robot(double constantAdded, double constantMultiplied, double mass, double maxMass, double distance) {
	constantAdded_ = constantAdded;
	constantMultiplied_ = constantMultiplied;
	mass_ = mass;
	maxMass_ = maxMass;
	k_ = getK();
	distance_ = distance;
	time_ = getTime();
}

Robot::~Robot() {}

double Robot::getConstantAdded() {
	return constantAdded_;
}

double Robot::getConstantMultiplied() {
	return constantMultiplied_;
}

double Robot::getMass() {
	return mass_;
}

bool Robot::verifyMass() {
	return mass_ <= maxMass_;
}

double Robot::getK() {
 	return getConstantAdded() + getConstantMultiplied()*getMass();
}

double Robot::getDistance() {
	return distance_;
}

double Robot::getTime() {
	return getK()*getDistance();
}
