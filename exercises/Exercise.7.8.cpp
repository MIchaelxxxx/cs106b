/*
 * digitSum
 */

#include <iostream>
#include <string>
#include "console.h"
using namespace std;

int digitSum(int n) {
	if (n < 10) {
		return n;
	}
	return digitSum(n/10) + (n % 10);
}

int digitalRoot(int n) {
	if (n < 10) {
		return n;
	}
	int digitalSum = digitSum(n);
	return digitalRoot(digitalSum);
}

int main() {
	
	cout << digitalRoot(1) << endl;
	cout << digitalRoot(53) << endl;
	cout << digitalRoot(1729) << endl;
	
	return 0;
}
