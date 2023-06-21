// Завдання 6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
void addToMap(map<char, int>& map, const string& word) {
    char initialLetter = word[0];    
    map[initialLetter] += word.size();  
}
void printEntry(const pair<char, int>& entry) {
    cout << entry.first << ": " << entry.second << endl;
}
int main()
{
    vector<string> V;

    cout << "Input words( print 'END' to stop):" << endl;
    string word;
    while (true) {
        cin >> word;
        if (word == "END") {
            break;
        }
        V.push_back(word);
    }

    map<char, int> M;   

    for_each(V.begin(), V.end(), [&](const string& word) {
        addToMap(M, word);  
        });

    for_each(M.begin(), M.end(), [&](const pair<char, int>& entry) {
        printEntry(entry);
        });
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
