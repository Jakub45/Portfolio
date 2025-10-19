# FUNKCJA LINIOWA
# import matplotlib.pyplot as plt

# a = input("zmienna a : ")
# b = input("zmienna b : ")

# x =range(-10,10)
# y = []
# for i in x:
#     y.append((int(a) * int(a) ) * i + int(b))

# plt.plot(x,y)
# plt.grid(True)
# plt.show()
# FUNKCJA LINIOWA





# WYRAZENIE LISTOWE 
# c = 5

# x = range(11)
# for z in x:
#     print(c + z)

# y = [c + z for z in range (11)]
# print(y)
# WYRAZENIE LISTOWE





# FUNCKCJA Z EKSTREMUM (PODWOJNA)
# import matplotlib.pyplot as plt
# import numpy as np
# a = input("podaj zmienna a:")

# x = np.arange(-10, 11, 0.5)

# if all(x < 0 ):
#     y = x / (-3) + int(a)
# else:
#     y = (x * x) / int(a)

# plt.plot(x,y)
# plt.show()
# FUNKCJA Z EKSTREMUM (PODWOJNA)





# #  FUNCKJA ZMIENNOPRZECINKOWA
# import matplotlib.pyplot as plt
# import numpy as np

# x = np.arange(-10, 10.5, 0.5)
# a = input("podaj zmienna a")

# if all(x < 0):
#     y = x / (-3) + int(a)
# else:
#     y = ( x * x ) / 3

# # plt.plot(x[:len(y)], y)
# plt.plot( x, y )
# plt.title( "Misiowe wykresy liniowe" )
# plt.grid( True )
# plt.show (  )
# #  FUNCKJA ZMIENNOPRZECINKOWA





# RUCHY BROWNA 
import math
import matplotlib.pyplot as plt
import random


x0 = [0]
y0 = [0]
n = int(input("podaj ilosc ruchow do wykonania"))
x = 0
y = 0

for b in range (0, n):
    rad = float(random.randint( 0, 360 )) * math.pi / 180
    sina = math.sin( rad )
    cosa = math.cos( rad )
    x = x + sina
    y = y + cosa
    x0.append(x)
    y0.append(y)
    # print (x, y)


plt.plot ( x0,y0, "o:", color = "blue", linewidth=2, alpha=0.5)
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Misiowe ruchy Browna")
plt.grid(True)
plt.show()


# RUCHY BROWNA