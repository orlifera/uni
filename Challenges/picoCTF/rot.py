from textwrap import wrap

key = 13

cipher = "cvpbPGS{arkg_gvzr_V'yy_gel_2_ebhaqf_bs_ebg13_jdJBFOXJ}"
cipher = list(cipher)
print(cipher)


output = ""
for j in range(2):
    for i in cipher:

        output += chr(ord(i) + key)
    print(output)
