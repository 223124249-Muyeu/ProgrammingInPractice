#include <stdio.h>
#include <string.h>

int main()
{
    char name[100];
    char email[100];
    char phone[20];
    char town[50];
    char backup[100];
    char description[200];
    char search[100];

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
    printf("Name : %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town : %s\n", town);

    printf("Supplier name length: %zu\n", strlen(name));
    printf("Email length: %zu\n", strlen(email));
    printf("Town length: %zu\n", strlen(town));

    char supplier1[] = "ABC Office Supplies";
    char supplier2[] = "Namibia Stationery";

    printf("Enter supplier name to search\n: ");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = '\0';

    if (strcmp(search, supplier1) == 0 || strcmp(search, supplier2) == 0)
    {
        printf("Supplier found.\n");
    }
    else
    {
        printf("Supplier not found.\n");
    }

    strcpy(backup, name);
    printf("Original: %s\n", name);
    printf("Backup  : %s\n", backup);

    strcpy(description, name);
    strcat(description, " operates in ");
    strcat(description, town);
    strcat(description, ".");
    printf("%s\n", description);

    return 0;
}