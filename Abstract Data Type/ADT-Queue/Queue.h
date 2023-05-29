#ifndef _QUEUE
#define _QUEUE

#include"Node.h"
using namespace std;

template<class ItemType>
class Queue
{
private:
	Node<ItemType>* backPtr;
	Node<ItemType>* frontPtr;

public:
	Queue();  //Default constructor
	Queue(const Queue<ItemType>& aQueue); //Copy constructor

	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const;
	void display() const;
};

template<class ItemType>
Queue<ItemType>::Queue()
{
	backPtr = NULL;
	frontPtr = NULL;
}
template<class ItemType>
Queue<ItemType>::Queue(const Queue<ItemType>& aQueue)
{
	Node<ItemType>* originalNodePtr = aQueue.frontPtr;
	if (originalNodePtr == NULL) {
		frontPtr = NULL;
		backPtr = NULL;
	}
	else {
		//copy the first node
		frontPtr = new Node<ItemType>;
		frontPtr->setItem(originalNodePtr->getItem());
		//copy the remaining nodes
		backPtr = frontPtr;
		while (originalNodePtr->getNext() != NULL) {
			originalNodePtr = originalNodePtr->getNext();
			ItemType nextItem = originalNodePtr->getItem();
			Node<ItemType>* newNode = new Node<ItemType>(nextItem);
			backPtr->setNext(newNode);
			backPtr = backPtr->getNext();
		}
		backPtr->setNext(NULL);
	}
}
template<class ItemType>
bool Queue<ItemType>::isEmpty() const
{
	return ((frontPtr == NULL) && (backPtr == NULL));
}
template<class ItemType>
bool Queue<ItemType>::enqueue(const ItemType& newEntry)
{
	Node<int>* newNode = new Node<ItemType>(newEntry, NULL);
	if (isEmpty()) {				//If the queue is empty then the new node is assign to the frontPtr
		frontPtr = newNode;			//and the backPtr is assign to a newNode
		backPtr = newNode;
	}
	else {
		backPtr->setNext(newNode);
		backPtr = newNode;		//Use the BackPtr to set the newNode		
	}
	return true;
}
template<class ItemType>
bool Queue<ItemType>::dequeue()
{
	if (isEmpty()) {			//If Queue is empty return false
		return false;
	}
	else {
		Node<ItemType>* currNode = frontPtr;
		if (frontPtr == backPtr) {
			delete(currNode);
			frontPtr = NULL;
			backPtr = NULL;
		}
		else {
			frontPtr = frontPtr->getNext();
			delete(currNode);
		}
		return true;
	}
}
template<class ItemType>
ItemType Queue<ItemType>::peekFront() const
{
	if (!isEmpty()) {	
		return frontPtr->getItem;
	}
	else {
		exit(0);
		}
}
template<class ItemType>
void Queue<ItemType>::display() const
{
	if (frontPtr == NULL) {
		cout << "The queue is empty!" << endl;
	}
	else {
		Node<ItemType>* currNode = frontPtr;
		while (currNode != NULL) {
			cout << currNode->getItem() << endl;
			currNode = currNode->getNext();
		}
	}
}
#endif

