#include <stdio.h>

int main()
{
    float basic, housing, transport, tax;
    float gross, net;

    printf("Enter basic salary: ");
    scanf("%f", &basic);
    printf("Enter housing allowance: ");
    scanf("%f", &housing);
    printf("Enter transport allowance: ");
    scanf("%f", &transport);
    printf("Enter tax: ");
    scanf("%f", &tax);

    gross = basic + housing + transport;
    net = gross - tax;

    printf("\nGross Salary: %.2f\n", gross);
    printf("Net Salary: %.2f\n", net);

    if (net >= 20000)
        printf("High Income\n");
    else
        printf("Standard Income\n");

    return 0;
}