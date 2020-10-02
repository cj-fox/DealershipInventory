#pragma 
#ifndef NEWCAR_H
#define NEWCAR_H
#include "Car.h"
#include <iostream>


using namespace std;

class newCar: public car
{
public:
	//constructor
	newCar();
	newCar(string vin, string make, string model, int year, float price, string warrantyProvider, string category="New");

	//overloading << operator
	friend ostream& operator<<(ostream& osObj, newCar& carObj);

	//overloading virtual function from car class
	void print();
	
	//return function for warranty
	string getWarranty();

	//add new car to inventory
	newCar addToInventory();
	
	

private:
	string warrantyProvider;
};
#endif