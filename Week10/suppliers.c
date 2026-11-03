#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "utilities.h"

#define MAX_SUPPLIERS 100

typedef struct
{
    int id;
    char name[50];
    char contact[50];
    char phone[20];
} Supplier;

static Supplier suppliers[MAX_SUPPLIERS];
static int supplierCount = 0;

void saveSuppliers(void)
{
    FILE *fp = fopen("Week10/data/suppliers.txt", "w");

    if (fp == NULL)
    {
        perror("Could not save supplier data");
        return;
    }

    for (int i = 0; i < supplierCount; i++)
    {
        fprintf(fp, "%d|%s|%s|%s\n",
                suppliers[i].id,
                suppliers[i].name,
                suppliers[i].contact,
                suppliers[i].phone);
    }

    fclose(fp);
    printf("%d supplier record(s) saved successfully.\n", supplierCount);
}

void loadSuppliers(void)
{
    FILE *fp = fopen("Week10/data/suppliers.txt", "r");

    if (fp == NULL)
    {
        printf("No saved supplier data found yet.\n");
        return;
    }

    supplierCount = 0;

    while (supplierCount < MAX_SUPPLIERS &&
           fscanf(fp, "%d|%49[^|]|%49[^|]|%19[^\n]\n",
                  &suppliers[supplierCount].id,
                  suppliers[supplierCount].name,
                  suppliers[supplierCount].contact,
                  suppliers[supplierCount].phone) == 4)
    {
        supplierCount++;
    }

    if (ferror(fp))
    {
        printf("Error reading supplier data.\n");
    }
    else
    {
        printf("%d supplier record(s) loaded successfully.\n", supplierCount);
    }

    fclose(fp);
}

void addSupplier(void)
{
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier list is full.\n");
        return;
    }

    Supplier newSupplier;

    printf("Enter supplier ID: ");
    if (scanf("%d", &newSupplier.id) != 1)
    {
        printf("Invalid supplier ID.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    printf("Enter supplier name: ");
    fgets(newSupplier.name, sizeof(newSupplier.name), stdin);
    newSupplier.name[strcspn(newSupplier.name, "\n")] = '\0';

    printf("Enter contact person: ");
    fgets(newSupplier.contact, sizeof(newSupplier.contact), stdin);
    newSupplier.contact[strcspn(newSupplier.contact, "\n")] = '\0';

    printf("Enter phone number: ");
    fgets(newSupplier.phone, sizeof(newSupplier.phone), stdin);
    newSupplier.phone[strcspn(newSupplier.phone, "\n")] = '\0';

    if (strchr(newSupplier.name, '|') != NULL ||
        strchr(newSupplier.contact, '|') != NULL ||
        strchr(newSupplier.phone, '|') != NULL)
    {
        printf("The | character is not allowed in supplier information.\n");
        return;
    }

    suppliers[supplierCount] = newSupplier;
    supplierCount++;

    printf("Supplier added successfully.\n");
    saveSuppliers();
}

void displaySuppliers(void)
{
    if (supplierCount == 0)
    {
        printf("No supplier records available.\n");
        return;
    }

    for (int i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier ID: %d\n", suppliers[i].id);
        printf("Name: %s\n", suppliers[i].name);
        printf("Contact Person: %s\n", suppliers[i].contact);
        printf("Phone: %s\n", suppliers[i].phone);
    }
}

void supplierMenu(void)
{
    int choice = 0;

    do
    {
        printf("\n===== SUPPLIER MANAGEMENT =====\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Enter a number.\n");
            clearInputBuffer();
            choice = 0;
            continue;
        }

        clearInputBuffer();

        switch (choice)
        {
            case 1:
                addSupplier();
                break;

            case 2:
                displaySuppliers();
                break;

            case 3:
                printf("Returning to main menu.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 3);
}
