# import turtle
# import random
#
#
# turtle.colormode(255)
# turtle_1 = turtle.Turtle()
#
#
# def random_colour():
#     r = random.randint(0, 255)
#     g = random.randint(0, 255)
#     b = random.randint(0, 255)
#     random_color = (r, g, b)
#     return random_color
#
#
# turtle_1.speed(1000)
#
# for x in range(360):
#     turtle_1.pencolor(random_colour())
#     turtle_1.circle(100)
#     turtle_1.right(1)
#
# turtle.exitonclick()
#

import turtle
import random


turtle_1 = turtle.Turtle()
turtle.colormode(255)

# def random_colour():
#     r = random.randint(0, 255)
#     g = random.randint(0, 255)
#     b = random.randint(0, 255)
#     return r, g, b

direction = [90, 180, 270, 360]
colours = ['red', 'blue', 'yellow', 'green', 'black', 'red', 'blue', 'green']

is_on = True
while is_on:
    turtle_1.hideturtle()
    turtle_1.pensize(5)

    colour = random.choice(colours)
    turtle_1.pencolor(colour)


    random_direction = random.choice(direction)
    turtle_1.right(random_direction)

    turtle_1.forward(20)
    turtle_1.speed(2500)


# from turtle import Turtle
# import random
# turtle = Turtle()
#
# colours = ['red', 'blue', 'green', 'yellow', 'black', 'red', 'blue', 'green']
#
# for n in range(3, 20):
#     angle = 180 - (((n - 2) * 180)/n)
#     turtle.pencolor(random.choice(colours))
#     for k in range(n):
#         turtle.forward(120)
#         turtle.right(angle)
