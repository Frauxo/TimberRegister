//Created by Emil Hallin
//Modified 2019-09-09

#ifndef TIMBER_H
#define TIMBER_H

#include <string>
using namespace std;

class Timber
{
private:
	string dimension = "";
	int runningMetre = 0;
	float pricePerRunningMetre = 0.0;

public:
	Timber();
	Timber(string dimension, int runningMetre, float pricePerRunningMetre);
	Timber(const Timber &other);
	~Timber();

	void setDimension(const string dimension);
	string getDimesion() const;

	void setRunningMetre(const int runningMetre);
	int getRunningMetre() const;

	void setPricePerRunningMetre(const float pricePerRunningMetre);
	float getPricePerRunningMetre() const;

	bool operator==(const Timber &other) const;
	string toString() const;

};

#endif // !TIMBER_H