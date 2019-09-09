//Emil Hallin
//DV1519 - Inlämningsuppgift A
//2017-02-03

#include <iostream>
#include <fstream>
#include <string>
#include "TimberRegister.h"
#include "Timber.h"
#include <crtdbg.h>

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	string dimension;
	int runningMetre;
	float price;
	int choice = 0;
	string answer;
	int underRM;
	float value;
	string filename;

	TimberRegister timbers;

	cout << "Timber Dimension: ";
	getline(cin, dimension);
	cout << "Running Metre: ";
	cin >> runningMetre; cin.ignore();
	cout << "Price: ";
	cin >> price; cin.ignore();
	timbers.addTimber(dimension, runningMetre, price);

	cout << "Timber Dimension: ";
	getline(cin, dimension);
	cout << "Running Metre: ";
	cin >> runningMetre; cin.ignore();
	cout << "Price: ";
	cin >> price; cin.ignore();
	timbers.addTimber(dimension, runningMetre, price);

	cout << "Timber Dimension: ";
	getline(cin, dimension);
	cout << "Running Metre: ";
	cin >> runningMetre; cin.ignore();
	cout << "Price: ";
	cin >> price; cin.ignore();
	timbers.addTimber(dimension, runningMetre, price);

	cout<< timbers.printTimber();
	cout << "Which Timber do you want to remove? ";
	getline(cin, answer);
	timbers.removeTimber(answer);

	cout << timbers.printTimber();
	cout << "Enter a maximum Running Metre: ";
	cin >> underRM; cin.ignore();
	cout << timbers.printTimberUnderRunningMetre(underRM);

	cout << "Which dimension do you want to change? ";
	getline(cin, answer);
	cout << "What do you want to change?\n1. Running Metre\n2. Price per Running Metre\n";
	cin >> choice; cin.ignore();
	cout << "Enter a value: ";
	cin >> value; cin.ignore();
	timbers.changeProperties(answer, choice, value);
	
	cout << timbers.printTimber();
	cout << "Total price: " << timbers.displayPrice() << ":-" << endl;
	getchar();

	cout << "Name your file you want to save: ";
	getline(cin, filename);
	timbers.saveToFile(filename);

	TimberRegister* timbers2 = new TimberRegister(timbers);

	cout << "timbers2 is printing: " << endl;
	cout <<  timbers2->printTimber();
	getchar();

	delete timbers2;

	TimberRegister timbers3;

	timbers3 = timbers;

	cout << "timbers3 is printing: " << endl;
	cout <<  timbers3.printTimber();

	getchar();
	return 0;
}