# import time
# import logging
from replit import clear

def get_player():
    player_name = input("Input your name and press ENTER to confirm: ")
    player_bid = int(input("Input your bid and press ENTER to confirm: "))
    return player_name, player_bid

def find_highest_bidder(bidding_record):
    highest_bid = 0
    winner = ""
    for bidder in bidding_record:
        bid_amount = bidding_record[bidder]
        if bid_amount > highest_bid:
            highest_bid = bid_amount
            winner = bidder
    print(f"the winner is {winner} with a bid of ${highest_bid}")

if __name__ == "__main__":
    player_with_bid = {}
    end_game = False

    while not end_game:
        player, bid = get_player()
        player_with_bid[player] = bid
        next_player = input("Do u want to add next player ? 'yes', or 'no' \n")
        if next_player.lower() == "yes":
            clear()
        else:
            find_highest_bidder(player_with_bid)
            end_game = True
    # print("Finished registering players...")
    # print("Rregistered players: ")
    # print(player_with_bid.items())




















































































########################################################################################################################################


# rozpiszmy to
# docelowo musi to wygladac tak:

# zbior_graczy = {
#     "Franek": 90,
#     "jakub": 120,
#     "Jędrzej": 9000,
# }

# zbior_graczy = [{
#
# }]
# ilosc_graczy = 9
#
# for game in range(ilosc_graczy):
#     name = input("jakie jest towje imie?")
#     bid = input("ile podbijasz?")
#     # zbior_graczy["name"] = bid
#
#
#
# print(zbior_graczy)


# [["imie", 534], ["hret", 45637], ["yhn", 765]]



# def play():
#     for player in players.items():
#         print(player)



# add_new_country = {}
#
# def add_new_country(country_visited,cities_visited,times_visited):
#     new_country = {}
#     new_country["country"] = country_visited
#     new_country["cities"] = cities_visited
#     new_country["visits"] = times_visited
#     # print(new_country)
#     travel_log.append(new_country)
#



########################################################
# student_scores = {
#     "Harry": 81,
#     "Ron": 78,
#     "Hermione": 99,
#     "Draco": 74,
#     "Neville": 62,
# }
#
# student_grade = {}
#
# for student in student_scores:
#     score = student_scores[student]
#     if score > 90:
#         student_grade[student] = "Outstanding"
#     elif score > 80:
#         student_grade[student] = "Excedes Expectations"
#     elif score > 80:
#         student_grade[student] = "Acceptable"
#     else:
#         student_grade[student] = "Fail"
#
# print(student_grade)


# # nesting
# capitals = {
#     "France": "Paris",
#     "Germany": "Berlin",
# }
#
# # nesting a list in a dictionary
# travel_log = {
#     "France": ["Paris","Hamburg","Stuttgart"],
#     "Germany": ["Berlin","Hamburg","Stuttgart"],
# }
#
# # nesting dictionary in dictionary
#
# travel_log = {
#     "France": {"cities_visited": ["Paris", "Hamburg", "Stuttgart"], "total_visits": 12},
#     "Germany":{"cities_visited": ["Berlin", "Hamburg", "Stuttgart"], "total_visits": 96},
# }
#
# # nesting dictionary in a list:

# travel_log = [
#     {
#      "country":"France",
#      "cities": ["Paris", "Hamburg", "Stuttgart"],
#      "visits": 12
#     },
#     {
#      "country":"Germany",
#      "cities": ["Berlin", "Hamburg", "Stuttgart"],
#      "visits": 96},
# ]
# add_new_country = {}
#
# def add_new_country(country_visited,cities_visited,times_visited):
#     new_country = {}
#     new_country["country"] = country_visited
#     new_country["cities"] = cities_visited
#     new_country["visits"] = times_visited
#     # print(new_country)
#     travel_log.append(new_country)
#
#
# add_new_country("Russia",["Moscow","Saint Petersburg","Stalinrad"],2)
# print(travel_log)
