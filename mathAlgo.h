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
    bool isPrime(const int64_t& number) {
        if (number <= 1) return false;

        for (int64_t i = 2; i < sqrt(number); i++) {
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
    long double cot(const long double number) {
        return (cos(number) / sin(number));
    }

    // Acotangent
    long double acot(const long double number) {
        return atan(1 / number);
    }

    // Finding the length of a line segment
    long double lengthOfLine(const long double x1, const long double x2,
                             const long double y1, const long double y2,
                             const long double z1 = 0, const long double z2 = 0) {
        return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
    }

    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    //
    // Formulas from probability theory and combinatorics
    //
    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    // Factorial
    int64_t fac(const int64_t number) {
        if (number <= 1) return 1;
        return number * fac(number - 1);
    }

    // Probability
    long double prob(const long double m, const long double n) {
        return m / n;
    }

    // Number of placements, the order in the condition is important
    int64_t comA(const int64_t m, const int64_t n) {
        return fac(n) / fac(n - m);
    }

    // Number of placements, order is NOT important
    int64_t comC(const int64_t m, const int64_t n) {
        return fac(n) / (fac(m) * fac(n - m));
    }

    // Default Bernoulli's formula
    long double bern(const int64_t n, const int64_t k, const long double p) {
        return comC(k, n) * pow(p, k) * pow(p, n - k);
    }

    //phi number for local Laplace theorem
    long double fiLocal(const long double x) {
        return 1 / sqrt(2 * _pi) * exp(-(x * x) / 2);
    }

    //Local Laplace theorem
    long double lLaplace(const long double n, const long double k, const long double p) {
        return fiLocal((k - n * p) / sqrt(n * p * (1 - p))) / sqrt(n * p * (1 - p));
    }

    //End part of the function for the number phi
    double endLaplaceTheorem(const double x) {
        return exp(-((x * x) / 2));
    }

    //Phi number for local Laplace theorem
    long double fiIntegral(const long double x) {
        double Integral = 0;
        double a = 0, b = fabs(x);
        double h = 0.01;
        double n = (b - a) / h;
        
        for (size_t i = 0; i < n; i++)
            Integral = Integral + h * endLaplaceTheorem(a + h * (i - 0.5));
        return 1 / sqrt(2 * _pi) * Integral;
    }

    // Laplace integral theorem
    long double iLaplace(const long double k1, const long double k2, const long double n, const long double p) {
        return fiIntegral((k2 - n * p) / sqrt(n * p * (1 - p))) + fiIntegral((k1 - n * p) / sqrt(n * p * (1 - p)));
    }

    // Expected value
    template <typename typeArr1, typename typeArr2>
    long double exValue(typeArr1* x, typeArr2* p, const int size) {
        long double m = 0;
        for (size_t i = 0; i < size; i++) {
            m += x[i] * p[i];
        }
        return m;
    }

    // Dispersion
    template <typename typeArr1, typename typeArr2>
    long double dispersion(typeArr1* x, typeArr2* p, const int size) {
        long double mx2 = 0;
        long double mx = pow(exValue(x, p, size), 2);

        for (size_t i = 0; i < size; i++) {
            mx2 += x[i] * x[i] * p[i];
        }

        return mx2 - mx;
    }

    // Standard deviation from the variance of a random variable
    template <typename typeArr1, typename typeArr2>
    long double sDev(typeArr1* x, typeArr2* p, const int size) {
        return sqrt(dispersion(x, p, size));
    }

    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    //
    // Arithmetic and geometric progression
    //
    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    // n-th term of an arithmetic sequence
    long double nTermOfASequence(const long double a1, const long double d, const int64_t n) {
        return a1 + (n - 1) * d;
    }

    // n-th term of a geometric sequence
    long double nTermOfGSequence(const long double a, const long double q, const int64_t n) {
        return a * pow(q, n - 1);
    }

    // The sum of an arithmetic progression
    long double sumAprogression(const long double a1, const long double an, const int64_t n) {
        return (a1 + an) * n / 2;
    }

    // The sum of a geometric progression
    long double sumGprogression(const long double a1, const long double an, const long double q) {
        return (a1 - an * q) / (1 - q);
    }


    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    //
    // Recursion
    //
    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


    // Fibonacci number
    int64_t fibonacci(const int64_t number) {
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
    long double halfDivisionMethod(const F func, long double a, long double b, const long double e = 0.001) {
        long double x = a + (b - a) / 2;
        
        while (fabs(b - a) > e) {
            if (func(a) * func(x) <= 0) {
                b = x;
            }
            else {
                a = x;
            }
            x = a + (b - a) / 2;
        }
        return x;
    }

    // Secant method
    template<typename F>
    long double secantMethod(const F func, long double x0, long double x1, const long double e = 0.001) {
        while (fabs(x1 - x0) > e) {
            long double tmp = x1;
            x1 = x1 - (((x1 - x0) * func(x1)) / (func(x1) - func(x0)));
            x0 = tmp;
        }
        return x1;
    }

    // Parabola method
    template<typename F>
    long double parabolaMethod(const F func, long double a, long double b, const long double e = 0.001) {
        long double x = 0, c = 0, A = 0, B = 0, C = 0, x1 = 0, x2 = 0;

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

            if (func(b) * func(x) < 0) a = x;

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
    typeArr aMin(typeArr* arr, const int size) {
        typeArr minimum = arr[0];
        for (size_t i = 0; i < size; i++) {
            if (arr[i] < minimum) {
                minimum = arr[i];
            }
        }
        return minimum;
    }

    // Maximum array value
    template <typename typeArr>
    typeArr aMax(typeArr* arr, const int size) {
        typeArr maximum = arr[0];
        for (size_t i = 0; i < size; i++) {
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
    typeArr* bSort(typeArr* arr, const int size, bool asc = true) {
        for (size_t i = 0; i < size - 1; i++)
        {
            for (size_t j = 0; j < size - i - 1; j++)
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
        for (size_t i = 0; i < size; i++) avg += arr[i];
        return avg / size;

    }

    // Most repeated number in array (number fashion)
    // max - return mode, rmax - number of repetitions
    template <typename typeArr>
    typeArr modenum(typeArr* arr, const int size) {
        typeArr max = arr[0], cmax = 0, rmax = 0;
        for (size_t i = 0; i < size; i++) {
            if (cmax > rmax) {
                rmax = cmax;
                max = arr[i - 1];
            }
            cmax = 0;
            for (size_t j = i; j < size; j++)
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
        return (arr[size / 2 - 1] + arr[size / 2]) / 2;
    }

    // Merge arrays(add)
    // arr0, arr1 - Arrays to be stacked (Be sure to be the same size!)
    // arr2 - Output array
    // size - size of two arrays (Must be the same)
    template <typename typeArr>
    typeArr* sumArr(typeArr* arr0, typeArr* arr1, typeArr* arr2, const int size) {
        for (size_t i = 0; i < size; i++) arr2[i] = arr1[i] + arr0[i];
        return arr2;
    }

    // Merge arrays (minus)
    // The element of the first array is subtracted
    // by the element of the second array
    template <typename typeArr>
    typeArr* minArr(typeArr* arr0, typeArr* arr1, typeArr* arr2, const int size) {
        for (size_t i = 0; i < size; i++) arr2[i] = arr0[i] - arr1[i];
        return arr2;
    }

    // array multiplication
    template <typename typeArr>
    typeArr* mulArr(typeArr* arr0, typeArr* arr1, typeArr* arr2, const int size) {
        for (size_t i = 0; i < size; i++) arr2[i] = arr0[i] * arr1[i];
        return arr2;
    }

    // array division
    // the element of the first array is divided
    // by the elements of the second array
    template <typename typeArr>
    typeArr* divArr(typeArr* arr0, typeArr* arr1, typeArr* arr2, const int size) {
        for (size_t i = 0; i < size; i++) arr2[i] = arr0[i] / arr1[i];
        return arr2;
    }

    // Add a number to array elements
    // number - The number to be added to the elements of the array
    template <typename typeArr, typename typeNum>
    typeArr* inPlusArr(typeArr* arr, const int size, const typeNum& number) {
        for (size_t i = 0; i < size; i++) arr[i] += number;
        return arr;
    }

    // Subtract a number from the array elements
    // number - the number to be subtracted from the array elements
template <typename typeArr, typename typeNum>
    typeArr* inMinArr(typeArr* arr, const int size, const typeNum& number) {
        for (size_t i = 0; i < size; i++) arr[i] -= number;
        return arr;
    }

    // Multiply a number by an array element
    // number - the number by which to multiply the elements of the array
    template <typename typeArr, typename typeNum>
    typeArr* inMulArr(typeArr* arr, const int size, const typeNum& number) {
        for (size_t i = 0; i < size; i++) arr[i] *= number;
        return arr;
    }

    // Divide the array numbers by the given number
    // number - the number by which the array elements will be divided
    template <typename typeArr, typename typeNum>
    typeArr* inDivArr(typeArr* arr, const int size, const typeNum& number) {
        for (size_t i = 0; i < size; i++) arr[i] /= number;
        return arr;
    }

    // Raising an array to a given power
    template <typename typeArr, typename typeNum>
    typeArr* powArr(typeArr* arr, const int size, const typeNum& gpow) {
        for (size_t i = 0; i < size; i++) arr[i] = pow(arr[i], gpow);
        return arr;
    }

    //abs array
    template <typename typeArr>
    typeArr* absArr(typeArr* arr, const int size) {
        for (size_t i = 0; i < size; i++) arr[i] = abs(arr[i]);
        return arr;
    }

    // Swap signs before numbers in an array
    template <typename typeArr>
    typeArr* swapArr(typeArr* arr, const int size) {
        for (size_t i = 0; i < size; i++) {
            arr[i] *= -1;
        }
        return arr;
    }

    // random nums array
    template <typename typeArr>
    typeArr* randArr(typeArr* arr, const int size) {
        for (size_t i = 0; i < size; i++) {
            arr[i] = rand() % 100 - 50;
        }
        return arr;
    }

    // union arrays (into one big)
    // For correct operation, use an array whose
    // size is twice the size of one of the original
    template <typename typeArr>
    typeArr* uniArr(typeArr* arr0, typeArr* arr1, typeArr* arr2, const int size) {
        for (size_t i = 0; i < size; i++) {
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
    template <typename typeMat>
    typeMat* sumMat(typeMat* mat0, typeMat* mat1, typeMat* mat2, const int isize, const int jsize) {
        for (size_t i = 0; i < isize; i++) {
            for (size_t j = 0; j < jsize; j++) {
                *(*(mat2 + i) + j) = *(*(mat0 + i) + j) + *(*(mat1 + i) + j);
            }
        }
        return mat2;
    }

    // Subtract matrices (minus)
    // The element of the first matrix is subtracted
    // by the element of the second matrix
    template <typename typeMat>
    typeMat* minMat(typeMat* mat0, typeMat* mat1, typeMat* mat2, const int isize, const int jsize) {
        for (size_t i = 0; i < isize; i++) {
            for (size_t j = 0; j < jsize; j++) {
                *(*(mat2 + i) + j) = *(*(mat0 + i) + j) - *(*(mat1 + i) + j);
            }
        }
        return mat2;
    }

    // Matrix multiplication
    template <typename typeMat>
    typeMat* mulMat(typeMat* mat0, typeMat* mat1, typeMat* mat2, const int isize, const int jsize) {
        for (size_t i = 0; i < isize; i++) {
            for (size_t j = 0; j < jsize; j++) {
                *(*(mat2 + i) + j) = *(*(mat0 + i) + j) * *(*(mat1 + i) + j);
            }
        }
        return mat2;
    }

    // Matrix division
    template <typename typeMat>
    typeMat* divMat(typeMat* mat0, typeMat* mat1, typeMat* mat2, const int isize, const int jsize) {
        for (size_t i = 0; i < isize; i++) {
            for (size_t j = 0; j < jsize; j++) {
                *(*(mat2 + i) + j) = *(*(mat0 + i) + j) / *(*(mat1 + i) + j);
            }
        }
        return mat2;
    }

    // Adds a given number to all elements of a matrix
    template <typename typeMat, typename typeNum>
    typeMat* inPlusMat(typeMat* mat, const int isize, const int jsize, const typeNum& number) {
        for (size_t i = 0; i < isize; i++) {
            for (size_t j = 0; j < jsize; j++) {
                *(*(mat + i) + j) += number;
            }
        }
        return mat;
    }

    // Subtracts a given number from all matrix elements
    template <typename typeMat, typename typeNum>
    typeMat* inMinMat(typeMat* mat, const int isize, const int jsize, const typeNum& number) {
        for (size_t i = 0; i < isize; i++) {
            for (size_t j = 0; j < jsize; j++) {
                *(*(mat + i) + j) -= number;
            }
        }
        return mat;
    }

    // Multiplies the given number by all matrix elements
    template <typename typeMat, typename typeNum>
    typeMat* inMulMat(typeMat* mat, const int isize, const int jsize, const typeNum& number) {
        for (size_t i = 0; i < isize; i++) {
            for (size_t j = 0; j < jsize; j++) {
                *(*(mat + i) + j) *= number;
            }
        }
        return mat;
    }

    // Divides the elements of a matrix by a given number.
    template <typename typeMat, typename typeNum>
    typeMat* inDivMat(typeMat* mat, const int isize, const int jsize, const typeNum& number) {
        for (size_t i = 0; i < isize; i++) {
            for (size_t j = 0; j < jsize; j++) {
                *(*(mat + i) + j) /= number;
            }
        }
        return mat;
    }

    // Raise a matrix to a given power
    template <typename typeMat, typename typeNum>
    typeMat* powMat(typeMat* mat, const int isize, const int jsize, const typeNum& gpow) {
        for (size_t i = 0; i < isize; i++) {
            for (size_t j = 0; j < jsize; j++) {
                *(*(mat + i) + j) = pow(*(*(mat + i) + j), gpow);
            }
        }
        return mat;
    }

    // abs matrix
    template <typename typeMat>
    typeMat* absMat(typeMat* mat, const int isize, const int jsize) {
        for (size_t i = 0; i < isize; i++) {
            for (size_t j = 0; j < jsize; j++) {
                *(*(mat + i) + j) = abs(*(*(mat + i) + j));
            }
        }
        return mat;
    }

    // Swap signs before numbers in matrix
    template <typename typeMat>
    typeMat* swapMat(typeMat* mat, const int isize, const int jsize) {
        for (size_t i = 0; i < isize; i++) {
            for (size_t j = 0; j < jsize; j++) {
                *(*(mat + i) + j) *= -1;
            }
        }
        return mat;
    }

    // Random numbers in matrix
    template <typename typeMat>
    typeMat* randMat(typeMat* mat, const int isize, const int jsize) {
        for (size_t i = 0; i < isize; i++) {
            for (size_t j = 0; j < jsize; j++) {
                *(*(mat + i) + j) = rand() % 100 - 10;
            }
        }
        return mat;
    }


} // end namespace


/*
    GitHub: https://github.com/MikeostCorp/Math-Algorithms
*/
