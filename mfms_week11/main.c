#include <stdio.h>
#include "records.h"

int main(void) {
    Employee employees[MAX_RECORDS];
    Supplier suppliers[MAX_RECORDS];
    Asset assets[MAX_RECORDS];
    Budget budgets[MAX_RECORDS];
    Project projects[MAX_RECORDS];

    int employeeCount = 0, supplierCount = 0, assetCount = 0;
    int budgetCount = 0, projectCount = 0;
    int choice;

    loadEmployees(employees, &employeeCount);

    do {
        printf("\n=== MFMS - Week 11 ===\n");
        printf("Employees: %d | Suppliers: %d | Assets: %d | Budgets: %d | Projects: %d\n",
            employeeCount, supplierCount, assetCount, budgetCount, projectCount);
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Add Supplier\n");
        printf("4. Display Suppliers\n");
        printf("5. Add Asset\n");
        printf("6. Display Assets\n");
        printf("7. Add Budget\n");
        printf("8. Display Budgets\n");
        printf("9. Add Project\n");
        printf("10. Display Projects\n");
        printf("11. Save Employees\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(employees, &employeeCount); break;
            case 2: displayEmployees(employees, employeeCount); break;
            case 3: addSupplier(suppliers, &supplierCount); break;
            case 4: displaySuppliers(suppliers, supplierCount); break;
            case 5: addAsset(assets, &assetCount); break;
            case 6: displayAssets(assets, assetCount); break;
            case 7: addBudget(budgets, &budgetCount); break;
            case 8: displayBudgets(budgets, budgetCount); break;
            case 9: addProject(projects, &projectCount); break;
            case 10: displayProjects(projects, projectCount); break;
            case 11: saveEmployees(employees, employeeCount); break;
            case 0: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}