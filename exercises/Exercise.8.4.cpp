/*
 * Embedded words
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "console.h"
#include "simpio.h"
#include "lexicon.h"
#include "set.h"

using namespace std;



Set<string> embeddedWords(Lexicon & lex, string str) {
	Set<string> result;
	
	if (str == "") 
		return result;
	
	if (lex.contains(str))
		result += str;
	
	for (int i = 0; i < str.length(); i++) {
		string rest = str.substr(0, i) + str.substr(i+1);
		
		foreach (string s in embeddedWords(lex, rest)) {
			result += s;
		}
	}
	return result;
}

int main() {
	Lexicon lex("in/dictionary.txt");
	
	while (true) {
		string word = getLine("Enter a word:");
		
		if (word.length() == 0)
			return 0;
		
		if (!lex.contains(word)) {
			cout << "Not a valid word." << endl;
			continue;
		}
		
		cout << "Embedded words are: " << endl;
		foreach (string str in embeddedWords(lex, word)) {
			cout << "-" << str << endl;
		}

	}
	
	return 0;
}
