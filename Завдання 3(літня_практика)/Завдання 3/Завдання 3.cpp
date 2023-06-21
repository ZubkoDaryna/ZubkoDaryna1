// Завдання 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
string removeWords(const string& firstText, const string& secondText) {
    istringstream iss(firstText);  
    ostringstream oss;         

    string word;
    while (iss >> word) {  
        word.erase(remove_if(word.begin(), word.end(), [](char c) { 
            return !isalpha(c); 
            }), word.end());
        if (secondText.find(word) == string::npos) { 
            oss << word << " ";
        }
    }

    return oss.str();
}
int main()
{
    string firstText, secondText, inputFile, outputFile;

    cout << "Enter the input file name: ";
    getline(cin, inputFile);

    cout << "Enter the output file name: ";
    getline(cin, outputFile);

    cout << "Enter the first text: ";
    getline(cin, firstText);
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

    ofstream input(inputFile);
    if (!input) {
        cout << "Failed to create input file." << endl;
        return 1;
    }
    input << firstText << endl;
    input.close();

    cout << "Enter the second text: ";
    getline(cin, secondText);

    string modifiedText = removeWords(firstText, secondText);

    ofstream output(outputFile);
    if (!output) {
        cout << "Failed to create output file." << endl;
        return 1;
    }
    output << modifiedText << endl;

    output.close();

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
