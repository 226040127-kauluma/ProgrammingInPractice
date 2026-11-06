#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "assets.h"

static void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static void readNonEmptyString(const char *prompt, char *dest, int size) {
    while (1) {
        printf("%s", prompt);
        if (fgets(dest, size, stdin) == NULL) {
            printf("Input error. Try again.\n");
            continue;
        }
        dest[strcspn(dest, "\n")] = '\0';
        if (strlen(dest) == 0) {
            printf("Input cannot be empty. Try again.\n");
            continue;
        }
        return;
    }
}

static double readNonNegativeDouble(const char *prompt) {
    double value;
    char   line[64];

    while (1) {
        printf("%s", prompt);
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("Input error. Try again.\n");
            continue;
        }
        line[strcspn(line, "\n")] = '\0';

        if (strlen(line) == 0) {
            printf("Input cannot be empty. Try again.\n");
            continue;
        }

        char *end;
        value = strtod(line, &end);

        if (*end != '\0') {
            printf("Invalid number. Try again.\n");
            continue;
        }
        if (value < 0) {
            printf("Value cannot be negative. Try again.\n");
            continue;
        }
        return value;
    }
}

static void readCondition(const char *prompt, char *dest, int size) {
    while (1) {
        readNonEmptyString(prompt, dest, size);

        if (strcmp(dest, "Excellent") == 0 ||
            strcmp(dest, "Good")      == 0 ||
            strcmp(dest, "Fair")      == 0 ||
            strcmp(dest, "Poor")      == 0) {
            return;
        }
        printf("Invalid condition. Must be Excellent, Good, Fair, or Poor.\n");
    }
}

int searchAsset(Asset assets[], int count, char id[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(assets[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

void displayAsset(Asset a) {
    printf("----------------------------------------\n");
    printf("Asset ID:        %s\n",   a.id);
    printf("Asset Name:      %s\n",   a.name);
    printf("Asset Type:      %s\n",   a.type);
    printf("Purchase Value:  N$%.2f\n", a.purchaseValue);
    printf("Department:      %s\n",   a.department);
    printf("Condition:       %s\n",   a.condition);
    printf("----------------------------------------\n");
}

void displayAssets(Asset assets[], int count) {
    if (count == 0) {
        printf("No assets registered.\n");
        return;
    }
    printf("\n===== ALL ASSETS (%d) =====\n", count);
    for (int i = 0; i < count; i++) {
        displayAsset(assets[i]);
    }
}

void addAsset(Asset assets[], int *count) {
    if (*count >= MAX_ASSETS) {
        printf("Error: Asset register is full (%d max).\n", MAX_ASSETS);
        return;
    }

    Asset a;

    /* --- ID: non-empty and unique --- */
    while (1) {
        readNonEmptyString("Enter Asset ID: ", a.id, MAX_AST_ID);

        if (searchAsset(assets, *count, a.id) != -1) {
            printf("Asset ID '%s' already exists. Try again.\n", a.id);
        } else {
            break;
        }
    }

    readNonEmptyString("Enter Asset Name: ", a.name, MAX_AST_NAME);

    readNonEmptyString("Enter Asset Type (Vehicle/Computer/Building/Equipment/Furniture): ",
                       a.type, MAX_AST_TYPE);

    a.purchaseValue = readNonNegativeDouble("Enter Purchase Value (N$): ");

    readNonEmptyString("Enter Department: ", a.department, MAX_AST_DEPT);

    readCondition("Enter Condition (Excellent/Good/Fair/Poor): ",
                  a.condition, MAX_CONDITION);

    assets[*count] = a;
    (*count)++;

    printf("\nAsset '%s' added successfully.\n", a.name);
}

void searchAssetMenu(Asset assets[], int count) {
    if (count == 0) {
        printf("No assets registered.\n");
        return;
    }

    char id[MAX_AST_ID];
    readNonEmptyString("Enter Asset ID to search: ", id, MAX_AST_ID);

    int idx = searchAsset(assets, count, id);
    if (idx == -1) {
        printf("Asset with ID '%s' not found.\n", id);
    } else {
        printf("\nAsset found:\n");
        displayAsset(assets[idx]);
    }
}

double getTotalAssetValue(Asset assets[], int count) {
    double total = 0;
    for (int i = 0; i < count; i++) {
        total += assets[i].purchaseValue;
    }
    return total;
}

double getAverageAssetValue(Asset assets[], int count) {
    if (count == 0) return 0;
    return getTotalAssetValue(assets, count) / count;
}

double getHighestAssetValue(Asset assets[], int count) {
    if (count == 0) return 0;
    double max = assets[0].purchaseValue;
    for (int i = 1; i < count; i++) {
        if (assets[i].purchaseValue > max) max = assets[i].purchaseValue;
    }
    return max;
}

double getLowestAssetValue(Asset assets[], int count) {
    if (count == 0) return 0;
    double min = assets[0].purchaseValue;
    for (int i = 1; i < count; i++) {
        if (assets[i].purchaseValue < min) min = assets[i].purchaseValue;
    }
    return min;
}

int countAssetsByCondition(Asset assets[], int count, const char *condition) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(assets[i].condition, condition) == 0) total++;
    }
    return total;
}

void handleAssetMenu(Asset assets[], int *count) {
    int  choice;

    do {
        printf("\n--- ASSET MANAGEMENT ---\n");
        printf("1. Add Asset\n");
        printf("2. Display All Assets\n");
        printf("3. Search Asset\n");
        printf("4. Asset Summary Report\n");
        printf("5. Back to Main Menu\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearBuffer();
            choice = 0;
            continue;
        }
        clearBuffer();

        switch (choice) {
            case 1:
                addAsset(assets, count);
                break;

            case 2:
                displayAssets(assets, *count);
                break;

            case 3:
                searchAssetMenu(assets, *count);
                break;

            case 4:
                if (*count == 0) {
                    printf("No assets registered.\n");
                } else {
                    printf("\n===== ASSET SUMMARY =====\n");
                    printf("Total Assets:      %d\n",    *count);
                    printf("Total Value:       N$%.2f\n", getTotalAssetValue(assets, *count));
                    printf("Average Value:     N$%.2f\n", getAverageAssetValue(assets, *count));
                    printf("Highest Value:     N$%.2f\n", getHighestAssetValue(assets, *count));
                    printf("Lowest Value:      N$%.2f\n", getLowestAssetValue(assets, *count));
                    printf("\nCondition Breakdown:\n");
                    printf("  Excellent: %d\n", countAssetsByCondition(assets, *count, "Excellent"));
                    printf("  Good:      %d\n", countAssetsByCondition(assets, *count, "Good"));
                    printf("  Fair:      %d\n", countAssetsByCondition(assets, *count, "Fair"));
                    printf("  Poor:      %d\n", countAssetsByCondition(assets, *count, "Poor"));
                }
                break;

            case 5:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice. Please enter 1-5.\n");
        }
    } while (choice != 5);
}