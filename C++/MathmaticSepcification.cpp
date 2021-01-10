
#include<iostream>
#include<cmath>
using namespace std;

/*******************************************************************************
 *
 * MATHEMATICS SPECIFICATION
 *______________________________________________________________________________
 *
 * This program implements several mathematical operations with a provided list,
 * including simple mathematics and geometric equations. When users enter the
 * choice of mathematical operation and input the number values, the program
 * will perform the corresponding mathematical calculation and output the
 * result or a specific error message if there is no solution.
 *______________________________________________________________________________
 *
 * INPUT:
 *  user_op               : Mathematical operation choice of users, input from
 *                          users
 *  num_input1            : First number received for mathematical operations,
 *                          input from users
 *  num_input2            : Second number received for mathematical operations,
 *                          input from users
 *  num_input3            : Third number received for mathematical operations,
 *                          input from users
 *
 * OUTPUT:
 *  quadratic_discriminant: A number tells whether a quadratic equation has two
 *                          solutions, one solution, or no solutions, calculated
 *                          based on numberical inputs from users
 *  quadratic_x1          : A solution for a quadratic equation, calculated
 *                          based on numeric values input from users
 *  quadratic_x2          : A solution for a quadratic equation, calculated
 *                          based on numeric values input from users
 *  quadratic_x3          : A solution for a quadratic equation, calculated
 *                          based on numeric values input from users
 *  sqrt_output           : The square root of first numeric value input from
 *                          users
 *  fabs_output           : The absolute value of first numeric input from
 *                          users
 *  sum_output            : The sum of first and second numeric inputs from
 *                          users
 *  quotient_output       : The quotient of first and second numeric inputs
 *                          from users
 *  difference_output     : The difference of first and second numeric inputs
 *                          from users
 *  product_output        : The product of first and second numeric inputs from
 *                          users
 *  pythagorean_output    : The square root of adding the square of first
 *                          numeric input and second numeric input from users
 *
 ******************************************************************************/

int main()
{
    // Declare variables
    string user_op;                 // INPUT - users choose which mathematical
                                    //         operation to run
    float num_input1;               // INPUT - the first numeric value used for
                                    //         calculations
    float num_input2;               // INPUT - the second numeric value used for
                                    //         calculations
    float num_input3;               // INPUT - the third numeric value used for
                                    //         calculations
    float quadratic_discriminant;   // CALC & OUT - using quadratic formula:
                                    //              b^2 - 4ac to check how many
                                    //              solutions a quadratic
                                    //              equation has
    float quadratic_x1;             // CALC & OUT - a quadratic solution by
                                    //              solving quadratic equation
    float quadratic_x2;             // CALC & OUT - a quadratic solution by
                                    //              solving quadratic equation
    float quadratic_x3;             // CALC & OUT - a quadratic solution by
                                    //              solving quadratic equation
    float sqrt_output;              // CALC & OUT - square root soluion by
                                    //              taking the square root of
                                    //              the first number input
    float fabs_output;              // CALC & OUT - absolute value by taking
                                    //              the absolute value of the
                                    //              first number input
    float sum_output;               // CALC & OUT - sum by adding the first and
                                    //              second number inputs
    float quotient_output;          // CALC & OUT - quotient by dividing the
                                    //              first number input by the
                                    //              second number input
    float difference_output;        // CALC & OUT - difference by subracting the
                                    //              second number input from the
                                    //              first number input
    float multiplication_output;    // CALC & OUT - product by the first and
                                    //              second number inputs
    float pythagorean_output;       // CALC & OUT - solution by calculating with
                                    //              the first and second number
                                    //              the and pythagorean theorem


    // Input: user enters the choice of mathematical operation
    cout << "Please choose an operation: " << endl;
    cin >> user_op;


    // Processing: depends on user`s choice of mathematical operation,
    //             corresponding branch will be processed
    if (user_op == "sqrt" || user_op == "fabs" ||
        user_op == "addition" || user_op == "division" ||
        user_op == "quadratic" || user_op == "subtraction" ||
        user_op == "multiplication" || user_op == "pythagorean")
    {
        // Input: user enters the first number
        cout << "Enter your first number: " << endl;
        cin >> num_input1;


        // Square root branch processing: square root operation is being
        //                                processed
        if (user_op == "sqrt")
        {
            // Output: calculation equation containing the first number input
            cout << "Equation: sqrt(" << num_input1 << ")" << "\n" << endl;


            // First condition processing: calculate the square root of a
            //                             negative number
            if (num_input1 < 0)
            {
                //  Output: output the error message to explain why the
                //          operation cannot be processed
                cout << "Error: Cannot take square root of a negative number."
                     << endl;
            }


            // Second condition processing: calculate the square root of a non-
            //                              negative number
            else
            {
                // Calculation: taking the square root of the first number input
                sqrt_output = sqrt(num_input1);


                // Output: output the square root solution of the first number
                //         input
                cout << "Result: " << sqrt_output << endl;
            }
        }


        // Fabs branch processing: float point absolute value operation is being
        //                         processed
        else if (user_op == "fabs")
        {
            // Output: calculation equation containing the first number input
            cout << "Equation: fabs(" << num_input1 << ") " << "\n" << endl;


            // Calculation: find the absolute value of the first number input
            fabs_output = fabs(num_input1);


            // Output: output the absolute value of the first number input
            cout << "Result: " << fabs_output << endl;
        }
    }


    // Processing when no operation recognized: when user`s choice of operation
    //                                          is unprovided in the list
    else
    {
        // Output: output the error message explains why the operation cannt be
        //         processed
        cout << "Error: Operation not supported." << endl;
    }


    // Processing: depends on user`s choice of mathematical operation,
    //             corresponding branch will be processed
    if (user_op == "addition" || user_op == "division" ||
        user_op == "quadratic" || user_op == "subtraction" ||
        user_op == "multiplication" || user_op == "pythagorean")
    {
        // Input: user enters the second number
        cout << "Enter your second number: " << endl;
        cin >> num_input2;


        // Addition branch processing: addition operation is being processed
        if (user_op == "addition")
        {
            // Output: calculation equation containing the first and second
            //         number input
            cout << "Equation: " << num_input1 << " + " << num_input2 << "\n"
                 << endl;


            // Calculation: adding the first number input and the second number
            //              number input
            sum_output = num_input1 + num_input2;


            // Output: output the sum of adding two number inputs
            cout << "Result: " << sum_output <<endl;
        }


        // Subtraction branch processing: subtraction operation is being
        //                                prcessed
        else if (user_op == "subtraction")
        {
            // Output: calculation equation containing the first and second
            //         number inputs
            cout << "Equation: " << num_input1 << " - " << num_input2 << "\n"
                 << endl;


            // Calculation: subtrating the second number input from the first
            //              number input
            difference_output = num_input1 - num_input2;


            // Output: output the difference of first number input minus second
            //         number input
            cout << "Result: " << difference_output << endl;
        }


        // Multiplication branch processing: multiplication operation is being
        //                                   processed
        else if (user_op == "multiplication")
        {
            // Output: calculation equation containing the first and second
            //         number inputs
            cout << "Equation: " << num_input1 << " * " << num_input2 << "\n"
                 << endl;


            // Calculation: the first number input times the second number input
            multiplication_output = num_input1 * num_input2;


            // Output: output the product of the first and second number inputs
            cout << "Result: " << multiplication_output << endl;
        }


        // Division branch processing: division operation is being processed
        else if (user_op == "division")
        {
            // Output: calculation equation containing the first and second
            //         number inputs
            cout << "Equation: " << num_input1 << " / " << num_input2 << "\n"
                 << endl;


            // First condition processing: calculate when divisor is zero
            if (num_input2 == 0)
            {
                // First condition output: output the error message to explain
                //                         why the operation cannot be processed
                cout << "Error: Cannot divide by zero." << endl;
            }


            // Second condition processing: calculate when divisor is not zero
            else
            {
                // Calculation: the first number input is divided by the second
                //              number input
                quotient_output = num_input1 / num_input2;


                // Second condition output: output quotient that divides the
                //                          second number input into the first
                //                          number input
                cout << "Result: " << quotient_output << endl;
            }
        }


        // Pythagorean branch processing: pythagorean operation is being
        //                                processed
        else if (user_op == "pythagorean")
        {
            // Output: calculation equation containing the first and the second
            //         number inputs
            cout << "Equation: sqrt(" << num_input1 << "^2 + " << num_input2
                 << "^2)" << "\n" <<endl;


            // Calculation: find the square of the first number input and the
            //              square of the second number input, then sum them up,
            //              take the square root of the sum in the end
            pythagorean_output = sqrt(pow(num_input1, 2) + pow(num_input2, 2));


            // Output: output the square root of the sum of square of the first
            //         number input and the second number input
            cout << "Result: " << pythagorean_output << endl;
        }
    }


    // Quadratic branch processing: qudratic operation is being processed
    if (user_op == "quadratic")
    {
        // Input: user enters the third number
        cout << "Enter your third number: " << endl;
        cin >> num_input3;


        // Calculation: using part of the qudratic formula to find the
        //              discriminant with the first, second and third number
        //              inputs
        quadratic_discriminant = pow(num_input2, 2) - 4 * num_input1 *
                                 num_input3;


        // Output: calculation equation containing the first, second and third
        //         number input
        cout << "Equation: " << num_input1 << "x^2 + " << num_input2 << "x + "
             << num_input3 << " = 0" << "\n" << endl;


        // First condition processing: calculate when the first number input is
        //                             equal to zero or the equation is linear
        if (num_input1 == 0)
        {
            // Calculation: divide the negative third number input by the second
            //              number input
            quadratic_x3 = (-num_input3) / num_input2;


            // First condition output: output the solution when the first number
            //                         input is equal to zero
            cout << "Result: " << quadratic_x3 << endl;
        }


        // Second condition processing: calculate solution when the first number
        //                              input is not equal to zero or the
        //                              equation is quadratic
        else if (num_input1 != 0)
        {
            // First condition processing: calculate when the discriminant is
            //                             greater than zero or the quadratic
            //                             equation has two solutions
            if (quadratic_discriminant > 0)
            {
                // Calculation: with the first, second and third number inputs,
                //              using quardratic formula to find the two
                //              solutions
                quadratic_x1 = (-num_input2) + sqrt(quadratic_discriminant) /
                               (2 * num_input1);
                quadratic_x2 = (-num_input2) - sqrt(quadratic_discriminant) /
                               (2 * num_input1);


                // Output: output the two solutions of the quadratic equation
                cout << "Results: " << quadratic_x1 << ", " << quadratic_x2
                     << endl;
            }


            // Second condition processing: calculate when the discriminant is
            //                              equal than zero or the quadratic
            //                              equation only has one solution
            else if (quadratic_discriminant == 0)
            {
                // Calculation: with the first, second and third number inputs,
                //              using quardratic formula to calculate the only
                //              solution
                quadratic_x1 = (-num_input2) + sqrt(quadratic_discriminant) /
                               (2 * num_input1);


                // Output: output the only solution for the quadratic equation
                cout << "Result: " << quadratic_x1 << endl;
            }


            // Third condition processing: calculate when the discriminant is
            //                             less than zero or the quadratic
            //                             equation has no solutions
            else
            {
                // Output: output the error message to explain why the operation
                //         cannot be processed
                cout << "Error: Cannot take square root of a negative number."
                     << endl;
            }
        }
    }


    return 0;
}


