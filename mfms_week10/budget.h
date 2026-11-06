#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENTS   20
#define MAX_DEPT_NAME     50

void budgetMenu(void);
void enterDepartmentBudget(void);
void enterExpenditure(void);
void displayBudgetInfo(void);
void searchDepartmentBudget(void);
void displayExceededDepartments(void);

double calculateRemainingBudget(double allocated, double expenditure);
int    isWithinBudget(double allocated, double expenditure);

int    getDepartmentCount(void);
double getTotalAllocated(void);
double getTotalExpenditure(void);
double getTotalRemaining(void);
int    countExceededDepartments(void);
void   displayBudgetReport(void);

// Accessors for storage.c - Week 10
void getBudgetDepartment(int index, char name[], double *allocated, double *expenditure);
void setBudgetDepartment(int index, const char *name, double allocated, double expenditure);
void clearBudgetDepartments(void);

#endif