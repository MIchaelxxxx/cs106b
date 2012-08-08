/*
 * File: BlankProject.cpp
 * --------------------------
 * You can use this file as a starter for 
 * testing things out that aren't assignments.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "math.h"
#include "console.h"
#include "graphics.h"
#include "strlib.h"
#include "random.h"
#include "simpio.h"
#include "map.h"

using namespace std;

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 480;

const int BOARD_ROWS = 8;
const int BOARD_COLS = 8;
const int BOARD_SIZE = (BOARD_ROWS * BOARD_COLS);


void drawPiece(string name, int row, int col);
void drawPiece(int name, int row, int col);





int posAt(int row, int col) {
	return (row * BOARD_ROWS) + col;
}

bool canPlacePiece(Map<int, string> & board, int row, int col) {
	bool exists = board.containsKey(posAt(row, col));
	
	drawPiece(".", row, col);
	if (col > 2) pause(250);
	if (col > 2 && exists) {
		cout << "C: " << row << ", " << col << " " << exists << endl;
		drawPiece("X", row, col);
		pause(1000);
	}
	pause(10);
	
	
	return !exists;
}

bool canPlaceQueen(Map<int, string> & board, int row, int col) {
	
	if (!canPlacePiece(board, row, col))
		return false;
	
	for (int i = 0; i < 8; i++) {
		// Row
		if ((row + i) < BOARD_ROWS && !canPlacePiece(board, row + i, col))
			return false;
		
		if ((row - i) > BOARD_ROWS &&!canPlacePiece(board, row - i, col))
			return false;
		
		// Col
		if (!canPlacePiece(board, row, col + i))
			return false;
		
		if (!canPlacePiece(board, row, col - i))
			return false;//
		
		// TR
		if (!canPlacePiece(board, row + i, col + i))
			return false;
		
		// BR
		if (!canPlacePiece(board, row - i, col + i))
			return false;
		
		// BR
		if (!canPlacePiece(board, row - i, col - i))
			return false;
		
		// TL
		if (!canPlacePiece(board, row + i, col - i))
			return false;
	}
	
	return true;
}

void drawBoard() {
	int rowSize = SCREEN_HEIGHT/ BOARD_ROWS;
	int colSize = SCREEN_WIDTH / BOARD_COLS;
	
	for (int i = 0; i < BOARD_ROWS; i++ ) {
		bool even = i % 2;
		for (int j = 0; j < BOARD_COLS; j++) {
			even ? setColor("BLACK") : setColor("WHITE");
			even = !even;
			
			fillRect(j * colSize, i * rowSize, colSize, rowSize);
		}
	}
}


void addPiece(Map<int, string> & board, string name, int row, int col) {
	board.put(posAt(row, col), name);
}
void addPiece(Map<int, string> & board, int name, int row, int col) {
	string newName = integerToString(name);
	addPiece(board, newName, row, col);
}

void removePiece(Map<int, string> & board, int row, int col) {
	if (board.containsKey(posAt(row, col))) {
		board.remove(posAt(row, col));
	}
}

void drawPiece(string name, int row, int col) {
	
	setColor("BLUE");
	setFont("Arial-Bold-36");
	
	int rowSize = SCREEN_HEIGHT / BOARD_ROWS;
	int colSize = SCREEN_WIDTH / BOARD_COLS;
	
	int colNudge = (BOARD_COLS * 2);
	int rowNudge = rowSize - (BOARD_ROWS * 2);
	
	int x = col * colSize + colNudge;
	int y = row * rowSize + rowNudge;
	
	drawString(name, x, y);
}

void drawPiece(int name, int row, int col) {
	string newName = integerToString(name);
	drawPiece(newName, row, col);
}

void drawPieces(Map<int, string> & board) {
	for (int i = 0; i < BOARD_ROWS; i++ ) {
		for (int j = 0; j < BOARD_COLS; j++) {
			if (board.containsKey(posAt(i, j)) ) {
				string name = board.get(posAt(i, j));
				drawPiece(name, i, j);
			}
		}
	}	
}

void draw(Map<int, string> & board) {
	drawBoard();
	drawPieces(board);
}

bool randomPieces(Map<int, string> & board, int c) {
	
	if (c == 0)
		return true;
	

	int row = randomInteger(0, BOARD_ROWS - 1);
	int col = randomInteger(0, BOARD_COLS - 1);
		
	if (!canPlacePiece(board, row, col))
		return randomPieces(board, c);
	
	addPiece(board, c, row, col);
	draw(board);
	pause(350);	
	
	randomPieces(board, c-1);
	
	return false;
}


bool iterativeMaxQueens(Map<int, string> & board, int row, int col) {	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (canPlaceQueen(board, i, j)) {
				cout << i << ", " << col;
				addPiece(board, "Q", i, j);
				draw(board);
				pause(500);	
			}
		}
	}
	
	return false;
}

bool solveMaxQueens(Map<int, string> & board, int col) {

	if (col >= BOARD_COLS ) 
		return true;
	
	int DELAY = 350;
	
	for (int row = 0; row < BOARD_ROWS; row++) {
		cout << row << ", " << col << endl;		
		if (canPlaceQueen(board, row, col)) {

			addPiece(board, "Q", row, col);
			draw(board);
			pause(DELAY);
			
			if (solveMaxQueens(board, col + 1)) {
				return true;
			} else {
				removePiece(board, row, col);
				draw(board);
			}
				
		} else {
			addPiece(board, "F", row, col);
			draw(board);
			pause(DELAY);

			removePiece(board, row, col);
		}

	}
	
	return false;
}

int main() {
	
	initGraphics(SCREEN_WIDTH, SCREEN_HEIGHT);
	
	Map<int, string> board;

	
	draw(board);
		
	//randomPieces(board, 32);
	//iterativeMaxQueens(board, 7, 7);
//	addPiece(board, "Q", 4, 4);
//	cout << canPlaceQueen(board, 4, 4) << endl;
//	cout << canPlaceQueen(board, 3, 4) << endl;
//	cout << canPlaceQueen(board, 3, 5) << endl;
//	cout << canPlaceQueen(board, 4, 5) << endl;
//	draw(board);
	
	
	bool result = solveMaxQueens(board, 0);
	cout << result << endl;

	return 0;
}
