import turtle
d=5
turtle.pendown()
turtle.pensize(2)
for i in range(24):
    turtle.seth(90)
    d+=5
    turtle.fd(d)
    turtle.seth(180)
    d+=5
    turtle.fd(d)
    turtle.seth(-90)
    d+=5
    turtle.fd(d)
    turtle.seth(0)
    d+=5
    turtle.fd(d)
turtle.seth(90)
d+=5
turtle.fd(d)
turtle.seth(180)
d+=5
turtle.fd(d)
turtle.seth(-90)
d+=5
turtle.fd(d)
turtle.seth(0)
turtle.exitonclick()
print('童言', 2015301332, '软工')