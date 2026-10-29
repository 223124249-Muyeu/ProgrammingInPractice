#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utilities.h"

static int employeeIDs[MAX_EMPLOYEES];
static char employeeNames[MAX_EMPLOYEES][50];
static float employeeSalaries[MAX_EMPLOYEES];
static int employeeCount = 0;

void addEmployee(void)
{
    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("Employee list is full.\n");
        return;
    }

    printf("Enter employee ID: ");
    if (scanf("%d", &employeeIDs[employeeCount]) != 1)
    {
        printf("Invalid ID.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    printf("Enter employee name: ");
    if (fgets(employeeNames[employeeCount],
              sizeof(employeeNames[employeeCount]), stdin) == NULL)
    {
        printf("Could not read employee name.\n");
        return;
    }

    employeeNames[employeeCount][strcspn(
        employeeNames[employeeCount], "\n")] = '\0';

    printf("Enter monthly salary: ");
    if (scanf("%f", &employeeSalaries[employeeCount]) != 1)
    {
        printf("Invalid salary.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();
    employeeCount++;

    printf("Employee added successfully.\n");
}

void displayEmployees(void)
{
    int i;

    if (employeeCount == 0)
    {
        printf("No employees recorded yet.\n");
        return;
    }

    printf("\n--- Employee List ---\n");

    for (i = 0; i < employeeCount; i++)
    {
        printf("ID: %d | Name: %s | Salary: %.2f\n",
               employeeIDs[i],
               employeeNames[i],
               employeeSalaries[i]);
    }
}

void searchEmployee(void)
{
    int id;
    int i;

    printf("Enter employee ID to search: ");

    if (scanf("%d", &id) != 1)
    {
        printf("Invalid ID.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    for (i = 0; i < employeeCount; i++)
    {
        if (employeeIDs[i] == id)
        {
            printf("Employee found:\n");
            printf("ID: %d | Name: %s | Salary: %.2f\n",
                   employeeIDs[i],
                   employeeNames[i],
                   employeeSalaries[i]);
            return;
        }
    }

    printf("Employee not found.\n");
}

void employeeMenu(void)
{
    int choice;

    do
    {
        printf("\n--- Employee Management ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Back to Main Menu\n");
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
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                printf("Returning to main menu.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);
}