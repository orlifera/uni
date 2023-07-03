from dataclasses import replace
from textwrap import wrap

"""
with open("description.txt", "r") as f:
    input = f.readline()

input = input.replace("Crack the cipher: ", "")

print("the code to decipher is: ", input)
"""
input = "vhixoieemksktorywzvhxzijqni"


list = wrap(input, 4)
output = ""
for index in range(len(list)):
    for i in range(7):
        if list[index][i] == input[0]:
            output += chr(ord(input[index]) - 2)
            # print(output)
        elif input[index][i] == input[1]:
            output += chr(ord(input[index]) - 4)
        # print(output)
        elif input[index] == input[2]:
            output += chr(ord(input[index]) - 0)
            # print(output)
        elif input[index] == input[3]:
            output += chr(ord(input[index]) - 18)
            # print(output)
        elif input[index] == input[4]:
            output += chr(ord(input[index]) - 0)
            # print(output)
        elif input[index] == input[5]:
            output += chr(ord(input[index]) - 17)
            # print(output)
# print(i)
print(output)
