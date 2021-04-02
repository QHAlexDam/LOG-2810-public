/*
* Titre :	Path.h - Travail Pratique #1 LOG2810
* Date :	29 octobre 2019
* Auteurs : Étienne Bourgoin		1955553
			Quy Hao Alexandre Dam	1949308
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Graph.h"


using namespace std;

class Path {
public:
	Path();
	Path(vector<Summit*> summits, double totalDistance, int totalQuantityA, int totalQuantityB, int totalQuantityC);
	vector<Summit*> getSummits();
	double getTotalDistance();
	int getTotalQuantityA();
	int getTotalQuantityB();
	int getTotalQuantityC();
	void setSummits(vector<Summit*> summits);
	void addSummit(Summit* summit);
	void setTotalDistance(double totalDistance);
	void addTotalDistance(double distance);
	void setTotalQuantityA(double totalQuantityA);
	void addTotalQuantityA(double quantityA);
	void setTotalQuantityB(double totalQuantityB);
	void addTotalQuantityB(double quantityB);
	void setTotalQuantityC(double totalQuantityC);
	void addTotalQuantityC(double quantityC);
	void printPath();

private:
	vector<Summit*> summits_;
	double totalDistance_;
	int totalQuantityA_;
	int totalQuantityB_;
	int totalQuantityC_;
};
