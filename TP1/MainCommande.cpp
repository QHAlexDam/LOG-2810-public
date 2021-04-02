#include "Command.h"
#include <iostream>
#include <fstream>

using namespace std;

void afficherMenu()
{
	cout << "Entrer 1 ou 2" << endl;
}

void afficherCommande(Command commande)
{
	commande.information();
}

Command prendreCommande()
{
	int nbObjetsA;
	int nbObjetsB;
	int nbObjetsC;
	cout << "Veuillez commander un certain nombre d'objets A: " << endl;
	cin >> nbObjetsA;
	cout << "Veuillez commander un certain nombre d'objets B: " << endl;
	cin >> nbObjetsB;
	cout << "Veuillez commander un certain nombre d'objets C: " << endl;
	cin >> nbObjetsC;
	Command commande(nbObjetsA, nbObjetsB, nbObjetsC);
	return commande;
}

int main()
{
	Command commande;
	bool exit = false;
	while (!exit) {
		afficherMenu();
		int reponse;
		cin >> reponse;
		switch (reponse) {
		case 1:
			cout << "Prise de commande: " << endl;
			commande = prendreCommande();
			break;
		case 2:
			cout << "Voici la commande: " << endl;
			afficherCommande(commande);
			break;
		}
	}
	return 0;
}
