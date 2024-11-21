#include <stdio.h>
#include <unistd.h>
#include <string.h> // For strcmp
#include <stdbool.h> // For boolean values
//editing this program
#define MAX_ITEMS 100

void displayMenu();
void displayElectronics();
void displayClothing();
void displayToys();
float calculateDiscount(float totalBill, int totalQuantity);
void displayCart(int cart[][2], int itemCount, float totalBill);
void loading();

int main() {
    char choice[20], subChoice[20];
    int quantity;
    float totalBill = 0;
    int totalQuantity = 0;
    int cart[100][2]; // Array to hold item selections [item number, quantity]
    int itemCount = 0;

    do {
        displayMenu();
        printf("Enter your choice (Electronics, Clothing, Toys), or 'Checkout' to proceed: ");
        scanf("%s", choice);
        loading();

        if (strcmp(choice, "Electronics") == 0) {
            displayElectronics();
            printf("Enter the item name you want to buy: ");
            scanf("%s", subChoice);
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
        } else if (strcmp(choice, "Clothing") == 0) {
            displayClothing();
            printf("Enter the item name you want to buy: ");
            scanf("%s", subChoice);
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
        } else if (strcmp(choice, "Toys") == 0) {
            displayToys();
            printf("Enter the item name you want to buy: ");
            scanf("%s", subChoice);
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
        } else if (strcmp(choice, "Checkout") == 0) {
            printf("Checking out...\n");
            loading();
            if (totalQuantity == 0) {
                printf("Your cart is empty!\n");
            } else {
                printf("Your total bill is %.2f\n", totalBill);
                totalBill = calculateDiscount(totalBill, totalQuantity);
                printf("Final Total Bill after discount (if applicable): %.2f\n", totalBill);
            }
            break;
        } else {
            printf("Invalid choice! Please choose a valid section.\n");
            continue; // Go back to the main menu
        }

        // Process the item choice
        bool validChoice = false;
        if (quantity < 1 || quantity > MAX_ITEMS) {
            printf("Invalid quantity! Please enter a value between 1 and %d.\n", MAX_ITEMS);
            continue; // Go back to the menu
        }

        if (strcmp(subChoice, "Mobile") == 0) {
            totalBill += quantity * 15000;
            cart[itemCount][0] = 1; // Mobile Phone
            validChoice = true;
        } else if (strcmp(subChoice, "Laptop") == 0) {
            totalBill += quantity * 60000;
            cart[itemCount][0] = 2; // Laptop
            validChoice = true;
        } else if (strcmp(subChoice, "Headphones") == 0) {
            totalBill += quantity * 2000;
            cart[itemCount][0] = 3; // Headphones
            validChoice = true;
        } else if (strcmp(subChoice, "T-Shirt") == 0) {
            totalBill += quantity * 500;
            cart[itemCount][0] = 4; // T-Shirt
            validChoice = true;
        } else if (strcmp(subChoice, "Jeans") == 0) {
            totalBill += quantity * 1500;
            cart[itemCount][0] = 5; // Jeans
            validChoice = true;
        } else if (strcmp(subChoice, "Jacket") == 0) {
            totalBill += quantity * 3000;
            cart[itemCount][0] = 6; // Jacket
            validChoice = true;
        } else if (strcmp(subChoice, "Action") == 0) {
            totalBill += quantity * 800;
            cart[itemCount][0] = 7; // Action Figure
            validChoice = true;
        } else if (strcmp(subChoice, "Puzzle") == 0) {
            totalBill += quantity * 300;
            cart[itemCount][0] = 8; // Puzzle
            validChoice = true;
        } else if (strcmp(subChoice, "Board") == 0) {
            totalBill += quantity * 1200;
            cart[itemCount][0] = 9; // Board Game
            validChoice = true;
        }

        if (validChoice) {
            cart[itemCount][1] = quantity; // Store quantity
            itemCount++;
            totalQuantity += quantity;
            printf("Added %d %s(s) to your cart. Current total: %.2f\n", quantity, subChoice, totalBill);
            displayCart(cart, itemCount, totalBill);
        } else {
            printf("Invalid item choice.\n");
        }

    } while (true);

    return 0;
}

void displayMenu() {
    printf("\n--- Welcome to the Shop ---\n");
    printf("Available Sections:\n");
    printf("1. Electronics\n");
    printf("2. Clothing\n");
    printf("3. Toys\n");
    printf("0. Checkout\n");
}

void displayElectronics() {
    printf("\n--- Electronics Section ---\n");
    printf("Mobile - 15,000\n");
    printf("Laptop - 60,000\n");
    printf("Headphones - 2,000\n");
}

void displayClothing() {
    printf("\n--- Clothing Section ---\n");
    printf("T-Shirt - 500\n");
    printf("Jeans - 1,500\n");
    printf("Jacket - 3,000\n");
}

void displayToys() {
    printf("\n--- Toys Section ---\n");
    printf("Action Figure - 800\n");
    printf("Puzzle - 300\n");
    printf("Board Game - 1,200\n");
}

float calculateDiscount(float totalBill, int totalQuantity) {
    if (totalQuantity > 35 || totalBill > 2000) {
        printf("Congratulations! You have received a 20%% discount.\n");
        totalBill *= 0.8; // Apply discount
    }
    return totalBill;
}

void displayCart(int cart[][2], int itemCount, float totalBill) {
    printf("\n--- Your Cart ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: Quantity %d\n", cart[i][0], cart[i][1]);
    }
    printf("Current Total Bill: %.2f\n", totalBill);
}

void loading() {
    printf("Loading");
    for (int i = 0; i < 3; i++) {
        printf("."); 
        fflush(stdout); 
        sleep(1); 
    }
    printf("\n"); 
}
