/*
 * implement a few convenience and convertion functions
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <math.h>
#include "console.h"
#include "filelib.h"
#include "simpio.h"
#include "error.h"

using namespace std;

int stringToInteger2(string str) {
	stringstream stream(str);
	int val;
	stream >> val >> ws;
	if (stream.fail() || !stream.eof()) { 
		error("stringToInteger2: Illegal integer format");
	}
	return val;
}

string integerToString2(int i) {
	ostringstream stream;
	stream << i;
	return stream.str();
}

string getLine2(string prompt) {
	const char EOL = '\n';
	string line;
	char ch;

	while (line.length() == 0) {
		cout << prompt;
		while ((ch = cin.get()) != EOF) {
			if (cin.fail() || ch == EOL) break;
			line += ch;
		}
	}
	return line;
}


double getReal2(string prompt) {
	double val;
	string input;
	while(true) {
		input = getLine2(prompt);
		istringstream stream(input);
		stream >> fixed >> val;
		if (!stream.fail() || stream.eof()) break;
		cout << "Illegal real format. Try again." << endl;
	}
	return val;	
}


int main() { 
	
	cout << "Casting string to integer: " << stringToInteger2("23") << endl;
	cout << "Casting integer to string: " << integerToString2(23) << endl;
	cout << endl;
	
	double d = getReal2("Please enter a real number: ");
	cout << d << endl;
	
	return 0;
} 

