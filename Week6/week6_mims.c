#include <stdio.h>
#include <string.h>

int main()
{
    float salaries[50];
    float budgets[10];
    char registrations[20][20];

    float total, average, highest, lowest, temp;
    float searchSalary;
    char searchReg[20];
    int found;

    printf("=== Municipal Information Management System ===\n");

    printf("\n--- A. Employee Salaries ---\n");

    for (int i = 0; i < 50; i++)
    {
        printf("Enter salary %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    printf("\nAll salaries:\n");
    for (int i = 0; i < 50; i++)
    {
        printf("%d. %.2f\n", i + 1, salaries[i]);
    }

    total = 0;
    highest = salaries[0];
    lowest = salaries[0];

    for (int i = 0; i < 50; i++)
    {
        total = total + salaries[i];

        if (salaries[i] > highest)
        {
            highest = salaries[i];
        }
        if (salaries[i] < lowest)
        {
            lowest = salaries[i];
        }
    }
    average = total / 50;

    printf("\nTotal salary: %.2f\n", total);
    printf("Average salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary: %.2f\n", lowest);

    printf("\nEnter a salary to search for: ");
    scanf("%f", &searchSalary);

    found = 0;
    for (int i = 0; i < 50; i++)
    {
        if (salaries[i] == searchSalary)
        {
            printf("Salary found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Salary not found.\n");
    }

    printf("\n--- B. Department Budgets ---\n");

    for (int i = 0; i < 10; i++)
    {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
    }

    printf("\nBudgets entered:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Department %d: %.2f\n", i + 1, budgets[i]);
    }

    total = 0;
    for (int i = 0; i < 10; i++)
    {
        total = total + budgets[i];
    }
    average = total / 10;

    printf("\nTotal budget: %.2f\n", total);
    printf("Average budget: %.2f\n", average);

    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (budgets[j] > budgets[j + 1])
            {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\nBudgets sorted (lowest to highest):\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%.2f\n", budgets[i]);
    }

    printf("\n--- C. Vehicle Registration Numbers ---\n");

    for (int i = 0; i < 20; i++)
    {
        printf("Enter registration number %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    printf("\nAll registration numbers:\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%d. %s\n", i + 1, registrations[i]);
    }

    printf("\nEnter a registration number to search for: ");
    scanf("%19s", searchReg);

    found = 0;
    for (int i = 0; i < 20; i++)
    {
        if (strcmp(registrations[i], searchReg) == 0)
        {
            printf("Registration found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Registration not found.\n");
    }

    return 0;
}
