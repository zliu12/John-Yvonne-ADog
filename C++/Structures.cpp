
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<string>
#include<cctype>
#include<vector>
#include<ctime>
#include<cmath>
using namespace std;
/*******************************************************************************
 *
 * Movie Data
 *______________________________________________________________________________
 *
 * The program will use structure to store the data of movies. There are three
 * methods of storing the data into the structure. The first is hard coded, the
 * second is input by the user, and the third is read from the input file
 *______________________________________________________________________________
 *
 * INPUT:
 *  movie_userInput.title           : The movie title input from the user
 *  movie_userInput.director        : The movie director input from the user
 *  movie_userInput.year_released   : The released year of the movie input from
 *                                    the user
 *  movie_userInput.running_time    : The running time of the movie input from
 *                                    the user
 *  inFile                          : An input stream from the input file
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


// Declare Structure
struct MovieData
{
    // Declare variables
    string title;                           // The tile of the movie
    string director;                        // The director of the movie
    string year_released;                   // The released year of the movie
    string running_time;                    // The running time of the movie
};


/*******************************************************************************
 * printMovieData
 *  This function accepts one parameter named &m, it returns nothing but outputs
 *  the movie data to the screen
 *  - returns nothing but outputs the movie data
 ******************************************************************************/
void printMovieData(const MovieData &m);    // The struct variable contains
                                            // movie data

int main()
{
    // Declare variables
    const int movie_total = 12;             // Const - The size of array
    ifstream inFile;                        // In - input stream from input file
    MovieData movie_hardCoded;              // First method of storing movie
                                            // data
    MovieData movie_userInput;              // Second method of storing movie
                                            // data
    MovieData movie_array[movie_total];     // The movie array with 12 different
                                            // movie structure variables
    string title_fileRead;                  // In - movie tile from input file
    string director_fileRead;               // In - movie director from input
                                            //      file
    string year_released_fileRead;          // In - movie released year from
                                            //      input file
    string running_time_fileRead;           // In - movie running time from
                                            //      input file


    // Proc: assign values to variables in movie_hardCoded
    movie_hardCoded.title = "Apollo 13";
    movie_hardCoded.director = "Ron Howard";
    movie_hardCoded.year_released = "1995";
    movie_hardCoded.running_time = "140";


    // Input: prompt the user to input the title, director, released year and
    // running time in min of the movie they input
    cout << "Enter Title: " << endl;
    getline(cin, movie_userInput.title);
    cout << "Enter Director: " << endl;
    getline(cin, movie_userInput.director);
    cout << "Enter Year Released: " << endl;
    cin >> movie_userInput.year_released;
    cout << "Enter Running Time (in minutes): " << endl;
    cin >> movie_userInput.running_time;


    // Connect variable inFile to the given file
    inFile.open("movies.txt");


    // Proc: use loop to store data into each structures in movie array
    for (int i = 0; i < movie_total; i++)
    {
        // Branch: when store data into first structure in movie array
        if (i == 0)
        {
            // Proc: assign corresponding movie_hardcoded values to movie_array
            movie_array[i].title = movie_hardCoded.title;
            movie_array[i].director = movie_hardCoded.director;
            movie_array[i].year_released = movie_hardCoded.year_released;
            movie_array[i].running_time = movie_hardCoded.running_time;
        }


        // Branch: when store data into second structure in movie array
        else if (i == 1)
        {
            // Proc: assign corresponding movie_userInput values to movie_array
            movie_array[i].title = movie_userInput.title;
            movie_array[i].director = movie_userInput.director;
            movie_array[i].year_released = movie_userInput.year_released;
            movie_array[i].running_time = movie_userInput.running_time;
        }


        // Branch: when store data into the rest structures in movie array
        else if (i > 1)
        {
            // Proc: reading movie data from the input file
            getline(inFile, title_fileRead);
            getline(inFile, director_fileRead);
            getline(inFile, year_released_fileRead);
            getline(inFile, running_time_fileRead);
            inFile.ignore(10000, '\n');


            // Proc: assign corresponding data values to structures in movie
            // array
            movie_array[i].title = title_fileRead;
            movie_array[i].director = director_fileRead;
            movie_array[i].year_released = year_released_fileRead;
            movie_array[i].running_time = running_time_fileRead;
        }
    }


    // Proc: loop to display the content in movie array
    for (int i = 0; i < movie_total; i++)
    {
        // Invocation: call function printMovieData to output the result
        printMovieData(movie_array[i]);
        cout << endl;
    }
    return 0;
}


/*******************************************************************************
 *
 * FUNCTION printMovieData
 * _____________________________________________________________________________
 *  This function accepts one parameter named &m, it returns nothing but outputs
 *  the movie data to the screen
 *  - returns nothing but outputs the movie data
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      m: the structure variables contains four other variables which are title
 *         , director, year_released, and running_time
 *
 * POST - CONDITIONS
 *  This function will output the data of a movie
 ******************************************************************************/
void printMovieData(const MovieData &m)
{
    cout << "Title: " << m.title << endl;
    cout << "Director: " << m.director << endl;
    cout << "Year released: " << m.year_released << endl;
    cout << "Running Time: " << m.running_time << endl;
}
