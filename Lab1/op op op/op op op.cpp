// op op op.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <fstream>
#include <ios>
#include <iostream>
#include <vector>

#include <time.h>

using namespace std;

typedef double *pDouble;

int taskNumber;
int taskTask;
int taskInput;
const int MAX = 100;
const int sizeMAX = 100;
int ConsoleInputSizeArray(const int sizeMax)
{
    int nA = 0;
    do {
        cout << " Input size Array ( 0< 1 < " << sizeMax << " ) "<<endl;
        cin >> nA;
    } while (nA <= 0 || nA >= sizeMax);
    return nA;
}
/*
*   ConsoleInputArrayDouble
*
*/


int Input() {
    int choice;
    cin >> choice;
    return choice;
}

void showMenuInput() {
    cout << "     Menu Input   \n";
    cout << "    1.  Console all \n";
    cout << "    2.  Console - size, array - random \n";
    cout << "    3.  File 1.txt \n";
    cout << "    4.  bb    \n";
    cout << "    5.  Exit \n";
}

void menuInput() {
   
        system("cls");
        showMenuInput();
        int ch = Input();
        switch (ch) {
        case 1:
               taskInput = 1;
            break;
        case 2:
            taskInput = 2;        
            break;
        case 3:
             taskInput = 3;
            break;
        case 4:
            taskInput = 4;
            break;
        case 5:
          cout << "You chose EXIT. Bye ";
            break;
        default:
            break;
        }
        system("cls");
}
void showMainMenu() {
    cout << "    Main Menu  \n";
    cout << "    1.  Task 1  \n";
    cout << "    2.  Task 2  \n";
    cout << "    3.  Task 3  \n";
}

void mainMenu() {
  
        system("cls");
        showMainMenu();
        int ch = Input();
        switch (ch) {
        case 1:
          taskNumber = 1;
            menuInput();
            break;
        case 2:
            taskNumber = 2;
            menuInput();
            break;
         case 3:
          taskNumber = 3;
            menuInput();
            break;
        default:
            break;
        }
   
}


void ConsoleInputIntoTextFile2() {
   
    double A[MAX];
    int nA, i, T, min;
    min = 0;


    cout << "Enter the number of elements < " << MAX << endl;
    cin >> nA;
    for (i = 0; i < nA; i++) {
        cout << "A[" << i << "]=";
        cin >> A[i];
    }

    cout << " Input T " << endl;
    cin >> T;
    i = 0;
    for (i = 0; i < nA; i++) {


        if (A[i] < 0 && A[i] != T) {
            if (A[i] > min || min == 0)
                min = A[i]
                ;
        }
        if (A[i] == T) {
            goto add; ;
        }
    }
    add: {
    cout << "min" << min << endl;;
    }
    fstream fout("file.txt");
    for (int i = 0; i < nA; i++)
        fout << A[i] << "   ";

    fout.close();
}
void ConsoleInputIntoTextFile3() {
    double A[MAX], B[MAX];
    int nA, i, j = 0, k=0;


    cout << "Enter the number of elements < " << MAX << endl;
    cin >> nA;
    for (i = 0; i < nA; i++) {
        cout << "A[" << i << "]=";
        cin >> A[i];
    }
    for (i = 0; i < nA; i++) {
        int zero = 0;

        for (int j = 0; j < i && !zero; j++) {
            if (A[i] == A[j]) zero++;
        }

        if (!zero) {
            for (int j = i; j < nA; j++) {
                if (A[i] == A[j]) zero++;
            }
        }

        if (zero > 1) {
            B[k++] = A[i];
        }
    }

    for (i = 0; i < k; i++) {
        cout << "B[" << i << "] = " << B[i] << " ";

        if ((i + 1) % 5 == 0) {
            cout << endl;
        }
    }
    cout << endl;
    
fstream fout("file.txt");
for (int i = 0; i < nA; i++)
    fout<< A[i] << "   ";

fout.close();
}
void ConsoleInputIntoTextFile1() {
  
    int i, nA = 0, nB = 0;
    double A[MAX], B[MAX];
  
    cout << "Enter the number of elements < " << MAX << endl;
    cin >> nA;
    for (i = 0; i < nA; i++) {
        cout << "A[" << i << "]=";
        cin >> A[i];
    }

    for (i = 0; i < nA; i++) {
        if (A[i] < 0) {
            B[nB++] = A[i];
        }
    }

  for (i = 0; i < nB; i++)

       cout << B[i] << " ";
  cout << endl;
  fstream fout("file.txt");
  for (int i = 0; i < nA; i++) {
      fout << A[i] << "   ";
  }

  fout.close();
}
void DynamicArrayFromFileToFile() {

  
    double* A = new double[MAX];
    
    fstream fout("file.txt");
    fstream fout1("ReadFile.txt");
    if (fout.is_open()) {
        double B;
     //   double A;
        while (fout>> B) {
            fout1 << B<< endl;
        }
        
    }
    else {
        cout << "Error" << endl;
    }
    fout.close();
    fout1.close();
}



void FromFileToContainer() {
    vector<double> A_vector;
   fstream fout("file.txt");
    if (fout.is_open()) {
        vector <double> data;
        double A;
        while (fout >> A) {
            data.push_back(A);
        }
        for (int i = 0; i < data.size(); i++) {
            
            cout << data[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Error" << endl;
    }
    
    fout.close();
}

void Task3_1() {
  
   ConsoleInputIntoTextFile1();
    DynamicArrayFromFileToFile();
}
void Task3_2() {
    ConsoleInputIntoTextFile2();
    DynamicArrayFromFileToFile();
}
void Task3_3()
{
    ConsoleInputIntoTextFile3();
    DynamicArrayFromFileToFile();

}
void Task4_1() {
    ConsoleInputIntoTextFile1();
    FromFileToContainer();
}
void Task4_2() {
    ConsoleInputIntoTextFile2();
    FromFileToContainer();
}
void Task4_3() {
    ConsoleInputIntoTextFile3();
    FromFileToContainer();
}

//1. Із одновимірного масиву А розміру N побудувати масив В із всіх від’ємних елементів.
void task1() {
    double A[MAX], B[MAX];
    int nA, nB, i;
    nB = 0;
    srand(time(NULL));
    vector<double> vA;

    fstream fout;
    fstream fout1;
    fstream File;
    File.open("NewFile.txt", fstream::in | fstream::out);
    ofstream file("file.bin", ios::out | ios::binary);
    ifstream file1("file.bin", ios::out | ios::binary); 

    switch (taskInput)
    {
    case 1:
        //звичайна консоль

        fout.open("file.txt", fstream::in | fstream::out);

        if (!fout.is_open())
        {
            cout << "Error. File was not open(";

        }
        else
        {
            cout << "Your file was open. Great\n";

            nA = ConsoleInputSizeArray(MAX);

            i = 0;
            for (i = 0; i < nA; i++)
            {
                cout << "A[" << i << "] = "; cin >> A[i];

            }
            for (i = 0; i < nA; i++) {
                if (A[i] < 0) {
                    B[nB++] = A[i];
                }
            }
            fout << "Your negative elements\n";
            for (i = 0; i < nB; i++) {

                cout << "B[" << i << "] =" << B[i] << "\t";

                fout << "B[" << i << "] =" << B[i] << endl;
            }
         }   
        fout.close();
            break;
        
    case 2:
        double B[MAX];
        if (!file) {
            cout << "File was not opened" << endl;
        }
        else
        {
            cout << "Succes. File was opened" << endl;
        }
        nA = ConsoleInputSizeArray(MAX);

        for (int i = 0; i < nA; i++)
        {
            A[i] = (rand() % 64) - 32;
            cout << "A[" << i << "]=" << A[i] << " ";
        }
        for (i = 0; i < nA; i++) {
            if (A[i] < 0) {
                B[nB++] = A[i];
            }
        }
        cout << "\n";
        cout << "\n";
        for (i = 0; i < nB; i++) {
            cout << "B[" << i << "]=" << B[i] << " ";
            file.write((char*)&A[i], sizeof(A[i]));
        }
        file.close();
        file1.close();
        break;
    case 3:
        /* Функції розв’язання задач згідно варіанту з використанням динамічних масивів.
          Вхідні дані зчитаються з файлів, результати записуються в нові файли та
          виводиться в консоль.*/
        Task3_1();
        break;
    case 4:
        /*4.Функцію читає дані з файлів в контейнер(vector, valarray або array) та з
         контейнера дані виводиться в консоль.*/
        Task4_1();
    default:
        break;
     }

    
}

//2. Знайти максимальне значення серед від’ємних елементів, розташованих до
//першого елемента, рівного Т.
void task2()
{
    fstream fout1;
    int nA, i, T, min;
    min = 0;
    const int MAX = 100;
    double A[MAX];
    fstream file_for_two;
    vector<double> vA;
    ofstream file("file.bin", ios::out | ios::binary);
    ifstream file1("file.bin", ios::out | ios::binary);
    switch (taskInput)
    {
    case 1:
      
        file_for_two.open("Second_Task.txt", fstream::in | fstream::out);
        if (!file_for_two.is_open())
        {
            cout << "Sorre. File was not opened";
        }
        else {
            cout << "File is opened";

            double A[MAX];
            int nA, i, T, min;
            min = 0;
            cout << " Input number N < " << MAX << endl;
            cin >> nA;
            file_for_two << "Size=" << nA<<endl;
            for (i = 0; i < nA; i++)
            {
                cout << "A[" << i << "] = "; cin >> A[i];
            }
            cout << " Input T " << endl;
            cin >> T;
            file_for_two <<"T="<< T<<endl;

            i = 0;
            for (i = 0; i < nA; i++) {


                if (A[i] < 0 && A[i] != T) {
                    if (A[i] > min || min == 0)
                        min = A[i]
                        ;
                }
                if (A[i] == T)
                {
                    break;
                }
            }
       
            cout << "min=" << min;
            file_for_two << "min=" << min;
 }

            file_for_two.close();
            break;
        
    case 2:
      
        min = 0;
         // double A[MAX];
          
        if (!file) {
            cout << "File was not opened" << endl;
        }
        else
        {
            cout << "Succes. File was opened" << endl;
        }
        nA = ConsoleInputSizeArray(MAX);

        for (int i = 0; i < nA; i++)
        {
            A[i] = (rand() % 64) - 32;
            cout << "A[" << i << "]=" << A[i] << " ";
        }
        cout << " Input T " << endl;
        cin >> T;
        file_for_two << T;
        i = 0;
        for (i = 0; i < nA; i++) {


            if (A[i] < 0 && A[i] != T) {
                if (A[i] > min || min == 0)
                    min = A[i];

            }
            if (A[i] == T) {

                cout << "min=" << min;
                file.write((char*)&min, sizeof(min));
            }
        }
      
        file.close();
        file1.close();
 
        break;
    case 3:
        Task3_2();
        
        break;
    case 4:          
        Task4_2();
       
        break;
        
    }
}
void task3()
{    double A[MAX], B[MAX];
    int nA, i, j=0, k;
    fstream file_for_two;
    fstream fout1;

    ofstream file("file.bin", ios::out | ios::binary);
    ifstream file1("file.bin", ios::out | ios::binary);
 int count = 0;
    switch (taskInput) {
    case 1:
      double B[MAX];
       k = 0;
        /* int nA, i, j, k;*/
        file_for_two.open("Second_Task.txt", fstream::in | fstream::out);
        if (!file_for_two.is_open())
        {
            cout << "Sorre. File was not opened";
        }
        else {
            cout << "File is opened" << endl;

            nA = ConsoleInputSizeArray(MAX);

            for (i = 0; i < nA; i++)
            {
                cout << "A[" << i << "] = ";
                cin >> A[i];
            }

            for (i = 0; i < nA; i++) {
                int zero = 0;

                for (int j = 0; j < i && !zero; j++) {
                    if (A[i] == A[j]) zero++;
                }

                if (!zero) {
                    for (int j = i; j < nA; j++) {
                        if (A[i] == A[j]) zero++;
                    }
                }

                if (zero > 1) {
                    B[k++] = A[i];
                }
            }
            file_for_two << "Your result" <<endl;
            for (i = 0; i < k; i++) {
                cout << "B[" << i << "] = " << B[i] << " ";
                file_for_two << "B[" << i << "]=" << B[i] << " ";
                if ((i + 1) % 5 == 0) {
                    cout << endl;
                }
            }
            file_for_two.close();


        }
        break;
    case 2:
      
        k = 0;
        if (!file) {
            cout << "File was not opened" << endl;
        }
        else
        {
            cout << "Succes. File was opened" << endl;
        }
        nA = ConsoleInputSizeArray(MAX);

        for (int i = 0; i < nA; i++)
        {
            A[i] = (rand() % 64) - 32;
            cout << "A[" << i << "]=" << A[i] << " ";
        }
        for (i = 0; i < nA; i++) {
            int zero = 0;

            for (int j = 0; j < i && !zero; j++) {
                if (A[i] == A[j]) zero++;
            }

            if (!zero) {
                for (int j = i; j < nA; j++) {
                    if (A[i] == A[j]) zero++;
                }
            }

            if (zero > 1) {
                B[k++] = A[i];
            }
        }
      
        for (i = 0; i < k; i++) {
            cout << "B[" << i << "] = " << B[i]<<" ";
            file.write((char*)&B[i], sizeof(B[i]));
            if ((i + 1) % 5 == 0) {
                cout << endl;
            }
        }
        file.close();
        file1.close();

        break;
    case 3:
        Task3_3();
        break;
    case 4:
        Task4_3();
        break;
    }
}

int main()
{
    mainMenu();
  switch (taskNumber)
  {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
    default:
        break;
    }
 
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
