print(
"""
░░░░░░░░░░░░░░░░░░░░░▄▀░░▌░░░░░░
░░░░░░░░░░░░░░░░░░░▄▀▐░░░▌░░░░░░
░░░░░░░░░░░░░░░░▄▀▀▒▐▒░░░▌░░░░░░
░░░░░▄▀▀▄░░░▄▄▀▀▒▒▒▒▌▒▒░░▌░░░░░░
░░░░▐▒░░░▀▄▀▒▒▒▒▒▒▒▒▒▒▒▒▒█░░░░░░
░░░░▌▒░░░░▒▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄░░░░
░░░░▐▒░░░░░▒▒▒▒▒▒▒▒▒▌▒▐▒▒▒▒▒▀▄░░
░░░░▌▀▄░░▒▒▒▒▒▒▒▒▐▒▒▒▌▒▌▒▄▄▒▒▐░░
░░░▌▌▒▒▀▒▒▒▒▒▒▒▒▒▒▐▒▒▒▒▒█▄█▌▒▒▌░░
░▄▀▒▐▒▒▒▒▒▒▒▒▒▒▒▄▀█▌▒▒▒▒▒▀▀▒▒▐░░░▄
▀▒▒▒▒▌▒▒▒▒▒▒▒▄▒▐███▌▄▒▒▒▒▒▒▒▄▀▀▀▀░░
▒▒▒▒▒▐▒▒▒▒▒▄▀▒▒▒▀▀▀▒▒▒▒▄█▀░░▒▌▀▀▄▄░░
▒▒▒▒▒▒█▒▄▄▀▒▒▒▒▒▒▒▒▒▒▒░░▐▒▀▄▀▄░░░░▀░░
▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▄▒▒▒▒▄▀▒▒▒▌░░▀▄░░░░░░
▒▒▒▒▒▒▒▒▀▄▒▒▒▒▒▒▒▒▀▀▀▀▒▒▒▄▀░░░░░░░░░░░░
░█████░░█░░░░░░░░██░░░░░░░██░░░░█░░░░░░░
░██░░█░░█░░░░░░░░███░░░░░██░░░░░█░░░██░░
░█░░██░░█░░░░░░░░█░██░░░█░░░░░░░█░███░░░
░████░░░█░░░░░░░░█░░█░░░█░░░░░░░███░░░░░
░█░░░██░█░░░░░░░█████░░░█░░░░░░░█░░██░░░
░██████░██████░░█░░░█░░░█████░░░█░░░░█░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
░░░░██████░░░░░░█░░░░░░░░██░░░░█░░░░█░░░
░░░░░░░░░█░░░░░███░░░░░██░░░░░░█░░░██░░░
░░░░░░░░░█░░░░██░█░░░░██░░░░░░░█░███░░░░
░░░░░░░░█░░░░██░░█░░░█░░░░░░░░░██░░░░░░░
░░░░░░░░█░░░███████░░██░░░░░░░░████░░░░░
░░░░░█░░█░░██░░░░░█░░░███░░░░░░█░░███░░░
░░░░░███░░░█░░░░░░█░░░░░████░░░█░░░░█░░░

Hello !!! This is orginal Kuboleon's blackjack game (alfa version, ace pack in DLC). I will give you two cards. 
You must have more valuable cards from me, to win, but you can't have more than 21. 
The earth starts to rumble !
""")

import random

def player_or_computer_cards_value(n1, n2):
    return n1 + n2

def ace(n1, n2):
    if n1 or n2 == 11:
        if player_or_computer_cards_value(n1,n2) > 21:
            return n1 or n2 == 1
        elif player_or_computer_cards_value(n1,n2) <= 21:
            return n1 or n2 == 11


if __name__ == "__main__":
    def game():
        new_game = True
        while new_game:
            all_player_cards_value = 0
            all_computer_cards_value = 0

            card_value_list = [2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10]
            player_first_card = 0
            player_second_card = 0
            computer_first_card = 0
            player_first_card += random.choice(card_value_list)
            card_value_list.remove(player_first_card)

            computer_first_card += random.choice(card_value_list)
            card_value_list.remove(computer_first_card)

            player_second_card += random.choice(card_value_list)
            card_value_list.remove(player_second_card)

            first_two_player_cards = player_or_computer_cards_value(player_first_card, player_second_card)
            all_player_cards_value += first_two_player_cards

            computer_second_card = 0
            computer_second_card += random.choice(card_value_list)
            card_value_list.remove(computer_second_card)
            first_two_computer_cards = player_or_computer_cards_value(computer_first_card, computer_second_card)
            all_computer_cards_value += first_two_computer_cards

            print(f"You have two cards, which value are {all_player_cards_value} . ")
            print(f"I have one card, which value is {computer_first_card} . ")

            game_in_progress = True
            while game_in_progress:
                another_card = input("You want to take another card ? Type 'yes' or 'pass' ")
                if another_card == "yes":
                    player_next_card = random.choice(card_value_list)
                    card_value_list.remove(player_next_card)
                    all_player_cards_value += player_next_card
                    print(all_player_cards_value)
                    if all_player_cards_value >= 22:
                        game_in_progress = False
                        play_or_not = input("you have more than 21. You lose! You want to continue-'yes' ? ")
                        if play_or_not == "yes":
                            continue
                        else:
                            new_game = False

                elif another_card == "pass":
                    while all_computer_cards_value <= 15:
                        computer_next_card = 0
                        computer_next_card += random.choice(card_value_list)
                        card_value_list.remove(computer_next_card)
                        all_computer_cards_value += computer_next_card
                        if all_computer_cards_value >= 22:
                            game_in_progress = False
                            play_or_not = input("Kuboleon have more than 22. You Win! You want to continue-'yes' ? ")
                            if play_or_not == "yes":
                                continue
                            else:
                                new_game = False
                    if all_computer_cards_value >= 16:
                        if all_computer_cards_value > all_player_cards_value:
                            play_or_not = input(f" Kuboleon have {all_computer_cards_value}, you have {all_player_cards_value}. You Lose. You want to continue ? ")
                            game_in_progress = False
                        elif all_computer_cards_value < all_player_cards_value:
                            play_or_not = input(f" Kuboleon have {all_computer_cards_value}, you have {all_player_cards_value}. You Win !. You want to continue ? ")
                            game_in_progress = False
                        elif all_computer_cards_value == all_player_cards_value:
                            play_or_not = input(f" Kuboleon have {all_computer_cards_value}, you have {all_player_cards_value}. It's a draw. You want to continue ?")
                            game_in_progress = False
                            if play_or_not == "yes":
                                continue
                            else:
                                new_game = False


    game()


# TODO 3:
#  AS MOZE BYC 1 I 11, NIE WIEM.
