#include "order.h"
#include <array>
#include <iostream>
// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
//for floating point numbers
using namespace Catch::Matchers::Floating;

TEST_CASE("CalculatePrice() Tests")
{
    INFO("Checks that CalculatePrice returns correct value for each product ")

    //2 lbs of strawberries
    CHECK(5.98 == order::CalculatePrice(2.99, 2));

    //3 jars of strawberry Jam
    CHECK(14.97 == order::CalculatePrice(4.99, 3));

    //4 glazed strawberry Scones
    CHECK(8 == order::CalculatePrice(2, 4));

    //10 chocolate strawberries
    CHECK(5 == order::CalculatePrice(.5, 10));
}

TEST_CASE("CalculateTax() Tests")
{
    INFO("Checks CalculateTax() Function calculates & returns the correct price with tax")

    //1 lbs of strawberries
    CHECK_THAT(order::CalculateTax(2.99, order::DISCOUNTED_RATE), WithinRelMatcher(3.0797, .001));

    //1 jars of strawberry Jam
    CHECK_THAT(order::CalculateTax(4.99), WithinRelMatcher(5.29439, .001));

    //1 glazed strawberry scone
    CHECK_THAT(order::CalculateTax(2), WithinRelMatcher(2.122, .001));

    //1 chocolate strawberries
    CHECK_THAT(order::CalculateTax(.50), WithinRelMatcher(0.5305, .001));
}

TEST_CASE("UpdateTotal() Tests")
{
    INFO("Check that UpdateTotal() can handle adding 1 of each product from the strawberry booth to the total variable");

    //Define total variable to test
    double test_total = 0;

    /*Add 1 of each product to total*/

    //Add 1 lb of strawberries
    order::UpdateTotal(3.08, test_total);
    CHECK_THAT(test_total, WithinRelMatcher(3.08, .001));

    //Add 1 jar of strawberry jam
    order::UpdateTotal(5.29, test_total);
    CHECK_THAT(test_total, WithinRelMatcher(8.37, .001));

    //Add 1 glazed strawberry scone
    order::UpdateTotal(2.12, test_total);
    CHECK_THAT(test_total, WithinRelMatcher(10.49, .001));

    //Add 1 chocolate strawberry
    order::UpdateTotal(.53, test_total);
    CHECK_THAT(test_total, WithinRelMatcher(11.02, .001));

    //zero out test_total
    test_total = 0;
    CHECK(0 == test_total);

    INFO("Check UpdateTotal with random input");
    for(int i = 1; i < 10; i++)
    {
        order::UpdateTotal(3, test_total);
        CHECK(3 * i == test_total);
    }
}

TEST_CASE("Order Flow Tests")
{
    //Order 4 strawberry scones, a jar of jam, and 2 lbs of strawberries

    //define variable to track customer's total
    double test_total = 0;

    INFO("Checking each item tax is correctly calculated")
    // Calculate the price with tax for each item and store it in a variable to use later
    double scones = order::CalculateTax(2);
    double jam   = order::CalculateTax(4.99);
    double strawberries = order::CalculateTax(2.99, order::DISCOUNTED_RATE);

    //Check that each variable has correct product price plus tax
    CHECK_THAT(scones, WithinRelMatcher(2.122, .001));
    CHECK_THAT(jam, WithinRelMatcher(5.29439, .001));
    CHECK_THAT(strawberries, WithinRelMatcher(3.0797, .001));

    //Calculate the new price of the product based on how many the user wants, store back into same variable
    //Check that the price is correct
    INFO("Checking that product price by quantity is correct, then that it is successfully added to total");
    scones = order::CalculatePrice(scones, 4);
    CHECK(scones == 8.488);
    jam = order::CalculatePrice(jam, 1);
    CHECK(jam == 5.29439);
    strawberries = order::CalculatePrice(strawberries, 2);
    CHECK_THAT(strawberries, WithinRelMatcher(6.1594, .001));

    //Use the updated variables to update the customer's final total variable
    INFO("Checking that each item is successfully added to total");
    CHECK(test_total == 0);
    order::UpdateTotal(scones, test_total);
    CHECK(test_total == scones);
    order::UpdateTotal(jam, test_total);
    CHECK(test_total == jam + scones);
    order::UpdateTotal(strawberries, test_total);
    CHECK(test_total == jam + scones + strawberries);
}



