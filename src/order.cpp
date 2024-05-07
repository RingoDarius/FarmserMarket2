#include <iomanip>   // for formatted output
#include <iostream>
#include "order.h"  // my order library

/*
 * @brief print the booth product menu
 *
 */
void order::CustomerMenu()
{
    std::cout << "-----------------------------" << std::endl;
    std::cout << "-- Strawberry Booth Menu ---" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Please choose from the following options:" << std::endl;
    std::cout << "1. Fresh Strawberries\t\t$2.99\n2. Strawberry Jam\t\t$4.99\n3. Glazed Strawberry Scone\t$2.00\n4. Chocolate Covered Strawberry\t$0.50" << std::endl;
}

/*
 * @brief calculate the price of the product based on the customer's chosen quanitity
 * @param: double: price
 * @param: double: quantity
 * @return double: result
 */
double order::CalculatePrice(double price, double quantity)
{
    return price * quantity;
}

/*
 * @brief calculate the tax rate based on the kind of product.
 * @param double: price of product
 * @param double: rate, default value = .061
 * return double: result
 */
double order::CalculateTax(double price, double rate)
{
    return price * rate + price;
}

/*
 * @brief update the total with the latest computed price
 * @param double: computedPrice
 * @param double: total - reference
 */
void order::UpdateTotal(double computedPrice, double& total)
{
    total += computedPrice;
}

