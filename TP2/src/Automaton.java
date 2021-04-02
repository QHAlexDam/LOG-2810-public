import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/*Classe Automaton
 * Contient l'algorithme de recherche
 * */

public class Automaton {
	
	//Set qui va contenir les resultats de recherche
	private Set<Item> resultsByName_;
	private Set<Item> resultsById_;
	private Set<Item> resultsByType_;
	private Set<Item> results_;
	
	//Inventaire et panier qui seront modifies s'il y a des ajouts au panier
	private Inventory inventory_;
	private Cart cart_;
	
	// indique si l'usager rafine la recherche
	private boolean refine = false; 

	public Automaton(Inventory inv, Cart cart){
		resultsByName_ = new HashSet<Item>();
		resultsById_ = new HashSet<Item>();
		resultsByType_ = new HashSet<Item>();
		results_ = new HashSet<Item>();
		inventory_ = inv;
		cart_ = cart;
	}
	
	//Methode de recherche par le nom de l'Item, ajoute tous les items ayant le terme cherche dans les resultats
	public void searchByName(String name) {
		Set<Item> temp = new HashSet<Item>();
		
		if (refine && !results_.isEmpty()) {
			temp.addAll(results_);
		}	
		else if(refine && results_.isEmpty()) {
			System.out.println("Erreur: Vous essayez de rafiner une recherche ayant aucun resultat, une nouvelle recherche est demaree.");
			temp.addAll(inventory_.getItems());
		}
		else {
			temp.addAll(inventory_.getItems());
		}

		for (Item item : temp) {
			boolean isFound = false;
			for (int i = 0; i < item.getName().length(); i++) { // parcours nom de l'obj en inventaire
				if (item.getName().charAt(i) == name.charAt(0)) {
					isFound = true;
					if (item.getName().length()- i < name.length()) { //si la portion restante du nom est plus petit que le terme de recherche
						isFound = false;
					}
					for (int j = 1; j < name.length(); j++) {
						if(i+j < item.getName().length()) { //s'assurer de ne pas etre out of bounds
							if (item.getName().charAt(i+j) != name.charAt(j)) { //compare les char 1 a 1
								isFound = false;
								break;
							}
						}
					}
				}
				if(isFound) {
					resultsByName_.add(item);
				}
			}
		}
	}
		
	//Methode de recherche par le ID de l'Item, ajoute tous les items ayant le terme cherche dans les resultats
	public void searchById(String id) {
		Set<Item> temp = new HashSet<Item>();
		
		if (refine && !results_.isEmpty()) {
			temp.addAll(results_);
		}	
		else if(refine && results_.isEmpty()) {
			System.out.println("Erreur: Vous essayez de rafiner une recherche ayant aucun resultat, une nouvelle recherche est demaree.");
			temp.addAll(inventory_.getItems());
		}
		else
			temp.addAll(inventory_.getItems());
		
		for (Item item : temp) {
			boolean isFound = false;
			for (int i = 0; i < item.getID().length(); i++) { // parcours nom de l'obj en inventaire
				if (item.getID().charAt(i) == id.charAt(0)) {
					isFound = true;
					if (item.getID().length()- i < id.length()) { //si la portion restante du nom est plus petit que le terme de recherche
						isFound = false;
					}
					for (int j = 1; j < id.length(); j++) {
						if(i+j < item.getID().length()) { //s'assurer de ne pas etre out of bounds
							if (item.getID().charAt(i+j) != id.charAt(j)) { //compare les char 1 a 1
								isFound = false;
								break;
							}
						}
					}
				}
				if(isFound) {
					resultsById_.add(item);
				}
			}
		}
	}

	//Methode de recherche par le Type de l'Item, ajoute tous les items ayant le terme cherche dans les resultats
	public void searchByType(char type) {
		Set<Item> temp = new HashSet<Item>();
		
		if (refine && !results_.isEmpty()) {
			temp.addAll(results_);
		}	
		else if(refine && results_.isEmpty()) {
			System.out.println("Erreur: Vous essayez de rafiner une recherche ayant aucun resultat, une nouvelle recherche est demaree.");
			temp.addAll(inventory_.getItems());
		}
		else
			temp.addAll(inventory_.getItems());
		
		for (Item item : temp) {
			for (int i = 0; i < item.getName().length(); i++) { // parcours nom de l'obj en inventaire
				if (item.getType() == type) {
					resultsByType_.add(item);
				}
			}
		}
	}
	
	// Methode qui coordonne les trois methodes de recherche selon les champs entres par l'utilisateur
	public void filter(Scanner input) {
		boolean restartSearch = true;
		boolean nameNull = false, idNull = false, typeNull = false;
		
		while(restartSearch) {
			//Scanner input= new Scanner(System.in);
			System.out.println("Recherche: (laissez vide si inconnu)");
			
			System.out.print("Entrez nom:");
			String name = input.nextLine();
			if (name.equals("") || name.equals(" ")) {
				nameNull = true;
				System.out.print("no name entered");
			}
			else nameNull = false;
				
			System.out.println();
			
			System.out.print("Entrez id:");
			String id =input.nextLine();
			if (id.equals("") || id.equals(" ")) {
				idNull = true;
				System.out.print("no id entered");
			}
			else idNull = false;
				
			System.out.println();
			
			System.out.print("Entrez type:");
			String type =input.nextLine();
			
			if (type.equals("") || type.equals(" ")) {
				typeNull = true;
				System.out.print("no type entered");
			}
			else typeNull = false;
				
			System.out.println();
			
			if(!nameNull) 
				searchByName(name);	
			if(!idNull) 
				searchById(id);
			if(!typeNull)
				searchByType(type.charAt(0));
			
			if(nameNull && idNull && typeNull) {
				System.out.println(" Vous n'avez rien entre, veuillez entre au moins 1 champ de recherche.");
				restartSearch = true;
			}else {
				System.out.println();
				System.out.println("Resultats:");
				printResults();/////////////////////////
				System.out.println();
				if (results_.isEmpty()) {
					System.out.println("Aucun resultat");
				}
				else {
					restartSearch = searchMenu(input);
				}		
			}		
		}	
	}
	
	//Methode qui affiche un menu suite a une premiere recherche
	public boolean searchMenu(Scanner input) {
		//boolean exit = false;
		
		while(true) {
			
			System.out.println("Veuillez choisir une option: ");
			System.out.println("(1) Add search result to cart.");
			System.out.println("(2) Refine search.");
			System.out.println("(3) New search.");
			System.out.println("Entrez '0' pour quitter la recherche et revenir vers le menu principal.");
			
			String choice = null;
			if (input.hasNextLine())
				choice = input.nextLine();
			
			switch(choice) {
			case "0":{
				return false;
			}
			case "1":{//add to cart
				if (!results_.isEmpty()) {
					addToCart();
					System.out.println("Item(s) ajoute(s) avec succes au panier.");
				}
					
				else
					System.out.println("Erreur: aucun item a ajouter, veuiller refaire une nouvelle recherche.");
				
			}break;
			case "2":{// refine search on last results
				refine = true;
				if (results_.isEmpty())
					System.out.println("Erreur: aucun resultat a rafiner, veuiller refaire une nouvelle recherche.");
				else
					return true;
			}
			case "3":{ //erase all search contents and redo search
				results_.clear();
				refine = false;
				return true;
			}
			default:{
				System.out.println("Choix non valide, veuiller choisir un choix du menu: ");
			}break;
			}
		}
		
	}
	
	//add current search results to cart
	public void addToCart() {
		for(Item i: results_) {
			cart_.addItem(i);
		}
		results_.clear();
	}
	
	// Etant donne qu'il y a trois methodes de recherche qui stockent les resultats dans differents set,
	// cette methode permet de tout fusionner 
	public void mergeResults() {
		results_.clear();
		
		if (!resultsByName_.isEmpty()) {
			for (Item i: resultsByName_) {
				results_.add(i);
			}
		}
			
		if (!resultsById_.isEmpty()) {
			for (Item i: resultsById_) {
				results_.add(i);
			}
			
		}
		if (!resultsByType_.isEmpty()) {
			for (Item i: resultsByType_) {
				results_.add(i);
			}
			
		}
		
		//Cas ou il y a plusieurs champs entrees en meme temps
		Set<Item> temp = new HashSet<Item>();
		for (Item i: results_) {
			if (!resultsByName_.isEmpty() && !resultsById_.isEmpty() && !resultsByType_.isEmpty()) {
				if (!resultsByName_.contains(i) || !resultsById_.contains(i) || !resultsByType_.contains(i)) {
					temp.add(i);
				}
			}
			else if (!resultsByName_.isEmpty() && !resultsById_.isEmpty() && resultsByType_.isEmpty()) {
				if (!resultsByName_.contains(i) || !resultsById_.contains(i)) {
					temp.add(i);
				}
			}
			else if (!resultsByName_.isEmpty() && resultsById_.isEmpty() && !resultsByType_.isEmpty()) {
				if (!resultsByName_.contains(i) || !resultsByType_.contains(i)) {
					temp.add(i);
				}
			}
			else if (resultsByName_.isEmpty() && !resultsById_.isEmpty() && !resultsByType_.isEmpty()) {
				if (!resultsById_.contains(i) || !resultsByType_.contains(i)) {
					temp.add(i);
				}
			}
		}
		
		if (!temp.isEmpty()) {
			for (Item i : temp) {
				if (results_.contains(i)) {
					results_.remove(i);
				}	
			}
		}
		
		//vide les 3 set specifiques
		resultsByName_.clear();
		resultsById_.clear();
		resultsByType_.clear();
	}
	
	//Methode pour imprimer les resultats de la recherche (si non vide)
	public void printResults() {
		mergeResults();
		if (!results_.isEmpty()) {
			for (Item i: results_) {
				i.printItem();
			}
		}	
	}
}