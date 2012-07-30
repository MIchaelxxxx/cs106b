
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
#include "queue.h"
#include "lexicon.h"

using namespace std;

string letters = "abcdefghijklmnopqrstuvwxyz";

Vector<string> wordsByOneLetter (Lexicon & lex, string str, string target) {
	Vector<string> words;
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == target[i]) continue;

		char orig = str[i];
		for (int j = 0; j < letters.length(); j++) {
			if (j == i) continue;
			str[i] = letters[j];
			if (lex.contains(str)) {
				words += str;
			}
		}
		str[i] = orig;
	}
	
	return words;
}

bool ladderContains(Vector<string> & ladder, string value) {
	int i = ladder.size();
	while (i--) {
		if (ladder[i] == value) {
			return true;
		}
	}
	return false;
}

Vector<string> cloneLadder(Vector<string> ladder) {
	return ladder;
}

Vector<string> wordLadder(Lexicon & lex, string start, string end) {
	Vector<string> l1;
	l1 += start;
	
	Queue<Vector <string> > queue;
	queue.enqueue(l1);
	
	while(!queue.isEmpty()) {
		Vector<string> ladder = queue.dequeue();
		
		string word = ladder.get(ladder.size() - 1);

		if (end == word) {
			return ladder;
		}
		
		Vector<string> newWords = wordsByOneLetter(lex, word, end);

		for (int i = 0; i < newWords.size(); i++) {
			if (ladderContains(ladder, newWords[i])) {
				continue;
			}	
			Vector<string> newLadder = cloneLadder(ladder);
			newLadder += newWords[i];
			queue.enqueue(newLadder);
			
			if (queue.size() > 5000)
				return newLadder;
		}
		

	}
	
	Vector <string> emptyLadder;
	return emptyLadder;
}

int main() {
	
	Lexicon lex("in/dictionary.txt");
	
	string start = "work";
	string end = "play";
	
	Vector<string> ladder = wordLadder(lex, start, end);
	
	foreach (string word in ladder) {
		cout << word << " ";
	}
	
	return 0;
}
