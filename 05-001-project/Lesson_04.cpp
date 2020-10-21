
#include <iostream>
#include "Lesson_04.h"
#include <time.h>
#define size(X) (sizeof(X) / sizeof(int))
#define PI 3.1415

#define sqr(X) ((X) * (X)) // 2 + 3 * 2 + 3
#define out(X) (cout << #X << " = " << X << endl)


using namespace std;


void powerOfThree(int n) {
	double d = n;
	while (d >= 3)
	{
		d /= 3;
	}
	/*if (n == 1) {
		cout << "TRUE\n";
	}
	else {
		cout << "FALSE\n";
	}*/

	cout << (d == 1 ? "TRUE\n" : "FALSE\n");
}

double f(double x, double y) {
	return sin(x) + cos(y);
}

int doubleFactorial(int n) {
	int result = 1;
	if (n % 2 == 0) {
		for (int i = 2; i <= n; i+=2)
		{
			result *= i;
		}
	}
	else 
	{
		for (int i = 1; i <= n; i+=2)
		{
			result *= i;
		}
	}

	return result;
}

int doubleFactorial2(int n) {
	int result = 1;
	// n % 2 == 0
	
	for (int i = 2 - n % 2; i <= n; i+=2)
	{
		result *= i;
	}

	return result;
}

int doubleFactorial3(int n) {
	int result = 1;
	
	while (n >= 1)
	{
		result *= n;
		n -= 2;
	}

	return result;
}

void printArray(int arr[], int size) {
	cout << "{";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
		if (i != size - 1) cout << ", ";
	}
	cout << "}\n";
}

void lesson_04()
{
	int length = 5;

	for (int i = 1; i <= length; i++)
	{
		for (int j = length; j > i; j--)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * i - 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	int k = 0;
	while (k < length) {
		k++;
	}

	int a = 13, b = 3;
	while (a > b) {
		a -= b;
	}
	cout << "a = " << a << endl << endl;
	
	powerOfThree(81);
	powerOfThree(83);
	powerOfThree(811212);

	cout << "doubleFactorial:\n";
	cout << "5!! = " << doubleFactorial(5) << endl;
	cout << "6!! = " << doubleFactorial(6) << endl;

	cout << "doubleFactorial2:\n";
	cout << "5!! = " << doubleFactorial2(5) << endl;
	cout << "6!! = " << doubleFactorial2(6) << endl;
	
	cout << "doubleFactorial3:\n";
	cout << "5!! = " << doubleFactorial3(5) << endl;
	cout << "6!! = " << doubleFactorial3(6) << endl;

	//do {

	//} while (true)
	//{

	//}


	for (int i = 0; i < 10; i++)
	{
		if (i == 2) {
			continue;
		}
		if (i == 4) {
			break;
		}
		cout << i << " ";
	}
	cout << endl;


	// type name[size];

	const int n = 10;

	int anArray[n]; // [0; n), [0; n-1]

	//anArray[0];
	int secondArray[4] = { 1, 2, 3 };


	for (int i = 0; i < n; i++)
	{
		anArray[i] = rand() % 201 - 100;
		cout << anArray[i] << " ";
	}
	cout << endl;

	int max = anArray[0];
	for (int i = 1; i < n; i++)
	{
		if (max < anArray[i]) {
			max = anArray[i];
		}
	}
	cout << "max = " << max << endl;

	int arr[] = {1, 2, 1, 5, 2, 5};
	int min = arr[0];
	for (int i = 1; i < sizeof(arr) / sizeof(int); i++)
	{
		if (min > arr[i]) {
			min = arr[i];
		}
	}

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		if (min == arr[i]) {
			cout << "i = " << i << endl;
			break;
		}
	}

	int arr1[] = { 1, 3, 5 };
	int arr2[] = { 2, 4, 6 };

	a = 1;
	b = 2;

	int t = a;
	a = b;
	b = t;
	cout << "arr1 = ";
	printArray(arr1, size(arr1));
	cout << "arr2 = ";
	printArray(arr2, size(arr2));

	for (int i = 0; i < size(arr1); i++)
	{
		int t1 = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = t1;
	}
	cout << "arr1 = ";
	printArray(arr1, size(arr1));
	cout << "arr2 = ";
	printArray(arr2, size(arr2));

	cout << PI << endl;

	cout << sqr(2 + 3) << endl;
	out(doubleFactorial2(4));
}