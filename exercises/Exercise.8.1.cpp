/*
 * Count Hanoi Moves
 */

#include <iostream>
#include <string>
#include "console.h"
using namespace std;

int countHanoiMoves(int n) {
	if (n == 0)
		return 0;
	return countHanoiMoves(n-1) + countHanoiMoves(n-1) + 1;
}

int main() {
	cout << countHanoiMoves(1) << endl;
	cout << countHanoiMoves(2) << endl;
	cout << countHanoiMoves(3) << endl;
	return 0;
}
