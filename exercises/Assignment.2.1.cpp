
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

bool contains(Vector<string> & ladder, string str) {
	int i = ladder.size();
	while (i--) {
		if (ladder[i] == str) {
			return true;
		}
	}
	return false;
}

Vector<string> clone(Vector<string> ladder) {
	Vector<string> newLadder;
	
	for (int i = 0; i < ladder.size(); i++) {
		newLadder += ladder[i];
	}
	return newLadder;
}

Vector<string> wordsByOneLetter (Lexicon & lex, string word) {
	Vector<string> words;
	string original = word;
	
	for (int i = 0; i < word.length(); i++) {

		char originalCh = word[i];
		
		for (int j = 0; j < letters.length(); j++) {
		
			word[i] = letters[j];
			
			if (word == original)
				continue;
			
			if (contains(words, word))
				continue;

			if (!lex.contains(word))
				continue;
				
			words += word;
		}

		word[i] = originalCh;
	}
	
	return words;
}



Vector<string> wordLadder(Lexicon & lex, string start, string target) {

	Vector<string> startingLadder;
	startingLadder += start;
	
	Queue<Vector <string> > queue;
	queue.enqueue(startingLadder);
	
	Vector<string> seen;
	
	while(!queue.isEmpty()) {
		Vector<string> lastLadder = queue.dequeue();

		string lastWord = lastLadder.get(lastLadder.size() - 1);

		if (lastWord == target)
			return lastLadder;

		foreach (string word in wordsByOneLetter(lex, lastWord)) {
			
			if (contains(lastLadder, word))
				continue;
			
			if (contains(seen, word))
				continue;

			Vector<string> ladder = clone(lastLadder);

			
			seen += word;
			ladder += word;
				
			queue.enqueue(ladder);
			
		}
		
	}
	
	Vector <string> emptyLadder;
	return emptyLadder;
}

int main() {
	
	Lexicon lex("in/dictionary.txt");
	
	
	while (true) {
		string start = getLine("Enter a starting word [or blank to end]: ");
		if (start == "") break;
		
		string end = getLine("Enter a starting word [or blank to quit]: ");		
		if (end == "") break;
		
		cout << "Please wait while I connect '" << start << "' with '" << end << "'" << endl;
		
		Vector<string> ladder = wordLadder(lex, start, end);
		
		if (ladder.size() == 0) {
			cout << "No ladder found!" << endl;
			continue;
		}
		
		foreach (string word in ladder) {
			cout << word << " ";
		}
		cout << endl;
	}

	
	return 0;
}
