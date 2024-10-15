from cs50 import get_float

# Calculate how many of each coin is needed to produce
# the necessary amount of change

# Prompt the user for the amount of change owed
while True:
    change_owed = get_float("Change Owed: ")
    if change_owed >= 0:
        break
    else:
        print("Please input a non negative number.")

change_owed = change_owed * 100

coins = 0

# Calculate the number of quarters
coins += int(change_owed / 25)
change_owed %= 25

# Calculate the number of dimes
coins += int(change_owed / 10)
change_owed %= 10

# Calculate the number of nickels
coins += int(change_owed / 5)
change_owed %= 5

# Calculate the number of pennies
coins += int(change_owed)

print(f"{coins}")
