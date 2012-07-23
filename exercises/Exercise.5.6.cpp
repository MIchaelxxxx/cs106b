/*
 * Sieve of Eratosthenes
 */

#include <iostream>
#include <string>
#include <math.h>
#include "console.h"
#include "vector.h"

using namespace std;

const int FIRST_PRIME = 2;

void seive(Vector<bool> & range) {
	int n = range.size();
	int lim = sqrt(n);
	for (int num = FIRST_PRIME; num < lim; num++) {
		if (range[num]) {
			for (int x = (num+num); x < n; x += num) {
				range[x] = 0;	
			}
		}
	}
}

Vector<int> getVectorOfPrimes(int n) {
	
	Vector<bool> range(n, 1);
	seive(range);

	Vector<int> primes;
	for(int i = FIRST_PRIME; i < range.size(); i++) {
		if (range[i] == 1) {
			primes.add(i);
		}
	}
	
	return primes;
}

int main() {

	int n = 1000;
	Vector<int> primes = getVectorOfPrimes(n);
	
	cout << "Primes up to " << n << endl;
	foreach (int prime in primes) {
		cout << prime << endl;
	}
	
	return 0;
}
