#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

// Prototype for the calc_hours function
float calc_hours(int hours[], int weeks, char output);

// Program to calculate, based on user input, a total number of hours or an
// average number of hours across a given day was spent working on this class
int main(void)
{
    // Prompt user for number of weeks in class
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    // Prompt user for number of hours per week spent on class
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// Calculate the total number of hours spent in class
float calc_hours(int hours[], int weeks, char output)
{
    float total_hours = 0;
    float average_hours = 0;

    if (output == 'T')
    {
        for (int i = 0; i < weeks; i++)
        {
            total_hours = total_hours + hours[i];
        }

        return total_hours;
    }

    if (output == 'A')
    {
        for (int i = 0; i < weeks; i++)
        {
            average_hours = average_hours + hours[i];
        }

        average_hours = average_hours / weeks;

        return average_hours;
    }

    else
    {
        return 1;
    }
}
