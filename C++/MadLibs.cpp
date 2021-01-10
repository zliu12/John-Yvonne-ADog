

#include<iostream>
#include<string>
using namespace std;

/*******************************************************************************
 *
 * CREATE A MADLID - FIELD TRIP
 *______________________________________________________________________________
 *
 * Users can enter 18 inputs into the program, and the program will output a
 * story based on isnputs and display the story on the screen.
 *______________________________________________________________________________
 *
 * INPUT:
 *  place_name          : users input a name of a place
 *  country_1           : users input the first name of a country
 *  country_2           : users input the second name of a country
 *  profession_1        : users input the first name of a profession
 *  profession_2        : users input the second name of a profession
 *  adjective_1         : users input the first adjective
 *  adj_1_antonym       : users input the antonym of the first adjective
 *  favorite_animal     : users input one favorite animal
 *  city_name           : users input a name of a city
 *  street_name         : users input a name of a street
 *  park_name           : users input a name of a park
 *  type_of_liquid      : users input a type of liquid
 *  animal              : users input a name of an animal
 *  adjective_3         : users input the third adjective
 *  adjective_4         : users input the fourth adjective
 *  food_1              : users input the first type of the food
 *  num                 : users input an integer
 *  food_2              : users input the second type of the food
 *
 * OUTPUT:
 *  story               : A story which is created based on the inputs
 *                        from users, as the output of the program
 *
 ******************************************************************************/

int main()
{
    //Declare constants
    const string MEASURINGSTICK(80, '_'); // Measure and part line


    //Declare variables with data table
    string place_name;      // User input of a place`s name
    string country_1;       // User input of a country`s name
    string country_2;       // User input of another country`s name
    string profession_1;    // User input of a type of job
    string profession_2;    // User input of another type of job
    string adjective_1;     // User input of an adjective
    string adj_1_antonym;   // User input of an antonym of adjective_1
    string favorite_animal; // User input of an favorite animal
    string city_name;       // User input of a city`s name
    string street_name;     // User input of a street`s name
    string park_name;       // User input of a park`s name
    string type_of_liquid;  // User input of a liquid`s name
    string animal;          // User input of an animal`s name
    string adjective_3;     // User input of a third adjective
    string adjectvie_4;     // User input of a fourth adjective
    string body_part;       // User input of a name of a body part
    string food_1;          // User input of a food`s name
    string num;             // User input of an integer
    string food_2;          // User input of another food`s name


    //Output - Display Header Information
    cout << "***************************************************************\n";
    cout << "         Programmed by: Zhao Liu\n";
    cout << "         Student ID   : 00962612\n";
    cout << "         CS002        : MW 9:45 - 11:50am TuTh 9:45 -11:10am\n";
    cout << "         Assignment#1 : Madlibs\n";
    cout << "***************************************************************\n";


    //Input: get the inputs from users to create a story
    cout << "\n Please enter a place: \n" << " ";
    cin >> place_name;

    cout << "\n Please enter a country: \n" << " ";
    cin >> country_1;

    cout << "\n Please enter another country: \n" << " ";
    cin >> country_2;

    cout << "\n Please think of a profession: \n" << " ";
    cin >> profession_1;

    cout << "\n Please think of another profession: \n" << " ";
    cin >> profession_2;

    cout << "\n Please enter an adjective: \n" << " ";
    cin >> adjective_1;

    cout << "\n Please enter the antonym of the adjective you just entered: \n";
    cout << " ";
    cin >> adj_1_antonym;

    cout << "\n What`s your favorite animal: \n" << " ";
    cin >> favorite_animal;

    cout << "\n Please think of a city: \n" << " ";
    cin >> city_name;

    cout << "\n Please think of a street name: \n" << " ";
    cin >> street_name;

    cout << "\n Please think of a park name: \n" << " ";
    cin >> park_name;

    cout << "\n Please enter a type of liquid: \n" << " ";
    cin >> type_of_liquid;

    cout << "\n Please enter the name of an animal: \n" << " ";
    cin >> animal;

    cout << "\n Please enter an adjective again: \n" << " ";
    cin >> adjective_3;

    cout << "\n Please enter anther adjective again: \n" << " ";
    cin >> adjectvie_4;

    cout << "\n Please think of a kind of food: \n" << " ";
    cin >> food_1;

    cout << "\n Please think of another kind of food: \n" << " ";
    cin >> food_2;

    cout << "\n Please enter a positive integer: \n" << " ";
    cin >> num;

    cout << "\n Please enter the name of a body part: \n" << " ";
    cin >> body_part;


    //Output: create and display the story based on inputs from users
    cout << "\n" << MEASURINGSTICK << "\n";


    //First paragrah
    cout << "\t";
    cout << "A field trip or excursion is a journey by a group of people to a "
         << "place,\n";
    cout << "like the " << place_name << ", away from their normal "
         << "environment. When done for students,\n";
    cout << "it is also known as school trip in " << country_1 << " or "
         << country_2 << ", Lakbay Aral in\n";
    cout << "the Philippines, Ensoku (Excursion) in Japan and Klassenfahrt in "
         << "Germany.\n";
    cout << "\n";


    //Second paragrah
    cout << "\t";
    cout << "The purpose of the trip is usually observation for education,"
         << " non -\n";
    cout << "experimental research or to provide students with experiences "
         << "outside their\n";
    cout << "everyday activities, such as going camping with " << profession_1
         << " and "<< profession_2 << ". It\n";
    cout << "is seen that " << adjective_1 << " " << profession_1 << " may have"
         << " already experienced cultural\n";
    cout << "institutions outside of the school, and field trips provide a "
         << "a common ground\n";
    cout << "that " << profession_1 << " and " << adj_1_antonym << " "
         << profession_2 << " can have some of the same cultural\n";
    cout << "experiences in the arts.\n";
    cout << "\n";



    //Third paragraph
    cout << "\t";
    cout << "Zoo is one of the most " << adjective_3 << " idea for a field "
         << "trip. It`s a place\n";
    cout << "where wild " << favorite_animal << " is(are) kept in pens or "
         << "cages. There are two zoos in\n";
    cout << city_name << ", one on the " << street_name << " street and one "
         << "in the " << park_name << " park. The\n";
    cout << "park zoo is built around a large pond filled with clear "
         << "sparkling " << type_of_liquid << ".\n";
    cout << "You will see several " << animal << " swimming in the pond and "
         << "eating fish. When it\n";
    cout << "is feeding time, all of the animals make " << adjectvie_4
         <<" noises. In one part of the\n";
    cout << "zoo, there are " << adjectvie_4 << " gorillas who love to eat "
         << food_1 << ". But my favorite\n";
    cout << "animal is the " << favorite_animal << ". It has a huge "
         << body_part << " and eats " << num << " pounds\n";
    cout << "of " << food_2 << " a day.\n";


    cout << "\n" << MEASURINGSTICK << "\n";


    return 0;
}

