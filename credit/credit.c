#include <cs50.h>
#include <stdio.h>

// Program to check the validity of a credit card number
int main(void)
{
    // Prompt user for input
    long card;
    do
    {
        card = get_long("Card number: \n");
    }
    while (card < 0);

    // Implement Luhn's Algorithm
    // Separate every other digit from right to left
    int card1, card2, card3, card4, card5, card6, card7, card8;
    card1 = ((card % 100) / 10) * 2;
    card2 = ((card % 10000) / 1000) * 2;
    card3 = ((card % 1000000) / 100000) * 2;
    card4 = ((card % 100000000) / 10000000) * 2;
    card5 = ((card % 10000000000) / 1000000000) * 2;
    card6 = ((card % 1000000000000) / 100000000000) * 2;
    card7 = ((card % 100000000000000) / 10000000000000) * 2;
    card8 = ((card % 10000000000000000) / 1000000000000000) * 2;

    card1 = ((card1 / 10) + (card1 % 10));
    card2 = ((card2 / 10) + (card2 % 10));
    card3 = ((card3 / 10) + (card3 % 10));
    card4 = ((card4 / 10) + (card4 % 10));
    card5 = ((card5 / 10) + (card5 % 10));
    card6 = ((card6 / 10) + (card6 % 10));
    card7 = ((card7 / 10) + (card7 % 10));
    card8 = ((card8 / 10) + (card8 % 10));

    int sum1 = card1 + card2 + card3 + card4 + card5 + card6 + card7 + card8;

    int card9, card10, card11, card12, card13, card14, card15, card16;
    card9 = (card % 10);
    card10 = (card % 1000) / 100;
    card11 = (card % 100000) / 10000;
    card12 = (card % 10000000) / 1000000;
    card13 = (card % 1000000000) / 100000000;
    card14 = (card % 100000000000) / 10000000000;
    card15 = (card % 10000000000000) / 1000000000000;
    card16 = (card % 1000000000000000) / 100000000000000;

    int sum2 = card9 + card10 + card11 + card12 + card13 + card14 + card15 + card16;

    int sum3 = sum1 + sum2;

    // Print card number
    printf("%i\n", sum3);

    // Result if card is invalid
    if (sum3 % 10 != 0)
    {
        printf("Card is invalid!\n");
        return 0;
    }

    // Result if card is AMEX
    if (card / 10000000000000 == 34 || card / 10000000000000 == 37)
    {
        printf("Card is AMEX!\n");
        return 0;
    }

    // Result if card is Mastercard
    if (card / 100000000000000 == 51 || card / 100000000000000 == 52 || card / 100000000000000 == 53 || card / 100000000000000 == 54 || card / 100000000000000 == 55)
    {
        printf("Card is Mastercard!\n");
        return 0;
    }

    // Result if card is Visa
    if (card / 1000000000000000 == 4)
    {
        printf("Card is Visa!\n");
        return 0;
    }

    // Catch all other cases
    else
    {
        printf("INVALID!\n");
    }
}


