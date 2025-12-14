import time

# List of cookie ingredients
ingredient_list = ["flour", "sugar", "butter", "eggs", "chocolate", "milk"]

# Initialize score
score = 0

print("Hello, you have to guess 3 ingredients from the cookies recipe, ready???")
time.sleep(3)

# Loop 3 times for guesses
for index in range(1, 4):
    answer = input(f"Ingredient {index}: ").strip().lower()

    if answer in ingredient_list:
        print(f"You have successfully guessed {answer}")
        score += 1
    else:
        print("Uh oh, your guess is wrong!")
    
    time.sleep(2)

# Final result
print(f"Game over, you have {score} points!")
print("The ingredients were:", ", ".join(ingredient_list))
