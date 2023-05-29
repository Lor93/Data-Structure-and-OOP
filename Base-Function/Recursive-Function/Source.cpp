#include<iostream>
using namespace std;

void display(int n) // Function that receive a positive integer n and print the integer
{
	n && (display(n - 1), cout << n << " " << endl);
}

int sumSquare(int n)  // function that receives a positive integer n and returns the sum of the squares of all the numbers from 1 to n
{
	if (n == 1)
		return 1;
	else
		return n * sumSquare(n -1);
	
}

bool containsZero(int a[], int length) // function that receives an integer array along with its length, the function returns true if the array contains 0, and returns false otherwise
{
	if (length == 0) {
		return false;
	}
	else {
		if (a[length - 1] == 0)
			return true;
		else
			return containsZero(a, length - 1);
	}
}

int min(int a[], int length) // function that receives an integer array along with its length and then returns minimum of the numbers in the array
{
	if (length == 1)
		return a[0];
	else
		if (a[0] > a[length - 1]);
	a[0] = a[length - 1];
	return min(a, length - 1);
	
}


int main()
{
	cout << sumSquare(5) << endl;
	const int ARRAY_SIZE = 5;
	int a[ARRAY_SIZE] = { 10, 1, 0, 20, 100 };
	cout << "The array " << (containsZero(a, ARRAY_SIZE) ? "does " : "does NOT ")
		<< "contain a 0.\n";
	cout << "The min in the array is " << (min(a, ARRAY_SIZE));
	cout << 5 << endl;
	display(5);
	return 0;

}
