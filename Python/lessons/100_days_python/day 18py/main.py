import turtle


color_list = [(245, 243, 239), (247, 242, 244), (204, 164, 107), (151, 73, 47), (239, 245, 240), (235, 237, 243),
              (52, 93, 124), (223, 201, 136), (169, 153, 41), (136, 32, 22), (132, 162, 185), (201, 91, 70),
              (48, 122, 88), (67, 47, 41), (14, 100, 73), (147, 178, 146), (162, 142, 157), (234, 175, 165),
              (111, 74, 77), (18, 85, 89), (183, 205, 172), (55, 45, 48), (154, 16, 20), (39, 61, 74), (49, 65, 79),
              (83, 146, 128), (178, 89, 93), (179, 191, 207), (110, 127, 150), (215, 177, 182), (215, 177, 182)]

turtle.colormode(255)
the_turtle = turtle.Turtle()

the_turtle.pensize(30)
the_turtle.hideturtle()
the_turtle.speed(10000)
x_dimension = 0
y_dimension = 0
color_number = 0

for a in range(5):
    y_dimension += 40
    the_turtle.penup()
    the_turtle.setx(x_dimension)
    the_turtle.sety(y_dimension)
    the_turtle.pendown()
    for b in range(6):
        color_number += 1
        the_turtle.pencolor(color_list[color_number])
        the_turtle.forward(0)
        the_turtle.penup()
        the_turtle.forward(40)
        the_turtle.pendown()

turtle.exitonclick()
