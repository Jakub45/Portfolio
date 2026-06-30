# # WISIELEC
# # GRA MUSI:
# # -- GENEROWAĆ SŁOWO (WYBIERAĆ Z PODANYCH)
# #
# # -- PODAWAĆ UŻYTKOWNIKOWI DŁUGOŚĆ
# #
# # -- PYTAĆ UŻYTKOWNIKA O LITERĘ
# #
# # -- SPRAWDZAĆ PODANĄ LITERĘ ::
# #
# #     -- JEŚLI DOBRA:
# #
# #         -- PODAWAĆ UYTKOWNIKOWI EFEKT I PĘTLA
# #
# #     -- JEŚLI ZŁA:
# #
# #         -- PODAWAĆ UŻYTKOWNIKOWI EFEKT I PĘTLA
# #
# # -- PO WYKONANIU ZAŁOŻEŃ, KONIEC GRY:
#
# ###############################################
#
# import random
#
# word_to_check = ["puchak", "misiak", "kitka", "moro", "wyinicjowany"]
# unknown_word = (random.choice(word_to_check))
# known_words = []
# x = 0
#
# end_of_the_game = False
# if
#
#
# while end_of_the_game == False:
#     choice = input("type a letter").lower()
#     for letter in unknown_word:
#         if letter == choice:
#             known_words += letter
#             print(known_words)
#             break
#         else:
#             print("_")
#     print(unknown_word)
#     print(known_words)
#
# the_word = unknown_word
#
# the_word.insert(known_words, )
#
#
# print(x)
# print("you lose !")


# Step 4
import random
from replit import clear


stages = ['''
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========
''', '''
  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========
''', '''
  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========
''', '''
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
  |   |
      |
      |
=========
''', '''
  +---+
  |   |
  O   |
      |
      |
      |
=========
''', '''
  +---+
  |   |
      |
      |
      |
      |
=========
''']

end_of_game = False
word_list = ["ardvark", "baboon", "camel"]
chosen_word = random.choice(word_list)
word_length = len(chosen_word)

#TODO-1: - Create a variable called 'lives' to keep track of the number of lives left.
#Set 'lives' to equal 6.

lives = 6
while lives == 0:
    print("You lose")
    end_of_game = True

#Testing code
print(f'Pssst, the solution is {chosen_word}.')

#Create blanks
display = []
for _ in range(word_length):
    display += "_"

while not end_of_game:
    guess = input("Guess a letter: ").lower()
    clear()
    #Check guessed letter
    for position in range(word_length):
        letter = chosen_word[position]
        # print(f"Current position: {position}\n Current letter: {letter}\n Guessed letter: {guess}")
        if letter == guess:
            display[position] = letter
    #TODO-2: - If guess is not a letter in the chosen_word,
    #Then reduce 'lives' by 1.
    #If lives goes down to 0 then the game should stop and it should print "You lose."
    if guess not in chosen_word:
        lives -= 1
        print(f"you have {lives} lives")
        print(stages[lives])
        if lives == 0:
            end_of_game = True
            print ("you lose")
    #Join all the elements in the list and turn it into a String.
    print(f"{' '.join(display)}")

    #Check if user has got all letters.
    if "_" not in display:
        end_of_game = True
        print("You win.")

    #TODO-3: - print the ASCII art from 'stages' that corresponds to the current number of 'lives' the user has remaining.