#include "Complex.h"

Complex::Complex(const double real, const double imaginar)
{
	re = real;
	im = imaginar;
}
Complex::Complex(const Complex& z)
{
	re = z.re;
	im = z.im;
}
Complex::~Complex()
{
	re = 0;
	im = 0;
}
void Complex::set_real(const double real)
{
	re = real;
}
void Complex::set_imaginar(const double imaginar)
{
	im = imaginar;
}
double Complex::get_real()
{
	return re;
}
double Complex::get_imaginar()
{
	return im;
}
void Complex::citire()
{
	double real, imaginar;
	cout << "Parte reala: ";
	cin >> real;
	cout << "Parte imaginara: ";
	cin >> imaginar;
	re = real;
	im = imaginar;
}
void Complex::afisare()
{
	if ((re != 0) || (re == 0 && im == 0))
	{
		cout << re;
	}
	if (im != 0)
	{
		if (im > 0 && re != 0)
		{
			cout << "+";
		}
		cout << im << "*i";
	}
	cout << endl;
}

// Este specificat in cerinta exercitiului ca operatorii de mai jos sa fie realizati prin intermediul functiilor friend!

// OPERATORUL +
Complex operator +(const Complex z1, const Complex z2)
{
	return Complex(z1.re + z2.re, z1.im + z2.im);
}
Complex operator +(const double z1, const Complex z2)
{
	return Complex(z1 + z2.re, z2.im);
}
Complex operator +(const Complex z1, const double z2)
{
	return Complex(z1.re + z2, z1.im);
}
Complex operator +(const Complex z)
{
	return z;
}

// OPERATORUL +=
void operator +=(Complex& z1, const Complex z2)
{
	z1 = Complex(z1.re + z2.re, z1.im + z2.im);
}
void operator +=(Complex& z1, const double z2)
{
	z1 = Complex(z1.re + z2, z1.im);
}

// OPERATORUL -
Complex operator -(const Complex z1, const Complex z2)
{
	return Complex(z1.re - z2.re, z1.im - z2.im);
}
Complex operator -(const double z1, const Complex z2)
{
	return Complex(z1 - z2.re, -z2.im);
}
Complex operator -(const Complex z1, const double z2)
{
	return Complex(z1.re - z2, z1.im);
}
Complex operator -(const Complex z)
{
	return Complex(-z.re, -z.im);
}

// OPERATORUL -=
void operator -=(Complex& z1, const Complex z2)
{
	z1 = Complex(z1.re - z2.re, z1.im - z2.im);
}
void operator -=(Complex& z1, const double z2)
{
	z1 = Complex(z1.re - z2, z1.im);
}

// OPERATORUL *
Complex operator *(const Complex z1, const Complex z2)
{
	/*
	z1 = a + bi
	z2 = c + di
	z1 * z2 = (a + bi)*(c + di) = (ac - bd) + i*(ad + bc)
	*/
	return Complex(z1.re * z2.re - z1.im * z2.im, z1.re * z2.im + z1.im * z2.re);
}
Complex operator *(const double z1, const Complex z2)
{
	return Complex(z1 * z2.re, z1 * z2.im);
}
Complex operator *(const Complex z1, const double z2)
{
	return Complex(z1.re * z2, z1.im * z2);
}

// OPERATORUL *=
void operator *=(Complex& z1, const Complex z2)
{
	z1 = Complex(z1.re * z2.re - z1.im * z2.im, z1.re * z2.im + z1.im * z2.re);
}
void operator *=(Complex& z1, const double z2)
{
	z1 = Complex(z1.re * z2, z1.im * z2);
}

// OPERATORUL /
Complex operator /(const Complex z1, const Complex z2)
{
	/*
	z1 = a + bi
	z2 = c + di
	z1 / z2 = (a + bi)/(c + di) = (a+bi)(c-di)/(c^2 + d^2) = (ac + bd)/(c^2 + d^2) + i * (bc - ad)/(c^2 + d^2)
	*/
	return Complex((z1.re * z2.re + z1.im * z2.im) / (z2.re * z2.re + z2.im * z2.im), (-z1.re * z2.im + z1.im * z2.re) / (z2.re * z2.re + z2.im * z2.im));
}
Complex operator /(const double z1, const Complex z2)
{
	return Complex((z1 * z2.re) / (z2.re * z2.re + z2.im * z2.im), (-z1 * z2.im) / (z2.re * z2.re + z2.im * z2.im));
}
Complex operator /(const Complex z1, const double z2)
{
	return Complex(z1.re / z2, z1.im / z2);
}

// OPERATORUL /=
void operator /=(Complex& z1, const Complex z2)
{
	z1 = Complex((z1.re * z2.re + z1.im * z2.im) / (z2.re * z2.re + z2.im * z2.im), (-z1.re * z2.im + z1.im * z2.re) / (z2.re * z2.re + z2.im * z2.im));
}
void operator /=(Complex& z1, const double z2)
{
	z1 = Complex(z1.re / z2, z1.im / z2);
}

// OPERATORUL ^
Complex operator ^(const Complex z, const int p)
{
	Complex aux = z;
	int putere = p;
	/*
	Aici am folosit aux pentru a retine rezultatele prin inmultirea lui z, aux reprezinta puterea lui z la un anumit pas
	la pasul final va fi egal cu z^p
	*/
	while (putere > 1)
	{
		putere--;
		aux = Complex(z.re * aux.re - z.im * aux.im, z.re * aux.im + z.im * aux.re);
	}
	return aux;
}

// OPERATORUL ==
bool operator ==(const Complex z1, const Complex z2)
{
	return (z1.re == z2.re) && (z1.im == z2.im);
}
bool operator ==(const double z1, const Complex z2)
{
	return (z1 == z2.re) && (z2.im == 0);
}
bool operator ==(const Complex z1, const double z2)
{
	return (z1.re == z2) && (z1.im == 0);
}

// OPERATORUL !=
bool operator !=(const Complex z1, const Complex z2)
{
	return (z1.re != z2.re) || (z1.im != z2.im);
}
bool operator !=(const double z1, const Complex z2)
{
	return (z1 != z2.re) || (z2.im != 0);
}
bool operator !=(const Complex z1, const double z2)
{
	return (z1.re != z2) || (z1.im != 0);
}

double abs(const Complex z)
{
	// radicalul complex, pentru z = a + bi este radical din a^2 + b^2
	return sqrt((z.re) * (z.re) + (z.im) * (z.im));
}

pair<Complex, Complex> sqrt(const Complex z1)
{
	Complex rez;
	double z1_mod = abs(z1);
	double a = z1.re;
	double b = z1.im;
	/* radicalul unui numar complex, dat prin relatia z = a + bi,  este dat de formula:
	q = sqrt(sqrt(a^2 + b^2) + a) / 2), r = sqrt(sqrt(a^2 + b^2) - a) / 2)
	unde, pentru b > 0, avem:
	sqrt(z) = q + ri sau sqrt(z) = -q - ri, adica forma negativa a primului
	,iar pentru b <= 0, avem:
	sqrt(z) = q - ri sau sqrt(z) = -q + ri, adica forma negativa a primului*/
	if (b > 0)
	{
		Complex z2 = Complex(sqrt((z1_mod + a) / 2), sqrt((z1_mod - a) / 2));
		return make_pair(z2, -z2);
	}
	else
	{
		Complex z2 = Complex(sqrt((z1_mod + a) / 2), -sqrt((z1_mod - a) / 2));
		return make_pair(z2, -z2);
	}
}

pair<Complex, Complex> ecuatie(const Complex a, const Complex b, const Complex c)
{
	Complex rad_delta;
	rad_delta = sqrt(((b ^ 2) - (4 * a * c))).first; // am luat doar prima solutie, pentru ca a doua e cu semn schimbat si nu schimba solutiile
	Complex x1, x2;
	x1 = (-b + rad_delta) / 2 * a;
	x2 = (-b - rad_delta) / 2 * a;
	/* daca rad_delta este 0, oricum vom fi returnat un pair de forma make_pair(-b/2a, -b/2a), deci nu este nevoie
	sa il tratam drept caz separat, deoarece cazul general il cuprinde si pe acesta */
	return make_pair(x1, x2);
}

// OPERATORUL >>
istream& operator>>(istream& in, Complex& z)
{
	cout << "Parte reala: ";
	in >> z.re;
	cout << "Parte imaginara: ";
	in >> z.im;
	return in;
}

// OPERATORUL <<
ostream& operator<<(ostream& out, Complex z)
{
	if ((z.re != 0) || (z.re == 0 && z.im == 0))
	{
		out << z.re;
	}
	if (z.im != 0)
	{
		if (z.im > 0 && z.re != 0)
		{
			out << "+";
		}
		out << z.im << "*i";
	}
	return out;
}
