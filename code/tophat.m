close all;
clear all;
clc;

raw_image=imread('/disk/doc/course/dip/term/sourceimage/rice.bmp');

se = strel('rectangle',[3 3]);
top_hat_image = imtophat(raw_image, se); 

subplot(121);
imshow(raw_image);

subplot(122);
imshow(top_hat_image,[]);