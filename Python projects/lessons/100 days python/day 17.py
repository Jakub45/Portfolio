class production:
    def __init__(self):
        self.food -= self.population

class kingdom:
    def __init__(self, name):
        self.name = name
        self.territory = 130
        self.population = 80
        self.food = 100
        self.gold = 250
        self.is_existing = True
        self.is_religious = False

    def make_farm(self):
        self.food += 20


if __name__ == "__main__":
    name_of_kingdom = input("choose a name for your kingdom!")
    your_kingdom = kingdom(name_of_kingdom)
    print(your_kingdom)

    while your_kingdom.is_existing is True:
        decisions = input("what is your decision ?")
        if decisions == "build a farm":
            your_kingdom.make_farm()