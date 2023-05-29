#include<iostream>
#include "Bag.h"
using namespace std;

int main()
{
	Bag<int> intBag;
	for (int i = 0; i < 10; i++){
		intBag.add(rand() % 100);
	}
	intBag.display();
	intBag.removeMax();
	intBag.removeMin();
	cout << "====================" << endl;
	intBag.display();
	cout << "====================" << endl;
	cout << "The sum of all the data items in the bag is: " << intBag.getSum()  << endl;
	cout << "The average sum of all integer is: " << intBag.getSum() / intBag.getItemCount()  << endl;

	return 0;
}
