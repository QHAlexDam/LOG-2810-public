/*
* Titre :	Main.cpp - Travail Pratique #1 LOG2810
* Date :	29 octobre 2019
* Auteurs : Étienne Bourgoin		1955553
			Quy Hao Alexandre Dam	1949308
*/

#pragma once

#include "Graph.h"
#include "Summit.h"
#include "Arc.h"
#include "Robot.h"
#include "Order.h"
#include "Path.h"
#include "PathSelector.h"
#include "RobotSelector.h"

using namespace std;

void afficherMenu()
{
	cout << "===MENU===" << endl << endl;

	cout << "Entrez le chiffre relie a l'option voulue: " << endl << endl;

	cout << "1. Creer le graphe" << endl;
	cout << "2. Afficher le graphe" << endl;
	cout << "3. Prendre une commande" << endl;
	cout << "4. Afficher la commande" << endl;
	cout << "5. Trouver le plus court chemin" << endl << endl;
	cout << "Entrez '0' pour quitter en tout temps" << endl;
}


int main()
{
	const string FILE_NAME = "entrepot.txt";
	bool exit = false;
	Graph graph;
	Order order;
	PathSelector pathselector;
	
	while (!exit) {
		afficherMenu();
		int reponse;
		cin >> reponse;

		switch (reponse) {
		case 0:{
			cout << "merci d'avoir utilise l'application" << endl;
			exit = true;
		}
			break;
			
		case 1: {
			cout << "Le graphe se cree..." << endl;
			graph = Graph(FILE_NAME);
			cout << "le graphe est pret" << endl;
		}
			break;

		case 2: {
			graph.printGraph();
		}
			break;

		case 3: {
			cout << "ID de commande desire ";
			int ID;
			cin >> ID;
			order.setID(ID);
			cout << "Nombre d'objets de type A a commander: ";
			int quantityA;
			cin >> quantityA;
			order.setQuantityA(quantityA);
			cout << "Nombre d'objets de type B a commander: ";
			int quantityB;
			cin >> quantityB;
			order.setQuantityB(quantityB);
			cout << "Nombre d'objets de type C a commander: ";
			int quantityC;
			cin >> quantityC;
			order.setQuantityC(quantityC);

		}
			break;

		case 4: {
			order.printOrder();
		}
			break;

		case 5: {
			cout << "Voici le plus court chemin: " << endl;
			pathselector.printUnorderedPaths(FILE_NAME);
		}
			break;
		}
	}

	return 0;
}

