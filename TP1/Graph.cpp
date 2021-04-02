#include "Graph.h"

//Default constructor
Graph::Graph(){}

//Destructor
Graph::~Graph(){
	arcTab_.erase(arcTab_.begin(), arcTab_.end());
	summitTab_.erase(summitTab_.begin(), summitTab_.end());
	arcTab_.clear();
	summitTab_.clear();
}

//constructor by param
Graph::Graph(const string& fileName) {
	createGraph(fileName);
}


//Constructor by copy
Graph::Graph(const Graph& graph){
	for (int i = 0; i < summitTab_.size(); i++) {
		this->summitTab_.push_back(graph.summitTab_[i]);
	}
	for (int i = 0; i < arcTab_.size(); i++) {
		this->arcTab_.push_back(graph.arcTab_[i]);
	}
}

//Reads file and creates graph
void Graph::createGraph(const string& fileName) {
	bool part1 = true, part2 = false;
	ifstream file(fileName);
	string line;
	if (file.is_open()) {
		while (getline(file, line)) {
			if (!line.size()) {// ligne vide qui separe les 2 sets de donnees
				part1 = false;
			}
			if (part1 && !part2) { //partie 1 contenant les noeuds
				vector<int> param;
				for (int i = 0; i < line.length(); i++) {
					string tmpStr;
					int j = i;
					while (line[j] != ',' && j < line.length()) {
						tmpStr += line[j];
						j++;
					}
					i = j;
					int tmp = stoi(tmpStr);
					param.push_back(tmp);
				}
				if (param.size() == 4) {
					Summit* summit = new Summit(param[0], param[1], param[2], param[3]);
					summitTab_.push_back(summit);
				}
				else {
					cout << "erreur vecteur param part1" << endl;
				}
			}
			if (!part1 && part2) { // partie 2 contenant les arcs
				vector<int> param;
				for (int i = 0; i < line.length(); i++) {
					string tmpString = "";
					int j = i;
					while (line[j] != ',' && j < line.length()) {
						tmpString += line[j];
						j++;
					}
					i = j;
					int tmp = stoi(tmpString);
					param.push_back(tmp);
				}
				if (param.size() == 3) {
					Arc* arc = new Arc(summitTab_[param[0]], summitTab_[param[1]], param[2]);
					arcTab_.push_back(arc);
				}
				else
					cout << "erreur vecteur param part2" << endl;
			}
			if (!line.size()) {// ligne vide qui separe les 2 sets de donnees
				part2 = true;
			}
		}
	}
	else {
		cout << "erreur le fichier n'a pas ete ouvert" << endl;
	}
}

vector<Summit*> Graph::getSummits() {
	return summitTab_;
}

vector<Arc*> Graph::getArc() {
	return arcTab_;
}

void Graph::printGraph() {
	cout << "Voici le contenu de chaque noeud, le format d'affichage est le suivant: " << endl;
	cout << "(Noeud0, nbObjetA, nbObjetB, nbObjetC, ((noeud_voisin, distance), ...))" << endl << endl;
	for (int i = 0; i < summitTab_.size(); i++) {
		cout << "(" << summitTab_[i]->getID()
			<< ", " << summitTab_[i]->getQuantityA()
			<< ", " << summitTab_[i]->getQuantityB()
			<< ", " << summitTab_[i]->getQuantityC() << ", ";
		for (int j = 0; j < arcTab_.size(); j++) {
			if (arcTab_[j]->getStartingSummit()->getID() == summitTab_[i]->getID()) {
				cout << "(" << arcTab_[j]->getFinalSummit()->getID() << ", "
					<< arcTab_[j]->getDistance() << ")";
			}
			if (arcTab_[j]->getFinalSummit()->getID() == summitTab_[i]->getID()) {
				cout << "(" << arcTab_[j]->getStartingSummit()->getID() << ", "
					<< arcTab_[j]->getDistance() << ")";
			}
		}
		cout << ")" << endl;
	}
	cout << endl;
}