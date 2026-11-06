#include <stdio.h>
#include "records.h"

void addEmployee(Employee employees[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Employee list is full!\n");
        return;
    }
    Employee *e = &employees[*count];
    printf("Enter ID: ");
    scanf("%d", &e->id);
    printf("Enter name: ");
    scanf("%29s", e->name);
    printf("Enter department: ");
    scanf("%19s", e->department);
    printf("Enter salary: ");
    scanf("%lf", &e->salary);
    (*count)++;
    printf("Employee added.\n");
}

void displayEmployees(Employee employees[], int count) {
    int i;
    if (count == 0) { printf("No employees.\n"); return; }
    printf("\n%-5s %-20s %-15s %10s\n", "ID", "Name", "Department", "Salary");
    for (i = 0; i < count; i++)
        printf("%-5d %-20s %-15s %10.2f\n",
            employees[i].id, employees[i].name,
            employees[i].department, employees[i].salary);
}

void addSupplier(Supplier suppliers[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Supplier list is full!\n");
        return;
    }
    Supplier *s = &suppliers[*count];
    printf("Enter ID: ");
    scanf("%d", &s->id);
    printf("Enter name: ");
    scanf("%39s", s->name);
    printf("Enter email: ");
    scanf("%39s", s->email);
    printf("Enter phone: ");
    scanf("%14s", s->phone);
    printf("Enter town: ");
    scanf("%19s", s->town);
    (*count)++;
    printf("Supplier added.\n");
}

void displaySuppliers(Supplier suppliers[], int count) {
    int i;
    if (count == 0) { printf("No suppliers.\n"); return; }
    printf("\n%-5s %-20s %-25s %-15s %-15s\n", "ID", "Name", "Email", "Phone", "Town");
    for (i = 0; i < count; i++)
        printf("%-5d %-20s %-25s %-15s %-15s\n",
            suppliers[i].id, suppliers[i].name, suppliers[i].email,
            suppliers[i].phone, suppliers[i].town);
}

void addAsset(Asset assets[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Asset list is full!\n");
        return;
    }
    Asset *a = &assets[*count];
    printf("Enter ID: ");
    scanf("%d", &a->id);
    printf("Enter description: ");
    scanf("%39s", a->description);
    printf("Enter value: ");
    scanf("%lf", &a->value);
    printf("Enter acquired date (day month year): ");
    scanf("%d %d %d", &a->acquired.day, &a->acquired.month, &a->acquired.year);
    (*count)++;
    printf("Asset added.\n");
}

void displayAssets(Asset assets[], int count) {
    int i;
    if (count == 0) { printf("No assets.\n"); return; }
    printf("\n%-5s %-20s %10s %12s\n", "ID", "Description", "Value", "Acquired");
    for (i = 0; i < count; i++)
        printf("%-5d %-20s %10.2f %02d/%02d/%04d\n",
            assets[i].id, assets[i].description, assets[i].value,
            assets[i].acquired.day, assets[i].acquired.month, assets[i].acquired.year);
}

void addBudget(Budget budgets[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Budget list is full!\n");
        return;
    }
    Budget *b = &budgets[*count];
    printf("Enter ID: ");
    scanf("%d", &b->id);
    printf("Enter department: ");
    scanf("%19s", b->department);
    printf("Enter allocated: ");
    scanf("%lf", &b->allocated);
    printf("Enter spent: ");
    scanf("%lf", &b->spent);
    (*count)++;
    printf("Budget added.\n");
}

void displayBudgets(Budget budgets[], int count) {
    int i;
    if (count == 0) { printf("No budgets.\n"); return; }
    printf("\n%-5s %-15s %12s %12s %12s\n", "ID", "Department", "Allocated", "Spent", "Balance");
    for (i = 0; i < count; i++)
        printf("%-5d %-15s %12.2f %12.2f %12.2f\n",
            budgets[i].id, budgets[i].department, budgets[i].allocated,
            budgets[i].spent, budgets[i].allocated - budgets[i].spent);
}

void addProject(Project projects[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Project list is full!\n");
        return;
    }
    Project *p = &projects[*count];
    printf("Enter ID: ");
    scanf("%d", &p->id);
    printf("Enter title: ");
    scanf("%39s", p->title);
    printf("Enter budget: ");
    scanf("%lf", &p->budget);
    printf("Enter start date (day month year): ");
    scanf("%d %d %d", &p->startDate.day, &p->startDate.month, &p->startDate.year);
    printf("Enter end date (day month year): ");
    scanf("%d %d %d", &p->endDate.day, &p->endDate.month, &p->endDate.year);
    (*count)++;
    printf("Project added.\n");
}

void displayProjects(Project projects[], int count) {
    int i;
    if (count == 0) { printf("No projects.\n"); return; }
    printf("\n%-5s %-20s %10s %12s %12s\n", "ID", "Title", "Budget", "Start", "End");
    for (i = 0; i < count; i++)
        printf("%-5d %-20s %10.2f %02d/%02d/%04d %02d/%02d/%04d\n",
            projects[i].id, projects[i].title, projects[i].budget,
            projects[i].startDate.day, projects[i].startDate.month, projects[i].startDate.year,
            projects[i].endDate.day, projects[i].endDate.month, projects[i].endDate.year);
}

void saveEmployees(Employee employees[], int count) {
    FILE *f = fopen("employees.dat", "wb");
    if (f == NULL) { printf("Could not save employees.\n"); return; }
    fwrite(&count, sizeof(int), 1, f);
    fwrite(employees, sizeof(Employee), count, f);
    fclose(f);
    printf("Employees saved.\n");
}

void loadEmployees(Employee employees[], int *count) {
    FILE *f = fopen("employees.dat", "rb");
    if (f == NULL) { printf("No saved employees found.\n"); return; }
    fread(count, sizeof(int), 1, f);
    fread(employees, sizeof(Employee), *count, f);
    fclose(f);
    printf("Employees loaded: %d\n", *count);
}