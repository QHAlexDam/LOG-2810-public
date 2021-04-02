/*
* Titre :	Graph.h - Travail Pratique #1 LOG2810
* Date :	29 octobre 2019
* Auteurs : Étienne Bourgoin		1955553
			Quy Hao Alexandre Dam	1949308
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

#include "Arc.h"
#include "Summit.h"
#include "Robot.h"

using namespace std;

class Graph {
public:
	Graph();
	~Graph();
	Graph(const string& fileName);
	Graph(const Graph& graph);
	void createGraph(const string& fileName);
	vector<Summit*> getSummits();
	vector<Arc*> getArc();
	void printGraph();

private:
	vector<Summit*> summitTab_;
	vector<Arc*> arcTab_;
};

