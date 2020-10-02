#pragma once
#ifndef USEDCAR_H
#define USEDCAR_H
#include "Car.h"

using namespace std;

class usedCar: public car
{
public:
	//constructors
	usedCar();
	usedCar(string vin, string make, string model, int year, float price, string category, int mileage);

	//overloading << operator
	friend ostream& operator<<(ostream& osObj, usedCar& carObj);

	//overriding virtual print function
	void print() override;

	//return function for mileage
	int getMileage();

	//sell and lease functions
	void leaseCar();

	//add new car to inventory
	usedCar addToInventory();

private:
	int mileage;
};
#endif