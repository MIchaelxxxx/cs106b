/*
 * Calculate standard deviation
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "console.h"
#include "math.h"
#include "vector.h"
using namespace std;

double mean(Vector<double> data) {
	double sum = 0;
	foreach (double d in data) {
		sum += d;
	}
	return sum / data.size();
}

double standardDeviation(Vector<double> data) {
	double m = mean(data);
	double sum = 0;
	foreach (double x in data) {
		sum += pow((m-x), 2);
	}
	return sqrt(sum / (data.size() - 1));
}

int main() {
	// [TODO: code here]
	Vector<double> v;
	v.add(2);
	v.add(4);
	v.add(6);
	v.add(8);
	v.add(16);
	
	cout << setw(20) << "Mean (Average): " << mean(v) << endl;
	cout << setw(20) << "Standard Deviation: " << standardDeviation(v) << endl;
	
	return 0;
}
