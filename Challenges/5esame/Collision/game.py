import random
import datetime

# decrypt the following
ciphertext = "ZSUASRZDTF?~jesj_flkojqkjfy5?;5u0y"


def XOR(text, seed):
    # set the seed to allow reproducibility
    random.seed(seed)
    x = "".join([chr(ord(x) ^ random.randint(0, 10)) for x in text])
    print(x)
    return x


# print(XOR(ciphertext, 53))


def h(x, y=123):
    while x >= y:
        x = x - y
    print(x)
    return x


# print(h(2021))


def encrypt(text):
    year = 2021  # datetime.date.today().year
    cipher = XOR(text, h(year))

    return cipher


def decrypt(text, seed):
    if seed <= 10000:
        raise Exception(f"Not so easy! The value {seed} cannot be accepted")

    plaintext = XOR(text, h(seed))
    print(plaintext)
    return plaintext


decrypt(ciphertext, 10016)
