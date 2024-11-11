from time import sleep
import requests


while True:
    resp = requests.get("https://marudhu2004.pythonanywhere.com/")
    print(resp.text)
    sleep(0.25)