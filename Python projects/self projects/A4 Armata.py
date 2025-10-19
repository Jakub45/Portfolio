# dobra, jest armata. Zadać można 3 zmienne (kierunek [x,y], kąt nachylenia, i siłe wystrzału). Program musi umieć policzyć i podać w układzie kartezjańskim położenie kuli.
#  STAŁE (masa kuli [1kg], [ewentualnie jeszcze opór aerodynamiczny] ,)
# 
#  TASK 1: można podać dane takie jak siła wystrzału, kąt nachylenia - podać odległość w jakiej się znajduje kula
#  TASK 2: podać kierunek wystrzału, podać odległość w jakiej się znaduję kula oraz położenie w układzie kartezjańskim

# Python code to demonstrate the working of sin()
# importing "math" for mathematical operations 


import math 

g = 9.81
y = input (str("podaj kąt wystrzału kuli"))
sina = math.sin(math.radians(int(y)))
cosa = math.cos(math.radians(int(y)))
V = input (str("Podaj prędkość początkową kuli"))

m = V * 2
sin2a = 2 * float(sina) * float(cosa)
x = float(((float(V * 2) / float(g) )) * float(sin2a))

print (float(x))