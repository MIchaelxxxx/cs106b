/*
 * Embedded words, refactored #1
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "console.h"
#include "simpio.h"
#include "lexicon.h"
#include "set.h"

using namespace std;
/*
 
 Remove the first character from the string and store it in the variable ch. 
 
 Generate the set containing all permutations of the remaining characters.
 
 Form a new set by inserting ch in every possible position in each of those permutations.
 
 */


Set<string> permutations(string str) {
	Set<string> result;
	
	if (str == "") {
		result += "";
		return result;
	} 
	
	string ch = str.substr(0, 1);
	string rest = str.substr(1);	
	
	Set<string> remaining = permutations(rest);
	
	cout << remaining.size() << endl;


	foreach (string s in permutations(rest)) {
		cout << s;
		for (int i = 0; i < s.length(); i++) {
//			char ch = str[i];
//			string rest = str.substr(0, i) + ch + str.substr(i + 1); 
			result += str.insert(i, ch);
		}
//		result += ch + s;
	}
	
//	for (int i = 0; i < str.length(); i++) {
//		char ch = str[i];
//		string rest = str.substr(0, i) + str.substr(i + 1); 
//		foreach (string s in permutations(rest)) {
//			result += ch + s;
//		}
//	}
	
	return result;
}

int main() {
	Lexicon lex("in/dictionary.txt");
	
		string word = "ABCD";
		
		cout << "Permutations are: " << endl;
		foreach (string str in permutations(word)) {
			cout << "-" << str << endl;
		}
		
	return 0;
}
