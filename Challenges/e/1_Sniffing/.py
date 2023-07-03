import base64

flag = "YmFzaE5pbmphOmZsYWd7aGVscC1tZS1vYml3YW59"

decoded = base64.b64decode(flag).decode("ascii")
print("Flag is: ", decoded)
