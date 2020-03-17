#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
	int n = 0;
	Complex sir[100];
	cout << "n = ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> sir[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << sir[i] << endl;
	}
	cout << ecuatie(1, Complex(1, 1), 3).first << ' ' << ecuatie(1, Complex(1, 1), 3).second;
	return 0;
}