import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Create a new table and index to keep track of stock orders by each user
db.execute(
    "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username TEXT NOT NULL, hash TEXT NOT NULL, cash NUMERIC NOT NULL DEFAULT 10000.00)"
)
db.execute("CREATE UNIQUE INDEX IF NOT EXISTS username ON users (username)")
db.execute(
    "CREATE TABLE IF NOT EXISTS transactions (id INTEGER PRIMARY KEY, user_id INTEGER, transacted DEFAULT CURRENT_TIMESTAMP NOT NULL, symbol TEXT NOT NULL, shares NUMERIC NOT NULL, price NUMERIC NOT NULL, FOREIGN KEY(user_id) REFERENCES users(id))"
)


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # get the current user's user_id
    user_id = session["user_id"]

    # get the current user's stocks that they own right now (stocks w more than 0 shares)
    shares = db.execute(
        "SELECT symbol, SUM(shares) as num_shares FROM transactions WHERE user_id = ? GROUP BY symbol HAVING num_shares > 0",
        user_id,
    )

    # retrieve the cash balance from our database (with the current user's user_id)
    cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]

    # calculating total value of cash balance + shares (added in later in loop)
    total_value = cash

    # loop for each share
    for share in shares:
        quote = lookup(share["symbol"])
        share["name"] = quote["name"]
        share["price"] = quote["price"]
        share["value"] = share["price"] * share["num_shares"]
        total_value += share["value"]

    return render_template(
        "index.html", shares=shares, cash=cash, total_value=total_value
    )


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        shares = request.form.get("shares")
        quote = lookup(symbol)

        # check if the symbol is invalid
        if not symbol or quote is None:
            return apology("INVALID SYMBOL.")

        # check if the number of shares is invalid
        elif not shares or not shares.isdigit() or int(shares) <= 0:
            return apology("INVALID SHARES.")

        # calculating total cost of the shares to be bought
        total_cost = int(shares) * quote["price"]

        # getting user's cash balance
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0][
            "cash"
        ]

        # if user cannot afford the transaction
        if cash < total_cost:
            return apology("NOT ENOUGH CASH.")

        # execute a transaction
        db.execute(
            "INSERT INTO transactions (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)",
            session["user_id"],
            symbol,
            shares,
            quote["price"],
        )

        # update the amount of cash the user has
        db.execute(
            "UPDATE users SET cash = ? WHERE id = ?",
            cash - total_cost,
            session["user_id"],
        )

        flash("Bought!")
        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # get the transactions from the transactions table in the database for current user
    transactions = db.execute(
        "SELECT * FROM transactions WHERE user_id = ?", session["user_id"]
    )
    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "POST":
        # check for existence of symbol
        symbol = request.form.get("symbol")
        quote = lookup(symbol)
        if not symbol or not quote:
            return apology("INVALID SYMBOL.")
        return render_template("quoted.html", quote=quote)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        # error checking for all situations
        if not request.form.get("username"):
            return apology("INVALID USERNAME.")
        elif not request.form.get("password"):
            return apology("INVALID PASSWORD.")
        elif not request.form.get("confirmation"):
            return apology("INVALID CONFIRMATION.")
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("PASSWORDS DO NOT MATCH.")

        # query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?;", request.form.get("username")
        )

        if len(rows) != 0:
            return apology("username already exists", 400)

        # insert username to database
        user_id = db.execute(
            "INSERT INTO users (username, hash) VALUES(?, ?)",
            request.form.get("username"),
            generate_password_hash(request.form.get("password")),
        )

        # remember logged in user
        session["user_id"] = user_id

        flash("Registered!")
        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    shares_to_sell = db.execute(
        "SELECT symbol, SUM(shares) as total_shares FROM transactions WHERE user_id = ? GROUP BY symbol HAVING total_shares > 0",
        session["user_id"],
    )

    if request.method == "POST":
        # error checking
        symbol = request.form.get("symbol").upper()
        shares = request.form.get("shares")

        if not symbol:
            return apology("INVALID SYMBOL.")

        elif not shares or not shares.isdigit() or int(shares) <= 0:
            return apology("INVALID SHARES.")

        shares = int(shares)

        # for share to sell
        for sell_share in shares_to_sell:
            if sell_share["symbol"] == symbol:
                if sell_share["total_shares"] < shares:
                    return apology("NOT ENOUGH SHARES.")
                else:
                    quote = lookup(symbol)
                    if quote is None:
                        return apology("INVALID SYMBOL.")

                    # updating user's cash amount
                    db.execute(
                        "UPDATE users SET cash = cash + ? WHERE id = ?",
                        shares * quote["price"],
                        session["user_id"],
                    )

                    # updating user's transactions
                    db.execute(
                        "INSERT INTO transactions (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)",
                        session["user_id"],
                        symbol,
                        -shares,
                        quote["price"],
                    )

                    flash("Sold!")
                    return redirect("/")

            return apology("INVALID SYMBOL.")

    else:
        return render_template("sell.html", symbols=shares_to_sell)


@app.route("/deposit", methods=["GET", "POST"])
@login_required
def deposit():
    """Deposit additional cash"""

    if request.method == "POST":
        # check if amount requested to deposit is valid
        add_cash = request.form.get("deposit_amount")
        if not add_cash or not add_cash.isdigit() or int(add_cash) <= 0:
            return apology("INVALID DEPOSIT AMOUNT.")

        add_cash = int(add_cash)

        db.execute(
            "UPDATE users SET cash = cash + ? WHERE id = ?",
            add_cash,
            session["user_id"],
        )

        flash("Deposited!")
        return redirect("/")
    else:
        return render_template("deposit.html")
