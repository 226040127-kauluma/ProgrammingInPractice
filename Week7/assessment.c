#include <stdio.h>
#include <string.h>

int main(void) {
    char name[100], email[100], phone[20], town[50];
    char nameCopy[100], search[100];

    // 1. Accept all four fields
    printf("Enter supplier name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("Enter town: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = '\0';

    // 2. Display the information
    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name : %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town : %s\n", town);

    // 3. Display the length of the supplier name
    printf("\nSupplier name length: %zu\n", strlen(name));

    // 4. Copy the supplier name into a second variable
    strcpy(nameCopy, name);
    printf("Copied name: %s\n", nameCopy);

    // 5. Search for the supplier
    printf("\nEnter supplier name to search: ");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = '\0';

    // 6. Display an appropriate message
    if (strcmp(search, nameCopy) == 0) {
        printf("Supplier found.\n");
    } else {
        printf("Supplier not found.\n");
    }

    return 0;
}