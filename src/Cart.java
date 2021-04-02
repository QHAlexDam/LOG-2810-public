import java.util.*;

/*Classe Cart 
 * Represente le panier d'achat
 * */

public class Cart {
	private Set<Item> items_;
	Inventory inventory_;
	private int weight_;
	
	public Cart(Inventory inv, Set<Item> items, int weight) {
		items_ = new HashSet<Item>(items);
		weight_ = weight;
		inventory_ = inv;
	}
	
	public Set <Item> getItems(){
		return items_;
	}
	
	public int getWeight() {
		return weight_;
	}
	
	public void addItem(Item item) {
		items_.add(item);
		weight_ += item.getWeight();
		updateInventory(true);
	}
	
	public void removeItem(Item item) {
		updateInventory(false);
		for (Item i : items_) {
			if (i.equals(item)) {
				items_.remove(item);
				weight_ -= item.getWeight();
				
			}
		}
	}
	
	public void clearCart() {
		updateInventory(false);
		items_.removeAll(items_);
		weight_ = 0;
	}
	
	//checkout les items dans le panier et vide le panier apres
	public void checkout() {
		if(weight_ > 25){
			System.out.println("Erreur, panier trop lourd, veuiller garder les commandes en dessous de 25Kg.");
			System.out.println("Veuillez vider le panier et recommencer");
		}
		else {
			System.out.println("Achat complete avec succes, voici la liste des achats: ");
			for (Item i: items_) {
				i.printItem();
			}
			clearCart();
		}
	}
	
	public void updateInventory(boolean remove) {
		if (remove) {
			for (Item item: items_) {
				if (inventory_.getItems().contains(item)) {
					inventory_.removeItem(item);
				}
			}
		}
		else {
			for (Item item: items_) {
				if (!inventory_.getItems().contains(item)) {
					inventory_.addItem(item);
				}
			}
		}
	}
}
