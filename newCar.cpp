#include "newCar.h"
#include <iostream>
#include <string>
#include "Car.h"
#include "Inventory.h"
#include <iomanip>

using namespace std;

//constructor
newCar::newCar(): car()
{
	warrantyProvider = "unknown";
}
newCar::newCar(string vin, string make, string model, int year, float price, string category, string warrantyProvider) : car(vin, make, model, year, price, category)
{
	this->warrantyProvider = warrantyProvider;
}

//overloading << operator & printing functions
ostream& operator<<(ostream& osObj, newCar& carObj)
{
	osObj << setw(5) << carObj.getVIN();
	osObj << setw(15) << carObj.getMake();
	osObj << setw(15) << carObj.getModel();
	osObj << setw(15) << carObj.getYear();
	osObj << setw(15) << carObj.getPrice();
	osObj << setw(15) << carObj.getCategory();
	osObj << setw(15) << "N/A";
	osObj << setw(20) << carObj.getWarranty() << endl;

	return osObj;
}

//overriding virtual print function from class car
void newCar::print()
{
	cout << *this;
}

//return function for warranty
string newCar::getWarranty()
{
	return this->warrantyProvider;
}

//add new car to inventory
newCar newCar::addToInventory()	//for getting info and adding new cars to inventory
{
	string vin, make, model, warrantyProvider;
	int year;
	float price;
	try
	{
		cout << "Please fill out information for the new vehicle" << endl;
		cout << "-----------------------------------------------" << endl << endl;

		cout << "Enter the VIN: ";
		cin >> vin;
		cout << endl;

		cout << "Enter the make: ";
		cin >> make;
		cout << endl;

		cout << "Enter the model: ";
		cin >> model;
		cout << endl;

		cout << "Enter the year: ";
		cin >> year;
		cout << endl;

		cout << "Enter the price: $";
		cin >> price;
		cout << endl;

		cout << "Enter the warranty provider (dealership or manufacturer): ";
		cin >> warrantyProvider;
		cout << endl;

		return newCar(vin, make, model, year, price, "New", warrantyProvider);
	}
	catch (logic_error le)
	{

	}

	
}



