#include <stdio.h>

int main() {
    int choice, quantity;
    
    // Total 15 items with their prices
    int total_items = 15;
    float price[15] = {
        60.0, 50.0, 30.0, 110.0, 25.0,  
        60.0, 70.0, 45.0, 80.0, 80.0,  
        65.0, 40.0, 50.0, 100.0, 90.0
    };
    
    char *items[15] = {
        "Burger", "Sandwich", "Tea/Coffee", "Pasta", "Samosa",
        "Veg Chowmein", "Fried Rice", "maggi", "Masala Dosa", "French Fries",
        "Cold Coffee", "Badam Milk", "Ice Cream", "Brownie", "Momos"
    };
    
    int ordered_qty[15] = {0}; // Array to track quantities ordered for each item
    float subtotal = 0.0, discount = 0.0, final_amount = 0.0;
    char continue_order;

    printf("========================================\n");
    printf("      WELCOME TO SMART COLLEGE CANTEEN   \n");
    printf("========================================\n");

    // Display the 15-item menu ONCE at the beginning
    printf("\n----------------------------------------\n");
    printf("              CANTEEN MENU              \n");
    printf("----------------------------------------\n");
    for (int i = 0; i < total_items; i++) {
        printf("%2d. %-15s - Rs. %.2f\n", i + 1, items[i], price[i]);
    }
    printf("----------------------------------------\n");

    // Loop to allow ordering multiple items without re-printing the full menu
    do {
        printf("\nEnter item number (1 to 15): ");
        scanf("%d", &choice);

        // Validate choice using conditional statements
        if (choice >= 1 && choice <= total_items) {
            printf("Enter quantity for %s: ", items[choice - 1]);
            scanf("%d", &quantity);
            
            if (quantity > 0) {
                ordered_qty[choice - 1] += quantity; // Store quantity at index (choice - 1)
                printf("--> Added %d %s(s) to your order.\n", quantity, items[choice - 1]);
            } else {
                printf("Invalid quantity! Please enter a positive number.\n");
            }
        } else {
            printf("Invalid choice! Please select between 1 and 15.\n");
        }

        printf("Do you want to order another item? (y/n): ");
        scanf(" %c", &continue_order);

    } while (continue_order == 'y' || continue_order == 'Y');

    // Displaying the Itemized Bill
    printf("\n========================================\n");
    printf("               FINAL BILL               \n");
    printf("========================================\n");
    printf("%-15s %-10s %-10s\n", "Item", "Qty", "Total (Rs.)");
    printf("----------------------------------------\n");

    int items_ordered_count = 0;
    for (int i = 0; i < total_items; i++) {
        if (ordered_qty[i] > 0) {
            float item_total = ordered_qty[i] * price[i];
            subtotal += item_total;
            printf("%-15s %-10d %-10.2f\n", items[i], ordered_qty[i], item_total);
            items_ordered_count++;
        }
    }

    // If no items were ordered
    if (items_ordered_count == 0) {
        printf("No items ordered!\n");
        printf("========================================\n");
        return 0;
    }

    printf("----------------------------------------\n");
    printf("Subtotal:                        Rs. %.2f\n", subtotal);

    // Apply a 10% discount if the subtotal exceeds Rs. 300
    if (subtotal > 300.0) {
        discount = subtotal * 0.10; 
        printf("Discount (10%% applied):          -Rs. %.2f\n", discount);
    } else {
        printf("Discount:                        Rs. 0.00\n");
    }

    final_amount = subtotal - discount;
    printf("========================================\n");
    printf("Final Amount Payable:            Rs. %.2f\n", final_amount);
    printf("========================================\n");
    printf("Thank you! Visit again.\n");

    return 0;
}