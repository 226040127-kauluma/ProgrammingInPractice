#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS     100
#define MAX_AST_ID     20
#define MAX_AST_NAME   50
#define MAX_AST_TYPE   30
#define MAX_AST_DEPT   50
#define MAX_CONDITION  20

typedef struct {
    char id[MAX_AST_ID];
    char name[MAX_AST_NAME];
    char type[MAX_AST_TYPE];
    double purchaseValue;
    char department[MAX_AST_DEPT];
    char condition[MAX_CONDITION];
} Asset;

int searchAsset(Asset assets[], int count, char id[]);
void displayAsset(Asset a);
void displayAssets(Asset assets[], int count);
void addAsset(Asset assets[], int *count);
void searchAssetMenu(Asset assets[], int count);

double getTotalAssetValue(Asset assets[], int count);
double getAverageAssetValue(Asset assets[], int count);
double getHighestAssetValue(Asset assets[], int count);
double getLowestAssetValue(Asset assets[], int count);
int countAssetsByCondition(Asset assets[], int count, const char *condition);

void handleAssetMenu(Asset assets[], int *count);

#endif