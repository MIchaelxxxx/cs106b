/*
 * File: BlankProject.cpp
 * --------------------------
 * You can use this file as a starter for 
 * testing things out that aren't assignments.
 */

#include <iostream>
#include <string>
#include <fstream>
#include "strlib.h"
#include "filelib.h"
#include "simpio.h"
#include "console.h"
#include "map.h"
using namespace std;


void loadAreaCodes(string path, Map<int, string> & data) {
	ifstream fs;
	Vector<string> lines;
	
	openFile(fs, path);
	readEntireFile(fs, lines);
	
	foreach (string line in lines) {
		int pos = line.find('-');
		int k = stringToInteger(line.substr(0, pos));
		string v = line.substr(pos+1);
		data.put(k, v);
	}
	
}

int main() {
	Map<int,string> areacodes;
	loadAreaCodes("in/areacodes.txt", areacodes);
	while (true) {
		string input = getLine("Enter an areacode or state or blank: ");
		if (input.length() == 0) break;
		
		if (input.length() == 3) {
			int areacode = stringToInteger(input);
			if (areacodes.containsKey(areacode)) {
				cout << areacodes.get(areacode) << endl;
			} else {
				cout << "Area code " << areacode << " is not in our phone book." << endl;
			}
			
		} else {
			foreach (int k in areacodes) {
				if(areacodes.get(k) == input) {
					cout << k << endl;
				}
			}
		}
		
	}

	return 0;
}
