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

#include "../include/mp2_math.h"

#define NUMBER_OF_TERMS 10



// Computes and returns the value of x raised to n. 
double RaiseTo(double x, int n) {

    // Initialize the result to 1. (Identity Property of Multiplication)
    double result = 1.0;

    // Loop from 1 to n.
    for (int i = 1; i <= n; i++) {

        // Multiply result by x every iteration.
        result *= x;
    }

    // Return calculated value of x^n.
    return result;
}



// Computes and returns the value of the factorial of n.
double factorial(int n) {

    // Initialize value of result. (0! = 1)
    double result = 1.0;

    // Loop from 1 to n. 
    for (int i = 1; i <= n; i++) {

        // Multiply result by the integer i.
        result *= i;
    }

    // Return calculated of x!.
    return result;
}



// Computes and returns the value o the cosine of angle x.
// Note that x is in radians.
double cosine(double x) {

    // Convert angle x from degrees to radians.
    // x *= PI / 180;

    // Initialize value of cosine result to 0.
    double result = 0.0;

    // Loop through NUMBER_OF_TERMS to calculate Taylor series for cosine.
    for (int i = 0; i < NUMBER_OF_TERMS; i++) {

        // Calculate current term in the series.
        double term = RaiseTo(x, 2 * i) / factorial(2 * i);

        // Add or subtract term if even or odd.
        result += (i % 2 == 0 ? term : -term);
    }

    // Return calculated result of cos(x).
    return result;
}



// Computes and returns the value o the sine of angle c.
// Note that x is in radians.
double sine(double x) {

    // Convert angle x from degrees to radians.
    // x *= PI / 180;

    // Initialize value of sine result to 0.
    double result = 0.0;

    // Loop through NUMBER_OF_TERMS to calculate Taylor Series for sine.
    for (int i = 0; i < NUMBER_OF_TERMS; i++) {

        // Calculate current term in the series.
        double term = RaiseTo(x, 2 * i + 1) / factorial(2 * i + 1);

        // Add or subtract term if even or odd.
        result += (i % 2 == 0 ? term : -term);
    }

    // Return calculated result of sin(x).
    return result;
}
