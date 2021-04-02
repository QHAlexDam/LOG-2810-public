/*
* Titre :	PathSelector.h - Travail Pratique #1 LOG2810
* Date :	29 octobre 2019
* Auteurs : Étienne Bourgoin		1955553
			Quy Hao Alexandre Dam	1949308
*/

#pragma once

#include "Path.h"
#include "Order.h"

class PathSelector {
public:
	PathSelector();
	PathSelector(vector<Path*> unorderedPaths, vector<Path*> orderedPaths, Path* selectedPath);
	vector<Path*> getUnorderedPaths();
	vector<Path*> getOrderedPaths();
	Path* getSelectedPath();
	void findPaths(int IDinitialSummit, int numberOfSummits, const string& fileName);
	void orderPaths();
	void selectPath();
	void printSelectedPath();
	void printUnorderedPaths(const string& fileName);

private:
	vector<Path*> unorderedPaths_;
	vector<Path*> orderedPaths_;
	Path* selectedPath_;
};
