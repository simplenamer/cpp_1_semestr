// 05-001-project.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

/*
Lesson 02.

@author Shamil Khaydarov
*/

int main()
{
    //setlocale(LC_ALL, "RUS");
    //cout << "Hello World!\n" << endl;

    //// тип название;
    //// тип название = значение;
    //// тип название1 = значение2, название2, название3 = знач3;

    //cout << sizeof(short) << endl;
    //cout << sizeof(short int) << endl;
    //cout << sizeof(int) << endl;
    //cout << sizeof(long) << endl;
    //cout << sizeof(long int) << endl;
    //cout << sizeof(long long) << endl;
    //cout << sizeof(long long int) << endl;

    //cout << sizeof(float) << endl;
    //cout << sizeof(double) << endl;

    //unsigned int k = 3;

    //char str[12];

    //char str2[] = "Hello world"; // Hello world\0
    //char str3[] = {'H', 'e', 'l', 'l', 'o', '\0'};

    //cout << "Enter value: \n";
    //cin >> str;

    //cout << str << endl;

    //bool b = true;

    //if (k == 0 && (k < 10 || k > 3)) {  // ==, >, <, >=, <=, !=
    //    cout << "k equals zero\n";
    //}
    //if (k == 3) {
    //    cout << "k equals three\n";
    //}
    //else if (k == 4) {
    //    cout << "k equals four\n";
    //}
    //else {
    //    cout << "not 3, not 4\n";
    //}
    int h;
    // exit(1);

    // +, -, *, /, %
    // 2 *  n

    cout << "Enter hour:\n";
    cin >> h;
    
    if (!(h >= 0 && h <= 23)) {
        cout << "Wrong input!!! Exiting...\n";
        exit(1);
    }

    if (h >= 8 && h <= 17 && h != 12) {
        cout << "Working hours.\n";
    }
    else {
        cout << "Not work!\n";
    }

    char c;
    double a, b, ans;
    cout << "Enter a:\n";
    cin >> a;
    cout << "Enter b:\n";
    cin >> b;
    cout << "Enter operation:\n";
    cin >> c;

    switch (c)
    {
    case '+':
        ans = a + b;
        break;
    default:
        break;
    }

    cout << "Anser: " << ans << endl;

    //switch (k)
    //{
    //case 3:
    //    cout << "k equals three\n";
    //    break;
    //case 4:
    //case 5:
    //    cout << "k equals five\n";
    //    break;
    //default:
    //    break;
    //}
    
    // && - AND: true && true = true, true && false = false
    // || - OR: true || true = true, true || false = true
    // !: !true = false



    return 0;
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

