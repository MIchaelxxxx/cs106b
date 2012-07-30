/*
 * is measurable
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "console.h"
#include "vector.h"
using namespace std;

bool isMeasurable(int target, Vector<int> & weights) {
	if (weights.size() == 0) 
		return target == 0;
	
	for (int i = 0; i < weights.size(); i++) {
		int a = weights[i];
		
		if (a == target)
			return true;
		
		Vector<int> rest;
		for (int j = 0; j < weights.size(); j++) {
			if (j == i) 
				continue;
			
			int b = weights[j];
			
			if (a + b == target)
				return true;
			
			rest += b;
		}
		
		if (isMeasurable((target-a), rest))
			return true;
	}
	
	return false;

}

Vector<int> getSampleWeights() {
	Vector<int> sampleWeights;
	sampleWeights += 1, 3, 4, 7;
	return sampleWeights;
}

int main() {

	Vector<int> sampleWeights;

	sampleWeights = getSampleWeights();
	cout << boolalpha << isMeasurable(1, sampleWeights) << ", " << true << endl;
	
	sampleWeights = getSampleWeights();
	cout << boolalpha << isMeasurable(6, sampleWeights) << ", " << false << endl;
	
	sampleWeights = getSampleWeights();
	cout << boolalpha << isMeasurable(7, sampleWeights) << ", " << true << endl;
	
	sampleWeights = getSampleWeights();
	cout << boolalpha << isMeasurable(8, sampleWeights) << ", " << true << endl;
	
	sampleWeights = getSampleWeights();
	cout << boolalpha << isMeasurable(9, sampleWeights) << ", " << false << endl;

	sampleWeights = getSampleWeights();
	cout << boolalpha << isMeasurable(10, sampleWeights) << ", " << true << endl;
	
	sampleWeights = getSampleWeights();
	cout << boolalpha << isMeasurable(15, sampleWeights) << ", " << true << endl;
	
	return 0;
}
