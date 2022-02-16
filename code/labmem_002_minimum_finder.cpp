#include <iostream>
#include <cmath>
using namespace std;

//add exceptions for input a and b in functions and for ch in main

double f(double x) {
	return (3 * x * x - 6 * x * cos(x));
}

double f1(double x) {
	return (6 * x * sin(x) + 6 * x - 6 * cos(x));
}

double f2(double x) {
	return (6 * x * cos(x) + 12 * sin(x) + 6);
}

//brute-force search
void m1() {
	double a, b;
	cout << endl;
	cout << "Input - a \n>> ";
	cin >> a;
	cout << "Input - b \n>> ";
	cin >> b;
	cout << endl;
	double x, x0, y, e = 0.1, h;
	int n = (b - a) / e, k = 1;
	h = (b - a) / n;
	y = f(a);
	x0 = a;
	x = a;
	cout << k << ") x = " << x << "\t f(x) = " << f(x) << endl;
	do
	{
		x = x + h;
		if (f(x) < y)
		{
			y = f(x);
			x0 = x;
		}
		k++;
		cout << k << ") x = " << x << "\t f(x) = " << f(x) << endl;
	} while (x < (b - h));
	cout << endl << "Min x = " << x0 << "\t f(x) = " << y << endl;
}

//bitwise search method
void m2() {
	double a, b;
	int k = 1;
	cout << endl;
	cout << "Input - a \n>> ";
	cin >> a;
	cout << "Input - b \n>> ";
	cin >> b;
	cout << endl;
	double h, x0, x1, e = 0.1;
	h = (b - a) / 4;
	x0 = a;
	cout << k << ") x = " << x0 << "\t f(x) = " << f(x0) << endl;
jump1:
	x1 = x0 + h;
	if (f(x0) >= f(x1))
	{
		x0 = x1;
		k++;
		cout << k << ") x = " << x0 << "\t f(x) = " << f(x0) << endl;
		if ((a <= x0) && (x0 <= b))
			goto jump1;
	}
	if (fabs(h) <= e)
	{
		cout << endl << "Min x = " << x0 << "\t f(x) = " << f(x0) << endl;
	}
	else
	{
		x0 = x1;
		k++;
		cout << k << ") x = " << x0 << "\t f(x) = " << f(x0) << endl;
		h = -h / 4;
		goto jump1;
	}
}

//dichotomy method - cheack
void m3() {
	double a, b;
	int k = 1;
	cout << endl;
	cout << "Input - a \n>> ";
	cin >> a;
	cout << "Input - b \n>> ";
	cin >> b;
	double x, e = 0.1, d;
	d = 0, 1 * e;
	cout << k << ") x = " << (a + b) / 2 << "\t f(x) = " << f((a + b) / 2) << endl;
	do
	{
		x = (a + b) / 2;
		if (f(x - d) < f(x + d))
			a = x;
		else b = x;
		k++;
		cout << k << ") x = " << (a + b) / 2 << "\t f(x) = " << f((a + b) / 2) << endl;
	} while (fabs(b - a) > e);
	cout << endl << "Min x = " << (a + b) / 2 << "\t f(x) = " << f((a + b) / 2) << endl;
}

//golden section method
double m4() {
	double a, b;
	int k = 1;
	cout << endl;
	cout << "Input - a \n>> ";
	cin >> a;
	cout << "Input - b \n>> ";
	cin >> b;
	double x1, x2, e = 0.1, d;
	cout << k << ") x = " << (a + b) / 2 << "\t f(x) = " << f((a + b) / 2) << endl;
	d = (1 + sqrt(5)) / 2;
	jump1:
	x1 = b - (b - a) / d;
	cout << x1 << endl;
	x2 = a + (b - a) / d;
	cout << x2 << endl;
	if (f(x1) >= f(x2)) {
		a = x2;
		cout << "yes" << endl;
	}
	else
		b = x2;
	if (fabs(b - a) <= e)
	{
		cout << endl << "Min x = " << (a + b) / 2 << "\t f(x) = " << f((a + b) / 2) << endl;
		cin.get();
		return 0;
	}
	k++;
	cout << k << ") x = " << (a + b) / 2 << "\t f(x) = " << f((a + b) / 2) << endl;
	goto jump1;
}

//midpoint method - doesn't work
double m5() {
	double a, b;
	cout << endl;
	cout << "Input - a \n>> ";
	cin >> a;
	cout << "Input - b \n>> ";
	cin >> b;
	cout << endl;
	double x, e = 0.05;
	int k = 1;
jump2:
	x = (b + a) / 2;
	cout << k << ") x = " << x << "\t f(x) = " << f(x) << endl;
	if (abs(f1(x)) <= e)
	{
		cout << endl << "Min x = " << x << "\t f(x) = " << f(x) << endl;
		cin.get();
		return 0;
	}
	k++;
	if (f1(x) < 0) a = x; else b = x;
	goto jump2;
}

//chord method
double m6() {
	double a, b;
	cout << endl;
	cout << "Input - a \n>> ";
	cin >> a;
	cout << "Input - b \n>> ";
	cin >> b;
	cout << endl;
	double x, e = 0.05;
	int k = 1;
	if (f1(a) == 0)
	{
		x = a;
		cout << endl << "Min x = " << x << "\t f(x) = " << f(x) << endl;
		cin.get();
		return 0;
	}
	if (f1(b) == 0)
	{
		x = b;
		cout << endl << "Min x = " << x << "\t f(x) = " << f(x) << endl;
		cin.get();
		return 0;
	}
	if ((f1(a) > 0) && (f1(b) > 0))
	{
		x = a;
		cout << endl << "Min x = " << x << "\t f(x) = " << f(x) << endl;
		cin.get();
		return 0;
	}
	if ((f1(a) < 0) && (f1(b) < 0))
	{
		x = b;
		cout << endl << "Min x = " << x << "\t f(x) = " << f(x) << endl;
		cin.get();
		return 0;
	}
jump3:
	x = a - (f1(a) * (b - a)) / (f1(b) - f1(a));
	cout << k << ") x = " << x << "\t f(x) = " << f(x) << endl;
	if (abs(f1(x)) <= e)
	{
		cout << endl << "Min x = " << x << "\t f(x) = " << f(x) << endl;
		cin.get();
		return 0;
	}
	k++;
	if (f1(x) > 0) a = x; else b = x;
	goto jump3;
}

//newton method
double m7() {
	double a, b, x0;
	int k = 0;
	cout << endl;
	cout << "Input - a \n>> ";
	cin >> a;
	cout << "Input - b \n>> ";
	cin >> b;
	cout << "Input - x0 \n>> ";
	cin >> x0;
	cout << endl;
	double x1, e = 0.05;
	do
	{
		x1 = x0 - f1(x0) / f2(x0);
		k++;
		cout << k << ") x = " << x1 << "\t f(x) = " << f(x1) << endl;
		x0 = x1;
	} while (fabs(f1(x1)) > e);
	cout << "Min x = " << x1 << "\t f(x) = " << f(x1) << endl;
	cin.get();
	return 0;
}

int main()
{
	int ch = 0, n = 0;
	cout << "|__labmem_002_minimum_finder__|" << endl;
jump1:
	cout << "|Choose method:               |" << endl;
	cout << "|1 - Brute-force search       |" << endl;
	cout << "|2 - Bitwise search method    |" << endl;
	cout << "|3 - Dichotomy method         |" << endl;
	cout << "|4 - Golden section method    |" << endl;
	cout << "|5 - Midpoint method          |" << endl;
	cout << "|6 - Chord method             |" << endl;
	cout << "|7 - Newton method            |" << endl;
	cout << "|0 - Exit                     |" << endl;
	cout << "| >>> ";
	cin >> ch;
	switch (ch) {
	case 1:
		m1();
		break;
	case 2:
		m2();
		break;
	case 3:
		m3();
		break;
	case 4:
		m4();
		break;
	case 5:
		m5();
		break;
	case 6:
		m6();
		break;
	case 7:
		m7();
		break;
	case 0:
	{
		cout << endl << "|Made by MarconiNN" << endl;
		cin.get();
		cin.get();
		return 0;
	}	break;
	default:
		cout << "default value" << endl;
	}
	cout << endl;
	goto jump1;
	return 0;
}