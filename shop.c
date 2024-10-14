#include <stdio.h>
#include <unistd.h> // For sleep() function

#define MAX_ITEMS 100

void displayMenu();
void displayElectronics();
void displayClothing();
void displayToys();
float calculateDiscount(float totalBill, int totalQuantity);
void displayCart(int cart[][2], int itemCount, float totalBill);
void loading(); // Function to show loading dots

int main() {
    int choice, subChoice, quantity;
    float totalBill = 0;
    int totalQuantity = 0;
    int cart[100][2]; // Array to hold item selections [item number, quantity]
    int itemCount = 0;

    do {
        displayMenu();
        printf("Enter your choice (1-3), or 0 to checkout: ");
        scanf("%d", &choice);
        loading(); // Show loading effect

        switch (choice) {
            case 1: // Electronics
                displayElectronics();
                printf("Enter the item number you want to buy: ");
                scanf("%d", &subChoice);
                printf("Enter the quantity: ");
                scanf("%d", &quantity);
                if (quantity < 1 || quantity > MAX_ITEMS) {
                    printf("Invalid quantity! Please enter a value between 1 and %d.\n", MAX_ITEMS);
                    break;
                }
                switch (subChoice) {
                    case 1: // Mobile Phone
                        totalBill += quantity * 15000;
                        cart[itemCount][0] = 1; // Mobile Phone
                        break;
                    case 2: // Laptop
                        totalBill += quantity * 60000;
                        cart[itemCount][0] = 2; // Laptop
                        break;
                    case 3: // Headphones
                        totalBill += quantity * 2000;
                        cart[itemCount][0] = 3; // Headphones
                        break;
                    default:
                        printf("Invalid item choice.\n");
                        continue; // Go back to the main menu
                }
                cart[itemCount][1] = quantity; // Store quantity
                itemCount++;
                totalQuantity += quantity;
                printf("Added %d items to your cart. Current total: %.2f\n", quantity, totalBill);
                displayCart(cart, itemCount, totalBill);
                break;

            case 2: // Clothing
                displayClothing();
                printf("Enter the item number you want to buy: ");
                scanf("%d", &subChoice);
                printf("Enter the quantity: ");
                scanf("%d", &quantity);
                if (quantity < 1 || quantity > MAX_ITEMS) {
                    printf("Invalid quantity! Please enter a value between 1 and %d.\n", MAX_ITEMS);
                    break;
                }
                switch (subChoice) {
                    case 1: // T-Shirt
                        totalBill += quantity * 500;
                        cart[itemCount][0] = 4; // T-Shirt
                        break;
                    case 2: // Jeans
                        totalBill += quantity * 1500;
                        cart[itemCount][0] = 5; // Jeans
                        break;
                    case 3: // Jacket
                        totalBill += quantity * 3000;
                        cart[itemCount][0] = 6; // Jacket
                        break;
                    default:
                        printf("Invalid item choice.\n");
                        continue; // Go back to the main menu
                }
                cart[itemCount][1] = quantity; // Store quantity
                itemCount++;
                totalQuantity += quantity;
                printf("Added %d items to your cart. Current total: %.2f\n", quantity, totalBill);
                displayCart(cart, itemCount, totalBill);
                break;

            case 3: // Toys
                displayToys();
                printf("Enter the item number you want to buy: ");
                scanf("%d", &subChoice);
                printf("Enter the quantity: ");
                scanf("%d", &quantity);
                if (quantity < 1 || quantity > MAX_ITEMS) {
                    printf("Invalid quantity! Please enter a value between 1 and %d.\n", MAX_ITEMS);
                    break;
                }
                switch (subChoice) {
                    case 1: // Action Figure
                        totalBill += quantity * 800;
                        cart[itemCount][0] = 7; // Action Figure
                        break;
                    case 2: // Puzzle
                        totalBill += quantity * 300;
                        cart[itemCount][0] = 8; // Puzzle
                        break;
                    case 3: // Board Game
                        totalBill += quantity * 1200;
                        cart[itemCount][0] = 9; // Board Game
                        break;
                    default:
                        printf("Invalid item choice.\n");
                        continue; // Go back to the main menu
                }
                cart[itemCount][1] = quantity; // Store quantity
                itemCount++;
                totalQuantity += quantity;
                printf("Added %d items to your cart. Current total: %.2f\n", quantity, totalBill);
                displayCart(cart, itemCount, totalBill);
                break;

            case 0: // Checkout
                printf("Checking out...\n");
                loading(); // Show loading effect
                if (totalQuantity == 0) {
                    printf("Your cart is empty!\n");
                } else {
                    printf("Your total bill is %.2f\n", totalBill);
                    // Automatically apply discount if conditions are met
                    totalBill = calculateDiscount(totalBill, totalQuantity);
                    printf("Final Total Bill after discount (if applicable): %.2f\n", totalBill);
                }
                break;

            default:
                printf("Invalid choice! Please choose a valid section.\n");
                break;
        }

    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n--- Welcome to the Shop ---\n");
    printf("1. Electronics\n");
    printf("2. Clothing\n");
    printf("3. Toys\n");
    printf("0. Checkout\n");
}

void displayElectronics() {
    printf("\n--- Electronics Section ---\n");
    printf("1. Mobile Phone - 15,000\n");
    printf("2. Laptop - 60,000\n");
    printf("3. Headphones - 2,000\n");
}

void displayClothing() {
    printf("\n--- Clothing Section ---\n");
    printf("1. T-Shirt - 500\n");
    printf("2. Jeans - 1,500\n");
    printf("3. Jacket - 3,000\n");
}

void displayToys() {
    printf("\n--- Toys Section ---\n");
    printf("1. Action Figure - 800\n");
    printf("2. Puzzle - 300\n");
    printf("3. Board Game - 1,200\n");
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
        printf("."); // Print dot
        fflush(stdout); // Flush the output buffer to show the dot immediately
        sleep(1); // Sleep for 1 second
    }
    printf("\n"); // Move to the next line after loading
}
