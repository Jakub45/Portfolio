# x = 0
# y = 1 + x
# z = 0
# while x < 100:
#     x += 1
#     z == ((2 * x) +1)
# print(z)

def fibonacci(n):
    a, b = 0, 1
    while a < n:
        print(a, end= ' ')
        a, b = b, a+b
    print()
fibonacci(100)

# elif y < 100:
#   y == x + 1
# elif x < 100:
#   x += 1
# while y < 1000:
#     y == x + 1
#     while z < 2000:
#         print(z)
#         z == x + y