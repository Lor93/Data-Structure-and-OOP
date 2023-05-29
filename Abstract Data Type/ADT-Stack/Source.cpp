#include<iostream>
#include "Stack.h"
#include<iomanip>
#include<string>
using namespace std;

int main()
{
	Stack<int> intStack;
	Stack<char> charStack;
	int r;
	for (int i = 0; i < 50; i++) {
		r = rand() % 100;
		if (r % 2 != 0) {
			intStack.push(r);
		}
		else {
			i--;
		}
	}
	intStack.display();
	cout << "Now we display odd numbers in the first half of the stack: " << endl;
	for (int i = 0; i < 25; i++) {
		intStack.pop();
	}
	int a; 
	for (int i = 0; i < 25; i++) {
		a = intStack.peek();
			cout << setw(5) << a;
		intStack.pop();
		}
	cout << endl;
	string str;
	cout << "Enter your string: ";
	getline(cin, str);
	int i = 0; 
	while (str[i] != '\0') {
		charStack.push(str[i]);
		i++;
	}
	charStack.display();
	cout << endl;
	while (!charStack.isEmpty()) {
		cout << charStack.peek() << endl;
		charStack.pop();
	}
	return 0;
}
