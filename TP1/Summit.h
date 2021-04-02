/*
* Titre :	Summit.h - Travail Pratique #1 LOG2810
* Date :	29 octobre 2019
* Auteurs : Étienne Bourgoin		1955553
			Quy Hao Alexandre Dam	1949308
*/

#pragma once

using namespace std;

class Summit {
public:
	Summit();
	Summit(int id, int a, int b, int c);
	~Summit();

	int getQuantityA();
	int getQuantityB();
	int getQuantityC();
	int getID();

	void setQuantityA(int a);
	void setQuantityB(int b);
	void setQuantityC(int c);
	void setID(int id);

private:
	int ID_;

	int quantityA_;
	int quantityB_;
	int quantityC_;
};