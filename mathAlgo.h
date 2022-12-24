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
    bool isPrime(const int64_t& number);

    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    //
    // Geometry
    //
    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    // Cotangent
    long double cot(const long double number);

    // Acotangent
    long double acot(const long double number);

    // Finding the length of a line segment
    long double lengthOfLine(const long double x1, const long double x2,
                             const long double y1, const long double y2,
                             const long double z1 = 0, const long double z2 = 0);

    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    //
    // Formulas from probability theory and combinatorics
    //
    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    // Factorial
    int64_t fac(const int64_t number);
    // Probability
    long double prob(const long double m, const long double n);

    // Number of placements, the order in the condition is important
    int64_t comA(const int64_t m, const int64_t n);

    // Number of placements, order is NOT important
    int64_t comС(const int64_t m, const int64_t n);

    // Default Bernoulli's formula
    long double bern(const int64_t n, const int64_t k, const long double p);

    //phi number for local Laplace theorem
    long double fiLocal(const long double x);

    //Local Laplace theorem
    long double lLaplace(const long double n, const long double k, const long double p);

    //End part of the function for the number phi
    double endLaplaceTheorem(const double x);

    //Phi number for local Laplace theorem
    long double fiIntegral(const long double x);

    // Laplace integral theorem
    long double iLaplace(const long double k1, const long double k2, const long double n, const long double p);
    // Expected value
    template <typename typeArr1, typename typeArr2>
    long double exValue(typeArr1* x, typeArr2* p, const int size);

    // Dispersion
    template <typename typeArr1, typename typeArr2>
    long double dispersion(typeArr1* x, typeArr2* p, const int size);

    // Standard deviation from the variance of a random variable
    template <typename typeArr1, typename typeArr2>
    long double sDev(typeArr1* x, typeArr2* p, const int size);
    
    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    //
    // Arithmetic and geometric progression
    //
    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    // n-th term of an arithmetic sequence
    long double nTermOfASequence(const long double a1, const long double d, const int64_t n);

    // n-th term of a geometric sequence
    long double nTermOfGSequence(const long double a, const long double q, const int64_t n);

    // The sum of an arithmetic progression
    long double sumAprogression(const long double a1, const long double an, const int64_t n);

    // The sum of a geometric progression
    long double sumGprogression(const long double a1, const long double an, const long double q);

    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    //
    // Recursion
    //
    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    // Fibonacci number
    int64_t fibonacci(const int64_t number);

    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    //
    // Numerical methods for solving nonlinear equations
    //
    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    // Half-Division method
    template<typename F>
    long double halfDivisionMethod(const F func, long double a, long double b, const long double e = 0.001);

    // Secant method
    template<typename F>
    long double secantMethod(const F func, long double x0, long double x1, const long double e = 0.001);

    // Parabola method
    template<typename F>
    long double parabolaMethod(const F func, long double a, long double b, const long double e = 0.001);

    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    //
    // Array && matrix
    //
    //-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    // Array minimum value
    template <typename typeArr>
    typeArr aMin(typeArr* arr, const int size);

    // Maximum array value
    template <typename typeArr>
    typeArr aMax(typeArr* arr, const int size);

    // Buble parametr method, the third parameter is optional
    // True - sort in ascending order, false - sort in descending order
    template<typename T>
    void swap(T& val1, T& val2);

    template <typename typeArr>
    typeArr* bSort(typeArr* arr, const int size, bool asc = true);

    //Average of the array
    template<typename typeArr>
    typeArr avgArr(typeArr* arr, const int size);

    // Most repeated number in array (number fashion)
    // max - return mode, rmax - number of repetitions
    template <typename typeArr>
    typeArr modenum(typeArr* arr, const int size);

    // Median of numbers
    template<typename typeArr>
    typeArr median(typeArr* arr, const int size);
    // Merge arrays(add)
    // arr0, arr1 - Arrays to be stacked (Be sure to be the same size!)
    // arr2 - Output array
    // size - size of two arrays (Must be the same)
    template <typename typeArr>
    typeArr* sumArr(typeArr* arr0, typeArr* arr1, typeArr* arr2, const int size);

    // Merge arrays (minus)
    // The element of the first array is subtracted
    // by the element of the second array
    template <typename typeArr>
    typeArr* minArr(typeArr* arr0, typeArr* arr1, typeArr* arr2, const int size);

    // array multiplication
    template <typename typeArr>
    typeArr* mulArr(typeArr* arr0, typeArr* arr1, typeArr* arr2, const int size);

    // array division
    // the element of the first array is divided
    // by the elements of the second array
    template <typename typeArr>
    typeArr* divArr(typeArr* arr0, typeArr* arr1, typeArr* arr2, const int size);

    // Add a number to array elements
    // number - The number to be added to the elements of the array
    template <typename typeArr, typename typeNum>
    typeArr* inPlusArr(typeArr* arr, const int size, const typeNum& number);

    // Subtract a number from the array elements
    // number - the number to be subtracted from the array elements
    template <typename typeArr, typename typeNum>
    typeArr* inMinArr(typeArr* arr, const int size, const typeNum& number);

    // Multiply a number by an array element
    // number - the number by which to multiply the elements of the array
    template <typename typeArr, typename typeNum>
    typeArr* inMulArr(typeArr* arr, const int size, const typeNum& number);

    // Divide the array numbers by the given number
    // number - the number by which the array elements will be divided
    template <typename typeArr, typename typeNum>
    typeArr* inDivArr(typeArr* arr, const int size, const typeNum& number);

    // Raising an array to a given power
    template <typename typeArr, typename typeNum>
    typeArr* powArr(typeArr* arr, const int size, const typeNum& gpow);
    //abs array
    template <typename typeArr>
    typeArr* absArr(typeArr* arr, const int size);

    // Swap signs before numbers in an array
    template <typename typeArr>
    typeArr* swapArr(typeArr* arr, const int size);

    // random nums array
    template <typename typeArr>
    typeArr* randArr(typeArr* arr, const int size);

    // union arrays (into one big)
    // For correct operation, use an array whose
    // size is twice the size of one of the original
    template <typename typeArr>
    typeArr* uniArr(typeArr* arr0, typeArr* arr1, typeArr* arr2, const int size);

    // Combine matrices (plus)
    // mat0 - First matrix
    // mat1 - Second matrix
    // mat2 - The matrix in which the result will be written
    // isize - First parameter of matrix size
    // jsize - Second parameter of matrix size
    // IMPORTANT! Matrices must be exactly the same size
    template <typename typeMat>
    typeMat* sumMat(typeMat* mat0, typeMat* mat1, typeMat* mat2, const int isize, const int jsize);

    // Subtract matrices (minus)
    // The element of the first matrix is subtracted
    // by the element of the second matrix
    template <typename typeMat>
    typeMat* minMat(typeMat* mat0, typeMat* mat1, typeMat* mat2, const int isize, const int jsize);

    // Matrix multiplication
    template <typename typeMat>
    typeMat* mulMat(typeMat* mat0, typeMat* mat1, typeMat* mat2, const int isize, const int jsize);

    // Matrix division
    template <typename typeMat>
    typeMat* divMat(typeMat* mat0, typeMat* mat1, typeMat* mat2, const int isize, const int jsize);

    // Adds a given number to all elements of a matrix
    template <typename typeMat, typename typeNum>
    typeMat* inPlusMat(typeMat* mat, const int isize, const int jsize, const typeNum& number);

    // Subtracts a given number from all matrix elements
    template <typename typeMat, typename typeNum>
    typeMat* inMinMat(typeMat* mat, const int isize, const int jsize, const typeNum& number);

    // Multiplies the given number by all matrix elements
    template <typename typeMat, typename typeNum>
    typeMat* inMulMat(typeMat* mat, const int isize, const int jsize, const typeNum& number);

    // Divides the elements of a matrix by a given number.
    template <typename typeMat, typename typeNum>
    typeMat* inDivMat(typeMat* mat, const int isize, const int jsize, const typeNum& number);

    // Raise a matrix to a given power
    template <typename typeMat, typename typeNum>
    typeMat* powMat(typeMat* mat, const int isize, const int jsize, const typeNum& gpow);

    // abs matrix
    template <typename typeMat>
    typeMat* absMat(typeMat* mat, const int isize, const int jsize);

    // Swap signs before numbers in matrix
    template <typename typeMat>
    typeMat* swapMat(typeMat* mat, const int isize, const int jsize);

    // Random numbers in matrix
    template <typename typeMat>
    typeMat* randMat(typeMat* mat, const int isize, const int jsize);


} // end namespace


/*
    GitHub: https://github.com/MikeostCorp/Math-Algorithms
*/