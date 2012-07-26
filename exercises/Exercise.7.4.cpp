/*
 * greatest common divisor
 * --------------------------
 */

#include <iostream>
#include <string>
#include "console.h"
using namespace std;

int gcd(int x, int y) {
	if (x % y == 0) return y;
	return gcd(y, x % y);
}

int main() {
	// [TODO: code here]
	cout << gcd(2, 1) << endl;
	cout << gcd(4, 2) << endl;
	cout << gcd(12, 9) << endl;
	cout << gcd(15, 6) << endl;
	return 0;
}
