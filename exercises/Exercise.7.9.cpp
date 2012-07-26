/*
 * Pascal's triangle
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "console.h"
using namespace std;

int c(int n, int k) {
	if (n == 0 || k == 0 || k == n) 
		return 1;
	
	return c(n-1, k-1) + c(n-1, k);
}

int t(int n, int k) {
//	cout << "c(" << n << ", " << k << ") " << endl;
	cout << setw(n) << c(n, k);
	if (k == 0) {
		return n-1;
	}
	
	return t(n, k-1);
}

int d(int n) {
	if (n == 0) {
		return 1;
	}
	int x = t(n, n);
	cout << endl;
	return d(x);
}

int main() {

	cout << c(0, 0) << endl; // 1
	cout << c(0, 1) << endl; // 1
	cout << c(1, 1) << endl; // 1
	cout << c(2, 1) << endl; // 2
	cout << c(3, 1) << endl; // 3
	cout << c(4, 1) << endl; // 4
	cout << c(4, 2) << endl; // 6
	cout << c(4, 3) << endl; // 4
	cout << d(6) << endl; // 4
	
	return 0;
}
