
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SUPPLIERS 5

int main(void)
{
    char names[MAX_SUPPLIERS][100];
    char emails[MAX_SUPPLIERS][100];
    char phones[MAX_SUPPLIERS][20];
    char towns[MAX_SUPPLIERS][50];
    char input[100];
    char search[100];
    int count = 0;
    int choice;
    int found;

    do
    {
        printf("\n===== SUPPLIER MANAGEMENT =====\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        choice = atoi(input);

        switch (choice)
        {
            case 1:
                if (count >= MAX_SUPPLIERS)
                {
                    printf("Supplier list is full.\n");
                    break;
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
                printf("Supplier added successfully.\n");
                break;

            case 2:
                if (count == 0)
                {
                    printf("No suppliers have been added.\n");
                    break;
                }

                for (int i = 0; i < count; i++)
                {
                    printf("Supplier %d\n", i + 1);
                    printf("Name : %s\n", names[i]);
                    printf("Email: %s\n", emails[i]);
                    printf("Phone: %s\n", phones[i]);
                    printf("Town : %s\n", towns[i]);
                }
                break;

            case 3:
                printf("Enter supplier name to search: ");

                if (fgets(search, sizeof(search), stdin) == NULL)
                    break;

                search[strcspn(search, "\n")] = '\0';
                found = 0;

                for (int i = 0; i < count; i++)
                {
                    if (strcmp(names[i], search) == 0)
                    {
                        printf("Supplier found!\n");
                        printf("Name : %s\n", names[i]);
                        printf("Email: %s\n", emails[i]);
                        printf("Phone: %s\n", phones[i]);
                        printf("Town : %s\n", towns[i]);
                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                    printf("Supplier not found.\n");

                break;

            case 4:
                if (count == 0)
                {
                    printf("No suppliers have been added.\n");
                    break;
                }

                for (int i = 0; i < count; i++)
                {
                    printf("%s: %zu characters\n",
                           names[i], strlen(names[i]));
                }
                break;

            case 5:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
