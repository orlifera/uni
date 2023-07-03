import requests

r = requests.get("http://127.0.0.1:8084/").text
print(r)
