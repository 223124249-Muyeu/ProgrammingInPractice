#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

void displayReport(void)
{
    printf("\n===== MFMS SUMMARY REPORT =====\n");

    printf("\nEmployee Records:\n");
    displayEmployees();

    printf("\nBudget Information:\n");
    displayBudget();

    printf("\nSupplier Records:\n");
    displaySuppliers();

    printf("\nAsset Records:\n");
    displayAssets();

    printf("\n===== END OF REPORT =====\n");
}
