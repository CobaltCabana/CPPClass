/*
  Programmer:           Rohan Teredesai
  Assignment:           Lab 7
  Topic:                Implement and test class Item
  File Name:            DL2_L7_Teredesai.cpp
  Course/Section:       COSC 1337; Section DL2
  Due Date:             See syllabus or blackboard
  Instructor:           Thayer
*/

// Compiler directives
#include <iostream> // for cin, cout, endl
#include <fstream>  // if needed for file IO
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class Item {
private:
	string name = "unknown item";	//A string that describes the item
	int ID;	        //An int that holds the item’s ID number
	int quantity;	//An int that holds the quantity of the item on hand
	double  cost;	//A double that hold the wholesale per - unit cost of the item

public:
	//default constructor
	Item() {
		ID = 1;
		quantity = 1;
		cost = 5.0;
	//	cout << "calling default ctr" << endl;
	}
	//second constructor
	Item(string aName, int anID, int aQuantity, double aCost) {
		name = aName;
		ID = abs(anID);
		quantity = abs(aQuantity);
		cost = abs(aCost);
	//	cout << "calling default ctr" << endl;
	}
	//default destructor
	~Item() {
		ID = 1;
		quantity = 1;
		cost = 5.0;
	//	cout << "calling default dtr" << endl;
	}
	void display() {
		cout << "name :  " << name
			<< " ID :  " << ID
			<< " quantity :  " << quantity
			<< " cost :  " << cost << endl;

	}
	//setters
	void set_name(string aName) { name = aName; } //Accept a string argumentand copies it into the name variable
	void set_ID(int anID) {
		if (anID < 0) {
			return;
		}
		ID = anID;
	}	//Accepts an int argumentand copies it into the ID variable, but ONLY if >= 0
	void set_quantity(int aQuantity) {
		if (aQuantity < 0) {
			return;
		}
		quantity = aQuantity;
	}	//Accept an int argument and copies it into the quantity variable if >= 0
	void	set_cost(double aCost) {
		if (aCost < 0) {
			return;
		}
		cost = aCost;
	}//Accepts a double argument and copies it into the cost variable if >= $0.00

	//getters
	string	get_name() { return name; }	//Returns the value in name
	int	get_ID() { return ID; }	//Returns the value of the ID
	int	get_quantity() { return quantity; }	//Returns the quantity value
	double get_cost() { return cost; }	//Returns the cost of a single item
	double	get_total_cost() { return quantity * cost; }	//Returns the cost of all the items in inventory

};
void testInput(Item& myItem) {
	//testing set ID
	if (myItem.get_ID() < 0) {
		cout << "Setter should have protected against negative user input ID!\n";
	}
	else {
		//cout << "Sucess, setter prevented negative value ID\n";
	}
	//testing set quantity
	if (myItem.get_quantity() < 0) {
		cout << "Setter should have protected against negative user input quantity!\n";
	}
	else {
		//cout << "Sucess, setter prevented negative value quantity\n";
	}
	//testing set cost
	if (myItem.get_cost() < 0) {
		cout << "Setter should have protected against negative user input cost!\n";
	}
	else {
		//cout << "Sucess, setter prevented negative value cost\n";
	}
}
void readInventoryFromFile(int argc, char* args[], Item items[], const int itemArraySize) {
	string firstLine;
	ifstream myfile;
	string fileName = argc > 1 ? args[1] : "C:\\Users\\rohan\\Desktop\\CPP\\DL2_L7_Teredesai\\DL2_L7_Teredesai\\DL2_L7_Teredesai.txt";
	myfile.open(fileName);
	if (myfile.is_open()) {
		cout << "Rohan Teredesai's Inventory File is OPENED\n\n";
		//cout << "Opened file: " << fileName;
	}
	else {
		cout << "Can't open file: " << fileName;
		cout << "Each row has the format itemName itemID itemQuantity itemCost";
		return;
	}
	string name;
	int ID;	        
	int quantity;
	double  cost;
	int itemNum = 0;

	while (myfile >> name >> ID >> quantity >> cost) {
		Item anItem { name, ID, quantity, cost};
		anItem.display();
		items[itemNum] = anItem;
		itemNum++;
		if (itemNum >= itemArraySize) {
			cout << "I only read" << itemArraySize << "rows";
			break;
		}
	}
	myfile.close();
	cout << endl;
}
int main(int argc, char* args[]) {
	const int MAX_INVENTORY{ 5 };
	Item items[MAX_INVENTORY];

	cout << "This program will create up to " << MAX_INVENTORY
		<< " separate, co-existing instances of items and display them to the user.\n";
	//THis is the hard coded method
	//Item myItem1{ "Racket", 140321, 2, 125.50 };
	//Item myItem2{ "Orange", 140322, 43, 5.50 };
	//Item myItem3{ "HockeyStick", 140323, 62, 70.99 };
	//Item myItem4{ "Trumpet", -140324, -8, 200.25 };
	//Item myItem5{ "Egg", 140325, 36, -1.10 };
	//items[0] = myItem1;
	//items[1] = myItem2;
	//items[2] = myItem3;
	//items[3] = myItem4;
	//items[4] = myItem5;
	
	//File read method
	readInventoryFromFile(argc, args, items, MAX_INVENTORY);


	//Displaying created objects and creating a subtotal of cost
	double sub_total = 0.0;
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		items[i].display();
		sub_total += items[i].get_total_cost();
	}
	cout << "Total cost of inventory = $" << sub_total <<endl;
	//testing invalid input during constructor
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		testInput(items[i]);
	}

	//Testing invalid input through setter
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		items[i].set_ID(-3);
		items[i].set_quantity(-1);
		items[i].set_cost(-5.5);
		testInput(items[i]);
	}

	cout << "I'm expecting myItem and myItem2 to have been destroyed";
	cout << "\nThis ends the Item program. Goodbye.\n";
	return EXIT_SUCCESS;
}   // end of main


// Test output below:
/*
This program will create up to 5 separate, co-existing instances of items and display them to the user.
Rohan Teredesai's Inventory File is OPENED

name :  Racket ID :  140321 quantity :  2 cost :  125.5
name :  Orange ID :  140322 quantity :  43 cost :  5.5
name :  HockeyStick ID :  140323 quantity :  62 cost :  70.99
name :  Trumpet ID :  140324 quantity :  8 cost :  200.25
name :  Egg ID :  140325 quantity :  36 cost :  1.1
I only read5rows
name :  Racket ID :  140321 quantity :  2 cost :  125.5
name :  Orange ID :  140322 quantity :  43 cost :  5.5
name :  HockeyStick ID :  140323 quantity :  62 cost :  70.99
name :  Trumpet ID :  140324 quantity :  8 cost :  200.25
name :  Egg ID :  140325 quantity :  36 cost :  1.1
Total cost of inventory = $6530.48
I'm expecting myItem and myItem2 to have been destroyed
This ends the Item program. Goodbye.

C:\Users\rohan\Desktop\CPP\DL2_L7_Teredesai\out\build\x64-Debug\DL2_L7_Teredesai\DL2_L7_Teredesai.exe (process 19920) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/