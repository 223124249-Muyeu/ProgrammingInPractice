#include <stdio.h>

int main()
{
    char name[50];
    float price, budget;
    int registered, docs;

    printf("Enter supplier name: ");
    scanf("%49s", name);
    printf("Enter tender price: ");
    scanf("%f", &price);
    printf("Enter available budget: ");
    scanf("%f", &budget);
    printf("Is supplier registered? (1=Yes, 0=No): ");
    scanf("%d", &registered);
    printf("Are all documents complete? (1=Yes, 0=No): ");
    scanf("%d", &docs);

    printf("\nSupplier: %s\n", name);

    if (registered == 1 && docs == 1 && price <= budget)
        printf("Status: Qualified\n");
    else
        printf("Status: Disqualified\n");

    return 0;
}