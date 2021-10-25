#include "UserInterface.h"

int main() {
	UserInterface UserObject;												
	int userMenuNum;
	UserObject.displayMenu();
	while (true) {															// While true to get user inputs without exiting until selected from user menu.
		try {																// Define code to be tested.
			userMenuNum = _getch();											// Get input without needing to press enter for the user menu
			userMenuNum = (int)((char)userMenuNum - '0');					// Sets userNum to the expected number input, E.G. 1 will be read as 1.
			UserObject.userController(userMenuNum);							// Call user input function (Swith with cases)
		}
		catch (const std::runtime_error& exception) {						// Execute if runtime error occurs.
			std::cout << "   " << exception.what() << std::endl;			// Terminal output of which runtime error was caught.	
		}
		catch (...) {														// Execute if unexpected error occurs.
			std::cout << "   Unexpected Exception Occured." << std::endl;
		}
	}
	return 0;
}

//What to name this object
