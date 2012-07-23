/*
 * Banish letters from string
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "console.h"
#include "filelib.h"
#include "simpio.h"
#include "error.h"

using namespace std;

void println(string str);
void println(char str);


std::string defaultExtension2(std::string filename, std::string ext) {
	string root = getRoot(filename);
	string newExt = getExtension(filename);
	
	if(ext[0] == '*') {
		newExt = ext.substr(1);
	}
	
	if(newExt.length() == 0) {
		newExt = ext;
	}
	
	return root + newExt;
}


int main() {
	
	ifstream in;
	ofstream out;
	
	promptUserForFile(in, 'Read from what file?')
}


void println(string str) {
	cout << str << endl;
}
void println(char str) {
	cout << str << endl;
}