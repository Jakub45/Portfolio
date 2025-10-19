### 1870362481026588102387632455801946557293 do analizy ###

import numpy as np

a = np.array( [ 1.3 , 2. , 5 , 2.7 , 9 ] )
# print( a )
b = np.array( [[ 3.2 , 2. , 6] , [ 4.7 , 6 , 8 ]] )
# print( b )

a.shape
# print(a.shape)
b.shape
# print(b.shape)
b.ndim
# print(b.ndim)
b.size
# print(b.size)
a.dtype
# print(a.dtype)

c= np.array([0.6, 4.98701, 8], dtype= 'float32' )
# print(c)

# print(np.zeros(( 3 , 6 )))
# print(np.eye( 5 ))
# print(np.full((3,7), 9))
# print(np.empty(( 8 ,8 )))

# Często będziemy potrzebowali wytworzyć tablicę (zazwyczaj jednowymiarową - wektor), posiadającą dokładnie 
# określoną ilość elementów z jakiegoś konkretnego przedziału. Przychodzą nam wtedy z pomocą dwie metody: 
# np.arange() i np.linspace(). Pierwsza działa podobnie jak pythonowe range() przyjmując start, stop i step, 
# i zwracając jednowymiarową tablicę liczb zdefiniowanych tymi parametrami.
# Nieznacznie inaczej działa np.linspace(), w której spośród trzech parametrach definiujemy również start i stop, 
# ostatni parametr jednak określa na ile równo oddalonych od siebie wartości wydzielić z przedziału [start, stop]. 
# Bardzo przydatna metoda przy generowaniu zbioru wartości potrzebnego do zbudowania wykresu.

# print(np.random.rand(3,3))
# print(np.random.randint(3,6,(9,9)))

print(nparray.shape(b))
