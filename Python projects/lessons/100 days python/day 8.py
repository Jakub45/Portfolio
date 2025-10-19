# def greet():
#     print("1")
#     print("2")
#     print("3")
#
# greet()
#
# name = input("what is your name")
# location = input("what is your location")
#
# def greet_go(name, location):
#     print(f"You tells me, you are a {name} and your location is {location}, but I know it isn't True")
#
# greet_go(name, location)


# NA JAKIEJ PLANECIE JESTEŚ

# import math

# planeta = (merkury, wenus, ziemia, mars, jowisz, saturn, uran, neptun)
# aktualna_planeta = input("na jakiej planecie jesteś ? merkury, wenus, ziemia, mars, jowisz, saturn, uran, neptun")
# docelowa_planeta = input(" a na jakiej chcesz być ? merkury, wenus, ziemia, mars, jowisz, saturn, uran, neptun ")
# odległość = abs(aktualna_planeta -= docelowa_planeta)
#
#
# for odległość in range(planeta):
#     letter = chosen_word[position]
#     # print(f"Current position: {position}\n Current letter: {letter}\n Guessed letter: {guess}")
#     if letter == guess:
#         merkury = 50000000
#         wenus = 100000000
#         ziemia = 150000000
#         mars = 220000000
#         jowisz = 1000000000
#         saturn = 10000000000
#         uran = 200000000000
#         neptun = 30000000000
#         pluton = 999999999999999999999
#
#         display[odległość] = letter
#
#
# def odległość_do_nowej_planety (aktualna_planeta, docelowa_planeta):
#     odległość = abs(int(aktualna_planeta) - int(docelowa_planeta))
#
# odległość_do_nowej_planety(aktualna_planeta, docelowa_planeta)


# import math
#
# def paint_calc(height, width, cover):
#     area = (height * width)
#     num_of_cans = math.ceil(area / cover)
#     print(f"we need {num_of_cans}")
# test_h = int(input("height of wall"))
# test_w = int(input("width of wall"))
# coverage = 5
#
# paint_calc(height=test_h, width=test_w, cover=coverage)


# test

# merkury = 50000000
# wenus = 100000000
# ziemia = 150000000
# mars = 220000000
# jowisz = 1000000000
# saturn = 10000000000
# uran = 200000000000
# neptun = 30000000000
#
#
# wynik = 0
# import math

# def planeta(wybrana_planeta, wybrana_docelowa):
#     wynik = abs(choosen_planet - choosen_destiny)
#     print(wynik)
#
# wybrana_planeta = str(input("wybierz planete,"))
# wybrana_docelowa = str(input("wybierz planete na ktorej chcesz sie znalezc"))
#
# if wybrana_planeta == ('merkury'):
#     choosen_planet = merkury
# elif wybrana_planeta ==('wenus'):
#     choosen_planet = wenus
# elif wybrana_planeta == ('ziemia'):
#     choosen_planet = ziemia
# elif wybrana_planeta == ('mars'):
#     choosen_planet = mars
# elif wybrana_planeta == ('jowisz'):
#     choosen_planet = jowisz
# elif wybrana_planeta == ('saturn'):
#     choosen_planet = saturn
# elif wybrana_planeta == ('uran'):
#     choosen_planet = uran
# elif wybrana_planeta == ('neptun'):
#     choosen_planet = neptun
#
# if wybrana_docelowa == ('merkury'):
#     choosen_destiny = merkury
# elif wybrana_docelowa ==('wenus'):
#     choosen_destiny = wenus
# elif wybrana_docelowa == ('ziemia'):
#     choosen_destiny = ziemia
# elif wybrana_docelowa == ('mars'):
#     choosen_destiny = mars
# elif wybrana_docelowa == ('jowisz'):
#     choosen_destiny = jowisz
# elif wybrana_docelowa == ('saturn'):
#     choosen_destiny = saturn
# elif wybrana_docelowa == ('uran'):
#     choosen_destiny = uran
# elif wybrana_docelowa == ('neptun'):
#     choosen_destiny = neptun
#
# planeta(wybrana_planeta, wybrana_docelowa)



# def prime_checker(number):
#     is_prime = True
#     for i in range(2, number):
#         if number % i == 0:
#             is_prime = False
#     if is_prime:
#         print("it's a prime number")
#     else:
#         print("it's not a prime number")
#
# n = int(input("check this number: "))
# prime_checker(number=n)
#
# alphabet = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','s','t','u','v','w','x','y','z']
# numbers = ['0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9']
#
# direction = input("Type 'encode', to encrypt, type 'decode' to decrypt:\n")
# text = input("Type your message:\n").lower()
# shift = int(input("Type the shift number:\n"))

# def cipher(plain_text, shift_amount):
#     cipher_text = ""
#     for letter in plain_text:
#         position = alphabet.index(letter)
#         if direction == ("encode"):
#             new_position = position + shift_amount
#             new_letter = alphabet[new_position]
#             cipher_text += new_letter
#             print(f"the encoded text is {cipher_text}")
#         elif direction ==("decode"):
#             new_position = position - shift_amount
#             new_letter = alphabet[new_position]
#             cipher_text += new_letter
#             print(f"the decoded text is {cipher_text}")

# def cipher_for_numbers(plain_text, shift_amount):
#     cipher_text = ""
#     for letter in plain_text:
#         position = numbers.index(letter)
#         if direction == ("encode"):
#             new_position = position + shift_amount
#             new_letter = numbers[new_position]
#             cipher_text += new_letter
#             print(f"the encoded text is {cipher_text}")
#         elif direction ==("decode"):
#             new_position = position - shift_amount
#             new_letter = numbers[new_position]
#             cipher_text += new_letter
#             print(f"the decoded text is {cipher_text}")
#
#
#
#
#
# cipher_for_numbers(plain_text=text, shift_amount=shift)
#
