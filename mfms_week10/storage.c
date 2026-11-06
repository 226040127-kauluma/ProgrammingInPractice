#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#include <sys/types.h>
#endif
#include "storage.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "employees.h"
#include "utilities.h"

static void stripNewline(char *s) {
    size_t len = strlen(s);
    while (len > 0 && (s[len-1] == '\n' || s[len-1] == '\r')) s[--len] = '\0';
}

static void ensureDataDir(void) {
#ifdef _WIN32
    _mkdir("data");
#else
    mkdir("data", 0777);
#endif
}

static void copyFile(const char *src, const char *dst) {
    FILE *in = fopen(src, "rb");
    FILE *out;
    char buf[1024];
    size_t n;
    if (!in) return;
    out = fopen(dst, "wb");
    if (!out) { fclose(in); return; }
    while ((n = fread(buf, 1, sizeof(buf), in)) > 0) fwrite(buf, 1, n, out);
    fclose(in); fclose(out);
}

/* ---------- SAVE ALL ---------- */
void saveAllData(Supplier suppliers[], int supplierCount, Asset assets[], int assetCount, int employeeCount) {
    FILE *f;
    int i;
    ensureDataDir();

    // Employees - text
    f = fopen("data/employees.txt", "w");
    if (f) {
        for (i = 0; i < employeeCount; i++) {
            fprintf(f, "%d|%s|%s|%s|%s|%s|%d|%.2f|%.2f|%.2f|%.2f|%.2f\n",
                employeeID[i], employeeName[i], department[i], qualification[i],
                gender[i], phoneNumber[i], age[i], workingHours[i],
                basicSalary[i], housingAllowance[i], transportAllowance[i], otherAllowance[i]);
        }
        fclose(f);
        printf("Employees saved: %d\n", employeeCount);
    } else printf("Error: cannot save employees.txt\n");

    // Budgets - via accessors
    f = fopen("data/budgets.txt", "w");
    if (f) {
        for (i = 0; i < getDepartmentCount(); i++) {
            char bName[MAX_DEPT_NAME];
            double bAlloc, bSpent;
            getBudgetDepartment(i, bName, &bAlloc, &bSpent);
            fprintf(f, "%s|%.2f|%.2f\n", bName, bAlloc, bSpent);
        }
        fclose(f);
        printf("Budgets saved: %d\n", getDepartmentCount());
    } else printf("Error: cannot save budgets.txt\n");

    // Suppliers
    f = fopen("data/suppliers.txt", "w");
    if (f) {
        for (i = 0; i < supplierCount; i++) {
            fprintf(f, "%d|%s|%s|%s|%s\n",
                suppliers[i].supplierID,
                suppliers[i].name,
                suppliers[i].email,
                suppliers[i].phone,
                suppliers[i].location);
        }
        fclose(f);
        printf("Suppliers saved: %d\n", supplierCount);
    } else printf("Error: cannot save suppliers.txt\n");

    // Assets
    f = fopen("data/assets.txt", "w");
    if (f) {
        for (i = 0; i < assetCount; i++) {
            fprintf(f, "%s|%s|%s|%.2f|%s|%s\n",
                assets[i].id,
                assets[i].name,
                assets[i].type,
                assets[i].purchaseValue,
                assets[i].department,
                assets[i].condition);
        }
        fclose(f);
        printf("Assets saved: %d\n", assetCount);
    } else printf("Error: cannot save assets.txt\n");

    printf("\nAll data saved successfully!\n");
}

/* ---------- LOAD ALL ---------- */
void loadAllData(Supplier suppliers[], int *supplierCount, Asset assets[], int *assetCount, int *employeeCount) {
    FILE *f;
    char line[512];
    ensureDataDir();

    // Employees
    f = fopen("data/employees.txt", "r");
    if (!f) printf("No saved data found for employees (0 loaded).\n");
    else {
        int c = 0;
        while (fgets(line, sizeof(line), f) && c < MAX_EMPLOYEES) {
            stripNewline(line);
            if (sscanf(line, "%d|%49[^|]|%49[^|]|%99[^|]|%19[^|]|%19[^|]|%d|%f|%f|%f|%f|%f",
                &employeeID[c], employeeName[c], department[c], qualification[c],
                gender[c], phoneNumber[c], &age[c], &workingHours[c],
                &basicSalary[c], &housingAllowance[c], &transportAllowance[c], &otherAllowance[c]) == 12) c++;
        }
        fclose(f);
        *employeeCount = c;
        printf("Employees loaded: %d\n", c);
    }

    // Budgets
    f = fopen("data/budgets.txt", "r");
    if (!f) printf("No saved data found for budgets (0 loaded).\n");
    else {
        int c = 0;
        char bName[MAX_DEPT_NAME];
        double bAlloc, bSpent;
        clearBudgetDepartments();
        while (fgets(line, sizeof(line), f) && c < MAX_DEPARTMENTS) {
            stripNewline(line);
            if (sscanf(line, "%49[^|]|%lf|%lf", bName, &bAlloc, &bSpent) == 3) {
                setBudgetDepartment(c, bName, bAlloc, bSpent);
                c++;
            }
        }
        fclose(f);
        printf("Budgets loaded: %d\n", c);
    }

    // Suppliers
    f = fopen("data/suppliers.txt", "r");
    if (!f) printf("No saved data found for suppliers (0 loaded).\n");
    else {
        int c = 0;
        while (fgets(line, sizeof(line), f) && c < MAX_SUPPLIERS) {
            stripNewline(line);
            if (sscanf(line, "%d|%99[^|]|%99[^|]|%99[^|]|%99[^\n]",
                &suppliers[c].supplierID,
                suppliers[c].name,
                suppliers[c].email,
                suppliers[c].phone,
                suppliers[c].location) == 5) c++;
        }
        fclose(f);
        *supplierCount = c;
        printf("Suppliers loaded: %d\n", c);
    }

    // Assets
    f = fopen("data/assets.txt", "r");
    if (!f) printf("No saved data found for assets (0 loaded).\n");
    else {
        int c = 0;
        while (fgets(line, sizeof(line), f) && c < MAX_ASSETS) {
            stripNewline(line);
            if (sscanf(line, "%99[^|]|%99[^|]|%99[^|]|%lf|%99[^|]|%99[^\n]",
                assets[c].id,
                assets[c].name,
                assets[c].type,
                &assets[c].purchaseValue,
                assets[c].department,
                assets[c].condition) == 6) c++;
        }
        fclose(f);
        *assetCount = c;
        printf("Assets loaded: %d\n", c);
    }
    printf("\nAll data loaded!\n");
}

void backupData(void) {
    ensureDataDir();
    copyFile("data/employees.txt", "data/employees_backup.txt");
    copyFile("data/budgets.txt", "data/budgets_backup.txt");
    copyFile("data/suppliers.txt", "data/suppliers_backup.txt");
    copyFile("data/assets.txt", "data/assets_backup.txt");
    printf("\nBackup created successfully!\n");
}