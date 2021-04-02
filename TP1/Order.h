/*
* Titre :	Order.h - Travail Pratique #1 LOG2810
* Date :	29 octobre 2019
* Auteurs : Étienne Bourgoin		1955553
			Quy Hao Alexandre Dam	1949308
*/

#pragma once
#include <iostream>

using namespace std;

class Order {
public:

	Order();
	Order(int ID, int quantityA, int quantityB, int quantityC);
	int getQuantityA();
	int getQuantityB();
	int getQuantityC();
	int getID();

	void setQuantityA(int quantityA);
	void setQuantityB(int quantityB);
	void setQuantityC(int quantityC);
	void setID(int ID);
	
	void printOrder() const;

private:
	int ID_;
	int quantityA_;
	int quantityB_;
	int quantityC_;
};
