#pragma once

#include <iostream>

using namespace std;

class Complex
{
private:
	double re;
	double im;
public:
	Complex(const double real = 0, const double imaginar = 0);
	Complex(const Complex& z);
	~Complex();
	void set_real(const double real);			// setare parte reala
	void set_imaginar(const double imaginar);	// setare parte imaginara
	double get_real();							// furnizare parte reala
	double get_imaginar();						// furnizare parte imaginara
	void citire();
	void afisare();

	friend Complex operator+(const Complex z1, const Complex z2);
	friend Complex operator+(const double z1, const Complex z2);
	friend Complex operator+(const Complex z1, const double z2);
	friend Complex operator+(const Complex z);

	friend void operator+=(Complex& z1, const Complex z2);
	friend void operator+=(Complex& z1, const double z2);

	friend Complex operator-(const Complex z1, const Complex z2);
	friend Complex operator-(const double z1, const Complex z2);
	friend Complex operator-(const Complex z1, const double z2);
	friend Complex operator-(const Complex z);

	friend void operator-=(Complex& z1, const Complex z2);
	friend void operator-=(Complex& z1, const double z2);

	friend Complex operator*(const Complex z1, const Complex z2);
	friend Complex operator*(const double z1, const Complex z2);
	friend Complex operator*(const Complex z1, const double z2);

	friend void operator*=(Complex& z1, const Complex z2);
	friend void operator*=(Complex& z1, const double z2);

	friend Complex operator/(const Complex z1, const Complex z2);
	friend Complex operator/(const double z1, const Complex z2);
	friend Complex operator/(const Complex z1, const double z2);

	friend void operator/=(Complex& z1, const Complex z2);
	friend void operator/=(Complex& z1, const double z2);

	friend Complex operator^(const Complex z, const int p);

	friend bool operator==(const Complex z1, const Complex z2);
	friend bool operator==(const double z1, const Complex z2);
	friend bool operator==(const Complex z1, const double z2);

	friend bool operator!=(const Complex z1, const Complex z2);
	friend bool operator!=(const double z1, const Complex z2);
	friend bool operator!=(const Complex z1, const double z2);

	friend istream& operator>>(istream& in, Complex& z);
	friend ostream& operator<<(ostream& out, const Complex z);

	friend double abs(const Complex z);
	friend pair<Complex, Complex> sqrt(const Complex z);
	friend pair<Complex, Complex> ecuatie(const Complex a, const Complex b, const Complex c);
};