#include <stdio.h>

int main()
{
    char name[50];
    float test1, test2, assignment, total;

    printf("Enter student name: ");
    scanf("%49s", name);
    printf("Enter Test 1 mark: ");
    scanf("%f", &test1);
    printf("Enter Test 2 mark: ");
    scanf("%f", &test2);
    printf("Enter Assignment mark: ");
    scanf("%f", &assignment);

    total = test1 + test2 + assignment;

    printf("\nStudent: %s\n", name);
    printf("Total: %.2f\n", total);

    if (total >= 75)
        printf("Result: Distinction\n");
    else if (total >= 60)
        printf("Result: Credit\n");
    else if (total >= 50)
        printf("Result: Pass\n");
    else
        printf("Result: Fail\n");

    return 0;
}