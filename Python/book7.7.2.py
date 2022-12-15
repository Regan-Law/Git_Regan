from PIL import Image
import os
import math

picture = 'D:\\Regan\\Photo\\White rosetest.png'
image = Image.open(picture)
size = os.path.getsize(picture) / 1024
width, height = image.size
ima = 'D:\\Regan\\Photo\\test_compressed.png'
while True:
    if size > 10:
        width, height = round(width * 0.9), round(height * 0.9)
        image = image.resize((width, height), Image.ANTIALIAS)
        image.save(ima)
        size = os.path.getsize(ima) / 1024
    else:
        break

print('童言', 2015301332, '软工')