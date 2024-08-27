import cv2 as cv
import numpy as np
from skimage import util
from PIL import Image
import matplotlib.pyplot as plt

image=cv.imread('/disk/course/dip/term/sourceimage/lena.bmp')
noise_gaussian_image=util.random_noise(image,mode='gaussian')
noise_saltpepper_image=util.random_noise(image,mode='s&p')



cv.imshow('image',image);
cv.imshow('gauss noise image',noise_gaussian_image)
cv.imshow('salt pepper noise image',noise_saltpepper_image)

noise_gaussian_image*=256
cv.imwrite("guassian.bmp",noise_gaussian_image);

cv.waitKey(0)
