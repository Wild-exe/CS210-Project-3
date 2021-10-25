#pragma once
#ifndef ITEM_TRACKING_H										// Guards Header prevent redeclaration, redundancy, and recursive inclusion
#define ITEM_TRACKING_H										// Defines Header
#include <Python.h>											// Used to incorporate python
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>                                          // For reading and writing to file.
#include <iomanip>											// For formating the histogram

class ItemTracker {											// Class declaration
public:
	void callProcedure(std::string);						// Handles python functions with python function name
	int callIntFunc(std::string, std::string);				// Handles python functions with python function name and string parameter
	void readList();										// Reads frequency.dat and prints to terminal
	
private:													// Private class variables.
	std::string itemName = "NoName";                        // Variable for item name assigns noName.
	int quantity = -1;                                      // Variable for quantity of itemName assigns -1.
};
#endif