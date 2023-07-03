from curses.ascii import isupper
from textwrap import wrap


file = open("challenge.txt", "r").read()
print(file)

counter = ""
for lines in file:
    if lines.isupper():
        counter += lines
print(counter)
counter = counter.replace("ZERO", "0")
counter = counter.replace("ONE", "1")

print(counter)

list = wrap(counter, 8)

print(list)

for n in list:
    print(chr(int(n, 2)), end="")
