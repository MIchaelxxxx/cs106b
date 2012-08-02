/*
 * File: BlankProject.cpp
 * --------------------------
 * You can use this file as a starter for 
 * testing things out that aren't assignments.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "console.h"
#include "graphics.h"
#include "strlib.h"
#include "random.h"
#include "simpio.h"
#include "map.h"

using namespace std;


class Game {
public:
	
	Game(int cWidth, int cHeight, int cSize) {
		width = cWidth;
		height = cHeight;
		size = cSize;
		//Map<int, Piece> board;
	}
	
	int getSize() {
		return size;
	}
	
	int getRowSize() {
		return height / size;
	}
	
	int getColSize() {
		return width / size;
	}
	/*
	bool pieceExistsAt(int row, int col) {
		int pos = gridToPos(row, col);
		return board.containsKey(pos);
	}
	
	bool setPiece(Piece piece, int row, int col) {
		if (!pieceExistsAt(row, col)) {
			int pos = gridToPos(row, col);
			board.put(pos, piece);
		}
		return false;
	}
	
	int gridToPos(int row, int col) {
		return (row * size) + col;
	}
	 */
	
	void draw() {
		int rowSize = getRowSize();
		int colSize = getColSize();
		
		for (int i = 0; i < size; i++ ) {
			bool even = i % 2;
			for (int j = 0; j < size; j++) {
				even ? setColor("BLACK") : setColor("WHITE");
				even = !even;
				
				fillRect(j * colSize, i * rowSize, colSize, rowSize);
			}
		}
	}
	
private:
	int width;
	int height;
	int size;
	//Map<int, Piece> board;
	
};

class Piece {
public:
	
	
	Piece() {
		name = "";
		row = 0;
		col = 0;
	}
	
	Piece(string cName, int cRow, int cCol) {
		name = cName;
		row = cRow;
		col = cCol;
	}
	
	void draw(Game game) {
		setColor("BLUE");
		setFont("Arial-Bold-48");
		
		int rowSize = game.getRowSize();
		int colSize = game.getColSize();
		
		int rowNudge = 24;
		int colNudge = colSize - 24;
		
		drawString(name, row * rowSize + (rowNudge), col * colSize + (colNudge));
	}
	
private:
	string name;
	int row;
	int col;
	
};


int getPos(int row, int col) {
	return (row * 8) + col;
}

bool boardSpaceOpen(Map<int, Piece> & board, int row, int col) {
	return !board.containsKey(getPos(row, col));
}

bool canPlaceQueen(Map<int, Piece> & board, int row, int col) {
	
	if (!boardSpaceOpen(board, row, col))
		return false;
	
	for (int i = 0; i < 8; i++) {
		
		// Row
		if (board.containsKey(getPos(row + i, col)))
			return false;
		
		if (board.containsKey(getPos(row - i, col)))
			return false;
		
		// Col
		if (board.containsKey(getPos(row, col + i)))
			return false;
		
		if (board.containsKey(getPos(row, col - i)))
			return false;
		
		// TR
		if (board.containsKey(getPos(row + i, col + i)))
			return false;
		
		// BR
		if (board.containsKey(getPos(row - i, col - i)))
			return false;
		
		// BR
		if (board.containsKey(getPos(row - i, col + i)))
			return false;
		
		// TL
		if (board.containsKey(getPos(row + i, col - i)))
			return false;
	}
	
	return true;
}

void drawPiece(Game & game, Map<int, Piece> & board, int name, int row, int col) {

	Piece piece = Piece(integerToString(name), row, col);
	board.put(getPos(row, col), piece);
	piece.draw(game);
}

bool randomPieces(Game & game, Map<int, Piece> & board, int c) {
	
	if (c == 0)
		return true;
	

	int row = randomInteger(0, game.getSize() - 1);
	int col = randomInteger(0, game.getSize() - 1);
		
	if (!boardSpaceOpen(board, row, col))
		return randomPieces(game, board, c);
	
	drawPiece(game, board, c, row, col);
	pause(500);	
	
	randomPieces(game, board, c-1);
	
	return false;
}

bool maxQueens(Game & game, Map<int, Piece> & board, int row, int col) {
	// if we've reached the limit
		// return true
	
	// for each change
		// if we can make the change
		// make the change
		// if we can solve
			// done
		// remove change
	// can't solve
	int size = game.getSize();
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (canPlaceQueen(board, i, j)) {
				cout << i << ", " << col;
				drawPiece(game, board, 1, i, j);
				pause(500);	
			}
		}
	}
	
	return false;
}

int main() {
	
	int width = 640;
	int height = 640;
	int size = 8;
	
	initGraphics(width, height);
	
	Game game = Game(width, height, size);
	Map<int, Piece> board;
	
	
	while (true) {
		int items = 8; //getInteger("How many pieces to randomize?");
		
		if (items == 0)
			break;
		
		game.draw();
		
		//randomPieces(game, pieces, 8);
		maxQueens(game, board, 7, 7);
		
		break;
	}
	
	
	
	return 0;
}
