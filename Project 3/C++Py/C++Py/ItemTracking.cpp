#include "ItemTracking.h"
using namespace std;

void ItemTracker::callProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();														// Initialize the Python Interpreter
	PyObject* my_module = PyImport_ImportModule("PyFunctions");				// Build the name object
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();															// Finish the Python Interpreter

	delete[] procname;														// Clean

}

int ItemTracker::callIntFunc(string proc, string param) {
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	Py_Initialize();														
	pName = PyUnicode_FromString((char*)"PyFunctions");						
	pModule = PyImport_Import(pName);										// Load the module object
	pDict = PyModule_GetDict(pModule);										// pDict is a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);							// pFunc is also a borrowed reference 
	if (PyCallable_Check(pFunc)) {
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else {
		PyErr_Print();														//printf("Result is %d\n", _PyLong_AsInt(presult));
	}
	Py_DECREF(pValue);														// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	Py_Finalize();															

	delete[] procname;														 
	delete[] paramval;

	return _PyLong_AsInt(presult);
}

void ItemTracker::readList() {												
	ifstream inFS;															// Input file stream
	inFS.open("frequency.dat");												// Opens frequency.dat
	while (!inFS.eof()) {												    // While eof returns true loop.
		inFS >> itemName;                                                   // Input first string as itemName.
		inFS >> quantity;												    // Input integer after as quantity.
		if (!inFS.fail()) {                                                 // If the stream operation does not fail then:
			cout << left << "   " << setw(15) << itemName << "\033[36m" << string(quantity, '$') << "\033[37m" << endl;
			
		}
	}
	inFS.close();                                                           // Close file when done reading.
}

// Is the PyCall code necessary