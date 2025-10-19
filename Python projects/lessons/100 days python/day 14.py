import random


def compare(choice):
    if choice == "yes":
        if first_element >= next_element:
            return False
        elif first_element < next_element:
            return True
    elif choice == "no":
        if first_element >= next_element:
            return True
        elif first_element < next_element:
            return False


elements = {
    "puch": 1,
    "kitka": 3,
    "misiak": 8,
    "szymon": 0,
    "kiciucha_tega_jucha": 90,
}
if __name__ == "__main__":
    play = input("Siema. Czy chcesz grać w grę ?? jeśli tak 'yes'. ")
    new_game = False
    if play == "yes":
        new_game = True

    while new_game:
        print("Dzień dobry. To jest gra, gdzie musisz wybrać, czy pierwszy element ma większą wartość od drugiego.")
        first_element = random.choice(list(elements.items()))
        next_element = random.choice(list(elements.items()))

        end_game = False
        while not end_game:
            x = input(f"What do you think, {first_element} is greater than {next_element}??? Type 'yes' or 'no'. ")
            if compare(choice=x) is True:
                print("dobrze!")
                first_element = next_element
                next_element = random.choice(list(elements.items()))
            elif compare(choice=x) is False:
                end_game = True
                print("źle!")
                play_or_not = input("you want to play next? 'yes' or 'no'. ")
                if play_or_not == "no":
                    new_game = False
