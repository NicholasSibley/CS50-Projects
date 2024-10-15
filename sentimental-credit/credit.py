from cs50 import get_int

# Program to theck the validity of a credit card number

# Implement Luhn's Algorithm
# Separate every other digit from right to left
while True:
        card = get_int("Number: ")
        if card >= 0:
            break
        else:
            print("Number must be non negative")

card1 = ((card % 100) // 10) * 2
card2 = ((card % 10000) // 1000) * 2
card3 = ((card % 1000000) // 100000) * 2
card4 = ((card % 100000000) // 10000000) * 2
card5 = ((card % 10000000000) // 1000000000) * 2
card6 = ((card % 1000000000000) // 100000000000) * 2
card7 = ((card % 100000000000000) // 10000000000000) * 2
card8 = ((card % 10000000000000000) // 1000000000000000) * 2

card1 = ((card1 // 10) + (card1 % 10))
card2 = ((card2 // 10) + (card2 % 10))
card3 = ((card3 // 10) + (card3 % 10))
card4 = ((card4 // 10) + (card4 % 10))
card5 = ((card5 // 10) + (card5 % 10))
card6 = ((card6 // 10) + (card6 % 10))
card7 = ((card7 // 10) + (card7 % 10))
card8 = ((card8 // 10) + (card8 % 10))

sum1 = card1 + card2 + card3 + card4 + card5 + card6 + card7 + card8

card9 = (card % 10)
card10 = ((card % 1000) // 100)
card11 = ((card % 100000) // 10000)
card12 = ((card % 10000000) // 1000000)
card13 = ((card % 1000000000) // 100000000)
card14 = ((card % 100000000000) // 10000000000)
card15 = ((card % 10000000000000) // 1000000000000)
card16 = ((card % 1000000000000000) // 100000000000000)

sum2 = card9 + card10 + card11 + card12 + card13 + card14 + card15 + card16

sum3 = sum1 + sum2

# Output if the card number is invalid
if sum3 % 10 != 0:
    print("INVALID\n")

identifier1 = int(str(card)[:2])
identifier2 = int(str(card)[:1])

# Output if the card is AMEX
if identifier1 == 34 or identifier1 == 37:
    print("AMEX")

# Output if the card is Mastercard
elif identifier1 == 51 or identifier1 == 52 or identifier1 == 53 or identifier1 == 54 or identifier1 == 55:
     print("MASTERCARD")

# Output if the card is Visa
elif identifier2 == 4 and (len(str(card)) == 13 or len(str(card)) == 16):
    print("VISA")

# Account for all other cases
else:
    print("INVALID")
