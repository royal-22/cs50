# Implements a registration form, confirming registration via email

import os 
import re

from flask import Flask, render_template, request 
from flask_mail import Mail, Message 

app = Flask(__name__)

# Require that "Less secure app access" be on
# https://support.google.com/accounts/answers/6010255
app.config['MAIL_DEFAULT_SENDER'] = os.environ.get('MAIL_DEFAULT_SENDER')
app.config["MAIL_PASSWORD"] = os.environ.get("MAIL_PASSWORD")
app.config["MAIL_PORT"] = 587
app.config["MAIL_SERVER"] = "smtp.gmail.com"
app.config["MAIL_USE_TLS"] = True
app.config["MAIL_USERNAME"] = os.environ.get("MAIL_USERNAME")
mail = Mail(app)

SPORTS = [
    "Basketball",
    "Soccer",
    "Ultimate Frisbee"
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    # Validate submission
    name = request.form.get("name")
    email = request.form.get("email")
    sport = request.form.get("sports")
    if not name or not email or sport not in SPORTS:
        return render_template("failure.html")
    
    message = Message("You are registered!", recipients=[email])
    mail.send(message)
    return render_template("success.html")
