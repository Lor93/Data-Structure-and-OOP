#ifndef _Bag
#define _Bag
#include<iostream>
using namespace std;

class Bag // Class Definition
{
private:
	int item[100];
	int itemCount;
public:
	Bag(); // Default Constructor
	int getItemCount();
	bool isEmpty();
	void add(int newItem);
	void remove(int item);
	void display();
	void clear();
	bool contains(int anItem);
};
Bag::Bag()// Default Constructor
{
	itemCount = 0;
}
int Bag::getItemCount()
{
	return itemCount;
}
bool Bag::isEmpty()
{
	return (itemCount == 0);
}
void Bag::add(int newItem)
{
	if (itemCount == 10)
		cout << "The bag is full!" << endl;
	else {
		item[itemCount] = newItem;
		itemCount++;
	}
}
void Bag::display()
{
	for (int i = 0; i < itemCount; i++) {
		cout << item[i] << endl;
	}
}
bool Bag::contains(int anItem)
{
	for (int i = 0; i < itemCount; i++) {
		if (item[i] == anItem)
			return true;
	}
	return false;
}
void Bag::remove(int anitem)
{
	if (isEmpty()) {
		cout << "Removal is unable to process! The bag is empty!" << endl;
	}
	else if (!contains(anitem)) {
		cout << "Removal is unable to process! THe item is not in the bag." << endl;
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
void Bag::clear()
{
	itemCount = 0;
}
#endif
