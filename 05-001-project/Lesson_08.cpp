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

string* generateWords(string in, int& size) {
	add(history, histSize, in);
	string abc = "àáâãäå¸æçèéêëìíîïðñòóôõö÷øùúûüýþÿ";
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
			if (in_array(current, dict, dictLength) && current != in) {
				add(result, size, current);
			}
		}
	}
	return result;
}

void game(string in, string out) {

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


int main4() {
	readDictionary("dict_len4_ansi.txt");

	string in = "ñòóê";
	string out = "ñëîí";

	game(in, out);


	return 0;
}