/**
 * Describes a univariate polynomial and basic operations
 * on it.
 * CSC 3102 Homework Assignment # 1
 * @author Aaron Cao
 * @since 01-22-2017
 * @see Polynomial.h
 * @see Polynomial.cpp 
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include "Polynomial.h"
using namespace std::chrono;

int main()
{
    /**
     * rand() is kind of outdated nowadays isn't it? 
     * I think the <random> library has random generators with uniform distribution like the Mersenne-Twister
     * something that looks like
     * random_device rd;
     * mt19937 rng(rd());
     * uniform_int_distribution<int> uni(min,max);
     * and this way we don't even have to worry about using time as a seed
     */
    srand(time(NULL));
    /**
     * Initializing test case arrays 
     */
    double coefficients1[7] = {4, 5, 0, 2, 3, 5, -1};
    double coefficients2[6] = {12.5, 0, 0, -1, 7.2, -9.5};
    /**
     * Constructing polynomial classes
     */
    Polynomial poly1(coefficients1, 6);
    Polynomial poly2(coefficients2, 5);

    cout << "f := " << poly1.str() << endl;
    cout << "deg f(x) := " << poly1.degree() << endl;
    cout << "Using Horner's method, f(3) = " << poly1.hornerEval(3) << endl;
    cout << "Using naive method, f(3) = " << poly1.naiveEval(3) << endl << endl;

    cout << "g := " << poly2.str() << endl;
    cout << "deg g(x) := " << poly2.degree() << endl;
    cout << "Using Horner's method, g(-7.25) = " << poly2.hornerEval(-7.25) << endl;
    cout << "Using naive method, g(-7.25) = " << poly2.naiveEval(-7.25) << endl << endl;

    cout << "Empirical Analysis of Naive vs Horner’s Methods" << endl;
    cout << "on 10 Polynomials with Random Coefficients" << endl;
    cout << "================================================" << endl;
    cout << "Degree    Naive Time (ns)     Horner’s Time (ns)" << endl;
    cout << "------------------------------------------------" << endl;
    /**
     * Testing execution times
     * Creating a double variable randX that will store a random double in [0.5, 1.2]
     * Allocating memory dynamically for the coefficient array so it can be reassigned
     */
    double randX;
    double *coefficients;

    for (int i = 1; i <= 10; i++)
    {
        /**
         * Changing the size of the coefficient array per iteration
         */
        coefficients = new double[i*1000];
        /**
         * Filling the coefficient array with values
         */
        for (int j = 0; j < i*1000; j++)
        {
            coefficients[j] = rand()%6;
        }
        /**
         * Constructin the polynomial
         */
        Polynomial poly(coefficients, i*1000);
        /**
         * Starting the high resolution clock for naiveEval
         */    
        auto start = high_resolution_clock::now();
        /**
         * Starting the high resolution clock for naiveEval
         */ 
        for (int k = 0; k < 10; k++)
        {
            /**
             * Running the method 10 times gives a better measurement of elapsed time
             * Since rand() returns an int, this is a workaround to have it return a double
             */
            randX = 0.5+((double)rand()/RAND_MAX)*(1.2-0.5);
            poly.naiveEval(randX);
        }
        auto elapsed = high_resolution_clock::now() - start;
        /**
         * Since the method was ran 10 times, the duration is divided by 10
         */
        auto duration = (duration_cast<nanoseconds>(elapsed).count())/10;
        cout << i*1000 <<"      " << duration << "             ";
        /**
         * Same process for hornerEval
         */
        start = high_resolution_clock::now();
        for (int k = 0; k < 10; k++)
        {
            poly.hornerEval(randX);
        }
        elapsed = high_resolution_clock::now() - start;
        duration = (duration_cast<nanoseconds>(elapsed).count())/10;
        cout << duration << endl;
        /**
         * Freeing the coefficients array for reuse
         */
        delete [] coefficients;
    }

    cout << "------------------------------------------------" << endl;
    return 0;
}