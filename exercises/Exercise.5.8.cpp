/*
 * File: BlankProject.cpp
 * --------------------------
 * You can use this file as a starter for 
 * testing things out that aren't assignments.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include "console.h"
#include "vector.h"
#include "grid.h"
#include "error.h"

using namespace std;

void fillGrid(Grid<int> & grid, Vector<int> & values) {
	int rowSize = grid.numRows();
	for (int i = 0; i < grid.numRows(); i++) {
		for (int j = 0; j < grid.numCols(); j++) {
			grid[i][j] = values[(i * rowSize) + j];
		}
	}
}


bool isMagicSquare(Grid<int> & sq) {
	if (sq.numRows() != sq.numCols()) {
		error("MagicSquare grids must be... square!");
	}
	
	int size = sq.numRows();

	int sum = -1;
	
	for (int i = 0; i < size; i++) {
		int aSum = 0;
		int bSum = 0;
		int rowSum = 0;
		int colSum = 0;
		for (int j = 0; j < size; j++) {
			aSum += sq[j][j];
			bSum += sq[j][size-1-j];
			rowSum += sq[i][j];
			colSum += sq[j][i];
		}
		if (sum == -1) {
			sum = rowSum;
		}
		if (aSum != sum || bSum != sum || rowSum != sum || colSum != sum) {
			return false;
		}
	}
	
	return true;
}
void populateAndCheck(Grid<int> g, Vector<int> v, string hint) {
	fillGrid(g, v);
	
	cout << "isMagicSquare(g) " 
		<< boolalpha
		<< isMagicSquare(g) 
		<< " (" << hint << ")"
		<< endl;
}


int main() {
	cout << "Magic squares" << endl << endl;
	
	Grid<int> g1(3, 3);
	Vector<int> v1; 
	v1 += 1, 2, 3; 
	v1 += 4, 5, 6; 
	v1 += 7, 8, 9;
	populateAndCheck(g1, v1, "false");
	
	Grid<int> g2(3, 3);
	Vector<int> v2; 
	v2 += 8, 1, 6; 
	v2 += 3, 5, 7; 
	v2 += 4, 9, 2;
	populateAndCheck(g2, v2, "true");
	
	Grid<int> g3(4, 4);
	Vector<int> v3; 
	v2 += 16,  3,  2, 13; 
	v2 +=  5, 10, 11,  8; 
	v2 +=  9,  6,  7, 12;
	v2 +=  4, 15, 14,  1;

	populateAndCheck(g2, v2, "true");
	
	
	return 0;
}
