#include <stdio.h>
#include <string.h>
#include "budget.h"
#include "utilities.h"

typedef struct {
    char name[MAX_DEPT_NAME];
    double allocated;
    double expenditure;
} Department;

static Department departments[MAX_DEPARTMENTS];
static int departmentCount = 0;

static void budgetFlushLine(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static int budgetFindDepartment(const char *name) {
    int i;
    for (i = 0; i < departmentCount; i++) {
        if (strcmp(departments[i].name, name) == 0) return i;
    }
    return -1;
}

static int budgetReadName(char name[]) {
    char line[200];
    int length, i, hasText = 0;
    printf("Department name: ");
    if (fgets(line, sizeof(line), stdin) == NULL) return -1;
    length = strcspn(line, "\n");
    if (line[length] == '\0') budgetFlushLine();
    line[length] = '\0';
    for (i = 0; i < length; i++) if (line[i] != ' ' && line[i] != '\t') hasText = 1;
    if (hasText == 0) { printf("Error: name cannot be empty.\n"); return 0; }
    if (strlen(line) >= MAX_DEPT_NAME) { printf("Error: name too long.\n"); return 0; }
    strcpy(name, line);
    return 1;
}

static double budgetReadAmount(char prompt[], int allowZero) {
    double amount; int result;
    while (1) {
        printf("%s", prompt);
        result = scanf("%lf", &amount);
        if (result == EOF) { printf("\nInput closed.\n"); return -1.0; }
        budgetFlushLine();
        if (result != 1) printf(" Error: please enter a valid number.\n");
        else if (amount < 0) printf(" Error: amount cannot be negative.\n");
        else if (amount == 0 && allowZero == 0) printf(" Error: amount must be greater than zero.\n");
        else return amount;
    }
}

static int budgetReadChoice(void) {
    int choice, result;
    printf("Enter your choice: ");
    result = scanf("%d", &choice);
    if (result == EOF) { printf("\nInput closed.\n"); return 6; }
    budgetFlushLine();
    if (result != 1) return -1;
    return choice;
}

double calculateRemainingBudget(double allocated, double expenditure) {
    return allocated - expenditure;
}
int isWithinBudget(double allocated, double expenditure) {
    return expenditure <= allocated;
}
int getDepartmentCount(void) { return departmentCount; }

double getTotalAllocated(void) {
    double total = 0; int i;
    for (i = 0; i < departmentCount; i++) total += departments[i].allocated;
    return total;
}
double getTotalExpenditure(void) {
    double total = 0; int i;
    for (i = 0; i < departmentCount; i++) total += departments[i].expenditure;
    return total;
}
double getTotalRemaining(void) { return getTotalAllocated() - getTotalExpenditure(); }

int countExceededDepartments(void) {
    int count = 0, i;
    for (i = 0; i < departmentCount; i++) {
        if (!isWithinBudget(departments[i].allocated, departments[i].expenditure)) count++;
    }
    return count;
}

void enterDepartmentBudget(void) {
    char name[MAX_DEPT_NAME];
    double allocated;
    int r, idx;
    if (departmentCount >= MAX_DEPARTMENTS) { printf("\nDepartment list is full!\n"); return; }
    printf("\n========== ADD DEPARTMENT BUDGET ==========\n");
    r = budgetReadName(name);
    if (r != 1) return;
    idx = budgetFindDepartment(name);
    if (idx != -1) { printf("Error: Department '%s' already exists.\n", name); return; }
    allocated = budgetReadAmount("Enter Allocated Budget: N$ ", 0);
    if (allocated < 0) return;
    strcpy(departments[departmentCount].name, name);
    departments[departmentCount].allocated = allocated;
    departments[departmentCount].expenditure = 0;
    departmentCount++;
    printf("\nDepartment budget added successfully!\n");
}

void enterExpenditure(void) {
    char name[MAX_DEPT_NAME];
    double amount;
    int r, idx;
    if (departmentCount == 0) { printf("\nNo departments yet.\n"); return; }
    printf("\n========== ENTER EXPENDITURE ==========\n");
    r = budgetReadName(name);
    if (r != 1) return;
    idx = budgetFindDepartment(name);
    if (idx == -1) { printf("Department '%s' not found.\n", name); return; }
    amount = budgetReadAmount("Enter Expenditure Amount: N$ ", 0);
    if (amount < 0) return;
    departments[idx].expenditure += amount;
    printf("\nExpenditure recorded. New total: N$ %.2f\n", departments[idx].expenditure);
    if (!isWithinBudget(departments[idx].allocated, departments[idx].expenditure))
        printf("WARNING: Department '%s' has EXCEEDED its budget!\n", name);
}

void displayBudgetInfo(void) {
    int i;
    if (departmentCount == 0) { printf("\nNo departments have been added.\n"); return; }
    printf("\n========== BUDGET INFORMATION ==========\n");
    for (i = 0; i < departmentCount; i++) {
        double rem = calculateRemainingBudget(departments[i].allocated, departments[i].expenditure);
        printf("\nDepartment: %s\n", departments[i].name);
        printf("Allocated: N$ %.2f\n", departments[i].allocated);
        printf("Expenditure: N$ %.2f\n", departments[i].expenditure);
        printf("Remaining: N$ %.2f\n", rem);
        printf("Status: %s\n", isWithinBudget(departments[i].allocated, departments[i].expenditure) ? "Within Budget" : "EXCEEDED");
    }
}

void searchDepartmentBudget(void) {
    char name[MAX_DEPT_NAME];
    int r, idx;
    printf("\n========== SEARCH DEPARTMENT BUDGET ==========\n");
    r = budgetReadName(name);
    if (r != 1) return;
    idx = budgetFindDepartment(name);
    if (idx == -1) { printf("\nDepartment '%s' not found.\n", name); return; }
    printf("\nDepartment Found!\n");
    printf("Department: %s\n", departments[idx].name);
    printf("Allocated: N$ %.2f\n", departments[idx].allocated);
    printf("Expenditure: N$ %.2f\n", departments[idx].expenditure);
    printf("Remaining: N$ %.2f\n", calculateRemainingBudget(departments[idx].allocated, departments[idx].expenditure));
}

void displayExceededDepartments(void) {
    int i, found = 0;
    printf("\n========== EXCEEDED DEPARTMENTS ==========\n");
    for (i = 0; i < departmentCount; i++) {
        if (!isWithinBudget(departments[i].allocated, departments[i].expenditure)) {
            printf("Department: %s | Allocated: N$ %.2f | Spent: N$ %.2f | Over by: N$ %.2f\n",
                departments[i].name, departments[i].allocated, departments[i].expenditure,
                departments[i].expenditure - departments[i].allocated);
            found = 1;
        }
    }
    if (!found) printf("No departments have exceeded their budget.\n");
}

void displayBudgetReport(void) {
    printf("\n========== BUDGET REPORT ==========\n");
    printf("Total Departments: %d\n", getDepartmentCount());
    printf("Total Allocated: N$ %.2f\n", getTotalAllocated());
    printf("Total Expenditure: N$ %.2f\n", getTotalExpenditure());
    printf("Total Remaining: N$ %.2f\n", getTotalRemaining());
    printf("Departments Exceeded: %d\n", countExceededDepartments());
}

void budgetMenu(void) {
    int choice;
    do {
        printf("\n====================================\n");
        printf("       BUDGET MANAGEMENT\n");
        printf("====================================\n");
        printf("1. Enter Department Budget\n");
        printf("2. Enter Expenditure\n");
        printf("3. Display Budget Info\n");
        printf("4. Search Department Budget\n");
        printf("5. Display Exceeded Departments\n");
        printf("6. Back to Main Menu\n");
        choice = budgetReadChoice();
        switch (choice) {
            case 1: enterDepartmentBudget(); break;
            case 2: enterExpenditure(); break;
            case 3: displayBudgetInfo(); break;
            case 4: searchDepartmentBudget(); break;
            case 5: displayExceededDepartments(); break;
            case 6: printf("\nReturning to main menu...\n"); break;
            default: printf("\nInvalid choice. Please try again.\n"); break;
        }
    } while (choice != 6);
}