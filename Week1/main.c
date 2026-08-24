#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char municipality[50];
    char mayor[50];
    char populationStr[20];
    int population;

    printf("Municipal Financial Management System\n");
    printf("Welcome to Windhoek Municipality\n\n");

    printf("Enter Municipality Name: ");
    fgets(municipality, sizeof(municipality), stdin);
    municipality[strcspn(municipality, "\n")] = '\0';

    printf("Enter Mayor: ");
    fgets(mayor, sizeof(mayor), stdin);
    mayor[strcspn(mayor, "\n")] = '\0';

    printf("Enter Population: ");
    fgets(populationStr, sizeof(populationStr), stdin);
    population = atoi(populationStr);

    printf("\n--------------------------------\n");
    printf("Municipality : %s\n", municipality);
    printf("Mayor        : %s\n", mayor);
    printf("Population   : %d\n", population);

    return 0;
}
