#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string* dict;
int dictLength = 0;

string* history;
int histSize = 0;

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
	string abc = "��������������������������������";
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
			for (int k = 0; k < dictLength; k++)
			{
				if (current == dict[k] && current != in) {
					add(result, size, current);
					break;
				}
			}
		}
	}
	return result;
}

void game(string in, string out) {

	if (in == out) return;

	cout << in << ": ";

	int size = 0;
	string* newWords = generateWords(in, size);
	print(newWords, size);

	for (int i = 0; i < size; i++)
	{
		game(newWords[i], out);
	}

}


int main() {
	readDictionary("dict_len4_ansi.txt");

	string in = "����";
	string out = "����";

	game(in, out);



}