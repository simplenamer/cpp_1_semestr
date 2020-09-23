// lesson_03.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;


int main()
{
	
	int length = 6;
	cout << "* * * * * * * *" << endl; // 0
	
	// init - 1; test - 2; update - 4
	for (int i = 0; i < length; i++)
	{
		cout << "*             *" << endl;  // 3 
	}
	cout << "* * * * * * * *" << endl << endl;  // 5

	cout << "For10. 1/n" << endl;
	double sum = 1;
	for (int i = 2; i <= length; i++)
	{
		//1 / (double)(i);
		sum += 1.0 / i;
	}

	cout << "sum = " << sum << endl;

	cout << "For17. 1 + a + a^2 - ... + a^n.\n";

	double a = 3;
	sum = 1;
	double power = 1;

	for (int i = 1; i <= 3; i++)
	{
		power *= a;
		sum += power;
	}
	cout << "sum = " << sum << endl << endl;

	cout << "For18. 1 - a + a^2 - ... + (-1)^n a^n.\n";

	a = 3;
	sum = 1;
	power = 1;
	int k = 1;
	for (int i = 1; i <= 3; i++)
	{
		//k *= -1;
		//power *= k * a;
		power *= -a;
		sum += power;
	}
	cout << "sum = " << sum << endl << endl;


	cout << "For21. 1 + 1/1! + ... + 1/n!" << endl;

	power = 1;
	sum = 2;
	for (int i = 2; i <= length; i++)
	{
		power *= 1.0 / i;
		sum += power;
	}

	cout << "exp = " << sum << endl;
	cout << endl;

	cout << "square\n";
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	
	cout << endl;

	length = 10;

	cout << "left triangle\n";
	for (int i = 1; i <= length; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	
	cout << "right triangle\n";
	for (int i = 1; i <= length; i++)
	{
		for (int j = length - i - 1; j >= 0; j--) 
		//for (int j = 0; j < length - i; j++) 
		{
			cout << "  ";
		}
		for (int j = 0; j < i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "For36. Find 1^k + 2^k + ... + N^k." << endl;

	k = 5;
	sum = 0;
	for (int i = 0; i < length; i++)
	{
		double pow = 1;
		for (int j = 0; j < k; j++)
		{
			pow *= i;
		}
		sum += pow;
	}

	cout << "sum = " << sum << endl; // \n

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
