// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
#include <bitset>
#include <string>
#include <fstream>
using namespace std;

void Task1()
{
	system("cls");
	int a, b, x, y, d, c, t, q;

	cout << "Введiть a" << endl;
	cin >> a;
	cout << "Введiть b" << endl;
	cin >> b;
	cout << "Введiть c" << endl;
	cin >> c;
	cout << "Введiть d" << endl;
	cin >> d;

	t = ((b + (b << 5)));
	q = (((d << 4) - d) + (a << 3) + (a << 2))>> 9;

	x = (t + q) - ((c << 6) + c) + ((d << 3) + (d << 2) + 2 * d);

	y = 33 * b + ((d * 15 + 12 * a) / 512) - 65 * c + d * 14;

	cout <<"Ваш результат:"<<" x = " << x << endl;
	cout << "Необхiдний результат:"<<" y = " << y << endl;
}

void Task2_1() {
	/*Результат записується у бінарний файл.Початкова інформація може бути у
		текстовому файлі*/
	system("cls");
	cout << "Task 2\n";

	unsigned short r, w;
	unsigned short   b, k, t;
	char text[8][8];
	char c[64];
	unsigned short result[8][8];
	fstream fout;
	//
	cout << "Введiть 8 рядкiв тексту(до 8 символiв, якщо Ваша ласка):\n";
	for (int i = 0; i < 8; i++)
	{
		cin >> text[i];
		
		int n = strlen(text[i]);
		while (n < 7)
		{
			strcat_s(text[i], " ");
			n++;
		}
		text[i][7] = '\0';
	}
	fout.open("file.txt", fstream::out | fstream::app); 
	for (int i = 0; i < 8; i++) {
		fout << text[i] << endl; 
	}
	fout.close();
	
	cout << "\tДякую. Ваш результат. Текст модна перевiрити у текстовому файлi\n";
	for (unsigned short i = 0; i < 8; i++)
	{
		for (unsigned short j = 0; j < 8; j++)
		{
			/*у бітах 0 - 2 знаходиться номер рядка символу(3 біти),
				у бітах 3 - 10 ASCII - код букви(8 біт),
				11 біт – біт парності перших двох полів(1 біт)
				у бітах 12 - 14 позиція символу в рядку(3 біти),
				15 біт - біт парності попереднього поля(1 біт).*/
				unsigned short r = 0, w = 0;
				// Line number/номер рядка символу (3 bits)
				r |= i;
				// ASCII letter code/код букви (8 bits)
				w = text[i][j];
				r |= (w << 3);
				// Bit values of pairs/біт парності перших двох полів (1 bit)
				if ((i & (1 << 1)) || (w & (1 << 7))) {
					r |= (1 << 11);
				}
				// Position of the character in the line (3 bits)
				r |= (j << 12);
				// Parity bit/ (1 bit)
				int b = 0;
				for (int k = 0; k < 15; k++) {
					if (r & (1 << k)) {
						b = ~b;
					}
				}
				if (b == 1) {
					r |= (1 << 15);
				}
				result[i][j] = r;
		}
	}
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				bitset<16> x(result[i][j]);
				cout << x << endl;
			}
		}
		ofstream MyFile("file1.dat", ios::out | ios::binary);
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				MyFile.write((const char*)&result[i][j], sizeof(unsigned short));
			}
		}
		MyFile.close();

	
}

void Task2_2() {
	//Друга програма – читає із файлу зашифровану інформацію, розшифровує та виводить у вікно консолі та інший файл
	unsigned short r, w;
	unsigned short b, k, t;
	char text[8][8];
	
	unsigned short result[8][8];

	// Read the encoded data from the binary file
	ifstream MyFile("file1.dat", ios::in | ios::binary);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			MyFile.read((char*)&result[i][j], sizeof(unsigned short));
		}
	}
	MyFile.close();

	for (unsigned short i = 0; i < 8; i++)
	{
		for (unsigned short j = 0; j < 8; j++)
		{
			/*
			у бітах 0 - 2 знаходиться номер рядка символу(3 біти),
				у бітах 3 - 10 ASCII - код букви(8 біт),
				11 біт – біт парності перших двох полів(1 біт)
				у бітах 12 - 14 позиція символу в рядку(3 біти),
				15 біт - біт парності попереднього поля(1 біт).*/

			r = result[i][j];
			// Extract the fields from the encoded value
			unsigned short line = r & 0x7;//номер символу (0x7 має двійкове представлення 00000111 
			                              //(він зберігає лише останні 3 біти, а решту встановлює на 0).
			unsigned short code = (r >> 3) & 0xFF;//ASCII - код букви  0xFF має двійкове представлення 11111111,  зберігає лише останні 8 бітів і встановлює 0
			bool pair_bit = (r >> 11) & 0x1;//біт парності 0x1 (0b00000001) 
			//Цей код маскує всі біти в числі , крім біту, що знаходиться на 11 позиції від кінця числа r.
			//Спочатку число r зсувається на 11 позицій вправо, щоб біт опинився в крайньому правому розряд
		
			unsigned short position = (r >> 12) & 0x7;//символу в рядку  0x7 (0b00000111) 
			
			bool parity_bit = (r >> 15) & 0x1;//біт парності  0x1 (0b00000001)


			// Construct the original character
			text[line][position] = code;
		}
	}
	fstream fout1;
	fout1.open("file2.txt", fstream::out | fstream::app);

	// Print the decoded text
	for (int i = 0; i < 8; i++)
	{
		cout << text[i] << endl;
     fout1 << text[i] << endl;
	}
	fout1.close();
	}

int main()
{
	setlocale(LC_CTYPE, "ukr");
	int ch;
	cout << "\tHi! Here you are able to choose proper task\n";
	cout << "\t\tChoose 1 or 2 and write it" << endl;
	cout << "\t\t\t    3.Exit" << endl;
	cin >> ch;
	switch (ch) {
	case(1):
		Task1();
		break;
	case(2):
		system("cls");
		int ch1;
		cout << "1.Program 1\tШифрування\n2.Program 2\tРозшифрування\n3.Exit\n";
		cin >> ch1;
		system("cls");
		switch (ch1) {
		case(1):
			Task2_1();
			break;
		case(2):
			Task2_2();
			break;
		}
	case(3):	
		break;
		return 0;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка " > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
