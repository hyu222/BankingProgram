#include "stdafx.h"
#include "Maintenance.h"
#include <time.h>

/*
The maintenance class contains the methods that will be called in order to add to the ExecutionTrace.txt file.
The ExecutionTrace.txt file tracks all activity at the bank. It can only be turned off by maintenance and the 
contents can only be read if you're maintenance as well.
*/

const std::string currentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
	return buf;
}


Maintenance::Maintenance() : outputFile("ExecutionTrace.txt") {}

void Maintenance::traceOn() {
	if (trace == true) {
		std::cout << "Trace already on" << std::endl;
	}
	else {
		trace = true;
		std::cout << "Trace On" << std::endl;
	}
}

void Maintenance::traceOff() {
	if (trace == false) {
		std::cout << "Trace already off" << std::endl;
	}
	else {
		trace = false;
		std::cout << "Trace Off" << std::endl;
	}
}

void Maintenance::addCustomer() {
	if (trace) {
		outputFile << "Added Customer" << currentDateTime() << std::endl;

	}
}
void Maintenance::openCheckings() {
	if (trace) {
		outputFile << "Opened Checkings Account " << currentDateTime() << std::endl;
	}
}
void Maintenance::closeCheckings() {
	if (trace) {
		outputFile << "Closed Checkings Account" << currentDateTime() << std::endl;
	}
}
void Maintenance::openSavings() {
	if (trace) {
		outputFile << "Opened Savings Account" << currentDateTime() << std::endl;
	}
}
void Maintenance::closeSavings() {
	if (trace) {
		outputFile << "Closed Savings Account" << currentDateTime() << std::endl;
	}
}
void Maintenance::viewAll() {
	if (trace) {
		outputFile << "Viewed All Customer Information" << currentDateTime() << std::endl;
	}
}
void Maintenance::viewCustomer() {
	if (trace) {
		outputFile << "Viewed A Customer's Information" << currentDateTime() << std::endl;
	}
}
void Maintenance::setID() {
	if (trace) {
		outputFile << "Set a Customer ID" << currentDateTime() << std::endl;
	}
}
void Maintenance::getID() {
	if (trace) {
	outputFile << "Got a Customer's ID" << currentDateTime() << std::endl;
	}
}

void Maintenance::checkCheckings() {
	if (trace) {
		outputFile << "Checked Balance of Checkings Account" << currentDateTime() << std::endl;
	}
}
void Maintenance::depositCheckings() {
	if (trace) {
		outputFile << "Deposited Into Checkings Account" << currentDateTime() << std::endl;
	}
}
void Maintenance::withdrawCheckings() {
	if (trace) {
		outputFile << "Withdrew From Checkings Account" << currentDateTime() << std::endl;
	}
}

void Maintenance::checkSavings() {
	if (trace) {
		outputFile << "Checked Balance of Savings Account" << currentDateTime() << std::endl;
	}
}
void Maintenance::depositSavings() {
	if (trace) {
		outputFile << "Deposited Into Savings Account" << currentDateTime() << std::endl;
	}
}
void Maintenance::withdrawSavings() {
	if (trace) {
		outputFile << "Withdrew From Savings Account" << currentDateTime() << std::endl;
	}
}

void Maintenance::transferCtoS() {
	if (trace) {
		outputFile << "Transfer from Checkings to Savings" << currentDateTime() << std::endl;
	}
}

void Maintenance::transferStoC() {
	if (trace) {
		outputFile << "Transfer from Savings to Checkings" << currentDateTime() << std::endl;
	}
}

void Maintenance::transferCtoC() {
	if (trace) {
		outputFile << "Transfer from Checkings to Another Customer's Checkings" << currentDateTime() << std::endl;
	}
}

void Maintenance::checkInterest() {
	if (trace) {
		outputFile << "Checked Interest" << currentDateTime() << std::endl;
	}
}

void Maintenance::readTrace() {
	std::string input;
	std::ifstream inputFile("ExecutionTrace.txt");
	while (std::getline(inputFile, input)) {
		std::cout << input << std::endl;
	}
}