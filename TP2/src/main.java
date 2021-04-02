import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/*Main
 * Contient le menu principal du logiciel
 * */

public class main {
	public static Scanner input= new Scanner(System.in);
	
	public static void main(String[]args) throws Exception {
		boolean exit = false;
		boolean isInit = false;
		Inventory inventory = null;
		Cart cart = null; 
		Automaton auto = null;
		
		//boucle du menu qui est affiche jusqu'a ce que l'usager quitte
		while (!exit) {
			
			System.out.println();
			System.out.println();
			
			System.out.println("Veuillez choisir un des options suivants: ");
			
			if(!isInit)
				System.out.println( "(1) Initialiser le programme  " );
			else
				System.out.println( "(1) Imprimer l'inventaire " );
			
			System.out.println( "(2) Recherche" );
				
			System.out.println( "(3) Afficher le panier" );
			
			System.out.println( "(4) Vider le panier" );
			
			System.out.println( "(5) Passer commande" );
			
			System.out.println( "Entrez 0 en tout temps pour quitter." );
			
			String choice = input.nextLine();
			switch(choice) {
				case "0": { //quitte le programme
					System.out.println( "Merci d'avoir magasine chez nous." );
					exit = true;
				}break;
			
				case "1":{ // initialisation (inventaire et automate)
					if (!isInit) {
						System.out.println( "Le programme s'initialise ..." );
					
						//initalise l'inventaire (une seule fois au debut du programme)
						System.out.println( "Entrez le nom du fichier de l'inventaire avec l'extention: " );
						String fileName =input.nextLine();
						inventory = new Inventory (fileName);
						cart = new Cart(inventory, new HashSet<Item>(), 0);
						System.out.println( "Inventaire cree avec succes!" );
						
						//initialiser les automates
						System.out.println( "Creation des automates ... " );
						auto = new Automaton(inventory, cart);
						System.out.println( "Automate cree avec succes!" );
									
						isInit = true;
						System.out.println( "Le programme est pret." );
					}
					else { // si l'initialisation est deja fait, on remplace par l'option d'afficher l'inventaire
						System.out.println( "Voici l'inventaire: " );
						inventory.printInventory();		
					}
					
				}break;
				
				case "2":{ //recherche par nom, id ou type, on entre dans un 2e menu
					boolean endSearch = false;
					if (auto == null) {
						System.out.println( "Veuillez initialiser le programme avant la recherche" );
					}
					else {
						auto.filter(input);
					}
				}break;
				
				case "3":{ // afficher le panier
					if (cart == null || cart.getItems().isEmpty()) {
						System.out.println( "Le panier est vide" );
					}
					else { //imprimer les items du panier si non vide
						System.out.println( "Voici le contenu du panier: " );
						for (Item i: cart.getItems()) { //imprimer les items
							i.printItem();
						}
					}
				}break;
				
				case "4":{ // vide le panier
					if (cart == null || cart.getItems().isEmpty()) {
						System.out.println( "Panier est deja vide" );
					}
					else {
						cart.clearCart();
						System.out.println( "Panier a ete vide avec succes" );
					}
				}break;
				
				case "5":{ // passer commande
					if (cart == null || cart.getItems().isEmpty()) {
						System.out.println( "Erreur: panier vide" );
					}
					else {
						cart.checkout();
					}
					
				}break;
				default: {
					System.out.println( "Erreur, option invalide, veuillez reessayer." );
				}
				
				
			}
			
		}
	}
}
