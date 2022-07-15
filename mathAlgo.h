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

		for (uint64_t i = 2; i < sqrt(number); i++) {
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
        	return number * fac(number - 1);
    	}

	// Probability
	long double prob(long double m, long double n) {
		return m / n;
	}

	// Number of placements, the order in the condition is important
    	uint64_t comA(uint64_t m, uint64_t n) {
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
		for (int i = 1; i <= n; i++)
			Integral = Integral + h * endLaplaceTheorem(a + h * (i - 0.5));
		return 1 / sqrt(2 * _pi) * Integral;
	}

	// Laplace integral theorem
	long double iLaplace(long double k1, long double k2, long double n, long double p) {
		return fiIntegral((k2 - n * p) / sqrt(n * p * (1 - p))) + fiIntegral((k1 - n * p) / sqrt(n * p * (1 - p)));
	}

	// Expected value
	template <typename typeArr1, typename typeArr2>
	long double exvalue(typeArr1 x[], typeArr2 p[], const int size) {
		long double m = 0;
		for (int i = 0; i < size; i++) {
			m += x[i] * p[i];
		}
		return m;
	}

	// Dispersion
	template <typename typeArr1, typename typeArr2>
	long double dispersion(typeArr1 x[], typeArr2 p[], const int size) {
		long double mx2 = 0;
		long double mx = pow(exvalue(x, p, size), 2);

		for (int i = 0; i < size; i++) {
			mx2 += x[i] * x[i] * p[i];
		}

		return mx2 - mx;
	}

	// Standard deviation from the variance of a random variable
	template <typename typeArr1, typename typeArr2>
	long double sdev(typeArr1 x[], typeArr2 p[], const int size) {
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

	// Buble parametr method, the third parameter is optional
	// True - sort in ascending order, false - sort in descending order
	template<typename T>
	void swap(T& val1, T& val2) {
		T temp = val1;
		val1 = val2;
		val2 = temp;
	}

	template <typename typeArr>
	typeArr* bsort(typeArr* arr, const int size, bool asc = true) {
		for (int i = 1; i < size; i++)
		{
			for (int j = 0; j < size - i; j++)
			{
				if (asc) {
					if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
				}
				else {
					if (arr[j] < arr[j + 1]) swap(arr[j + 1], arr[j]);
				}
			}
		}
		return arr;
	}

	//Average of the array
	template<typename typeArr>
	typeArr avgArr(typeArr* arr, const int size) {
		typeArr avg = 0;
		for (int i = 0; i < size; i++) avg += arr[i];
		return avg / size;

	}

	// Most repeated number in array (number fashion)
	// max - return mode, rmax - number of repetitions
	template <typename typeArr>
	typeArr modenum(typeArr* arr, const int size) {
		typeArr max = arr[0], cmax = 0, rmax = 0;
		for (int i = 0; i < size; i++) {
			if (cmax > rmax) {
				rmax = cmax;
				max = arr[i - 1];
			}
			cmax = 0;
			for (int j = i; j < size; j++)
				if (arr[j] == arr[i])
					cmax++;
		}
		return max;
	}

	// Median of numbers
	template<typename typeArr>
	typeArr median(typeArr* arr, const int size) {
		if (size % 2 == 1)
			return arr[size / 2];
		else return (arr[size / 2 - 1] + arr[size / 2]) / 2;
	}

	// Merge arrays(add)
	// arr0, arr1 - Arrays to be stacked (Be sure to be the same size!)
	// arr2 - Output array
	// size - size of two arrays (Must be the same)
	template <typename typeArr>
	typeArr* sumarr(typeArr* arr0, typeArr* arr1, typeArr* arr2, const int size) {
		for (int i = 0; i < size; i++) arr2[i] = arr1[i] + arr0[i];
		return arr2;
	}

	// Merge arrays (minus)
	// The element of the first array is subtracted 
	// by the element of the second array
	template <typename typeArr>
	typeArr* minarr(typeArr* arr0, typeArr* arr1, typeArr* arr2, const int size) {
		for (int i = 0; i < size; i++) arr2[i] = arr0[i] - arr1[i];
		return arr2;
	}

	// array multiplication
	template <typename typeArr>
	typeArr* mularr(typeArr* arr0, typeArr* arr1, typeArr* arr2, const int size) {
		for (int i = 0; i < size; i++) arr2[i] = arr0[i] * arr1[i];
		return arr2;
	}

	// array division
	// the element of the first array is divided 
	// by the elements of the second array
	template <typename typeArr>
	typeArr* divarr(typeArr* arr0, typeArr* arr1, typeArr* arr2, const int size) {
		for (int i = 0; i < size; i++) arr2[i] = arr0[i] / arr1[i];
		return arr2;
	}
	
	// Add a number to array elements
	// number - The number to be added to the elements of the array
	template <typename typeArr>
	typeArr* inplusarr(typeArr* arr, const int size, typeArr number) {
		for (int i = 0; i < size; i++) arr[i] += number;
		return arr;
	}

	// Subtract a number from the array elements
    // number - the number to be subtracted from the array elements
	template <typename typeArr>
	typeArr* inminarr(typeArr* arr, const int size, typeArr number) {
		for (int i = 0; i < size; i++) arr[i] -= number;
		return arr;
	}

	// Multiply a number by an array element
    // number - the number by which to multiply the elements of the array
	template <typename typeArr>
	typeArr* inmularr(typeArr* arr, const int size, typeArr number) {
		for (int i = 0; i < size; i++) arr[i] *= number;
		return arr;
	}

	// Divide the array numbers by the given number 
	// number - the number by which the array elements will be divided
	template <typename typeArr>
	typeArr* indivarr(typeArr* arr, const int size, typeArr number) {
		for (int i = 0; i < size; i++) arr[i] /= number;
		return arr;
	}

	// Raising an array to a given power
	template <typename typeArr>
	typeArr* powarr(typeArr* arr, const int size, typeArr gpow) {
		for (int i = 0; i < size; i++) arr[i] = pow(arr[i],gpow);
		return arr;
	}

	//abs array
	template <typename typeArr>
	typeArr* absarr(typeArr* arr, const int size) {
		for (int i = 0; i < size; i++) arr[i] = abs(arr[i]);
		return arr;
	}

	// Swap signs before numbers in an array
	template <typename typeArr>
	typeArr* swaparr(typeArr* arr, const int size) {
		for (int i = 0; i < size; i++) {
			if (arr[i] < 0) arr[i] = abs(arr[i]);
			else {
				arr[i] = -(arr[i]);
			}
		}
		return arr;
	}

	// random nums array
	template <typename typeArr>
	typeArr* randarr(typeArr* arr, const int size) {
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % 100 - 50;
		}
		return arr;
	}

	// union arrays (into one big)
	// For correct operation, use an array whose 
	// size is twice the size of one of the original
	template <typename typeArr>
	typeArr* uniarr(typeArr* arr0, typeArr* arr1, typeArr* arr2, const int size) {
		for (int i = 0; i < size; i++) {
			arr2[i] = arr0[i];
			arr2[size + i] = arr1[i];
		}
		return arr2;
	}

	// Combine matrices (plus)
	// mat0 - First matrix
	// mat1 - Second matrix
	// mat2 - The matrix in which the result will be written
	// isize - First parameter of matrix size
	// jsize - Second parameter of matrix size
	// IMPORTANT! Matrices must be exactly the same size
	template <typename typeArr>
	typeArr* summat(typeArr *mat0, typeArr *mat1, typeArr *mat2, const int isize, const int jsize) {
		for (int i = 0; i < isize; i++) {
			for (int j = 0; j < jsize; j++) {
				*(*(mat2 + i) + j) = *(*(mat0 + i) + j) + *(*(mat1 + i) + j);
			}
		}
		return mat2;
	}

	// Subtract matrices (minus)
	// The element of the first matrix is subtracted 
	// by the element of the second matrix
	template <typename typeArr>
	typeArr* minmat(typeArr* mat0, typeArr* mat1, typeArr* mat2, const int isize, const int jsize) {
		for (int i = 0; i < isize; i++) {
			for (int j = 0; j < jsize; j++) {
				*(*(mat2 + i) + j) = *(*(mat0 + i) + j) - *(*(mat1 + i) + j);
			}
		}
		return mat2;
	}

	// Matrix multiplication
	template <typename typeArr>
	typeArr* mulmat(typeArr* mat0, typeArr* mat1, typeArr* mat2, const int isize, const int jsize) {
		for (int i = 0; i < isize; i++) {
			for (int j = 0; j < jsize; j++) {
				*(*(mat2 + i) + j) = *(*(mat0 + i) + j) * *(*(mat1 + i) + j);
			}
		}
		return mat2;
	}

	// Matrix division
	template <typename typeArr>
	typeArr* divmat(typeArr* mat0, typeArr* mat1, typeArr* mat2, const int isize, const int jsize) {
		for (int i = 0; i < isize; i++) {
			for (int j = 0; j < jsize; j++) {
				*(*(mat2 + i) + j) = *(*(mat0 + i) + j) / *(*(mat1 + i) + j);
			}
		}
		return mat2;
	}

	// Adds a given number to all elements of a matrix
	template <typename typeArr>
	typeArr* inplusmat(typeArr* mat, const int isize, const int jsize, typename number) {
		for (int i = 0; i < isize; i++) {
			for (int j = 0; j < jsize; j++) {
				*(*(mat + i) + j) += number;
			}
		}
		return mat;
	}

	// Subtracts a given number from all matrix elements
	template <typename typeArr>
	typeArr* inmiusmat(typeArr* mat, const int isize, const int jsize, typename number) {
		for (int i = 0; i < isize; i++) {
			for (int j = 0; j < jsize; j++) {
				*(*(mat + i) + j) -= number;
			}
		}
		return mat;
	}

	// Multiplies the given number by all matrix elements
	template <typename typeArr>
	typeArr* inmultmat(typeArr* mat, const int isize, const int jsize, typename number) {
		for (int i = 0; i < isize; i++) {
			for (int j = 0; j < jsize; j++) {
				*(*(mat + i) + j) *= number;
			}
		}
		return mat;
	}

	// Divides the elements of a matrix by a given number.
	template <typename typeArr>
	typeArr* indivmat(typeArr* mat, const int isize, const int jsize, typename number) {
		for (int i = 0; i < isize; i++) {
			for (int j = 0; j < jsize; j++) {
				*(*(mat + i) + j) /= number;
			}
		}
		return mat;
	}

	// Raise a matrix to a given power
	template <typename typeArr>
	typeArr* powmat(typeArr* mat, const int isize, const int jsize, typename gpow) {
		for (int i = 0; i < isize; i++) {
			for (int j = 0; j < jsize; j++) {
				*(*(mat + i) + j) = pow(*(*(mat + i) + j),gpow);
			}
		}
		return mat;
	}

	// abs matrix
	template <typename typeArr>
	typeArr* powmat(typeArr* mat, const int isize, const int jsize) {
		for (int i = 0; i < isize; i++) {
			for (int j = 0; j < jsize; j++) {
				*(*(mat + i) + j) = abs(*(*(mat + i) + j));
			}
		}
		return mat;
	}

	// Swap signs before numbers in matrix
	template <typename typeArr>
	typeArr* swapmat(typeArr* mat, const int isize, const int jsize) {
		for (int i = 0; i < isize; i++) {
			for (int j = 0; j < jsize; j++) {
				if (*(*(mat + i) + j) < 0) {
					*(*(mat + i) + j) = abs(*(*(mat + i) + j));
				}
				else {
					*(*(mat + i) + j) = -*(*(mat + i) + j);
				}
			}
		}
		return mat;
	}

	// Random numbers in matrix
	template <typename typeArr>
	typeArr* randmat(typeArr* mat, const int isize, const int jsize) {
		for (int i = 0; i < isize; i++) {
			for (int j = 0; j < jsize; j++) {
				*(*(mat + i) + j) = rand()% 100 - 10;
			}
		}
		return mat;
	}


} // end namespace


/*
	GitHub: https://github.com/MikeostCorp/Math-Algorithms
*/
