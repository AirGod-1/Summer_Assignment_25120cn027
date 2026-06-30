/*
* LOGIC: The Financial Calculation Engine
 * 1. Gross Salary = Basic + HRA (House Rent Allowance) + DA (Dearness Allowance).
 * 2. Calculate percentages on the fly.
 */



#include <stdio.h>
int main() {
    char name[50];

    float basic, hra, da, pf, gross, net;

    printf("--- Salary Management System ---\n");
    printf("Enter Employee Name: ");
    scanf(" %[^\n]s", name);
    printf("Enter Basic Salary: Rs. ");
    scanf("%f", &basic);

    hra = basic * 0.20;
    da = basic * 0.50;
    pf = basic * 0.12;

    gross = basic + hra + da;
    net = gross - pf;


    printf("\n--- Salary Slip for %s ---\n", name);
    printf("Basic Salary: Rs. %.2f\n", basic);
    printf("HRA (20%%)   : Rs. %.2f\n", hra);
    printf("DA (50%%)    : Rs. %.2f\n", da);
    printf("Gross Salary: Rs. %.2f\n", gross);
    printf("PF (12%%)    : Rs. %.2f (Deduction)\n", pf);
    printf("--------------------------------\n");
    printf("Net Payable : Rs. %.2f\n", net);


    return 0;
}