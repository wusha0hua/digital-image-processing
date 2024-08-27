import numpy as np
import cv2 as cv

img=cv.imread('/disk/course/dip/term/sourceimage/bank.bmp')

gray=cv.cvtColor(img,cv.COLOR_BGR2GRAY)
print(gray)

edges=cv.Canny(gray,50,200,apertureSize=3)

#lines=cv.HoughLines(edges,rho=1,theta=12*np.pi/180,threshold=120,srn=0,stn=0,min_theta=1,max_theta=2)
lines=cv.HoughLines(edges,1,np.pi/180,120)

print(lines)

for i in range(0,len(lines)):
    rho,theta=lines[i][0][0],lines[i][0][1]
    a=np.cos(theta)
    b=np.sin(theta)
    x0=a*rho
    y0=b*rho
    x1=int(x0+1000*(-b))
    y1=int(y0+1000*a)
    x2=int(x0-1000*(-b))
    y2=int(y0-1000*a)
    cv.line(img,(x1,y1),(x2,y2),(0,0,255),2)

cv.imshow('image',img)

cv.waitKey(0)
