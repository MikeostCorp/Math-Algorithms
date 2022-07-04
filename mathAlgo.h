#ifndef MATHALGO_H_
#define MATHALGO_H_

#include <iostream>
#include <cmath>

namespace mathAlgo{

	// Abs
	long double abs(long double number){
		if(number < 0){
			return -number;
		}
		else{
			return number;
		}
	}

	// Cotangent
	long double cot(long double number){
		return (cos(number) / sin(number));
	}

}

#endif