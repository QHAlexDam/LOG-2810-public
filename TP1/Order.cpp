/*
* Titre :	Order.cpp - Travail Pratique #1 LOG2810
* Date :	29 octobre 2019
* Auteurs : Étienne Bourgoin		1955553
			Quy Hao Alexandre Dam	1949308
*/

#include "Order.h"

Order::Order() {
	ID_ = 0;
	quantityA_ = 0;
	quantityB_ = 0;
	quantityC_ = 0;
}

Order::Order(int ID, int quantityA, int quantityB, int quantityC) {
	ID_ = ID;
	quantityA_ = quantityA;
	quantityB_ = quantityB;
	quantityC_ = quantityC;
}

int Order::getQuantityA() {
	return  quantityA_;
}

int Order::getQuantityB() {
	return  quantityB_;
}

int Order::getQuantityC() {
	return  quantityC_;
}

int Order::getID() {
	return  ID_;
}

void Order::setQuantityA(int quantityA) {
	quantityA_ = quantityA;
}

void Order::setQuantityB(int quantityB) {
	quantityB_ = quantityB;
}

void Order::setQuantityC(int quantityC) {
	quantityC_ = quantityC;
}

void Order::setID(int ID) {
	ID_ = ID;
}

void Order::printOrder() const
{
	cout << "Voici votre commande:" << endl
		<< "ID: " << ID_ << endl
		<< "Objet(s) de type A: " << quantityA_ << endl
		<< "Objet(s) de type B: " << quantityB_ << endl
		<< "Objet(s) de type C: " << quantityC_ << endl;
}