#pragma once

#include <math.h>

#define _pi 3.141592653589793 // number PI
#define _e  2.7182818284590   // number E

namespace mathAlgo {

	// Abs
	long double abs(long double number) {
		if (number < 0) return -number;
		return number;
	}

	// Cotangent
	long double cot(long double number) {
		return (cos(number) / sin(number));
	}

	// Acotangent
	long double acot(long double number) {
		return atan(1 / number);
	}

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
	uint64_t nop(uint64_t n, uint64_t m) {
		return fac(n) / fac(n - m);
	}

	// Combination C, order is NOT important
	uint64_t comС(uint64_t n, uint64_t m) {
		return fac(n) / (fac(m) * fac(n - m));
	}

	// Default Bernoulli's formula
	long double bern(uint64_t n, uint64_t k, long double p){
		return comС(n, k) * pow(p, k) * pow(p, n - k);
	}

	// Finding the length of a line segment
	long double lengthOfLine(long double x1, long double x2, long double y1, long double y2, long double z1 = 0, long double z2 = 0){
		return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
	}

	// Arithmetic progression, n-th term of sequence
	long double nTermOfSequence(long double a1, long double d, uint64_t n){
		return a1 + (n - 1) * d;
	}

} // end namespace



/*

    GitHub: https://github.com/MikeostCorp/Math-Algorithms

*/
