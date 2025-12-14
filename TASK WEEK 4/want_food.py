#Favorite food pick

food = ["chicken noddle", "chicken smash", "rendang", "sate", "bakso", "orak-arik"]
price = ["15000", "20000", "30000", "25000", "13000", "18000"]

print("====MENU====")
for i in range(len(food)) :
    print(f"{food[i]} - Rp.{price[i]}")

user_input = input("Enter Your favorite food: ").lower()

if user_input in food:
    index = food.index(user_input)
    print(f"your favorite food is {food[index]} and you must pay Rp.{price[index]}")
else:
    print("your input is not on the list")