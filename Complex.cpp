#include "Complex.h"
#include <iostream>
#include <math.h>
using namespace std;

//  онструктор по умолчанию
Complex::Complex() {
  re = 0.0;
  im = 0.0;
}
//  онструктор копировани€
Complex::Complex(const Complex& c) {
  re = c.re;
  im = c.im;
}
//  онструктор инициализации
Complex::Complex(double _re, double _im) : re(_re), im(_im) { }
//  онструктор преобразовани€ типа
Complex::Complex(double _re) {
  re = _re;
  im = 0.0;
}
// ƒеструктор
Complex::~Complex() {
  re = 0.0;
  im = 0.0;
}

void Complex::outPut(const char* name) 
{
  cout << name << ": re = " << re << ": im = " << im << endl;
}


Complex Complex::operator+(const Complex& c2)
  {
  Complex tmp;
  tmp.re = re + c2.re;
  tmp.im = c2.im + im;
  return tmp;
  }

Complex Complex::operator-(const Complex& c2)
{
  Complex tmp;
  tmp.re = re - c2.re;
  tmp.im = im - c2.im;
  return tmp;
}
Complex Complex::operator+(double d)
{
  Complex tmp;
  tmp.re = re + d;
  tmp.im = im;
  return tmp;
}

Complex operator+(double d, const Complex& c2)
{
  Complex tmp;
  tmp.re = d + c2.re;
  tmp.im = c2.im;
  return tmp;
}
Complex& Complex::operator=(const Complex& C)// возвращаемый тип Ccomplex&
{
  if (this != &C) // проверка (указатель на мен€) != (адрес C)
  {
    re = C.re;
    im = C.im;
  }
  return *this; // возврат себ€
}

bool Complex::operator==(const Complex& c2)
{
  return (re == c2.re && im == c2.im);
}

Complex Complex::operator++()
{
  re = re + 1.0;
  im = im + 1.0;
  return *this;
}

Complex Complex::operator++(int)
{
  Complex tmp(*this);
  re = re + 1.0;
  im = im + 1.0;
  return tmp;

}
Complex Complex::operator/(const Complex& c) {
  Complex res;
  double tmp = c.re * c.re + c.im * c.im;
  res.re = (re * c.re + im * c.im) / tmp;
  res.im = (im * c.re - re * c.im) / tmp;
  return res;
}
Complex Complex::operator*(const Complex& c) {
  Complex res;
  res.re = re * c.re - im * c.im;
  res.im = re * c.im + im * c.re;
  return res;
}

double Complex::module()
{
	return sqrt(im*im + re*re);
}

Complex Complex::exponen(int n)
{
  double fi = acos(re/(this->module()));
      re = pow(this->module(), n) * cos(n * fi);
      im = pow(this->module(), n) * sin(n * fi);
  return *this;
}

Complex Complex::operator-()
{
  return Complex(-re, -im);
}

Complex operator*(double d, const Complex& c) {
  return Complex(d * c.re, d * c.im);
}
ostream& operator<<(ostream& stream, const Complex& c) {
  stream << c.re << " " << c.im << endl;
  return stream;
}
istream& operator>>(istream& stream, Complex& c) {
  stream >> c.re >> c.im;
  return stream;
}