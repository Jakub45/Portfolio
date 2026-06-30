MENU = {
    "espresso": {
        "ingredients": {
            "water": 50,
            "milk": 0,
            "coffee": 18,
        },
        "cost": 150,
    },
    "latte": {
        "ingredients": {
            "water": 200,
            "milk": 150,
            "coffee": 24,
        },
        "cost": 250,
    },
    "cappuccino": {
        "ingredients": {
            "water": 250,
            "milk": 100,
            "coffee": 24,
        },
        "cost": 300,
    }
}

profit = 0
resources = {
    "water": 300,
    "milk": 200,
    "coffee": 100,
}


def coin_interpreter():
    if coin_insert == "cent":
        return 1
    elif coin_insert == "nickel":
        return 5
    elif coin_insert == "dime":
        return 10
    elif coin_insert == "quarter":
        return 25
    elif coin_insert == "half_dollar":
        return 50
    elif coin_insert == "one_dollar":
        return 100
    else:
        return 0


def to_pay():
    return coffe_costs - wallet


def rest():
    return int(abs(to_pay()))


def production_capacity():
    return resources["water"] - coffe_stock["water"],\
           resources["milk"] - coffe_stock["milk"],\
           resources["coffee"] - coffe_stock["coffee"]


coffe_machine_on = True
while coffe_machine_on:
    wallet = 0
    coffe_done = False
    user_choose = input("Dzień dobry, produkujemy kawę. Jaką chciałbyś kawusię ??? "
                        "'espresso', 'latte', czy 'cappuccino' ???")

    if user_choose == "status":
        print(resources)
        user_choose = input("Dzień dobry, produkujemy kawę. Jaką chciałbyś kawusię ??? "
                            "'espresso', 'latte', czy 'cappuccino' ???")

    coffe_stock = (MENU[user_choose]["ingredients"])
    resources = {
        "water": resources["water"] - coffe_stock["water"],
        "milk": resources["milk"] - coffe_stock["milk"],
        "coffee": resources["coffee"] - coffe_stock["coffee"],
    }
    if resources["water"] < 0 or resources["milk"] < 0 or resources["coffee"] < 0:
        print("Automat nieczynny, koniec zasobów, przepraszamy.")
        coffe_machine_on = False
        break

    coffe_costs = (MENU[user_choose]["cost"])
    print(f"masz do zapłaty {coffe_costs} centow.")

    while not coffe_done:
        coin_insert = input("wrzucaj monety o nominałach 'cent', 'nickel', 'dime', 'quarter',"
                            " 'half_dollar', 'one_dollar'"". Tylko pojedynczo! ")
        wallet = wallet + coin_interpreter()
        if to_pay() < 0:
            print(f"Twoja reszta {rest()}. Smaczej kawusi.")
            coffe_done = True
            break
        print(f"wpłacona wartość wynosi {wallet}. musisz zapłacić jeszcze {to_pay()}")
