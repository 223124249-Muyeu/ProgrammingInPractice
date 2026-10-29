#include <stdio.h>
#include <string.h>

char names[5][50];
char emails[5][50];
char phones[5][20];
char towns[5][30];
int count = 0;

void displayMenu();
void addSupplier();
void displaySupplier();
void searchSupplier();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);

int main()
{
    int choice;
    float amount, basic, housing, transport, revenue, expenses, balance;

    do
    {
        displayMenu();
        scanf("%d", &choice);
        getchar();    

        switch (choice)
        {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySupplier();
                break;
            case 3:
                searchSupplier();
                break;
            case 4:
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("VAT: %.2f\n", calculateVAT(amount));
                break;
            case 5:
                printf("Basic salary: ");
                scanf("%f", &basic);
                printf("Housing allowance: ");
                scanf("%f", &housing);
                printf("Transport allowance: ");
                scanf("%f", &transport);
                printf("Gross salary: %.2f\n", calculateSalary(basic, housing, transport));
                break;
            case 6:
                printf("Enter revenue: ");
                scanf("%f", &revenue);
                printf("Enter expenses: ");
                scanf("%f", &expenses);
                balance = calculateBudget(revenue, expenses);
                printf("Balance: %.2f\n", balance);
                if (balance > 0)
                    printf("SURPLUS\n");
                else if (balance < 0)
                    printf("DEFICIT\n");
                else
                    printf("BALANCED\n");
                break;
            case 7:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}

void displayMenu()
{
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Add Supplier\n");
    printf("2. Display Supplier\n");
    printf("3. Search Supplier\n");
    printf("4. Calculate VAT\n");
    printf("5. Calculate Salary\n");
    printf("6. Calculate Budget\n");
    printf("7. Exit\n");
    printf("Enter choice: ");
}

void addSupplier()
{
    if (count == 5)
    {
        printf("Supplier list is full.\n");
        return;
    }

    printf("Enter supplier name: ");
    fgets(names[count], sizeof(names[count]), stdin);
    names[count][strcspn(names[count], "\n")] = '\0';

    printf("Enter email: ");
    fgets(emails[count], sizeof(emails[count]), stdin);
    emails[count][strcspn(emails[count], "\n")] = '\0';

    printf("Enter phone: ");
    fgets(phones[count], sizeof(phones[count]), stdin);
    phones[count][strcspn(phones[count], "\n")] = '\0';

    printf("Enter town: ");
    fgets(towns[count], sizeof(towns[count]), stdin);
    towns[count][strcspn(towns[count], "\n")] = '\0';

    count++;
    printf("Supplier added.\n");
}

void displaySupplier()
{
    if (count == 0)
    {
        printf("No suppliers yet.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Name : %s\n", names[i]);
        printf("Email: %s\n", emails[i]);
        printf("Phone: %s\n", phones[i]);
        printf("Town : %s\n", towns[i]);
    }
}

void searchSupplier()
{
    char search[100];
    int found = 0;

    printf("Enter supplier name to search: ");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = '\0';    

    for (int i = 0; i < count; i++)
    {
        if (strcmp(names[i], search) == 0)
        {
            printf("Supplier found at position %d.\n", i + 1);
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("Supplier not found.\n");
}

float calculateVAT(float amount)
{
    return amount * 0.15;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}