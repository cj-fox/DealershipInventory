#include "usedCar.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "Car.h"
#include "Inventory.h"

using namespace std;

//constructors
usedCar::usedCar() :car()
{
	this->mileage = 0;
}
usedCar::usedCar(string vin, string make, string model, int year, float price, string category, int mileage) 
	: car(vin, make, model, year, price, category)
{
	this->mileage = mileage;
}

//overloading << operator
ostream& operator<<(ostream& osObj, usedCar& carObj)
{
	osObj << setw(5) << carObj.getVIN();
	osObj << setw(15) << carObj.getMake();
	osObj << setw(15) << carObj.getModel();
	osObj << setw(15)<< carObj.getYear();
	osObj << setw(15) << carObj.getPrice();
	osObj << setw(15) << carObj.getCategory();
	osObj << setw(15) << carObj.getMileage();
	osObj << setw(20) << "N/A" << endl;

	return osObj;
}

//overriding virtual print function
void usedCar::print()
{
	cout << *this;
	
}

//return function for mileage
int usedCar::getMileage()
{
	return this->mileage;
}

//sell and lease functions
void usedCar::leaseCar()
{

}

//function used to add used car to inventory
usedCar usedCar::addToInventory()
{
	string vin, make, model;
	int year, mileage;
	float price;

	cout << "Please fill out information on the used vehicle" << endl;
	cout << "------------------------------------------------" << endl << endl;

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

	cout << "Enter the mileage: ";
	cin >> mileage;
	cout << endl;

	return usedCar(vin, make, model, year, price, "Used", mileage); //return the used car object to the function to be put into catalog vector
}