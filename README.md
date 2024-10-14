# Shop Management System

## Overview

This is a simple console-based Shop Management System written in C. The program allows users to browse through different sections such as Electronics, Clothing, and Toys, select items, input quantities, and calculate the total bill with potential discounts.

## Features

- **Sections and Subsections**: 
  - Electronics (e.g., Mobile Phones, Laptops, Headphones)
  - Clothing (e.g., T-Shirts, Jeans, Jackets)
  - Toys (e.g., Action Figures, Puzzles, Board Games)
  
- **User Input**: Users can input the quantity of items they wish to purchase.

- **Discounts**: If the total quantity of items exceeds 35 or if the total bill exceeds 2000 rupees, a 20% discount is applied at checkout.

- **Input Validation**: The program checks for invalid input such as negative quantities or quantities exceeding the defined limit.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC) installed on your machine.

### Compilation

To compile the program, navigate to the directory containing the `shop.c` file and use the following command:

```bash
gcc -o shop shop.c
```
Running the Program
After successful compilation, run the program using:

```bash
./shop
# Example Usage
Select a Section:

Enter 1 for Electronics
Enter 2 for Clothing
Enter 3 for Toys
Enter 0 to checkout
Select an Item:

# Input the item number based on the displayed options.
Input Quantity:

# Enter the desired quantity for the selected item.
Checkout:

# Upon entering 0, the program will calculate the total bill and apply any applicable discounts.
```
#Code Structure
The program is structured with several functions:

displayMenu(): Displays the main menu for section selection.
displayElectronics(): Displays the items available in the Electronics section.
displayClothing(): Displays the items available in the Clothing section.
displayToys(): Displays the items available in the Toys section.
calculateDiscount(float totalBill, int totalQuantity): Calculates any applicable discount based on total bill and quantity.

#Sample Output

```
--- Welcome to the Shop ---
1. Electronics
2. Clothing
3. Toys
0. Checkout
Enter your choice (1-4), or 0 to checkout: 1

--- Electronics Section ---
1. Mobile Phone - 15,000
2. Laptop - 60,000
3. Headphones - 2,000
Enter the item number you want to buy: 1
Enter the quantity: 3
Added 3 items to your cart. Current total: 45000.00
```

License
This project is licensed under the MIT License - see the LICENSE file for details.

Acknowledgments
Inspiration for this project was drawn from basic retail management concepts.
