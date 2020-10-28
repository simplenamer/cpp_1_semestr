#include<iostream>
#include<string>

#define out(X) (cout << #X << " = " << X << endl)

using namespace std;

// asdf kj hg, " " 
int findCount(string str, string find) {
	int pos = 0;
	int count = 0;
	while ((pos = str.find(find, pos + 1)) != string::npos) {
		count++;
	}
	return count;
}

string* split(string str, string delimeter = " ") {
	int length = findCount(str, delimeter);
	string* result = new string[length];


	return result;
}
// split("str ing example", "string") => ["", " example"]1


void lesson_07() {
	char ch = 'a';
	cout << "ch = " << ch << endl;
	cout << "(int)ch = " << (int)ch << endl;
	cout << ch + ch << endl;

	char str[] = "string example"; // \0
	char str2[15] = "string example"; // \0
	char str3[] = { 'a', 's', 'd', 'f', '\0' };
	const char* str4 = "simple text";

	for (int i = 0; i < strlen(str4); i++)
	{
		cout << "str4_i" << i << " = " << str4[i] << endl;
	}
	
	for (int i = 0; str4[i] != '\0'; i++)
	{
		cout << "str4_i" << i << " = " << str4[i] << endl;
	}

	string str5 = "string text example";
	string str6 = "asdf1234";
	cout << sizeof(char) << endl;
	cout << str6 << "\n";
	int count = 0;
	for (int i = 0; i < str6.size(); i++) //size() == length()
	{
		//str6[i];
		if (str6.at(i) >= '0' && str6.at(i) <= '9') {
			count++;
		}
	}

	cout << "digits count is " << count << ".\n";

	string str7("asdf");
	string str8(10, 'a');

	cout << str6 + str7 << endl; // concat

	str6.operator+=("123");
	str6 += "123";

	//str6.empty() 
	//str6.clear();

	// element access
	out(str6[0]);
	out(str6.at(1));
	out(str6.front());
	out(str6.back());
	out(str6.substr(4, 2));

	// modifying
	str6.append("ASDF");
	out(str6);
	str6.insert(4, "0000");
	out(str6);
	str6.erase(0, 4);
	out(str6);
	str6.replace(0, 3, "FFFFFF");
	out(str6);
	str6.push_back('z');
	str6.push_back('z');
	out(str6);
	str6.pop_back();
	out(str6);

	cout << "finded 01 at " << str6.find("01") << endl;
	cout << "finded afasf at " << (int) str6.find("afasf") << endl;
	cout << "finded FFF at " << str6.find("FFF") << endl;
	cout << "finded FFF at " << str6.rfind("FFF") << endl;
	//std::string str8;
	//"asdfasdfasdf", "f" => {asd, asd, asd}
	//"asdf asd fd" " " => "asdf", "asd", "fd"

	string str9 = "asdf asdf asdf";
	out(findCount(str9, "asdf"));
	out(findCount(str9, " "));



}

//int main() {
//	lesson_07();
//}