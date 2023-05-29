#include<iostream>
#include"Node.h"
#include<string>

using namespace std;

int main() {
	Node<int>* head = NULL;
	Node<int>* newNode;
	int newItem;

	newNode = new Node<int>(36);
	head = newNode;
	newNode = new Node<int>(24);
	newNode->setNext(head);
	head = newNode;

	Node<int>* currNode = head;
	while (currNode != NULL) {
		cout << currNode-> getItem() << endl;
		currNode = currNode->getNext();
		cout << endl;
	}
	currNode = head;
	while (currNode != NULL) {
		if (currNode->getItem() == 36) {
			currNode->setItem(50);
		}
		currNode = currNode->getNext();
	 }
	currNode = head;
	while (currNode != NULL) {
		cout << currNode->getNext();
		currNode = currNode->getNext();
		cout << endl;
	}
	{
		Node<string>* head = NULL;
		Node<string>* newNode;

		newNode = new Node<string>("Winter");
		head = newNode;	// first item in nodes
		newNode = new Node<string>("Summer");
		newNode->setNext(head);
		head = newNode;

		Node<string>* currNode = head;
		while (currNode != NULL) {
			cout << currNode->getItem() << endl;
			currNode = currNode->getNext();
			cout << endl;
		}
		currNode = head;
		while (currNode != NULL) {
			if (currNode->getItem() == "Winter") {
				currNode->setItem("Spring");
			}
			currNode = currNode->getNext();
		}
		currNode = head;
		while (currNode != NULL) {
			cout << currNode->getItem() << endl;
			currNode = currNode->getNext();
			cout << endl;
		}
	}


	return 0;
}