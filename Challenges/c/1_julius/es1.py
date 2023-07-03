import base64
from dataclasses import replace
import codecs
from re import A

with open("description.txt", "r") as f:
    input = f.readline()
    for i in f:
        s = i

i = i.replace("ciphertext: ", "")
input = input.replace("Julius,", "")
key = input

print(key)
print(i)

k = base64.b64decode(key).decode("ascii")
print("The key is: ", k)
# t = base64.b64decode(i).decode("ascii")
t = "}{[l^KlwOmwZjmOKW9"

output = ""
for s in range(26):
    output = ""
    for m in t:
        output += chr(ord(m) - s)
    print(output)
    print(s)
