import random
import string

pwd_len = 10
pwd = ""
for i in range(pwd_len):
    pwd += random.choice(string.ascii_letters + string.digits)

print(pwd)
