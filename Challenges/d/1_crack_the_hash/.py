import hashlib

c = "365d38c60c4e98ca5ca6dbc02d396e53"

pwd_list = ["pwd", "password", "password1", "passowrd123", "password12345"]

for word in pwd_list:
    guess = hashlib.md5(word.encode("utf-8")).hexdigest()
    if guess == c:
        print("password found: ", word)
    else:
        print(word, "Isn't the password.")
