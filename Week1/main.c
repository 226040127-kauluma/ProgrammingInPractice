#include <stdio.h>

int main()
{
    // exercise1
    printf("Municipal Financial Management System\n");
    printf("Welcome to Windhoek Municipality\n\n");

    // exercise2
    char municipality[50];
    char mayor[50];
    int population;

    printf("Enter Municipality Name: ");
    scanf("%49s", municipality);
    printf("Enter Mayor: ");
    scanf("%49s", mayor);
    printf("Enter Population: ");
    scanf("%d", &population);

    printf("\n------------------------------------\n");
    printf("Municipality : %s\n", municipality);
    printf("Mayor : %s\n", mayor);
    printf("Population : %d\n", population);

    return 0;
}