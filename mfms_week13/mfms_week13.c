#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

void swapSalary(Employee *a, Employee *b) {
    double temp = a->salary;
    a->salary = b->salary;
    b->salary = temp;
}

int main(void)
{
    Employee *employees = NULL;
    Employee *bigger;
    int count = 0;
    int capacity = 2;
    int choice;
    int i;
    int id;
    int searchId;
    int found;
    Employee e;
    FILE *fp;

    employees = malloc(capacity * sizeof(Employee));
    if (employees == NULL) {
        printf("Out of memory!\n");
        return 1;
    }

    /* Load from file if it exists */
    fp = fopen("employees.dat", "rb");
    if (fp != NULL) {
        while (fread(&e, sizeof(Employee), 1, fp) == 1) {
            if (count == capacity) {
                capacity = capacity * 2;
                bigger = realloc(employees, capacity * sizeof(Employee));
                if (bigger == NULL) {
                    printf("Out of memory!\n");
                    free(employees);
                    fclose(fp);
                    return 1;
                }
                employees = bigger;
            }
            employees[count] = e;
            count++;
        }
        fclose(fp);
        printf("Loaded %d employees. Capacity: %d\n", count, capacity);
    }

    do {
        printf("\n=== MFMS - Week 13 ===\n");
        printf("1. Add Employee\n");
        printf("2. List Employees\n");
        printf("3. Swap Salaries (Pointers)\n");
        printf("4. Update Salary by ID\n");
        printf("5. Save and Exit\n");
        printf("6. Search by ID\n");
        printf("0. Exit without Saving\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Employee ID: ");
                scanf("%d", &e.id);
                printf("Name: ");
                scanf("%29s", e.name);
                printf("Salary: ");
                scanf("%lf", &e.salary);

                /* Week 13: grow if full */
                if (count == capacity) {
                    capacity = capacity * 2;
                    bigger = realloc(employees, capacity * sizeof(Employee));
                    if (bigger == NULL) {
                        printf("Out of memory!\n");
                        free(employees);
                        return 1;
                    }
                    employees = bigger;
                    printf("(grown to %d slots)\n", capacity);
                }
                employees[count] = e;
                count++;
                printf("Added. Employees: %d | Capacity: %d\n", count, capacity);
                break;

            case 2:
                if (count == 0) {
                    printf("No employees.\n");
                } else {
                    for (i = 0; i < count; i++) {
                        printf("%d  %s  N$%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
                    }
                }
                printf("Employees: %d | Capacity: %d\n", count, capacity);
                break;

            case 3:
                if (count < 2) {
                    printf("Need at least 2 employees.\n");
                } else {
                    printf("Enter first ID: ");
                    scanf("%d", &id);
                    printf("Enter second ID: ");
                    scanf("%d", &searchId);
                    {
                        Employee *p1 = NULL;
                        Employee *p2 = NULL;
                        for (i = 0; i < count; i++) {
                            if (employees[i].id == id) p1 = &employees[i];
                            if (employees[i].id == searchId) p2 = &employees[i];
                        }
                        if (p1 == NULL || p2 == NULL) {
                            printf("Employee not found.\n");
                        } else {
                            swapSalary(p1, p2);
                            printf("Salaries swapped.\n");
                        }
                    }
                }
                break;

            case 4:
                printf("Enter employee ID to update: ");
                scanf("%d", &id);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (employees[i].id == id) {
                        printf("Current: %s N$%.2f\n", employees[i].name, employees[i].salary);
                        printf("Enter new salary: ");
                        scanf("%lf", &employees[i].salary);
                        printf("%s now earns N$%.2f\n", employees[i].name, employees[i].salary);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Employee not found.\n");
                break;

            case 6:
                /* TASK 8: Search by ID */
                printf("Enter employee ID to search: ");
                scanf("%d", &searchId);
                found = 0;
                for (i = 0; i < count; i++) {
                    if (employees[i].id == searchId) {
                        printf("Found: %d  %s  N$%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Employee not found.\n");
                break;

            case 5:
                fp = fopen("employees.dat", "wb");
                if (fp == NULL) {
                    printf("Could not save file.\n");
                } else {
                    fwrite(employees, sizeof(Employee), count, fp);
                    fclose(fp);
                    printf("Saved %d employees.\n", count);
                }
                free(employees);
                return 0;

            case 0:
                free(employees);
                printf("Exited without saving.\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}