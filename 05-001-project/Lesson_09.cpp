#include <iostream>
#include <string>

using namespace std;
//
//bool in_array(int findMe, int* arr, int length) {
//
//	//bool flag = false;
//
//	for (int i = 0; i < length; i++)
//	{
//		if (arr[i] == findMe) {
//			//flag = true;
//			//break;
//			return true;
//		}
//	}
//	return false;
//	//return flag;
//}
//
//bool in_array(string findMe, string* arr, int length) {
//
//	for (int i = 0; i < length; i++)
//	{
//		if (arr[i] == findMe) {
//			return true;
//		}
//	}
//	return false;
//}

template<typename T>
bool in_array(T findMe, T* arr, int length) {

	for (int i = 0; i < length; i++)
	{
		if (arr[i] == findMe) {
			return true;
		}
	}
	return false;
}


// 73
// { 1, 4, 5, 7, 8, 19, 42, 56, 69, 73 };
bool binary_search(int findMe, int* arr, int length) {
	int left = 0;
	int right = length - 1;

	while (left <= right) {
		int middle = (right + left) / 2;
		if (arr[middle] < findMe) {
			left = middle + 1;
		}
		else if (arr[middle] > findMe) {
			right = middle - 1;
		}
		else {
			return true;
		}
	}


	return false;
}

int main() {

	int length = 10;
	int* arr = new int[length];

	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % 100;
		cout << " " << arr[i];
	}
	cout << endl;

	int findMe = 0;

	if (in_array(findMe, arr, length))
		cout << "FOUND!!!\n";
	else
		cout << "NOT FOUND!!!\n";

	if (in_array(123, arr, length))
		cout << "FOUND!!!\n";
	else
		cout << "NOT FOUND!!!\n";

	string* strs = new string[]{ "asdf", "asd", "fd", "123" };

	if (in_array(string("fd"), strs, length))
		cout << "FOUND!!!\n";
	else
		cout << "NOT FOUND!!!\n";

	// find 73
	int* sortedArr = new int[10] {1, 4, 5, 7, 8, 19, 42, 56, 69, 73};
	cout << "binary \n";
	if (binary_search(73, sortedArr, length))
		cout << "FOUND!!!\n";
	else
		cout << "NOT FOUND!!!\n";


	return 0;
}