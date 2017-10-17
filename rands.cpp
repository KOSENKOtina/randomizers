#include "rands.h"

static const long unsigned m = pow(5, 4) * 29 * 31;
long  c = 24 * 18;
long  a = 5 * 31 * 29 + 1;
static const unsigned long p = 8999;

void plot_gisto(double(*f)()) {
	int n = 12000;
	double arr[10];

	for (int i = 0; i < 10; ++i) { arr[i] = 0; }

	int t = 0;
	for (int i = 0; i < n; ++i) {
		t = int((double(f()) / m) * 10);
		++arr[t];
	}
	double sum = 0;
	for (double i = 0; i < 10; ++i) {
		cout << fixed;
		cout << '[' << setprecision(1) << i / 10 << ',' << setprecision(1) << (i + 1) / 10 << ']';
		cout << "\t\t" << setprecision(3) << arr[int(i)] / n << endl;
		sum += arr[int(i)] / n;
	}

	cout << sum << ' ';
}

void plot_gisto3(double(*f)()) {
	int n = 1000;
	double arr[60];

	for (int i = 0; i < 60; ++i) { arr[i] = 0; }

	double t = 0;
	for (int i = 0; i < n; ++i) { 
		t = f();
		if(t<=0)
		++arr[int((3 + t) * 10)];
		else
			++arr[30 + int(t * 10)];
	}

	for (int i = 0; i < 60; ++i) {
		cout << fixed;
		cout << '[' << setprecision(1) << -3 + i*0.1 << ',' << setprecision(1) << -3 + (i + 1)*0.1 << ']';
		cout << "\t\t" << setprecision(3) << arr[i] / n << endl;
	}
}


void plot_gisto100(double(*f)()) {
	int n = 12000;
	double arr[20];

	for (int i = 0; i < 20; ++i) { arr[i] = 0; }

	double t = 0;
	for (int i = 0; i < n; ++i) { 
		t = f()/5;
		arr[int(t)]++;
	}

	for (int i = 0; i < 20; ++i) {
		cout << fixed;
		cout << '[' << setprecision(1) <<  i * 5 << ',' << setprecision(1) << (i + 1)*5 << ']';
		cout << "\t\t" << setprecision(3) << arr[i] / n << endl;
	}
}

double rand_1() {                
	static long  x = 0;
	x = (a*x + c) % m;
	return x;
}

double rand_2() {
	long d = 5 * 29 * 31;
	static long  x = rand_1();
	x = (d * x * x + a * x + c) % m;
	return x;
}


double rand_3() {
	static long  x=rand_1();
	static long y;
	static long z;
		z = (x + y) % m;
		x = y;
		y = z;
		return z;
}

double rand_4() {  
	long a = 801, c = 1602;
	static unsigned long x = 1;
	static unsigned long x1 = 0;
	for (int i = 0; i < p; ++i) 
		if ((i*int(x)) % p == 1) {
			x1 = i;
			break;
		}
	x = (a*x1 + c) % m;
	return x;
}

double rand_5() {
	static unsigned long z;
		return z = int((rand_1()) - rand_2()) % m;
}

double rand_6() {  
	double x = 0;
	double sum = 0;
	for (int i = 0; i < 12; ++i) 
			sum += rand_1()/m;
	return x = sum - 6;
}

double rand_7() {  
	static bool isEven = false;
	static double x1 = 0, x2 = 0;
	if (isEven) {
		isEven = false;
		return double(x2);
	}
	double s = 0;
	double v1 = 0;
	double v2 = 0;
	double ux = 0, uy = 0;
	bool isReady = false;
	while (!isReady) {
		ux = rand_1() / m;
		uy = rand_1() / m;
		v1 = 2 * ux - 1;
		v2 = 2 * uy - 1;
		s = v1*v1 + v2*v2;
		if (s < 1) {
			x1 = v1*(sqrt(((-2)*log(s)) / s));
			x2 = v2*(sqrt(((-2)*log(s)) / s));
			isReady = true;
		}
	}
	isEven = true;
	return double(x1);
}

double rand_8() {  
	double ux = 0, uy = 0, z = 0;
	bool isReady = false;
	while (!isReady) {
		ux = rand_1() / m;
		uy = rand_1() / m;
		z = (sqrt(8 / (exp(1))))*((uy - 0.5) / ux);
		if ((z*z) <= (5 - (4 * pow((exp(1)), (1 / 4))*ux)))
			isReady = true;
		else if ((z*z) >= ((4 * pow((exp(1)), ((-1)*1.35)) / ux) + 1.4)) isReady = false;
			else if ((z*z) <= ((-4)*log(ux)))
				isReady = true;
	}

	return z;
}

double rand_9()
{
	double xn = 0, ux = 0;
	ux = rand_5() / m;
	xn = -1.75 * log(ux);
	return xn;
}

double rand_10()
{
	double xn = 0, y = 0, x = 0, a = 15; //разні параметри а -- разні гистограми
	bool isReady = false;
	while (!isReady) {
		xn = rand_1() / m;
		y = tan(3.1415*xn);
		x = sqrt(2 * a - 1)*y + a - 1;
		if (x > 0) {
			xn = rand_1() / m;
			if (xn <= (1 + y*y)*exp((a - 1)*log(x / (a - 1)) - sqrt(2 * a - 1)*y))
				isReady = true;
		}
	}
	return x;
}
