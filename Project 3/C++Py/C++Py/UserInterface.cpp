#include "UserInterface.h"
using namespace std;

string UserInterface::obtainInput() {
	getline(cin, inputStr);
	return inputStr;
}

string UserInterface::validateInput() {
	validInputStr = obtainInput();											// Call obtainInput and assign to temp
	size_t length = validInputStr.length();									// input string length is assigned to unsigned integer length
	for (size_t i = 0; i < length; i++) {									// Iterate length times.
		unsigned char ch = (unsigned char)validInputStr[i]; 				// Assign inputs char to ch for each iteration
		if (isalpha(ch)) {													// If char is alphabetical then
			validInputStr[i] = (i == 0) ? toupper(validInputStr[i]) : tolower(validInputStr[i]);	// Format string to capitalize and lowercase the rest.
		}
		else {
			throw runtime_error("Invalid Item");							// throw runtime error to catch in main
		}
	}
	return validInputStr;
}

void UserInterface::displayMenu() {
	cout << string(20, '*') << " Controls " << string(19, '*') << endl;
	cout << "*  1: Display Quantity of Each Item Purchased   *" << endl;
	cout << "*  2: Search for Quantity of Item               *" << endl;
	cout << "*  3: Display Histogram                         *" << endl;
	cout << "*  4: Exit                                      *" << endl;
	cout << string(49, '*') << endl;
}

void UserInterface::userController(int& userMenuNum) {
	system("CLS");															// Clear terminal.
	displayMenu();															// Call userMenu function
	switch (userMenuNum) {													// Switch using UserMenuNum for case
	case 1:
		callProcedure("DisplayQuantityList");								// Call with parameter DisplayQuantityList for calling python DisplayQuantityList.
		break;																// Exits the case to continue the loop.
	case 2:
		cout << "   Item to search: " << flush;
		cout << right << setw(12) << callIntFunc("ItemSearch", validateInput()) << endl;// Call with parameter IteamSearch for calling python ItemSearch 
		break;																			// passing checkInput as parameter, print quantity.
	case 3:
		callProcedure("DisplayHistogram");
		readList();
		break;
	case 4:
		exit(4);															// Terminates program on input of 4.
	default:																// Default case to ignore userMenuNum if input is not valid.
		throw runtime_error("Invalid Menu Input");
	}
}
