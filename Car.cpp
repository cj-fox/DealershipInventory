#include <iostream>
#include <vector>
#include <iomanip>
#include "Car.h"

using namespace std;


//constructors
car::car()
{
	VIN = "unknown";
	make = "unknown";
	model = "unknown";
	year = 1980;
	price = 0.00;
	category = "unknown";
}
car::car(string vin, string make, string model, int year, float price, string category)
{
	this->VIN = vin;
	this->make = make;
	this->model = model;
	this->year = year;
	this->price = price;
	this->category = category;
}

//return functinos
string car::getVIN()
{
	return this->VIN;
}
string car::getMake()
{
	return this->make;
}
string car::getModel()
{
	return this->model;
}
int car::getYear()
{
	return this->year;
}
float car::getPrice()
{
	return this->price;
}
string car::getCategory()
{
	return this->category;
}

//overloading << operator
ostream& operator<<(ostream& osObj, const car& carObj)
{
	osObj << carObj.VIN << setw(15) << carObj.make << setw(10) << carObj.model << setw(10) << carObj.year
		<< setw(10) << carObj.price << setw(10) << carObj.category << endl;

	return osObj;
}
void car::print()
{
	cout << this->VIN << setw(15) << this->make << setw(10) << this->model << setw(10) << this->year
		<< setw(10) << this->price << setw(10) << this->category << endl;
}





