import random
import math



class kingdom:
    def __init__(self, name):
        self.name = name

        self.num_of_farms = 0
        self.num_of_mines = 0
        self.num_of_swords = 5

        self.territory = 130
        self.population = 80
        self.food = 100
        self.gold = 250
        self.num_of_paladins = 0
        self.is_existing = True
        self.is_religious = False


    def report(self):
        print(f"you have population {self.population}. Possesing a religion of your kingdom is {self.is_religious}."
              f" You control {self.territory}km2 of area. You have {self.food} food, {self.gold} gold and {self.num_of_swords} swords. You have "
              f"{self.num_of_farms} farms, {self.num_of_mines} mines and {self.num_of_paladins} paladins.")

    def make_farm(self):
        self.num_of_farms += 1
        self.gold -= 25
        self.territory -= 10

    def make_mine(self):
        self.num_of_mines += 1
        self.food -= 10
        self.territory -= 8
        self.num_of_swords += 1

    def making_religion(self):
        self.population -= 20
        self.territory += 100
        self.gold -= 40
        self.num_of_swords += 100
        self.num_of_paladins = 0
        self.is_religious = True

    def train_troops(self):
        if decisions == "train_troops":
            num_of_trained_troops = int(input("How many troops you wanted to rent ?"))
            self.num_of_swords = self.num_of_swords - num_of_trained_troops
            self.population = self.population - num_of_trained_troops
            self.num_of_paladins = self.num_of_paladins + num_of_trained_troops
        else:
            print("You cannot train more troops.")

    def production(self):
        self.food = self.food + self.num_of_farms
        self.gold = self.gold + self.num_of_mines
        self.gold = self.gold - self.num_of_paladins

    def if_resources_incufissient(self):
        if self.food < 0:
            print("Your people are starving!")
            self.population = self.population - 2
        if self.gold <0 and self.num_of_paladins > 0 :
            print("You have incuffisient gold to rent your troops! Some of them are betray.")
            self.num_of_paladins -= 3
            self.territory -= 7
            self.population -= 5

    def paladins_rent(self):
        self.food -= self.num_of_paladins
        self.gold -= self.num_of_paladins


    def decision(self):
        if decisions == "make_farm":
            your_kingdom.make_farm()
        elif decisions == "make_mine":
            your_kingdom.make_mine()
        elif decisions == "making_religion":
            your_kingdom.making_religion()
        elif decisions == "train_troops":
            your_kingdom.train_troops()

        else:
            print("King cannot stutter ! After your bad decisions you lose some gold and population")
            self.gold -= 12
            self.population -= 3

    def if_end_game(self):
        if self.gold < -100 or self.food < -100 or self.population <= 0 or self.num_of_paladins <0 :
            print("Your kingdom is fell into chaos. Your troops are joined to local bandits,"
                  " rest of your people are retreated or has been murdered."
                  " Your remainings is lying near a huge sycamore in local forest.")
            self.is_existing = False

    def bandits(self):
        propability_of_attack = random.randint(0, 10)
        if propability_of_attack == 10:
            self.num_of_bandits = random.randint(4,18)
            print(f"Your kingdom has been attacked by bandits ! Number of bandits - {self.num_of_bandits}")
            paladin_vs_bandit_ratio = 0.2
            self.num_of_paladins = self.num_of_paladins - (self.num_of_bandits * paladin_vs_bandit_ratio)
            self.num_of_paladins = math.ceil(self.num_of_paladins)
            print(f"Your knights fight with bandits. Survived {self.num_of_paladins} paladins")



if __name__ == "__main__":
    print("Welcome! You stayed on a heritage for your great-grandfathers."
          " You must good manage of your kingdom to lest it be destroyed."
          "Remember about your soldiers, because bandits lurks in hiding."
          "Mines produces gold, farms produces food, religion gives you some perks."
          "To rent you soldiers you need swords and population. Remember that you must paid him!")


    name_of_kingdom = input("choose a name for your kingdom!")
    your_kingdom = kingdom(name_of_kingdom)
    while your_kingdom.is_existing is True:
        your_kingdom.report()
        decisions = input("what is your decision ? You want to 'making_religion', 'make_farm', 'make_mine', or 'train_troops' ? Type it")
        your_kingdom.train_troops()
        your_kingdom.decision()
        your_kingdom.production()
        your_kingdom.paladins_rent()
        your_kingdom.bandits()
        your_kingdom.if_resources_incufissient()
        your_kingdom.if_end_game()

