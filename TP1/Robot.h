/*
* Titre :	Robot.h - Travail Pratique #1 LOG2810
* Date :	29 octobre 2019
* Auteurs : Étienne Bourgoin		1955553
			Quy Hao Alexandre Dam	1949308
*/

#pragma once

using namespace std;

class Robot {
public:
	Robot();
	Robot(double constantAdded, double constantMultiplied, double mass, double maxMass, double distance);
	~Robot();
	double getConstantAdded();
	double getConstantMultiplied();
	double getMass();
	bool verifyMass();
	double getK();
	double getDistance();
	double getTime();
	
private:
	double constantAdded_;
	double constantMultiplied_;
	double mass_;
	double maxMass_;
	double k_;
	double distance_;
	double time_;
};