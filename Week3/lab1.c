#include <stdio.h>

int main() {

    // Declaration of variables 
 double basicSalary=0.00;
 double housing=0.00;
 double transport=0.00;
 double tax=0.00;
 double grossSalary=0.00;
 double netSalary=0.00;

 //Ask user to input values for basic salary
 printf("Enter basic salary: ");
 scanf("%lf", &basicSalary);

 // Ask user to input values for housing allowance
 printf("Enter housing allowance: ");
 scanf("%lf", &housing);

 // Ask user to input values for transport allowance
 printf("Enter transport allowance: ");
 scanf("%lf", &transport);

 // Ask user to input values for tax
 printf("Enter tax: ");
 scanf("%lf", &tax);

 // Calculate gross and net salaries
 grossSalary = basicSalary + housing + transport;
 netSalary = grossSalary - tax;

 // Display the results
 printf("Gross Salary: %lf\n", grossSalary);
 printf("Net Salary: %lf\n", netSalary);
 
 return 0;
}