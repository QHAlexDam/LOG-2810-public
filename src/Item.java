
/*Classe Item
 * Represente un item qui peut etre achete
 * */

public class Item {
	private String name_;
	private char type_;
	private String ID_;
	private int weight_;
	
	//constructor
	public Item(String name, String ID, char type) {
		name_ = name;
		type_ = type;
		ID_ = ID;
		if(type == 'A')
			weight_ = 1;
		if (type == 'B')
			weight_ = 3;
		if (type == 'C')
			weight_ = 6;
		
	}
	
	//getters
	public String getName() {
		return name_;
	}
	public char getType() {
		return type_;
	}
	public String getID() {
		return ID_;
	}
	public int getWeight() {
		return weight_;
	}
	//print item
	public void printItem() {
		System.out.println("Name: " + name_ + ", type: " + type_ + ", ID: " + ID_);
	}
}

