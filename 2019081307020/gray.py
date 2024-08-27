import cv2 as cv
import numpy as np

def gray_level(img,level):
    image=np.zeros(img.shape,dtype=np.uint8)
    image+=255
    r=image.shape[0]
    c=image.shape[1]

    threshold_up=256//level
    threshold_low=0
    n=threshold_up

    while(threshold_up<256):
        for i in range(r):
            for j in range(c):
                if(threshold_low<=img[i][j]<threshold_up):
                    image[i][j]=threshold_low

        threshold_low=threshold_up
        threshold_up+=n

    return image

image=cv.imread('/disk/course/dip/term/sourceimage/lena.bmp',0)
sp=image.shape

image2=gray_level(image,2)
image4=gray_level(image,4)
image8=gray_level(image,8)
image16=gray_level(image,16)
image32=gray_level(image,32)
image64=gray_level(image,64)
image128=gray_level(image,128)


cv.imshow('image',image)
cv.imshow('2',image2)
cv.imshow('4',image4)
cv.imshow('8',image8)
cv.imshow('16',image16)
cv.imshow('32',image32)
cv.imshow('64',image64)
cv.imshow('128',image128)

cv.waitKey(0)
