#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100
#define STRING_LEN 100

typedef struct {
    int supplierID;
    char name[STRING_LEN];
    char email[STRING_LEN];
    char phone[STRING_LEN];
    char location[STRING_LEN];
} Supplier;

void addSupplier(Supplier suppliers[], int *count);
void displaySuppliers(const Supplier suppliers[], int count);
void searchSupplier(const Supplier suppliers[], int count);
void compareSuppliersByLocation(const Supplier suppliers[], int count);
void supplierMenu(Supplier suppliers[], int *count);

#endif