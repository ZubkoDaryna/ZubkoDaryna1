// Практика.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;
double computeA(int k);
double computeB(int k);
double factorial(int num);

//Обчислення a_k
double computeA(int k)
{
    if (k == 1)
        return 1;
    else
        return 0.3 * computeB(k - 1) + 0.2 * computeA(k - 1);
}

// Обчислення b_k
double computeB(int k)
{
    if (k == 1)
        return 1;
    else      
        return pow(computeA(k - 1), 2) + pow(computeB(k - 1), 2);
}
// Обчислення суми ряду
double computeSum(int n)
{
    double sum = 0;
    for (int k = 1; k <= n; k++)
    {
        double term = (computeA(k) * computeB(k)) / factorial(k + 1);
        sum += term;
    }
    return sum;
}
// Факторіал
double factorial(int num)
{
    if (num == 0)
        return 1;
    else
        return num * factorial(num - 1);
}
int main() {
 int n;
    cout << "Input n: ";
    cin >> n;

    double Sum = computeSum(n);
    cout << "Sum: " << Sum << endl;
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
