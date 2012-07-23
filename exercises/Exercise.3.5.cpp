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

int calcPoints(string word);
int calcPoints(char c);
void println(string str);

int main() {
	while (true) {
		string word = getLine("Enter a word: ");
		
		if (word.length() == 0) break;
		int points = calcPoints(word);
		cout << "Worth " + integerToString(points) + " points \n";
	}
	
	return 0;
}

int calcPoints(string word) {
	int points = 0;
	for (int i = 0; i < word.length(); i++) {
		points += calcPoints(word[i]);
	}
	return points;
}

int calcPoints(char c) {
	string valid = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	if (valid.find(c) == -1) {
		return 0;
	}	
	
	string pointMap[11] = {
		"",
		"AEILNORSTU",
		"DG",
		"BCMP",
		"FHVWY",
		"K",
		"", // 6
		"", // 7
		"JX",
		"", // 9
		"QZ"
	};
	
	for (int i = 0; i <= sizeof(pointMap); i++) {
		if (pointMap[i].find(c) != -1) {
			return i;
		}
	}
	return 0;
}

void println(string str) {
	cout << str << endl;
}