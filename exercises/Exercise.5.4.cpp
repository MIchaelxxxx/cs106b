/*
 * Historgram
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "strlib.h"
#include "vector.h"

using namespace std;

void drawHistogram(Vector<int> v, char marker = '*') {
	for (int i = 0; i <= 10; i++) {
		string m = "";
		m.insert(0, v.get(i), marker);
		cout << left << setfill('s') << setw(3) << i*10 << ": " << m << endl;
	}	
}

int main() {
	
	string path = "in/integers.txt";
	ifstream is;
	Vector<string> lines;
	
	openFile(is, path);
	readEntireFile(is, lines);
	
	Vector<int> h(11, 0);
	foreach (string line in lines) {
		int x = stringToInteger(line) / 10;
		if (x >= 0 || x <= 10) {
			h[x] += 1;
		}
	}

	drawHistogram(h);
	
		
	return 0;
}
