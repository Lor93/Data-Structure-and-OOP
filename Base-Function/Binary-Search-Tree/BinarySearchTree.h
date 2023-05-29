#ifndef _BINARYSEARCH_TREE
#define _BINARYSEARCH_TREE

#include"BinaryNode.h"
using namespace std;

template<class ItemType>
class BinarySearchTree
{
private:
	BinaryNode<ItemType>* rootPtr;
protected:
	void inOrderVisit(BinaryNode<ItemType>* treeRoot);

	void binarySearchAddHelper(BinaryNode<ItemType>* treeRoot, BinaryNode<ItemType>* newNodePtr);
	BinaryNode<ItemType>* getNodeHelper(BinaryNode<ItemType>* treeRoot, const ItemType& target) const;
	BinaryNode<ItemType>* removeEntry(BinaryNode<ItemType>* treeRoot, ItemType& target, bool& success);
	void removeNode(BinaryNode<ItemType>* nodeToBeRemoved);
	BinaryNode<ItemType>* removeLeftMost(BinaryNode<ItemType>* treeRoot, ItemType& nodeItem);
public:
	//Constructors
	BinarySearchTree();

	//Set and Get functions 
	ItemType getRootItem();
	void setRootItem(const ItemType& rootItem);

	//Other member functions
	void binarySearchAdd(ItemType& newItem);
	BinaryNode<ItemType>* getNode(const ItemType& target) const { return getNodeHelper(this->rootPtr, target); }
	void displayInorder();

	bool binarySearchRemove(ItemType anItem);
	bool isEmpty() const;
};
//Constructor
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{
	rootPtr = NULL;
}
//Set and get functions for the item in the root
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootItem()
{
	if (rootPtr != NULL)
		return rootPtr->getItem();
	else {
		cout << "Empty tree!\n";
		exit(1);
	}
}
template<class ItemType>
void BinarySearchTree<ItemType>::setRootItem(const ItemType& rootItem)
{
	if (rootPtr != NULL)
		rootPtr->setItem(rootItem);
	else
		rootPtr = new BinaryNode<ItemType>(rootItem, NULL, NULL);
}
//Protected functions
template<class ItemType>
void BinarySearchTree<ItemType>::inOrderVisit(BinaryNode<ItemType>* treeRoot)
{
	if (treeRoot == NULL)
		cout << "It is an empty tree!\n";
	else {
		if (treeRoot->getLeftChildPtr() != NULL) 
			inOrderVisit(treeRoot->getLeftChildPtr());
		cout << treeRoot->getItem() << endl;
		if (treeRoot->getRightChildPtr() != NULL)
			inOrderVisit(treeRoot->getRightChildPtr());
	}
}

//Other public member functions
template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
	return (rootPtr == NULL);
}
template<class ItemType>
void BinarySearchTree<ItemType>::displayInorder()
{
	inOrderVisit(rootPtr);
}
template<class ItemType>
void BinarySearchTree<ItemType>::binarySearchAddHelper(BinaryNode<ItemType>* treeRoot, BinaryNode<ItemType>* newNodePtr)
{
	if (this->rootPtr == NULL) {
		this->rootPtr = newNodePtr;
		return;
	}

	if (treeRoot != NULL) {
		if (treeRoot->getItem() > newNodePtr->getItem()) {	//new node has to go to left
			if (treeRoot->getLeftChildPtr() == NULL) {
				treeRoot->setLeftChildPtr(newNodePtr);
				return;
			}
			binarySearchAddHelper(treeRoot->getLeftChildPtr(), newNodePtr);
		}
		else if (treeRoot->getItem() < newNodePtr->getItem()) {	//new node has to go to right
			if (treeRoot->getRightChildPtr() == NULL) {
				treeRoot->setRightChildPtr(newNodePtr);
				return;
			}
			binarySearchAddHelper(treeRoot->getRightChildPtr(), newNodePtr);
		}
		else	//duplicate 
			return;
	}
}
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::getNodeHelper(BinaryNode<ItemType>* treeRoot, const ItemType& target) const
{
	if (this->rootPtr == NULL) {
		return NULL;
	}

	if (treeRoot != NULL) {
		if (treeRoot->getItem() > target) {	//new node has to go to left
			return getNodeHelper(treeRoot->getLeftChildPtr(), target);
		}
		else if (treeRoot->getItem() < target) {	//new node has to go to right
			return getNodeHelper(treeRoot->getRightChildPtr(), target);
		}
		else {
			return treeRoot;
		}
	}
	else	// at end of branch, no existing target match
		return NULL;


}
template<class ItemType>
void BinarySearchTree<ItemType>::binarySearchAdd(ItemType& newItem)
{
	BinaryNode<ItemType>* newNode = new BinaryNode<ItemType>(newItem);
	binarySearchAddHelper(this->rootPtr, newNode);
}
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeEntry(BinaryNode<ItemType>* treeRoot, ItemType& target, bool& success)
{
	if (treeRoot == NULL) {
		success = false;
		return NULL;
	}
	else {
		BinaryNode<ItemType>* current{ treeRoot };
		while (current != NULL && current->getItem() != target) {
			if (current->getItem() > target) {
				current = current->getLeftChildPtr();
			}
			else if (current->getItem() < target) {
				current = current->getRightChildPtr();
			}
		}
		if (current == NULL) {
			success = false;
			return NULL;
		}
		else {
			removeNode(current);
			success = true;
			return current;
		}
	}

}
template<class ItemType>
void BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType>* nodeToBeRemoved)
{
	if (nodeToBeRemoved == NULL)
		return;

	else if (nodeToBeRemoved->isLeaf()) {
		BinaryNode<ItemType>* current{ rootPtr };
		while (current->getLeftChildPtr() != nodeToBeRemoved && current->getRightChildPtr() != nodeToBeRemoved) {
			if (current->getItem() > nodeToBeRemoved->getItem()) {
				current = current->getLeftChildPtr();
			}
			else if (current->getItem() < nodeToBeRemoved->getItem()) {
				current = current->getRightChildPtr();
			}
		}
		if (current->getLeftChildPtr() == nodeToBeRemoved) {
			delete current->getLeftChildPtr();
			current->setLeftChildPtr(NULL);
		}
		else if (current->getRightChildPtr() == nodeToBeRemoved) {
			delete current->getRightChildPtr();
			current->setRightChildPtr(NULL);
		}
	}
	else if (nodeToBeRemoved->getLeftChildPtr() == NULL) {
		//nodeToBeRemoved = nodeToBeRemoved->getRightChildPtr();
		BinaryNode<ItemType>* rightNode{ nodeToBeRemoved->getRightChildPtr() };
		ItemType tmp = rightNode->getItem();
		removeNode(rightNode);
		nodeToBeRemoved->setItem(rightNode->getItem());
		rightNode->setItem(tmp);
	}
	else if (nodeToBeRemoved->getRightChildPtr() == NULL) {
		BinaryNode<ItemType>* current{ rootPtr };
		while (current->getLeftChildPtr() != nodeToBeRemoved && current->getRightChildPtr() != nodeToBeRemoved) {
			if (current->getItem() > nodeToBeRemoved->getItem()) {
				current = current->getLeftChildPtr();
			}
			else if (current->getItem() < nodeToBeRemoved->getItem()) {
				current = current->getRightChildPtr();
			}
		}
		if (current->getLeftChildPtr() == nodeToBeRemoved) {
			current->setLeftChildPtr(nodeToBeRemoved->getLeftChildPtr());
			delete nodeToBeRemoved;
		}
		else if (current->getRightChildPtr() == nodeToBeRemoved) {
			current->setRightChildPtr(nodeToBeRemoved->getLeftChildPtr());
			delete nodeToBeRemoved;

		}
	}
	else {
		ItemType tmp;
		removeLeftMost(nodeToBeRemoved, tmp);
		nodeToBeRemoved->setItem(tmp);
	}
}
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftMost(BinaryNode<ItemType>* treeRoot, ItemType& nodeItem)
{

	BinaryNode<ItemType>* leftMost{ treeRoot }, * leftMostParent{ NULL };

	while (leftMost->getLeftChildPtr() != NULL) {
		leftMostParent = leftMost;
		leftMost = leftMost->getLeftChildPtr();
	}

	leftMostParent->setLeftChildPtr(NULL);
	nodeItem = leftMost->getItem();
	delete leftMost;
	return treeRoot;

}
template<class ItemType>
bool BinarySearchTree<ItemType>::binarySearchRemove(ItemType anItem)
{
	bool removal{ false };
	removeEntry(this->rootPtr, anItem, removal);
	return removal;
}

#endif //