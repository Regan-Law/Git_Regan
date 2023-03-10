import turtle

def DrawTree(length, angle):
    if length > 15:
        turtle.left(angle)
        turtle.fd(length)
        DrawTree(length - 15, angle)
        turtle.backward(length)
        turtle.rt(2 * angle)
        turtle.fd(length)
        DrawTree(length - 15, angle)
        turtle.backward(length)
        turtle.left(angle)
def main():
    turtle.penup()
    turtle.goto(100, -200)
    turtle.pendown()
    turtle.pencolor('black')
    turtle.write('童言-2015301332', font=('宋体', 18, 'normal'))
    turtle.penup()
    turtle.goto(0, -250)
    turtle.pendown()
    turtle.pencolor('green')
    turtle.speed(0)
    turtle.left(90)
    turtle.pensize(2)
    turtle.fd(200)
    DrawTree(100, 25)
    turtle.hideturtle()
    turtle.exitonclick()
main()