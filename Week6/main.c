#include <stdio.h>
#include <string.h>

int main() {
    float salaries[50];
    float budgets[10];
    char registrations[20][20];

    int choice, i, j;
    int salariesCaptured = 0;
    int budgetsCaptured = 0;
    int regCaptured = 0;

    while (1) {
        printf("\n===== Municipal Information Management System =====\n");
        printf("1. Employee Salaries (50)\n");
        printf("2. Department Budgets (10)\n");
        printf("3. Vehicle Registrations (20)\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // A. Employee salaries
            printf("\n--- A. Employee Salaries ---\n");
            printf("Enter 50 salaries:\n");
            for (i = 0; i < 50; i++) {
                printf("Salary %d: ", i + 1);
                scanf("%f", &salaries[i]);
            }
            salariesCaptured = 1;

            // Display all
            printf("\nAll Salaries:\n");
            for (i = 0; i < 50; i++) {
                printf("%.2f ", salaries[i]);
                if ((i + 1) % 10 == 0) printf("\n");
            }

            // Average, Highest, Lowest
            float sum = 0, highest, lowest;
            highest = salaries[0];
            lowest = salaries[0];
            for (i = 0; i < 50; i++) {
                sum += salaries[i];
                if (salaries[i] > highest) highest = salaries[i];
                if (salaries[i] < lowest) lowest = salaries[i];
            }
            printf("\nAverage Salary: %.2f\n", sum / 50);
            printf("Highest Salary: %.2f\n", highest);
            printf("Lowest Salary: %.2f\n", lowest);

            // Search
            float search;
            printf("\nEnter salary to search: ");
            scanf("%f", &search);
            int found = 0;
            for (i = 0; i < 50; i++) {
                if (salaries[i] == search) {
                    printf("Found %.2f at position %d\n", search, i + 1);
                    found = 1;
                    // break; // remove break if you want all occurrences
                }
            }
            if (!found) printf("Salary %.2f not found.\n", search);

        } else if (choice == 2) {
            // B. Department budgets
            printf("\n--- B. Department Budgets ---\n");
            printf("Enter 10 department budgets:\n");
            for (i = 0; i < 10; i++) {
                printf("Budget %d: ", i + 1);
                scanf("%f", &budgets[i]);
            }
            budgetsCaptured = 1;

            // Display
            printf("\nAll Budgets:\n");
            for (i = 0; i < 10; i++) {
                printf("%.2f ", budgets[i]);
            }
            printf("\n");

            // Total and Average
            float total = 0;
            for (i = 0; i < 10; i++) total += budgets[i];
            printf("Total Budget: %.2f\n", total);
            printf("Average Budget: %.2f\n", total / 10);

            // Sort lowest to highest (Bubble Sort)
            for (i = 0; i < 10 - 1; i++) {
                for (j = 0; j < 10 - 1 - i; j++) {
                    if (budgets[j] > budgets[j + 1]) {
                        float temp = budgets[j];
                        budgets[j] = budgets[j + 1];
                        budgets[j + 1] = temp;
                    }
                }
            }
            printf("\nBudgets Sorted Lowest to Highest:\n");
            for (i = 0; i < 10; i++) {
                printf("%.2f ", budgets[i]);
            }
            printf("\n");

        } else if (choice == 3) {
            // C. Vehicle registration numbers
            printf("\n--- C. Vehicle Registration Numbers ---\n");
            printf("Enter 20 registration numbers:\n");
            // Clear input buffer
            getchar();
            for (i = 0; i < 20; i++) {
                printf("Registration %d: ", i + 1);
                fgets(registrations[i], 20, stdin);
                // Remove newline
                registrations[i][strcspn(registrations[i], "\n")] = 0;
            }
            regCaptured = 1;

            // Display
            printf("\nAll Registration Numbers:\n");
            for (i = 0; i < 20; i++) {
                printf("%d. %s\n", i + 1, registrations[i]);
            }

            // Search
            char searchReg[20];
            printf("\nEnter registration number to search: ");
            fgets(searchReg, 20, stdin);
            searchReg[strcspn(searchReg, "\n")] = 0;

            int found = 0;
            for (i = 0; i < 20; i++) {
                if (strcmp(registrations[i], searchReg) == 0) {
                    printf("Found %s at position %d\n", searchReg, i + 1);
                    found = 1;
                    break;
                }
            }
            if (!found) printf("Registration %s not found.\n", searchReg);

        } else if (choice == 4) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}