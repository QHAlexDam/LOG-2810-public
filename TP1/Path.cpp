/*
* Titre :	Path.cpp - Travail Pratique #1 LOG2810
* Date :	29 octobre 2019
* Auteurs : Étienne Bourgoin		1955553
			Quy Hao Alexandre Dam	1949308
*/

#include "Path.h"

Path::Path() {
	summits_ = {};
	totalDistance_ = 0;
	totalQuantityA_ = 0;
	totalQuantityB_ = 0;
	totalQuantityC_ = 0;
}

Path::Path(vector<Summit*> summits, double totalDistance, int totalQuantityA, int totalQuantityB, int totalQuantityC) {
	for (int i = 0; i < summits.size(); i++)
		summits_.push_back(summits[i]);
	totalDistance_ = totalDistance;
	totalQuantityA_ = totalQuantityA;
	totalQuantityB_ = totalQuantityB;
	totalQuantityC_ = totalQuantityC;
}

vector<Summit*> Path::getSummits() {
	return summits_;
}

double Path::getTotalDistance() {
	return totalDistance_;
}

int Path::getTotalQuantityA() {
	return totalQuantityA_;
}

int Path::getTotalQuantityB() {
	return totalQuantityB_;
}

int Path::getTotalQuantityC() {
	return totalQuantityC_;
}

void Path::setSummits(vector<Summit*> summits) {
	summits_.clear();
	for(int i = 0; i < summits.size(); i++)
		summits_.push_back(summits[i]);
}

void Path::addSummit(Summit* summit) {
	summits_.push_back(summit);
}

void Path::setTotalDistance(double totalDistance) {
	totalDistance_ = totalDistance;
}

void Path::addTotalDistance(double distance) {
	totalDistance_ += distance;
}

void Path::setTotalQuantityA(double totalQuantityA) {
	totalQuantityA_ = totalQuantityA;
}

void Path::addTotalQuantityA(double quantityA) {
	totalQuantityA_ = quantityA;
}

void Path::setTotalQuantityB(double totalQuantityB) {
	totalQuantityB_ = totalQuantityB;
}

void Path::addTotalQuantityB(double quantityB) {
	totalQuantityB_ = quantityB;
}

void Path::setTotalQuantityC(double totalQuantityC) {
	totalQuantityC_ = totalQuantityC;
}

void Path::addTotalQuantityC(double quantityC) {
	totalQuantityC_ = quantityC;
}

void Path::printPath() {
	cout << "Voici le contenu de chaque noeud du chemin: " << endl;
	cout << "Noeud        Objets A        Objets B        Objets C" << endl;
	for (int i = 0; i < summits_.size(); i++) {
		if (summits_[i]->getID() < 10)
			cout << summits_[i]->getID() << "               ";
		else
			cout << summits_[i]->getID() << "              ";
		cout << summits_[i]->getQuantityA() << "               ";
		cout << summits_[i]->getQuantityB() << "               ";
		cout << summits_[i]->getQuantityC() << endl << endl;
	}
	cout << "Quantite totale" << " ";
	cout << getTotalQuantityA() << "               ";
	cout << getTotalQuantityA() << "               ";
	cout << getTotalQuantityA() << endl << endl;
}