import os
import time
import requests
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions
from werkzeug.security import check_password_hash, generate_password_hash
from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached


@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

db = SQL("sqlite:///finance.db")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    rows = db.execute("SELECT symbol, shares from owned WHERE user_id=:user_id", user_id=session['user_id'])
    cash = db.execute("SELECT cash from users WHERE id=:user_id", user_id=session['user_id'])
    stocks = [lookup(row['symbol']) for row in rows]
    total = cash[0]['cash']
    for n in range(len(rows)):
        stocks[n].update(shares=rows[n]['shares'])
        total += stocks[n]['shares'] * stocks[n]['price']
    return render_template("index.html", stocks=stocks, cash=cash[0]['cash'], total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        stock = lookup(request.form.get("symbol"))
        try:
            number = int(request.form.get("shares"))
            assert(number > 0)
        except (ValueError, AssertionError):
            return apology("invalid number of shares", 400)
        if not request.form.get("symbol") or not stock:
            return apology("invalid symbol", 400)
        shares = int(request.form.get("shares"))
        if shares < 1:
            return apology("invalid number of shares", 400)
        price = stock['price']
        cash = db.execute("SELECT cash from users WHERE id=:id", id=session['user_id'])[0]['cash']
        if (price * shares) > cash:
            return apology("insufficient funds", 400)
        db.execute("INSERT INTO transactions (price, symbol, time, user_id, shares) VALUES(:price, :symbol, :time, :user_id, :shares)",
                   price=price, symbol=stock['symbol'], time=time.strftime('%Y-%m-%d %H:%M:%S'), user_id=session['user_id'], shares=shares)
        db.execute("UPDATE users SET cash=cash-:bought WHERE id=:user_id", bought=price*shares, user_id=session['user_id'])
        rows = db.execute("SELECT * FROM owned WHERE user_id=:user_id AND symbol=:symbol", 
                          user_id=session['user_id'], symbol=stock['symbol'])
        if len(rows) == 0:
            db.execute("INSERT INTO owned (user_id, symbol, shares) VALUES(:user_id, :symbol, :shares)", 
                       user_id=session['user_id'], symbol=stock['symbol'], shares=shares)
        else:
            db.execute("UPDATE owned SET shares=shares+:bought WHERE user_id=:user_id AND symbol=:symbol", 
                       bought=shares, user_id=session['user_id'], symbol=stock['symbol'])
        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    stocks = db.execute("SELECT * from transactions WHERE user_id=:user_id", user_id=session['user_id'])
    return render_template("history.html", stocks=stocks)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""
    session.clear()
    if request.method == "POST":
        if not request.form.get("username"):
            return apology("missing username", 403)
        elif not request.form.get("password"):
            return apology("missing password", 403)
        rows = db.execute("SELECT * FROM users WHERE username=:username", username=request.form.get("username"))
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)
        session["user_id"] = rows[0]["id"]
        return redirect("/")

    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""
    session.clear()
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if symbol is None:
            return apology("missing symbol", 400)
        stock = lookup(symbol)
        if stock is None:
            return apology("invalid symbol", 400)
        return render_template("quoted.html", name=stock['name'], symbol=stock['symbol'], price=stock['price'])
    
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        user = request.form.get("username")
        passwd = request.form.get("password")
        if not user:
            return apology("missing username", 400)
        elif not passwd:
            return apology("missing password", 400)
        elif passwd != request.form.get("confirmation"):
            return apology("passwords don't match", 400)
        rows = db.execute("SELECT * FROM users WHERE username=:name", name=user)
        if len(rows) != 0:
            return apology("username already exists", 400)
        db.execute("INSERT INTO users (username, hash) VALUES(:name, :hash)", name=user, hash=generate_password_hash(passwd))
        return redirect("/")
    
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    stocks = db.execute("SELECT * FROM owned WHERE user_id=:user_id", user_id=session['user_id'])
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("missing symbol", 400)
        owned = next((stock for stock in stocks if stock["symbol"] == symbol), None)
        if not owned:
            return apology("stock not owned", 400)
        shares = int(request.form.get("shares"))
        if not shares:
            return apology("missing shares", 400)
        elif owned['shares'] < shares:
            return apology("too many shares", 400)
        price = lookup(symbol)['price']
        db.execute("INSERT INTO transactions (price, symbol, time, user_id, shares) VALUES(:price, :symbol, :time, :user_id, :shares)",
                   price=price, symbol=symbol, time=time.strftime('%Y-%m-%d %H:%M:%S'), user_id=session['user_id'], shares=-shares)
        db.execute("UPDATE users SET cash=cash+:sold WHERE id=:user_id", sold=(price*shares), user_id=session['user_id'])
        db.execute("UPDATE owned SET shares=shares-:sold WHERE user_id=:user_id AND symbol=:symbol",
                   sold=shares, user_id=session['user_id'], symbol=symbol)
        db.execute("DELETE FROM owned WHERE user_id=:user_id AND shares=0", user_id=session['user_id'])
        return redirect("/")

    else:
        return render_template("sell.html", stocks=stocks)


@app.route("/account", methods=["GET", "POST"])
@login_required
def account():
    """Basic account overview and changes"""
    if request.method == "POST":
        current = request.form.get("current")
        if not current:
            return apology("missing password", 400)
        valid = db.execute("SELECT hash FROM users WHERE id=:user_id", user_id=session['user_id'])
        if not check_password_hash(valid, current):
            return apology("invalid password", 400)
        new = request.form.get("new")
        if not new:
            return apology("missing new password", 400)
        elif new != request.form.get("confirm"):
            return apology("passwords don't match", 400)
        db.execute("UPDATE users SET hash=:hash WHERE id=:user_id", hash=generate_password_hash(new), user_id=session['user_id'])

    else:
        return render_template("account.html")


def errorhandler(e):
    """Handle error"""
    return apology(e.name, e.code)


# listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)