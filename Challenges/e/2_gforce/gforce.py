import base64


flag = "SU5TQXtjMTgwN2EwYjZkNzcxMzI3NGQ3YmYzYzY0Nzc1NjJhYzQ3NTcwZTQ1MmY3N2I3ZDIwMmI4MWUxNDkxNzJkNmE3fQ=="

decoded = base64.b64decode(flag).decode("ascii")

print("Flag is: ", decoded)
