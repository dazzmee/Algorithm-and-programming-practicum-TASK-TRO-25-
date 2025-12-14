#Guess the country games

import time
country = [
    "INDONESIA", "BRAZIL", "CHINA", "USA",
    "JAPAN", "SAUDI ARABIA", "EGYPT", "ITALY",
    "UK", "TURKEY"]

health = 3
point = 0

while health > 0:
    print("You have", health , " health point" )
    user_input = input("Guess the country : ").upper()
    if user_input in country:
        print("correct answer\n")
        point += 10
    else:
        print("Your answer is wrong\n")
        health -= 1

print(point)
time.sleep(3)
print("Thanks for playing the games")