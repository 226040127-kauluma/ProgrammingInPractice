#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

int main(void)
{
    int capacity = 2;   /* slots available */
    int count = 0;      /* slots used */
    int i;
    Employee *employees = NULL;
    Employee *bigger;
    Employee e;

    /* TODO 1: use malloc() to get room for 'capacity' employees */
    employees = malloc(capacity * sizeof(Employee));
    if (employees == NULL) {
        printf("Out of memory!\n");
        return 1;
    }

    printf("Employee ID (0 to stop): ");
    scanf("%d", &e.id);

    while (e.id != 0) {
        printf("Name: ");
        scanf("%29s", e.name);
        printf("Salary: ");
        scanf("%lf", &e.salary);

        /* TODO 2: if count == capacity, double the capacity with realloc() */
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

        /* TODO 3: store e in employees[count], then add 1 to count */
        employees[count] = e;
        count++;

        printf("Employee ID (0 to stop): ");
        scanf("%d", &e.id);
    }

    /* TODO 4: print every employee, then Employees: <count> | Capacity: <capacity> */
    for (i = 0; i < count; i++) {
        printf("%d  %s  N$%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
    printf("Employees: %d | Capacity: %d\n", count, capacity);

    /* TODO 5: give the memory back */
    free(employees);

    return 0;
}