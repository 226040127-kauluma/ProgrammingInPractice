#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100
#define ASSET_LEN 100

typedef struct {
    char id[ASSET_LEN];
    char name[ASSET_LEN];
    char type[ASSET_LEN];
    double purchaseValue;
    char department[ASSET_LEN];
    char condition[ASSET_LEN];
} Asset;

void addAsset(Asset assets[], int *count);
void displayAssets(const Asset assets[], int count);
void searchAsset(const Asset assets[], int count);
void handleAssetMenu(Asset assets[], int *count);

#endif