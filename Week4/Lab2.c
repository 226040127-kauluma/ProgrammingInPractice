#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char supplierName[50];
    double price, budget; // CHANGED
    int registered;
    int documentsComplete;
    
    double lowestPrice = 9999.99; // CHANGED
    char preferredName[50] = "None";
    int foundQualified = 0;

    printf("Enter available budget: ");
    scanf("%lf", &budget); // %lf for double

    printf("Enter number of suppliers: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        printf("\n--- Supplier %d ---\n", i);
        
        printf("Enter supplier name: ");
        scanf("%49s", supplierName);

        printf("Enter tender price: ");
        scanf("%lf", &price); // %lf for double

        printf("Is supplier registered? (1=Yes, 0=No): ");
        scanf("%d", &registered);

        printf("Are all documents complete? (1=Yes, 0=No): ");
        scanf("%d", &documentsComplete);

        if (registered == 0 || documentsComplete == 0 || price > budget)
        {
            printf("Supplier: %s\n", supplierName);
            printf("Status: Disqualified\n");
        }
        else
        {
            printf("Supplier: %s\n", supplierName);
            printf("Status: Qualified\n");
            foundQualified = 1;

            if (price < lowestPrice)
            {
                lowestPrice = price;
                strcpy(preferredName, supplierName);
            }
        }
    }

    printf("\n======== FINAL RESULT ========\n");
    if (foundQualified == 1)
    {
        printf("Preferred Supplier: %s\n", preferredName);
        printf("Price: %.2lf\n", lowestPrice); // %.2lf = 2 decimal places
    }
    else
    {
        printf("No Qualified Suppliers. No Preferred Supplier.\n");
    }

    return 0;
}