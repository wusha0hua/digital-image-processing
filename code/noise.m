
close all;
clear all;
clc;

raw_image=imread('/disk/repository/course/dip/term/sourceimage/jet.bmp');
guass_image=imnoise(raw_image,'gaussian',0,0.03);
saltpepper_image=imnoise(raw_image,'salt & pepper',0.3);
median_filter_guass_image=median_filter(guass_image,3);
median_filter_saltpepper_image=median_filter(saltpepper_image,3);

subplot(1,5,1);
imshow(raw_image);
title('image');

subplot(1,5,2);
imshow(guass_image);
title('guassian noise');

subplot(1,5,3);
imshow(saltpepper_image);
title('salt&pepper noise');

subplot(1,5,4);
imshow(median_filter_guass_image);
title('median filter for guassian');

subplot(1,5,5);
imshow(median_filter_saltpepper_image);
title('median filter for salt&pepper');