// Завдання 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
void printList(const list<string>& words)
{
    for (auto it = words.rbegin(); it != words.rend(); ++it) 
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    list<string> L1;
    list<string> L2;
    string word;

    cout << "Input words for L1(print 'END' to stop):\n";
    while (true)
    {
        cin >> word;
        if (word == "END")
            break;
        L1.push_back(word);
    }

    cout << "Input words for L2(print 'END' to stop):\n";
    while (true)
    {
        cin >> word;
        if (word == "END")
            break;
        L2.push_back(word);
    }

    list<string> result;

    for (const auto& word : L1)
    {
        if (find(L2.begin(), L2.end(), word) == L2.end())
        {
            result.push_back(word);
        }
    }

    // Виведення результату
    printList(result);
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
