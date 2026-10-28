#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[100];
    char email[100];
    char phone[20];
    char town[50];
    char searchName[100];
    char label[160];

    printf("Enter supplier name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("Enter town: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = '\0';

    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name:  %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town:  %s\n", town);

    printf("\n--- STRING LENGTHS ---\n");
    printf("Supplier name length: %zu\n", strlen(name));
    printf("Email length: %zu\n", strlen(email));
    printf("Town length: %zu\n", strlen(town));

    strcpy(label, name);
    strcat(label, " - ");
    strcat(label, town);

    printf("Supplier label: %s\n", label);

    printf("Enter supplier name to search\n: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    if (strcmp(name, searchName) == 0)
    {
        printf("Supplier found!\n");
    }
    else
    {
        printf("Supplier not found.\n");
    }

    return 0;
}