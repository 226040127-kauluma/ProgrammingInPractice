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
        printf("\n=== MFMS - Week 12 ===\n");
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
        printf("12. Update Employee Salary\n");
        printf("13. Salary Report (Swap / Highest / Average / Raise)\n");
        printf("14. Pointer Warm-up\n");
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

            case 12: {
                int searchId;
                double newSalary;
                printf("Enter employee ID: ");
                scanf("%d", &searchId);
                Employee *found = findEmployee(employees, employeeCount, searchId);
                if (found == NULL) {
                    printf("Employee not found.\n");
                } else {
                    printf("Found %s, current salary N$%.2f\n", found->name, found->salary);
                    printf("Enter new salary: ");
                    scanf("%lf", &newSalary);
                    updateSalary(found, newSalary);
                    printf("%s now earns N$%.2f\n", found->name, found->salary);
                }
                break;
            }

            case 13: {
                if (employeeCount == 0) {
                    printf("No employees yet.\n");
                    break;
                }
                double salaries[MAX_RECORDS];
                int i;
                for (i = 0; i < employeeCount; i++) {
                    salaries[i] = employees[i].salary;
                }

                printf("\n--- Before swap ---\n");
                displaySalaries(salaries, employeeCount);

                if (employeeCount >= 2) {
                    swapSalariesWrong(salaries[0], salaries[1]);
                    printf("\n--- After WRONG swap (no change) ---\n");
                    displaySalaries(salaries, employeeCount);

                    swapSalaries(&salaries[0], &salaries[1]);
                    printf("\n--- After CORRECT swap ---\n");
                    displaySalaries(salaries, employeeCount);
                }

                printf("\nHighest salary: N$%.2f\n", findHighest(salaries, employeeCount));
                printf("Average salary: N$%.2f\n", calculateAverage(salaries, employeeCount));

                printf("\n--- Before 10%% raise ---\n");
                displaySalaries(salaries, employeeCount);
                giveRaise(salaries, employeeCount, 10);
                printf("\n--- After 10%% raise ---\n");
                displaySalaries(salaries, employeeCount);
                printf("(Note: raise shown here only - real salaries unchanged until you use option 12)\n");
                break;
            }

            case 14: {
                int x = 10;
                int *p = &x;
                printf("Value: %d, Address: %p, p: %d\n", x, (void*)p, *p);
                *p = 25;
                printf("After *p = 25 -> x = %d, *p = %d\n", x, *p);

                if (employeeCount >= 2) {
                    printf("\nAddresses: staff[0]=%p, staff[1]=%p, difference=%ld bytes\n",
                        (void*)&employees[0], (void*)&employees[1],
                        (long)((char*)&employees[1] - (char*)&employees[0]));
                    printf("sizeof(Employee) = %lu bytes\n", (unsigned long)sizeof(Employee));
                }
                break;
            }

            case 0: printf("Goodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}