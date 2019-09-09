//Created by Emil Hallin
//Modified 2019-09-09

#include <iostream>
#include <fstream>
#include <string>
#include "TimberRegister.h"
#include "Timber.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	TimberRegister timbers;
	string dimension;
	string filename;
	string answer;
	int runningMetre;
	int choice = 0;
	int underRM;
	int menu;
	int exit = 0;
	bool success = false;
	float value;
	float price;

	while (!exit)
	{
		int negative = 1;

		system("cls");
		cout << "Welcome to the Timber Storage!" << endl;
		cout << "1. Add timber" << endl;
		cout << "2. Show all timbers" << endl;
		cout << "3. Show dimension under specific running meter" << endl;
		cout << "4. Present current total price" << endl;
		cout << "5. Remove timber" << endl;
		cout << "6. Change properties" << endl;
		cout << "7. Save to file" << endl;
		cout << "8. Load file" << endl;
		cout << "9. Exit" << endl;
		cout << "Choice: ";
		cin >> menu; cin.ignore();					//Expected the user to write an integer.

		switch (menu)
		{
		case 1:
			while (negative)
			{
				cout << "Timber Dimension: ";
				getline(cin, dimension);
				cout << "Running Meter: ";			//Expected the user to write an integer.
				cin >> runningMetre; cin.ignore();
				cout << "Price: ";					//Expected the user to write a float.
				cin >> price; cin.ignore();
				
				if (runningMetre < 0 || price < 0)
				{
					negative = 1;
				}
				else
				{
					negative = 0;
				}
				for (int i = 0; i < sizeof(dimension) && dimension[i] != '\0'; i++)
				{
					if (dimension[i] == '-')
					{
						negative = 1;
					}
				}
				if (negative)
				{
					cout << "An error occured. Remember to only enter positive numbers!" << endl;
				}
			}
			timbers.addTimber(dimension, runningMetre, price);
			break;
		case 2:
			cout << timbers.printTimber();
			getchar();
			break;
		case 3:
			while (negative)
			{
				cout << "Enter a maximum Running Meter: ";
				cin >> underRM; cin.ignore();
				if (underRM < 0)
				{
					negative = 1;
					cout << "A running meter can't be negative! Please try again." << endl;
				}
				else
				{
					negative = 0;
				}
			}
			cout << "Displaying Timbers under " << to_string(underRM) << endl;
			cout << timbers.printTimberUnderRunningMetre(underRM);
			getchar();
			break;
		case 4:
			cout << "Total price: " << timbers.displayPrice() << ":-" << endl;
			getchar();
			break;
		case 5:
			cout << timbers.printTimber();
			cout << "Which Timber do you want to remove? (Type the dimension) ";
			getline(cin, answer);
			if (timbers.removeTimber(answer))
			{
				cout << "Unknown dimension";
				getchar();
			}
			break;
		case 6:
			while (negative)
			{
				cout << timbers.printTimber();
				cout << "Which dimension do you want to change? ";
				getline(cin, answer);
				cout << "What do you want to change?\n1. Running Meter\n2. Price per Running Meter\n";
				cin >> choice; cin.ignore();
				cout << "Enter a value: ";
				cin >> value; cin.ignore();

				if (choice < 1 || choice > 2 || value < 0)
				{
					negative = 1;
				}
				else
				{
					negative = 0;
				}
				for (int i = 0; i < sizeof(answer) && answer[i] != '\0'; i++)
				{
					if (answer[i] == '-')
					{
						negative = 1;
					}
				}
				if (negative)
				{
					cout << "An error occured. Please try again" << endl;
					getchar();
					system("cls");
				}
			}
			timbers.changeProperties(answer, choice, value);
			break;
		case 7:
			cout << "Name your file you want to save: ";
			try
			{
				getline(cin, filename);
				timbers.saveToFile(filename);
				cout << "File successfully saved" << endl;
				getchar();
			}
			catch (const std::exception&)
			{
				cout << "An error occured. Please try again" << endl;
				getchar();
			}
			break;
		case 8:
			cout << "Enter file name: ";
			try
			{
				getline(cin, filename);
				timbers.loadFile(filename);
				cout << "File successfully loaded" << endl;
				getchar();
			}
			catch (const std::exception&)
			{
				cout << "That file doesn't exist. Press Enter to continue" << endl;
				getchar();
			}
			break;
		case 9:
			if (timbers.getNrOfTimber() > 0)
			{
				cout << "Save before closing the program?" << endl;
				getline(cin, answer);
				if (answer == "Y" || answer == "y" || answer == "yes" || answer == "Yes")
				{
					cout << "Name your file you want to save: ";
					do
					{
						try
						{
							getline(cin, filename);
							timbers.saveToFile(filename);
							cout << "File successfully saved";
							getchar();
							success = true;
						}
						catch (const std::exception&)
						{
							cout << "An error occured. Please try again" << endl;
							getchar();
							success = false;
						}
					} while (!success);
				}
			}
			exit = 1;
			break;
		default:
			cout << "Error, invalid option. Please try again!" << endl;
			getchar();
			break;
		}
	}

	cout << "Welcome again!";
	
	getchar();
	return 0;
}