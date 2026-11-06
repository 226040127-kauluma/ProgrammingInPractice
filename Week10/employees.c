#include <stdio.h>
#include <string.h>
#include "employees.h"

int employeeID[100];
char employeeName[100][50];
char department[100][50];
char qualification[100][100];
char gender[100][20];
char phoneNumber[100][20];
int age[100];
float workingHours[100];
float basicSalary[100];
float housingAllowance[100];
float transportAllowance[100];
float otherAllowance[100];

int employeeMenu(int count)
{
    int choice;
    int id;
    int position;
    do {
        printf("\n====================================\n");
        printf("       EMPLOYEE MANAGEMENT\n");
        printf("====================================\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit Employee Management\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) count = addEmployee(count);
        else if (choice == 2) displayEmployees(count);
        else if (choice == 3) {
            printf("\n========== SEARCH EMPLOYEE ==========\n");
            printf("Enter Employee ID: ");
            scanf("%d", &id);
            position = searchEmployee(id, employeeID, count);
            if (position == -1) printf("\nEmployee with ID %d was not found.\n", id);
            else { printf("\nEmployee Found!\n"); displayEmployee(position); }
        }
        else if (choice == 4) printf("\nLeaving Employee Management...\n");
        else printf("\nInvalid choice. Please try again.\n");
    } while (choice != 4);
    return count;
}

int addEmployee(int count)
{
    if (count >= 100) { printf("\nEmployee list is full!\n"); return count; }
    printf("\n========== ADD EMPLOYEE ==========\n");
    printf("Enter Employee ID: ");
    scanf("%d", &employeeID[count]);
    getchar();
    printf("Enter Employee Name: ");
    fgets(employeeName[count], 50, stdin);
    employeeName[count][strcspn(employeeName[count], "\n")] = '\0';
    printf("Enter Department: ");
    fgets(department[count], 50, stdin);
    department[count][strcspn(department[count], "\n")] = '\0';
    printf("Enter Qualification: ");
    fgets(qualification[count], 100, stdin);
    qualification[count][strcspn(qualification[count], "\n")] = '\0';
    printf("Enter Gender: ");
    fgets(gender[count], 20, stdin);
    gender[count][strcspn(gender[count], "\n")] = '\0';
    printf("Enter Phone Number: ");
    fgets(phoneNumber[count], 20, stdin);
    phoneNumber[count][strcspn(phoneNumber[count], "\n")] = '\0';
    printf("Enter Age: ");
    scanf("%d", &age[count]);
    while (age[count] < 0) { printf("Age cannot be negative.\nEnter Age again: "); scanf("%d", &age[count]); }
    printf("Enter Working Hours: ");
    scanf("%f", &workingHours[count]);
    while (workingHours[count] < 0) { printf("Working hours cannot be negative.\nEnter Working Hours again: "); scanf("%f", &workingHours[count]); }
    printf("Enter Basic Salary: N$ ");
    scanf("%f", &basicSalary[count]);
    while (basicSalary[count] < 0) { printf("Salary cannot be negative.\nEnter Basic Salary again: N$ "); scanf("%f", &basicSalary[count]); }
    printf("Enter Housing Allowance: N$ ");
    scanf("%f", &housingAllowance[count]);
    while (housingAllowance[count] < 0) { printf("Allowance cannot be negative.\nEnter Housing Allowance again: N$ "); scanf("%f", &housingAllowance[count]); }
    printf("Enter Transport Allowance: N$ ");
    scanf("%f", &transportAllowance[count]);
    while (transportAllowance[count] < 0) { printf("Allowance cannot be negative.\nEnter Transport Allowance again: N$ "); scanf("%f", &transportAllowance[count]); }
    printf("Enter Other Allowance: N$ ");
    scanf("%f", &otherAllowance[count]);
    while (otherAllowance[count] < 0) { printf("Allowance cannot be negative.\nEnter Other Allowance again: N$ "); scanf("%f", &otherAllowance[count]); }
    printf("\nEmployee added successfully!\n");
    return count + 1;
}

void displayEmployees(int count)
{
    int i;
    if (count == 0) { printf("\nNo employees have been added.\n"); return; }
    printf("\n========== EMPLOYEE LIST ==========\n");
    for (i = 0; i < count; i++) {
        printf("\nEmployee %d\n", i + 1);
        printf("Employee ID: %d\n", employeeID[i]);
        printf("Name: %s\n", employeeName[i]);
        printf("Department: %s\n", department[i]);
        printf("Qualification: %s\n", qualification[i]);
        printf("Gender: %s\n", gender[i]);
        printf("Phone Number: %s\n", phoneNumber[i]);
        printf("Age: %d\n", age[i]);
        printf("Working Hours: %.2f hours\n", workingHours[i]);
        printf("Basic Salary: N$ %.2f\n", basicSalary[i]);
        printf("Housing Allowance: N$ %.2f\n", housingAllowance[i]);
        printf("Transport Allowance: N$ %.2f\n", transportAllowance[i]);
        printf("Other Allowance: N$ %.2f\n", otherAllowance[i]);
    }
}

int searchEmployee(int id, int ids[], int size)
{
    int i;
    for (i = 0; i < size; i++) if (ids[i] == id) return i;
    return -1;
}

void displayEmployee(int position)
{
    printf("Employee ID: %d\n", employeeID[position]);
    printf("Name: %s\n", employeeName[position]);
    printf("Department: %s\n", department[position]);
    printf("Qualification: %s\n", qualification[position]);
    printf("Gender: %s\n", gender[position]);
    printf("Phone Number: %s\n", phoneNumber[position]);
    printf("Age: %d\n", age[position]);
    printf("Working Hours: %.2f hours\n", workingHours[position]);
    printf("Basic Salary: N$ %.2f\n", basicSalary[position]);
    printf("Housing Allowance: N$ %.2f\n", housingAllowance[position]);
    printf("Transport Allowance: N$ %.2f\n", transportAllowance[position]);
    printf("Other Allowance: N$ %.2f\n", otherAllowance[position]);
}

float calculateSalary(float basic, float housing, float transport, float other)
{
    return basic + housing + transport + other;
}