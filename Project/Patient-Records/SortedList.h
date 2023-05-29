#ifndef SortedList_h
#define SortedList_h

#include"Node.h"
#include<iostream>
using namespace std;

template<class ItemType>
class SortedList
{
private:
    Node<ItemType>* head;
    int itemCount;
    Node<ItemType>* getNodeBefore(ItemType& anEntry)const;
    Node<ItemType>* getNodeAt(int position) const; //Directly from class template List
public:
    //Following eight member fucntions are directly from class template List
    SortedList();
    SortedList(const SortedList<ItemType>& aList);
    bool isEmpty() const;
    int getLength() const;
    bool remove(int position);
    void clear();
    ItemType getEntry(int position) const;
    void displayList();

    //Following are three new methods:
    void insertSorted(ItemType& newEntry);
    bool removeSorted(const ItemType& anEntry);
    int getPosition(const ItemType& newEntry) const;
    bool contains(const ItemType anItem) const;
};
//Complete all the constructors and methods here:
template<class ItemType>
SortedList<ItemType>::SortedList()
{
    head = NULL;
    itemCount = 0;
}
template<class ItemType>
SortedList<ItemType>::SortedList(const SortedList<ItemType>& aList)
{
    if (aList.isEmpty()) {
        head = NULL;
        itemCount = 0;
    }
    else {
        Node<ItemType>* originalNode = aList.head;
        head = new Node<ItemType>(originalNode->getItem(), NULL);
        itemCount++;
        Node<ItemType>* newNode, * curNode = head;
        while (originalNode->getNext() != NULL) {
            originalNode = originalNode->getNext();
            newNode = new Node<ItemType>(originalNode->getItem(), NULL);
            curNode->setNext(newNode);
            curNode = curNode->getNext();
            itemCount++;
        }
    }
}
template<class ItemType>
Node<ItemType>* SortedList<ItemType>::getNodeAt(int position) const
{
    if (position<1 || position>itemCount) {
        cout << "Invalid position for function: getNode()\n";
        cout << "Program aborted!\n";
        system("pause");
        exit(1);
    }
    Node<ItemType>* nodePtr = head;
    for (int i = 1; i < position; i++)
        nodePtr = nodePtr->getNext();
    return nodePtr;
}
template<class ItemType>
bool SortedList<ItemType>::isEmpty() const
{
    return (head == NULL);
}
template<class ItemType>
int SortedList<ItemType>::getLength() const
{
    return itemCount;
}
template<class ItemType>
void SortedList<ItemType>::displayList()
{
    Node<ItemType>* currentNode = head;
    if (head == NULL)
        cout << "It is an empty list!\n";
    while (currentNode != NULL) {
        cout << currentNode->getItem() << endl;
        currentNode = currentNode->getNext();
    }
}
template<class ItemType>
bool SortedList<ItemType>::remove(int position)
{
    if (position<1 || position>itemCount) {
        cout << "Invalid Position!" << endl;
        return false;
    }
    else if (isEmpty()) {
        cout << "It is an empty list!" << endl;
        return false;
    }
    else if (position == 1) {
        Node<ItemType>* nodePtr = head;
        head = head->getNext();
        nodePtr->setNext(NULL);
        delete(nodePtr);
    }
    else {
        Node<ItemType>* preNode = getNodeAt(position - 1);
        Node<ItemType>* curNode = getNodeAt(position);
        preNode->setNext(curNode->getNext());
        curNode->setNext(NULL);
        delete(curNode);
    }
    itemCount--;
    return true;
}
template<class ItemType>
void SortedList<ItemType>::clear()
{
    while (!isEmpty())
        remove(1);
}
template<class ItemType>
ItemType SortedList<ItemType>::getEntry(int position) const
{
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet) {
        Node<ItemType>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else {
        cout << "Invalid Position! getEntry() call failed, The program is aborted!" << endl;
        system("pause");
        exit(1);
    }
}
//Node<ItemType>* getNodeBefore(const ItemType& anEntry)const;
template<class ItemType>
Node<ItemType>* SortedList<ItemType>::getNodeBefore(ItemType& anEntry) const
{
    Node<ItemType>* curPtr = head;
    Node<ItemType>* prePtr = NULL;
    while ((curPtr != NULL) && (anEntry > curPtr->getItem())) {
        prePtr = curPtr;
        curPtr = curPtr->getNext();
    }
    return prePtr;
}
template<class ItemType>
void SortedList<ItemType>::insertSorted(ItemType& newEntry)
{
    //Create a new node containing the new entry
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry, NULL);
    Node<ItemType>* preNode = getNodeBefore(newEntry);
    if (isEmpty() || preNode == NULL) {
        //Add the new node to the beginning of the list
        newNodePtr->setNext(head);
        head = newNodePtr;
    }
    else {
        //Insert the new node
        newNodePtr->setNext(preNode->getNext());
        preNode->setNext(newNodePtr);
    }
    itemCount++;
}
template<class ItemType>
bool SortedList<ItemType>::removeSorted(const ItemType& anEntry)
{
    if (isEmpty())
        return false;
    else {
        Node<ItemType>* prePtr, * curPtr = head;
        prePtr = getNodeBefore(anEntry);
        if (prePtr == NULL) {
            if (curPtr->getItem() > anEntry)
                return false;
            else if (curPtr->getItem() == anEntry) {
                head = curPtr->getNext();
                curPtr->setNext(NULL);
                delete(curPtr);
                itemCount--;
            }
        }
        else {
            curPtr = prePtr->getNext();
            if (curPtr == NULL)
                return false;
            else if (curPtr->getItem() > anEntry)
                return false;
            else if (curPtr->getItem() == anEntry) {
                prePtr->setNext(curPtr->getNext());
                curPtr->setNext(NULL);
                delete(curPtr);
                itemCount--;
            }
        }
    }
    return true;
}
template<class ItemType>
int SortedList<ItemType>::getPosition(const ItemType& newEntry) const
{
    int position = 0;
    Node<ItemType>* nodePtr = head;
    if (nodePtr == NULL)
        position = 1;
    else {
        position = 1;
        while ((nodePtr != NULL) && newEntry > nodePtr->getItem()) {
            nodePtr = nodePtr->getNext();
            position++;
        }
    }
    return position;
}
template<class ItemType>
bool SortedList<ItemType>::contains(const ItemType anItem) const
{
    Node<ItemType>* cur = head;
    if (isEmpty())
        return false;
    else {
        while (cur != NULL) {
            if (cur->getItem() == anItem)
                return true;
            cur = cur->getNext();
        }
        return false;
    }
}
#endif /* SortedList_h */

