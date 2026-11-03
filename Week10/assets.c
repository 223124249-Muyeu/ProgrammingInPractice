#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "utilities.h"

#define MAX_ASSETS 100

typedef struct
{
    int id;
    char name[50];
    char description[100];
    double value;
} Asset;

static Asset assets[MAX_ASSETS];
static int assetCount = 0;

void saveAssets(void)
{
    FILE *fp = fopen("Week10/data/assets.dat", "wb");

    if (fp == NULL)
    {
        perror("Error opening asset file");
        return;
    }

    if (fwrite(assets, sizeof(Asset), assetCount, fp) != (size_t)assetCount)
        printf("Error writing asset data.\n");
    else
        printf("%d asset record(s) saved in binary format.\n", assetCount);

    fclose(fp);
}

void loadAssets(void)
{
    FILE *fp = fopen("Week10/data/assets.dat", "rb");

    if (fp == NULL)
    {
        printf("No saved asset data found yet.\n");
        return;
    }

    assetCount = 0;

    while (assetCount < MAX_ASSETS &&
           fread(&assets[assetCount], sizeof(Asset), 1, fp) == 1)
    {
        assetCount++;
    }

    if (ferror(fp))
        printf("Error reading asset data.\n");
    else
        printf("%d asset record(s) loaded.\n", assetCount);

    fclose(fp);
}

void addAsset(void)
{
    if (assetCount >= MAX_ASSETS)
    {
        printf("Asset list is full.\n");
        return;
    }

    Asset newAsset;

    printf("Enter asset ID: ");
    if (scanf("%d", &newAsset.id) != 1)
    {
        printf("Invalid ID.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    printf("Enter asset name: ");
    fgets(newAsset.name, sizeof(newAsset.name), stdin);
    newAsset.name[strcspn(newAsset.name, "\n")] = '\0';

    printf("Enter asset description: ");
    fgets(newAsset.description, sizeof(newAsset.description), stdin);
    newAsset.description[strcspn(newAsset.description, "\n")] = '\0';

    printf("Enter asset value: ");
    if (scanf("%lf", &newAsset.value) != 1 || newAsset.value < 0)
    {
        printf("Invalid asset value.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    assets[assetCount] = newAsset;
    assetCount++;

    printf("Asset added successfully.\n");
    saveAssets();
}

void displayAssets(void)
{
    if (assetCount == 0)
    {
        printf("No assets available.\n");
        return;
    }

    printf("\n--- Asset List ---\n");

    for (int i = 0; i < assetCount; i++)
    {
        printf("ID: %d | Name: %s | Description: %s | Value: %.2f\n",
               assets[i].id, assets[i].name,
               assets[i].description, assets[i].value);
    }
}

void assetMenu(void)
{
    int choice = 0;

    do
    {
        printf("\n--- Asset Management ---\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input.\n");
            clearInputBuffer();
            choice = 0;
            continue;
        }

        clearInputBuffer();

        switch (choice)
        {
            case 1: addAsset(); break;
            case 2: displayAssets(); break;
            case 3: printf("Returning to main menu.\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 3);
}
