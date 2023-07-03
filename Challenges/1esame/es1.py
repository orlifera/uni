from dataclasses import replace


with open("cyphertext.txt", "r") as file:
    cipher = file.read()

print(cipher)
# commento

cipher = cipher.replace("G", "s")
cipher = cipher.replace("E", "p")
cipher = cipher.replace("N", "r")
cipher = cipher.replace("A", "i")
cipher = cipher.replace("H", "t")
cipher = cipher.replace("C", "z")
cipher = cipher.replace("P", "l")
cipher = cipher.replace("W", "f")
cipher = cipher.replace("D", "o")
cipher = cipher.replace("B", "m")
cipher = cipher.replace("Y", "d")
cipher = cipher.replace("R", "u")
cipher = cipher.replace("U", "y")
cipher = cipher.replace("I", "e")
cipher = cipher.replace("V", "h")
cipher = cipher.replace("M", "n")
cipher = cipher.replace("Z", "c")
cipher = cipher.replace("T", "a")
cipher = cipher.replace("J", "b")
cipher = cipher.replace("L", "g")
cipher = cipher.replace("O", "v")
cipher = cipher.replace("S", "j")
cipher = cipher.replace("F", "k")

print(cipher)
