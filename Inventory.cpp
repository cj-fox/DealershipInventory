#include "Inventory.h"
#include<iostream>
#include <iomanip>

using namespace std;

//constructor
inventory::inventory()
{
}

//destructor
inventory::~inventory()
{

}

//initialize starting inventory
void inventory::initializeCatalog()
{
	catalog.emplace_back(new newCar("58196", "Dodge", "Charger", 2018, 42000, "New", "Dealership"));
	catalog.emplace_back(new newCar("13362", "Chevrolet", "Equinox", 2019, 26400, "New", "Dealership"));
	catalog.emplace_back(new newCar("76448", "Subaru", "Crosstrek", 2019, 30000, "New", "Manufacturer"));
	catalog.emplace_back(new newCar("99212", "Mercedes-Benz", "A220", 2018, 32800, "New", "Manufacturer"));
	catalog.emplace_back(new newCar("46552", "BMW", "330i", 2019, 40750, "New", "Manufacturer"));

	catalog.emplace_back(new usedCar("86519", "Ford", "Fusion", 2013, 8900, "Used", 64540));
	catalog.emplace_back(new usedCar("46795", "Ram", "1500", 2017, 33250, "Used", 14693));
	catalog.emplace_back(new usedCar("21789", "Pontiac", "Torrent", 2006, 3850, "Used", 124520));
	catalog.emplace_back(new usedCar("51098", "Ford", "Focus", 2007, 5420, "Used", 133200));
	catalog.emplace_back(new usedCar("62189", "Saturn", "Ion", 2008, 7430, "Used", 74300));
}

//function to run program and interact with inventory
void inventory::runProgram()
{

		
		inventory::initializeCatalog();
		while (true)
		{
			try
			{
				int option; //variable to interact with menu

				//display menu
				cout << "1. Display all inventory" << endl;
				cout << "2. Search Inventory" << endl;
				cout << "3. Sell/Lease cars" << endl;
				cout << "4. Return a leased car" << endl;
				cout << "5. Add cars to inventory" << endl;
				cout << "6. Exit" << endl;
				cout << "Enter option: ";																			//catch invalid inputs here
				cin >> option; //read in menu option
				cout << endl << endl;

				switch (option)
				{
				case 1:
					printCatalog();
					break;
				case 2:
					searchInventory();
					break;
				case 3:
					sellOrLease();
					break;
				case 4:
					returnLease();
					break;
				case 5:
					addToInventory();
					break;
				case 6:
					return;
					break;
				default:
					throw option; //if optoin != 1-6 throw error


				}
			}
			catch (int option)
			{
				cout << "Invalid option. Try again." << endl << endl; //return error message. loop continues to show menu
			}
		}
	
}


//adding cars to inventory
void inventory::addToInventory(car& carObj)
{
	this->catalog.push_back(&carObj);
}
void inventory::addToInventory()
{
	try //try block for attempting to add vehicle to the inventory
	{
		int option;

		cout << "Would you like to add a new or used car to the inventory?" << endl;
		cout << "1. New" << endl;
		cout << "2. Used " << endl;
		cout << "Enter option: ";
		cin >> option;

		if (option == 1)
		{
			car* addNewCar; //create car pointer object
			addNewCar = new newCar(newCar().addToInventory()); //get information for the car that is to be added to inventory
			for (int i = 0; i < catalog.size(); i++)
			{
				if (catalog[i]->getVIN() == addNewCar->getVIN()) //if a car with this VIN number is already in inventory
					throw addNewCar;//throw error; every car has unique VIN
			}
			
			catalog.push_back(addNewCar); //if error not thrown, add the car to the catalog
		}
		else if (option == 2) //same error checking process as adding new car
		{
			car* addUsedCar;
			addUsedCar = new usedCar(usedCar().addToInventory());
			for (int i = 0; i < catalog.size(); i++)
			{
				if (catalog[i]->getVIN() == addUsedCar->getVIN())
					throw addUsedCar;
			}
			catalog.push_back(addUsedCar);
		}
		else
		{
			cout << "Invalid input. Returning to menu." << endl << endl;

		}
	}
	catch (car * objectToAdd)
	{
		cout << "Cannot add car that is already in inventory." << endl<<endl;
	}
}

//deleting cars from inventory - to be used in leasing/selling functions
void inventory::removeFromInventory(string vinInput)
{
	int carLoc=999; //variable to find location of car in the catalog vector
	

	for (int i = 0; i < catalog.size(); i++)
	{
		if (catalog[i]->getVIN() == vinInput)//if the VIN of a car in the catalog matches the VIN of car to remove
		{
			carLoc = i;//save index in carLoc
		}
	}
	if (carLoc == 999)//if no location was saved in carLoc
		cout << "Car was not found." << endl;
	else//if the desired VIN was found
	{
		int option;
		cout << *catalog[carLoc];
		cout << "Confirm car removal from inventory." << endl;//confirm that the car should be removed because of the lease or sale
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		cout << "Enter option: ";
		cin >> option;
		cout << endl;
		if (option == 1)//if yes
		{
			catalog.erase(catalog.begin()+carLoc);//remove the vehicle from the catalog vector
			cout << "Car removed from inventory." << endl;//show confirmation message
		}
		if (option == 2)//if no
		{
			cout << "Car not removed." << endl;//show message to indicate that the car was not removed and is still in inventory
		}
		
	}
}

//sell/lease functions
void inventory::returnLease()
{
	car* lease;
	lease = new usedCar(usedCar().addToInventory()); //the returning lease is now entered in the inventory as a used car
	catalog.push_back(lease);
}
void inventory::sellOrLease()
{
	int option;
	cout << "Would you like to sell or lease a car?" << endl;
	cout << "1. Sell" << endl;
	cout << "2. Lease" << endl;
	cout << "Enter option: ";
	cin >> option;
	if (option == 1)
		sellCar();
	else if (option == 2)
		leaseCar();
	else if(option != 1 && option != 2)
		cout << "Invalid input." << endl;
}
void inventory::sellCar()
{
	string vinInput;
	bool removed = true;
	printCatalog();
	cout << "Enter VIN of car to sell: ";
	cin >> vinInput;
	cout << endl;


		removeFromInventory(vinInput); //call function to remove the vehicle
		for (int i = 0; i < catalog.size(); i++)//removeFromInventory asks for confirmation, so iterate through to confirm that the car was removed
			{
				if (catalog[i]->getVIN() == vinInput)//if that VIN number is still found in the catalog
					removed = false; //indicate the car was not removed
			}
		if (removed == true)//output appropriate message for whether or not the lease was completed
			cout << "Sale complete." << endl << endl;
		else
			cout << "Sale incomplete." << endl << endl;		
		
	
	


}
void inventory::leaseCar()
{
	string vinInput;
	bool removed = true; //variable to confimr the vehicle gets removed
	int carLoc = 999; // variable for locating vehicle in the catalog vector
	printCatalog(); //show the inventory
	cout << "Enter VIN of car to lease: ";
	cin >> vinInput; //get VIN for car that is to be leased
	cout << endl;

	for (int i = 0; i < catalog.size(); i++)
	{
		if (catalog[i]->getVIN() == vinInput) //iterate through the catalog
		{
			carLoc = i; //find location of the appropriate car in the catalog vector
		}
	}
	if (carLoc != 999) //if the car was found in the vector
	{
		if (catalog[carLoc]->getCategory() == "New")//and the car with that VIN number is a New car
		{
			removeFromInventory(vinInput); //call function to remove the vehicle
			for (int i = 0; i < catalog.size(); i++)//removeFromInventory asks for confirmation, so iterate through to confirm that the car was removed
			{
				if (catalog[i]->getVIN() == vinInput)//if that VIN number is still found in the catalog
					removed = false; //indicate the car was not removed
			}
			if (removed == true)//output appropriate message for whether or not the lease was completed
				cout << "Lease complete." << endl << endl;
			else
				cout << "Lease incomplete." << endl << endl;
		}
		else //if the car with the VIN number searched for is not in the New category
			cout << "Cannot lease used cars." << endl << endl;
	}
	else//if the car location for that VIN number was never found
		cout << "Car was not found." << endl << endl;
	
}

//search functions
void inventory::searchMake()
{
	string makeWanted;
	bool found = false;
	cout << "Enter the make to search for: "; //prompt for desired make
	cin >> makeWanted; //input make
	cout << endl;
	cout << "Searching for: " << makeWanted << "." << endl << endl; //show message that confirms it is being searched for

	for (int i = 0; i < catalog.size(); i++) // linear search of catalog for the desired make
	{
		if (catalog[i]->getMake() == makeWanted) //if the make of a car in the inventory matches the desired make
		{
			catalog[i]->print(); //output the information of the car that fits criteria
			found = true; //indicate that at least one matching car has been found
		}
	}
	if (!found) //if no matching cars were found
		cout << "Make not found." << endl; //display message stating that none were found

	cout << endl;
	//same algorithm follows for all the following search methods

}
void inventory::searchYear()
{
	int yearWanted;
	bool found = false;
	cout << "Enter year of car to search for: ";
	cin >> yearWanted;
	cout << endl;
	cout << "Searching for cars from " << yearWanted << "." << endl;

	for (int i = 0; i < catalog.size(); i++)
	{
		if (catalog[i]->getYear() == yearWanted)
		{
			catalog[i]->print();
			found = true;
		}
	}
	if (!found)
		cout << "No cars found from " << yearWanted << "." << endl;

	cout << endl;
}
void inventory::searchPrice()
{
	float min, max;
	bool found = false;
	cout << "Enter price range minimum: $";
	cin >> min;

	cout << "Enter price range maximum: $";
	cin >> max;

	for (int i = 0; i < catalog.size(); i++)
	{
		if (catalog[i]->getPrice() >= min && catalog[i]->getPrice() <= max)
		{
			catalog[i]->print();
			found = true;
		}
	}
	if (!found)
		cout << "No cars in this price range." << endl;

	cout << endl;
}
void inventory::searchCategory()
{
	string categoryWanted;
	bool found = false;

	cout << "Enter category to search for (New or Used): ";
	cin >> categoryWanted;
	cout << endl;
	cout << "Searching for " << categoryWanted << " cars." << endl << endl;

	for (int i = 0; i < catalog.size(); i++)
	{
		if (catalog[i]->getCategory() == categoryWanted)
		{
			catalog[i]->print();
			found = true;
		}
	}
	if (!found)
		cout << "No " << categoryWanted << " cars found." << endl;
	cout << endl;
}
void inventory::searchInventory()
{
	int option;
	cout << "How would you like to search?" << endl;
	cout << "1. Search by make" << endl;
	cout << "2. Search by year" << endl;
	cout << "3. Search by price" << endl;
	cout << "4. Search by category" << endl;

	cout << "Enter option: ";
	cin >> option;

	switch (option)
	{
	case 1:
		searchMake();
		break;
	case 2:
		searchYear();
		break;
	case 3:
		searchPrice();
		break;
	case 4:
		searchCategory();
		break;
	default:
		cout << "Invalid input. Returning to menu."<<endl << endl;
		break;
	}
}

//function to show all cars in inventory
void inventory::printCatalog()
{
	if (catalog.empty())
	{
		cout << "Inventory is empty." << endl << endl;
	}
	if (!catalog.empty())
	{
		
		cout << setw(5) << "VIN";
		cout << setw(15) << "Make";
		cout << setw(15) << " Model";
		cout << setw(15) << "Year";
		cout << setw(15) << "Price";
		cout << setw(15) << "Category";
		cout << setw(15) << "Mileage";
		cout << setw(20) << "Warranty Provider"<<endl << endl;
		for (int i =0; i<catalog.size();i++)
		{
			catalog[i]->print();
		}
	}
	cout << endl;


}
