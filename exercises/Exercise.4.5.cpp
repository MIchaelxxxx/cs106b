/*
 * Implement default extension
 */

#include <iostream>
#include <iomanip>
#include <string>
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
	
	println(defaultExtension2("in/lear1", ".txt"));
	println(defaultExtension2("in/lear1.txt", ".yml"));
	println(defaultExtension2("in/lear1.txt", "*.yml"));
		
	return 0;
}


void println(string str) {
	cout << str << endl;
}
void println(char str) {
	cout << str << endl;
}