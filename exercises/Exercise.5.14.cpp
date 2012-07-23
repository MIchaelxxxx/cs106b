/*
 * Check brackets
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "console.h"
#include <queue.h>
#include <stack.h>
using namespace std;


bool checkBrackets(string str) {
	Stack<char> b;
	
	foreach (char ch in str) {
		switch (ch) {
			case '{':
			case '[':
			case '(':
				b.push(ch);
				break;
			case '}':
				if (b.pop() != '{') return false;
				break;
			case ']':
				if (b.pop() != '[') return false;
				break;
			case ')':
				if (b.pop() != '(') return false;
				break;
		}
	}
	
	return true;
}

int main() {
	Vector<string> test;
	test += "{ s = 2 * (a[2] + 3); x = (1 + (2)); }";
	test += "[()]";
	test += "[]";
	test += "{]}";
	
	foreach (string str in test) {
		cout 
			<< "Testing: " 
			<< str
			<< " "
			<< boolalpha
			<< checkBrackets(str)
			<< endl;
	}
	
	return 0;

}
