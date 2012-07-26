/*
 * reverse string
 */

#include <iostream>
#include <string>
#include "console.h"
using namespace std;

string r(string str, int l) {
	if (l == 0) 
		return str;
	
	char ch = str[l-1];
	
	str += ch;
	str.erase(l-1, 1);
	
	return r(str, l-1);
}

string reverse(string str) {
	return r(str, str.length());
}

int main() {
	cout << reverse("program") << endl;
	return 0;
}
