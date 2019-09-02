from flask import Flask, render_template, request
from solver import solve, cross

app = Flask(__name__)

@app.route("/")
def index():
    """Render map"""
    return render_template("index.html")

@app.route("/submit", methods=["GET", "POST"])
def submit():
    """Render map"""
    vals = ''
    for c in request.form.getlist("cell"):
        vals += c if c.isdigit() else '.'
    vals = solve(vals)
    temp = []
    result = []
    for i, c in enumerate(cross('ABCDEFGHI', '123456789')):
        if i and not i % 9:
            result += [temp]
            temp = []
        temp += [vals[c]]
    result += [temp]
    return render_template("result.html", grid=result)
