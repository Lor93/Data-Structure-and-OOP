#ifndef _SORTED_LIST
#define _SORTED_LIST
#include "Node.h"
using namespace std;

template<class ItemType>
class SortedList
{
private:
	Node<ItemType>* head;
	int itemCount;
	Node<ItemType>* getNodeAt(int position) const;
	Node<ItemType>* getNodeBefore(const ItemType& anEntry) const;
public:
	SortedList();
	SortedList(const SortedList<ItemType>& anEntry);
	bool isEmpty() const;
	int getLength() const;
	void clear();
	ItemType getEntry(int postion) const;
	void displayList();
	void insertSorted(const ItemType& anEntry);
	bool removeSorted(const ItemType& anEntry);
	int getPosition(const ItemType& newEntry) const;
};
template<class ItemType>
Node<ItemType>* SortedList<ItemType>::getNodeAt(int position) const
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
Node<ItemType>* SortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const
{

	if (isEmpty() && head->getItem() > anEntry) { cout << "Invalid!\n"; exit(0); }

	Node<ItemType>* currNode, *preNode;

	for (int i = 2; i <= itemCount; i++) {	//already checked first node with conditional statement
		currNode = getNodeAt(i);
		preNode = getNodeAt(i - 1);
		if (currNode->getItem() >= anEntry) {
			return preNode;
		}
	}
	
	return getNodeAt(itemCount);
}
template<class ItemType>
SortedList<ItemType>::SortedList()
{
	head = NULL;
	itemCount = 0;
}

template<class ItemType>
bool SortedList<ItemType>::isEmpty() const
{
	return(head == 0);
}
template<class ItemType>
int SortedList<ItemType>::getLength() const
{
	return itemCount;
}
template<class ItemType>
void SortedList<ItemType>::clear()
{
	Node<ItemType>* currNode = head;
	while (head != NULL) {
		currNode = head;
		head = head->getNext();
		delete(currNode);
		itemCount--;
	}
}
template<class ItemType>
ItemType SortedList<ItemType>::getEntry(int newPosition) const
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
void SortedList<ItemType>::displayList()
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
template<class ItemType>
void SortedList<ItemType>::insertSorted(const ItemType& anEntry)
{
	Node<ItemType>* newNode;
	Node<ItemType>* currNode, * preNode;

	newNode = new Node<ItemType>(anEntry);	// [anEntry]->NULL

	if (isEmpty()) {	//place beginning of list
		head = newNode;
		itemCount++;
	}
	else {
		if (itemCount == 1) {
			if (anEntry > head->getItem()) {
				head->setNext(newNode);
				itemCount++;
			}
			else {
				newNode->setNext(head);
				head = newNode;
				itemCount++;
			}
		}
		else {
			if (head->getItem() > anEntry) {
				newNode->setNext(head);
				head = newNode;
				itemCount++;
			}
			else {
				preNode = getNodeBefore(anEntry);
				currNode = preNode->getNext();
				preNode->setNext(newNode);
				newNode->setNext(currNode);
				itemCount++;
			}
		}
	}
}
template<class ItemType>
bool SortedList<ItemType>::removeSorted(const ItemType& anEntry) 
{
	if (isEmpty() || head->getItem() > anEntry)
		return false;

	if (head->getItem() == anEntry) {
		Node<ItemType>* tmp = head;
		head = head->getNext();
		delete tmp;
		itemCount--;
		return true;
	}

	Node<ItemType>* a, * aNext;

	a = getNodeBefore(anEntry);
	if (a->getNext() == NULL) {
		return false;
	}
	else {
		aNext = a->getNext();
		if (aNext->getItem() == anEntry) {
			a->setNext(aNext->getNext());
			delete aNext;
			itemCount--;
			return true;
		}
		else return false;
	}

}
template<class ItemType>
int SortedList<ItemType>::getPosition(const ItemType& newEntry) const
{
	int position = 1;
	Node<ItemType>* currNode = head;
	if (!isEmpty()) {
		while (currNode != NULL && currNode->getItem() < newEntry) {
			currNode = currNode->getNext();
			position++;
		}
	}

	return position;
}
#endif LIST