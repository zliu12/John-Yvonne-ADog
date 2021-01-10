#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<string>
#include<cctype>
#include<vector>
#include<ctime>
#include<vector>
#include<cmath>
using namespace std;
/*******************************************************************************
 *
 * Breakfast Billing System
 *______________________________________________________________________________
 * This program reads in a list of breakfast products and prices and displays to
 * customers in a restaurant menu. The customer is allowed to choose which item
 * to purchase and how many items they would like to buy. The program will
 * caculate the total spending and the tax and display on the payment receipt
 *______________________________________________________________________________
 *
 * INPUT:
 *  menuItem    : the name of items from the input file
 *  menuPrice   : the price of items from the input file
 *  &filename   : the name of the input file
 *  &a          : the vector stores items' name and price
 *  infile      : input stream from input file
 *  name        : the name of product
 *  price       : the price of items
 *  &menu       : the menu of items
 *  num         : the item number input by the user
 *  quantity    : the item quantity input by the user
 *
 * OUTPUT:
 *  itemName    : the name of items the customer orders
 *  itemQuantity: the quantity of items the customer orders
 *  itemPrice   : the price of items the customer orders
 *  order       : the vector stores item number and quantity
 ******************************************************************************/


// Declare struct
struct MenuItemType
{
    string menuItem;        // In - the name of items from the input file
    double menuPrice;       // In - the price of items from the input file
};


// Declare struct
struct Order
{
    string itemName;        // Out - the name of items the customer orders
    int itemQuantity;       // Out - the quantity of items the customer orders
    double itemPrice;       // Out - the price of items the customer orders
};


/*******************************************************************************
 * getData
 *  This function gets two reference parameters. It reads in data from the file
 *  input by users, stores the data in the vector parameter, returns and outputs
 *  nothing
 *  - returns and outputs nothing but reads in data
 ******************************************************************************/
void getData(string &filename,          // In - the name of the input file
             vector<MenuItemType> &a);  // In - the vector stores items' name
                                        //      and price


/*******************************************************************************
 * showMenu
 *  This function gets 1 reference parameters. It displays the menu and promots
 *  the user to enter the item number and quantity of their purchase, and then
 *  returns the vector stores the purchase data
 *  - outputs the menu and returns the purchase data vector
 ******************************************************************************/
vector<Order> showMenu(vector<MenuItemType> &menu); // In - the menu of items


/*******************************************************************************
 * printCheck
 *  This function gets 1 parameters. It displays the check of the current order,
 *  including the quantity and price of each item, total price before and after
 *  the tax
 *  - returns nothing but outputs the complete check
 ******************************************************************************/
void printCheck(vector<Order> order);   // Out - the vector stores the order
                                        //       data input by the user


int main()
{
    // Declare variables
    vector<MenuItemType> menuList;      // In - the vector stores the menu data
    vector<Order> orderContent;         // Out - the vector stores the order
                                        //       data
    ifstream inFile;                    // In - input stream from input file
    string fileName;                    // In - the name of input file


    // In: prompt the user to enter the file name
    cout << "Enter filename: " << endl;
    getline(cin, fileName);
    cout << endl;


    // Invocation: call function getData to store menu data into menuList vector
    getData(fileName, menuList);


    // Invocation: call function showMenu and store the function returned value
    // to the vector orderContent
    orderContent = showMenu(menuList);


    // Invocation: call function printCheck and display the order check
    printCheck(orderContent);


    return 0;
}


/*******************************************************************************
 *
 * FUNCTION getData
 * _____________________________________________________________________________
 *  This function gets two reference parameters. It reads in data from the file
 *  input by users, stores the data in the vector parameter, returns and outputs
 *  nothing
 *  - returns and outputs nothing but reads in data
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      &filename: the name of the input file
 *      &a       : the vector stores items' name and price
 *
 * POST - CONDITIONS
 *  This function will only read in data from the input file
 ******************************************************************************/
void getData(string &filename,          // In - the name of the input file
             vector<MenuItemType> &a)   // In - the vector stores items' name
                                        //      and price
{
    // Declare variables
    ifstream infile;                    // In - input stream from input file
    string name;                        // In - the name of items
    double price;                       // In - the price of items
    int sort;                           // Counter - count the number of items
                                        //           input from the input file


    // Initialization
    sort = 0;                           // Set the number of items to zero


    // Connect varialbe infile to the user input file
    infile.open(filename);


    // Proc: loop to read in data from the input file, strings before '$' stored
    // in variable name, the rest of line stored in price
    while (getline(infile, name, '$') && infile >> price)
    {
        // Store the struct to the vector
        a.push_back(MenuItemType());


        // Store the name data to the struct's name variable in vector
        a[sort].menuItem = name;


        // Store the price data to the struct's price variable in vector
        a[sort].menuPrice = price;


        // Counter increases by 1 each time the loop iterates
        sort++;


        // Ignore 666 characters or the first delimiter '\n' is met
        infile.ignore(777, '\n');
    }


    // Disconnect infile from the input file
    infile.close();
}


/*******************************************************************************
 *
 * FUNCTION showMenu
 * _____________________________________________________________________________
 *  This function gets 1 reference parameters. It displays the menu and promots
 *  the user to enter the item number and quantity of their purchase, and then
 *  returns the vector stores the purchase data
 *  - outputs the menu and returns the purchase data vector
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      &filename: the name of the input file
 *      &a       : the vector stores items' name and price
 *
 * POST - CONDITIONS
 *  This function will only read in data from the input file
 ******************************************************************************/
vector<Order> showMenu(vector<MenuItemType> &menu)  // In - the menu of items
{
    // Declare variables
    int count;                  // Counter - count the number of items bought
    int num;                    // In - the item number input by the user
    int quantity;               // In - the item quantity input by the user
    vector<Order> order;        // Out - the vector stores item number and
                                //       quantity


    // Initialization
    count = 0;                  // Counter starts from 0
    num = 0;                    // Item number is initially 0
    quantity = 0;               // Item quantity is initially 0


    // Proc: loop to prompt the user to enter the item number and quantity,
    // store the purchasing data into vector order, loop exits when 0 is entered
    while (true)
    {
        // Output: display the menu header
        cout << "Welcome to Johnny's Restaurant" << endl << endl;
        cout << "             Menu\n" << endl;


        // Out: output the menu items and prices
        for (unsigned i = 0; i < menu.size(); i++)
        {
            cout << (i + 1) << ". " << setw(20) << left << menu[i].menuItem;
            cout << setw(2) << left << "$ " << fixed << setprecision(2)
                 << menu[i].menuPrice << endl;
        }
        cout << endl;


        // In: prompt the user to enter the item number
        cout << "Enter 0 when you finish your order." << endl << endl;
        cout << "Enter the item number: ";
        cin >> num;
        cout << endl;


        // Branch: when the item number is not zero
        if (num != 0)
        {
            // In: prompt the user to enter the quantity
            cout << "How many would you like to order? ";
            cin >> quantity;
            cout << endl << endl << endl;
        }


        // Branch: when the item number is 0
        else if (num == 0)
        {
            // Proc: loop exits
            break;
        }


        // Proc: push back the struct Order into the vector order, and store the
        // name, quantity and price of items purchased into the sturct variables
        order.push_back(Order());
        order[count].itemName = menu[num - 1].menuItem;
        order[count].itemQuantity = quantity;
        order[count].itemPrice = menu[num - 1].menuPrice;
        count++;
    }
    return order;
}


/*******************************************************************************
 *
 * FUNCTION printCheck
 * _____________________________________________________________________________
 *  This function gets 1 parameters. It displays the check of the current order,
 *  including the quantity and price of each item, total price before and after
 *  the tax
 *  - returns nothing but outputs the complete check
 * _____________________________________________________________________________
 * PRE - CONDITIONS
 *  The following need previously defined values:
 *      order: the vector stores the order data input by the user
 *
 * POST - CONDITIONS
 *  This function will output the order check
 ******************************************************************************/
void printCheck(vector<Order> order)        // Out - the vector stores the order
                                            //       data input by the user
{
    // Declare variables
    double oneBe4Tax;       // Cal & Out - spending of one item before taxing
    double be4Tax;          // Cal & Out - total spending before taxing
    double tax;             // Cal & Out - tax of the spending


    // Initialization
    oneBe4Tax = 0;          // Spending of one item is initially zero
    be4Tax = 0;             // Total spending before taxing is initially zero
    tax = 0;                // Tax is initially zero


    // Out: display the check heard
    cout << "\n\nWelcome to Johnny's Restaurant" << endl << endl;
    cout << "             SALE\n" << endl;


    // Proc: loop to computer the spendings and display the order
    for (unsigned i = 0; i < order.size(); i++)
    {
        // Cal: compute teh spending of one item by multiplying the itme price
        // with item quantity
        oneBe4Tax = order[i].itemPrice * order[i].itemQuantity;


        // Out: display the quantity, name and spending of each tiem
        cout << setw(3) << left << order[i].itemQuantity;
        cout << setw(20) << left << order[i].itemName;
        cout << "$";
        cout << setw(5) << right << fixed << setprecision(2) << oneBe4Tax;
        cout << endl;


        // Cal: compute the total spending without tax
        be4Tax = be4Tax + order[i].itemPrice * order[i].itemQuantity;
    }


    // Cal: compute the tax of the order
    tax = tax + be4Tax * 0.05;


    // Out: display tax and total amount due of the order
    cout << setw(23) << left << "Tax";
    cout << setw(2) << left << "$ ";
    cout << fixed << setprecision(2) << tax << endl;
    cout << "-----------------------------" << endl;
    cout << setw(23) << "Amount Due";
    cout << "$" << fixed << setprecision(2) << be4Tax + tax;
    cout << endl << endl;
}








