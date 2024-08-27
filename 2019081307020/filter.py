from PIL import Image
import numpy as np
import matplotlib.pyplot as plt
import cv2 as cv
from skimage import util


image=cv.imread('/disk/course/dip/term/sourceimage/lena.bmp')
noise_gaussian_image=util.random_noise(image,mode='gaussian')
noise_saltpepper_image=util.random_noise(image,mode='s&p')



cv.imshow('image',image);
cv.imshow('gauss noise image',noise_gaussian_image)
cv.imshow('salt pepper noise image',noise_saltpepper_image)





girl = r"guassian.bmp"

im = Image.open(girl).convert('L')
imarr = np.array(im)
height, width = imarr.shape

fft = np.fft.fft2(imarr)
fftshift = np.fft.fftshift(fft)

cutstop = 100

for i in range(height):
    for j in range(width):
        if (i - (height) / 2) ** 2 + (j - (width) / 2) ** 2 >= cutstop ** 2:
            fftshift[i, j] = 0

fftshift = np.fft.ifftshift(fftshift)
ifft = np.fft.ifft2(fftshift)

new = np.zeros((height, width))

for i in range(height):
    for j in range(width):
        new[i, j] = ifft[i, j].real

max = np.max(new)
min = np.min(new)
res = np.zeros((height, width), dtype="uint8")

for i in range(height):
    for j in range(width):
        res[i, j] = 255 * (new[i, j] - min) / (max - min)

res_im = Image.fromarray(res)
res_im.save("guassion-filter.bmp")

cv_img = cv.cvtColor(np.asarray(res_im),cv.COLOR_RGB2BGR)
cv.imshow('cv',cv_img)
cv.waitKey(0)
