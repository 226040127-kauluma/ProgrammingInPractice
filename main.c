#include <stdio.h>

int main() {
    double revenue;
    double expenses;
    double balance;

    printf("MUNICIPAL BUDGET CALCULATOR\n\n");

    printf("Enter total revenue: ");
    scanf("%lf", &revenue);
    printf("Enter total expenses: ");
    scanf("%lf", &expenses);
    
    balance = revenue - expenses;
    
    printf("\n--- Budget Summary ---\n");
    printf("Revenue : %.2f\n", revenue);
    printf("Expenses: %.2f\n", expenses);
    printf("Balance : %.2f\n", balance);
    
    return 0;
}