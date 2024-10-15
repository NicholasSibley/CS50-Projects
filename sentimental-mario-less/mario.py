# Program to print a pyrmid similar to what is seen in Super Mario
while True:

    # Prompt user for pyramid height
    try:
        height = input("Height: ")
        height = int(height)
        if 1 <= height <= 8:
            break
        else:
            print("Height must be between 1 and 8.")
    except ValueError:
        print("Invalid usage.")

width = height

# Print right-aligned pyramid
for height in range(1, height + 1):
    for width in range(1, width):
        print(" ", end="")
    for column in range(0, height):
        print("#", end="")
    print("")
