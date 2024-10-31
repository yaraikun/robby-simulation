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
 * Return: The value of x^n.
 */
double RaiseTo(double x, int n)
{
        double result = 1.0;

        for (int i = 0; i < n; i++)
                result *= x;

        return result;
}

/*
 * factorial - Computes the value of the factorial of n (n!).
 * @n: Non-negative integer.
 *
 * Return: The factorial of n.
 */
double factorial(int n)
{
        double result = 1.0;

        for (int i = 1; i <= n; i++)
                result *= i;

        return result;
}

/* 
 * cosine - Computes the value of the cosine of angle x (cos x).
 * @x: Angle in radians.
 *
 * Return: The cosine of x.
 */
double cosine(double x)
{
        while (x > 2 * PI) x -= 2 * PI;
        while (x < -2 * PI) x += 2 * PI;

        double result = 0.0;

        for (int i = 0; i < NUMBER_OF_TERMS; i++) {
                double term = RaiseTo(x, 2 * i) / factorial(2 * i);
                result += (i % 2 == 0) ? term : -term;
        }

        return result;
}

/*
 * sine - Computes the value of the sine of angle x (sin x).
 * @x: Angle in radians.
 *
 * Return: The sine of x.
 */
double sine(double x)
{
        while (x > 2 * PI) x -= 2 * PI;
        while (x < -2 * PI) x += 2 * PI;

        double result = 0.0;

        for (int i = 0; i < NUMBER_OF_TERMS; i++) {
                double term = RaiseTo(x, 2 * i + 1) / factorial(2 * i + 1);
                result += (i % 2 == 0) ? term : -term;
        }

        return result;
}
