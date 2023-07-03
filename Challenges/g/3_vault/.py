import base64

flag = "ZW5jcnlwdENURntpX0g0dDNfaW5KM2M3aTBuNX0="

dec = base64.b64decode(flag).decode("ascii")

print(dec)
