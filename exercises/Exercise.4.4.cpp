/*
 * Count characters, words, lines in a file
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "error.h"

using namespace std;

void println(string str);
void println(char str);

int countWords(string str) {
	if (str.length() == 0) 
		return 0;
	
	int count = 1;
	for (int i = 0; i < str.length(); i++) {
		if (isspace(str[i])) {
			count++;
		}
	}
	return count;
}

int countChars(string str) {
	return str.length() + 1;
}


int main() {
	
	string path = "in/lear.txt";
	ifstream in;
	string line;

	int chars = 0,
		words = 0, 
		lines = 0;
	
	in.open(path.c_str());
	
	if(in.fail()) {
		error("Cannot open " + path);
	}
	
	
	while (getline(in, line)) {
		if (in.fail()) break;
		lines++;
		chars += countChars(line);
		words += countWords(line);

	}
	in.close();
	
	cout << "Input file: " << path << endl;
	cout << "Chars:" << setw(5) << chars << endl;
	cout << "Words:" << setw(5) << words << endl;
	cout << "Lines:" << setw(5) << lines << endl;

	
	return 0;
}


void println(string str) {
	cout << str << endl;
}
void println(char str) {
	cout << str << endl;
}