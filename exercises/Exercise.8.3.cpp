/*
 * Subset sum
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "console.h"
#include "set.h"
using namespace std;

bool subsetSumExists(Set<int> & set, int target) {
	if (set.isEmpty()) 
		return target == 0;
	
	int n = set.first();
	Set<int> rest = set - n;
	
	return subsetSumExists(rest, target)
		|| subsetSumExists(rest, target - n);
}

int countSubsetSumWays(Set<int> & set, int target) {
	if (set.isEmpty()) 
		return target == 0 ? 1 : 0;
	
	int n = set.first();
	Set<int> rest = set - n;
	
	return subsetSumExists(rest, target)
	+ subsetSumExists(rest, target - n);	
}

int main() {
	Set<int> s0;
	Set<int> s1;
	s1 += 1;
	s1 += 2;
	s1 += 3;
	Set<int> s2;
	s2 += 1;
	s2 += 3;
	s2 += 4;
	s2 += 5;
	
	cout << boolalpha << subsetSumExists(s0, 0) << endl;
	cout << countSubsetSumWays(s0, 0) << endl;
	cout << boolalpha << subsetSumExists(s1, 3) << endl;
	cout << countSubsetSumWays(s1, 3) << endl;
	cout << boolalpha << subsetSumExists(s1, 5) << endl;
	cout << countSubsetSumWays(s1, 5) << endl;
	cout << boolalpha << subsetSumExists(s1, 7) << endl;
	cout << countSubsetSumWays(s1, 7) << endl;	
	cout << boolalpha << subsetSumExists(s2, 5) << endl;
	cout << countSubsetSumWays(s2, 5) << endl;	// 2
	cout << boolalpha << subsetSumExists(s2, 11) << endl;
	cout << countSubsetSumWays(s2, 11) << endl;	// 0
	return 0;
}
