# players: represents key - value dtionary that contains:
# key : name of the player
# value: bid that player set for a game
players = {"Name" : "bid"}

def register_player(player_name, player_bid):
    try:
        players[player_name] = player_bid
    except Exception as e:
        print("Unexpected exception occured !!!: " + str(e))
        return False
    return True

def play():
    for player in players.items():
        print(player)

if __name__ == "__main__":
    register_player("Kubson", 10)
    register_player("Banan", 9)
    register_player("Kitku", 923)
    play()




