/*
 * File: BlankProject.cpp
 * --------------------------
 * You can use this file as a starter for 
 * testing things out that aren't assignments.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "strlib.h"
#include "simpio.h"
using namespace std;

bool myEndsWith(string str, string suffix);
string mySubString(string str, int pos, int n);
void println(string str);

int main() {
	string word = getLine("Enter a word: ");
	string suffix = getLine("Enter a suffix: ");
	
	if (myEndsWith(word, suffix)) {
		println(suffix + " is contained within " + word);
	} else {
		println("Nope");
	}
	
	while (true) {
		string word = getLine("Enter a word: ");

		if (word.length() == 0) break;
		
		int pos = getInteger("Enter pos: ");
		int n = getInteger("Enter n: ");
		string str = mySubString(word, pos, n);
		
		println("Your substring is: " + str);
	}
	
	return 0;
}

bool myEndsWith(string str, string suffix) {
	if (str.length() < suffix.length())
		return false;
	
	int pos = str.length() - suffix.length();
	return mySubString(str, pos, 0) == suffix;
}

string mySubString(string str, int pos = 0, int n = 0) {
	if (pos > str.length()) {
		println("mySubString - pos > str");
		return "";
	}
	
	if (n == 0 || (pos + n) > str.length()) {
		n = str.length() - pos;
	}
	
	string out;
	
	for (int i = pos; i < pos + n; i++) {
		out += str[i];
	}
	
	return out;
}

void println(string str) {
	cout << str << endl;
}