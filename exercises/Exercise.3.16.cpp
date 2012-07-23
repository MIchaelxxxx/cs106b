/*
 * obenglobish a string
 */

#include <iostream>
#include <string>
#include "console.h"
#include "strlib.h"
#include "simpio.h"
using namespace std;

string obenglobish(string word);
void println(string str);

int main() {
	while (true) {
		string word = getLine("Enter a word: "); 
		if (word == "") break; 
		string trans = obenglobish(word); 
		cout << word << " -> " << trans << endl;
	}
	return 0;
}

string obenglobish(string word) {
	string vowels = "aeiou";
	
	string out = "";
	
	for (int i = 0; i < word.length(); i++) {
		bool lastWasVowel = (i > 0 && vowels.find(word[i-1]) != -1);
		bool isLast = (i == word.length());
		
		if (vowels.find(word[i]) != -1) {
			if (!lastWasVowel && !isLast) {
				out += "ob";
			}
		}
		out += word[i];
													   

	}
	
	return out;
}

void println(string str) {
	cout << str << endl;
}