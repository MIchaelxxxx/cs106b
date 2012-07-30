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
#include "simpio.h"
#include "vector.h"
#include "map.h"
#include "error.h"
using namespace std;

const string towerNames = "abcdefghijklmnopqrstuvwxyz";

void drawTowerRow(int towerSize, int discSize) {
	towerSize = (towerSize * 2) + 4;
	discSize = (discSize * 2) + 1;
	
	int padding = (towerSize - discSize) / 2;
	string disc = "";
	disc.insert(0, discSize, '*');
	cout << setw(padding) << "" << disc  << setw(padding) << " ";
}

void drawGame(Map<string, Vector<int> > & towers) {
	
	Vector<int> a = towers.get("a");
	Vector<int> b = towers.get("b");
	Vector<int> c = towers.get("c");
	
	int size = towers.get("a").size();
	int i = a.size();
	
	cout << endl;
	while (i--) {
		foreach (string key in towers) {
			drawTowerRow(size, towers.get(key).get(i));
		}
		cout << endl;
	}
}

bool moveDisc(Vector<int> & t1, Vector<int> & t2) {
	int disc = -1;
	
	int i = t1.size();
	while (i--) {
		if (t1.get(i) != 0) {
			disc = t1.get(i);
			break;
		}
	}
	
	if (disc == -1) 
		return false;
	
	int j = t2.size();
	while (j--) {
		if (j == 0 && t2.get(j) == 0) {
			t1.set(i, 0);
			t2.set(j, disc);
			return true;
		}
			
		if (t2.get(j) != 0 && t2.get(j) > disc) {
			t1.set(i, 0);
			t2.set(j+1, disc);
			return true;
		}
	}
	
	return false;
}

Map<string, Vector<int> > buildGame(int towerCount, int towerHeight) {

	Map<string, Vector<int> > towers;

	for (int i = 0; i < towerCount; i++) {
		string name = towerNames.substr(i,1);
		Vector<int> tower(towerHeight, 0);
		towers.put(name, tower);
	}
	
	for (int j = 0; j < towerHeight; j++) {
		string name = towerNames.substr(0,1);
		Vector<int> tower = towers.get(name);
		tower.set(j, towerHeight-j);
		towers.put(name, tower);
	}
	
	return towers;
}

void turn(Map<string, Vector<int> > & towers, string t1, string t2) {
	if (!towers.containsKey(t1) || !towers.containsKey(t2))
		return;
	
	Vector<int> a;
	Vector<int> b; 
		
	cout << "Move " << t1  << " --> " << t2 << endl;
		
	a = towers.get(t1);
	b = towers.get(t2);
		
	bool move = moveDisc(a, b);
		
	if (!move) {
		cout << "Sorry, cannot perform that move" << endl;
	}
		
	towers.put(t1, a);
	towers.put(t2, b);
		
	drawGame(towers);
}

void moveTower(Map<string, Vector<int> > & towers, int n, string start, string end, string tmp) {
	if (n == 0) {
		turn(towers, start, end);
	} else {
		moveTower(towers, n-1, start, tmp, end);
		turn(towers, start, end);
		moveTower(towers, n-1, tmp, end, start);
	}
}

int main() {
	
	Map<string, Vector<int> > towers = buildGame(3, 8);
		
	drawGame(towers);
	
	bool autoSolvable = true;
	
	while (true) {
		string t1, t2;
		
		t1 = getLine("Move from [a, b, c, solve]: ");
		if (t1.length() == 0) 
			return 0;
		
		if (t1 == "solve") {
			if (!autoSolvable) {
				cout << "Cannot auto-solve. You're on your own..." << endl;
			} else {
				cout << "Attempting to solve..." << endl;
				moveTower(towers, towers.get("a").size(), "a", "b", "c");
			}
		}
		
		t2 = getLine("Move to [a, b, c]: ");
		if (t2.length() == 0) 
			return 0;
		
		autoSolvable = false;
		turn(towers, t1, t2);
	}
	
	return 0;
}

