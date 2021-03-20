import os
import cv2

if __name__ == '__main__':
    pics = os.listdir()
    print(pics)
    for pic in pics:
        if '.jpg' in pic:
            img = cv2.imread(pic)
            img = cv2.resize(img, (128, 128), interpolation=cv2.INTER_AREA)
            cv2.imwrite(pic, img)