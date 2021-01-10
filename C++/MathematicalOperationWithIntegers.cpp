
#include<iostream>

using namespace std;

/**************************************************************************
 *
 * ADDITION & SUBTRACTION & DIVISION CALULATION OF INPUT INTEGERS
 *_________________________________________________________________________
 *
 * This program will use mathematical algorithms to calculate the sum, the
 * product, the quotient, and the remainder of two input integers.
 * Inputs and outputs are integer type variables.
 *_________________________________________________________________________
 *
 * INPUT:
 *   int num_1          : The first input integer from the user.
 *   int num_2          : The second input integer from the user.
 *
 * OUTPUT:
 *   int sum_num        : The sum of two input integers.
 *   int product_sum    : The production of two input integers.
 *   int quotient_sum   : The quotient of two input integers.
 *   int remainder_sum  : The remainder of two input integers.
 *
 *************************************************************************/

int main()
{   // Declare variables.
    int num_1;           // The first integer entered by the user.
    int num_2;           // The second integer entered by the user.
    int sum_num;         // CALC & OUT - contains the sum result of adding
                         // two input integers.
    int product_num;     // CALC & OUT - contains the product result of
                         // multiplying two input integers.
    int quotient_num;    // CALC & OUT - contains the quotient result of
                         // dividing the first input integer into the
                         // second input integer.
    int remainder_num;   // CALC & OUT - contains the remainder result of
                         // dividing the first input integer into the
                         // second input integer.


    // INPUT: two integers from the user.
    cout << "Enter the first integer: \n";
    cin >> num_1;
    cout << "Enter the second integer: \n";
    cin >> num_2;


    // PROCESSING: two input integers are being calculated by addition,
    // subtraction, multiplication, and modulus.
    sum_num = num_1 + num_2;
    product_num = num_1 * num_2;
    quotient_num = num_1 / num_2;
    remainder_num = num_1 % num_2;


    // OUTPUT: The program returns the sum, product, quotient, and
    // remainder of the two input integers from the user.
    cout << num_1 << " + " << num_2 << " = " << sum_num << endl;
    cout << num_1 << " * " << num_2 << " = " << product_num << endl;
    cout << num_1 << " / " << num_2 << " = " << quotient_num << endl;
    cout << num_1 << " % " << num_2 << " = " << remainder_num << endl;

    return 0;
}

