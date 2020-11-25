#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string* dict;
int dictLength = 0;

string* history;
int histSize = 0;


bool in_array(string findMe, string* arr, int length) {

	for (int i = 0; i < length; i++)
	{
		if (arr[i] == findMe) {
			return true;
		}
	}
	return false;
}

void readDictionary(const char* filename) {
	setlocale(LC_ALL, "ru_RU");
	ifstream file(filename);

	if (file.is_open()) {
		char* line = new char();
		
		while (file.getline(line, 6)) {
			dictLength++;
		}
		cout << dictLength << endl;

		dict = new string[dictLength];

		file.clear();
		file.seekg(0);

		for (int i = 0; file.getline(line, 6); i++)
		{
			dict[i] = line;
			//cout << dict[i] << endl;
		}
		file.close();
	}
}

void add(string*& strs, int& size, string newValue) {
	string* result = new string[size + 1];

	for (int i = 0; i < size; i++)
	{
		result[i] = strs[i];
	}
	result[size] = newValue;
	size++;
	strs = result;
}

void print(string* strs, int& size) {
	cout << "[";
	for (int i = 0; i < size; i++)
	{
		cout << strs[i] << (i < size - 1 ? ", " : "]\n");
	}
}

int compareStrings(const string& left, const string& right) {

	int length = min(left.length(), right.length());
	string abc = "אבגדהו¸זחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ";
	// todo
	for (int i = 0; i < length; i++)
	{
		unsigned char c1 = (left.at(i)) * 2;
		unsigned char c2 = (right.at(i)) * 2;
		if ((left.at(i)) == '¸') {
			c1 = 'ו' * 2 + 1;
		}

		if ((right.at(i)) == '¸') {
			c2 = 'ו' * 2 + 1;
		}

		//if (c1 != c2) return c1 - c2;

		if (c1 < c2) {
			return -1;
		}

		if (c1 > c2) {
			return 1;
		}
	}
	//return left.length() - right.length();
	if (left.length() < right.length()) return -1;
	else if (left.length() > right.length()) return 1;

	return 0;
}

bool binary_search(string& findMe, string*& arr, int length) {
	int left = 0;
	int right = length - 1;

	while (left <= right) {
		int middle = (right + left) / 2;
		//if (arr[middle] < findMe) {
		if (compareStrings(arr[middle], findMe) < 0) {
			left = middle + 1;
		}
		//else if (arr[middle] > findMe) {
		else if (compareStrings(arr[middle], findMe) > 0) {
			right = middle - 1;
		}
		else {
			return true;
		}
	}

	return false;
}

string* generateWords(string& in, int& size) {
	add(history, histSize, in);
	string abc = "אבגדהו¸זחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ";
	int count = 0;
	//int size = 0;
	string* result = new string[size];
	for (int i = 0; i < in.size(); i++)
	{
		string current = in;
		for (int j = 0; j < abc.length(); j++)
		{
			current[i] = abc[j];
			//current.replace(i, 1, abc.substr(j, 1));
			if (current != in && binary_search(current, dict, dictLength)) {
				add(result, size, current);
			}
		}
	}
	return result;
}

void game(string& in, string& out) {

	if (in == out) return;

	cout << in << ": ";

	int size = 0;

	add(history, histSize, in);
	string* newWords = generateWords(in, size);
	print(newWords, size);

	for (int i = 0; i < size; i++)
	{
		if (!in_array(newWords[i], history, histSize)) {
			game(newWords[i], out);
		}
	}

}


int main() {
	readDictionary("dict_len4_ansi.txt");

	string in = "סעףך";
	string out = "סכמם";

	game(in, out);


	return 0;
}