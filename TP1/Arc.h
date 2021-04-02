/*
* Titre :	Arc.h - Travail Pratique #1 LOG2810
* Date :	29 octobre 2019
* Auteurs : Étienne Bourgoin		1955553
			Quy Hao Alexandre Dam	1949308
*/

#pragma once
#include "Summit.h"

using namespace std;

class Arc {
public:
	Arc();
	Arc(Summit* startingSummit, Summit* finalSummit, int distance);
	~Arc();
	Summit* getStartingSummit();
	Summit* getFinalSummit();
	int getDistance();

private:
	Summit* startingSummit_;
	Summit* finalSummit_;
	int distance_;
	
};

