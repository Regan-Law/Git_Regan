import turtle,datetime
SIZE=5
FD=40
LR=90
FONT_SIZE=18
def drawGap():
    turtle.penup()
    turtle.fd(FONT_SIZE)
def drawLine(draw):
    drawGap()
    turtle.pendown() if draw else turtle.penup()
    turtle.fd(FD)
    drawGap()
    turtle.right(LR)
def drawDigit(d):
    drawLine(True) if d in [2,3,4,5,6,8,9] else drawLine(False)
    drawLine(True) if d in [0,1,3,4,5,6,7,8,9] else drawLine(False)
    drawLine(True) if d in [0,2,3,5,6,8,9] else drawLine(False)
    drawLine(True) if d in [0,2,6,8] else drawLine(False)
    turtle.left(LR)
    drawLine(True) if d in [0,4,5,6,8,9] else drawLine(False)
    drawLine(True) if d in [0,2,3,5,6,7,8,9] else drawLine(False)
    drawLine(True) if d in [0,1,2,3,4,7,8,9] else drawLine(False)
    turtle.left(180)
    turtle.penup()
    turtle.fd(20)
def drawDate(date):
    turtle.pencolor("red")
    for i in date:
        if i=='-':
            turtle.write('年',font=("Arial",FONT_SIZE,"normal"))
            turtle.pencolor("green")
            turtle.fd(FD)
        elif i=='=':
            turtle.write('月',font=("Arial",FONT_SIZE,"normal"))
            turtle.pencolor("blue")
            turtle.fd(FD)
        elif i=='+':
            turtle.write('日',font=("Arial",FONT_SIZE,"normal"))
        else:
            drawDigit(eval(i))  
def main():
    turtle.setup(800,350,200,200)
    turtle.penup()
    turtle.fd(-350)
    turtle.pensize(FONT_SIZE)
    drawDate(datetime.datetime.now().strftime('%Y-%m=%d+'))
    turtle.hideturtle()
    turtle.exitonclick()
main()
print('童言', 2015301332, '软工')