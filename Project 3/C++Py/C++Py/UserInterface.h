#pragma once
#ifndef	USER_INTERFACE_H									// Guards Header prevent redeclaration, redundancy, and recursive inclusion
#define USER_INTERFACE_H									// Defines Header
#include "ItemTracking.h"
#include <conio.h>											// Used for _getch input


class UserInterface : public ItemTracker {
public:
	std::string obtainInput();								// Takes user input as a string and returns string.
	std::string validateInput();							// Validate user input.
	void displayMenu();										// Display to show user menu of inputs printed to terminal.
	void userController(int&);								// Switch for user input controls
private:													// Private class variables.
	std::string inputStr;									// Initial input string.
	std::string validInputStr;								// input string during validation
};
#endif

//Should I implement separate headers and cpp
//Is this handled correctly