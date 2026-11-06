#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100

int employeeMenu(int count);
int addEmployee(int count);
void displayEmployees(int count);
int searchEmployee(int id, int ids[], int size);
void displayEmployee(int position);
float calculateSalary(float basic, float housing, float transport, float other);

#endif