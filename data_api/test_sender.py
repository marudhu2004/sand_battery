from time import sleep
import requests
import random
import json

while False:
    data = json.dumps({"sen1": random.randint(20, 200), "sen2": random.randint(20, 200), "sen3": random.randint(20, 200)})
    requests.post("https://marudhu2004.pythonanywhere.com/update", data, headers={"content-type": "application/json"})
    sleep(0.5)

data = json.dumps({"sen1": random.randint(20, 200), "sen2": random.randint(20, 200), "sen3": random.randint(20, 200)})
print(data)