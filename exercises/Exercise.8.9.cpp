/*
 * Embedded words, refactored #1
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "console.h"
#include "simpio.h"
#include "set.h"

using namespace std;


void permutations(string str, int index) {
	if (str.length() == index) {
		return;
	}
	
	string prefix = str.substr(0, index);
	char ch = str[index];
	
	for (int i = index; i < str.length(); i++) {
		str[index] = str[i];
		str[i] = ch;
		
		cout << prefix << str.substr(index) << endl;
		
		str[i] = str[index];
		str[index] = ch;
	}

}

void listPermudations(string str) {
	for (int i = 0; i < str.length(); i++) {
		permutations(str, i);
	}
}

int main() {
	string word = "ABCD";
	
	cout << "Permutations are: " << endl;
	
	listPermudations(word);

	return 0;
}
