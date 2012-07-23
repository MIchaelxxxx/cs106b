/*
 * Calculate mean
 */

#include <iostream>
#include <string>
#include "console.h"
#include "vector.h"
using namespace std;

double mean(Vector<double> & data) {
	double sum = 0;
	foreach (double d in data) {
		sum += d;
	}
	return sum / data.size();
}

int main() {
	// [TODO: code here]
	Vector<double> v;
	v.add(5.3);
	v.add(9);
	v.add(8);
	v.add(2);
	v.add(100);
	
	cout << "Mean: " << mean(v);
	
	return 0;
}
