#include <iostream>
#include "Queue.h"

int main() {
	Queue<int> q;
	Node<int>* qHead, * newNode;

	//adding to 'q'
	newNode = new Node<int>(29);
	qHead = newNode;
	
	q.enqueue(29);
	q.enqueue(93);
	q.dequeue();
	q.display();

	return 0;
}