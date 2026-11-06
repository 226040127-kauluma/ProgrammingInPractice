#include <stdio.h>
#include "reports.h"
#include "utilities.h"
#include "budget.h"
#include "employees.h"

extern float basicSalary[100];
extern float housingAllowance[100];
extern float transportAllowance[100];
extern float otherAllowance[100];

void displayEmployeeReport(int count)
{
    int i;
    float salary;
    float total = 0;
    float highest;
    float lowest;
    printf("\n========== EMPLOYEE REPORT ==========\n");
    if (count == 0) { printf("No employees registered.\n"); return; }
    highest = calculateSalary(basicSalary[0], housingAllowance[0], transportAllowance[0], otherAllowance[0]);
    lowest = highest;
    for (i = 0; i < count; i++) {
        salary = calculateSalary(basicSalary[i], housingAllowance[i], transportAllowance[i], otherAllowance[i]);
        total += salary;
        if (salary > highest) highest = salary;
        if (salary < lowest) lowest = salary;
    }
    printf("Total Employees: %d\n", count);
    printf("Average Salary: N$ %.2f\n", total / count);
    printf("Highest Salary: N$ %.2f\n", highest);
    printf("Lowest Salary: N$ %.2f\n", lowest);
}

void displaySupplierReport(Supplier suppliers[], int count)
{
    int i;
    printf("\n========== SUPPLIER REPORT ==========\n");
    if (count == 0) { printf("No suppliers registered.\n"); return; }
    printf("Total Suppliers: %d\n", count);
    for (i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Email: %s | Phone: %s | Location: %s\n",
            suppliers[i].supplierID, suppliers[i].name, suppliers[i].email, suppliers[i].phone, suppliers[i].location);
    }
}

void displayAssetReport(Asset assets[], int count)
{
    int i;
    printf("\n========== ASSET REPORT ==========\n");
    if (count == 0) { printf("No assets registered.\n"); return; }
    printf("Total Assets: %d\n", count);
    for (i = 0; i < count; i++) {
        printf("ID: %s | Name: %s | Type: %s | Value: N$ %.2f | Department: %s | Condition: %s\n",
            assets[i].id, assets[i].name, assets[i].type, assets[i].purchaseValue, assets[i].department, assets[i].condition);
    }
}

void reportsMenu(int employeeCount, Supplier suppliers[], int supplierCount, Asset assets[], int assetCount)
{
    int choice;
    do {
        printf("\n========================================\n");
        printf("                REPORTS\n");
        printf("========================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        choice = getMenuChoice(1, 5);
        switch (choice) {
            case 1: displayEmployeeReport(employeeCount); break;
            case 2: displayBudgetReport(); break;
            case 3: displaySupplierReport(suppliers, supplierCount); break;
            case 4: displayAssetReport(assets, assetCount); break;
            case 5: printf("\nReturning to main menu...\n"); break;
        }
    } while (choice != 5);
}