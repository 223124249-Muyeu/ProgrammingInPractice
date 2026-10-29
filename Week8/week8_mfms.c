#include <stdio.h>
#include <string.h>

char names[5][50];
char emails[5][50];
char phones[5][20];
char towns[5][30];
int count = 0;

void displayMenu();
void salaryOption();
void vatOption();
void budgetOption();
void searchEmployeeOption();
void supplierMenu();
void addSupplier();
void displaySupplier();
void searchSupplier();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);

int main()
{
    int choice;

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: salaryOption(); break;
            case 2: vatOption(); break;
            case 3: budgetOption(); break;
            case 4: searchEmployeeOption(); break;
            case 5: supplierMenu(); break;
            case 6: printf("Goodbye.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu()
{
    printf("\n============================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("1. Calculate Employee Salary\n");
    printf("2. Calculate VAT\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Supplier Management\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

void salaryOption()
{
    float basic, housing, transport;

    printf("Basic salary: ");
    scanf("%f", &basic);
    printf("Housing allowance: ");
    scanf("%f", &housing);
    printf("Transport allowance: ");
    scanf("%f", &transport);
    printf("Gross salary: %.2f\n", calculateSalary(basic, housing, transport));
}

void vatOption()
{
    float amount;

    printf("Enter amount: ");
    scanf("%f", &amount);
    printf("VAT: %.2f\n", calculateVAT(amount));
}

void budgetOption()
{
    float revenue, expenses, balance;

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
}

void searchEmployeeOption()
{
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int id, position;

    printf("Enter employee ID: ");
    scanf("%d", &id);

    position = searchEmployee(id, employeeIDs, 5);
    if (position == -1)
        printf("Employee not found.\n");
    else
        printf("Employee found at position %d.\n", position);
}

void supplierMenu()
{
    int choice;

    do
    {
        printf("\n--- SUPPLIER MANAGEMENT ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Back\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();    

        switch (choice)
        {
            case 1: addSupplier(); break;
            case 2: displaySupplier(); break;
            case 3: searchSupplier(); break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
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

int searchEmployee(int id, int ids[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (ids[i] == id)
            return i;
    }
    return -1;
}