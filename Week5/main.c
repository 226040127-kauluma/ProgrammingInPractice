#include <stdio.h>

int main() {
    float salary;
    float total = 0;
    float highest = 0;
    float lowest = 0;
    float average;

    // 1. Capture salary of each employee
    for (int i = 1; i <= 50; i++) {
        printf("Enter salary for employee %d: ", i);
        scanf("%f", &salary);
        
        // 2. Calculate total
        total = total + salary;

        // Set first salary as both highest and lowest
        if (i == 1) {
            highest = salary;
            lowest = salary;
        }

        // 4. Determine highest
        if (salary > highest) {
            highest = salary;
        }

        // 5. Determine lowest
        if (salary < lowest) {
            lowest = salary;
        }
    }

    // 3. Calculate average
    average = total / 50;

    // 6. Display results
    printf("\n--- Municipal Salary Report ---\n");
    printf("Total salary: %.2f\n", total);
    printf("Average salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary: %.2f\n", lowest);

    return 0;
}