# Checking_year =input("which year do you want to check ?")
# Leap_year = int(Checking_year) % 4 == 0
# print(Leap_year)
#
# if Leap_year is True:
#     print("yeas, that year are leap year")
# else:
#     print("it wasn't a leap year")
# #
# # Continuation = input("you want to continue ? is yes, type true")
# # if Continuation is True:
# #     return
# # elif:
#
# if int(Checking_year) % 4 == 0 and int(Checking_year) % 100 == 0:
#     print("yes, jest przestepny")
# elif int (Checking_year) % 400 == 0:
#     print("yes , jest przestepny")
# else:
#     print("nie jest")
#

#
# print("welcome to pizza's factory")
# # def (Pizza_price)
#
# Pizza_size = input("what size of pizza you want? small, medium or big ?")
# Pepperoni_to_pizza = input("you want a peeperoni to pizza ? yes or no")
# Extra_cheese = input("you want extra cheese to pizza ? Yes or no")
#
# Pizza_price = 0
# if Pizza_size == str ( "small" ):
#     Pizza_price += 15
#     if Pepperoni_to_pizza == str("yes"):
#         Pizza_price += 2
#     if Extra_cheese == str("yes"):
#         Pizza_price += 3
# elif Pizza_size == str( "medium" ):
#     Pizza_price += 17
#     if Pepperoni_to_pizza == str("yes"):
#         Pizza_price += 3
#     if Extra_cheese == str("yes"):
#         Pizza_price += 3
# elif Pizza_size == str( "big" ):
#     Pizza_price += 19
#     if Pepperoni_to_pizza == str("yes"):
#         Pizza_price += 3
#     if Extra_cheese == str("yes"):
#         Pizza_price += 3
#
# print(f"your pizza price is {Pizza_price}$")
#

# Love calculator

# Name1 = input("what is the name of the first person")
# Name2 = input("what is the name of the second person")

# Names = str(Name1) + str(Name2)
# Names.lower

# true = Names.count("t") + Names.count("r") + Names.count("u") + Names.count("e") 
# love = Names.count("l") + Names.count("o") +Names.count("v") +Names.count("e")

# Final = str(true) + str(love)
# print(f"love is ture in {Final}%")


# print("You must find Morro. Morro is a cat. PS: Kitka and Misiak is also a cat, Kukskus is a dog :P")
# print("how to find Morro in the forest")
# choice1 = input("You are on the forest route, you can go left or forward. but is there something to the left, but you don't heard Morro's miaow. where you want to go ?")
# if choice1 == "left":
#     print("You go to the left, but there's a bewitching Kitka. You are enchantement, you lose")
# elif choice1 == "forward":
#     choice2 = input("You go forward and you are see collapsed tree over the valley. You can go forward or go trough this rotten, moldy tree. Where you want to go ? tree or forward ? ")
#     if choice2 == "tree":
#         choice3 = input("You make a few steps trough this rotten, moldy tree. Suddenly, you heard crash and on this tree jumped off Misiak's Pucharro. Misiak challenges you to a duel. you want to accept a challenge ? yes or no ")
#         if choice3 == "yes":
#             print("You are finghting with Misiak on a sword skewer, but you are died. You lose")
#         elif choice3 == "no":
#             print("you are covered with disgrace and you could just go forward.")
#     if choice2 == "forward" or choice3 == "no":
#         choice4 = input("you came to a very huge, majetic tree, which spread is 40 meters and height is 200meters. You heard that something like was running to you. You can climb to this tree, when probably Morro is, or stay and wait. What you want to do? wait or climb")
#         if choice4 == "climb":
#             print("you are climbing to this tree. After 7 hours of climbing you lose your bearings and you couldn't go ahead. You lose")
#         elif choice4 == "wait":
#             print("When you wait a 17.4 seconds, you saw a reason of this sounds. You see a Misiak which fights with a Kukskus II fearful. Suddenly, behind this tree, comes out Morro. You found a Morro. Morro calls pegasus and you are fly away. You win.")

#
# names_string = input("Give me everybody's names, seperated by a comma. ")
# names = names_string.split(", ")

# import random

# num_items = len(names)
# random_choice = random.randint(0, num_items - 1)
# person_who_pay = names[random_choice]
# print(person_who_pay + " is goint to buy for a meal")

# # # OR
# import random
# person_who_pay = random.choice(names)
# print(person_who_pay + " wefwoijqfeoij")