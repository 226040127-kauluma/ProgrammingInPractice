#include <stdio.h>

int main() {
    float salary[50];
    float total = 0, average;
    float highest, lowest;
    int i;

    // Capture salaries
    for (i = 0; i < 50; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salary[i]);

        total = total + salary[i];
    }

    // Initialize highest and lowest
    highest = salary[0];
    lowest = salary[0];

    // Find highest and lowest salary
    for (i = 1; i < 50; i++) {
        if (salary[i] > highest) {
            highest = salary[i];
        }

        if (salary[i] < lowest) {
            lowest = salary[i];
        }
    }

    // Calculate average
    average = total / 50;

    // Display results
    printf("\n--- Municipal Employee Salary Analysis ---\n");
    printf("Total Salary: N$%.2f\n", total);
    printf("Average Salary: N$%.2f\n", average);
    printf("Highest Salary: N$%.2f\n", highest);
    printf("Lowest Salary: N$%.2f\n", lowest);

    return 0;
}