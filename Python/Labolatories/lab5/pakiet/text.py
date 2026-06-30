space = " "

def left(text):
    for i in range(0, len(text), 45):
        print(text[i:i+45])

def right(text):
    for m in range(0, len(text), 45):
        line = text[m:m+45]
        n = 90 - len(line)
        print(space * n + line)

def center(text):
    for z in range(0, len(text), 45):
        line = text[z:z+45]
        n = (90 - len(line)) // 2
        print(space * n + line)

if __name__ == "__main__":

    print('Moduł "text" definiuje funkcje center, left, right i służy do:\n')
    left("Wypisania tekstu wyrównanego do lewej,")
    right("do prawej,")
    center("lub wycentrowanego.")
    print("\nDodatkowo ten moduł zawiera:\n")
    print(dir())

def present():
    print('Moduł "text" definiuje funkcje center, left, right i służy do:\n')
    left("Wypisania tekstu wyrównanego do lewej,")
    right("do prawej,")
    center("lub wycentrowanego.")
