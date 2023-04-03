// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include<complex>
#include <fstream>

using namespace std;
////////////////////////////////////////////////          Task 1          ////////////////////////////////////////////////
class Parallelogram
{
    short a; // основа
    short b; // бічна сторона
    short h; // висота
    unsigned int color;

public://Конструктори зі стандартними або заданими значеннями для параметрів
    Parallelogram() : a(0), b(0), h(0), color(0) {}
    Parallelogram(short ai, short c) : a(ai), b(0), h(0), color(c) {}
    Parallelogram(short ai, short bi, short hi, int ci) : a(ai), b(bi), h(hi), color(ci) {}

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
    ComplexVector() : v(NULL), num(0), state(0) {}
    //виділяє простір для одного елемента та ініціалізує його нулем

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
//3 n-це розмір вектора, b-значення, яке буде використано для ініціалізації всіх елементів вектора
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
ComplexVector::ComplexVector(const ComplexVector& s) {
    num = s.num;
    v = new ComplexShort[num];
    state = 0;
    for (int i = 0; i < num; i++) v[i] = s.v[i];
}

// 4 Оператор присвоєння
ComplexVector& ComplexVector::operator=(const ComplexVector& s) {
    if (num != s.num)
    {  //Якщо вони різні, функція видаляє старий вектор v і створює новий із відповідним розміром.
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
//Проблема з ScalarMultiply функцією полягає в тому, що вхідним аргументом scalar є символ без знака, 
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

////////////////////////////////////////////////          Task 3         /////////////////////////////////////////////////////////////////////////
class Matrix {
private:
    short* data; // pointer to matrix elements
    int num;// кількість елементів у масиві
    int state; // стан вектора
    short rows; // number of rows
    int cols; // number of columns
    int error; // error status (e.g. for out-of-bounds access)

public:

    void print() const;
    Matrix Addition(const Matrix& other) const;
    Matrix subtraction(const Matrix& other) const;
    bool checkEqual(const Matrix& mat1, const Matrix& mat2) {
        // Check if the dimensions are the same
        if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
            return false;
        }

        // Check if the elements are the same
        for (int i = 0; i < mat1.rows; i++) {
            for (int j = 0; j < mat1.cols; j++) {
                if (mat1.getElement(i, j) != mat2.getElement(i, j)) {
                    return false;
                }
            }
        }

        // The matrices are equal
        return true;
    }
    Matrix multiplyScalar(short scalar) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }
    // 1 Constructor without parameters: allocates space for a 4x4 matrix and initializes it to zero
    Matrix() : rows(4), cols(4), error(0), num(rows* cols) {
        data = new short[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            data[i] = 0;
        }
    }
    //2
    Matrix(int n) : rows(n), cols(n), error(0) {
        if (n <= 0) {
            data = NULL;
            num = 0;
            state = -1;
            cout << "Matrix size is invalid. Setting data to NULL." << endl;
        }
        else {
            data = new short[n * n];
            for (int i = 0; i < n * n; i++) {
                data[i] = 0;
            }
        }
    }
    //3
    Matrix(int n, int m, short value) : rows(n), cols(m), error(0) {
        rows = n; cols = m;

        if (n <= 0 || m <= 0) {
            data = NULL;
            num = 0;
            state = -1;
            cout << "Matrix size is invalid. Setting data to NULL." << endl;
        }
        else {
            data = new short[n * m];
            for (int i = 0; i < n * m; i++) {
                data[i] = value;
            }
        }
    }
    ~Matrix();
    //4
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new short[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            data[i] = other.data[i];
        }
    }

    //4 Оператор присвоєння
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            // Вивільнення старої пам'яті
            delete[] data;

            // Виділяє нову пам'ять
            rows = other.rows;
            cols = other.cols;
            data = new short[rows * cols];
            for (int i = 0; i < rows * cols; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

//6
    void setElement(int row, int col, short value = 0) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            error = 1;
            cout << "Error: Out of bounds access." << endl;
        }
        else {
            data[row * cols + col] = value;
        }
    } 
 /* 7*/  short getElement(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            cout << "Error: Out of bounds access." << endl;
            return 0;
        }
        else {
            return data[i * cols + j];
        }
    }



    Matrix(short n_rows, int n_cols) : rows(n_rows), cols(n_cols), num(n_rows* n_cols), error(0) {
        data = new short[num];
        memset(data, 0, num * sizeof(short));
    }

    Matrix multiply(const Matrix& other) const {
        // Check if the matrices are compatible for multiplication
        if (cols != other.rows) {
            cout << "Error: Incompatible matrix sizes for multiplication." << endl;
            return Matrix();
        }

        // Create the resulting matrix
        Matrix result(rows, other.cols);

        // Multiply the matrices and fill in the resulting matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                short sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum += data[i * cols + k] * other.getElement(k, j);
                }
                result.setElement(i, j, sum);
            }
        }

        return result;
    }

};
//5 Деструктор
Matrix::~Matrix() {
    delete[] data;
}
// 8
void Matrix::print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << data[i * cols + j] << " ";
        }
        cout << endl;
    }
}
Matrix Matrix::Addition(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        Matrix result;
        result.error = 1;
        cout << "Error: Matrices must have the same size." << endl;
        return result;
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i * cols + j] = data[i * cols + j] + other.data[i * cols + j];
        }
    }
    return result;
}

Matrix Matrix::subtraction(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        Matrix result;
        result.error = 1;
        cout << "Error: Matrices must have the same size." << endl;
        return result;
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i * cols + j] = data[i * cols + j] - other.data[i * cols + j];
        }
    }
    return result;
}
Matrix createMatrix() {
    int n, m;

    cout << "Enter number of rows: ";
    cin >> n;

    cout << "Enter number of columns: ";
    cin >> m;

    Matrix mat(n, m);

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            short val;
            cin >> val;
            mat.setElement(i, j, val);
        }
    }
    cout << "Your matrix:\n";
    mat.print();
    return mat;
}//rand() % 10
Matrix createrandMatrix() {
    int n, m;
    n = rand() % 7;
    cout << "Number of rows: " << n << endl << endl;
    m = rand() % 8;

    cout << "Number of columns: " << m << endl << endl;

    Matrix mat(n, m);

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            short val;
            val = rand() % 10;
            mat.setElement(i, j, val);
        }
    }
    cout << "Your matrix:\n";
    mat.print();
    return mat;
}
Matrix FileMatrix(ofstream& fout2) {
   
    int n, m;

    cout << "Enter number of rows: ";
    cin >> n;
    fout2 <<"n="<<n<< endl;
    cout << "Enter number of columns: ";
    cin >> m;
    fout2 <<"m="<< m<<endl;

    Matrix mat(n, m);
    fout2 << "  Yout matrix" << endl;
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            short val;
            cin >> val;
            fout2 << val<<endl;

            mat.setElement(i, j, val);
        }
    }
    fout2 << endl;
    cout << "Your matrix:\n";
    mat.print();
    return mat;

}


void Task1_1() {
    
    system("cls");
    short a, b, h;
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
void Task1_2() {

    system("cls");
    double a, b, h;
    unsigned int color;

   a= rand() % 1000;
   b= rand() % 1000;
   h= rand() % 1000;
   color= rand() % 1000;
   cout << "a=" << a << endl;
   cout << "b=" << b << endl;
   cout << "h=" << h << endl;
   cout << "color=" << color << endl;


    Parallelogram obj(a, b, h, color);//// Створює об'єкт паралелограм за допомогою введених користувачем даних
    obj.printInfo();
}
void readfile() {
    short a, b, h;

    unsigned int color;
    ifstream readfile("NewFile.txt");
    readfile >> a >> b >> h >> color;
}
//Передбачити введення початкових даних : з файлу
void Task1_3()
{
 system("cls");
    ofstream fout1;
    fout1.open("NewFile.txt");

   
   short a, b, h;

   unsigned int color;
   cout << "Enter size" << endl;
  
    cout << "Enter a: ";
    cin >> a;
 


    fout1 << "a: " << a << endl;


 cout << "Enter b: ";
    cin >> b;   

    fout1 << "b: " << b << endl;


 cout << "Enter h: ";

 cin >> h;  
 fout1 << "h: " << h << endl;

  cout << "Enter color: ";

    cin >> color;    
    fout1 << "color: " << color << endl;
    fout1.close();

    readfile();

  
    Parallelogram obj(a, b, h, color);//// Створює об'єкт паралелограм за допомогою введених користувачем даних
    obj.printInfo();

}

void Task2_1() {
    system("cls");

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
}
void Task2_2() {
    system("cls");

    setlocale(LC_CTYPE, "ukr");
    int size=rand() % 10;
    cout << "The size of 1 the vector: "<<size<<endl;

    // create a vector of the given size
    ComplexVector v1(size);

    cout << "Enter the elements of the vector:" << std::endl;
    for (int i = 0; i < size; i++) {
              short real_part= rand() % 100;
              std::cout << "Element " << i + 1 << ": " << real_part << endl;
       // std::cin >> real_part;
        ComplexShort c(real_part);
        v1.SetElement(i, c);
    }
    cout << endl;
    int size1= rand() % 10;
    std::cout << "Enter the size of 2 the vector: "<<size1<<endl;
   // std::cin >> size1;
    ComplexVector v2(size1);


    std::cout << "Enter the elements of the vector:" << std::endl;
    for (int i = 0; i < size1; i++) {
             short real_part1= rand() % 100;
   std::cout << "Element " << i + 1 << ": "<<real_part1<<endl;
       // std::cin >> real_part1;
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
}
void Task2_3() {
    system("cls");

    ofstream fout;
    fout.open("File.txt", fstream::in | fstream::out);
    setlocale(LC_CTYPE, "ukr");
    int size;
    std::cout << "Enter the size of 1 the vector: ";
    cin >> size;

    fout << "The size of 1 the vector: ";
    fout << size;

    // create a vector of the given size
    ComplexVector v1(size);
    fout << "\nv1:\n";
    std::cout << "Enter the elements of the vector:" << std::endl;
    for (int i = 0; i < size; i++) {
        short real_part;
        cout << "Enter real and imaginary parts of element " << i + 1 << ": ";
        cin >> real_part;
        fout << real_part << endl;


        ComplexShort c(real_part);
        v1.SetElement(i, c);
    }
    

        int size1;
        std::cout << "Enter the size of 2 the vector: ";
        std::cin >> size1;
        fout << "The size of 2 the vector: " << size1;

        ComplexVector v2(size1);

        fout << "\nv2:\n";

        std::cout << "Enter the elements of the vector:" << std::endl;
        for (int i = 0; i < size1; i++) {
            short real_part1;
            std::cout << "Enter real and imaginary parts of element " << i + 1 << ": ";
            std::cin >> real_part1;
            fout << real_part1 << endl;

            ComplexShort c(real_part1);
            v2.SetElement(i, c);
        }
        fout.close();
        ifstream readfile("File.txt");
        for (int i = 0; i < size; i++) {
            short real_part;

            readfile >> real_part;
        }
        for (int i = 0; i < size1; i++) {
            short real_part1;

            readfile >> real_part1;
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
        fout.close();
    
}

void Read() {
 int n, m, val;
 ifstream readfile("Txt_File.txt");
 readfile >> n >> m;
 for (int i = 0; i < n; i++) {
     for (int j = 0; j < m; j++) {
         double value;
         readfile >> value;
     }
 }
}
void Task3_1() {
    system("cls");
    cout << "Creating the first matrix:" << endl;
    Matrix mat1 = createMatrix();

    // Create the second matrix
    cout << "Creating the second matrix:" << endl;
    Matrix mat2 = createMatrix();
    Matrix mat3 = mat1.Addition(mat2);
    cout << "The sum of the matrices is:" << endl;
    mat3.print();
    Matrix mat4 = mat1.subtraction(mat2);
    cout << "The subtraction of the matrices is:" << endl;
    mat4.print();
    Matrix mat5 = mat1.multiply(mat2);
    cout << "The multiply of the matrices is:" << endl;
    mat5.print();
    cout << "Multiplication of a matrix by a scalar of type short, enter scalar" << endl;

    short scalar;
    cin >> scalar;
    cout << "First\n";
    Matrix mat6 = mat1.multiplyScalar(scalar);
    mat6.print();
    cout << "Second\n";
    Matrix mat7 = mat2.multiplyScalar(scalar);
    mat7.print();
    if (mat1.checkEqual(mat1, mat2)) {
        cout << "mat1 and mat2 are equal" << endl;
    }
    else {
        cout << "They are not equal" << endl;
    }

}
void Task3_3() {
   

    ofstream fout2;
    fout2.open("File1.txt", fstream::in | fstream::out);
    system("cls");
    cout << "Creating the first matrix:" << endl;
    Matrix mat1 = FileMatrix(fout2);
    Read();
    // Create the second matrix
    cout << "Creating the second matrix:" << endl;
    Matrix mat2 = FileMatrix(fout2);
    Read();
     fout2.close();

    cout << "The sum of the matrices is:" << endl;
    Matrix mat3 = mat1.Addition(mat2);
    mat3.print();
    Matrix mat4 = mat1.subtraction(mat2);
    cout << "The subtraction of the matrices is:" << endl;
    mat4.print();
    Matrix mat5 = mat1.multiply(mat2);
    cout << "The multiply of the matrices is:" << endl;
    mat5.print();
    cout << "Multiplication of a matrix by a scalar of type short, enter scalar" << endl;

    short scalar;
    cin >> scalar;
    cout << "First\n";
    Matrix mat6 = mat1.multiplyScalar(scalar);
    mat6.print();
    cout << "Second\n";
    Matrix mat7 = mat2.multiplyScalar(scalar);
    mat7.print();
    if (mat1.checkEqual(mat1, mat2)) {
        cout << "mat1 and mat2 are equal" << endl;
    }
    else {
        cout << "They are not equal" << endl;
    }

}
void Task3_2() {
    system("cls");

    cout << "Creating the first matrix:" << endl;
    Matrix mat1 = createrandMatrix();

    // Create the second matrix
    cout << "Creating the second matrix:" << endl;
    Matrix mat2 = createrandMatrix();

    Matrix mat3 = mat1.Addition(mat2);
    cout << "The sum of the matrices is:" << endl;
    mat3.print();
    Matrix mat4 = mat1.subtraction(mat2);
    cout << "The subtraction of the matrices is:" << endl;
    mat4.print();
    Matrix mat5 = mat1.multiply(mat2);
    cout << "The multiply of the matrices is:" << endl<<endl;
    mat5.print();
    cout << "Multiplication of a matrix by a scalar of type short, enter scalar" << endl;

    short scalar;
    cin >> scalar;
    cout << "First\n";
    Matrix mat6 = mat1.multiplyScalar(scalar);
    mat6.print();
    cout << "Second\n";
    Matrix mat7 = mat2.multiplyScalar(scalar);
    mat7.print();
    if (mat1.checkEqual(mat1, mat2)) {
        cout << "mat1 and mat2 are equal" << endl;
    }
    else {
        cout << "They are not equal" << endl;
    }


}
void asd() {
    int a; 
    cout << "1, 2 or 3"<<endl ;cin >> a;
        switch (a) {
        case 1:
            Task1_1();
            break;
        case 2:
            Task1_2();
            break;
        case 3:
            Task1_3();
            break;
        }

}
void bsd() {
    int a; 
    cout << "1, 2 or 3"<<endl ;cin >> a;
        switch (a) {
        case 1:
            Task2_1();
            break;
        case 2:
            Task2_2();
            break;
        case 3:
            Task2_3();
            break;
        }
}

void csd() {
    int a;
    cout << "1, 2 or 3" << endl; cin >> a;
    switch (a) {
    case 1:
        Task3_1();
        break;
    case 2:
        Task3_2();
        break;
    case 3:
        Task3_3();
        break;
    }
}

int main()
{
    int ch;
    cout << "Choose 1, 2 or 3" << endl;
    cin >> ch;
    switch (ch) {
    case(1):
        system("cls");
        asd();
        break;
    case(2):
        system("cls");
        bsd();
        break;
    case(3):
        system("cls");
        csd();
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
