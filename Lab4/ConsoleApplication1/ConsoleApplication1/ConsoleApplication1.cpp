// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include <string>
#include <clocale>
#include <complex>
#include <map>
#include <fstream.>
#include <stdexcept>
using namespace std;
//typedef double ComplexDouble;


class VectorShort {
	short* v;
	int num;
	int codeError;
public:
	//перевантажений оператор зсуву біта вправо, який зсуває всі біти кожного елемента вектора на задану кількість позицій вправо.
	friend VectorShort operator>>(const VectorShort& vec, const int shift) {
		VectorShort result(vec.num);
		for (int i = 0; i < vec.num; i++) {
			result.v[i] = vec.v[i] >> shift;
		}
		return result;
	}

	//перевантажений оператор зсуву біта вліво, який зсуває всі біти кожного елемента вектора на задану кількість позицій вліво
	friend VectorShort operator<<(const VectorShort& vec, const int shift) {
		VectorShort result(vec.num);
		for (int i = 0; i < vec.num; i++) {
			result.v[i] = vec.v[i] << shift;
		}
		return result;
	}
	// Constructor without parameters
	//створює VectorShort, який має нульове значення
	VectorShort() {
		num = 1;
		v = new short[num];
		v[0] = 0;
		codeError = 0;
	}

	// Constructor with one parameter - the size of the vector
	VectorShort(int size) {
		num = size;
		v = new short[num];
		for (int i = 0; i < num; i++) {
			v[i] = 0;
		}
		codeError = 0;
	}

	// Constructor with two parameters - vector size and value initialization
	VectorShort(int size, short value) {
		num = size;
		v = new short[num];
		for (int i = 0; i < num; i++) {
			v[i] = value;
		}
		codeError = 0;
	}
//перевантажений оператор нижнього індексу, який дозволяє отримати доступ до окремих елементів
	//функцію, яка звертається до елементу
	//масиву за індексом, якщо індекс невірний функція вказує на останній
	//	елемент масиву та встановлює код помилки у змінну codeError;
	short& operator[](int index) {
		if (index < 0 || index >= num) {
			codeError = 1;
		}
		return v[index];
	}

	// Copy constructor
	VectorShort(const VectorShort& other) {
		num = other.num;
		v = new short[num];
		for (int i = 0; i < num; i++) {
			v[i] = other.v[i];
		}
		codeError = other.codeError;
	}

	// Destructor
	~VectorShort() {
		delete[] v;
	}

//присвоєння =: копіює вектор
	VectorShort& operator=(const VectorShort& other) {
		if (this == &other) {
			return *this;
		}
		delete[] v;
		num = other.num;
		codeError = other.codeError;
		v = new short[num];
		for (int i = 0; i < num; i++) {
			v[i] = other.v[i];
		}
		return *this;
	}

	// Overload prefix increment operator
	VectorShort& operator++() {
		for (int i = 0; i < num; i++) {
			v[i]++;
		}
		return *this;
	}

	// Overload postfix increment operator
	VectorShort operator++(int) {
		VectorShort temp(*this);
		operator++();
		return temp;
	}

	// Overload prefix decrement operator
	VectorShort& operator--() {
		for (int i = 0; i < num; i++) {
			v[i]--;
		}
		return *this;
	}

	// Overload postfix decrement operator
	VectorShort operator--(int) {
		VectorShort temp(*this);
		operator--();
		return temp;
	}

//повертає значення true, якщо елементи якщо size не дорівнює – нулю, 
	bool operator!() const {
		return num == 0;
	}

	VectorShort operator~() const {//Двійковий вид числа, зворотного даному (наприклад, 5 і -5) виходить шляхом переведення всіх бітів з додатком 1.
		VectorShort result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = ~v[i];
		}
		return result;
	}
	VectorShort  operator-() const {
		VectorShort  result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = -v[i];
		}
		return result;
	}
	static VectorShort create(int size, const double* elements) {
		VectorShort result(size);
		for (int i = 0; i < size; i++) {
			result.v[i] = elements[i];
		}
		for (int i = 0; i < size; i++) {
			cout << result.v[i] << " ";
		}
		cout << endl;
		return result;
	}
	static VectorShort createWithInput() {
		int size;
		cout << "Enter the size of the vector: ";
		cin >> size;

		double* elements = new double[size];
		cout << "Enter the elements of the vector:\n";
		for (int i = 0; i < size; i++) {
			cin >> elements[i];
		}

		VectorShort result = create(size, elements);

		delete[] elements;

		return result;
	}
	//виділяє новий масив shortцілих чисел із розміром вхідного об’єкта та копіює існуючі елементи поточного об’єкта,
	//додаючи до них відповідні елементи вхідного об’єкта.Потім він копіює решту елементів вхідного об’єкта в новий масив.
	//	Нарешті, він звільняє старий масив і оновлює розмір поточного об’єкта.
	VectorShort& operator+=(const VectorShort& other) {
		if (num < other.num) {
			short* new_v = new short[other.num];
			for (int i = 0; i < num; i++) {
				new_v[i] = v[i] + other.v[i];
			}
			for (int i = num; i < other.num; i++) {
				new_v[i] = other.v[i];
			}
			delete[] v;
			v = new_v;
			num = other.num;
		}
		else {
			for (int i = 0; i < other.num; i++) {
				v[i] += other.v[i];
			}
		}
		return *this;
	}
	VectorShort& operator-=(const VectorShort& other) {
		//визначає мінімальний розмір двох векторів
		//виділяє новий масив шортів для зберігання результату віднімання вектора
	int min_num = std::min(num, other.num);
		short* new_v = new short[min_num];

		for (int i = 0; i < min_num; i++) {
			new_v[i] = v[i] - other.v[i];
		}

		if (num < other.num) {
			for (int i = min_num; i < other.num; i++) {
				new_v[i] = -other.v[i];
			}
			num = other.num;
		}
		else {
			for (int i = min_num; i < num; i++) {
			}
		}

		delete[] v;
		v = new_v;

		return *this;
	}
	VectorShort& operator*=(short scalar) {
		for (int i = 0; i < num; i++) {
			v[i] *= scalar;
		}
		return *this;
	}
	VectorShort& operator/=(short scalar) {
		if (scalar == 0) {
			// Handle division by zero error
		}		
		else {
			for (int i = 0; i < num; i++) {
				v[i] /= scalar;
			}
		}
		return *this;
	}
	VectorShort& operator%=(short scalar) {
		if (scalar == 0) {
			// Handle division by zero error
		}
		else {
			for (int i = 0; i < num; i++) {
				v[i] %= scalar;
			}
		}
		return *this;
	}
	VectorShort& operator|=(const VectorShort& other) {
		if (num != other.num) {
		}
		else {
			for (int i = 0; i < num; i++) {
				v[i] |= other.v[i];
			}
		}
		return *this;
	}
	// Overload the ^= operator
	VectorShort& operator^=(const VectorShort& other) {
		int min_num = std::min(num, other.num);
		for (int i = 0; i < min_num; i++) {
			v[i] ^= other.v[i];
		}
		return *this;
	}

	// Overload the &= operator
	VectorShort& operator&=(const VectorShort& other) {
		int min_num = std::min(num, other.num);
		for (int i = 0; i < min_num; i++) {
			v[i] &= other.v[i];
		}
		return *this;
	}

	VectorShort operator+(const VectorShort& other) const {
		if (num != other.num) {
		}
		VectorShort result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] + other.v[i];
		}
		return result;
	}
	VectorShort operator-(const VectorShort& other) const {
		if (num != other.num) {
		}
		VectorShort result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] - other.v[i];
		}
		return result;
	}
	VectorShort operator*(int scalar) const {
		VectorShort result(num);
		for (int i = 0; i < num; i++) {
			result[i] = v[i] * scalar;
		}
		return result;
	}
	// Division of a vector by a number of type int
	VectorShort operator/(int divisor) const {
		if (divisor == 0) {
			// division by zero is undefined, set an error code
			VectorShort result;
			result.codeError = 1;
			return result;
		}
		VectorShort result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] / divisor;
		}
		return result;
	}

	// Remainder from dividing a vector by a number of type int
	VectorShort operator%(int divisor) const {
		if (divisor == 0) {
			// division by zero is undefined, set an error code
			VectorShort result;
			result.codeError = 1;
			return result;
		}
		VectorShort result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] % divisor;
		}
		return result;
	}
	VectorShort operator|(const VectorShort& other) const {
		if (num != other.num) {
		}
		VectorShort result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] | other.v[i];
		}
		return result;
	}

	// bitwise XOR operator
	VectorShort operator^(const VectorShort& other) const {
		if (num != other.num) {
			// handle error
		}
		VectorShort result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] ^ other.v[i];
		}
		return result;
	}

	// bitwise AND operator
	VectorShort operator&(const VectorShort& other) const {
		if (num != other.num) {
		}
		VectorShort result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] & other.v[i];
		}
		return result;
	} 
	bool operator==(const VectorShort& other) const {
		if (num != other.num) {
			// If the two vectors have different lengths, they are not equal
			return false;
		}
		for (int i = 0; i < num; i++) {
			// Compare each pair of elements by index
			if (v[i] != other.v[i]) {
				// If any pair of elements is different, the vectors are not equal
				return false;
			}
		}
		// If all pairs of elements are equal, the vectors are equal
		return true;
	}
	bool operator!=(const VectorShort& other) const {
		if (num != other.num) {
			// If the two vectors have different lengths, they are not equal
			return true;
		}
		for (int i = 0; i < num; i++) {
			// Compare each pair of elements by index
			if (v[i] != other.v[i]) {
				// If any pair of elements is different, the vectors are not equal
				return true;
			}
		}
		// If all pairs of elements are equal, the vectors are equal
		return false;
	}
	void* operator new(size_t size) {
		void* p = ::operator new(size);
		return p;
	}

	// Overloaded delete operator for releasing dynamically allocated memory
	void operator delete(void* ptr) {
		::operator delete(ptr);
	}
	// function call operator ()
	//повертає значення елемента за вказаним індексом
	int operator() (int index) const {
		if (index < 0 || index >= num) {
			cout << "Index out of range." << endl;
			return -1;
		}
		return v[index];
	}
	// Member function to perform comparison greater than (>)
	//порівнює елементи двох векторів і повертає істину, якщо всі елементи в першому векторі більші за відповідні елементи в другому векторі.
	bool operator>(const VectorShort& b) const {
		if (num != b.num) {
			cout << "Error: Vectors have different sizes!\n";
			return false;
		}
		for (int i = 0; i < num; i++) {
			if (v[i] <= b.v[i]) {
				return false;
			}
		}
		return true;
	}

	// Member function to perform comparison greater than or equal to (>=)
	//повертає істину, якщо всі елементи в першому векторі більші або дорівнюють відповідним елементам у другому векторі
	bool operator>=(const VectorShort& b) const {
		if (num != b.num) {
			cout << "Error: Vectors have different sizes!\n";
			return false;
		}
		for (int i = 0; i < num; i++) {
			if (v[i] < b.v[i]) {
				return false;
			}
		}
		return true;
	}

	// Member function to perform comparison less than (<)
	//повертає істину, якщо всі елементи в першому векторі менші за відповідні елементи в другому векторі
	bool operator<(const VectorShort& b) const {
		if (num != b.num) {
			cout << "Error: Vectors have different sizes!\n";
			return false;
		}
		for (int i = 0; i < num; i++) {
			if (v[i] >= b.v[i]) {
				return false;
			}
		}
		return true;
	}

	// Member function to perform comparison less than or equal to (<=)
	//порівнює елементи двох векторів і повертає істину, якщо всі елементи в першому векторі менші або дорівнюють відповідним елементам у другому векторі
	bool operator<=(const VectorShort& b) const {
		if (num != b.num) {
			cout << "Error: Vectors have different sizes!\n";
			return false;
		}
		for (int i = 0; i < num; i++) {
			if (v[i] > b.v[i]) {
				return false;
			}
		}
		return true;
	}





};
class Array
{
	
	map<int, string> numbers{};
	int CodeError;
public:
	Array();
	string& operator[](int index);
	int& operator[](string index);
	friend istream& operator>>(istream& is, Array& a);
	//вивід в консоль
	friend ostream& operator<<(ostream& os, Array& a)
	{
		int i;
		for (i = 0; i < 7; i++) os << " " << a.numbers[i] << " ";
		return os;
	}
	int& operator()(string index);

};

Array::Array()
{
	CodeError = 0;
	numbers[101] = "bunny@gmail.com";
	numbers[102] = "firefly@gmail.com";
	numbers[103] = "mimimi@gmail.com";
	numbers[104] = "NiceToMeetYou@gmail.com";
	numbers[109] = "user12335324@gmail.com";

}
//приймає індекс і повертає рядкове посилання на елемент із цим індексом
string& Array::operator[](int index) {
	if (index < 0|| index>=110 ) {
		CodeError = -1;
		cout << "Check index";
		return numbers[111];
	}
	return numbers[index];
}
//приймає рядковий індекс і повертає ціле посилання на індекс
int& Array::operator[](string index) {
	for (int i = 1; i <= 110; i++) {
		if (numbers[i] == index) {
			return i;
		}
	}		cout << "Check index";

}
int& Array::operator()(string index) {
	for (int i = 0; i <= 110; i++) {
		if (numbers[i] == index)
			return i;
	}
	cout << "Check index";

}

//зчитує змінну
istream& operator>>(istream& is, Array& a)
{
	int i;
	for (i = 0; i < 110; i++) is >> a.numbers[i];
	return is;
}

void Task2() {
	Array array;
	int index;
	cin>>index;
	cout << array[index];
}

void Task1() {

	int size, value;
	cout << "Enter size of vector: ";
	cin >> size;

	VectorShort v1(size);
	cout << "v1 = ";
	for (int i = 0; i < size; i++) {
		cout << v1[i] << " ";
	}
	cout << endl;

	cout << "Enter value to initialize vector: ";
	cin >> value;

	VectorShort v2(size, value);
	cout << "v2 = ";
	for (int i = 0; i < size; i++) {
		cout << v2[i] << " ";
	}
	cout << endl;

	VectorShort v3 = v2;
	VectorShort v99 = v2;
	VectorShort v88 = v2;

	cout << "v3(copy) = ";
	for (int i = 0; i < size; i++) {
		cout << v3[i] << " ";
	}
	cout << endl;

	v2++;
	cout << "v2++ = ";
	for (int i = 0; i < size; i++) {
		cout << v2[i] << " ";
	}
	cout << endl;

	++v2;
	cout << "++v2 = ";
	for (int i = 0; i < size; i++) {
		cout << v2[i] << " ";
	}
	cout << endl;

	VectorShort v4 = v2--;

	cout << "v4 = v2-- = ";
	for (int i = 0; i < size; i++) {
		cout << v2[i] << " ";
	}
	cout << endl;
	--v2;
	cout << "--v2 = ";
	for (int i = 0; i < size; i++) {
		cout << v2[i] << " ";
	}
	cout << endl;


	bool is_empty = !v1;
	cout << "v1 is empty? " << boolalpha << is_empty << endl;

	VectorShort v5 = ~v3;
	cout << "v5 = ~v3" << endl;
	std::cout << "Original vector: ";
	for (int i = 0; i < size; i++) {
		std::cout << v3[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Result vector: ";
	for (int i = 0; i < size; i++) {
		std::cout << v5[i] << " ";
	}
	cout << std::endl;
	cout << "v6 = -v3" << endl;

	VectorShort v6 = -v3;
	for (int i = 0; i < size; i++) {
		cout << v6[i] << " ";
	}
	cout << std::endl;
	VectorShort v7 = VectorShort::createWithInput();
	VectorShort v12 = v7;	VectorShort v77 = v7;	VectorShort v100 = v7;	VectorShort v0 = v7;
	VectorShort v8 = v3 += v7;
	cout << "v3 += v7 = ";
	for (int i = 0; i < size; i++) {
		cout << v8[i] << " ";
	}
	cout << endl;
	v3 -= v7;
	VectorShort v9 = v3 -= v7;
	cout << "v3 -= v7 = ";
	for (int i = 0; i < size; i++) {
		cout << v9[i] << " ";
	}
	cout << endl;
	cout << endl;
	short s;
	cout << "Scalar=";
	cin >> s;
	cout << "*=" << endl;
	VectorShort v10 = v7 *= s;
	for (int i = 0; i < size; i++) {
		cout << v10[i] << " ";
	}
	cout << endl;
	v7 /= s;
	cout << "/=" << endl;
	VectorShort v11 = v7 /= s;
	for (int i = 0; i < size; i++) {
		cout << v11[i] << " ";
	}
	cout << endl;
	cout << "%" << endl;
	v12 %= s;
	VectorShort v13 = v12 %= s;
	for (int i = 0; i < size; i++) {
		cout << v12[i] << " ";
	}
	cout << endl;

	
	cout << "+" << endl;
	v99 + v100;
	VectorShort v14 = v99 + v100;
	for (int i = 0; i < size; i++) {
		cout << v14[i] << " ";
	}
	cout << endl;
	v99 - v100;
	cout << "-" << endl;

	VectorShort v15 = v99 - v100;
	for (int i = 0; i < size; i++) {
		cout << v15[i] << " ";
	}
	cout << endl;
	int r;
	cout << "Scalar for * =";
	cin >> r;
	cout << "*" << endl;
	VectorShort v16 = v100 * r;
	for (int i = 0; i < size; i++) {
		cout << v16[i] << " ";
	}
	cout << endl;
	cout << "/" << endl;
	VectorShort v17 = v0 / r;
	for (int i = 0; i < size; i++) {
		cout << v17[i] << " ";
	}
	cout << endl;
	cout << "%" << endl;
	VectorShort v18 = v0 % r;
	for (int i = 0; i < size; i++) {
		cout << v18[i] << " ";
	}
	cout << endl;
	VectorShort v19 = v0 >> 1;		std::cout << "After right shift by 1 bit: " << endl;

	for (int i = 0; i < size; i++) {
		cout << v19[i] << " ";
	}
	VectorShort v20 = v0 << 1;		std::cout << endl << "After right shift by 1 bit: " << endl;

	for (int i = 0; i < size; i++) {
		cout << v20[i] << " ";
	}
	cout << endl << "==" << endl;
	v77 == v88;
	bool equal = (v77 == v88);
	cout << equal;
	cout << endl << "!=" << endl;
	v77 != v88;
	bool equal1 = (v77 != v88);
	cout << equal1;
    cout << "v1 > v2: " <<endl<< (v77 > v88) << std::endl;
	cout << "v1 >= v2: " << (v77 > v88) << std::endl;
	cout << "v1 < v2: " << (v77 > v88) << std::endl;
	cout << "v1 <= v2: " << (v77 > v88) << std::endl;
}
int main() {
	setlocale(LC_CTYPE, "ukr");
	int c;
	cin >> c;	
	Array arr;
	switch (c)
	{
	case 1:
		Task1();
		break;
	case 2:
		system("CLS");
		cout << "\n101 – Пожежна допомога\n102 – Полiцiя\n103 – Швидка медична допомога\n104 – Аварiйна служба газової мережi\n109 – Довiдкова служба\n";
		Task2();
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
