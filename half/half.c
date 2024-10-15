#include <cs50.h>
#include <stdio.h>

// Calculate your half of a restaurant bill

// Prototype for half function
float half(float bill, float tax, float tip);

// Prompt user for input and store result in variables
int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_float("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// Pass variables to half function and return final amount owed
float half(float bill, float tax, float tip)
{
    bill = bill * ((tax / 100) + 1);
    bill = bill * ((tip / 100) + 1);
    bill = bill / 2;
    return bill;
}
