#include "stdafx.h"
#include "Checkings.h"
#include "Savings.h"
#include <iostream>

/* 
Checkings Account is a class that stores the balance of the checkings account for customers.
It contains get and set functions (each with their own checks) as well as a boolean variable that states whether
or not the account is actually open and available for use. 
*/
Checkings::Checkings() {}

void Checkings::openAccount() {
	open = true;
	std::cout << "Your account has been opened" << std::endl;
}

void Checkings::closeAccount() {
	if (checkings == 0) {
		open = false;
		std::cout << "Your account has been closed." << std::endl;
	}
	else {
		std::cout << "There is still " << checkings << " in this account. You cannot close the account unless the balance is $0" << std::endl;
	}
}

bool Checkings::checkAccount() {
	return open;
}

float Checkings::getCheckings() {
	if (checkAccount()==false) {
		std::cout << "You have no open checkings account" << std::endl;
		return 0;
	}
	return checkings;
}

void Checkings::setCheckings(float newCheckings) {
	if (checkAccount()==false) {
		std::cout << "You have no open checkings account" << std::endl;
		return;
	}
	checkings = newCheckings;
	std::cout << "Your new Checkings Account Balance is" << checkings << std::endl;
}

void Checkings::depositCheckings(float deposit) {
	if (checkAccount()==false) {
		std::cout << "You have no open checkings account" << std::endl;
		return;
	}
	checkings += deposit;
	std::cout << "You've deposited " << deposit << " into your Checkings Account" << std::endl;
}

/*
This method is a little more complicated than the others because there is an additional check. First, we have to check whether or not there is enough 
in the checkings account to withdraw, but then we also have to check whether the withdrawal will place the balance below 1000 (as this will introduce a surcharge).
If it does, the user will be prompted as to whether or not s/he wants to pay the surcharge.
*/

void Checkings::withdrawCheckings(float withdrawal) {
	if (checkAccount()==false) {
		std::cout << "You have no open checkings account" << std::endl;
		return;
	}
	if (withdrawal > checkings) {
		std::cout << "You do not have that much money in your Checkings Account!" << std::endl;
	}
	else if ((checkings >= 1000) && (withdrawal - checkings < 1000)) {
		std::cout << "This will place your Checkings balance below $1000. This will result in a $2.00 charge. Do you agree to this?" << std::endl << "1. Yes" << std::endl << "2. No" << std::endl;
		int response;
		std::cin >> response;
		if (response == 1) {
			float surcharge = 2.00;
			checkings -= withdrawal;
			checkings -= surcharge;
			std::cout << "You've withdrawn " << withdrawal << " from your Checkings Account. You now have " << checkings << std::endl;
		}
		else {
			std::cout << "You have chosen not to withdraw from your Checkings Account" << std::endl;
		}
	}
	else {
		checkings -= withdrawal;
		std::cout << "You've withdrawn " << withdrawal << " from your Checkings Account. You now have " << checkings << std::endl;
	}
}