#include<iostream>
#include "PQueue.h"
#include"SortedList.h"
#include"Node.h"

using namespace std;

int main() {
	
	
	PQueue<int> q;
	
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(9);
	q.enqueue(7);
	q.enqueue(1);
	q.enqueue(12);
	q.enqueue(10); 
	q.enqueue(6);
	q.dequeue();
	q.displayQueue();
	
	
	return 0;
}