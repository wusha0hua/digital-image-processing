close all;
clear all;
clc;

raw_image=imread('/disk/doc/course/dip/term/sourceimage/lena.bmp');
tow_level_image=imadjust(raw_image,[0.1,0.9],[0,1]);

subplot(121);
imshow(raw_image);
title('raw image');

subplot(122);
imshow(two_level_image);
title('two level');
