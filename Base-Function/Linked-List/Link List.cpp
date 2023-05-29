#include<iostream>
#include "Nodes.h"
using namespace std;

int main()
{
	//Generate the random 50 integer
	Node<int>* head = NULL;
	Node<int>* newNode;
	int newItem;
	int c;
	cout << "Here are the first 10 number in your link list. " << endl;
	//cin >> c;
	for (int i = 0; i < 50; i++) {
		c = rand() % 100;
		newNode = new Node<int>(c, head);
		head = newNode;
	}
	//Display 10 Items in the LInked List
	Node<int>* currNode = head;
	int count = 1;
	while (count <= 10) {
		cout << currNode->getItem() << endl;
		currNode = currNode->getNext();
		cout << endl;
		count++;
	}
	//Calculate the Sum of the Data Items in the linked list
	currNode = head;
	int s = 0;
	while (currNode != NULL) {
		s += currNode->getItem();
		currNode = currNode->getNext();
	}
	cout << "The sum is: " << s << endl;
	currNode = head;
	int a = currNode->getItem();
	currNode = currNode->getNext();
	while (currNode != NULL) {
		if (currNode->getItem() > a)
			a = currNode->getItem();
		currNode = currNode->getNext();
	}
	cout << "The largest number is: " << a << endl;
	//Display the Odd Integer in the List
	currNode = head;
	while (currNode != NULL) {
		if (currNode->getItem() % 2 != 0) {
			cout << currNode->getItem() << endl;
		}
		currNode = currNode->getNext();
	}

	return 0;
}
