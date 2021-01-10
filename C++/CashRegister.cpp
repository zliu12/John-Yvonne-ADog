
#include<iostream>
using namespace std;
/*******************************************************************************
 *
 * CASH REGISTER
 * ______________________________________________________________________________
 *
 * With the inputs of the purchase amount and the amount received, the program
 * will calulate the total change and the quantities of each denomination,
 * including the dollar, the quarter, the dime, the nickel, and the penny.
 * _____________________________________________________________________________
 *
 * INPUT:
 *  purchase_amount: User`s input of how much money should be charged
 *  amount_received: User`s input of how much money received from the customer
 *
 * OUTPUT:
 *  change         : Amount of money returned to the customer
 *  dollar_q       : Quantities of the dollar denomination in returned change
 *  quarter_q      : Quantities of the quarter denomination in returned change
 *  dime_q         : Quantities of the dime denomination in returned change
 *  penny_q        : Quantities of the penny denomination in returned change
 *
 ******************************************************************************/
int main()
{
    //Declare Variables
    float purchase_amount; // A float variable denotes the charged amount, input
                           // from users
    float amount_received; // A float variable denotes the paid amount, input
                           // from users
    float change;          // A float variable denotes the amount of money
                           // returned to customers after paying
    int change_in_pennies; // An integer variable denotes the amount of
                           // returned change in pennies
    int dollar_q;          // An integer variable denotes the quantities of
                           // dollar denomination
    int quarter_q;         // An integer variable denotes the quantities of
                           // quarter denomination
    int dime_q;            // An integer variable denotes the quantities of
                           // dime denomination
    int nickel_q;          // An integer variable denotes the quantities of
                           // nickel denomination
    int penny_q;           // An integer variable denotes the quantities of
                           // penny denomination


    //Input: Users enter the amount of all total purchase and the amount of
    //       total payments
    cout << "Enter purchase amount: " << endl;
    cin >> purchase_amount;
    cout << "Enter amount received: " << endl;
    cin >> amount_received;


    //Processing: First subtract the purchase amount from the received amount,
    //            then convert the difference into pennies. Note through the
    //            coversion, the type of variable "change" transfroms from
    //            the float to the integer, and it is transfromed by a static_
    //            cast. Also 0.5 is added to the float variable "change" for
    //            forcing the float point number to be rounded to the nearest
    //            integer.
    //            Quantities of dollar is calculated by dividing the amount of
    //            change in pennies into 100;
    //            Dividing the remainder of dollar quantity calculation into 25
    //            to get the quantities of quarter;
    //            Dividing the remainder of quarter quantity calculation into
    //            10 to get the quantities of dime;
    //            Dividing the remainder of dime quantity calculation into 5 to
    //            get the quantities of nickel;
    //            The remainder of nickel quantity calculation is the quantities
    //            of penny.
    change            = amount_received - purchase_amount;
    change_in_pennies = static_cast<int>(change*100 + 0.5);
    dollar_q          = change_in_pennies / 100;
    quarter_q         = (change_in_pennies % 100) / 25;
    dime_q            = ((change_in_pennies % 100) % 25) / 10;
    nickel_q          = (((change_in_pennies % 100) % 25) % 10) / 5;
    penny_q           = ((((change_in_pennies % 100) % 25) % 10) % 5);


    //Output: The amount of change returned to customers is the output along
    //        with the quantities of dollar denomination, quarter denomination,
    //        dime denomination, nickel denomination, and penny denominatino.
    cout << "Total Change: $" << change << endl;
    cout << "\n";
    cout << "dollars " << dollar_q << endl;
    cout << "quarters " << quarter_q << endl;
    cout << "dimes " << dime_q << endl;
    cout << "nickels " << nickel_q << endl;
    cout << "pennies " << penny_q << endl;

    return 0;
}

