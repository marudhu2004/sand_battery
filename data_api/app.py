from flask import Response
from flask import request
from flask import Flask
from flask import json


app = Flask(__file__)
data = {}


@app.route("/update", methods=["POST"])
def update_data():
    global data
    data = request.get_json(force=True)
    return Response({"status": "ok"}, content_type="application/json")


@app.route("/")
def retrive_data():
    return Response(json.dumps(data), content_type="application/json")


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)