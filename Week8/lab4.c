#include <stdio.h>

float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}

int main() {
    float revenue, expenses, result;
    printf("Enter revenue: ");
    scanf("%f", &revenue);
    printf("Enter expenses: ");
    scanf("%f", &expenses);

    result = calculateBudget(revenue, expenses);
    printf("Budget: %.2f\n", result);

    if(result > 0) {
        printf("SURPLUS\n");
    } else if(result < 0) {
        printf("DEFICIT\n");
    } else {
        printf("BALANCED\n");
    }
    return 0;
}