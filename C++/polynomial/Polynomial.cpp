/**
 * Describes a univariate polynomial and basic operations
 * on it.
 * CSC 3102 Homework Assignment # 1
 * @author Aaron Cao
 * @since 01-22-2017
 * @see Polynomial.h
 * @see PolynomialDemo.cpp
 */

#include <string>
#include "Polynomial.h"
using namespace std;


Polynomial::Polynomial()
{
    deg = 0;
    coeffs = new double[deg+1];
    coeffs[0] = 0;
}

Polynomial::Polynomial(double c[], int d)
{
    deg = d;
    coeffs = new double[deg+1];
    for (int i = 0; i < deg+1; i++)
    {
        coeffs[i] = c[i];
    }
}

Polynomial::~Polynomial()
{
    delete coeffs;
} 
    
double Polynomial::hornerEval(double x) const
{
    double result = coeffs[0];
    for (int i = 1; i < deg+1; i++)
    {
        result = result*x + coeffs[i];
    }
    return result;
}
    
double Polynomial::naiveEval(double x) const
{
    double exponentiatedX;
    double sum = 0;
    for (int i = 0; i < deg+1; i++)
    {
        exponentiatedX = 1;
        for (int j = 0; j < deg-i; j++)
        {
            exponentiatedX *= x;
        }
        exponentiatedX *= coeffs[i];
        sum += exponentiatedX;
    }
    return sum;    
}

int Polynomial::degree() const
{
    return deg;
}

string Polynomial::str() const
{
    string polynomialAsString = "[";
    for (int i = 0; i < deg; i++)
    {
        polynomialAsString += to_string(coeffs[i]);
        polynomialAsString += ", ";
    }
    polynomialAsString += to_string(coeffs[deg+1]);
    polynomialAsString += "]";
    return polynomialAsString;
}