#include "stdafx.h"
#ifndef SAVINGS_H
#define SAVINGS_H

class Savings {
private:
	float savings=0;
	bool open = false;

public:
	Savings();
	void openAccount();
	void closeAccount();
	bool checkAccount();
	float getSavings();
	void setSavings(float newSavings);
	void Savings::checkInterest(int years);
	void depositSavings(float deposit);
	void withdrawSavings(float withdrawal);
};

#endif