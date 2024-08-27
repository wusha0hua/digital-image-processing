import numpy as np
import cv2 as cv

image=cv.imread('/disk/course/dip/term/sourceimage/rice.bmp',0)

kernel=np.ones((10,10),np.uint8)

#open_image=cv.morphologyEx(image,cv.MORPH_OPEN,kernel)

tophat_image=cv.morphologyEx(image,cv.MORPH_TOPHAT,kernel)

cv.imshow('image',image)
#cv.imshow('open image',open_image)
cv.imshow('top hat image',tophat_image)


cv.waitKey(0)
