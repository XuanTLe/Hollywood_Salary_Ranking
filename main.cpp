// MathProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "HollywoodPay.h"
#include <string>

using namespace std;
int displayMenu();
int main()
{
	HollywoodPay person;
	person.insert(68, "Mark Wahlberg");
	person.insert(65, "Dwayne 'The Rock' Johnson");
	person.insert(54.5, "Vin Diesel");
	person.insert(50.5, "Adam Sandler");
	person.insert(49, "Jackie Chan");
	person.insert(48, "Robert Downey, Jr.");
	person.insert(43, "Tom Cruise");
	person.insert(31.5, "Chris Hemsworth");
	person.insert(31, "Tom Hanks");
	person.insert(30.5, "Samuel L. Jackson");
	person.insert(29, "Ryan Gosling");
	person.insert(26, "Emma Stone");
	person.insert(25.5, "Jennifer Aniston");
	person.insert(24, "Jennifer Lawrence");
	person.insert(21.5, "Ryan Reynolds");
	person.insert(21, "Matt Damon");
	person.insert(19, "Jeremy Renner");

	int decision;
	float starPay;
	string starName;
	decision = displayMenu(); // get user's option in menu

	while (decision != 5)
	{
		switch (decision)
		{
			case 1: // Search a name
				cout << " Enter the star's name you want to search': ";
				cin.ignore();
				getline(cin, starName);
				if (person.search(person.getRootNode(), starName))
					cout << " The name was found.\n";

				else
					cout << " The name was not found.\n";
				
				break;

				// Display the tree
			case 2:
				cout << "\n Display the tree inorder\n";
				person.showTree();
				break;

			case 3: // Add a new star
				cout << " Enter the name of the new star: ";
				cin.ignore();
				getline(cin, starName);
				if (person.search(person.getRootNode(), starName))
					cout << " That name was already in the tree.\n";

				else
				{
					cout << "Enter pay: ";
					cin >> starPay;
					person.insert(starPay, starName);
				}

				break;

			case 4: // Remove a star
				cout << " Enter the name of the star you want to remove: ";
				cin.ignore();
				getline(cin, starName);
				
				if (!person.search(person.getRootNode(), starName))
					cout << " That name was not found.\n";
				else
				{
					person.remove(starName);
					cout << "\nRemoved\n";
				}
		} //end switch

		  // get user's option
		decision = displayMenu();
	}// end while

	return 0;
}

/************************************************************************************************************
Function: displayMenu
Inputs:   User's choice
Outputs:  A valid user option
Purpose:  This function displays a menu, takes a user's input (choice), reads, validates, and returns it.
*************************************************************************************************************/
int displayMenu()
{
	int choice;
	do
	{
		cout << "\n-------------------------MENU----------------------------\n\n";
		cout << " 1. Search a Hollywood star\n";
		cout << " 2. Display the tree\n";
		cout << " 3. Add a new star\n";
		cout << " 4. Remove a star\n";
		cout << " 5. Quit the menu\n";
		cout << " This program summarizes the top 17 highest-paid stars and displays\n";
		cout << " a menu for the user to choose.\n";

		cout << " Enter a number from the menu for your choice: ";
		cin >> choice;

		if ((choice < 1) || (choice > 5))
		{
			cout << " Invalid choice. Please enter again: ";
			cin >> choice;
		}

	} while ((choice < 1) || (choice > 5));

	return choice;
}
