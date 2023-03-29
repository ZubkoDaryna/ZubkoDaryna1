// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include<complex>

using namespace std;
////////////////////////////////////////////////          Task 1          ////////////////////////////////////////////////
class Parallelogram
{
    double a; // основа
    double b; // бічна сторона
    double h; // висота
    unsigned int color;

public://Конструктори зі стандартними або заданими значеннями для параметрів
    Parallelogram() : a(0), b(0), h(0), color(0) {}
    Parallelogram(double ai, int c) : a(ai), b(0), h(0), color(c) {}
    Parallelogram(double ai, double bi, double hi, int ci) : a(ai), b(bi), h(hi), color(ci) {}

    double getA() const { return a; }
    void setA(double a)
    {
        if (a < 0 || a > 1.e+100)
        {
            cout << "Error setting a" << endl;
            return;
        }
        this->a = a;
    }

    double getB() const { return b; }
    void setB(double b)
    {
        if (b < 0 || b > 1.e+100)
        {
            cout << "Error setting b" << endl;
            return;
        }
        this->b = b;
    }

    double getH() const { return h; }
    void setH(double h)
    {
        if (h < 0 || h > 1.e+100)
        {
            cout << "Error setting h" << endl;
            return;
        }
        this->h = h;
    }

    unsigned int getColor() const { return color; }
    void setColor(unsigned int c)
    {
        if (c < 0 || c > 10000)
        {
            cout << "Error setting color" << endl;
            return;
        }
        this->color = c;
    }

    double S() const { return h * a; }
    double P() const { return 2 * (a + b); }
    // Друк інформації про паралелограм
    void printInfo() const
    {
        cout << " a = " << a <<endl <<" b = " << b <<endl<< " h = " << h << endl<<" color = " << color<<endl;
        cout << endl << "Your result:"<<endl;
        cout << endl << " S = " << S() << "\t P = " << P() << endl;
    }
};
////////////////////////////////////////////////          Task 2         /////////////////////////////////////////////////////////////////////////
#define _SILENCE_NONFLOATING_COMPLEX_DEPRECATION_WARNING
#pragma warning(disable : 4996)
typedef complex<short> ComplexShort;
class ComplexVector
{
    ComplexShort* v; // вказівник на масив комплексних чисел
    int num;// кількість елементів у масиві
    int state; // стан вектора
public:
    //1
    ComplexVector() : v(NULL), num(0), state(0) {}//// ініціалізує змінні значеннями за замовчуванням

    ComplexVector(int n);// конструктор, який створює вектор розміром n
    ComplexVector(int n, ComplexShort&); //конструктор, який створює вектор розміром n та ініціалізує його комплексним числом
    ComplexVector(int n, ComplexShort*);
    // конструктор, який створює вектор розміром n та ініціалізує його масивом комплексних чисел
    ComplexVector(const ComplexVector& s);
    // конструктор копіювання, який створює копію іншого вектора
    ComplexVector& operator=(const ComplexVector& s);
    // копіювати оператор присвоювання, який створює копію іншого вектора


    // 5 деструктор, який видаляє масив комплексних чисел
    ~ComplexVector() {
        cout << " del vec";
        if (v) delete[] v;//It also prints a message that the vector is being deleted.
    }
    
    
    void Output();
    void Output1();
    void Input();
    // метод встановлення елемента вектора за певним індексом
    void SetElement(int index, ComplexShort value);
    ComplexVector Add(ComplexVector& b);

    ComplexVector Subtraction(ComplexVector& b);
    ComplexShort GetElement(int index) const; // getter for a single element
    void ScalarMultiply(int scalar);

    bool Compare(const ComplexVector& other) const;

};
//2
ComplexVector::ComplexVector(int n) {//конструктор, який створює вектор розміром n;
    if (n <= 0) { v = NULL; num = 0; state = -1; cout << " Vec --> 0 "; }

    num = n;
    v = new ComplexShort[n];

    for (int i = 0; i < n; i++) {
        v[i] = 0.0;
    }
}
//3
ComplexVector::ComplexVector(int n, ComplexShort& b) {//конструктор, який створює вектор розміром n та ініціалізує його комплексним числом;
    if (n <= 0) { v = NULL; num = 0; state = -1; cout << " Vec --> 0 "; }
    num = n;
    v = new ComplexShort[n];
    for (int i = 0; i < n; i++) {
        v[i] = b;
    }
}

ComplexVector::ComplexVector(int n, ComplexShort* p) {// конструктор, який створює вектор розміром n та ініціалізує його масивом комплексних чисел;
    if (n <= 0 || p == NULL) { v = NULL; num = 0; state = -1; cout << " Vec --> 0 "; }
    //Цей рядок перевіряє, чи вхідні дані nменші або дорівнюють нулю. Якщо n менше або дорівнює нулю, конструктор встановлює покажчик v на NULL
    num = n;
    v = new ComplexShort[n];
  //  Цей рядок динамічно виділяє пам'ять для вектора v
    for (int i = 0; i < n; i++) {
        v[i] = p[i];
    }
}

// 4 конструктор копіювання, який створює копію іншого вектора.
ComplexVector::ComplexVector(const ComplexVector& s) {//конструктор копіювання, який створює копію іншого вектора.
    num = s.num;
    v = new ComplexShort[num];
    state = 0;
    for (int i = 0; i < num; i++) v[i] = s.v[i];
}

// 4 Оператор присвоєння
ComplexVector& ComplexVector::operator=(const ComplexVector& s) {
    if (num != s.num)
    {//Цей блок коду перевіряє, чи є різною кількість елементів у двох векторах.
        //Якщо вони різні, функція видаляє старий вектор v і створює новий із відповідним розміром.
        //Потім він копіює кожен елемент з об’єкта, який призначається поточному об’єкту
        if (v) delete[] v;
        num = s.num;
        v = new ComplexShort[num];
        state = 0;
    }
    return *this;
}

// 6 
void ComplexVector::SetElement(int index, ComplexShort value) {
    if (index < 0 || index >= num) {
        throw std::out_of_range("Index out of bounds"); //Індекс поза межами
    }
    v[index] = value;
}

//7
ComplexShort ComplexVector::GetElement(int index) const {
    if (index < 0 || index >= num) {
        throw std::out_of_range("Invalid index");
    }
    return v[index];
}
void ComplexVector::Input() {

    if (num == 0) {
        if (v) delete[] v;
        do {
            cout << "Input size Vec\n";
            cin >> num;
        } while (num <= 0);
        v = new ComplexShort[num];
    }
    for (int i = 0; i < num; i++) {
        short RE;
        cout << " v [ " << i << " ] real img ";
        cin >> RE;
        v[i] = ComplexShort(RE);
    }
}

void ComplexVector::Output() {
    if (num != 0) {
        for (int i = 0; i < num; i++) {
            cout << " v [ " << i << " ] " << v[i].real() << '\t';
            cout << endl;
        }
    }
}
void ComplexVector::Output1() {
    if (num != 0) {
        for (int i = 0; i < num; i++) {
            cout << " v [ " << i << " ] " << v[i].real() << '\t';
            cout << endl;
        }
    }
}
ComplexVector ComplexVector::Add(ComplexVector& b) {
    int tnum;
    tnum = num < b.num ? num : b.num;
    /* Цей рядок оголошує цілочисельну змінну tnum та ініціалізує
         її мінімальною кількістю елементів між поточним вектором(num)
         і вхідним вектором(b.num).Оператор ? використовується для вибору мінімального значення.*/
    if (tnum >= 0) {
        ComplexVector tmp(tnum);
        for (int i = 0; i < tnum; i++) tmp.v[i] = v[i] + b.v[i];
        /* Цей рядок запускає цикл, який перебирає перші tnumелементи обох векторів
             і додає їх поелементно, зберігаючи результат у відповідному елементі вектора tmp.*/
        return tmp;
    }
    return ComplexVector(0);
}
ComplexVector ComplexVector::Subtraction(ComplexVector& b) {
    int tnum;
    tnum = num < b.num ? num : b.num;
    /* Цей рядок оголошує цілочисельну змінну tnumта ініціалізує
         її мінімальною кількістю елементів між поточним вектором(num)
         і вхідним вектором(b.num).Оператор ? використовується для вибору мінімального значення.*/
    if (tnum >= 0) {
        ComplexVector tmp(tnum);
        for (int i = 0; i < tnum; i++) tmp.v[i] = v[i] - b.v[i];
        /* Цей рядок запускає цикл, який перебирає перші tnumелементи обох векторів
             і додає їх поелементно, зберігаючи результат у відповідному елементі вектора tmp.*/
        return tmp;
    }
    return ComplexVector(0);
}
void ComplexVector::ScalarMultiply(int scalar) {
    for (int i = 0; i < num; i++) {
        v[i] *= scalar;
    }
}
//Проблема з ScalarMultiplyфункцією полягає в тому, що вхідним аргументом scalarє символ без знака, 
//максимальне значення якого дорівнює 255. Перемноження складної короткої змінної зі значенням, більшим за 255,
//призведе до переповнення, що може призвести до неочікуваних результатів.


bool ComplexVector::Compare(const ComplexVector& other) const {
    if (num != other.num) {
        return false;
    }
    for (int i = 0; i < num; i++) {
        if (v[i] != other.v[i]) {
            return false;
        }
    }
    return true;
}


void Task1() {
    system("cls");
    double a, b, h;
    unsigned int color;

        cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << "Enter h: ";
    cin >> h;

    cout << "Enter color: ";
    cin >> color;

    Parallelogram obj(a, b, h, color);//// Створює об'єкт паралелограм за допомогою введених користувачем даних
    obj.printInfo();
}
void Task2() {
    setlocale(LC_CTYPE, "ukr");
    int size;
    std::cout << "Enter the size of 1 the vector: ";
    std::cin >> size;

    // create a vector of the given size
    ComplexVector v1(size);

       std::cout << "Enter the elements of the vector:" << std::endl;
    for (int i = 0; i < size; i++) {
        short real_part;
        std::cout << "Enter real and imaginary parts of element " << i + 1 << ": ";
        std::cin >> real_part;
        ComplexShort c(real_part);
        v1.SetElement(i, c);
    }
    int size1;
    std::cout << "Enter the size of 2 the vector: ";
    std::cin >> size1;
    ComplexVector v2(size1);

    
    std::cout << "Enter the elements of the vector:" << std::endl;
    for (int i = 0; i < size1; i++) {
        short real_part1;
        std::cout << "Enter real and imaginary parts of element " << i + 1 << ": ";
        std::cin >> real_part1;
        ComplexShort c(real_part1);
        v2.SetElement(i, c);
    }
    // output the vectors
    std::cout << "v1:" << std::endl;
    v1.Output();
    std::cout << "v2:" << std::endl;
    v2.Output();

    // add the vectors
    ComplexVector v3 = v1.Add(v2);

    // output the result
    std::cout << "v1 + v2 = v3:" << std::endl;
    v3.Output();

    ComplexVector v4 = v1.Subtraction(v2);
    // output the result
    std::cout << "v1 - v2 = v4:" << std::endl;
    v4.Output();
    cout << "Введiть число для множення" << endl;
    int scalar;
    cin >> scalar;

    cout << "Результат множення" << endl;
    v1.ScalarMultiply(scalar);
    cout << "Перший вектор:" << endl;
    v1.Output();
    v2.ScalarMultiply(scalar);
    cout << "Другий вектор" << endl;
    v2.Output();
    cout << "Comparing the first and second vectors: \n";
    if (v1.Compare(v2)) {
        std::cout << "The vectors are equal." << std::endl;
    }
    else {
        std::cout << "The vectors are not equal." << std::endl;
    }
  //  getch();
}

int main()
{
    int ch;
    cout << "Choose 1, 2 or 3" << endl;
    cin >> ch;
    switch (ch) {
    case(1):
        Task1();
        break;
    case(2):
       // Task2();
        system("cls");
        Task2();

        break;
    case(3):
        system("cls");

        break;
    }
    return 0;
}
//Створити клас типу – паралелограм(поля : основа, висота, бічна сторона, колір).
//У класі визначити o конструктори(не менше двох); o функції - члени обчислення площі, периметру;
//функції - члени встановлення основи, висоти, бічної сторони, кольору, 
//ункції встановлення полів класу повинні перевіряти коректність параметрів, що задаються;
//функції - члени що повертають значення полів; o функцію друку.



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
