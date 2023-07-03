from dataclasses import replace
from textwrap import wrap


ciphertext = "yxyxxyy yxyxxxx yxyxxyx yxxyxxy yxyxyxx yxyyxyx yxxxxyy yxyxyxx yxxxyyx yyyyxy yyyyxyy yyxxyxy yyxyyyx yyxxxyy yyyxxyx yyyyxxy yyyxxxx yyyxyxx yyxyxxy yyxyyyy yyxyyyx yyxxxx yyxxxx yyxxxx yyxxxx yyxxxx yyxxxy yyyyyxy"

# ciphertext = ciphertext.replace("yxyxxyy", "s")
# ciphertext = ciphertext.replace("yxyxxxx", "p")
# ciphertext = ciphertext.replace("yxyxxyx", "r")
# ciphertext = ciphertext.replace("yxxyxxy", "i")
# ciphertext = ciphertext.replace("yxyxyxx", "t")
# ciphertext = ciphertext.replace("yxyyxyx", "z")
# ciphertext = ciphertext.replace("yxxxxyy", "c")
# ciphertext = ciphertext.replace("yxxxyyx", "f")
# # ciphertext = ciphertext.replace("yyyyxy", "{")
# # ciphertext = ciphertext.replace("yyyyyxy", "}")
ciphertext = ciphertext.replace("y", "1")
ciphertext = ciphertext.replace("x", "0")
ciphertext = ciphertext.split(" ")
print(ciphertext)
prova = ""
for i in ciphertext:
    prova += chr(int(i, 2))

print(prova)
