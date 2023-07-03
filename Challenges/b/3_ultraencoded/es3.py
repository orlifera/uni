from dataclasses import replace
from fileinput import close
from textwrap import wrap
import base64

with open("zero_one.txt", "r") as file:
    input = file.read()
file.close()
print(input)
input = input.replace("ZERO", "0")
input = input.replace("ONE", "1")
input = input.replace(" ", "")
print(input)

list = wrap(input, 8)
print(list)

string = ""
print("CIao")
for i in list:
    string += chr(int(i, 2))
print(" ")
print(string)

decode = base64.b64decode(string).decode("ascii")
print(decode)


MORSE_CODE_DICT = {
    "A": ".-",
    "B": "-...",
    "C": "-.-.",
    "D": "-..",
    "E": ".",
    "F": "..-.",
    "G": "--.",
    "H": "....",
    "I": "..",
    "J": ".---",
    "K": "-.-",
    "L": ".-..",
    "M": "--",
    "N": "-.",
    "O": "---",
    "P": ".--.",
    "Q": "--.-",
    "R": ".-.",
    "S": "...",
    "T": "-",
    "U": "..-",
    "V": "...-",
    "W": ".--",
    "X": "-..-",
    "Y": "-.--",
    "Z": "--..",
    "1": ".----",
    "2": "..---",
    "3": "...--",
    "4": "....-",
    "5": ".....",
    "6": "-....",
    "7": "--...",
    "8": "---..",
    "9": "----.",
    "0": "-----",
    ", ": "--..--",
    ".": ".-.-.-",
    "?": "..--..",
    "/": "-..-.",
    "-": "-....-",
    "(": "-.--.",
    ")": "-.--.-",
}

morese2alpha = {value: key for key, value in MORSE_CODE_DICT.items()}
decoded = "".join(morese2alpha.get(i) for i in decode.split())
print("\n")
print(decoded)
