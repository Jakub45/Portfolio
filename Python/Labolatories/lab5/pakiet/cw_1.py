def czy_swieci_slonce():
    print("czy świeci dziś słońce (tak/nie) ?")
    is_true = True
    while is_true:
        answer = input()
        if answer == "tak":
            print("co tu robisz?")
            is_true = False
        elif answer == "nie":
            print("pracuj dalej!")
            is_true = False
        else:
            print("Przepraszam, nie rozumiem")

czy_swieci_slonce()
