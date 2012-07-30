/*
 * mnemonics, refactored #1
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "console.h"
#include "strlib.h"
#include "set.h"
#include "map.h"
#include "vector.h"
#include "lexicon.h"

using namespace std;



Map<int,string> buildKeyMap() {
	Map<int, string> keys;
	
	keys.put(0, "");
	keys.put(1, "");
	keys.put(2, "ABC");
	keys.put(3, "DEF");
	keys.put(4, "GHI");
	keys.put(5, "JKL");
	keys.put(6, "MNO");
	keys.put(7, "PQRS");
	keys.put(8, "TUV");
	keys.put(9, "WXYZ");	
	
	return keys;
}


Set<string> mnemonicPermutations(Map<int, string> & keys, string number) {
	Set<string> result;
	
	if (number == "") {
		result += "";
		return result;
	}
	
	
	int n = stringToInteger(number.substr(0, 1));
	string letters = keys.get(n);
	
	
	for (int i = 0; i < letters.length(); i++) {
		string ch = letters.substr(i, 1);
		string rest = number.substr(1);
		foreach (string l in mnemonicPermutations(keys, rest)) {
			result.add(ch + l);
		}
	}
}

Set<string> listMnemonics(Lexicon & lex, Map<int, string> & keys, string number) {
	Set<string> result;
	
	foreach (string m in mnemonicPermutations(keys, number)) {
		if (lex.contains(m)) {
			result.add(m);
		}
	}
	
	return result;
}




int main() {
	string word = "ABCD";
	

	Lexicon lex("in/dictionary.txt");
	
	
	cout << "Permutations are: " << endl;
	
	Map<int, string> keys = buildKeyMap();
	
	foreach (string str in 	listMnemonics(lex, keys, "72547")) {
		cout << str << endl;
	}

	
	return 0;
}
