//Created by Emil Hallin
//Modified 2019-09-09

#ifndef TIMBERREGISTER_H
#define TIMBERREGISTER_H
#include "Timber.h"

using namespace std;

class TimberRegister
{
private:
	Timber** newTimber;
	int nrOfTimber;
	int timberRegisterCapacity ;

public:
	TimberRegister();
	TimberRegister(const TimberRegister &other);
	~TimberRegister();

	string printTimber();
	string printTimberUnderRunningMetre(const int answer);
	void addTimber(const string dimension, const int runningMetre, const float price);
	void expand();
	void changeProperties(const string dimension, const int choice, const float change);
	void saveToFile(const string filename);
	void loadFile(const string filename);
	float displayPrice() const;
	int getNrOfTimber() const;
	bool removeTimber(const string answer);
	

	TimberRegister& operator=(const TimberRegister &other);
};
#endif // !TIMBERREGISTER_H