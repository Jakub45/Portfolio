
waga = input(str("podaj swoją wagę, podaj tylko liczbę "))
if float(waga) > 200 or float(waga) < 25:
    print("podane złe dane")
    waga = input(str("podaj swoją wagę, dokłądnie, przykład - 76 "))
else:
    wzrost = input(str("podaj swój wzrost (w metrach) "))
    if float(wzrost) > 2.50 or float(wzrost) < 1.0:
        print("podane złe dane")
        wzrost = input(str("podaj swój wzrost (w metrach), dokładnie, przykład - 1.60"))


k = float(wzrost) * float(wzrost)
b = float(waga) / float(k)


if round(b) <= 18:
    print("Niedowaga, wskaźnik BMI = ")
    print(round(b))
elif round(b) > 18 and round(b) <= 24:
    print("Git wszystko w normie, wskaźnik BMI = ")
    print(round(b))
elif round(b) > 24 and round(b) <= 29:
    print("Nadwaga, wskaźnik BMI = ")
    print(round(b))
elif round(b) > 29 and round(b) <= 39:
    print("Otyłość, Wskaźnik BMI = ")
    print(round(b))
elif round(b) >= 40:
    print("https://www.youtube.com/watch?v=KPhqU--Mq1A")
    print(round(b))
else: print("something goes wrong")

print("oczywiście wskaźnik BMI jest dla osób dorosłych, więc jeśli nie jesteś dorosły, nie przywiązuj do tego dużej wagi 🙂")
