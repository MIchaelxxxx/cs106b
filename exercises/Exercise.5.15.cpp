/*
 * roll stack
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "console.h"
#include <queue.h>
#include <stack.h>
#include <error.h>
using namespace std;


Stack<string> getStack() {
	Stack<string> s;
	s.push("A");
	s.push("B");
	s.push("C");
	s.push("D");
	
	return s;
}

void printStack(Stack<string> s) {
	cout 
	<< s.pop() << "\n"
	<< s.pop() << "\n"
	<< s.pop() << "\n"
	<< s.pop() << "\n"
	<< endl;
}

void roll(Stack<string> & stack, int n, int k) {
	if (n > stack.size()) {
		error("roll: argument out of range");
	}
	
	Stack<string> holding;
	
	string head;
	
	while (k--) {
		
		head = stack.pop();
		
		for (int i = 0; i < n-1; i++) {
			holding.push(stack.pop());
		}
		
		stack.push(head);
		
		for (int i = 0; i < n-1; i++) {
			stack.push(holding.pop());
		}
		
		
	}
}

int main() {

	Stack<string> s1 = getStack();
	printStack(s1);
	roll(s1, 4, 1);
	printStack(s1);
	
	cout << endl;
	
	Stack<string> s2 = getStack();
	printStack(s2);
	roll(s2, 3, 2);
	printStack(s2);
	
	
	cout << endl;
	
	Stack<string> s3 = getStack();
	printStack(s3);
	roll(s3, 2, 4);
	printStack(s3);
	
	return 0;
	
}
