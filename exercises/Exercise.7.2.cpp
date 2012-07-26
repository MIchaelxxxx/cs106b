/*
 * Recursive raise to power
 */

#include <iostream>
#include <string>
#include "console.h"
using namespace std;

int raiseToPower(int n, int k) {
	if (k == 0) return 1;
	if (k == 1) return n;
	return raiseToPower(n, k-1) * n;
}

int main() {
	cout << raiseToPower(1, 0) << endl;
	cout << raiseToPower(5, 0) << endl;
	cout << raiseToPower(2, 1) << endl;
	cout << raiseToPower(2, 2) << endl;
	cout << raiseToPower(2, 3) << endl;
	cout << raiseToPower(2, 4) << endl;
	return 0;
}
