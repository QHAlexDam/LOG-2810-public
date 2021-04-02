/*
* Titre :	PathSelector.cpp - Travail Pratique #1 LOG2810
* Date :	29 octobre 2019
* Auteurs : Étienne Bourgoin		1955553
			Quy Hao Alexandre Dam	1949308
*/

#include "PathSelector.h"
#include <deque>

const string& fileName = "entrepot.txt";


PathSelector::PathSelector() {
	unorderedPaths_ = {};
	orderedPaths_ = {};
	selectedPath_ = nullptr;
}
PathSelector::PathSelector(vector<Path*> unorderedPaths, vector<Path*> orderedPaths, Path* selectedPath) {
	unorderedPaths_ = unorderedPaths;
	orderedPaths_ = orderedPaths;
	selectedPath_ = selectedPath;
}

vector<Path*> PathSelector::getUnorderedPaths() {
	return unorderedPaths_;
}

vector<Path*> PathSelector::getOrderedPaths() {
	return orderedPaths_;
}

Path* PathSelector::getSelectedPath() {
	return selectedPath_;
}

void PathSelector::findPaths(int IDinitialSummit, int numberOfSummits, const string& fileName) {
	vector<Summit*> summitsPassed = {};
	deque<Summit*> nextInitialSummits = {};
	Graph* graph = new Graph(fileName);
	Path* path = new Path();

	path->addSummit(graph->getSummits()[IDinitialSummit]);
	unorderedPaths_.push_back(path);
	bool isInNextInitialSummits = false;
	int totalDistanceBeforeSummitAdded = 0;
	int totalQuantityABeforeSummitAdded = 0;
	int totalQuantityBBeforeSummitAdded = 0;
	int totalQuantityCBeforeSummitAdded = 0;
	while (summitsPassed.size() <= numberOfSummits) {
		for (int i = 0; i < graph->getArc().size(); i++) {
			if(graph->getArc()[i]->getStartingSummit()->getID() == IDinitialSummit) {
				for (int j = 0; j < nextInitialSummits.size(); j++) {
					if (nextInitialSummits[j]->getID() == graph->getArc()[i]->getFinalSummit()->getID())
						isInNextInitialSummits = true;
				}
				if(!isInNextInitialSummits)
					nextInitialSummits.push_front(graph->getArc()[i]->getFinalSummit());
			if (graph->getArc()[i]->getFinalSummit()->getID() == IDinitialSummit) {
				for (int k = 0; k < unorderedPaths_.size(); k++) {
					if (unorderedPaths_[k]->getSummits().back()->getID() == graph->getArc()[i]->getStartingSummit()->getID()) {
						path->setTotalDistance(unorderedPaths_[k]->getTotalDistance());
						path->addTotalDistance(graph->getArc()[i]->getDistance());
						path->setTotalQuantityA(unorderedPaths_[k]->getTotalQuantityA());
						path->addTotalQuantityA(graph->getArc()[i]->getFinalSummit()->getQuantityA());
						path->setTotalQuantityB(unorderedPaths_[k]->getTotalQuantityB());
						path->addTotalQuantityB(graph->getArc()[i]->getFinalSummit()->getQuantityB());
						path->setTotalQuantityC(unorderedPaths_[k]->getTotalQuantityC());
						path->addTotalQuantityC(graph->getArc()[i]->getFinalSummit()->getQuantityC());
						path->setSummits(unorderedPaths_[k]->getSummits());
						path->addSummit(graph->getArc()[i]->getFinalSummit());
						unorderedPaths_.push_back(path);
					}
				}
			}
			}
			isInNextInitialSummits = false;
		}
		summitsPassed.push_back(graph->getSummits()[IDinitialSummit]);
		IDinitialSummit = nextInitialSummits.back()->getID();
		nextInitialSummits.pop_back();
	}
}

void PathSelector::orderPaths() {
	vector<Path*> tempVector = {};
	for (int i = 0; i < unorderedPaths_.size(); i++) {
		tempVector.push_back(unorderedPaths_[i]);
	}
	//orderedPaths_ = sort(tempVector.begin(), tempVector.end(), function{});
	//tempVector.clear();
	//tempVector.delete();

}

void PathSelector::selectPath() {

}

void PathSelector::printSelectedPath() {

}

void PathSelector::printUnorderedPaths(const string& fileName) {
	findPaths(0, 21, fileName);
	for (int i = 0; i < unorderedPaths_.size(); i++) {
		string tmp = "";
		for (int j = 0; j < unorderedPaths_[i]->getSummits().size(); j++) {
			tmp += to_string(unorderedPaths_[i]->getSummits()[j]->getID());
			tmp += " ";
		}
		cout << tmp << endl;
	}
}