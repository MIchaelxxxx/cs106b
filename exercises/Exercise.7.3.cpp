/*
 * Calculate Titius Bode Distance
 */

#include <iostream>
#include <string>
#include "console.h"
using namespace std;


int getTitiusBodeDistance(int k) {
	if (k == 1) return k;
	if (k == 2) return 3;
	return getTitiusBodeDistance(k-1) * 2;
}

float calculateDistance(int k) {
	int b = getTitiusBodeDistance(k);
	return (float) (4+b)/10;
}

int main() {
	cout << getTitiusBodeDistance(1) << " " << calculateDistance(1) << endl;
	cout << getTitiusBodeDistance(2) << " " << calculateDistance(2) << endl;
	cout << getTitiusBodeDistance(3) << " " << calculateDistance(3) << endl;
	cout << getTitiusBodeDistance(4) << " " << calculateDistance(4) << endl;
	cout << getTitiusBodeDistance(5) << " " << calculateDistance(5) << endl;
	return 0;
}
