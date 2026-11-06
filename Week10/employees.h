#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100

extern int employeeID[100];
extern char employeeName[100][50];
extern char department[100][50];
extern char qualification[100][100];
extern char gender[100][20];
extern char phoneNumber[100][20];
extern int age[100];
extern float workingHours[100];
extern float basicSalary[100];
extern float housingAllowance[100];
extern float transportAllowance[100];
extern float otherAllowance[100];

int employeeMenu(int count);
int addEmployee(int count);
void displayEmployees(int count);
int searchEmployee(int id, int ids[], int size);
void displayEmployee(int position);
float calculateSalary(float basic, float housing, float transport, float other);

#endif