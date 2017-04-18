#include "stdafx.h"
#ifndef CHECKINGS_H
#define CHCEKINGS_H

class Checkings {
private:
	float checkings=0;
	bool open = false;
public: 
	Checkings();
	void openAccount();
	void closeAccount();
	bool checkAccount();
	float getCheckings();
	void setCheckings(float newCheckings);
	void depositCheckings(float deposit);
	void withdrawCheckings(float withdrawal);
};

#endif