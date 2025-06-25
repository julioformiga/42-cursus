import turtle


def draw_grid(width, height):
    t = turtle.Turtle()
    t.hideturtle()
    t.speed(0)
    t.pensize(1)

    half_width = width // 2
    half_height = height // 2

    unit_scale = 50

    for y in range(-6, 7, 1):
        y_pixel = y * unit_scale
        t.penup()
        t.goto(-half_width, y_pixel)

        if y == 0:
            t.pensize(3)
            t.pencolor("white")
        else:
            t.pensize(1)
            t.pencolor("gray")

        t.pendown()
        t.goto(half_width, y_pixel)

        if y != 0:
            t.penup()
            t.goto(-half_width + 15, y_pixel - 15)
            t.pencolor("white")
            t.write(str(y), font=("Arial", 8, "normal"))

    for x in range(-6, 7, 1):
        x_pixel = x * unit_scale
        t.penup()
        t.goto(x_pixel, -half_height)

        if x == 0:
            t.pensize(3)
            t.pencolor("white")
        else:
            t.pensize(1)
            t.pencolor("gray")

        t.pendown()
        t.goto(x_pixel, half_height)

        if x != 0:
            t.penup()
            t.goto(x_pixel - 10, -half_height + 15)
            t.pencolor("white")
            t.write(str(x), font=("Arial", 8, "normal"))

    t.penup()
    t.goto(5, 5)
    t.pencolor("white")
    t.write("(0,0)", font=("Arial", 8, "normal"))


def draw_triangle(vertices):
    t = turtle.Turtle()
    t.hideturtle()
    t.color("green")
    t.pensize(3)
    t.speed(0)

    unit_scale = 50

    t.penup()
    t.goto(vertices[0][0] * unit_scale, vertices[0][1] * unit_scale)
    t.pendown()
    for vertex in vertices[1:] + [vertices[0]]:
        t.goto(vertex[0] * unit_scale, vertex[1] * unit_scale)

    for vertex in vertices:
        t.penup()
        t.goto(vertex[0] * unit_scale, vertex[1] * unit_scale)
        t.pendown()
        t.dot(10, "green")


def draw_point(point, color="red"):
    t = turtle.Turtle()
    t.hideturtle()
    t.speed(0)
    t.penup()

    unit_scale = 50

    x_pixel = point[0] * unit_scale
    y_pixel = point[1] * unit_scale

    t.goto(x_pixel, y_pixel)
    t.pendown()
    t.dot(10, color)

    t.penup()
    t.goto(x_pixel + 10, y_pixel - 20)
    t.color("white")
    coord_text = f"({point[0]:.2f}, {point[1]:.2f})"
    t.write(coord_text, font=("Arial", 8, "normal"))


def main():
    screen = turtle.Screen()
    screen.title("Triângulo e Pontos")
    screen.bgcolor("black")
    screen.setup(800, 600)
    screen.tracer(0)

    draw_grid(800, 600)

    triangle_vertices = [(3.01172, 4), (1.30078, 2), (2, 5.19922)]

    draw_triangle(triangle_vertices)

    point_on_line = (
        (triangle_vertices[0][0] + triangle_vertices[1][0]) / 2,
        (triangle_vertices[0][1] + triangle_vertices[1][1]) / 2,
    )

    point_on_line = (1.64844, 3.60156)
    draw_point((2.2, 4), "blue")
    draw_point(point_on_line, "blue")
    draw_point((4, 2.2), "red")

    screen.listen()
    screen.onkey(turtle.bye, "Escape")
    screen.onkey(turtle.bye, "q")

    turtle.mainloop()


if __name__ == "__main__":
    main()
