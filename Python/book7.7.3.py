from PIL import Image

ascii_char = list('俺也一样')

def get_char(r, b, g, alpha=256):
    if alpha == 0:
        return ' '
    gray = int(0.2126 * r + 0.7152 * g + 0.0722 * b)
    unit = 256 / len(ascii_char)
    return ascii_char[int(gray // unit)]

def main():
    im = Image.open('D:\\Regan\\Photo\\headpic.png')
    WIDTH, HEIGHT = 100, 60
    im = im.resize((WIDTH, HEIGHT))
    txt = " "
    for i in range(HEIGHT):
        for j in range(WIDTH):
            txt += get_char(*im.getpixel((j, i)))
        txt += '\n'
    fo = open("pic_char.txt", "w")
    fo.write(txt)
    fo.close()

main()
print('童言', 2015301332, '软工')