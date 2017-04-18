#include "stdafx.h"
#ifndef MAINTENANCE_H
#define MAINTENANCE_H
#include <fstream>
#include <string>
#include <iostream>

class Maintenance {
private:
	std::ofstream outputFile;
	bool trace = true;
public:
	Maintenance();
	void traceOn();
	void traceOff();
	void addCustomer();
	void openCheckings();
	void closeCheckings();
	void openSavings();
	void closeSavings();
	void viewAll();
	void viewCustomer();
	void setID();
	void getID();
	void checkCheckings();
	void depositCheckings();
	void withdrawCheckings();
	void checkSavings();
	void depositSavings();
	void withdrawSavings();
	void transferCtoS();
	void transferStoC();
	void transferCtoC();
	void checkInterest();
	void readTrace();
}; 

#endif