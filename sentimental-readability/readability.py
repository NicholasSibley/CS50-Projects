from cs50 import get_string

# Program to calculate the approximate grade level needed to comprehend a given string of text
# The grade level is caluclated by the Coleman-Liau index.  index = 0.0588 * L - 0.296 * S - 15.8

# Prompt the user for a string
input = get_string("What is your text?\n")

letters = 0
words = 1
sentences = 0

# Calculate the number of letters
for i in input:
    if i.isalpha():
        letters += 1

# Calculate the number of words
    if i == " ":
        words += 1

# Calculat ethe number of sentences
    if i == "!" or i == "." or i == "?":
        sentences += 1

# print the nubmer of letters, words, and sentences
print(f"{letters}, {words}, {sentences}")

letters = letters / words
letters = float(letters * 100)

sentences = sentences / words
sentences = float(sentences * 100)

# Apply the Coleman-Liau index
index = round(0.0588 * letters - 0.296 * sentences - 15.8)

# Output if the string is before grade 1
if index < 1:
    print("Before Grade 1")

# Output if the grade is post graduate level
elif index > 16:
    print("Grade 16+")

# All other outputs
else:
    print(f"Grade {index}")
