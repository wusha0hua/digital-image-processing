import cv2 as cv
import numpy as np

path='/disk/course/dip/term/sourceimage/rice.bmp'

image=cv.imread(path,0)

ret,otsu=cv.threshold(image,0,255,cv.THRESH_OTSU)
contours,ret=cv.findContours(otsu,cv.RETR_TREE,cv.CHAIN_APPROX_SIMPLE)

otsu_out=cv.cvtColor(otsu,cv.COLOR_GRAY2RGB)
for cont in contours:

    M = cv.moments(cont)
    cX = int(M["m10"] / M["m00"])
    cY = int(M["m01"] / M["m00"])
   
    cv.circle(otsu_out, (cX, cY), 3, (0, 255, 0), -1)

    rect=cv.minAreaRect(cont)
    box=cv.boxPoints(rect)
    startidx=box.sum(axis=1).argmin()
    box=np.roll(box,4-startidx,0)
    box=box.reshape((-1,1,2)).astype(np.int32)
    cv.polylines(otsu_out,[box],True,(0,0,255),1)

cv.imshow('image',image)
cv.imshow('otsu',otsu)
cv.imshow('otsu_out',otsu_out)
cv.waitKey(0)
