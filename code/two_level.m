I = imread('/disk/doc/course/dip/term/sourceimage/lena.bmp');
[m,n]=size(I);J=zeros(m,n);
for i=1:m    
    for j=1:n        
        J(i,j)=floor(I(i,j)/32);    
    end
end
K=uint8(J);
subplot(131);
imshow(I);

subplot(132);
imshow(K);
