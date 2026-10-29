#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"

void displayReport(void)
{
    printf("\n===== MFMS SUMMARY REPORT =====\n");

    printf("\nEmployee Records:\n");
    displayEmployees();

    printf("\nBudget Information:\n");
    displayBudget();

    printf("\n===== END OF REPORT =====\n");
}