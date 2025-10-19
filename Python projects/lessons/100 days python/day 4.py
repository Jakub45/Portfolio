#
# # # dwuwymiarowa mapa.
# linia1 = [" " , " " , " "]
# linia2 = [" " , " " , " "]
# linia3 = [" " , " " , " "]
# print(f"{linia1}\n{linia2}\n{linia3}\n")
#
# # Oznaczenie podanych koordynatów
# X = "X"
#
# # Mozliwosc podania koordynatów. Cyfra dziesiatek odpowiada kolumnie, jedności wierszowi
# decision = input("choose cordinates, first number is column, second is wiersz (example, 23)((min11, max33))")
# first_dimension = int(decision[0])
# second_dimension = int(decision[1])
#
# linie = [linia1 , linia2 , linia3]
# linie[first_dimension - 1][second_dimension - 1] = X
#
# print(f"{linia1}\n{linia2}\n{linia3}\n")
#



# papier kamien nozyce

player = int(input("what is your choice ? 0 is paper, 1 is rock, 2 is scissors"))

import random

paper = 0
rock = 1
scissors = 2

avalible_options = (paper,rock,scissors)
computer = (random.choice(avalible_options))
win = bool()

print(f"your choice is {player}\ncomputer choice is {computer}")

if player == computer:
    print("you are not win, but you are not lose too")
elif player == 0 and computer == 1:
    win = True
elif player == 1 and computer == 2:
    win = True
elif player == 2 and computer == 0:
    win = True
elif player == 0 and computer == 2:
    win = False
elif player == 1 and computer == 0:
    win = False
elif player == 2 and computer == 1:
    win = False

if win == True:
    print("you won!")
if win == False:
    print("you lose!")




