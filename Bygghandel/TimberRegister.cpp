//Created by Emil Hallin
//Modified 2019-09-09

#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include "TimberRegister.h"

TimberRegister::TimberRegister()
{
	this->nrOfTimber = 0;
	this->timberRegisterCapacity = 2;

	this->newTimber = new Timber*[timberRegisterCapacity];

	for (int i = 0; i < timberRegisterCapacity; i++)
	{
		newTimber[i] = nullptr;
	}
}

TimberRegister::TimberRegister(const TimberRegister & other)
{
	this->timberRegisterCapacity = other.timberRegisterCapacity;
	this->nrOfTimber = other.nrOfTimber;

	newTimber = new Timber*[timberRegisterCapacity];
	
	if (other.newTimber)
	{
		for (int i = 0; i < nrOfTimber; i++)
		{
			if (other.newTimber[i])
			{
				Timber* newTimberRegister = new Timber(other.newTimber[i]->getDimesion(), other.newTimber[i]->getRunningMetre(), other.newTimber[i]->getPricePerRunningMetre());
				this->newTimber[i] = newTimberRegister;
			}
			else
			{
				this->newTimber[i] = nullptr;
			}
		}
	}
}

TimberRegister::~TimberRegister()
{
	for (int i = 0; i < this->nrOfTimber; i++)
	{
		delete this->newTimber[i];
	}
	delete[] this->newTimber;
}

void TimberRegister::addTimber(const string dimension, const int runningMetre, const float price)
{
	int checkException = 0;
	if (nrOfTimber == timberRegisterCapacity)
	{
		expand();
	}

	this->newTimber[nrOfTimber] = new Timber(dimension, runningMetre, price);
	nrOfTimber++;

	if (nrOfTimber > 1)
	{
		for (int i = 0; i < nrOfTimber - 1; i++)
		{
			if (*this->newTimber[i] == *this->newTimber[nrOfTimber - 1] && !checkException)
			{
				delete newTimber[nrOfTimber - 1];
				nrOfTimber--;
				checkException = 1;
			}
		}
	}
}

bool TimberRegister::removeTimber(const string answer)
{
	bool returnBool = 1;

	for (int i = 0; i < nrOfTimber; i++)
	{
		if(answer == newTimber[i]->getDimesion())
		{
			delete this->newTimber[i];
			this->newTimber[i] = this->newTimber[nrOfTimber - 1];
			nrOfTimber--;
			returnBool = 0;
		}
	}
	return returnBool;
}

string TimberRegister::printTimber()
{
	string returnString;
	
	returnString = "";

	for (int i = 0; i < nrOfTimber; i++)
	{
		returnString += this->newTimber[i]->toString() += "\n";
	}
	return returnString;
}

string TimberRegister::printTimberUnderRunningMetre(const int answer)
{
	string returnString;
	returnString = "";

	for (int i = 0; i < nrOfTimber; i++)
	{
		if (newTimber[i]->getRunningMetre() <= answer)
		{
			returnString += newTimber[i]->toString() += "\n";
		}
	}
	return returnString;
}

void TimberRegister::expand()
{
	int timberTemp = timberRegisterCapacity;
	timberRegisterCapacity += 1;

	Timber** timberExpand = new Timber*[timberRegisterCapacity];

	for (int i = 0; i < timberRegisterCapacity; i++)
	{
		if (i <= timberTemp - 1)
		{
			timberExpand[i] = new Timber(this->newTimber[i]->getDimesion(), this->newTimber[i]->getRunningMetre(), this->newTimber[i]->getPricePerRunningMetre());
		}
		else
		{
			timberExpand[i] = nullptr;
		}
	}

	for (int i = 0; i < timberTemp; i++)
	{
		delete newTimber[i];
	}
	delete[] newTimber;

	newTimber = timberExpand;
}

void TimberRegister::changeProperties(const string dimension, const int choice, const float change)
{
	for (int i = 0; i < nrOfTimber; i++)
	{
		if (newTimber[i]->getDimesion() == dimension)
		{
			if (choice == 1)
			{
				newTimber[i]->setRunningMetre((int)change);
			}
			else if (choice == 2)
			{
				newTimber[i]->setPricePerRunningMetre(change);
			}
		}
	}
}

float TimberRegister::displayPrice() const
{
	float price = 0.0;

	for (int i = 0; i < nrOfTimber; i++)
	{
		price += newTimber[i]->getRunningMetre() * newTimber[i]->getPricePerRunningMetre();
	}
	return price;
}

int TimberRegister::getNrOfTimber() const
{
	return this->nrOfTimber;
}

void TimberRegister::saveToFile(const string filename)
{
	ofstream out;
	out.open(filename + ".txt");

	out << printTimber();

	out.close();
}

void TimberRegister::loadFile(const string filename)
{
	//First we need to make sure the register empties out before filling it up.
	int tempCounter = nrOfTimber;
	for (int i = 0; i < tempCounter; i++)
	{
		delete this->newTimber[i];
		nrOfTimber--;
	}

	//Then we read in the file.
	ifstream in;
	in.open(filename + ".txt");

	string dimension;
	string runningMetre;
	string price;

	int runningMetreConvert = 0;
	float priceConvert = 0.0;

	//There might be a better solution to this loop, but this is the solution I could come up on the spot.
	while (!in.eof())
	{
		in >> dimension;
		in >> dimension;		

		in >> runningMetre;
		in >> runningMetre;
		in >> runningMetre;

		in >> price;
		in >> price;
		in >> price;
		in >> price;
		in >> price;

		runningMetreConvert = stoi(runningMetre);
		priceConvert = stof(price);

		addTimber(dimension, runningMetreConvert, priceConvert);

		in.ignore();
	}
	in.close();
}

TimberRegister & TimberRegister::operator=(const TimberRegister & other)
{
	this->timberRegisterCapacity = other.timberRegisterCapacity;
	this->nrOfTimber = other.nrOfTimber;

	for (int i = 0; i < this->nrOfTimber - 1; i++)
	{
		delete this->newTimber[i];
		newTimber[i] = nullptr;
	}
	delete[] this->newTimber;

	this->newTimber = new Timber*[timberRegisterCapacity];

	if (other.newTimber)
	{
		for (int i = 0; i < nrOfTimber; i++)
		{
			if (other.newTimber[i])
			{
				Timber* newTimberRegister = new Timber(other.newTimber[i]->getDimesion(), other.newTimber[i]->getRunningMetre(), other.newTimber[i]->getPricePerRunningMetre());
				this->newTimber[i] = newTimberRegister;
			}
			else
			{
				this->newTimber[i] = nullptr;
			}
		}
	}
	return *this;
}