#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "suppliers.h"

static void trimNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') str[len - 1] = '\0';
}

void addSupplier(Supplier suppliers[], int *count) {
    if (*count >= MAX_SUPPLIERS) { printf("\n[Error] Supplier database is full!\n"); return; }
    Supplier newSupplier;
    printf("\n=== ADD NEW SUPPLIER ===\n");
    printf("Enter Supplier ID (positive integer): ");
    while (scanf("%d", &newSupplier.supplierID) != 1 || newSupplier.supplierID <= 0) {
        printf("Invalid ID. Enter a positive number: ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    for (int i = 0; i < *count; i++) {
        if (suppliers[i].supplierID == newSupplier.supplierID) {
            printf("[Error] Supplier ID %d already exists!\n", newSupplier.supplierID);
            return;
        }
    }
    do {
        printf("Enter Supplier Name: ");
        fgets(newSupplier.name, STRING_LEN, stdin);
        trimNewline(newSupplier.name);
        if (strlen(newSupplier.name) == 0) printf("Name cannot be empty. Please try again.\n");
    } while (strlen(newSupplier.name) == 0);
    printf("Enter Email: ");
    fgets(newSupplier.email, STRING_LEN, stdin);
    trimNewline(newSupplier.email);
    printf("Enter Phone Number: ");
    fgets(newSupplier.phone, STRING_LEN, stdin);
    trimNewline(newSupplier.phone);
    printf("Enter Town/Location: ");
    fgets(newSupplier.location, STRING_LEN, stdin);
    trimNewline(newSupplier.location);
    suppliers[*count] = newSupplier;
    (*count)++;
    printf("\n[Success] Supplier '%s' registered successfully!\n", newSupplier.name);
}

void displaySuppliers(const Supplier suppliers[], int count) {
    if (count == 0) { printf("\nNo suppliers registered yet.\n"); return; }
    printf("\n================================ SUPPLIER LIST ================================\n");
    printf("%-8s %-20s %-25s %-15s %-15s\n", "ID", "Name", "Email", "Phone", "Location");
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-8d %-20s %-25s %-15s %-15s\n", suppliers[i].supplierID, suppliers[i].name, suppliers[i].email, suppliers[i].phone, suppliers[i].location);
    }
    printf("-------------------------------------------------------------------------------\n");
    printf("Total Suppliers: %d\n", count);
}

void searchSupplier(const Supplier suppliers[], int count) {
    if (count == 0) { printf("\nNo suppliers available to search.\n"); return; }
    int choice;
    printf("\n=== SEARCH SUPPLIER ===\n");
    printf("1. Search by ID\n2. Search by Name\nEnter choice: ");
    if (scanf("%d", &choice) != 1) { while (getchar() != '\n'); printf("Invalid selection.\n"); return; }
    while (getchar() != '\n');
    if (choice == 1) {
        int searchID;
        printf("Enter Supplier ID to search: ");
        while (scanf("%d", &searchID) != 1) { printf("Invalid ID. Enter a number: "); while (getchar() != '\n'); }
        while (getchar() != '\n');
        for (int i = 0; i < count; i++) {
            if (suppliers[i].supplierID == searchID) {
                printf("\n[Found] ID: %d | Name: %s | Email: %s | Phone: %s | Town: %s\n", suppliers[i].supplierID, suppliers[i].name, suppliers[i].email, suppliers[i].phone, suppliers[i].location);
                return;
            }
        }
        printf("\n[Not Found] No supplier found with ID %d.\n", searchID);
    } else if (choice == 2) {
        char searchName[STRING_LEN];
        printf("Enter Supplier Name to search: ");
        fgets(searchName, STRING_LEN, stdin);
        trimNewline(searchName);
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(suppliers[i].name, searchName) == 0) {
                printf("\n[Found] ID: %d | Name: %s | Email: %s | Phone: %s | Town: %s\n", suppliers[i].supplierID, suppliers[i].name, suppliers[i].email, suppliers[i].phone, suppliers[i].location);
                found = 1;
            }
        }
        if (!found) printf("\n[Not Found] No supplier found matching name '%s'.\n", searchName);
    } else printf("Invalid search option.\n");
}

void compareSuppliersByLocation(const Supplier suppliers[], int count) {
    if (count == 0) { printf("\nNo suppliers registered.\n"); return; }
    char targetLocation[STRING_LEN];
    printf("\nEnter Town/Location to filter suppliers: ");
    fgets(targetLocation, STRING_LEN, stdin);
    trimNewline(targetLocation);
    printf("\n=== SUPPLIERS IN LOCATION: %s ===\n", targetLocation);
    int matchCount = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(suppliers[i].location, targetLocation) == 0) {
            printf("- ID: %-5d Name: %-20s Phone: %s\n", suppliers[i].supplierID, suppliers[i].name, suppliers[i].phone);
            matchCount++;
        }
    }
    if (matchCount == 0) printf("No suppliers found located in '%s'.\n", targetLocation);
    else printf("Total matching suppliers: %d\n", matchCount);
}

void supplierMenu(Supplier suppliers[], int *count) {
    int choice;
    do {
        printf("\n--- SUPPLIER MANAGEMENT MENU ---\n");
        printf("1. Add Supplier\n2. Display All Suppliers\n3. Search Supplier\n4. Filter/Compare Suppliers by Location\n5. Back to Main Menu\nEnter choice: ");
        if (scanf("%d", &choice) != 1) { printf("Invalid input. Please enter a number.\n"); while (getchar() != '\n'); continue; }
        while (getchar() != '\n');
        switch (choice) {
            case 1: addSupplier(suppliers, count); break;
            case 2: displaySuppliers(suppliers, *count); break;
            case 3: searchSupplier(suppliers, *count); break;
            case 4: compareSuppliersByLocation(suppliers, *count); break;
            case 5: printf("Returning to Main Menu...\n"); break;
            default: printf("Invalid option. Enter 1-5.\n"); break;
        }
    } while (choice != 5);
}