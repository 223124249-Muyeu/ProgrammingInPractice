#include <stdio.h>
#include "budget.h"
#include "utilities.h"

static float totalBudget = 0.0f;
static int budgetSet = 0;

void setBudget(void)
{
    printf("Enter the total budget: ");

    if (scanf("%f", &totalBudget) != 1 || totalBudget < 0)
    {
        printf("Invalid budget amount.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();
    budgetSet = 1;

    printf("Budget saved successfully.\n");
}

void displayBudget(void)
{
    if (!budgetSet)
    {
        printf("No budget has been set yet.\n");
        return;
    }

    printf("Total budget: %.2f\n", totalBudget);
}

void budgetMenu(void)
{
    int choice;

    do
    {
        printf("\n--- Budget Management ---\n");
        printf("1. Set Budget\n");
        printf("2. Display Budget\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Enter a number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        switch (choice)
        {
            case 1:
                setBudget();
                break;
            case 2:
                displayBudget();
                break;
            case 3:
                printf("Returning to main menu.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 3);
}