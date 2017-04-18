#include "stdafx.h"
#include "Savings.h"
#include "Checkings.h"
#include <iostream>
#include <math.h>

/*
Savings Account is a class that stores the balance of the savings account for customers.
It contains get and set functions (each with their own checks) as well as a boolean variable that states whether
or not the account is actually open and available for use.
*/

Savings::Savings() {}

void Savings::openAccount() {
	open = true;
	std::cout << "Your account has been opened" << std::endl;
}

void Savings::closeAccount() {
	if (savings == 0) {
		open = false;
		std::cout << "Your account has been closed." << std::endl;
	}
	else {
		std::cout << "There is still " << savings << " in this account. You cannot close the account unless the balance is $0" << std::endl;
	}
}

bool Savings::checkAccount() {
	return open;
}

float Savings::getSavings() {
	if (checkAccount()==false) {
		std::cout << "You have no open savings account" << std::endl;
		return 0;
	}
	return savings;
}

void Savings::setSavings(float newSavings) {
	if (checkAccount()==false) {
		std::cout << "You have no open savings account" << std::endl;
		return;
	}
	savings = newSavings;
	std::cout << "Your new Savings Account balance is " << savings << std::endl;
}

void Savings::depositSavings(float deposit) {
	if (checkAccount()==false) {
		std::cout << "You have no open savings account" << std::endl;
		return;
	}
	savings += deposit;
	std::cout << "You've deposited " << deposit << " into your Savings Account. You now have " << savings << std::endl;
}

/* 
This is an additional feature that uses the current interest rate today and calculates how much the 
customer's savings will be worth after the user specified number of years
*/

void Savings::checkInterest(int years) {
	float interest = 1.015;
	std::cout << "The current interest rate is: " << interest << std::endl;
	if (checkAccount() == false) {
		std::cout << "You have no open savings account" << std::endl;
		return;
	}
	else {
		std::cout << "Your savings will be worth " << savings*pow(interest,years) << " in " << years << " years" <<std::endl;
	}
}

/*
Much simpler than the checkings withdraw function because it does not have to check if the balance
falls below $1000.
*/

void Savings::withdrawSavings(float withdrawal) {
	if (checkAccount()==false) {
		std::cout << "You have no open savings account" << std::endl;
		return;
	}
	if (withdrawal > savings) {
		std::cout << "You do not have that much money in your Savings Account!" << std::endl;
	}
	else {
		savings -= withdrawal;
		std::cout << "You've withdrawn " << withdrawal << " from your Savings Account. You now have " << savings << std::endl;
	}
}