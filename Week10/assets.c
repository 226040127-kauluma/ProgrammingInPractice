#include <stdio.h>
#include <string.h>
#include "assets.h"

static void trimNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') str[len - 1] = '\0';
}

static void readAssetString(char *buffer, int size, const char *prompt) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    trimNewline(buffer);
}

void addAsset(Asset assets[], int *count) {
    if (*count >= MAX_ASSETS) { printf("\n[Error] Asset database is full!\n"); return; }
    Asset newAsset;
    printf("\n=== ADD NEW ASSET ===\n");
    readAssetString(newAsset.id, ASSET_LEN, "Enter Asset ID: ");
    if (strlen(newAsset.id) == 0) { printf("ID cannot be empty.\n"); return; }
    for (int i = 0; i < *count; i++) {
        if (strcmp(assets[i].id, newAsset.id) == 0) {
            printf("[Error] Asset ID %s already exists!\n", newAsset.id);
            return;
        }
    }
    readAssetString(newAsset.name, ASSET_LEN, "Enter Asset Name: ");
    readAssetString(newAsset.type, ASSET_LEN, "Enter Asset Type (e.g. Vehicle, Computer, Furniture): ");
    printf("Enter Purchase Value: N$ ");
    while (scanf("%lf", &newAsset.purchaseValue) != 1 || newAsset.purchaseValue < 0) {
        printf("Invalid value. Enter a positive number: N$ ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    readAssetString(newAsset.department, ASSET_LEN, "Enter Department: ");
    readAssetString(newAsset.condition, ASSET_LEN, "Enter Condition (Good / Fair / Poor): ");
    assets[*count] = newAsset;
    (*count)++;
    printf("\n[Success] Asset '%s' registered successfully!\n", newAsset.name);
}

void displayAssets(const Asset assets[], int count) {
    if (count == 0) { printf("\nNo assets registered yet.\n"); return; }
    printf("\n========== ASSET LIST ==========\n");
    for (int i = 0; i < count; i++) {
        printf("\nAsset %d\n", i + 1);
        printf("ID: %s\n", assets[i].id);
        printf("Name: %s\n", assets[i].name);
        printf("Type: %s\n", assets[i].type);
        printf("Value: N$ %.2f\n", assets[i].purchaseValue);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);
    }
    printf("\nTotal Assets: %d\n", count);
}

void searchAsset(const Asset assets[], int count) {
    if (count == 0) { printf("\nNo assets available to search.\n"); return; }
    char searchID[ASSET_LEN];
    printf("\n=== SEARCH ASSET ===\n");
    readAssetString(searchID, ASSET_LEN, "Enter Asset ID to search: ");
    for (int i = 0; i < count; i++) {
        if (strcmp(assets[i].id, searchID) == 0) {
            printf("\n[Found] ID: %s | Name: %s | Type: %s | Value: N$ %.2f | Department: %s | Condition: %s\n",
                assets[i].id, assets[i].name, assets[i].type, assets[i].purchaseValue, assets[i].department, assets[i].condition);
            return;
        }
    }
    printf("\n[Not Found] No asset found with ID %s.\n", searchID);
}

void handleAssetMenu(Asset assets[], int *count) {
    int choice;
    do {
        printf("\n--- ASSET MANAGEMENT MENU ---\n");
        printf("1. Add Asset\n2. Display All Assets\n3. Search Asset\n4. Back to Main Menu\nEnter choice: ");
        if (scanf("%d", &choice) != 1) { printf("Invalid input. Please enter a number.\n"); while (getchar() != '\n'); continue; }
        while (getchar() != '\n');
        switch (choice) {
            case 1: addAsset(assets, count); break;
            case 2: displayAssets(assets, *count); break;
            case 3: searchAsset(assets, *count); break;
            case 4: printf("Returning to Main Menu...\n"); break;
            default: printf("Invalid option. Enter 1-4.\n"); break;
        }
    } while (choice != 4);
}