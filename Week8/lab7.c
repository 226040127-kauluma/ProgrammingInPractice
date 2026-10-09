#include <stdio.h>

void displayWelcome() {
    printf("Welcome to the Municipal Financial Management System\n");
}

void displayMenu() {
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("========================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

float calculateVAT(float amount) {
    return amount * 0.15;
}

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}

int searchEmployee(int id, int ids[], int size) {
    for(int i = 0; i < size; i++) {
        if(ids[i] == id) return i;
    }
    return -1;
}

int main() {
    int choice;
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int empSize = 5;

    displayWelcome();

    while(1) {
        displayMenu();
        scanf("%d", &choice);

        if(choice == 1) {
            float amount;
            printf("Enter amount: ");
            scanf("%f", &amount);
            printf("VAT: %.2f\n", calculateVAT(amount));
        }
        else if(choice == 2) {
            float b,h,t;
            printf("Basic salary: ");
            scanf("%f", &b);
            printf("Housing allowance: ");
            scanf("%f", &h);
            printf("Transport allowance: ");
            scanf("%f", &t);
            printf("Gross salary: %.2f\n", calculateSalary(b,h,t));
        }
        else if(choice == 3) {
            float rev, exp, res;
            printf("Enter revenue: ");
            scanf("%f", &rev);
            printf("Enter expenses: ");
            scanf("%f", &exp);
            res = calculateBudget(rev, exp);
            printf("Result: %.2f\n", res);
            if(res > 0) printf("SURPLUS\n");
            else if(res < 0) printf("DEFICIT\n");
            else printf("BALANCED\n");
        }
        else if(choice == 4) {
            int id, pos;
            printf("Enter employee ID: ");
            scanf("%d", &id);
            pos = searchEmployee(id, employeeIDs, empSize);
            if(pos!= -1) printf("Employee found at position %d.\n", pos);
            else printf("Employee not found.\n");
        }
        else if(choice == 5) {
            break;
        }
    }
    return 0;
}