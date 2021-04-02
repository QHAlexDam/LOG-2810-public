import java.util.HashSet;
import java.util.Scanner;
import java.util.Set; 
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

/*Classe Inventory
 * Represente l'inventaire (extrait d'un fichier txt)
 * */

public class Inventory {
	private Set<Item> items_;
	
	//constructor with filename
	public Inventory(String fileName) throws Exception {
		items_ = new HashSet<Item>();
		readFile(fileName);
	}
	
	//getter
	public Set<Item> getItems(){
		return items_;
	}
	
	//add item in set
	public void addItem(Item item) {
		items_.add(item);
	}
	
	//remove item from set
	public void removeItem(Item item) {
		if(items_.contains(item))
			items_.remove(item);
	}
	
	//remove all items from set
	public void clearInventory() {
		items_.removeAll(items_);
	}
	
	//Read a txt file dans creates items with each line and adds the items to the set
	public void readFile(String fileName) throws Exception{
		FileReader f=new FileReader(new File("./src/" + fileName)); //important, il faut que le fichier txt soit dans le fichier src
	    BufferedReader bf=new BufferedReader(f);
		Scanner scanner = new Scanner(bf);

		while(scanner.hasNextLine()){
			if (scanner.nextLine() != null) {
				final String name = scanner.next();
				final String id = scanner.next();
			    final char type = scanner.next().charAt(0);

			    Item item = new Item (name, id, type);
			    items_.add(item);
			}
			
		}
		scanner.close();
	}
	
	//print items in inventory
	public void printInventory() {
		for (Item i : items_) {
			i.printItem();
		}
	}
		
}