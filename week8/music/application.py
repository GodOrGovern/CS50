from flask import Flask, render_template, request
from cs50 import SQL, eprint

app = Flask(__name__)

db = SQL("sqlite:///lecture.db")

@app.route("/")
def index():
    rows = db.execute("SELECT * FROM Album")
    return render_template("index.html", albums=rows)
