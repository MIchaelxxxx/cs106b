/*
 * Remove comments
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


string replaceTabs(string str, int spaces = 8) {
	int pos;
	while ((pos = str.find("\t")) != -1) {
		int d = (((pos / spaces) + 1) * spaces) - pos;
		str.erase(pos, 1);
		str.insert(pos, d, ' ');
	}
	return str;
}



void tabsToSpaces(istream & is, ostream & os) {
	string text;
	string line;
	while (getline(is, line)) {
		if (is.fail()) break;
		text += replaceTabs(line + "\n", 8);
	}
	
	os << text;
	cout << text;
}


int main() { 
	
	ifstream infile; 
	ofstream outfile; 
	
	infile.open("in/tabs.txt");
	outfile.open("out/tabs.txt");	
	tabsToSpaces(infile, outfile);

	
	infile.close();
	outfile.close();
	
	return 0;
} 

