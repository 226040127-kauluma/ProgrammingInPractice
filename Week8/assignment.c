#include <stdio.h>
#include <string.h>

// Prototypes
void displayMenu();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
void addSupplier();
void displaySupplier();
void searchSupplier();

// Supplier storage
char sName[100] = "";
char sEmail[100] = "";
char sPhone[20] = "";
char sTown[50] = "";
char sBackup[100] = "";
int sAdded = 0;

void displayMenu() {
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Add Supplier\n");
    printf("2. Display Supplier\n");
    printf("3. Search Supplier\n");
    printf("4. Calculate VAT\n");
    printf("5. Calculate Salary\n");
    printf("6. Calculate Budget\n");
    printf("7. Exit\n");
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

void addSupplier() {
    printf("Enter supplier name: ");
    getchar();
    fgets(sName, 100, stdin);
    sName[strcspn(sName, "\n")] = 0;

    printf("Enter email: ");
    fgets(sEmail, 100, stdin);
    sEmail[strcspn(sEmail, "\n")] = 0;

    printf("Enter phone: ");
    fgets(sPhone, 20, stdin);
    sPhone[strcspn(sPhone, "\n")] = 0;

    printf("Enter town: ");
    fgets(sTown, 50, stdin);
    sTown[strcspn(sTown, "\n")] = 0;

    strcpy(sBackup, sName);
    sAdded = 1;
    printf("\nSupplier added! Backup created.\n");
    printf("Name length: %lu\n", strlen(sName));
}

void displaySupplier() {
    if(!sAdded) {
        printf("No supplier added yet!\n");
        return;
    }
    char description[200];
    strcpy(description, sName);
    strcat(description, " operates in ");
    strcat(description, sTown);
    strcat(description, ".");

    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name : %s\n", sName);
    printf("Email: %s\n", sEmail);
    printf("Phone: %s\n", sPhone);
    printf("Town : %s\n", sTown);
    printf("Backup: %s\n", sBackup);
    printf("Description: %s\n", description);
    printf("Name length: %lu\n", strlen(sName));
}

void searchSupplier() {
    char search[100];
    if(!sAdded) {
        printf("No supplier added yet!\n");
        return;
    }
    printf("Enter supplier name to search: ");
    getchar();
    fgets(search, 100, stdin);
    search[strcspn(search, "\n")] = 0;

    if(strcmp(search, sName) == 0) {
        printf("Supplier found.\n");
    } else {
        printf("Supplier not found.\n");
    }
}

int main() {
    int choice;

    while(1) {
        displayMenu();
        scanf("%d", &choice);

        if(choice == 1) {
            addSupplier();
        } else if(choice == 2) {
            displaySupplier();
        } else if(choice == 3) {
            searchSupplier();
        } else if(choice == 4) {
            float amt;
            printf("Enter amount: ");
            scanf("%f", &amt);
            printf("VAT: %.2f\n", calculateVAT(amt));
        } else if(choice == 5) {
            float b,h,t;
            printf("Basic salary: ");
            scanf("%f", &b);
            printf("Housing allowance: ");
            scanf("%f", &h);
            printf("Transport allowance: ");
            scanf("%f", &t);
            printf("Gross Salary: %.2f\n", calculateSalary(b,h,t));
        } else if(choice == 6) {
            float rev, exp, res;
            printf("Enter revenue: ");
            scanf("%f", &rev);
            printf("Enter expenses: ");
            scanf("%f", &exp);
            res = calculateBudget(rev, exp);
            printf("Budget: %.2f - ", res);
            if(res > 0) printf("SURPLUS\n");
            else if(res < 0) printf("DEFICIT\n");
            else printf("BALANCED\n");
        } else if(choice == 7) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}