#ifndef _LIST
#define _LIST
#include "Node.h"
#include<iostream>
using namespace std;

template<class ItemType>
class List
{
private:
	Node<ItemType>* head;
	int itemCount; // Count of List Item
	Node<ItemType>* getNodeAt(int position) const; // Return a pointer that is pointing to a node at 'position' 
public:
	List(); //The default constructor
	List(const List<ItemType>& aList); //The copy constructor
	bool isEmpty()const; // Check to see if the list is empty(There should be no stored in the list
	int getLength()const; // Return the number of item in the list
	bool insert(int newPosition, const ItemType& newEntry); // Insert a new node
	bool remove(int newPosition); // Remove entyr at given position from the list
	void clear(); //Remove all the item from the list
	ItemType getEntry(int newPosition) const; //Retrive an item on the list at the given position
	void setEntry(int newPosition, const ItemType& newEntry); //Retrive an item on the list at the given position
	void displayList();
};

template<class ItemType>
Node<ItemType>* List<ItemType>::getNodeAt(int position) const
{
	Node<ItemType>* currNode = head;
	if (position < 1 or position > itemCount) {
		cout << "Invalide position!" << endl;
		return NULL;
	}
	else {
		for (int i = 0; i < position - 1; i++) {
			currNode = currNode->getNext();
		}
		return currNode;
	}
}
template<class ItemType>
List<ItemType>::List()
{
	head = NULL;
	itemCount = 0;
}
template<class ItemType>
List<ItemType>::List(const List<ItemType>& aList)
{
	ItemType aItem;
	Node<ItemType>* origNode = aList.head;
	Node<ItemType>* currNode = head, * newNode;
	while (origNode != NULL) {
		aItem = origNode->getItem();
		newNode = new Node<ItemType>(aItem);
		if (aList.head == origNode) {	//if origNode is first node in list
			head = newNode;	// [aItem]->NULL
			currNode = head;
		}
		else {
			currNode->setNext(newNode);
			currNode = newNode;
		}
		origNode = origNode->getNext();
		itemCount++;
	}
}
template<class ItemType>
bool List<ItemType>::isEmpty() const
{
	return(head == 0);
}
template<class ItemType>
int List<ItemType>::getLength() const
{
	return itemCount;
}
template<class ItemType>
bool List<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
	Node<ItemType>* newNode, * currNode, * preNode;
	if (newPosition < 1 or newPosition > itemCount + 1) {
		cout << "It is an invalid position. " << endl;
		return false;
	}
	else {
		//Case 1: postion is = 1
		if (newPosition == 1) {
			newNode = new Node<ItemType>(newEntry, head);
			head = newNode;
		}
		else {
			currNode = getNodeAt(newPosition);
			preNode = getNodeAt(newPosition - 1);
			currNode = preNode->getNext();
			newNode = new Node<ItemType>(newEntry, currNode);
			preNode->setNext(newNode);
		}
		itemCount++;
		return true;
	}
}
template<class ItemType>
bool List<ItemType>::remove(int newPosition)
{
	Node<ItemType>* currNode = head;
	if (newPosition < 1 or newPosition > itemCount) {
		cout << "The function remove recieve an INVALID position." << endl;
		return false;
	}
	else {
		if (newPosition == 1) {
			head = head->getNext();
			currNode->setNext(NULL);
			delete(currNode);
		}
		else {
			Node<ItemType>* preNode = getNodeAt(newPosition - 1);
			Node<ItemType>* currNode = getNodeAt(newPosition);
			preNode->setNext(currNode->getNext());
			currNode->setNext(NULL);
			delete(currNode);
		}
		itemCount--;
		return true;
	}
}
template<class ItemType>
void List<ItemType>::clear()
{
	Node<ItemType>* currNode = head;
	while (!isEmpty())
		remove(1);
	itemCount--;
	/*while (head != NULL) {
		currNode = head;
		head = head->getNext();
		delete(currNode);
		itemCount--;
	}*/
}
template<class ItemType>
ItemType List<ItemType>::getEntry(int newPosition) const
{
	if (newPosition < 1 or newPosition > itemCount) {
		cout << "The function getEntry() recieve an INVALID position." << endl;
		exit(1);
	}
	else {
		Node<ItemType>* aNode = getNodeAt(newPosition);
		return aNode->getItem();
	}
}
template<class ItemType>
void List<ItemType>::setEntry(int newPosition, const ItemType& newEntry)
{
	if (newPosition < 1 or newPosition > itemCount) {
		cout << "The function getEntry() recieve an INVALID position." << endl;
		exit(1);
	}
	else {
		Node<ItemType>* aNode = getNodeAt(newPosition);
		aNode->setItem(newEntry);
	}
}
template<class ItemType>
void List<ItemType>::displayList()
{
	if (head == NULL) {
		cout << "The list is empty!" << endl;
	}
	else {
		Node<ItemType>* currNode = head;
		while (currNode != NULL) {
			cout << currNode->getItem() << endl;
			currNode = currNode->getNext();
		}
	}
}
#endif LIST


