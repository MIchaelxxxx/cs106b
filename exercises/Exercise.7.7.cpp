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
	return digitSum(n/10) + n % 10;
}

int main() {
	
	cout << digitSum(1) << endl;
	cout << digitSum(53) << endl;
	cout << digitSum(1729) << endl;
	
	return 0;
}
