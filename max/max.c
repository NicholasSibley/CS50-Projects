#include <cs50.h>
#include <stdio.h>

// Function prototype
int max(int array[], int n);

// Program to determine the maximum value in an array
int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// Return the max value
int max(int array[], int n)
{
    int counter = array[0];

    for (int i = 0; i < n; i++)
    {
        if (array[i] > counter)
        {
            counter = array[i];
        }
    }
    return counter;
}
