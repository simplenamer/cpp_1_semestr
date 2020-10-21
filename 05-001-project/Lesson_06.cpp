#include<iostream>
#include<malloc.h>
using namespace std;

void swap(int a, int b) {
	cout << "swap &a = " << &a << endl;
	int t = a;
	a = b;
	b = t;

	cout << "In swap function:\n";
	cout << "a = " << a << ", b = " << b << endl;
}

void swap2(int& a, int& b) {
	cout << "swap2 &a = " << &a << endl;
	int t = a;
	a = b;
	b = t;
}

void swap3(int*& a, int*& b) {
	int t = *a;
	a = b;
	b = &t;
	cout << "In swap3 function:\n";
	cout << "&a = " << a << endl;
	cout << "a = " << *a << ", b = " << *b << endl;
}

void doubleArrayElements(int* arr) {
	int length = _msize(arr) / sizeof(int);
	for (int i = 0; i < length; i++)
	{
		arr[i] = arr[i] * 2;
	}
}

void printArray(int* arr, int n = -1) {
	cout << "[";
	int length = n == -1 ? _msize(arr) / sizeof(int) : n;
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << (i < length - 1 ? ", " : "]\n");
	}
}

void removeElement(int*& arr, int index) {
	int length = _msize(arr) / sizeof(int);
	int* newArray = new int[length - 1];
	for (int i = 0, j = 0; i < length; i++)
	{
		if (i == index - 1) continue;
		newArray[j] = arr[i];
		j++;
	}
	arr = newArray;
}

int* removeEvenElements(int* arr) {
	int length = _msize(arr) / sizeof(int);
	int* newArray = new int[length - 1];
	return newArray;
}

void lesson_06() {
	int a = 5, b = 10;
	cout << "main &a = " << &a << endl;
	cout << "Before:\n";
	cout << "a = " << a << ", b = " << b << endl;
	swap(a, b);
	swap2(a, b);
	
	cout << "After swap2:\n";
	cout << "a = " << a << ", b = " << b << endl;
	int* pA = &a, *pB = &b;
	swap3(pA, pB);

	cout << "After swap3:\n";
	cout << "a = " << a << ", b = " << b << endl;

	int ints[3] = {1, 2, 3};

	cout << "ints = " << ints << endl;
	cout << "ints[0] = " << *ints << endl;
	cout << "ints[1] = " << *(ints + 1) << endl;

	int* ptr = &a;
	*ptr = 51;
	cout << "ptr = " << *ptr << endl;
	a = 11;
	cout << "after ptr = " << *ptr << endl;

	int* ptr2 = new int(123);
	cout << "ptr2 = " << *ptr2 << endl;

	int* ptr3 = nullptr;

	cout << "value a = " << a << endl;
	cout << "reference of a = " << &a << endl;
	cout << "pointer ptr = " << ptr << endl;
	cout << "pointer ptr value = " << *ptr << endl;

	delete ptr3;

	int length = 10;
	int* ptrInts = new int[length];
	cout << "Before:\n";
	for (int i = 0; i < length; i++)
	{
		ptrInts[i] = i + 1;
		cout << ptrInts[i] << (i < length - 1 ? ", " : "\n");
	}

	doubleArrayElements(ptrInts);

	cout << "After:\n";
	for (int i = 0; i < length; i++)
	{
		cout << ptrInts[i] << (i < length - 1 ? ", " : "\n");
	}
	int k = 3;
	for (int i = k - 1; i < length - 1; i++)
	{
		ptrInts[i] = ptrInts[i + 1];
	}

	
	printArray(ptrInts);
	removeElement(ptrInts, 3);
	printArray(ptrInts);
	printArray(removeEvenElements(ptrInts));

	int first = ptrInts[0];
	for (int i = 0; i < length - 1; i++)
	{
		ptrInts[i] = ptrInts[i + 1];
	}
	ptrInts[length - 1] = first;





	//k = 1: 1, 3, 4, 6 => 6, 1, 3, 4
	//k = -1: 1, 3, 4, 6 => 3, 4, 6, 1
	//k = any

}