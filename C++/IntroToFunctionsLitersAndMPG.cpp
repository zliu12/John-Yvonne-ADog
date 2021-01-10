
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
/*******************************************************************************
 *
 * Intro to Functions - Liters and MPG
 *______________________________________________________________________________
 * This program reads in the number of liters of gasoline consumed by the user’s
 * car and the number of miles traveled by the car, then outputs the number of
 * miles per gallon the car delivered. Users are allowed to repeat this
 * calculation as often as the user wishes. Next, this program also inputs data
 * from two cars and outputs the number of miles per gallon delivered by each
 * car, then compares and concludes which car has the best fuel efficiency.
 *______________________________________________________________________________
 *
 * INPUT:
 *  ch          : an instruction from the user, received as input
 *  liters      : the number of liters of gasoline consumed by a car, received
 *                as input
 *  miles       : the number of miles a car travels, received as input
 *  car1_liters : the number of liters of gasoline consumed by the first car,
 *                received as input
 *  car1_miles  : the number of miles the first car travels, received as input
 *  car2_liters : the number of liters of gasoline consumed by the second car,
 *                received as input
 *  car2_miles  : the number of miles the second car travels, received as input
 *
 * OUTPUT:
 *  mpg         : miles per gallon of a car
 *  mpg1        : miles per gallon of the first car
 *  mpg2        : miles per gallon of the second car
 ******************************************************************************/


/*******************************************************************************
 * mpgCalculator
 *  This function receives the number of liters of gasoline consumed by the
 *  user’s car and the number of miles traveled by the car, then outputs the
 *  number of miles per gallon the car delivered
 *  - returns mpg (miles per gallon) → This will output the mpg.
 ******************************************************************************/
double mpgCalculator (double liters, // IN - the number of liters of gasoline
                                     //      consumed by the user’s car
                      double miles); // IN - the number of miles traveled by the
                                     //      car


// main funciton
int main()
{
    //Declare variables
    char ch;            // INPUT - a letter input by users whether or not they
                        //         want to continue the calculation
    double liters;      // INPUT - a car`s gasoline consumption in liters to
                        //         calculate the miles per gallon
    double miles;       // INPUT - miles traveled by a car to calculate the
                        //         miles per gallon
    double car1_liters; // INPUT - the first car`s gasoline consumption in
                        //         liters to calculate the miles per gallon
    double car1_miles;  // INPUT - miles traveled by the first car to calculate
                        //         the miles per gallon
    double car2_liters; // INPUT - the second car`s gasoline consumption in
                        //         liters to calculate the miles per gallon
    double car2_miles;  // INPUT - miles traveled by the second car to calculate
                        //         the miles per gallon
    double mpg1;        // CALC & OUTPUT - miles per gallon of the first car
    double mpg2;        // CALC & OUTPUT - miles per gallon of the second car


    // Prompt users to enter gasoline consumption and miles traveled by a car,
    // loop over until received the quit instruction
    do
    {
        // Input: gasoline consumption in liters by the car is being input
        cout << "Enter the number of liters of gas consumed: " << endl;
        cin >> liters;


        // Input: distance traveled in miles by the car is being input
        cout << "Enter the number of miles traveled: " << endl;
        cin >> miles;


        // Output: miles per gallon of the car is being output, the result is
        // set to a number with four decimal places
        cout << fixed << setprecision(4) << "This car gets "
             << mpgCalculator(liters, miles) << " miles per gallon." << endl;


        // Input: prompt users if they would like to calculate the mpg of
        // another car, calculation starts again if users enter 'y' or quit
        // otherwise
        cout << "Calculate again? " << endl;
        cin >> ch;  
    } while (ch == 'y');
    cout << "\n" << endl;


    // Input: gasoline consumption in liters by the first car is being input
    cout << "Enter the number of liters consumed for the first car: " << endl;
    cin >> car1_liters;


    // Input: distance traveled in miles by the first car is being input
    cout << "Enter the number of miles traveled for the first car: " << endl;
    cin >> car1_miles;


    // Input: gasoline consumption in liters by the second car is being input
    cout << "Enter the number of liters consumed for the second car: " << endl;
    cin >> car2_liters;


    // Input: distance traveled in miles by the first car is being input
    cout << "Enter the number of miles traveled for the second car: " << endl;
    cin >> car2_miles;
    cout << "\n" << endl;


    // mpgCalculator: outputs miles a car can travel with one gallon of gasoline
    mpg1 = mpgCalculator(car1_liters, car1_miles);
    mpg2 = mpgCalculator(car2_liters, car2_miles);


    // Output: miles per gallon of the first & second cars are being output,
    // results are set to numbers with four decimal places
    cout << "The first car gets " << fixed << setprecision(4) << mpg1
         << " miles per gallon." << endl;
    cout << "The second car gets " << fixed << setprecision(4) << mpg2
         << " miles per gallon." << endl;


    // Processing: compare which car has the best fuel efficiency
    // When the first car has a larger mpg
    if (mpg1 > mpg2)
    {
        // Output： the first car has the better fuel efficiency
        cout << "The first car has better gas mileage." << endl;
    }


    // When the first car doesn`t have a larger mpg
    else
    {
        // Output: the second car has the better fuel efficiency
        cout << "The second car has better gas mileage." << endl;
    }


   return 0;
}


/*******************************************************************************
 *
 * FUNCTION mpgCalculator
 * _____________________________________________________________________________
 * This function receives the number of liters of gasoline consumed by the
 * user’s car and the number of miles traveled by the car, then outputs the
 * number of miles per gallon the car delivered -
 * returns mpg (miles per gallon).
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      liters: the number of liters of gasoline consumed by the user’s car
 *      miles : the number of miles traveled by the car
 *
 * POST - CONDITIONS
 *  This function will output miles per gallon which is abbreviated to mpg
 *      mpg   : the number of miles per gallon a car delivered
 ******************************************************************************/
double mpgCalculator (double liters, // IN - the number of liters of gasoline
                                     //      consumed by the user’s car
                      double miles)  // IN - the number of miles traveled by the
                                     //      car
{
    // Declare variables
    const double liter_to_gallon = 0.264179; // CONST - ratio between liters
                                             // and gallons
    double mpg;                              // Output - miles per gallon


    // Calculation: gasoline consumption in liters of a cars are converted
    // into gallons, then divides miles traveled of each car, will output miles
    // per gallon of each car
    mpg = miles / (liters * liter_to_gallon);


    return mpg;
}
