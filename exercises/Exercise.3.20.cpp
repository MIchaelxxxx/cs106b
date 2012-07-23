/*
 * Find DNA Match
 */

#include <iostream>
#include <string>
#include "console.h"
#include "strlib.h"
#include "simpio.h"
using namespace std;

int findDNAMatch(string s1, string s2, int start = 0);
int findFirstLinkable(string str, char c, int start = 0);
bool canLink(char c1, char c2);

void println(string str);
void println(char str);

int main() {
	string base = "taacggtacgtc";
	string a    = "ttgcc";
	string b    = "tgc";
	int match;
	
	match = findDNAMatch(base, a);
	println(base + " <-> " + a + ": " + integerToString(match));
	
	match = findDNAMatch(base, a, 2);
	println(base + " <-> " + a + ": " + integerToString(match));
	
	match = findDNAMatch(base, b);
	println(base + " <-> " + b + ": " + integerToString(match));

	match = findDNAMatch(base, b, 3);
	println(base + " <-> " + b + ": " + integerToString(match));	

	return 0;
}

int findDNAMatch(string s1, string s2, int start) {
	int l = s1.length();
	int m = s2.length();
	
	if ((start + m) > l)
		return -1;
	
	for (int i = start; i < l; i++) {
		for (int j = 0; j < m; j++) {
			
			bool linkable = canLink(s2[j], s1[i + j]);
			if (!linkable) {
				break;
			}
			
			bool end = (j + 1 == m);
			if (end) {
				return i;
			}
		}
	}

	return -1;
}

bool canLink(char c1, char c2) {	
	switch (c1) {
		case 'c': 
			return (c2 == 'g');
		case 'g':
			return (c2 == 'c');
		case 'a': 
			return (c2 == 't');
		case 't':
			return (c2 == 'a');
		default:
			return false;
	}
}

void println(string str) {
	cout << str << endl;
}
void println(char str) {
	cout << str << endl;
}