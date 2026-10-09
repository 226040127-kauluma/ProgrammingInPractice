#include <stdio.h>
#include <string.h>

#define MAX 5

static void readLine(const char *prompt, char *buf, int size) {
    printf("%s", prompt);
    fgets(buf, size, stdin);
    buf[strcspn(buf, "\n")] = '\0';
}

int main(void) {
    char name[MAX][100], email[MAX][100], phone[MAX][20], town[MAX][50];
    char search[100], line[20];
    int count = 0, choice = 0;

    do {
        printf("\n==================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("==================================\n");
        printf("1. Add Supplier\n2. Display Suppliers\n3. Search Supplier\n");
        printf("4. Show Name Length\n5. Exit\n");
        printf("Enter choice: ");
        fgets(line, sizeof(line), stdin);
        if (sscanf(line, "%d", &choice) != 1) choice = 0;

        switch (choice) {
        case 1:
            if (count >= MAX) { printf("Supplier list is full (%d).\n", MAX); break; }
            readLine("Enter supplier name: ", name[count], sizeof(name[count]));
            readLine("Enter email: ", email[count], sizeof(email[count]));
            readLine("Enter phone: ", phone[count], sizeof(phone[count]));
            readLine("Enter town: ", town[count], sizeof(town[count]));
            count++;
            printf("Supplier added (%d/%d).\n", count, MAX);
            break;
        case 2:
            if (count == 0) { printf("No suppliers stored yet.\n"); break; }
            for (int i = 0; i < count; i++) {
                printf("\n--- SUPPLIER %d ---\n", i + 1);
                printf("Name : %s\nEmail: %s\nPhone: %s\nTown : %s\n",
                       name[i], email[i], phone[i], town[i]);
            }
            break;
        case 3: {
            int found = -1;
            readLine("Enter supplier name to search: ", search, sizeof(search));
            for (int i = 0; i < count; i++)
                if (strcmp(search, name[i]) == 0) { found = i; break; }
            if (found >= 0) {
                printf("Supplier found.\n");
                printf("Name : %s\nEmail: %s\nPhone: %s\nTown : %s\n",
                       name[found], email[found], phone[found], town[found]);
            } else
                printf("Supplier not found.\n");
            break;
        }
        case 4:
            if (count == 0) { printf("No suppliers stored yet.\n"); break; }
            for (int i = 0; i < count; i++)
                printf("%s length: %zu\n", name[i], strlen(name[i]));
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