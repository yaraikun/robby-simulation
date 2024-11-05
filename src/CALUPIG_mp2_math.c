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

/**
 * RaiseTo - Computes the value of x raised to the power of n (x^n).
 * @x: Base value to be exponentiated.
 * @n: Exponent.
 *
 * Does not handle very large exponentiation.
 *
 * Return: The value of x^n.
 *
 * Edge Cases:
 * - If n < 0 and x == 0, the function returns NaN (undefined).
 * - If n == 0, the function returns 1.0, as x^0 is defined for all x.
 */
double RaiseTo(double x, int n)
{
        double result = 1.0;
        int exp = (n < 0) ? -n : n;

        while (exp > 0) {           /* Exponentiation by squaring */
                if (exp % 2 == 1) 
                        result *= x;
                x *= x;
                exp /= 2;
        }

        if (n < 0) {                /* Adjusts for negative exponent */
                if (x != 0)
                        result = 1.0 / result;
                else
                        result = 0.0 / 0.0;
        }

        /* If n == 0, it remains 1.0 as initialized */

        return result;
}

/**
 * factorial - Computes the value of the factorial of n (n!).
 * @n: Value whose factorial is to be calculated.
 *
 * Does not handle very large factorials.
 *
 * Return: The factorial of n.
 *
 * Edge Cases:
 * - If n < 0, the function returns NaN (undefined), as factorials are only
 *   defined for non-negative integers.
 * - If n == 0 or n == 1, the function returns 1.0, as 0! and 1! are both
 *   defined as 1.
 */
double factorial(int n)
{
        double result = 1.0;

        while (n > 1) {             /* Calculate factorial iteratively */
                result *= n;
                n--;
        }

        if (n < 0)                      /* Handles negative case */
                result = 0.0 / 0.0;

        /* If n == 0 or 1, it remains 1.0 as initialized */

        return result;
}

/** 
 * cosine - Computes the value of the cosine of angle x (cos x).
 * @x: Angle in radians.
 *
 * Calls RaiseTo() and factorial() functions to approximate cosine.
 *
 * Return: The cosine of x.
 */
double cosine(double x)
{
        double result = 0.0;

        for (int i = 0; i < NUMBER_OF_TERMS; i++) {
                double term = RaiseTo(-1, i) * RaiseTo(x, 2 * i) /
                              factorial(2 * i);
                result += term;
        }

        return result;
}

/**
 * sine - Computes the value of the sine of angle x (sin x).
 * @x: Angle in radians.
 *
 * Calls RaiseTo() and factorial() functions to approximate sine.
 *
 * Return: The sine of x.
 */
double sine(double x)
{
        double result = 0.0;

        for (int i = 0; i < NUMBER_OF_TERMS; i++) {
                double term = RaiseTo(-1, i) * RaiseTo(x, 2 * i + 1) /
                              factorial(2 * i + 1);
                result += term;
        }

        return result;
}
