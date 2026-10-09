#include <stdio.h>
#include <string.h>

int main() {
    char supplierName[100];
    char email[100];
    char phone[20];
    char town[50];

    printf("Enter supplier name: ");
    fgets(supplierName, sizeof(supplierName), stdin);
    supplierName[strcspn(supplierName, "\n")] = 0;

    printf("Enter email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0;

    printf("Enter phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = 0;

    printf("Enter town: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = 0;

    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name : %s\n", supplierName);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town : %s\n", town);

    // LAB TASK 2 - String Length
    printf("\n--- STRING LENGTH ---\n");
    printf("Supplier name length: %lu\n", strlen(supplierName));
    printf("Email length: %lu\n", strlen(email));
    printf("Town length: %lu\n", strlen(town));

    return 0;
}