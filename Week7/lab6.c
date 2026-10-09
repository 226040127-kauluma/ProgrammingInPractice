#include <stdio.h>
#include <string.h>

static void readLine(const char *prompt, char *buf, int size) {
    printf("%s", prompt);
    fgets(buf, size, stdin);
    buf[strcspn(buf, "\n")] = '\0';
}

int main(void) {
    char name[100] = "", email[100] = "", phone[20] = "", town[50] = "";
    char search[100], line[20];
    int added = 0, choice = 0;

    do {
        printf("\n==================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("==================================\n");
        printf("1. Add Supplier\n2. Display Supplier\n3. Search Supplier\n");
        printf("4. Show Name Length\n5. Exit\n");
        printf("Enter choice: ");
        fgets(line, sizeof(line), stdin);
        if (sscanf(line, "%d", &choice) != 1) choice = 0;

        switch (choice) {
        case 1:
            readLine("Enter supplier name: ", name, sizeof(name));
            readLine("Enter email: ", email, sizeof(email));
            readLine("Enter phone: ", phone, sizeof(phone));
            readLine("Enter town: ", town, sizeof(town));
            added = 1;
            printf("Supplier added.\n");
            break;
        case 2:
            if (!added) { printf("No supplier stored yet.\n"); break; }
            printf("\n--- SUPPLIER DETAILS ---\n");
            printf("Name : %s\nEmail: %s\nPhone: %s\nTown : %s\n",
                   name, email, phone, town);
            break;
        case 3:
            if (!added) { printf("No supplier stored yet.\n"); break; }
            readLine("Enter supplier name to search: ", search, sizeof(search));
            printf(strcmp(search, name) == 0 ? "Supplier found.\n"
                                             : "Supplier not found.\n");
            break;
        case 4:
            if (!added) { printf("No supplier stored yet.\n"); break; }
            printf("Supplier name length: %zu\n", strlen(name));
            break;
        case 5:
            printf("Goodbye.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 5);
    return 0;
}