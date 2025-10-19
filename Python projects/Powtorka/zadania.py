import random

class bank_account:
    def __init__(self):
        self.ID = self.ID_generator

    def ID_generator(self):
        symbols = [1,2,3,4,5,6,7,8,9,0,'Z','A','Q','W','S','X','C','D','E','R','F','V','B','G','T','Y','H','N','M','J','U','I','K','L','O','P']
        self.ID = random.randint(0, 1000)
        return ''.join(random.choice(symbols) for _ in range(10))

user1 = bank_account()

user1.ID_generator()

print(f"{user1.ID}")

