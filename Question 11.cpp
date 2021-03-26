#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>
#include <vector>
using namespace std;
//James Ng CSCI 313 Question 11
class Restaurant {//Class Restaurant
public:
	struct Menu {};
	virtual void menu() = 0;//pure virutal menu
};
class Italian_Restaurant :Restaurant {//Derived from Restaurant
public:
	void menu() {
	string italian = "Italian";
	vector<string>Pizza = { "Cheese","Pepperoni","Margherita","Sicilian Pizza" };//This vector is the Pizza section
	vector<double>PizzaPrice = { 10.99,13.99,10.99,14.99 };//Pizza prices
	vector<string>Pasta = { "Spaghetti Pomodoro","Sausage Tortelloni","Pasta Woozie", "Spagghetti & Meatballs","Fettucccine Alfredo","Shrimp Alfedo" };//This vector is the Pasta section
	vector<double>PastaPrice = { 13.99,16.99,15.99,15.99,13.99,17.99 };//Pasta prices
	vector<string>Parm = { "Eggplant Parmesan","Veal Parmesan" };//This vector is the Parmesan section
	vector<double>ParmPrice{ 16.99,22.99 };//Parmesan prices
	vector<string>Dessert = { "Vanilla Gelato","Caramel Mascarpone Cheesecake","Warm Chocolate Cake","Tiramisu","Creme Brulee" };//This vector is the Desserts section
	vector<double>DessertPrice = { 4.99,6.99,7.99,6.99,6.99 };//Dessert Price
	cout << "Here is the " << italian << " menu:" << endl;//Food Menu is from Bravo! Italian Kitchen
	cout << "Pizza:" << endl;
	for (size_t i = 0; i < Pizza.size(); i++) {//Prints the Pizza section. size_t instead of int as int caused an error
		cout << Pizza[i] << "		Price: $" << PizzaPrice[i] << endl;
	}
	cout << "Pasta:" << endl;
	for (size_t i = 0; i < Pasta.size(); i++) {//Prints the Pasta section
		cout << Pasta[i] << "		Price: $" << PastaPrice[i] << endl;
	}
	cout << "Parmesan: " << endl;
	for (size_t i = 0; i < Parm.size(); i++) {//Prints the Parmesan section
		cout << Parm[i] << "		Price: $" << ParmPrice[i] << endl;
	}
	cout << "Dessert: " << endl;
	for (size_t i = 0; i < Dessert.size(); i++) {//Prints the Dessert section
		cout << Dessert[i] << "		Price: $" << DessertPrice[i] << endl;
	}
}
};
class Greek_Restaurant:Restaurant { // Derived from Restaurant
public:
	string greek = "Greek";//This is made so that if anyone wanted to get rid of the string and replace it, it'll be less of a hassle
	vector<string>Gyros= {"Beef/Lamb Gyro"," Pork Gyro Pita "," Chicken Gyro Pita "," Pork Souvlaki Pita "," Chicken Souvlaki Pita "," Veggie Pita "," Beefteki Pita "," Grecian Beefteki Burger " };//This vector is the Gyro section
	vector<double>GyrosPrice = {6.95,6.95,6.95,6.95,6.95,6.95,6.95,7.95};//Gyro Prices
	vector<string>Soups = {"Avgolemono Soup"," Gyro Salad ","Greek Salad ","Prasini Salad"};//This vector is the Soup section
	vector<double>SoupsPrice = {4.50,8.95,6.95,6.95};//Soup Prices
	vector<string>Plates = {" Chicken Souvlaki Plate","Pork Souvlaki Plate","Gyro Plate"};//This vector is the Plates section
	vector<double>PlatesPrice = {9.95,9.95,9.95};//Plate Prices
	vector<string>Desserts = { "Baklava","Yogurt with Honey", "Loukoumades" };//This vector is the Desserts section
	vector<double>DessertsPrice = { 3.00,4.00,4.95 };//Dessert Prices
	void menu() {
		cout<<" Here is the " << greek << " menu:" << endl;//Food Menu is from Nick the Greek's restaurant
		cout << "Gyros: " << endl;
		for (size_t i = 0; i < Gyros.size(); i++) {//Prints the Gyro section
			cout << Gyros[i] << "		Price: $" << GyrosPrice[i] << endl;
		}
		cout << "Soups: " << endl;
		for (size_t i = 0; i < Soups.size(); i++) {//Prints the Soup section
			cout << Soups[i] << "		Price: $" << SoupsPrice[i] << endl;
		}
		cout << "Plates: " << endl;
		for (size_t i = 0; i < Plates.size(); i++) {//Prints the Plates section
			cout << Plates[i] << "		Price: $" << PlatesPrice[i] << endl;
		}
		cout << "Desserts: " << endl;
		for (size_t i = 0; i < Desserts.size(); i++) {//Prints the Dessert section
			cout << Desserts[i] << "		Price: $" << DessertsPrice[i] << endl;
		}
	}
};
class Chinese_Restaurant:Restaurant {// Derived from Restaurant
public:
	string chinese = "Chinese";
	vector<string>Rice = { "Vegetable Fried Rice","Roast Pork Fried Rice", "Chicken Fried Rice", "Beef Fried Rice","Shrimp Fried Rice","Young Chow Fried Rice","House Special Fried Rice" };//This vector is the Rice section
	vector<double>RicePrice = { 4.95,4.95,5.25,5.95,5.95,6.55,6.55 };//Rice Prices
	vector<string>Noodles = { "Vegetable Lo Mein","Roast Pork Lo Mein", "Chicken Lo Mein", "Beef Lo Mein","Shrimp Lo Mein","Plain Lo Mein","House Special Lo Mein" };//This vector is the Noodles section
	vector<double>NoodlesPrice = { 6.25,6.25,6.25,6.75,6.75,4.95,7.25};//Noodle Prices
	vector<string>Beef= {"Beef w.Broccoli","Shredded Beef w. Scallion","Beef w. Bean Curd", "Beef w. Brown Sauce"};//This vector is the Beef section
	vector<double>BeefPrice = {7.55,7.55,7.55,8.55};//Beef Prices
	vector<string>Pork= {"Roast Pork w. Broccoli", "Fresh Shredded Pork","Sweet & Sour Pork"};//This vector is the Pork section
	vector<double>PorkPrice = {6.95,6.95,6.95};//Pork Prices
	vector<string>Chicken = {"Chicken Keilly Style","Chicken w. Broccoli","Sweet & Sour Chicken", "Kung Po Chicken","Chicken w.Brown Sauce","Pineapple Chicken","Lemon Chicken","Boneless Chicken"};//This vector is the Chicken section
	vector<double>ChickenPrice = {7.15,7.15,7.15,7.15,8.15,12.95,12.95,12.95};//Chicken Prices
	void menu() {
		cout << "Here is the " << chinese << " menu" << endl;//Food Menu is from Keilly's Chinese Restaurant
		cout << "Rice:" << endl;
		for (size_t i = 0; i < Rice.size(); i++) {//Prints the Rice section
			cout << Rice[i] << "		Price: $" << RicePrice[i] << endl;
		}
		cout << "Noodles:" << endl;
		for (size_t i = 0; i < Noodles.size(); i++) {//Prints the Noodles section
			cout << Noodles[i] << "		Price: $" << NoodlesPrice[i] << endl;
		}
		cout << "Beef:" << endl;
		for (size_t i = 0; i < Beef.size(); i++) {//Prints the Beef section
			cout << Beef[i] << "		Price: $" << BeefPrice[i] << endl;
		}
		cout << "Pork" << endl;
		for (size_t i = 0; i < Pork.size(); i++) {//Prints the Pork section
			cout << Pork[i] << "		Price: $" << PorkPrice[i] << endl;
		}
		cout << "Chicken" << endl;
		for (size_t i = 0; i < Chicken.size(); i++) {//Prints the Chicken section
			cout << Chicken[i] << "		Price: $" << ChickenPrice[i] << endl;
		}
	}
};
template<class Reader_Robot>
void readMenu(Reader_Robot restaurant){//Reader_robot receives value
	restaurant.menu();//Provides the menu that user provided
}
int main(){
	string name;
		cout << "Hello! What restaurant would you like to eat today?" << endl;//Prompts the user to input the restaurant name
		cout << "1. Italian" << endl;
		cout << "2. Greek" << endl;
		cout << "3. Chinese" << endl;
		cin >> name;
		transform(name.begin(), name.end(), name.begin(), ::tolower);//This is to change the input the user gave and make it all lowercase so it doesn't matter that input it is as long as it spells the key word.
		if (name == "italian" || name == "1") {
			Italian_Restaurant it;//it is for italian
			readMenu(it); // We use Reader_robot to direct us on what menu it will give us
		}
		if (name == "greek" || name == "2") {
			Greek_Restaurant gr;//gr is for greek 
			readMenu(gr);// We use Reader_robot to direct us on what menu it will give us
		}
		if (name == "chinese" || name == "3") {// using || without name was a mistake
		Chinese_Restaurant ch;//ch is for chinese
		readMenu(ch);// We use Reader_robot to direct us on what menu it will give us
		}		
}