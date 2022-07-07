#pragma once

#include <math.h>

#define _pi 3.1415926535897932384626433832795028841971693993751058209749 // number PI
#define _e  2.7182818284590452353602874713526624977572470936999595749669 // number e

namespace mathAlgo {

	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//
	// Ordinary arithmetic
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	// Check prime number
	bool isPrime(uint64_t number) {
		if (number <= 1) return false;

		for (uint64_t i = 2; i < sqrt(number); ++i) {
			if (number % i == 0) return false;
		}

		return true;
	}

	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//
	// Geometry
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	// Cotangent
	long double cot(long double number) {
		return (cos(number) / sin(number));
	}

	// Acotangent
	long double acot(long double number) {
		return atan(1 / number);
	}

	// Finding the length of a line segment
	long double lengthOfLine(long double x1, long double x2, long double y1, long double y2, long double z1 = 0, long double z2 = 0) {
		return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
	}

	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//
	// Formulas from probability theory and combinatorics
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	// Factorial
	uint64_t fac(uint64_t number) {
		if (number <= 1) return 1;
		else return number * fac(number - 1);
	}

	// Probability
	long double prob(long double m, long double n) {
		return m / n;
	}

	// Number of placements, the order in the condition is important
	uint64_t comA(uint64_t n, uint64_t m) {
		return fac(n) / fac(n - m);
	}

	// Number of placements, order is NOT important
	uint64_t comС(uint64_t n, uint64_t m) {
		return fac(n) / (fac(m) * fac(n - m));
	}

	// Default Bernoulli's formula
	long double bern(uint64_t n, uint64_t k, long double p) {
		return comС(n, k) * pow(p, k) * pow(p, n - k);
	}

	//phi number for local Laplace theorem
	long double fiLocal(long double x) {
		return 1 / sqrt(2 * _pi) * exp(-(x * x) / 2);
	}

	//Local Laplace theorem
	long double lLaplace(long double p, long double n, long double k) {
		return fiLocal((k - n * p) / sqrt(n * p * (1 - p))) / sqrt(n * p * (1 - p));
	}

	//End part of the function for the number phi
	double endLaplaceTheorem(double x) {
		return exp(-((x * x) / 2));
	}

	//Phi number for local Laplace theorem
	long double fiIntegral(long double x) {
		double Integral = 0;
		double a = 0.0, b = fabs(x);
		double h = 0.01;
		double n = (b - a) / h;
		for (int i = 1; i <= n; ++i)
			Integral = Integral + h * endLaplaceTheorem(a + h * (i - 0.5));
		return 1 / sqrt(2 * _pi) * Integral;
	}

	// Laplace integral theorem
	long double iLaplace(long double k1, long double k2, long double n, long double p) {
		return fiIntegral((k2 - n * p) / sqrt(n * p * (1 - p))) + fiIntegral((k1 - n * p) / sqrt(n * p * (1 - p)));
	}

	// Expected value
	long double exvalue(double x[], double p[], const int size) {
		long double _m = 0;
		for (int i = 0; i < size; ++i) {
			_m += x[i] * p[i];
		}
		return _m;
	}

	// Dispersion
	long double dispersion(double x[], double p[], const int size) {
		long double _mx2 = 0;
		long double _mx = pow(exvalue(x, p, size), 2);

		for (int i = 0; i < size; i++) {
			_mx2 += x[i] * x[i] * p[i];
		}

		return _mx2 - _mx;
	}

	// Standard deviation from the variance of a random variable
	long double sdev(double x[], double p[], const int size) {
		return sqrt(dispersion(x, p, size));
	}

	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//
	// Arithmetic and geometric progression
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	// n-th term of an arithmetic sequence
	long double nTermOfASequence(long double a1, long double d, uint64_t n) {
		return a1 + (n - 1) * d;
	}

	// n-th term of a geometric sequence
	long double nTermOfGSequence(long double a, long double q, uint64_t n) {
		return a * pow(q, n - 1);
	}

	// The sum of an arithmetic progression
	long double sumAprogression(long double a1, long double an, uint64_t n) {
		return (a1 + an) * n / 2;
	}

	// The sum of a geometric progression
	long double sumGprogression(long double a1, long double an, long double q) {
		return (a1 - an * q) / (1 - q);
	}


	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//
	// Recursion
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


	// Fibonacci number
	uint64_t fibonacci(uint64_t number) {
		if (number == 0) return 0;
		if (number == 1) return 1;

		return fibonacci(number - 1) + fibonacci(number - 2);
	}


	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//
	// Numerical methods for solving nonlinear equations
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


	// Half-Division method
	template<typename F>
	long double halfDivisionMethod(F func, long double a, long double b, long double e = 0.001) {
		long double x;

		x = (a + b) / 2;
		while (fabs(b - a) > e) {
			if (func(a) * func(x) <= 0) {
				b = x;
			}
			else {
				a = x;
			}
			x = (a + b) / 2;
		}
		return x;
	}

	// Secant method
	template<typename F>
	long double secantMethod(F func, long double x0, long double x1, long double e = 0.001) {
		while (fabs(x1 - x0) > e) {
			long double tmp = x1;
			x1 = x1 - (((x1 - x0) * func(x1)) / (func(x1) - func(x0)));
			x0 = tmp;
		}

		return x1;
	}

	// Parabola method
	template<typename F>
	long double parabolaMethod(F func, long double a, long double b, long double e = 0.001) {
		long double x, c, A, B, C, x1, x2;

		while (fabs(a - b) > e) {
			c = (a + b) / 2;

			C = func(a);

			B = ((func(c) - func(a)) / (c - a)) + ((((func(b) - func(c)) / (b - c)) - ((func(c) - func(a)) / (c - a))) / (b - a)) * (a - c);

			A = (((func(b) - func(c)) / (b - c)) - ((func(c) - func(a)) / (c - a))) / (b - a);

			x1 = a - ((2 * C) / (B + sqrt(pow(B, 2) - 4 * A * C)));

			x2 = a - ((2 * C) / (B - sqrt(pow(B, 2) - 4 * A * C)));

			if ((a <= x1 && x1 <= b) || (a >= x1 && x1 >= b)) x = x1;

			if ((a <= x2 && x2 <= b) || (a >= x2 && x2 >= b)) x = x2;

			if (func(a) * func(x) < 0) b = x;

			if (func(x) * func(b) < 0) a = x;

		}

		return x;
	}


	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//
	// Array && matrix
	//
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	// Array minimum value
	template <typename typeArr>
	typeArr amin(typeArr* arr, const int size) {
		typeArr minimum = arr[0];
		for (int i = 0; i < size; i++) {
			if (arr[i] < minimum) {
				minimum = arr[i];
			}
		}
		return minimum;
	}

	// Maximum array value
	template <typename typeArr>
	typeArr amax(typeArr* arr, const int size) {
		typeArr maximum = arr[0];
		for (int i = 0; i < size; i++) {
			if (arr[i] > maximum) {
				maximum = arr[i];
			}
		}
		return maximum;
	}
} // end namespace


/*
	GitHub: https://github.com/MikeostCorp/Math-Algorithms
*/
