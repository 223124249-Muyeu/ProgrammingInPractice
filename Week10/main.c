#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"
#include "suppliers.h"
#include "assets.h"

int main(void)
{
    int choice = 0;

    /* Load saved information when the program starts */
    loadEmployees();
    loadBudget();
    loadSuppliers();
    loadAssets();

    do
    {
        printf("\n===== MFMS WEEK 10 =====\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Save Data\n");
        printf("7. Load Data\n");
        printf("8. Exit\n");
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
                employeeMenu();
                break;

            case 2:
                budgetMenu();
                break;

            case 3:
                supplierMenu();
                break;

            case 4:
                assetMenu();
                break;

            case 5:
                displayReport();
                break;

            case 6:
                saveEmployees();
                saveBudget();
                saveSuppliers();
                saveAssets();
                break;

            case 7:
                loadEmployees();
                loadBudget();
                loadSuppliers();
                loadAssets();
                break;

            case 8:
                printf("Exiting MFMS Week 10. Goodbye!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 8);

    return 0;
}
