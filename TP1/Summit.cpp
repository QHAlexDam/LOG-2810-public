#pragma once
#include "Summit.h"

//default constructor
Summit::Summit() {
	ID_ = -1;
	quantityA_ = 0;
	quantityB_ = 0;
	quantityC_ = 0;
}

//Constructor by param
Summit::Summit(int id, int a, int b, int c) {
	ID_ = id;
	quantityA_ = a;
	quantityB_ = b;
	quantityC_ = c;
}

//Destructor
Summit::~Summit(){}

//Getters
int Summit::getQuantityA() {
	return quantityA_;
}

int Summit::getQuantityB() {
	return quantityB_;
}

int Summit::getQuantityC() {
	return quantityC_;
}

int Summit::getID() {
	return ID_;
}

//Setters

void Summit::setQuantityA(int a) {
	quantityA_ = a;
}

void Summit::setQuantityB(int b) {
	quantityB_ = b;
}
void Summit::setQuantityC(int c) {
	quantityC_ = c;

}
void Summit::setID(int id) {
	ID_ = id;
}
