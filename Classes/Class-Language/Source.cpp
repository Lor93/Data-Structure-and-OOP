#include<iostream>
#include "Stack.h"
#include<string>
using namespace std;

bool isinLanguage(string aString);
bool isinLanguage_2(string aString);

int main()
{
	cout << "isinLanguage()  " << (isinLanguage("abc$cba") ? "palindrone" : "not palidrone") << endl;
	cout << "isinLanguage_2()  " << (isinLanguage_2("abc$abc") ? "palindrone" : "not palidrone") << endl;

	return 0;
}

/*isInLanguage1 Function*/
bool isinLanguage(string aString)
{
	Stack<char> charStack;
	int mid = aString.size() / 2;	//middle index
	if (aString.at(mid) != '$') {
		return false;
	}
	for (int i = 0; i < aString.size(); i++) {
		charStack.push(aString[i]);
	}
	int j = 0;
	if (aString.size() - 1) {
		charStack.peek();
	}
	while (charStack.peek() != aString[mid]) {
		charStack.peek();
		if (charStack.peek() == aString[j]) {
			charStack.pop();
			j++;
		}
		else {
			return false;
		}

	}
	return true;
}


bool isinLanguage_2(string aString)
{
	Stack<char> charStack;
	int mid = aString.size() / 2;
	for (int i = 0; i < aString.size(); i++) {
		charStack.push(aString[i]);
	}
	int j = 0;
	if (aString.size() - 1) {
		charStack.peek();
	}
	while (charStack.peek() != aString[mid]) {
		charStack.peek();
		if (charStack.peek() == aString[j]) {
			charStack.pop();
			j++;
		}
		else {
			return false;
		}

	}
	return true;

}
