#include <stdio.h>
#include <string.h>
int main() {
    char supplier1[100] = "ABC Office Supplies";
    char supplier2[100] = "Namibia Stationery";
    char search[100];
    printf("Enter supplier name to search: ");
    fgets(search, 100, stdin); search[strcspn(search, "\n")] = 0;
    if (strcmp(search, supplier1) == 0 || strcmp(search, supplier2) == 0)
        printf("\nSupplier found.\n");
    else
        printf("\nSupplier not found.\n");
    return 0;
}