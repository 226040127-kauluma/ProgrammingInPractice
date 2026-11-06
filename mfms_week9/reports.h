#ifndef REPORTS_H
#define REPORTS_H

#include "suppliers.h"
#include "assets.h"

void displayEmployeeReport(int count);
void displaySupplierReport(Supplier suppliers[], int count);
void displayAssetReport(Asset assets[], int count);
void reportsMenu(int employeeCount, Supplier suppliers[], int supplierCount, Asset assets[], int assetCount);

#endif