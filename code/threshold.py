import cv2 as cv
import numpy as np

img=cv.imread('/disk/repository/course/dip/term/sourceimage/lena.bmp')

cv.imshow('image',img)

cv.waitKey(0)
