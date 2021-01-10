
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<cctype>
#include<ctime>
#include<cmath>
using namespace std;
/*******************************************************************************
 *
 * FUNCTIONS
 *______________________________________________________________________________
 * This program has two exercises. Exercise 1 takes in an integer parameter,
 * then computes and returns the sum of its digits; exercise 2 takes in two
 * positive integers (smaller number will be input first), then outputs all
 * prime numbers between these two integers
 *______________________________________________________________________________
 *
 * INPUT:
 *  ex          : user choice of exercise
 *  num         : the input integer for computing the sum of digits in ex1
 *  N1          : the input integer for defining the range floor in ex2
 *  N2          : the input integer for defining the range ceiling in ex2
 *
 * OUTPUT:
 *  digitsSum   : the sum of all digits of an integer
 *  digit       : the arabic number in each digit of an integer
 ******************************************************************************/


/*******************************************************************************
 * SumDigits
 *  This function receives an integer from users, then outputs the sum of its
 *  digits
 *  - returns digitsSum (sum of digits) → This will output digitsSum.
 ******************************************************************************/
int SumDigits(int ex1Num    // INPUT - an input integer for computing the sum of
                            //         its digits
             );



/*******************************************************************************
 *
 * FUNCTION SumDigits
 * _____________________________________________________________________________
 *  This function receives an integer from users, then outputs the sum of its
 *  digits
 *  - returns digitsSum (sum of digits) → This will output digitsSum.
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      digitsSum: the sum of digits of the input integer
 *      digit    : each digit of the input integer
 *
 * POST - CONDITIONS
 *  This function will output the sum of digits of the input integer
 *      digitsSum: the sum of digits of the input integer
 ******************************************************************************/
int SumDigits(int ex1Num    // INPUT - an input integer for computing the sum of
                            //         its digits
             )
{
    int digitsSum;          // CALC & OUTPUT - sum of digits of input integer
    int digit;              // CALC & OUTPUT - value of each digit of input
                            //                 integer
    digitsSum = 0;          // INITIALIZATION - sum of digits starts from zero


    // Proc: when input integer is negative
    if (ex1Num < 0)
    {
        // Calc: remove the negative sign by finding the absolute value of input
        // integer
        ex1Num = abs(ex1Num);
    }


    // Proc: loop over the input integer until get sum of its digits
    while (ex1Num > 0)
    {
        // Calc: let 10 divides input integer to find the value of the last
        // digit of input integer
        digit = ex1Num % 10;


        // Calc: add value of digit to running total
        digitsSum = digitsSum + digit;


        // Calc: remove digit once it`s added to the running total
        ex1Num = ex1Num / 10;
    }
    return digitsSum;
}


/*******************************************************************************
 * IsPrime
 *  This boolean function checks every integer in a given range, then returns
 *  true if an integer is prime or returns false if it`s not prime
 *  - returns true or false
 *  → true (if prime) or false (if not prime)
 ******************************************************************************/
bool IsPrime(int ex2Num       // INPUT - an arbitrary integer in the given range
            );


/*******************************************************************************
 *
 * FUNCTION IsPrime
 * _____________________________________________________________________________
 *  This boolean function checks every integer in a given range, then returns
 *  true if an integer is prime or returns false if it`s not prime
 *  - returns true or false
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      num: an arbitrary integer in the given range
 *
 * POST - CONDITIONS
 *  This function will return true if variable num is prime or false if variable
 *  num is not prime
 ******************************************************************************/
bool IsPrime(int ex2Num        // INPUT - an arbitrary integer in given range
             )
{
    // Proc & Output: return false if the tested integer is equal to 1
    if (ex2Num == 1 || ex2Num == 0)
    {
        return false;
    }


    // Proc & Output: check if each integer in the given range is prime
    else if (ex2Num >= 2)
    {
        // Each integer in range is divided by divisors;
        // divisor starts from 2 and increments by 1 repeatedly until it
        // is equal to the half of the dividend (tested integer)
        for (int divisor = 2; divisor <= (ex2Num / 2); divisor++)
        {
            // when a num can be exactly divided by any divisor between 2 and
            // half of the num, then it means num is not prime, which the
            // the function returns false
            if (ex2Num % divisor == 0)
            {
                return false;
            }
        }
    }
    else
    {
        return true;
    }
}


// main function
int main()
{
    //Declare variables
    int ex;                  // User input to choose which execise to run


    //Input: user choice of execise is input
    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;

    // Proc: when the first exercise is chosen
    if ( ex == 1 )
    {
        // Declare variable
        int num;            // INPUT - an integer input from users


        // Input: prompt users to enter an integer
        cout << "Please enter an integer (0 to quit): ";
        cin >> num;
        cout << endl;


        // Proc: prompt input message and output the sum of digits repeatedly,
        // otherwise output program stop message if sentinel is entered
        while (num != 0)
        {
            // Output: invoke SumDigits function to output sum of digits of
            // input integer
            cout << "The sum of the digits of " << num << " is "
                 << SumDigits(num) << endl;


            // Input: prompt users to enter an integer
            cout << "Please enter an integer (0 to quit): ";
            cin >> num;
            cout << endl;
        }
        cout << "Goodbye " << endl;
    }


    // Proc: when the second exercise is chosen
    else if ( ex == 2 )
    {
        // Declare variable
        int N1;     // INPUT - the first integer of the range
        int N2;     // INPUT - the last integer of the range


        // Input: prompt users to enter two positive integers
        cout << "Please input two positive numbers: ";
        cin >> N1 >> N2;
        cout << endl;


        // Output: output the message that prime numbers between N1 and N2 are
        cout << "The prime numbers between " << N1 << " and " << N2
             << " are: " << endl;


        // Proc & Output: loop starts from N1 and increments by 1 until it is
        // equal to N2;
        // count is an int type variable that denotes the number of prime number
        // displayed in one line
        for (int i = N1, count = 0; i <= N2; i++)
        {
            // Proc: when IsPrime function returns true
            if (IsPrime(i) == true)
            {
                // Output: prime numbers are being output, with the format that
                // has 8 numbers in one line and a tab between adjacent numbers
                cout << i << "\t";
                count++;


                // Output: output a newline when count gets to 8, which there`ve
                // been 8 numbers in one line
                if (count % 8 == 0)
                {
                    cout << endl;
                }
            }
        }
        cout << endl;
    }


    return 0;
}













