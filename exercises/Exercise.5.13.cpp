/*
 * Reverse queue
 */

#include <iostream>
#include <string>
#include "console.h"
#include <queue.h>
#include <stack.h>
using namespace std;

void reverseQueue(Queue<int> & queue) {
	Stack<int> s;

	while (!queue.isEmpty()) {
		s.push(queue.dequeue());
	}
	
	while (!s.isEmpty()) {
		queue.enqueue(s.pop());
	}
	return;
}

int main() {
	Queue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	
	reverseQueue(q);
	
	while (!q.isEmpty()) {
		cout << q.dequeue() << endl;
	}
	
	return 0;
}
	