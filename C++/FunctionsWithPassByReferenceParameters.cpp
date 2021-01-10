
 #include <iostream>
 #include <iomanip>
 #include <fstream>
 #include <string>
 using namespace std;
/*******************************************************************************
 *
 * FUNCTIONS WITH PASS BY REFERENCE PARAMETERS
 *______________________________________________________________________________
 * This program has two exercises. Ex1 reads from an input file named
 * numbers.dat, and returns the largest integer, the smallest integer, and the
 * average of integers in the file; ex2 reads from a file that the input file
 * name is entered by users. If the input file is open successfully, then ex2
 * returns the largest integer, smallest integer, and the average of integers
 * in the file. Otherwise, ex2 outputs an error message to indicate the failure
 * of open.
 *______________________________________________________________________________
 *
 * INPUT:
 *  ex          : the exercise users choose to run
 *  fileName    : the name of the input file entered by users
 *
 * OUTPUT:
 *  largest     : the maximum integer in input file
 *  smallest    : the minimum integer in input file
 *  avg         : the average of all integers in input file
 *
 ******************************************************************************/


/*******************************************************************************
 * exercise1
 *  This function takes in four parameters named &smallest, &largest, &ave, and
 *  fileName, reads from the input file, then outputs the minimum and maximum
 *  integer, and the average of all integers in the input file
 *  - returns nothing → outputs the minimum and maximum integer and the average
 ******************************************************************************/
void exercise1(int &smallest,       // REF - the minimum integer
               int &largest,        // REF - the maximum integer
               double &avg,         // REF - the average of integers
               string fileName);    // A string variable stores the file name


/*******************************************************************************
 * exercise2
 *  This function takes in four parameters named phrase, &smallest, &largest,
 *  &avg, and fileName. It first receives an input file name from users and
 *  checks whether the input file is opened successfully before reading from the
 *  file. If the file is not opened successfully, the function returns false. If
 *  the file is opened successfully, the function returns the minimum and
 *  maximum integer, and the average of integers in the file, and return false.
 *  - returns true if open file successfully or false if fail to open file,
 *    and outputs the minimum and maximum integer and the average
 ******************************************************************************/
bool exercise2(int &smallest,       // REF - the minimum integer
               int &largest,        // REF - the maximum integer
               double &avg,         // REF - the average of integers
               string fileName);    // IN  - the file name entered by users


int main()
{
    // Declare variables
    int ex;                         // IN - the exercise choice input from users
    int smallest;                   // OUT- the minimum integer in input file
    int largest;                    // OUT- the maximum integer in input file
    string fileName;                // IN - the input file name entered by users
    double avg;                     // CALC & OUT- the average of integers


    // Input: users` choice of exercise is input from users
    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;


    // Proc: when exercise 1 is chosen
    if (ex == 1)
    {
        // Calling: exercise1 function is being invoked
        exercise1(smallest, largest, avg, fileName);


        // Output: the minimum integer, maximum integer, and average of integers
        cout << "The min is: " << smallest << endl;
        cout << "The max is: " << largest << endl;
        cout << "The average is: " << avg << endl;
    }


    // Proc: when exercise 2 is chosen
    else if (ex == 2)
    {
        // Input: a file name is input from users
        cout << "Enter the name of the file: ";
        cin >> fileName;
        cout << endl;


        // Proc: when exercise2 function returns true
        if (exercise2(smallest, largest, avg, fileName) == true)
        {
            // Calling: exercise1 function is being invoked
            exercise2(smallest, largest, avg, fileName);


            // Output: the maximum integer, minimum integer, and average of
            // integers
            cout << "The max number is: " << largest << endl;
            cout << "The min number is: " << smallest << endl;
            cout << "The average is: " << avg << endl;
        }


        // Proc: when exercise2 function returns false
        else
        {
            // Output: output the error message to indicate the failure of file
            // opening
            cout << "Cannot open the file!" << endl;
        }
    }
    return 0;
 }


/*******************************************************************************
 *
 * FUNCTION exercise1
 * _____________________________________________________________________________
 * This function takes in four parameters named &smallest, &largest, &avg and
 * fileName, reads from the input file, then returns the minimum and maximum
 * integer, and the average of all integers in the input file
 * - returns the minimum and maximum integer and the average of integers
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      &smallest: the reference value denotes the minimum integer
 *      &largest : the reference value denotes the maximum integer
 *      &avg     : the reference value denotes the average of integers
 *      fileName : the string variable stores the file name
 *
 * POST - CONDITIONS
 *  This function returns nothing and outputs the minimum and maximum integer
 *  and average
 ******************************************************************************/
void exercise1(int &smallest,       // REF - the minimum integer
               int &largest,        // REF - the maximum integer
               double &avg,         // REF - the average of integers
               string fileName)     // A string variable stores the file name


{
    // Declare variable
    ifstream inFile;            // An input stream for the input file
    ofstream outFile;           // An output stream for the output file
    int integer;                // Denotes each number in input file
    int i;                      // Counter for counting iterations
    double sum;                 // Calc & Out: sum of integers in input file


    // Initialization
    sum = 0;                    // Sum of integers is equal to zero initially
    i = 0;                      // Counters starts from 0 initially
    fileName = "numbers.dat";   // Assign file name to variable fileName


    // Connect varialbe inFile to the file named numbers.dat
    inFile.open(fileName);


    // Proc: while reading from the input file
    while (inFile >> integer)
    {
        // Proc: when counter i gets to 1
        if (i == 1)
        {
            // Proc: set the value of variable smallest and largest to the first
            // reading integer
            smallest = integer;
            largest = integer;
        }


        // Proc: when counter passes 1
        else
        {
            // Proc: change the value of variable smallest to the smaller one
            // among the previously reading integer and the currently reading
            // integer
            smallest = min(smallest, integer);


            // Proc: change the value of variable largest to the larger one
            // among the previously reading integer and the currently reading
            // integer
            largest = max(largest, integer);
        }


        // Calc & Out: sum of all reading integers
        sum += integer;


        // i increments by 1 until all integers have been read
        i++;
    }


    // Calc & Out: i divides sum to get the average of integers in input file
    avg = sum / i;


    // Disconnect variables inFile and outFile from numbers.dat
    inFile.close();
    outFile.close();
}


/*******************************************************************************
 *
 * FUNCTION exercise2
 * _____________________________________________________________________________
 *  This function takes in four parameters named &smallest, &largest, &avg, and
 *  fileName. It first receives an input file name from users and checks whether
 *  the input file is opened successfully before reading from the file. If the
 *  file is not opened successfully, the function returns false. If the file is
 *  opened successfully, the function returns the minimum and maximum integer,
 *  and the average of integers in the file, and returns true.
 *  - returns true or false, and outputs the minimum and maximum integer and
 *    the average
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      &smallest: the reference value denotes the minimum integer
 *      &largest : the reference value denotes the maximum integer
 *      &avg     : the reference value denotes the average of integers
 *      fileName : the file name entered by users
 *
 * POST - CONDITIONS
 *  This function returns true or false and outputs the minimum and maximum
 *  integer and the average
 ******************************************************************************/
bool exercise2(int &smallest,   // REF - the minimum integer
               int &largest,    // REF - the maximum integer
               double &avg,     // REF - the average of integers
               string fileName) // IN  - the file name entered by users
{
    // Declare variables
    ifstream inFile;            // An input stream for the input file
    ofstream outFile;           // An output stream for the output file
    int integer;                // Denotes each number in input file
    int i;                      // Counter for counting iterations
    double sum;                 // Calc & Out: sum of integers in input file


    // Initialization
    sum = 0;                    // Sum of integers is equal to zero initially
    i = 0;                      // Counters starts from 0 initially


    // Connect variable inFile to the file that its name is given by users
    inFile.open(fileName);


    // Proc： if successfully open the file
    if (inFile.is_open())
    {
        // Proc: while reading from the input file
        while (inFile >> integer)
        {
            // Proc: when counter i gets to 1
            if (i == 1)
            {
                // Proc: set the value of variable smallest and largest to the
                // first reading integer
                smallest = integer;
                largest = integer;
            }


            // Proc: when counter passes 1
            else
            {
                // Proc: change the value of variable smallest to the smaller
                // one among the previously reading integer and the currently
                // reading integer
                smallest = min(smallest, integer);


                // Proc: change the value of variable largest to the larger
                // one among the previously reading integer and the currently
                // reading integer
                largest = max(largest, integer);
            }


            // Calc & Out: sum of all reading integers
            sum += integer;


            // i increments by 1 until all integers have been read
            i++;
        }


        // Calc & Out: i divides sum to get the average of integers in input
        // file
        avg = sum / i;


        // Disconnect variables inFile and outFile from input file
        inFile.close();
        outFile.close();
        return true;
    }


    // // Proc： if fail to open the file
    else
    {
        return false;

        // Output: output the error message to indicate the failure of file
        // opening
        cout << "Cannot open the file!" << endl;
    }
}







