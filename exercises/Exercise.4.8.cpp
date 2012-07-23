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
#include <algorithm>
using namespace std;

string removeLetters(string str, string letters) {
	char c;
	int p;
	for (int i = 0; i < letters.length(); i++) {
		c = letters[i];
		while ((p = str.find(c)) != -1) {
			str.erase(p, 1);
		}
	}
	return str;
}

int main() { 

	string txt;
	
	ifstream infile; 
	ofstream outfile; 
	
	promptUserForFile(infile, "Input file: "); 
	
	char c;
	while ((c = infile.get()) != EOF) {
		if (infile.fail()) break;
		txt += c;
	}
	infile.close();


	promptUserForFile(outfile, "Output file: "); 
	
	string letters = getLine("Letters: ");
	string cleaned = removeLetters(txt, letters);
	
	outfile << cleaned;
	outfile.close();
							 
	cout << cleaned;
	
	return 0;
} 

