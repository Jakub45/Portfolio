x = (1,2,3,4,5,6,7,8,9,10)
print(x[2:9])

zmienna = "kOt"

print(len(zmienna)) 
print(zmienna.capitalize())
print(zmienna.upper())
print(zmienna.lower())
print(zmienna[1:2]) 

print(zmienna.startswith("k"))
print(zmienna.endswith("t"))
print(zmienna.rstrip("t"))
print(zmienna.lstrip("k"))
print(zmienna.strip("kit"))


zmienna2 = "3,141592 653589 793238 "
print(zmienna2.split(" "))
join_string = " "
print(join_string.join("3,141592 653589 793238 "))
print(join_string.join([zmienna, zmienna2]))
print(str(zmienna2).zfill(30))
