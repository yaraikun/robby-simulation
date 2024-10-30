/*****************************************************************************/
/* CCPROG1 Machine Problem Part 2                                            */
/* CALUPIG, EVAN RILEY                                                       */
/* S24B                                                                      */
/*                                                                           */
/* This file should contain the function DEFINITION of the                   */
/* mp1_math functions.                                                       */
/*                                                                           */
/* NOTES:                                                                    */
/* 1. Change the word "lastname" in the filename to your own last name.      */
/*    For example, if your last name is SANTOS, then this file should be     */
/*    named as SANTOS_mp2_math.c                                             */ 
/* 2. Your main task is to implement/fill-up the body of the functions.      */
/* 3. You also need to compile this source code separately to produce        */
/*    the object file.                                                       */
/* 4. The following are NOT ALLOWED:                                         */
/*    a. addition of  new codes other than the implementation of the body    */  
/*       of the functions and the entries in this preamble                   */
/*    b. changing the return type, function name and parametrizations        */
/*    c. calling output function such as printf() - DO NOT output anything   */
/*       inside the function definitions!                                    */
/*****************************************************************************/

#include "mp2_math.h"

#define NUMBER_OF_TERMS 10

/* 
 * RaiseTo - Computes the value of x raised to the power of n (x^n).
 * @x: Base value to be exponentiated.
 * @n: Exponent (must be a non-negative integer).
 *
 * This function calculates the result of x raised to the power of n by 
 * multiplying x by itself n times. It initializes the result to 1.0 (the
 * multiplicative identity), and updates the result iteratively.
 *
 * Return: The value of x^n.
 */
double RaiseTo(double x, int n)
{
    double result = 1.0;  // Initialize accumulator to 1.0 for multiplication

    // Loop iterates n times
    for (int i = 0; i < n; i++)
        result *= x;  // Multiply accumulator by x for each iteration

    return result;  // Return computed exponential value
}

/*
 * factorial - Computes the value of the factorial of n (n!).
 * @n: Non-negative integer.
 *
 * This function calculates the result of n factorial by multiplying 1.0 by an
 * integer n from 1 to n. It initializes the result to 1.0 (the multiplicative
 * identity), and updates the result iteratively.
 *
 * Return: The factorial of n.
 */
double factorial(int n)
{
    double result = 1.0;  // Initialize accumulator to 1.0 for multiplication

    // Iterates from 1 to n
    for (int i = 1; i <= n; i++)
        result *= i;  // Multiply accumulator by i for each iteration

    return result;  // Return computed factorial
}

/* 
 * cosine - Computes the value of the cosine of angle x (cos x).
 * @x: Angle in radians.
 *
 * This function uses the Taylor series expansion to compute cos(x), limited to
 * NUMBER_OF_TERMS. It initializes the result to 0.0 (the additive identity)
 * and iteratively updates it with each term in the series.
 *
 * Return: The cosine of x.
 */
double cosine(double x)
{
    double result = 0.0;  // Initialize accumulator to 0.0 for summation.

    // Loop iterates NUMBER_OF_TERMS times
    for (int i = 0; i < NUMBER_OF_TERMS; i++) {
        /*
         * Calculates term in Taylor series using the formula:
         * ((-1)^n / (2n)!) * x^2n
         *
         * Which can be rewritten for the purposes of this loop as:
         * (-1)^i * ((x^2i) / (2i)!)
         *
         * Thus, we can calculate the term as:
         * ((x^2i) / (2i)!)
         *
         * And the sign of the term changes accordingly when i is even or odd:
         * (-1)^i
         */
        double term = RaiseTo(x, 2 * i) / factorial(2 * i);
        result += (i % 2 == 0 ? term : -term);
    }

    return result;  // Returns result calculated approximation
}

/*
 * sine - Computes the value of the sine of angle x
 * @x: Angle in radians.
 *
 * This function uses the Taylor series expansion to compute cos(x), limited to
 * NUMBER_OF_TERMS. It initializes the result to 0.0 (the additive identity)
 * and iteratively updates it with each term in the series.
 *
 * Return: The sine of x.
 */
double sine(double x)
{
    double result = 0.0;  // Initialize accumulator to 0.0 for summation.

    // Loop iterates NUMBER_OF_TERMS times
    for (int i = 0; i < NUMBER_OF_TERMS; i++) {
        /*
         * Calculates term in Taylor series using the formula:
         * ((-1)^n / (2n)!) * x^2n
         *
         * Which can be rewritten for the purposes of this loop as:
         * (-1)^i * ((x^2i + 1) / (2i + 1)!)
         *
         * Thus, we can calculate the term as:
         * ((x^2i + 1) / (2i + 1)!)
         *
         * And the sign of the term changes accordingly when i is even or odd:
         * (-1)^i
         */
        double term = RaiseTo(x, 2 * i + 1) / factorial(2 * i + 1);
        result += (i % 2 == 0 ? term : -term);
    }

    return result;  // Returns result calculated approximation
}
