import random

a = random.sample(range(1, 30), 12)
b = random.sample(range(1, 30), 12)

c = [i for i in set(a) if i in b]

print(c)
