#include <iostream>
#include <iomanip>
#include "order.h"
using namespace order;
using namespace std;

/*
 * @Mackenzie Bristow
 * @brief App for cashier that helps calculate and keep track of the customer's order
 * does math for total and tax to produce a final total that customer will owe.
 */

int main()
{
    //variable for user's choice
    int userChoice = 0;

    //variable to store the customer's total
    double total;

    //variable to break or keep looping
    char condition = 'y';
    while(condition == 'y' || condition == 'Y')
    {
        //Part 1: call menu function
        CustomerMenu();
        cin >> userChoice;

        //Part 2: Information gathering
        double quantity;
        double price;
        switch(userChoice)
        {
            case 1:
                cout << "How many pounds: " << endl;
                cin >> quantity;
                price = CalculateTax(2.99, DISCOUNTED_RATE);
                break;
            case 2:
                cout << "How many jars: " << endl;
                cin >> quantity;
                price = CalculateTax(4.99);
                break;
            case 3:
                cout << "How many scones:"<< endl;
                cin >> quantity;
                price = CalculateTax(2);
                break;
            case 4:
                cout << "How many chocolate covered strawberries: " << endl;
                cin >> quantity;
                price = CalculateTax(.5);
                break;
        }
        double computedPrice = CalculatePrice(price, quantity);
        UpdateTotal(computedPrice, total);
        cout << "Your current total is: " << fixed << std::setprecision(2) << total << endl;
        cout << "Would you like to add another item? (Y or N)" << endl;
        cin >> condition;
    }

    cout << "Final Total:\t\t" << total;

    return 0;
}