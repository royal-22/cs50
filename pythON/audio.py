import pyttsx3

engine = pyttsx3.init()
name = input("What's your name? ")
voices = engine.getProperty('voices') 
engine.setProperty('voice', voices[1].id)
engine.say(f"hello, {name}")
engine.runAndWait()