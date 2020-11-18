// ControlWork1Ped.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

/*
Задание 1.
Создать массив до заданного числа такой, что каждый элемент больше предыдущего на 7.
Начальное значние задается в параметре.
Примеры:
 0, -1 => []
 0, 1 => [0]
 0, 7 => [0, 7]
 7, 7 => [7]
 10, 25 => [10, 17, 24]
*/

int* getSevensArray(int start, int limit) {
    int counter = 0;
    for (int i = start; i <= limit; i += 7) {
        counter++;
    }
    int* result = new int[counter];

    for (int i = start, j = 0; i <= limit; i += 7, j++) {
        result[j] = i;
    }

    return result;
}
/*
 Задание 2.

 Дана строка, содержащая ISBN. Например, "978-5-9775-0735-6". Проверить является ли ISBN валидным.
 ISBN состоит из 13 цифр. Последняя цифра контрольная в вычислениях не учавствует.
 Вычисляется по алгоритму EAN-13 следующим образом:
 1. вычисляется сумма цифр на четных позициях;
 2. полученная сумма умножается на три;
 3. вычисляется сумма цифр на нечетных местах;
 4. полученные числа в п.2 и п.3 складываем;
 5. отбрасываем десятки и отнимаем из 10, и получаем контрольную цифру.
 Если последняя цифра числа из п.4 = 0, то контрольная цифра равна нулю.
 Имейте ввиду, строка может содержать числа недостаточной длины, или дефисы могут быть где угодно.

 Пример:
 0. "978-5-9775-0735-6" =>  "9785977507356"
 1. 7+5+7+5+7+5 = 36
 2. 36 * 3 = 108
 3. 9+8+9+7+0+3 = 36
 4. 108 + 36 = 144
 5. 10 - 4 = 6
 6. 6 == 6

*/
bool isISBNValid(string isbn) {
    int pos = -1;
    while ((pos = isbn.find('-')) != string::npos) {
        isbn.erase(pos, 1);
    }
    if (isbn.size() != 13 || !(isbn[isbn.size() - 1] >= '0' && isbn[isbn.size() - 1] <= '9')) return false;
    int sum = 0;
    for (int i = 0; i < isbn.size() - 1; i++)
    {
        if (!(isbn[i] >= '0' && isbn[i] <= '9')) return false;
        if (i % 2 == 0) {
            sum += isbn[i] - '0';
        }
        else {
            sum += 3 * (isbn[i] - '0');
        }
    }

    return (10 - sum % 10) % 10 == isbn[isbn.size() - 1] - '0';
}

string printArray(int* array) {
    string result = "[";
    int length = _msize(array) / sizeof(int);
    for (int i = 0; i < length; i++)
    {
        result += to_string(array[i]) + (i < length - 1 ? ", " : "");
    }
    return result + "]\n";
}

void cw1()
{
    cout << "Task 1.";
    cout << " Sevens \"array\": \n";

    cout << "  Expected: [], actual: " << printArray(getSevensArray(0, -1));
    cout << "  Expected: [0], actual: " << printArray(getSevensArray(0, 1));
    cout << "  Expected: [0, 7], actual: " << printArray(getSevensArray(0, 7));
    cout << "  Expected: [-20, -13, -6], actual: " << printArray(getSevensArray(-20, -3));
    cout << "  Expected: [7], actual: " << printArray(getSevensArray(7, 7));
    cout << "  Expected: [10, 17, 24], actual: " << printArray(getSevensArray(10, 25));

    cout << "Task 2.\n";
    cout << "  ISBN 978-5-9775-0735-6 " << (isISBNValid("978-5-9775-0735-6") ? "true" : "false") << endl;
    cout << "  ISBN 978-1-60309-432-0 " << (isISBNValid("978-1-60309-432-0") ? "true" : "false") << endl;
    cout << "  ISBN 978-5-9775-0735-4 (wrong) " << (isISBNValid("978-5-9775-0735-4") ? "true" : "false") << endl;
    cout << "  ISBN 116 (wrong) " << (isISBNValid("116") ? "true" : "false") << endl;
    cout << "  ISBN 000 (wrong) " << (isISBNValid("000") ? "true" : "false") << endl;
    cout << "  not ISBN (wrong) " << (isISBNValid("asdfasdfasdff") ? "true" : "false") << endl;



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
