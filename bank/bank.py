# Program to grant 0 dollars to someone that sends a message that starts with hello,
# to grant 20 dollars if the message starts with an h (but is not hello),
# or to grant 100 dollars to all other messages

user_input = input("Greeting\n").strip().lower()

if user_input.startswith("hello"):
    print("$0")
elif user_input.startswith("h"):
    print("$20")
else:
    print("$100")
