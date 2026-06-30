def fib_rec(n):
    if n <= 1:
        return n
    return fib_rec(n - 1) + fib_rec(n - 2)

def fib_iter(number):
    actual = 0
    next1 = 1
    temp = 0
    for i in range(number):
        temp = next1
        next1 = actual + next1
        actual = temp
    return actual

print(fib_rec(10))
print(fib_iter(10))