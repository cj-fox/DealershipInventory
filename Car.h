#pragma once
#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <vector>
using namespace std;


class car
{
public:
	//constructors
	car();
	car(string vin, string make, string model, int year, float price, string category);

	//overloading << operator
	friend ostream& operator<<(ostream& osObj, const car& carObj);
	virtual void print();

	//return functions
	string getVIN();
	string getMake();
	string getModel();
	int getYear();
	float getPrice();
	string getCategory();

private:
	//characteristics of car objects (new and used)
	string VIN;
	string make;
	string model;
	int year;
	float price;
	string category;
	
	


};

#endif