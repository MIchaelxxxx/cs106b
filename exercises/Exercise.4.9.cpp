/*
 * Remove comments
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

bool removeOccurance(string & str, string start, string end) {
	int a, b;
	if ((a = str.find(start)) != -1) {
		if ((b = str.find(end, a)) != -1) {
			str.erase(a, (b-a) + end.length());
			return true;
		}
	}
	return false;
}

void removeComments(istream & is, ostream & os) {
	string text;
	char ch;
	while ((ch = is.get()) != EOF) {
		if (is.fail()) break;
		text += ch;
	}
	
	while (removeOccurance(text, "/*", "*/"));
	while (removeOccurance(text, "//", "\n"));
	
	os << text;
	cout << text;
}


int main() { 
	
	ifstream infile; 
	ofstream outfile; 
	
//	infile.open("in/comments.txt");
//	outfile.open("out/comments.txt");	
//	removeComments(infile, outfile);
	
	promptUserForFile(infile, "Input file: "); 
	promptUserForFile(outfile, "Output file: "); 
	removeComments(infile, outfile);
	
	infile.close();
	outfile.close();
	
	return 0;
} 

