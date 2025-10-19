x = []

for y in range(200):
    x.append(y)


for z in x:
    if ((x[z] % 7) == 0 ):
        print ("true")
    else:
        print ("false")
