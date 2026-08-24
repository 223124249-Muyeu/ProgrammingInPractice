#include <stdio.h>

int main() {

    double revenue;
    double expenses;
    double balance;

    int departments;
    double payroll;
    double procurement;
    double assets;

    printf("MUNICIPAL BUDGET CALCULATOR\n");
    printf("----------------------------\n");

    printf("Enter total revenue: ");
    scanf("%lf", &revenue);

    printf("Enter total expenses: ");
    scanf("%lf", &expenses);

    balance = revenue - expenses;

    printf("Revenue: %.2f\n", revenue);
    printf("Expenses: %.2f\n", expenses);
    printf("Balance: %.2f\n", balance);

    // Extension exercise
    printf("Enter number of departments: ");
    scanf("%d", &departments);

    printf("Enter total payroll: ");
    scanf("%lf", &payroll);

    printf("Enter total procurement: ");
    scanf("%lf", &procurement);

    printf("Enter total assets: ");
    scanf("%lf", &assets);

    printf("\nMunicipal Financial Summary\n");
    printf("Departments: %d\n", departments);
    printf("Payroll: %.2f\n", payroll);
    printf("Procurement: %.2f\n", procurement);
    printf("Assets: %.2f\n", assets);

    return 0;
}
