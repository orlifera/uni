def add(x, y):
    return x + y


def sub(x, y):
    return x - y


def mult(x, y):
    return x * y


def div(x, y):
    if y != 0:
        return x / y
    else:
        return "not defined"


print("Input to integers: ")
x = int(input())
y = int(input())

print("Decide operation:")
print("1. Add")
print("2. Sub")
print("3. Mult")
print("4. Div")

choice = input(" ")


if choice == "1":
    print(add(x, y))
elif choice == "2":
    sub(x, y)
    print(sub(x, y))
elif choice == "3":
    mult(x, y)
    print(mult(x, y))
elif choice == "4":
    div(x, y)
    print(div(x, y))
