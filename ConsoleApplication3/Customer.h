#include "stdafx.h"
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Checkings.h"
#include "Savings.h"

class Customer {
private:
	Checkings checkingsAccount;
	Savings savingsAccount;
	int id=0; 
	int pin;

public:
	Customer();
	void setID(int newID);
	int getID();
	int getPin();
	void setPin(int newPIN);
	void createCheckings();
	void closeCheckings();
	float getCheckings();
	void checkCheckings();
	bool checkCheckingStatus();
	bool checkSavingsStatus();
	void depositCheckings(float deposit);
	void withdrawCheckings(float withdraw);
	void createSavings();
	void closeSavings();
	void checkSavings();
	void depositSavings(float deposit);
	void withdrawSavings(float withdraw);
	void transferStoC(float amount);
	void transferCtoS(float amount);
	void checkInterest(int years);
	void view();
};

#endif