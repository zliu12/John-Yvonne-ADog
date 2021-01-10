
#include<iostream>

using namespace std;

/**************************************************************************
 *
 * SUM AND AVERAGE CALCULATION OF SIX MEASUREMENTS
 *
 *_________________________________________________________________________
 * This program will use mathematical algorithms to calculate the sum and
 * the average of six measurements.
 * Inputs and outputs are float type variables.
 *_________________________________________________________________________
 * INPUT:
 *   float a: Input from the user.
 *   float b: Input from the user.
 *   float c: Input from the user.
 *   float d: Input from the user.
 *   float e: Input from the user.
 *   float f: Input from the user.
 *
 * OUTPUT:
 *   sum    : The sum of six inputs.
 *   average: The average of six inputs.
 *
 *
 *************************************************************************/
int main()
{   // Declare variables.
    float a;         // Measurement input from the user.
    float b;         // Measurement input from the user.
    float c;         // Measurement input from the user.
    float d;         // Measurement input from the user.
    float e;         // Measurement input from the user.
    float f;         // Measurement input from the user.
    float sum;       // Getting the total sum by adding all inputs.
    float average;   // Dividing the total sum of all inputs into six.


    // INPUT: the user inputs six measurements for the calculation of the
    // total sum and average.
    cout << "Enter six fp numbers on a single line, separated by "
            "spaces: \n";
    cin >> a >> b >> c >> d >> e >> f;


    // PROCESSING: the six measurements are being calculated by adding them
    // together and dividing into the number of amounts.
    sum = a + b + c + d + e + f;
    average = sum / 6;


    // OUTPUT: the program returns the total sum of six measurements and
    // their average.
    cout << "Sum of " << a << " + " << b << " + " << c << " + "
    << d << " + " << e << " + " << f << " = " << a+b+c+d+e+f << endl;
    cout << "Average = " << (a+b+c+d+e+f) / 6 << endl;

    return 0;


}

