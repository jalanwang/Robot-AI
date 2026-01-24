from flask import Flask, send_from_directory
import os

app = Flask(__name__)

@app.route('/favicon.ico')
def favicon():
    return send_from_directory(os.path.join(app.root_path, 'static'),
                               'favicon.svg', mimetype='image/svg+xml')

@app.route("/")
def hello():
    return "<h1>Hello World!</h1>"

@app.route("/hello")
def hello2():
    return "<h1>안녕하신가!</h1>"

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8000, debug=True)