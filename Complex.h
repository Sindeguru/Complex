#pragma once
#include <fstream>
using namespace std;

class Complex
{
private:
  double re, im;
public:
  void setre(double _re) { re = _re; }
  double getre() { return re; }
  void setim(double _im) { im = _im; }
  double getim() { return im; }
  void outPut(const char* name);

  double& Re() { return re; }
  double& Im() { return im; }
  // Конструктор по умолчанию
  Complex();
  // Конструктор копирования
  Complex(const Complex& c);
  // Конструктор инициализации
  Complex(double _re, double _im);
  // Конструктор преобразования типа
  Complex(double _re);
  // Деструктор
  ~Complex();

  // перегрузка  +,-,*,/,=,==, потоковый ввод и вывод
  Complex operator+(const Complex& c2);
  Complex operator+(double d);
  friend Complex operator+(double d, const Complex& c2);
  Complex operator-(const Complex& c2);
  Complex& operator=(const Complex& C);
  //Complex operator*(const Complex& c2);
  Complex operator/(const Complex& c2);
  bool operator==(const Complex& c2);
  Complex operator++(); // префиксный ++
  Complex operator++(int); // постфиксный ++
  Complex operator-(); // унарный -
  Complex operator*(const Complex& c);
  friend Complex operator*(double d, const Complex& c);
  friend ostream& operator<<(ostream& stream, const Complex& c);
  friend istream& operator>>(istream& stream, Complex& c);

  //Доп задание для запаздашек:
  double module();
  Complex exponen(int n);

};