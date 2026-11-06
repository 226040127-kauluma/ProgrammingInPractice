#ifndef STORAGE_H
#define STORAGE_H

#include "suppliers.h"
#include "assets.h"

void saveAllData(Supplier suppliers[], int supplierCount, Asset assets[], int assetCount, int employeeCount);
void loadAllData(Supplier suppliers[], int *supplierCount, Asset assets[], int *assetCount, int *employeeCount);
void backupData(void);
void saveEmployeesBinary(int employeeCount);
int loadEmployeesBinary(void);

#endif