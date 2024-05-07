# Farmers Market Booth Checkout

---
## Objectives
Demonstrate knowledge about the following topics:

- Functions
- Namespaces
- Pass by Reference

### The Problem to Solve
Farmers Market - Strawberries
A local farmers market booth sold strawberries. Customers loved their strawberries so much that
the booth owners decided to start selling strawberry related products alongside the
strawberries. These strawberry products included strawberry jam, chocolate covered
strawberries, and glazed strawberry scones.

Before the addition of the strawberry products it was easy for the booth owners to keep track of
the profit from the strawberry sales since raw, freshly grown products receive the discounted
tax rate of 3%. However, prepared products do not. So, the strawberry booth owners hired you
to create a basic program to correctly calculate the total for each sale.

This program needs to calculate the tax based on the last inputted product. It should then update the customer's total with that last product's price + tax.

### Files to Work on
You will be working in the following files:

All functions will be part  of the library order. The library consists of these two files:
- 'src/order.cpp'
- 'src/order.h'

Our "driver" file will be
- 'src/main.cpp

## Order Library
Create a library of functions to handle tasks that calculate the order and that are repetitive within the program.

### order.h
1. Create a namespace called order
2. In that namespace define the following:
   - Constant called DISCOUNTED_RATE with the value of .03 
   - Constant called NORMAL_RATE with the value of .061 
   - Function prototypes for the functions described in the next part.

### order.cpp
Make sure to add any necessary header files and scope the functions back to the order namespace. 

#### Function 1: Print the customer’s menu.

Call this function `CustomerMenu`. It should not return anything or take any parameters.
The customer menu should look like this: 

```bash
-----------------------------
-- Straweberry Booth Menu ---
-----------------------------
Please choose from the following options:
1. Fresh Strawberries           $2.99
2. Strawberry Jam               $4.99
3. Glazed Strawberry Scone      $2.00
4. Chocolate Covered Strawberry $0.50
```

#### Function 2: Calculate price with tax

_Function Setup_
  - Named `CalculateTax`. 
  - Returns a double
  - Accepts two parameters. 
    - The first parameter is a double and represent the price of a product.
    - The second parameter is a double and will represent the tax rate. 
    This parameter should have a default value of .061 _(notice this is the value from our constant called NORMAL_RATE)_.

_Function Task_
- Calculate the tax based on the price and rate
- Add tax to initial price
- return the final result

**Example**:
If the `price` of an item were $1.99 and the tax `rate` for that item were 6.10%. Then the function would first calculate the tax for the item: $.12.
Then add that tax to the final total, making it: $2.11


#### Function 3: Calculate price based on quantity
_Function Setup_
* Named `CalculateTotal`. 
* Returns a double
* Accepts two parameters
  * The first parameter is a double and represents the price of the item
  * The second parameter is a double and represents the quantity of items

_Function Task_
* Calculate the price of the item based on it's quanitity

**Example**:
If the `price` of the item is $2.11 and the user would like a `quantity` value of 3, the total for that item would be $6.33.

#### Function 4: Update the total

_Function Setup_
* Named UpdateTotal
* Returns nothing
* Accepts two parameters
  * The first parameter is a double and represents the new value to be added to the total 
  * The second parameter is a double and is a reference to the total variable. This variable keeps track of the customer's running total.

_Function Task_
* Update the passed in variable that is managing the customer's final `total`. 

**Example:**
If the `total` variable originally held the value of $12.99, but the customer added a new amount of $6.33 to their order, this function would update the `total` value to $19.32.

## Customer Order Flow
The customer's order flow will be handled in the `main.cpp` file.
It should use the functions from the `order` namespace to calculate and present the final order total to the cashier.
### Main.cpp

Create the flow of the customer's order in `main.cpp` by doing the following.
1. Print the menu
2. Get the user’s choice using the numbers from the menu (_ex: 1 is for strawberries, etc_)
3. Use a switch statement to:
   * Calculate the product’s price with tax (_remember the business rules described in the introduction_)
   * Get user’s choice of item quantity
```bash
For strawberries ask "How many pounds:"
For strawberry jam ask "How many jars: "
For scones ask "How many scones: "
For chocolate covered strawberries ask "How many chocolate covered strawberries: "
```

4. Outside of the switch statement we should calculate the total based on the quantity of that item.
5. Update a variable that is keeping track of the total
6. Report the current total to the cashier
7. Ask if the cashier to choose `Y` if they would like to add any more products and `N` if not. 
   * If `Y`, start the process over with step one.
   * If `N`, break out of the process
8. Print the final total to the customer. Use iostream manipulators to print the total with a fixed 2 point precision. 

Here is an example run of the final program output.

```bash
-----------------------------
-- Strawberry Booth Menu ---
-----------------------------
Please choose from the following options:
1. Fresh Strawberries           $2.99
2. Strawberry Jam               $4.99
3. Glazed Strawberry Scone      $2.00
4. Chocolate Covered Strawberry $0.50
1
How many pounds:
2
Your current total is: 6.16
Would you like to add another item? (Y or N)
y
-----------------------------
-- Strawberry Booth Menu ---
-----------------------------
Please choose from the following options:
1. Fresh Strawberries           $2.99
2. Strawberry Jam               $4.99
3. Glazed Strawberry Scone      $2.00
4. Chocolate Covered Strawberry $0.50
4
How many chocolate covered strawberries:
5
Your current total is: 8.81
Would you like to add another item? (Y or N)
n
Final Total:            8.81
Process finished with exit code 0
```
