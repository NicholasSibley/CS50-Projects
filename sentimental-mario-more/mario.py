# Print a pyramid similar to what is seen in Super Mario
# Should print two pyramids: one left aligned and one right aligned
while True:

    # Prompt user for the size of the pyramid
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
c = 0
r = 1
s = 0
h = 0

# Print right-aligned and left-aligned pyramid
for h in range(1, height + 1):
    for s in range(0, height - 1):
        print(" ", end="")
    for width in range(0, r):
        print("#", end="")
    print("  ", end="")
    for width in range(0, r):
        print("#", end="")
    r = r + 1
    height = height - 1
    print("")
