
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<cctype>
#include<cmath>
using namespace std;
/*******************************************************************************
 *
 * ARRAYS
 *______________________________________________________________________________
 * This program uses the randFloat function to generate two sequences of random
 * floating-point values between 4 and 10. Two sequences are specifically sized:
 * sequences of 100 and 10,000. Then the program compares the computed practical
 * mean and variance to the theoretical values (using the given formulas).
 *______________________________________________________________________________
 *
 * INPUT:
 *
 * OUTPUT:
 *  array1          : the sequence with 100 numbers
 *  array2          : the sequence with 10000 numbers
 *  sum1            : the sum of all elements in sequence 100
 *  sum2            : the sum of all elements in sequence 10000
 *  pracMean1       : the pratical mean of sequence 100
 *  pracMean2       : the pratical mean of sequence 10000
 *  sumSquareDiff1  : the sum of the squrare of the difference between each
 *                        element in squence 100 and the practical mean of
 *                        sequence 100
 *  sumSquareDiff2  : the sum of the squrare of the difference between each
 *                        element in squence 10000 and the practical mean of
 *                        sequence 10000
 *  pracVar1        : the practical variance of sequence 100
 *  ppracVar2       : the practical variance of sequence 10000
 ******************************************************************************/


/*******************************************************************************
 * randFloat
 *  This function takes in two int parameters named a and b, and then returns a
 *  random number between limits a and b
 *  - returns a random number
 ******************************************************************************/
double randFloat (double a,         // Floor value of a random sequence number
                  double b);        // Ceiling value of a random sequence number


/*******************************************************************************
 * theoreticalMean
 *  This function takes in two double parameters named a and b as the limits,
 *  and then returns the theoretical mean of the sequence
 *  - returns theoretical mean
 ******************************************************************************/
double theoreticalMean(double a,    // Floor value of a random sequence number
                       double b);   // Ceiling value of a random sequence number


/*******************************************************************************
 * theoreticalVar
 *  This function takes in two double parameters named a anb b as the limits,
 *  and then returns the theoretical variance of the sequence
 *  - returns theoretical variance
 ******************************************************************************/
double theoreticalVar(double a,     // Floor value of a random sequence number
                      double b);    // Ceiling value of a random sequence number


int main()
{
    // Seed rand with 500
    srand(500);

    // declare variable
    double array1[100];         // The sequence with 100 numbers
    double array2[10000];       // The sequence with 10000 numbers
    double a;                   // The floor value of a random sequence number
    double b;                   // The floor value of a random sequence number
    double sum1;                // Calc - the sum of all elements in array1
    double sum2;                // Calc - the sum of all elements in array2
    double sumSquareDiff1;      // Calc - the sum of the squrare of the
                                //        difference between array1 elements and
                                //        array1 mean
    double sumSquareDiff2;      // Calc - the sum of the squrare of the
                                //        difference between array2 elements and
                                //        array1 mean
    double pracMean1;           // Calc & Out: the practical mean of elements in
                                //             array1
    double pracMean2;           // Calc & Out: the practical mean of elements in
                                //             array2
    double pracVar1;            // Calc & Out: the practical variance of array1
    double pracVar2;            // Calc & Out: the practical variance of array2


    // Initialization
    a = 4;                      // Set floor value to 4
    b = 10;                     // Set ceiling value to 10
    sum1 = 0;                   // Set sum of all elements in array1 to 0
    sum2 = 0;                   // Set sum of all elements in array2 to 0
    sumSquareDiff1 = 0;         // Set sum of difference of array1 to 0
    sumSquareDiff2 = 0;         // Set sum of difference of array2 to 0


    // Proc: i starts from 0, increases by 1 each time loop iterates until i
    // becomes 1 integer less than 100
    for (int i = 0; i < 100; i++ )
    {
        // Invocation & Proc: calling randFloat function and assign its returned
        // value to array1
        array1[i] = randFloat(a, b);


        // Calc: add together the value of all elements in array1
        sum1 = sum1 + array1[i];
    }


    // Calc & Out: average the sum of array1 elements to get array1 practiceal
    // mean
    pracMean1 = sum1 / 100;


    // Proc: i starts from 0, increases by 1 each time loop iterates until i
    // becomes 1 integer less than 100
    for (int i = 0; i < 100; i++)
    {
        // Calc: add together the squared differences between array1 practical
        // mean and each array1 element
        sumSquareDiff1 = sumSquareDiff1 + pow((array1[i] - pracMean1), 2);
    }


    // Calc & Out: divide array1 sum of all squared difference by the number of
    // array1 elements to get array1 practical variance
    pracVar1 = sumSquareDiff1 / 100;


    // Proc: i starts from 0, increases by 1 each time loop iterates until i
    // becomes 1 integer less than 10000
    for (int i = 0; i < 10000; i++ )
    {
        // Invocation & Proc: calling randFloat function and assign its returned
        // value to array2
        array2[i] = randFloat(a, b);


        // Calc: add together the value of all elements in array2
        sum2 = sum2 + array2[i];
    }


    // Calc & Out: average the sum of array2 elements to get array2 practiceal
    // mean
    pracMean2 = sum2 / 10000;


    // Proc: i starts from 0, increases by 1 each time loop iterates until i
    // becomes 1 integer less than 10000
    for (int i = 0; i < 10000; i++ )
    {
        // Calc: add together the squared differences between array2 practical
        // mean and each array2 element
        sumSquareDiff2 = sumSquareDiff2 + pow((array2[i] - pracMean2), 2);
    }


    // Calc & Out: divide array1 sum of all squared difference by the number of
    // array1 elements to get array1 practical variance
    pracVar2 = sumSquareDiff2 / 10000;


    // Output: output the theoretcial mean, practical mean, theoretical variance
    // and practical variance of array1
    cout << theoreticalMean(a, b) << " " << pracMean1 << " "
         << theoreticalVar(a, b) << " " << pracVar1 << endl;


    // Output: output the theoretcial mean, practical mean, theoretical variance
    // and practical variance of array2
    cout << theoreticalMean(a, b) << " " << pracMean2 << " "
         << theoreticalVar(a, b) << " " << pracVar2 << endl;


    return 0;
}


/*******************************************************************************
 *
 * FUNCTION randFloat
 * _____________________________________________________________________________
 *  This function takes in two int parameters named a and b, and then returns a
 *  random number between limits a and b
 *  - returns a random number
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      a: the floor value of random numbers in sequence
 *      b: the ceiling value of random numbers in sequence
 *
 * POST - CONDITIONS
 *  This function will return a random number
 ******************************************************************************/
double randFloat (double a,         // Floor value of a random sequence number
                  double b)         // Ceiling value of a random sequence number
{
    // Return: a random number between a and b
   return a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
}


/*******************************************************************************
 *
 * FUNCTION theoreticalMean
 * _____________________________________________________________________________
 *  This function takes in two double parameters named a and b as the limits,
 *  and then returns the theoretical mean of the sequence
 *  - returns theoretical mean
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      a: the floor value of random numbers in sequence
 *      b: the ceiling value of random numbers in sequence
 *
 * POST - CONDITIONS
 *  This function will return the theoretical mean
 ******************************************************************************/
double theoreticalMean(double a,    // Floor value of a random sequence number
                       double b)    // Ceiling value of a random sequence number
{
    // Return: the theoretical mean
    return ((a + b) / 2);
}


/*******************************************************************************
 *
 * FUNCTION theoreticalVar
 * _____________________________________________________________________________
 *  This function takes in two double parameters named a anb b as the limits,
 *  and then returns the theoretical variance of the sequence
 *  - returns theoretical variance
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      a: the floor value of random numbers in sequence
 *      b: the ceiling value of random numbers in sequence
 *
 * POST - CONDITIONS
 *  This function will return the theoretical vairance
 ******************************************************************************/
double theoreticalVar(double a,     // Floor value of a random sequence number
                      double b)     // Ceiling value of a random sequence number
{
    // Return: the theoretical variance
    return ((pow((b - a), 2)) / 12);
}








