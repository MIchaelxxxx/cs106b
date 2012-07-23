/*
 * Sudoku Checker
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <math.h>
#include "console.h"
#include "filelib.h"
#include "vector.h"
#include "grid.h"
#include "set.h"
#include "strlib.h"
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

void printGrid(Grid<int> g) {
	for (int i = 0; i < g.numRows(); i++) {
		for (int j = 0; j < g.numCols(); j++) {
			cout << " " << g[i][j] << " ";			
		}
		cout << endl;
	}
}

bool addToSet(Set<int> & set, int val) {
	
	if (val == 0) return true;
	
	if (set.contains(val)) 
		return false;
	
	set.add(val);
	return true;
}

bool checkRow(Grid<int> & puzzle, int n) {
	Set<int> values;
	
	for (int i = 0; i < 9; i++)
		if (!addToSet(values, puzzle[n][i])) 
			return false;

	return true;
}

bool checkCol(Grid<int> & puzzle, int n) {
	
	Set<int> values;
	for (int i = 0; i < 9; i++) 
		if (!addToSet(values, puzzle[i][n]))
			return false;

	return true;
}
		
bool checkBox(Grid<int> & puzzle, int n) {
	Set<int> values;
	
	int offsetRow = floor(n/3) * 3;
	int offsetCol = (n - offsetRow) * 3;

	for (int row = offsetRow; row < offsetRow + 3; row++)
		for (int col = offsetCol; col < offsetCol + 3; col++)
			if (!addToSet(values, puzzle[row][col]))
				return false;
	
	return true;
}

bool checkSudokuSolution(Grid<int> & puzzle) {
	for (int i = 0; i < 9; i++) {
		if (!checkRow(puzzle, i)) return false;
		if (!checkCol(puzzle, i)) return false;
		if (!checkBox(puzzle, i)) return false;
	}
	
	return true;
}


Grid<int> createPuzzleFromString(string data) {
	Grid<int> puzzle(9, 9);

	Vector<int> numbers;
	for (int i = 0; i < data.size(); i++) {
		int num = stringToInteger(data.substr(i, 1));
		numbers.add(num);
	}
	
	fillGrid(puzzle, numbers);
	
	return puzzle;
}


int main() {

	ifstream fs;
	Vector<string> lines; 
	
	openFile(fs, "in/sudoku.txt");
	readEntireFile(fs, lines);
	
	foreach(string line in lines) {
		Grid<int> puzzle = createPuzzleFromString(line);
		cout << "Sudoku solvable? " << boolalpha <<  checkSudokuSolution(puzzle) << endl << endl;
		printGrid(puzzle);
		cout << endl;
		
	}
	
	return 0;
}
