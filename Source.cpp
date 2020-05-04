#include <clocale>
#include <iostream>
using namespace std;
#include "Complex.h"
int main()
{
	setlocale(LC_CTYPE, "Russian");
	Complex c1; // конструктор по умолчанию
	Complex c2(1.1, 2.2); // конструктор инициализатор
	Complex c3(3.3, 4.4); // конструктор инициализатор
	Complex c4(c2); // конструктор копирования
	c1.outPut("c1");
	c2.outPut("c2");
	c3.outPut("c3");
	c4.outPut("c4");
	cout << "\nc5 = c2 " << endl;
	Complex c5;
	c5 = c2;
	c5.outPut("c5");
	cout << "\nc1 == c2 " << endl;
	bool b = c1 == c2;
	cout << "b = " << b << " " << endl;
	cout << "\nc7 = c2 + c3;" << endl;
	Complex c7;
	c7 = c2 + c3;
	c7.outPut("c7");
	cout << "\nc7 = c2 - c3; " << endl;
	c7 = c2 - c3;
	c7.outPut("c7");
	cout << "\nc7 = c2 * c3; " << endl;
	c7 = c2 * c3;
	c7.outPut("c7");
	cout << "\nc7 = c2 / c3; " << endl;
	c7 = c2 / c3;
	c7.outPut("c7");
	cout << "\nc7 = 1.1 * c2 " << endl;
	c7 = 1.1 * c2;
	c7.outPut("c7");
	cout << "\nc7 = c2 * 2.2 " << endl;
	c7 = c2 * 2.2;
	c7.outPut("c7");
	// Запись в поток
	cout << "\nos << c2 << c3 << endl;" << endl;
	c2.outPut("c2");
	c3.outPut("c3");
	ofstream os; // поток для записи
	os.open("complex.txt"); // файл для записи
	os << c2 << c3 << endl;
	os.close();
	// Чтение из потока
	cout << "\nis >> c1 >> c4;" << endl;
	ifstream is; // поток для чтения
	is.open("complex.txt"); // файл для чтения
	is >> c1 >> c4;
	c1.outPut("c1");
	c4.outPut("c4");

	c3.outPut("c3");
	cout << "Module c3: " << c3.module() << endl;
	c3.exponen(2);
	c3.outPut("c3^2");
	c3.exponen(1/2);
	c3.outPut("c3^1/2");
	c3.exponen(-2);
	c3.outPut("c3^-2");
	c3.exponen(-1/2);
	c3.outPut("c3^2");
	is.close();
	cout << "\n" << endl;
	int a;
	cin >> a;
	



	return 0;
}
