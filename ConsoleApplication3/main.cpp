#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Customer.h"
#include "Maintenance.h"
#include "main.h"



int main(){
	//This is a vector that stores all the customers that will use this bank. I used a vector because the size is dynamic (we do not know how many customers there will be)
	std::vector<Customer> customerList;
	Maintenance maintenance;

	//These are just test customers that I used to test all the functions and while loops. This can be done in the program but it saves time to pre-set everything.
	Customer c1, c2, c3;
	c1.setID(100);
	c1.setPin(9211);
	c2.setID(200);
	c2.setPin(1129);
	c3.setID(300);
	c3.setPin(1234);
	customerList.push_back(c1);
	customerList.push_back(c2);
	customerList.push_back(c3);

	std::ofstream executionTrace("ExecutionTrace.txt");
	std::cout << "Hello! Please tell me which of the following you are by using the corresponding number:" << std::endl << "1. A Customer" << std::endl << "2. A Manager" << std::endl <<  "3. Maintenance" << std::endl << "4. Exit" << std::endl;
	int identity;
	std::cin >> identity;
	//This is the main loop. As long as the user does not input 4 (Exit), this loop will continue on. It allows the user to pick what role s/he has at the bank.
	while (identity != 4) {
		//If the user picks that s/he is a customer
		if (identity == 1) { 
			//Asks for the user's 3 digit ID and stores it in a variable 
			std::cout << "Please input your 3 digit ID. Type 0 to exit." << std::endl;
			int customerID=-1;
			std::cin >> customerID;
			//This variable is used to check whether or not the user has inputted 0, which is to exit instead of a 3 digit ID.
			bool exit = false;
			int listLocation;
			if (customerID == 0) {
				exit = true;
			}
			while (exit != true) {
				//This variable is used to check whether or not the bank can find the ID given. It it has, then it moves on and if not, then it loops back to ask for input again. 
				bool found = false;
				bool correctPass = false;
				while (found == false) {
					for (int i = 0; i < customerList.size(); i++) {
						if (customerID == customerList[i].getID()) {
							found = true;
							int pass;
							int count = 0;
							std::cout << "Please input your 4-digit PIN" << std::endl;
							std::cin >> pass;
							//This checks to make sure the user has inputted the correct password. It also limits the password attempts to 3. 
							while ((correctPass == false) && (count < 2)) {
								if (customerList[i].getPin() == pass) {
									correctPass = true;
								}
								else {
									count++;
									std::cout << "Incorrect Pin! Please input your 4-digit PIN. You have " << 3-count << " tries left" << std::endl;
									std::cin >> pass;
								}
							}
							if (correctPass == true) {
								std::cout << "You are now logged in with the ID: " << customerID << std::endl;
								listLocation = i;
							}
						}
					}
					if ((found==true) &&(correctPass == false)) {
						std::cout << "Failed PIN Too Many Times" << std::endl;
					}
					else if ((found == true) && (correctPass == true)){}
					else {
						std::cout << "Incorrect ID. Please input your 3 digit ID." << std::endl;
						std::cin >> customerID;
					}
				}
				//At this point the ID has been found and you are now logged in. You are presented with a few options.
				int customerChoice = 6;
				if ((found == true) && (correctPass == true)) {
					std::cout << "Please tell me what you would like to do :" << std::endl << "1. Check Balance" << std::endl << "2. Withdraw" << std::endl << "3. Deposit " << std::endl << "4. Transfer" << std::endl << "5. Check Interest on Savings" << std::endl << "6. Exit" << std::endl;
					std::cin >> customerChoice;
				}
				//As long as the customer does not input 5 (Exit), this loop will run. 
				while ((customerChoice != 6) && (found == true) && (correctPass==true)) {
					if (customerChoice == 1) {
						//Asks customer if s/he wants to check the balance of checkings or savings
						std::cout << "1. Checkings" << std::endl << "2. Savings" << std::endl << "3. Exit" << std::endl;
						int cors;
						std::cin >> cors;
						//Runs until the customer decides s/he is done with checking balances
						while (cors !=3) {
							if (cors == 1) {
								customerList[listLocation].checkCheckings();
								maintenance.checkCheckings();

							}
							else if (cors == 2) {
								customerList[listLocation].checkSavings();
								maintenance.checkSavings();
							}
							
							std::cout << "1. Checkings" << std::endl << "2. Savings" << std::endl << "3. Exit" << std::endl;
							std::cin >> cors;
						}
					}
					//Asks customer if s/he wants to withdraw from checkings or savings
					else if (customerChoice == 2) {
						std::cout << "1. Checkings" << std::endl << "2. Savings" << std::endl << "3. Exit" << std::endl;
						int cors;
						std::cin >> cors;
						//Runs until the customer decides s/he is done with withdrawals
						while (cors != 3) {
							std::cout << "How much would you like to withdraw? Please input positive float values:" << std::endl;
							float withdrawal;
							std::cin >> withdrawal;
							if (cors == 1) {
								customerList[listLocation].withdrawCheckings(withdrawal);
								maintenance.withdrawCheckings();
							}
							else if (cors == 2) {
								customerList[listLocation].withdrawSavings(withdrawal);
								maintenance.withdrawSavings();
								
							}
							
							std::cout << "1. Checkings" << std::endl << "2. Savings" << std::endl << "3. Exit" << std::endl;
							std::cin >> cors;
						}
					}
					//Asks customer if s/he wants to deposit to checkings or savings
					else if (customerChoice == 3) {
						std::cout << "1. Checkings" << std::endl << "2. Savings" << std::endl << "3. Exit" << std::endl;
						int cors;
						std::cin >> cors;
						//Runs until the customer decides s/he is done with deposits 
						while (cors != 3) {
							std::cout << "How much would you like to deposit? Please input positive float values:" << std::endl;
							float deposit;
							std::cin >> deposit;
							if (cors == 1) {
								customerList[listLocation].depositCheckings(deposit);
								maintenance.depositCheckings();
							}
							else if (cors == 2) {
								customerList[listLocation].depositSavings(deposit);
								maintenance.depositSavings();

							}
							
							std::cout << "1. Checkings" << std::endl << "2. Savings" << std::endl << "3. Exit" << std::endl;
							std::cin >> cors;
						}
					}

					else if (customerChoice == 4) {
						//Asks customer if s/he wants to transfer from checkings to savings or savings to checkings
						std::cout << "1. Checkings to Savings" << std::endl << "2. Savings to Checkings" << std::endl << "3. Checkings to Other Account Checkings" << std::endl << "4. Exit" << std::endl;
						int cors;
						std::cin >> cors;
						//Runs until the customer decides s/he is done with transfers
						while (cors != 4) {
							std::cout << "How much would you like to transfer? Please input positive float values:" << std::endl;
							float amount;
							std::cin >> amount;
							if (cors == 1) {
								customerList[listLocation].transferCtoS(amount);
								maintenance.transferCtoS();
								
							}
							else if (cors == 2) {
								customerList[listLocation].transferStoC(amount);
								maintenance.transferStoC();
							}
							//This is an extra that allows users to transfer money from their checkings into another customer's checkings
							else if (cors == 3) {
								std::cout << "Please input 3 digit ID of customer you want to transfer money to." << std::endl;
								int customerID;
								std::cin >> customerID;
								bool found = false;
								bool exit = false;
								int otherLocation;
								while ((found == false) && (exit == false)) {
									for (int i = 0; i < customerList.size(); i++) {
										if (customerID == customerList[i].getID()) {
											found = true;
											otherLocation = i;
										}
										if (found == false) {
											std::cout << "Invalid ID. Please input 3 digit ID of customer you want to transfer money to. Input 0 to exit." << std::endl;
											std::cin >> customerID;
										}
										else if (otherLocation == listLocation) {
											std::cout << "You cannot input your own ID. Please input 3 digit ID of customer you want to transfer money to. Input 0 to exit. " << std::endl;
											std::cin >> customerID;
											found = false;
										}
										if (customerID == 0) {
											exit = true;
										}
									}
								}
								//Checks to make sure that the customer you wish to transfer money to has an open checkings account
								if (customerList[otherLocation].checkCheckingStatus() == false) {
									std::cout << "The customer ID you inputted does not have an open checkings account" << std::endl;
								}
								//This is a check for when a withdrawal will place your checkings account under $1000. If it does and you say no to the surcharge, it will make sure that the other person's account will not gain any funds.
								else {
									float initAmount;
									initAmount = customerList[listLocation].getCheckings();
									customerList[listLocation].withdrawCheckings(amount);
									if (customerList[listLocation].getCheckings() != initAmount) {
										customerList[otherLocation].depositCheckings(amount);
										maintenance.transferCtoC();
									}

								}
							}
							
							std::cout << "1. Checkings to Savings" << std::endl << "2. Savings to Checkings" << std::endl << "3. Checkings to Other Account Checkings" << std::endl << "4. Exit" << std::endl;
							std::cin >> cors;
						}
					}

					else if (customerChoice == 5) {
						int years;
						std::cout << "How many years of interest would you like to check for? Please input an integer: " << std::endl;
						std::cin >> years;
						customerList[listLocation].checkInterest(years);
						maintenance.checkInterest();
					}

					else {
						std::cout << "Invalid Input" << std::endl;
					}

					std::cout << "Please tell me what you would like to do :" << std::endl << "1. Check Balance" << std::endl << "2. Withdraw" << std::endl << "3. Deposit " << std::endl << "4. Transfer" << std::endl << "5. Check Interest on Savings" << std::endl << "6. Exit" << std::endl;
					std::cin >> customerChoice;
					
				}

				std::cout << "Please input your 3 digit ID. Type 0 to exit." << std::endl;
				std::cin >> customerID;
				if (customerID == 0) {
					exit = true;
				}
			}

		}
		//If the user picks that s/he is the manager
		else if (identity == 2) {
			//Displays the options for the manager
			std::cout << "Please tell me what you would like to do:" << std::endl << "1. Add Customer" << std::endl << "2. Open Checkings Account" << std::endl << "3. Open Savings Account" << std::endl << "4. Close Checkings Account" << std::endl << "5. Close Savings Account" << std::endl << "6. View Single Customer Data" << std::endl << "7. View All Customer Data" << std::endl << "8. Exit \n" << std::endl;
			int customerChoice;
			std::cin >> customerChoice;
			//As long as the manager does not input 8 (Exit), this loop will continue on.
			while (customerChoice != 8) {
				//Manager wants to add a new customer to the system
				if (customerChoice == 1) {
					std::cout << "Please Input New 3 Digit Customer ID:" << std::endl;
					int id;
					std::cin >> id;
					std::cout << "Please Input New 4-Digit PIN" << std::endl;
					int pin;
					std::cin >> pin;
					bool inList = false;
					//Checks to see whether or not the new ID presented is already in the list or not (as IDs have to be unique)
					//If it is, it will not add the new customer.
					for (int i = 0; i < customerList.size(); i++) {
						if (id == customerList[i].getID()) {
							std::cout << "There is already a customer with that customer ID." << std::endl;
							inList = true;
						}
					}
					if (inList = true) {}
					else {
						Customer newCustomer;
						newCustomer.setID(id);
						newCustomer.setPin(pin);
						customerList.push_back(newCustomer);
					}
				}
				//Manager wants to open a customer's checking account
				else if (customerChoice == 2) {
					std::cout << "Please Input 3 Digit Customer ID:" << std::endl;
					int id;
					int listLocation;
					std::cin >> id;
					bool inList = false;
					//Finds the ID and opens the checkings account. If it cannot find it, it will return an error message
					for (int i = 0; i < customerList.size(); i++) {
						if (id == customerList[i].getID()) {
							inList = true;
							listLocation = i;
						}
					}
					if (inList = true) {
						customerList[listLocation].createCheckings();
						maintenance.openCheckings();
					}

					else {
						std::cout << "ID Not Found" << std::endl;
					}
				}
				//Manger wants to open a customer's savings account 
				else if (customerChoice == 3) {
					std::cout << "Please Input 3 Digit Customer ID:" << std::endl;
					int id;
					int listLocation;
					std::cin >> id;
					bool inList = false;
					//Finds the ID and opens the savings account. If it cannot find it, it will return an error message
					for (int i = 0; i < customerList.size(); i++) {
						if (id == customerList[i].getID()) {
							inList = true;
							listLocation = i;
						}
					}
					if (inList = true) {
						customerList[listLocation].createSavings();
						maintenance.openSavings();
					}

					else {
						std::cout << "ID Not Found" << std::endl;
					}
				}
				//Manager wants to close a customer's checkings account
				else if (customerChoice == 4) {
					std::cout << "Please Input 3 Digit Customer ID:" << std::endl;
					int id;
					int listLocation;
					std::cin >> id;
					bool inList = false;
					//Finds the ID and closes the checkings account. If it cannot find it, it will return an error message

					for (int i = 0; i < customerList.size(); i++) {
						if (id == customerList[i].getID()) {
							inList = true;
							listLocation = i;
						}
					}
					if (inList = true) {
						customerList[listLocation].closeCheckings();
						maintenance.closeCheckings();
					}

					else {
						std::cout << "ID Not Found" << std::endl;
					}
				}
				//Manager wants to close a customer's savings account
				else if (customerChoice == 5) {
					std::cout << "Please Input 3 Digit Customer ID:" << std::endl;
					int id;
					int listLocation;
					std::cin >> id;
					bool inList = false;
					//Finds the ID and closes the savings account. If it cannot find it, it will return an error message
					for (int i = 0; i < customerList.size(); i++) {
						if (id == customerList[i].getID()) {
							inList = true;
							listLocation = i;
						}
					}
					if (inList = true) {
						customerList[listLocation].closeSavings();
						maintenance.closeSavings();
					}

					else {
						std::cout << "ID Not Found" << std::endl;
					}
				}
				//Manager wants to view a specific customer's information
				else if (customerChoice == 6) {
					std::cout << "Please Input 3 Digit Customer ID:" << std::endl;
					int id;
					int listLocation;
					std::cin >> id;
					bool inList = false;
					for (int i = 0; i < customerList.size(); i++) {
						if (id == customerList[i].getID()) {
							inList = true;
							listLocation = i;
						}
					}
					if (inList = true) {
						customerList[listLocation].view();
						maintenance.viewCustomer();
					}

					else {
						std::cout << "ID Not Found" << std::endl;
					}
				}
				//Manager wants to view all customer's information
				else if (customerChoice == 7) {
					for (int i = 0; i < customerList.size(); i++) {
						customerList[i].view();
					}
					maintenance.viewAll();
				}

				else {
					std::cout << "Invalid Choice" << std::endl;
				}

				std::cout << "Please tell me what you would like to do:" << std::endl << "1. Add Customer" << std::endl << "2. Open Checkings Account" << std::endl << "3. Open Savings Account" << std::endl << "4. Close Checkings Account" << std::endl << "5. Close Savings Account" << std::endl << "6. View Single Customer Data" << std::endl << "7. View All Customer Data" << std::endl << "8. Exit \n" << std::endl;
				std::cin >> customerChoice;

			}

		}
		//If the user picks that s/he is maintenance
		else if (identity == 3) {
			std::cout << "Please tell me what you would like to do :" << std::endl << "1. Turn On Trace" << std::endl << "2. Turn Off Trace" << std::endl << "3. Print Trace" << std::endl << "4. Exit" << std::endl;
			int customerChoice;
			std::cin >> customerChoice;
			//As long as maintenance does not input 4 (Exit), this loop will continue on.
			while (customerChoice != 4) {
				//Maintenance wants to turn on the trace
				if (customerChoice == 1) {
					maintenance.traceOn();
				}
				//Maintenance wants to turn off the trace
				else if (customerChoice == 2) {
					maintenance.traceOff();
				}
				//Maintenance wants to print the trace
				else if (customerChoice == 3) {
					maintenance.readTrace();
				}
				else {
					std::cout << "Invalid Choice" << std::endl;
				}

				std::cout << "Please tell me what you would like to do :" << std::endl << "1. Turn On Trace" << std::endl << "2. Turn Off Trace" << std::endl << "3. Print Trace" << std::endl << "4. Exit" << std::endl;
				std::cin >> customerChoice;
			}

		}

		else {
			std::cout << "Invalid Choice" << std::endl;
		}
		
		std::cout << "Hello! Please tell me which of the following you are by using the corresponding number:" << std::endl << "1. A Customer" << std::endl << "2. A Manager" << std::endl << "3. Maintenance" << std::endl << "4. Exit" << std::endl;
		std::cin >> identity;
		
	}

	return 0;

}

