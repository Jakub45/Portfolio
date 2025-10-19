import random

class player:
    def __init__(self, name):
        print("Gracz sie rodzi! Moc pruchnieje!")
        self.name = name
        self.bid = int()
        self.age = 18
        self.hunger = 4
        self.owning_a_cat = True

    def zabij_kota(self):
        self.owning_a_cat = False

    def set_name(self, name):
        self.bid = name

    def set_bid(self):
        self.bid = random.randint(0, 10)

    def krzyk(self):
        print(self.name + " krzyczy: AUUUU WYGRAM TE GRE!!")

    def get_bid(self):
        return self.bid

    def get_name(self):
        return self.name


if __name__ == "__main__":
    kuba = player("Kubson")
    kuba.krzyk()
    banan = player("Banan")
    kitku = player("Kitku")

    players = []
    players.append(kuba)
    players.append(kitku)
    players.append(banan)
    print(players)
    for player in players:
        print("Gracz " + player.get_name() + " losuje...")
        player.set_bid()

    results = []
    for player in players:
        results.append(player.get_bid())

    print(results)