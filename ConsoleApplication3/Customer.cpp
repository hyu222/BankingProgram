#include "stdafx.h"
#include "Customer.h"
#include <iostream>
#include <fstream>
#include <string>

/* 
The Customer class stores all the information for the customers of the bank. This includes their unique ID, their savings account, and their checkings account. 
It also includes the appropriate get/set methods for the information (a lot of which use the get/set methods from the individual account classes. 
*/

Customer::Customer() {}
void Customer::setID(int newID) {
	id = newID;
}
int Customer::getID() {
	return id;
}

int Customer::getPin() {
	return pin;
}

void Customer::setPin(int newPIN) {
	pin = newPIN; 
}

float Customer::getCheckings() {
	return checkingsAccount.getCheckings();
}
void Customer::createCheckings() {
	if (checkingsAccount.checkAccount() == true) {
		std::cout << "There is already a checkings account open " << std::endl;
		return;
	}
	float newCheckingsAmount = 0.00;
	checkingsAccount.setCheckings(newCheckingsAmount);
	checkingsAccount.openAccount();
}

bool Customer::checkCheckingStatus() {
	return checkingsAccount.checkAccount();
}

bool Customer::checkSavingsStatus() {
	return savingsAccount.checkAccount();
}

void Customer::closeCheckings() {
	if (checkingsAccount.checkAccount() == false) {
		std::cout << "There is no open checkings account " << std::endl;
		return;
	}
	checkingsAccount.closeAccount();
}

void Customer::checkCheckings() {
	std::cout << checkingsAccount.getCheckings() << std::endl;

}

void Customer::depositCheckings(float deposit) {
	checkingsAccount.depositCheckings(deposit);
}

void Customer::withdrawCheckings(float withdraw) {
	checkingsAccount.withdrawCheckings(withdraw);
} 

void Customer::createSavings() {
	if (savingsAccount.checkAccount() == true) {
		std::cout << "There is already a savings account open" << std::endl;
		return;
	}
	float newSavingsAmount = 0.00;
	savingsAccount.setSavings(newSavingsAmount);
	savingsAccount.openAccount();
}

void Customer::closeSavings() {
	if (savingsAccount.checkAccount() == false) {
		std::cout << "There is no open savings account" << std::endl;
		return;
	}
	savingsAccount.closeAccount();
}

void Customer::checkSavings() {
	std::cout << savingsAccount.getSavings() << std::endl;

}

void Customer::depositSavings(float deposit) {
	savingsAccount.depositSavings(deposit);
}

void Customer::withdrawSavings(float withdraw) {
	savingsAccount.withdrawSavings(withdraw);
}
//This function is used to transfer money from a customer's savings account to his/her checkings account
//If checks whether or not there is enough money in the savings account to transfer the desired amount
//and then transfers the funds if both accounts are open.
void Customer::transferStoC(float amount) {
	if (savingsAccount.getSavings() < amount) {
		std::cout << "You do not have enough in your Savings Account" << std::endl;
		return;
	}
	else if (savingsAccount.checkAccount() == false) {
		std::cout << "You do not have a Savings Account open" << std::endl;
	}
	else if (checkingsAccount.checkAccount() == false) {
		std::cout << "You do not have a Checkings Account open" << std::endl;
	}

	else {
		savingsAccount.withdrawSavings(amount);
		checkingsAccount.depositCheckings(amount);
	}
}
//This function is used to transfer money from a customer's checking account to his/her savings account
//There is an additional check in this one because withdrawing from the checkings account has the additional rule
//of sub $1000 balances. It checks to make sure the customer actually agreed to withdraw the money. It will only transfer 
//if the customer agreed to the surcharge. 
void Customer::transferCtoS(float amount) {
	if (checkingsAccount.getCheckings() < amount) {
		std::cout << "You do not have enough in your Checkings Account" << std::endl;
		return;
	}
	else if (savingsAccount.checkAccount() == false) {
		std::cout << "You do not have a Savings Account open" << std::endl;
	}
	else if (checkingsAccount.checkAccount() == false) {
		std::cout << "You do not have a Checkings Account open" << std::endl;
	}

	else {
		float initAmount;
		initAmount = checkingsAccount.getCheckings();
		checkingsAccount.withdrawCheckings(amount);
		if (checkingsAccount.getCheckings() != initAmount) {
			savingsAccount.depositSavings(amount);
		}
	}
}

void Customer::checkInterest(int years) {
	savingsAccount.checkInterest(years);
}

//This function is used to view all customer data.
void Customer::view() {
	std::cout << "Customer ID: " << id << std::endl;
	if (checkingsAccount.checkAccount() == true) {
		std::cout << "Checking Account Information: Open with " << checkingsAccount.getCheckings() << std::endl;
	}
	else {
		std::cout << "Checking Account Information: Closed" << std::endl;
	}
	if (savingsAccount.checkAccount() == true) {
		std::cout << "Savings Account Information: Open with " << savingsAccount.getSavings() << std::endl;
	}
	else {
		std::cout << "Savings Account Information: Closed" << std::endl;
	}
}