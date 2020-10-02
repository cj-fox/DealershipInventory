#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H
#include "Car.h"
#include "newCar.h"
#include "usedCar.h"
#include <vector>
class inventory
{
public:
	//constructor for the inventory
	inventory();

	//destructor because of the vector of pointers
	~inventory();

	//function to initialize starting inventory
	void initializeCatalog();

	//function to run program and interact with inventory
	void runProgram();
	
	//adding cars to inventory
	void addToInventory(car& carObj);
	void addToInventory();

	//deleting cars from inventory - to be used in leasing/selling functions
	void removeFromInventory(string vinInput);

	//sell/lease functions
	void returnLease();
	void sellOrLease();
	void sellCar();	
	void leaseCar(); 
	

	//search functions
	void searchMake();
	void searchYear();
	void searchPrice();
	void searchCategory();
	void searchInventory();

	//function to show all cars in inventory
	void printCatalog();
	
private:
	vector<car*> catalog{};
};
#endif