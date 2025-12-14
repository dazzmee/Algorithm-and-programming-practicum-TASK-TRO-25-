available_pizzas = ["margherita", "calzone", "four cheese",
                    "peperoni", "napoli"]
pizza_order = []
total_price = 0
print("Hello! Here is the menu today:")

for i, pizza in enumerate(available_pizzas):
    print(str(i) + ". " + pizza)

continue_ordering = True
while continue_ordering:
    answer = input("Do you want to add a pizza (yes/no)? ")
    if answer == "yes":
        valid_pizza_choice = False
        while not valid_pizza_choice:
            pizza_choice = int(input(
                "What pizza do you want? (provide a number) "))
            # Validate user input
            if (pizza_choice >= 0) and \
            (pizza_choice <= len(available_pizzas) - 1):
                pizza_order.append(available_pizzas[pizza_choice])
                print("Adding " + available_pizzas[pizza_choice] + \
                      " pizza to the order")
                total_price += 10
                valid_pizza_choice = True
            else:
                print("Please provide a correct number.")
    else:
        continue_ordering = False

print("You have ordered: ")
print(pizza_order)
print("You have to pay " + str(total_price) + "€.")

valid_tip = False
while not valid_tip:
    tip = float(input("What tip do you want to leave (0-25%)? "))
    if (tip >= 0) and (tip <= 25):
        valid_tip = True
    else:
        print("Please provide a correct number.")

total_price += total_price * tip / 100
print("Thank you! The price is now " + str(total_price) + \
      "€. Pizzas are on the way.")