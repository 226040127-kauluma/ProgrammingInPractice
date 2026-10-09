#include <stdio.h>

void displayMenu() {
    printf("========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("========================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}

int main() {
    int choice;
    displayMenu();
    scanf("%d", &choice);
    printf("You chose %d\n", choice);
    return 0;
}