#include <stdio.h>
#include <string.h>

void displayWelcome() {
    printf("Welcome to the Municipal Financial Management System\n");
}

void displayMenu() {
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Calculate Employee Salary\n");
    printf("2. Calculate VAT\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Supplier Management\n");
    printf("6. Exit\n");
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
    for(int i=0;i<size;i++) if(ids[i]==id) return i;
    return -1;
}

void supplierManagement() {
    char name[100] = "", email[100] = "", phone[20] = "", town[50] = "";
    int added = 0;
    int sChoice;
    char search[100];

    while(1) {
        printf("\n--- SUPPLIER MANAGEMENT ---\n");
        printf("1. Add Supplier\n2. Display Supplier\n3. Search Supplier\n4. Back to Main Menu\nEnter choice: ");
        scanf("%d", &sChoice);
        getchar();

        if(sChoice == 1) {
            printf("Enter name: "); fgets(name,100,stdin); name[strcspn(name,"\n")]=0;
            printf("Enter email: "); fgets(email,100,stdin); email[strcspn(email,"\n")]=0;
            printf("Enter phone: "); fgets(phone,20,stdin); phone[strcspn(phone,"\n")]=0;
            printf("Enter town: "); fgets(town,50,stdin); town[strcspn(town,"\n")]=0;
            added = 1;
            printf("Supplier added!\n");
        } else if(sChoice == 2) {
            if(!added) printf("No supplier yet!\n");
            else printf("\nName: %s\nEmail: %s\nPhone: %s\nTown: %s\nLength: %lu\n", name,email,phone,town, strlen(name));
        } else if(sChoice == 3) {
            printf("Search: "); fgets(search,100,stdin); search[strcspn(search,"\n")]=0;
            if(strcmp(search,name)==0) printf("Supplier found.\n");
            else printf("Supplier not found.\n");
        } else if(sChoice == 4) {
            break;
        }
    }
}

int main() {
    int choice;
    int employeeIDs[] = {101,102,103,104,105};

    displayWelcome();

    while(1) {
        displayMenu();
        scanf("%d", &choice);

        if(choice == 1) {
            float b,h,t;
            printf("Basic: "); scanf("%f",&b);
            printf("Housing: "); scanf("%f",&h);
            printf("Transport: "); scanf("%f",&t);
            printf("Gross Salary: %.2f\n", calculateSalary(b,h,t));
        } else if(choice == 2) {
            float amt; printf("Enter amount: "); scanf("%f",&amt);
            printf("VAT: %.2f\n", calculateVAT(amt));
        } else if(choice == 3) {
            float r,e, res; printf("Revenue: "); scanf("%f",&r);
            printf("Expenses: "); scanf("%f",&e);
            res = calculateBudget(r,e);
            printf("Budget: %.2f - ", res);
            if(res>0) printf("SURPLUS\n"); else if(res<0) printf("DEFICIT\n"); else printf("BALANCED\n");
        } else if(choice == 4) {
            int id, pos; printf("Enter employee ID: "); scanf("%d",&id);
            pos = searchEmployee(id, employeeIDs, 5);
            if(pos!=-1) printf("Found at position %d\n", pos); else printf("Not found\n");
        } else if(choice == 5) {
            supplierManagement();
        } else if(choice == 6) {
            printf("Exiting...\n"); break;
        }
    }
    return 0;
}