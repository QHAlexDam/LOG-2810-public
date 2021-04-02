/*
* Titre :	Arc.cpp - Travail Pratique #1 LOG2810
* Date :	29 octobre 2019
* Auteurs : Étienne Bourgoin		1955553
			Quy Hao Alexandre Dam	1949308
*/

#include "Arc.h"

//default constructor
Arc::Arc() {
	startingSummit_ = 0;
	finalSummit_ = 0;
	distance_ = 0;
}

//constructor by param
Arc::Arc(Summit* startingSummit, Summit* finalSummit, int distance) {
	startingSummit_ = startingSummit;
	finalSummit_ = finalSummit;
	distance_ = distance;
}

//destructor
Arc::~Arc() {}

//Getters
Summit* Arc::getStartingSummit() {
	return startingSummit_;
}

Summit* Arc::getFinalSummit() {
	return finalSummit_;
}

int Arc::getDistance() {
	return distance_;
}