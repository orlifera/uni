def f(x):
    return x % 731


def mixer(message, x1, x2, x3):
    assert x1 != x2
    assert x1 != x3
    assert x2 != x3
    assert x1 != (x2 + x3)
    anonym1 = f(x1)
    anonym2 = f(x2 + x3)
    assert anonym1 == anonym2
    mix = "".join([chr(ord(x) ^ x1) for x in message])
    return mix


print(f(1))
print(f(5))
with open("message.txt", "r") as file:
    print(mixer(file, 1, -1, 2))
