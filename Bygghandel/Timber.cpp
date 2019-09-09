//Created by Emil Hallin
//Modified 2019-09-09

#include <iostream>
#include <string>
#include "Timber.h"

using namespace std;

Timber::Timber()
{
	string dimension = "";
	int runningMetre = 0;
	float pricePerRunningMetre = 0.0;
}

Timber::Timber(string dimension, int runningMetre, float pricePerRunningMetre)
{
	this->dimension = dimension;
	this->runningMetre = runningMetre;
	this->pricePerRunningMetre = pricePerRunningMetre;
}

Timber::Timber(const Timber & other)
{
	this->dimension = other.dimension;
	this->runningMetre = other.runningMetre;
	this->pricePerRunningMetre = other.pricePerRunningMetre;
}

Timber::~Timber()
{
}

void Timber::setDimension(const string dimension)
{
	this->dimension = dimension;
}

string Timber::getDimesion() const
{
	return this->dimension;
}

void Timber::setRunningMetre(const int runningMetre)
{
	this-> runningMetre = runningMetre;
}

int Timber::getRunningMetre() const
{
	return this->runningMetre;
}

void Timber::setPricePerRunningMetre(const float pricePerRunningMetre)
{
	this->pricePerRunningMetre = pricePerRunningMetre;
}

float Timber::getPricePerRunningMetre() const
{
	return this->pricePerRunningMetre;
}

string Timber::toString() const
{
	string returnString = "";

	returnString += "Dimension: "+ this->dimension += "\tRunning Metre: " + to_string(this->runningMetre) += "\tPrice per running meter: " + to_string(this->pricePerRunningMetre);

	return returnString;
}

bool Timber::operator==(const Timber & other) const
{
	bool returnBool = 0;

		if (this->dimension == other.dimension)
		{
			returnBool = 1;
		}

	return returnBool;
}