
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

/*******************************************************************************
 *
 * Manipulators and File IO
 *______________________________________________________________________________
 *
 * The program will read data from the file inData.txt and write output to the
 * file outData.txt.Write statements to open both of these files, associate
 * inFile with inData.txt, and associate outFile with outData.txt.
 *______________________________________________________________________________
 *
 * INPUT:
 *  inFile              : An input stream for the input file
 *
 * OUTPUT:
 *  outFile             : An output stream for the output file
 *  rectangleArea       : Area of a rectangle
 *  rectanglePerimeter  : length of the four sides of a rectangle
 *  circleArea          : Area of a circle
 *  circumference       : length of the circle line
 *  endBal              : Ending balance in the account
 *
 ******************************************************************************/

int main()
{
    //Declare variables
    ifstream inFile;            // An input stream for the input file
    ofstream outFile;           // An output stream for the output file
    double rectangleWidth;      // the width of a rectangle from input file
    double rectangleLength;     // the length of a rectangle from input file
    double rectangleArea;       // Cal & Output - represents the area of a
                                // rectangle
    double rectanglePerimeter;  // Cal & Output - represents the perimeter of a
                                // rectangle
    double circleRadius;        // the radius of a circle from input file
    double circleArea;          // Cal & Output - represents the area of a
                                // circle
    double circumference;       // Cal & Output - represents the circumference
                                // of a circle
    double pi;                  // use as a constant in calculation
    int age;                    // the age of a person from input file
    string firstName;           // the first name of a person from input file
    string lastName;            // the last name of a person from input file
    double begBal;              // the beginning balance in a saving account
                                // from input file
    double endBal;              // Cal & Output - represents the ending balance
                                // in a saving account
    double ir;                  // the interest rate per year from input file
    char ch;                    // an uppercase letter from input file


    // Initialization: set the value of pi
    pi = 3.14159;


    // Connect varialbe inFile to the file named inData.txt
    inFile.open("inData.txt");


    // Length and width of a rectangle is being read from inData.txt
    inFile >> rectangleLength >> rectangleWidth;
    // Radius of a circle is being read from inData.txt
    inFile >> circleRadius;
    // First and last name and age of a person is being read from inData.txt
    inFile >> firstName >> lastName >> age;
    // Beginning balance of a saving account is being read from inData.txt
    inFile >> begBal >> ir;
    // A upper case character is being read from inData.txt
    inFile >> ch;


    // Calculation: using width and length in inData.txt to calculate the area
    // and the perimeter of a rectangle
    rectangleArea = rectangleLength * rectangleWidth;
    rectanglePerimeter = (rectangleLength + rectangleWidth) * 2;


    // Calculation: using radius in inData.txt to calculate the area and
    // circumference of a circle
    circleArea = pi * pow(circleRadius, 2);
    circumference = 2 * pi * circleRadius;


    // Calculation: using beginning balance and interest rate in inData.txt to
    // caculate the ending balance at the end of the month
    endBal = begBal * (1 + ir / (12 * 100));


    // Connect varialbe outFile to the file named outData.txt
    outFile.open("outData.txt");


    // Writes the output data of a rectangle to the file outData.txt
    outFile << "Rectangle:" << endl;


    // Length is being sent with the decimal precision set to 2
    outFile << "Length = " << setprecision(2) << fixed << rectangleLength;


    // Width is being sent with the decimal precision set to 2
    outFile << ", width = " << setprecision(2) << fixed << rectangleWidth;


    // Area is being sent with the decimal precision set to 2
    outFile << ", area = " << setprecision(2) << fixed << rectangleArea;


    // Perimeter is being sent with the decimal precision set to 2
    outFile << ", perimeter = " << setprecision(2) << fixed
            << rectanglePerimeter;


    // Create a empty line between output in file outData.txt
    outFile << "\n" << endl;


    // Writes the output data of a rectangle to the file outData.txt
    outFile << "Circle:" << endl;


    // Radius is being sent with the decimal precision set to 2
    outFile << "Radius = " << setprecision(2) << fixed << circleRadius;


    // Area is being sent with the decimal precision set to 2
    outFile << ", area = " << setprecision(2) << fixed << circleArea;


    // Circumference is being sent with the decimal precision set to 2
    outFile << ", circumference = " << setprecision(2) << fixed
            << circumference;


    // Create a empty line between output in file outData.txt
    outFile << "\n" << endl;


    // Name and age of a person is being sent to the file outData.txt
    outFile << "Name: " << firstName << lastName << "age: " << age;


    // Beginning balance and interest rate is being sent with the decimal
    // precision set to 2
    outFile << "Beginning balance = $" << setprecision(2) << fixed << begBal
            << ", interest rate = " << setprecision(2) << fixed << ir;


    // Ending balance is being sent with the decimal precision set to 2
    outFile << "Balance at the end of the month = $" << setprecision(2) << fixed
            << endl;


    // Create a empty line between output in file outData.txt
    outFile << "\n" << endl;


    // Two uppercase characters are being sent to the file outData.txt
    outFile << "The character that comes after " << ch
            << " in the ASCII set is "
            << static_cast<char>(ch + 1);


    // Disconnect variables inFile to the file inData.txt
    inFile.close();


    // Disconnect variables outFile to the file outData.txt
    outFile.close();


    // Output rectangle data to the console
    cout << "Rectangle:" << endl;


    // Length is being output with the decimal precision set to 2
    cout << "Length = " << setprecision(2) << fixed << rectangleLength;


    // Width is being output with the decimal precision set to 2
    cout << ", width = " << setprecision(2) << fixed << rectangleWidth;


    // Area is being output with the decimal precision set to 2
    cout << ", area = " << setprecision(2) << fixed << rectangleArea;


    // Perimeter is being output with the decimal precision set to 2
    cout << ", perimeter = " << setprecision(2) << fixed
            << rectanglePerimeter;


    // Creat space in console
    cout << "\n" << endl;


    // Output circle data to the console
    cout << "Circle:" << endl;


    // Perimeter is being output with the decimal precision set to 2
    cout << "Radius = " << setprecision(2) << fixed << circleRadius;


    // Area is being output with the decimal precision set to 2
    cout << ", area = " << setprecision(2) << fixed << circleArea;


    // Circumference is being output with the decimal precision set to 2
    cout << ", circumference = " << setprecision(2) << fixed
            << circumference;


    // Create space in console
    cout << "\n" << endl;


    // Name and age are being output
    cout << "Name: " << firstName << " " << lastName << ", age: " << age
         << endl;


    // Beginning balance and interest are being output with the decimal
    // precision set to 2
    cout << "Beginning balance = $" << setprecision(2) << fixed << begBal
         << ", interest rate = " << setprecision(2) << fixed << ir << endl;


    // Ending balance and interest are being output with the decimal precision
    // set to 2
    cout << "Balance at the end of the month = $" << setprecision(2) << fixed
            << endBal;


    // Create space in console
    cout << "\n" << endl;


    // Two characters are being output
    cout << "The character that comes after " << ch << " in the ASCII set is "
         << static_cast<char>(ch + 1);
    cout << endl;


    return 0;
}
