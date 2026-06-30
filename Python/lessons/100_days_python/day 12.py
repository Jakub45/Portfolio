#  KOD LOSUJE JEDNĄ LICZBĘ, SPOŚRÓD 100 ELEMENTÓW KTÓRĄ
#  UŻYTKOWNIK MUSI ZGADNĄĆ. MA NA TO OKREŚLONĄ ILOŚĆ SZANS. NA ILOŚĆ SZANS UŻYTKOWNIK TEŻ MA WPŁYW
import random

def too_high_or_low():
    if user_choosen_number < random_number:
        print("too low")
    if user_choosen_number > random_number:
        print("too high")

def difficulty():
    if difficulty_level == "normal":
        return 11
    elif difficulty_level == "hard":
        return 6

print("Hello. This is a game when you must choose correct number."
      "One number from 0 to 100 is correct, you must him."
      "In difficulty 'normal' you hav 10 lives, in 'hard' difficulty, only 5 "
      "Good luck !")

new_game = True
while new_game:
    difficulty_level = input("What difficulty level you want ? 'normal', or 'hard'")
    game_over = False
    random_number = random.randint(0, 100)
    while not game_over:

        for chance in range(difficulty()):
            user_choosen_number = int(input("What is your number ? (interger from 0 to 100)"))
            if user_choosen_number == random_number:
                game_over = True
                print("You choose correct number !")
                play_again = input("you want to play next ? 'yes' , or 'no'. ")
                if play_again == "no":
                    new_game = False
                    break
                elif play_again =="yes":
                    break
            else:
                too_high_or_low()
                chance += 1
                print(chance)
        if user_choosen_number == random_number:
            break
        play_again = input("you lose all lives. you died. You want to play next ? 'yes' , or 'no'. ")
        if play_again == "no":
            game_over = True
            new_game = False
        else:
            game_over = True
