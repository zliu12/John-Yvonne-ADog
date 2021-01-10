
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<string>
#include<cctype>
#include<ctime>
#include<cmath>
using namespace std;
/*******************************************************************************
 *
 * INTRO TO 2D ARRAYS
 *______________________________________________________________________________
 * This program provides two mathmetical operations of 2D arrays. In exercise1,
 * the program receives two 2 by 3 arrays from the user and produces a sum array
 * by adding two input arrays. In exercise2, the program receives one 2 by 3
 * array and one 3 by 3 array from the user, and returns a product array by
 * multiplying two input arrays
 *______________________________________________________________________________
 *
 * INPUT:
 *  val_A1          : the value of elements in ex1 matrix A, input from the user
 *  val_B1          : the value of elements in ex1 matrix B, input from the user
 *  val_A2          : the value of elements in ex2 matrix A, input from the user
 *  val_B2          : the value of elements in ex2 matrix B, input from the user
 *
 * OUTPUT:
 *  matrixSum       : the sum of exercise1` s matrix A & B
 *  matrixProduct   : the product of exercise2` s matrix A & B
 ******************************************************************************/


// Declare global constants
const int M = 2;                    // Number of rows of matrixA & B in ex1
const int N = 3;                    // Number of columns of matrixA & B in ex1
const int Q = 2;                    // Number of rows of matrixA in ex2
const int R = 3;                    // Number of columns of matrixA in ex2, also
                                    // mean the number of rows of matrixB in ex2
const int S = 3;                    // Number of columns of matrixB in ex2


/*******************************************************************************
 * matrixAdd
 *  This function takes in three array parameters named a, b, and sum, then
 *  returns nothing but outputs the result of the sum of exercise1` s matrix A
 *  and B in 2 by 3 form
 *  - returns nothing → outputs the sum of two matrix
 ******************************************************************************/
void matrixAdd( const int a[][N],   // An array a with N columns
                const int b[][N],   // An array b with N columns
                int sum[][N]);      // An array sum with N columns


/*******************************************************************************
 * matrixMult
 *  This function takes in three array parameters named a, b, and product, then
 *  returns nothing but outputs the result of the product of exercise1` s matrix
 *  A and B in 2 by 3 form
 *  - returns nothing → outputs the product of two matrix
 ******************************************************************************/
void matrixMult(const int a[][R],   // An array a with R columns
                const int b[][S],   // An array b with S columns
                int product[][S]);  // An array product with S columns


// Main function
int main()
{
    // Exercise 1
    // Declare variable
    int val_A1;                 // IN - users input values of ex1 matrix A
    int val_B1;                 // IN - users input values of ex1 matrix B
    int matrixA1[M][N];         // Exercise1 matrix A with user input values
    int matrixB1[M][N];         // Exercise1 matrix B with user input values
    int matrixSum[M][N];        // Calc & Out: sum of matrix A & B


    // Input: prompt the user to enter values for matrix A
    cout << "Enter Matrix A(size 2x3): " << endl;


    // Proc: row begins from 0, increases by 1 each time the loop iterates
    // until row gets to 1 less than M
    for (int row = 0; row < M; row++)
    {
        // Proc: col begins from 0, increases by 1 each time the loop
        // iterates until col gets to 1 less than N
        for (int col = 0; col < N; col++)
        {
            // Input: the user entering the values
            cin >> val_A1;


            // Proc: assign the user input values to each element of matrixA
            matrixA1[row][col] = val_A1;
        }
    }


    // Input: prompt the user to enter values for matrix B
    cout << "Enter Matrix B(size 2x3): " << endl;


    // Proc: row begins from 0, increases by 1 each time the loop iterates
    // until row gets to 1 less than M
    for (int row = 0; row < M; row++)
    {
        // Proc: row begins from 0, increases by 1 each time the loop
        // iterates until row gets to 1 less than N
        for (int col = 0; col < N; col++)
        {
            // Input: the user entering the values
            cin >> val_B1;


            // Proc: assign the user input values to each element of matrixB
            matrixB1[row][col] = val_B1;
         }
    }


    // Invocation: calling function matrixAdd, the function will ouput the
    // result of adding matrixA1 and matrixB1
    matrixAdd(matrixA1, matrixB1, matrixSum);


    // Exercise 2
    // Declare variable
    int val_A2;                 // IN - users input values of ex2 matrix A
    int val_B2;                 // IN - users input values of ex2 matrix B
    int matrixA2[Q][R];         // Exercise2 matrix A with user input values
    int matrixB2[R][S];         // Exercise2 matrix B with user input values
    int matrixProduct[Q][S];    // Calc & Out: product of matrix A & B


    // Input: prompt the user to enter values for matrix A
    cout << "Enter Matrix A(size 2x3): " << endl;


    // Proc: row begins from 0, increases 1 each time the loop iterates,
    // until row gets to 1 less than Q
    for (int row = 0; row < Q; row++)
    {
        // Proc: col begins from 0, increases 1 each time the loop iterates,
        // until col gets to 1 less than R
        for (int col = 0; col < R; col++)
        {
            // Input: the user entering the values
            cin >> val_A2;


            // Proc: assign the user input values to each element of matrixA
            matrixA2[row][col] = val_A2;
        }
    }


    // Input: prompt the user to enter values for matrix A
    cout << "Enter Matrix B(size 3x3): " << endl;


    // Proc: row begins from 0, increases 1 each time the loop iterates,
    // until row gets to 1 less than R
    for (int row = 0; row < R; row++)
    {
        // Proc: row begins from 0, increases 1 each time the loop iterates,
        // until row gets to 1 less than S
        for (int col = 0; col < S; col++)
        {
            // Input: the user entering the values
            cin>> val_B2;


            // Proc: assign the user input values to each element of matrixB
            matrixB2[row][col] = val_B2;
        }
    }


    // Invocation: calling function matrixAdd, the function will ouput the
    // result of multiplying matrixA2 and matrixB2
    matrixMult(matrixA2, matrixB2, matrixProduct);


    return 0;
}


/*******************************************************************************
 *
 * FUNCTION matrixAdd
 * _____________________________________________________________________________
 *  This function takes in three array parameters named a, b, and sum, then
 *  returns nothing but outputs the result of the sum of exercise1` s matrix A
 *  and B in 2 by 3 form
 *  - returns nothing → outputs the sum of two matrix
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      a   : array a with N columns
 *      b   : array b with N columns
 *      sum : array sum with N columns
 *
 * POST - CONDITIONS
 *  This function will output the sum of matrix A and matrix B
 ******************************************************************************/
void matrixAdd(const int a[][N],    // Array a with N columns
               const int b[][N],    // Array b with N columns
               int sum[][N])        // Array sum with N columns
{
    // Output: output "Res:"
    cout << "Res:" << endl;


    // Proc: row begins from 0, increases by 1 each time loop iterates until it
    // gets to 1 less than M
    for (int row = 0; row < M; row++)
    {
        // Proc: col begins from 0, increases by 1 each time loop iterates until
        // it gets to 1 less than N
        for (int col = 0; col < N; col++)
        {
            // Calc： adding martix A & B by adding two elements in A and B that
            // have the same row and col
            sum[row][col] = a[row][col] + b[row][col];


            // Output: output the matrix sum with the form that has 3 elements
            // in each row and each one is segmented by a space
            cout << sum[row][col] << " ";
        }
        cout << endl;
    }
}


/*******************************************************************************
 *
 * FUNCTION matrixMult
 * _____________________________________________________________________________
 *  This function takes in three array parameters named a, b, and product, then
 *  returns nothing but outputs the result of the product of exercise1` s matrix
 *  A and B in 2 by 3 form
 *  - returns nothing → outputs the product of two matrix
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      a   : array a with R columns
 *      b   : array b with S columns
 *      sum : array product with S columns
 *
 * POST - CONDITIONS
 *  This function will output the sum of matrix A and matrix B
 ******************************************************************************/
void matrixMult(const int a[][R],   // Array a with R columns
                const int b[][S],   // Array b with S columns
                int product[][S])   // Array product with S columns
{
    // Proc: row begins from 0 and increases by 1 each time loop iterates until
    // it gets to 1 less than Q
    for (int row = 0; row < Q; row++)
    {
        // Proc: col begins from 0 and increases by 1 each time loop iterates
        // until it gets to 1 less than S
        for (int col = 0; col < S; col++)
        {
            // Proc: assign value 0 to each element in array product
            product[row][col] = 0;
        }
    }


    // Output: output "Res: "
    cout << "Res:" << endl;


    // Proc: row begins from 0 and increases by 1 each time loop iterates until
    // it gets to 1 less than Q
    for (int row = 0; row < Q; row++)
    {
        // Proc: col begins from 0 and increases by 1 each time loop iterates
        // until it gets to 1 less than S
        for (int col = 0; col < S; col++)
        {
            // Proc: k begins from 0 and increases by 1 each time loop
            // iterates until it gets to 1 less than R
            for (int k = 0; k < R; k++)
            {
                // Calc & Out: each element in array product is assigned with
                // the value that`s equal to the element in array a which is on
                // row-th row and k-th column times the element in array b which
                // is on k-th row and col-th column
                product[row][col] += a[row][k] * b[k][col];
            }


            // Output: output the matrix product with the form that has 3
            cout << product[row][col] << " ";
        }
        cout << endl;
    }
}
