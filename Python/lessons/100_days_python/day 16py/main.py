from menu import Menu, MenuItem
from coffee_maker import CoffeeMaker
from money_machine import MoneyMachine


money_machine = MoneyMachine()
coffee_maker = CoffeeMaker()
menu = Menu()

is_on = True
while is_on:
    options = menu.get_items()
    choice = input(f"what you want do buy ? {options} ")
    if choice == "report":
        money_machine.report()
        coffee_maker.report()
    elif choice == "off":
        is_on = False
    else:
        menu.get_items()
        serve = menu.find_drink(choice)
        print(serve)
        if coffee_maker.is_resource_sufficient(serve) is True:
            if money_machine.make_payment(serve.cost) is True:
                coffee_maker.make_coffee(serve)
