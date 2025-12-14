country = input("Where do you want to drive? (South Africa, Mexico, India, France) ")
user_age = int(input("How old are you? "))

if country == "South Africa":
    if user_age >= 17:
        print("You can drive")
    else:
        print("You can't drive")
elif country == "Mexico":
    if user_age >= 18:
        print("You can drive")
    elif user_age >= 16:
        print("You can drive with parental agreement")
    elif user_age >= 15:
        print("You can drive with parental supervision")
    else:
        print("You can't drive")
elif country == "India":
    if user_age >= 18:
        print("You can drive")
    else:
        print("You can't drive")
elif country == "France":
    if user_age >= 18:
        print("You can drive")
    elif user_age >= 15:
        print("You can drive with supervision")
    else:
        print("You can't drive")
else:
    print("Data is not available for this country")
