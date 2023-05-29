#ifndef _Bag
#define _Bag
#include<iostream>
//#include"Rectangle.h"
using namespace std;

template<class ItemType>
class Bag // Class Definition
{
private:
	ItemType item[100];
	int itemCount;
public:
	Bag(); // Default Constructor
	int getItemCount();
	int getFrequenceOf();
	int getMax();
	bool isEmpty();
	void add(ItemType newItem);
	void remove(ItemType anitem);
	void clear();
	void display();
	bool contains(ItemType anItem);
	bool removeMax();
	bool removeMin();
	ItemType getSum();
	ItemType getMin();

};
template<class ItemType>
Bag<ItemType>::Bag()// Default Constructor 
{
	itemCount = 0;
}
template<class ItemType>
int Bag<ItemType>::getItemCount()
{
	return itemCount;
}
template<class ItemType>
bool Bag<ItemType>::isEmpty()
{
	if (itemCount == 0)
		return true;
	else
		return false;
}
template<class ItemType>
void Bag<ItemType>::clear()
{
	itemCount = 0;
}
template<class ItemType>
void Bag<ItemType>::add(ItemType newItem)
{
	if (itemCount == 100)
		cout << "The bag is full!" << endl;
	else {
		item[itemCount] = newItem;
		itemCount++;
	}
}
template<class ItemType>
void Bag<ItemType>::display()
{
	
	for (int i = 0; i < itemCount; i++) {
		cout << item[i] << endl;
	}
}
template<class ItemType>
bool Bag<ItemType>::contains(ItemType anItem)
{
	for (int i = 0; i < itemCount; i++) {
		if (item[i] == anItem)
			return true;
	}
	return false;
}
template<class ItemType>
void Bag<ItemType>::remove(ItemType anitem)
{
	if (isEmpty()) {
		cout << "Removal is unable to process! The bag is empty!" << endl;
	}
	else if (!contains(anitem)) {
		cout << "Removal is unable to process! The item is not in the bag." << endl;
	}
	else {
		// finding the first index of the item
		int index = 0;
		for (int i = 0; i < itemCount; i++) {
			if (item[i] == anitem) {
				index = i;
				break;
			}
		}
		//Shifting all the number on the right
		for (int i = index; i < itemCount - 1; i++) {
			item[i] = item[i + 1];
		}
		itemCount--;
	}
}
template<class ItemType>
int Bag<ItemType>::getFrequenceOf()
{
	if (isEmpty())
		return 0;
	else {
		int counter = 0;
		for (int i = 0; i < itemCount; i++) {
			if (itemCount[i] == item)
				counter++;
		}
		return counter;
	}
}
template<class ItemType>
int Bag<ItemType>::getMax()
{
	if (isEmpty()) {
		cout << "The bag is empty!" << endl;
	}
	else {
		ItemType m = itemCount[0];
		for (int i = 0; i < itemCount; i++) {
			if (itemCount[i] > m)
				m = itemCount[0];
		}
		return m;
	}
}
template<class ItemType>
bool Bag<ItemType>::removeMax()
{
	if (isEmpty())
		return false;
	else {
		ItemType a = item[0];
		for (int i = 1; i < itemCount; i++) {
			if (item[i] > a)
				a = item[i];
		}
		remove(a);
		return true;
	}
}
template<class ItemType>
bool Bag<ItemType>::removeMin()
{
	if (isEmpty())
		return false;
	else {
		ItemType a = item[0];
		for (int i = 1; i < itemCount; i++) {
			if (item[i] < a)
				a = item[i];
		}
		remove(a);
		return true;
	}
}
template<class ItemType>
ItemType Bag<ItemType>::getSum()
{
	if (isEmpty())
		exit(1);
	else {
		ItemType a = item[0];
		for (int i = 1; i < itemCount; i++) {
			a += item[i];
		}
		return a;
	}
}
template<class ItemType>
ItemType Bag<ItemType>::getMin()
{
	if (isEmpty())
		exit(1);
	else {
		ItemType a = item[0];
		for (int i = 1; i < itemCount; i++) {
			a -= item[i];
		}
		return a;
	}
}

#endif Bag.h
