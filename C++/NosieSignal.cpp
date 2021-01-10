
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
 * NOISE SIGNALS
 *______________________________________________________________________________
 * This program has 4 parts. Part1(p1) creats two sequences with 100 or 10000
 * random floating-point values between 4 and 10, then compares the practical
 * mean and variance to the theoretical values (using the given formulas).
 * Part2(p2) creats two sequences with 500 points. Both have a theoretical mean
 * of 4, but one has a variance of 0.5 and the other one has 2. Part2 compares
 * the pratical mean and variacne to the theoretical values. Part3(p3) has two
 * 500 - point sequences that both have a variance of 3.0. One has a mean of 0.0
 * and the other one has -4.0. Part3(p3) compares the pratical mean and variance
 * to the theorectical values. Part4(p4) takes in values of mean and variance
 * from the user, calculates the limit A and B, and generates a random value
 * between the limit A and B. Part4 returns a randon value and outpus the limits
 * A and B.
 *______________________________________________________________________________
 *
 * INPUT:
 *  p4_desiredMean  : a specified mean input from the user
 *  p4_desiredVar   : a specified variance input from the user
 *
 * OUTPUT:
 *  p1_pracMean1    : the practical mean of the part1 100-point sequence
 *  p1_pracMean2    : the practical mean of the part1 10000-point sequence
 *  p1_pracVar1     : the practical variance of the part1 10000-point sequence
 *  p1_pracVar2     : the practical variance of the part1 10000-point sequence
 *  p1_theoMean     : the part1 theoretical mean
 *  p1_theoVar      : the part1 theoretical variance
 *  p2_limitA1      : the part2 rand sequence 1 lower limit
 *  p2_limitB1      : the part2 rand sequence 1 upper limit
 *  p2_limitA2      : the part2 rand sequence 2 lower limit
 *  p2_limitB2      : the part2 rand sequence 2 upper limit
 *  p2_pracMean1    : the pratical mean of the part2 sequence 1
 *  p2_pracMean2    : the pratical mean of the part2 sequence 2
 *  p2_pracVar1     : the pratical variance of the part2 sequence 1
 *  p2_pracVar2     : the pratical variance of the part2 sequence 2
 *  p3_limitA1      : the part3 rand sequence 1 lower limit
 *  p3_limitB1      : the part3 rand sequence 1 upper limit
 *  p3_limitA2      : the part3 rand sequence 2 lower limit
 *  p3_limitB2      : the part3 rand sequence 2 upper limit
 *  p3_pracMean1    : the pratical mean of the part3 sequence 1
 *  p3_pracMean2    : the pratical mean of the part3 sequence 2
 *  p3_pracVar1     : the pratical mean of the part3 sequence 1
 *  p3_pracVar2     : the pratical variance of the part3 sequence 2
 *  p4_randFpVal    : the rand value generated in part4
 *
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
 * theoMean
 *  This function takes in two double parameters named a and b as the limits,
 *  and then returns the theoretical mean of the sequence
 *  - returns theoretical mean
 ******************************************************************************/
double theoMean(double a,           // Floor value of a random sequence number
                double b);          // Ceiling value of a random sequence number


/*******************************************************************************
 * theoVar
 *  This function takes in two double parameters named a and b as the limits,
 *  and then returns the theoretical variance of the sequence
 *  - returns theoretical variance
 ******************************************************************************/
double theoVar(double a,            // Floor value of a random sequence number
               double b);           // Ceiling value of a random sequence number


/*******************************************************************************
 * pracMean
 *  This function takes in two parameters named array[] and size, then returns
 *  the practial mean of a sequence with the specified limits
 *  - returns pratical mean
 ******************************************************************************/
double pracMean(double array[],     // A sequence of numbers with certain limits
                int size);          // The number of points in the sequence


/*******************************************************************************
 * pracVar
 *  This function takes in two parameters named array[] and size, then returns
 *  the practial variance of a sequence with the specified limits
 *  - returns pratical variance
 ******************************************************************************/
double pracVar(double array[],      // A sequence of numbers with certain limits
               int size);           // The number of points in the sequence


/*******************************************************************************
 * findLimitA
 *  This function takes in two parameters named theoMean and theoVar, then
 *  returns the lower limit A of a sequence
 *  - returns the lower limit A
 ******************************************************************************/
double findLimitA(double theoMean,  // The theoretical mean of a sequence
                  double theoVar);  // The theoretical variance of a sequence


/*******************************************************************************
 * rand_mv
 *  This function takes in two parameters mean and var, calculates the lower and
 *  upper limits of a sequence that`s specified with the mean and var, then
 *  return a random value within the limits using the randFloat function
 *  - returns a random value
 ******************************************************************************/
double rand_mv(double mean,         // IN - The expected mean of a sequence
               double var);         // IN - The expected variance of a sequence


int main()
{
    // Seed rand with 500
    srand(500);


    // Part1
    // Declare variables
    int p1_size1;               // The number of points of sequence1 in part1
    int p1_size2;               // The number of points of sequence2 in part1
    double p1_array1[100];      // The 100 - point sequence1 in part1
    double p1_array2[10000];    // The 10000 - point sequence2 in part1
    double p1_limitA;           // The lower limit A of the random values stored
                                // in part1 sequences
    double p1_limitB;           // The upper limit B of the random values stored
                                // in part1 sequences
    double p1_pracMean1;        // The practical mean of sequence1 in part1
    double p1_pracMean2;        // The practical mean of sequence2 in part1
    double p1_pracVar1;         // The practical variance of sequence2 in part1
    double p1_pracVar2;         // The practical variance of sequence2 in part1
    double p1_theoMean;         // The theoretical mean of part1 sequences
    double p1_theoVar;          // The theoretical variance of part1 sequences


    // Initiliazation
    p1_limitA = 4;              // Set part1 lower limit A to 4
    p1_limitB = 10;             // Set part1 upper limit B to 10
    p1_size1 = 100;             // Set size of variable p1_size1 to 100
    p1_size2 = 10000;           // Set size of variable p1_size2 to 10000


    // Invocation: calling function theoMean, its returning value is assigned to
    // p1_theoMean
    p1_theoMean = theoMean(p1_limitA, p1_limitB);


    // Invocation: calling function theoVar, its returning value is assigned to
    // p1_theoVar
    p1_theoVar = theoVar(p1_limitA, p1_limitB);


    // Proc: i starts from 0, increases by 1 each time the loop iterates until
    // it gets to 1 less than the p1_size1
    for (int i = 0; i < p1_size1; i++)
    {
        // Invocation: calling function randFloat, as the loop iterates, each
        // point in sequence1 is assigned a random value returned from function
        p1_array1[i] = randFloat(p1_limitA, p1_limitB);
    }


    // Invocation: calling function pracMean, its returning value is assigned
    // to p1_pracMean1
    p1_pracMean1 = pracMean(p1_array1, p1_size1);


    // Invocation: calling function pracVar, its returning value is assigned to
    // p1_pracVar1
    p1_pracVar1 = pracVar(p1_array1, p1_size1);


    // Proc: i starts from 0, increases by 1 each time the loop iterates until
    // it gets to 1 less than the p1_size2
    for (int i = 0; i < p1_size2; i++)
    {
        // Invocation: calling function randFloat, as the loop iterates, each
        // point in sequence2 is assigned a random value returned from function
        p1_array2[i] = randFloat(p1_limitA, p1_limitB);
    }


    // Invocation: calling function pracMean, its returning value is assigned to
    // p1_pracMean2
    p1_pracMean2 = pracMean(p1_array2, p1_size2);


    // Invocation: calling function pracVar, its returning value is assigned to
    // p1_pracVar2
    p1_pracVar2 = pracVar(p1_array2, p1_size2);


    // Output: output the theoretical mean, practical mean, theoretical variance
    // and practical variance of the sequence1 & 2 in part1
    cout << p1_theoMean << " " << p1_pracMean1 << " "
         << p1_theoVar << " " << p1_pracVar1
         << endl;
    cout << p1_theoMean << " " << p1_pracMean2 << " "
         << p1_theoVar << " " << p1_pracVar2
         << endl;
    cout << endl;


    // Part 2
    // Declare variable
    int p2_size;                // The number of points of sequences in part2
    double p2_theoMean;         // The theoretical mean of part2 sequences
    double p2_theoVar1;         // The theoretical variance of part2 sequence1
    double p2_theoVar2;         // The theoretical variance of part2 sequence2
    double p2_array1[500];      // The 500 - point sequence1 in part2
    double p2_array2[500];      // The 500 - point sequence2 in part2
    double p2_limitA1;          // The lower limit A of the random values stored
                                // in part2 sequence1
    double p2_limitB1;          // The upper limit B of the random values stored
                                // in part2 sequence1
    double p2_limitA2;          // The lower limit A of the random values stored
                                // in part2 sequence2
    double p2_limitB2;          // The upper limit B of the random values stored
                                // in part2 sequence2
    double p2_pracMean1;        // The practical mean of sequence1 in part2
    double p2_pracMean2;        // The practical mean of sequence2 in part2
    double p2_pracVar1;         // The practical variance of sequence1 in part2
    double p2_pracVar2;         // The practical variance of sequence2 in part2

    // Initiliazation
    p2_size = 500;              // Set size of variable p2_size to 500
    p2_theoMean = 4;            // Set part2 theoretical mean to 4
    p2_theoVar1 = 0.5;          // Set part2 sequence1 theoretical variance to
                                // 0.5
    p2_theoVar2 = 2.0;          // Set part2 sequence2 theoretical variance to
                                // 2.0


    // Invocation: calling function findLimitA and assigns the returned value to
    // p2_limitA1
    p2_limitA1 = findLimitA(p2_theoMean, p2_theoVar1);


    // Calc & out: calculate p2_limitB1 using p2_limitA1 and p2_theoMean
    p2_limitB1 = 2 * p2_theoMean - p2_limitA1;


    // Proc: i starts from 0, increases by 1 each time the loop iterates until
    // it gets to 1 less than the p2_size
    for (int i = 0; i < p2_size; i++)
    {
        // Invocation: calling function randFloat, as the loop iterates, each
        // point in sequence1 is assigned a random value returned from function
        p2_array1[i] = randFloat(p2_limitA1, p2_limitB1);
    }


    // Invocation: calling function pracMean and assigns its returned value to
    // p2_pracMean1
    p2_pracMean1 = pracMean(p2_array1, p2_size);



    // Invocation: calling function pracVar and assigns its returned value to
    // p2_pracVar1
    p2_pracVar1 = pracVar(p2_array1, p2_size);


    // Invocation: calling function findlimitA and assigns its returned value to
    // p2_limitA2
    p2_limitA2 = findLimitA(p2_theoMean, p2_theoVar2);


    // Calc & out: calculate p2_limitB2 using p2_limitA2 and p2_theoMean
    p2_limitB2 = 2 * p2_theoMean - p2_limitA2;


    // Proc: i starts from 0, increases by 1 each time the loop iterates until
    // it gets to 1 less than the p2_size
    for (int i = 0; i < p2_size; i++)
    {
        // Invocation: calling function randFloat, as the loop iterates, each
        // point in sequence2 is assigned a random value returned from function
        p2_array2[i] = randFloat(p2_limitA2, p2_limitB2);
    }


    // Invocation: calling function pracMean and assigns its returned value to
    // p2_pracMean2
    p2_pracMean2 = pracMean(p2_array2, p2_size);


    // Invocation: calling function pracVar and assigns its returned value to
    // p2_pracVar2
    p2_pracVar2 = pracVar(p2_array2, p2_size);


    // Output: output the theoretical mean, practical mean, theoretical variance
    // and practical variance of the sequence1 & 2 in part2
    cout << p2_theoMean << " " << p2_pracMean1 << " "
         << p2_theoVar1 << " " << p2_pracVar1
         << endl;
    cout << p2_theoMean << " " << p2_pracMean2 << " "
         << p2_theoVar2 << " " << p2_pracVar2
         << endl;
    cout << endl;


    // Part 3
    // Declare variables
    double p3_theoVar;          // The theoretical variance of part3 sequences
    double p3_theoMean1;        // The theoretical mean of part3 sequence1
    double p3_theoMean2;        // The theoretical mean of part3 sequence2
    double p3_array1[p2_size];  // The part3 sequence1 with p2_size numbers of
                                // points
    double p3_array2[p2_size];  // The part3 sequence1 with p2_size numbers of
                                // points
    double p3_limitA1;          // The lower limit A of the random values stored
                                // in part3 sequence1
    double p3_limitB1;          // The upper limit B of the random values stored
                                // in part3 sequence1
    double p3_limitA2;          // The lower limit A of the random values stored
                                // in part3 sequence2
    double p3_limitB2;          // The upper limit B of the random values stored
                                // in part3 sequence2
    double p3_pracMean1;        // The practical mean of part3 sequence1
    double p3_pracMean2;        // The practical mean of part3 sequence2
    double p3_pracVar1;         // The practical variance of part3 sequence1
    double p3_pracVar2;         // The practical variance of part3 sequence2


    // Initialization
    p3_theoVar = 3.0;           // Set part3 theoretical variance to 3.0
    p3_theoMean1 = 0.0;         // Set part3 sequence1 theoretical mean to 0.0
    p3_theoMean2 = -4.0;        // Set part3 sequence2 theoretical mean to -4.0


    // Invocation: calling function findlimitA and assigns its returned value to
    // p3_limitA1
    p3_limitA1 = findLimitA(p3_theoMean1, p3_theoVar);


    // Calc & out: calculate p3_limitB1 using p3_limitA1 and p3_theoMean1
    p3_limitB1 = 2 * p3_theoMean1 - p3_limitA1;


    // Proc: i starts from 0, increases by 1 each time the loop iterates until
    // it gets to 1 less than the p2_size
    for (int i = 0; i < p2_size; i++)
    {
        // Invocation: calling function randFloat, as the loop iterates, each
        // point in sequence3 is assigned a random value returned from function
        p3_array1[i] = randFloat(p3_limitA1, p3_limitB1);
    }


    // Invocation: calling function pracMean and assigns its returned value to
    // p3_pracMean1
    p3_pracMean1 = pracMean(p3_array1, p2_size);


    // Invocation: calling function pracVar and assigns its returned value to
    // p3_pracVar1
    p3_pracVar1 = pracVar(p3_array1, p2_size);


    // Invocation: calling function findlimitA and assigns its returned value to
    // p3_limitA2
    p3_limitA2 = findLimitA(p3_theoMean2, p3_theoVar);


    // Calc & out: calculate p3_limitB1 using p3_limitA2 and p3_theoMean2
    p3_limitB2 = 2 * p3_theoMean2 - p3_limitA2;


    // Proc: i starts from 0, increases by 1 each time the loop iterates until
    // it gets to 1 less than the p2_size
    for (int i = 0; i < p2_size; i++)
    {
        // Invocation: calling function randFloat, as the loop iterates, each
        // point in sequence2 is assigned a random value returned from function
        p3_array2[i] = randFloat(p3_limitA2, p3_limitB2);
    }


    // Invocation: calling function pracMean and assigns its returned value to
    // p3_pracMean2
    p3_pracMean2 = pracMean(p3_array2, p2_size);


    // Invocation: calling function pracVar and assigns its returned value to
    // p3_pracVar2
    p3_pracVar2 = pracVar(p3_array2, p2_size);


    // Output: output the theoretical mean, practical mean, theoretical variance
    // and practical variance of the sequence1 & 2 in part3
    cout << p3_theoMean1 << " " << p3_pracMean1 << " "
         << p3_theoVar << " " << p3_pracVar1
         << endl;
    cout << p3_theoMean2 << " " << p3_pracMean2 << " "
         << p3_theoVar << " " << p3_pracVar2
         << endl;
    cout << endl;


    // Part 4
    // declare variable
    double p4_desiredMean;      // IN - the expected mean of sequences in part4,
                                //      input from the user
    double p4_desiredVar;       // IN - the expected variance of sequences in
                                //      part4, input from the user
    double p4_randFpVal;        // Out- a random value generated by rand_mv
                                //      function using p4_desiredMean and
                                //      p4_desiredVar


    // Input: prompt the user their expected mean and variance of sequences, and
    // store the numbers in p4_desiredMean, p4_desiredVar
    cout << "Enter Mean: ";
    cin >> p4_desiredMean;
    cout << endl;
    cout << "Enter Variance: ";
    cin >> p4_desiredVar;
    cout << endl;


    // Invocation: calling function rand_mv and assigns its returned value to
    // p4_randFpVal
    p4_randFpVal = rand_mv(p4_desiredMean, p4_desiredVar);


    // Output: output the value of p4_randFpVal
    cout << p4_randFpVal << endl;


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
 * FUNCTION theoMean
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
double theoMean(double a,           // Floor value of a random sequence number
                double b)           // Ceiling value of a random sequence number
{
    // Return: the theoretical mean
    return ((a + b) / 2);
}


/*******************************************************************************
 *
 * FUNCTION theoVar
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
double theoVar(double a,            // Floor value of a random sequence number
               double b)            // Ceiling value of a random sequence number
{
    // Return: the theoretical variance
    return ((pow((b - a), 2)) / 12);
}


/*******************************************************************************
 *
 * FUNCTION pracMean
 * _____________________________________________________________________________
 *  This function takes in two parameters named array[] and size, then returns
 *  the practial mean of a sequence with the specified limits
 *  - returns pratical mean
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      array[] : the sequence contains a number of points
 *      size    : the number of points in a squence
 *
 * POST - CONDITIONS
 *  This function will return the pratical mean
 ******************************************************************************/
double pracMean(double array[],     // A sequence of numbers with certain limits
                int size)           // The number of points in the sequence
{
    // Declare variable
    double sum;                     // Sum of points in a sequence


    // Initialization
    sum = 0;                        // Set sum to 0


    // Proc: i starts from 0, increases by 1 each time the loop iterates until
    // it gets to 1 less than the value of size
    for (int i = 0; i < size; i++)
    {
        // Calc: add up all values of points in sequence
        sum += array[i];
    }


    // Return: return the mean by dividing sum with size
    return sum / size;
}


/*******************************************************************************
 *
 * FUNCTION pracVar
 * _____________________________________________________________________________
 *  This function takes in two parameters named array[] and size, then returns
 *  the practial variance of a sequence with the specified limits
 *  - returns pratical variance
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      array[] : the sequence contains a number of points
 *      size    : the number of points in a squence
 *
 * POST - CONDITIONS
 *  This function will return the pratical variance
 ******************************************************************************/
double pracVar(double array[],      // A sequence of numbers with certain limits
               int size)            // The number of points in the sequence
{
    // Declare variable
    double m;                       // A double variable stores the returned
                                    // value of function pracmean
    double sumSqDiff;               // The sum of square of difference between
                                    // each point and the mean of the sequence

    // Initialization
    sumSqDiff = 0;                  // Set sum of square of difference to 0


    // Invocation: calling function pracMean and assigns its returned value to
    // m
    m = pracMean(array, size);


    // Proc: i begins from 0, increases 1 each time the loop iterates until it
    // gets to 1 less than the value of variable size
    for (int i = 0; i < size; i++)
    {
        // Calc: compute sumSqDiff by squaring the difference between m and each
        // point in sequence
        sumSqDiff += pow((array[i] - m), 2);
    }


    // Return: return the variance by dividing sumSqDiff by size
    return sumSqDiff / size;
}


/*******************************************************************************
 *
 * FUNCTION findLimitA
 * _____________________________________________________________________________
 *  This function takes in two parameters named theoMean and theoVar, then
 *  returns the lower limit A of a sequence
 *  - returns the lower limit A
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      theoMean: the theoretical mean of a sequence
 *      theoVar : the theoretical variance of a sequence
 *
 * POST - CONDITIONS
 *  This function will return the lower limit A
 ******************************************************************************/
double findLimitA(double theoMean,  // The theoretical mean of a sequence
                  double theoVar)   // The theoretical variance of a sequence
{
    // Declare variable
    double limitA;                  // Stores the value of lower limit


    // Calc: compute limitA by using the given theoretical variance function
    limitA = (2 * theoMean - sqrt(theoVar * 12)) / 2;


    // Return: return the limitA
    return limitA;
}


/*******************************************************************************
 *
 * FUNCTION rand_mv
 * _____________________________________________________________________________
 *  This function takes in two parameters mean and var, calculates the lower and
 *  upper limits of a sequence that`s specified with the mean and var, then
 *  return a random value within the limits using the randFloat function
 *  - returns a random value
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      mean: the desired mean of a sequence
 *      var : the desired variance of a sequence
 *
 * POST - CONDITIONS
 *  This function will return the lower limit A
 ******************************************************************************/
double rand_mv(double mean,         // IN - The expected mean of a sequence
               double var)          // IN - The expected variance of a sequence
{
    // Declare variable
    double p4_limitA;               // The lower limit A of part4 sequences
    double p4_limitB;               // The upper limit B of part4 sequences


    // Invocation: calling function findLimitA and assigns its returned value to
    // p4_limitA
    p4_limitA = findLimitA(mean, var);


    // Calc: compute p4_limitB by using the mean and p4_limitA
    p4_limitB = 2 * mean - p4_limitA;


    // Output: output the lower and upper limits of part4 sequences
    cout << p4_limitA << " " << p4_limitB << endl;


    // Invocation & return: calling function randFloat and its returned value is
    // the returned value of function rand_mv
    return randFloat(p4_limitA, p4_limitB);
}


