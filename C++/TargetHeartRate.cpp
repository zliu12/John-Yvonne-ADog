
#include<iostream>

using namespace std;

/**************************************************************************
 *
 * FIND LOWER LIMIT AND UPPER LIMIT TARGET HEART RATE BASE ON THE AGE
 *_________________________________________________________________________
 *
 * By entering the age, this program will calculate the user`s target
 * heart rate zone for aerobic exercise.
 * Inputs and outputs are float type variables.
 *_________________________________________________________________________
 *
 * INPUT:
 *   age: the float type variable to be entered and calculated as input.
 *
 * OUTPUT:
 *   lower_limit: the minimum heart rate for the age.
 *   upper_limit: the maximum heart rate for the age.
 *
 *************************************************************************/

int main()
{
    // Declare variables.
    float age;              // INPUT - float variable to be entered and
                            //         calculated.
    float lower_limit;      // CALC & OUT - contains the minimum result of
                            //         the calculation base on the age.
    float upper_limit;      // CALC & OUT - contains the maximum result of
                            //         the calculation base on the age.


    // Input: get the age from the user.
    cout << "What is your age: \n";
    cin >> age;


    // Processing: age entered by the user is passed to the functions to
    //             calculate.
    lower_limit = 0.6 * (220 - age);         // Process the age to output
                                             // the minimum result.
    upper_limit = 0.75 * (220 - age);        // Process the age to output
                                             // the maximum result.


    // Output: output the lower limit and the upper limit of the user`s
    //         heart rate zone.
    cout << "Your target heart rate is between " << lower_limit  <<
            " and " <<upper_limit << " bpm." << endl;

    return 0;

}
