#pragma once
#include <math.h>

#define _pi 3.141592653589793 // число пи
#define _eil  2.7182818284590 // число 

namespace mathAlgo {

	// Abs
	long double abs(long double number) {
		if (number < 0) {
			return -number;
		}
		else {
			return number;
		}
	}

	// Cotangent
	long double cot(long double number) {
		return (cos(number) / sin(number));
	}

	// Acotangent
	long double acot(long double number) {
		return atan(1/number);
	}

	// factorial
	long double fac(long double number) {
		if (number == 0) return 1;
		else return number* fac(number - 1);
	}

	//probability
	long double prob(long double m, long double n) {
		return m/n;
	}

	// number of placements, the order in the condition is important
	long double nop(long double m, long double n) {
		return fac(n) / fac(n - m);
	}

	// combination C, order is NOT important
	long double comc(long double m, long double n) {
		return fac(n) / (fac(m)*fac(n-m));
	}

	// Defoult Bernoulli's formula
	long double bern(long double n, long double k, long double p){
		return comc(k, n) * pow(p,k) * pow(p,n-k);
	}

} // end namespace



/*

    GitHub: https://github.com/MikeostCorp/Math-Algorithms

*/
