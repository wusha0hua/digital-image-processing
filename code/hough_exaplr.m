close all;
clear all;
clc;

%raw_image=imread('/disk/repository/course/dip/term/sourceimage/bank.bmp');

I=imread('/disk/repository/course/dip/term/sourceimage/bank.bmp');
rotI=imrotate(I,33,'crop');
fh(1)=figure('NumberTitle','off','MenuBar','none','Name','raw image');
ah(1)=axes('Parent',fh(1));
imshow(rotI,'Parent',ah(1),'DisplayRange',[]);
BW=edge(rotI,'canny');

fh(2)=figure('NumberTitle','off','MenuBar','none','Name','edge image');
ah(2)=axes('Parent',fh(2));
imshow(BW,'Parent',ah(2),'DisplayRange',[]);

[H,theta,rho]=hough(BW);

fh(3)=figure('NumberTitle','off','MenuBar','none','Name','hough image');
ah(3)=axes('Parent',fh(3));
imshow(imadjust(mat2gray(H)),'Parent',ah(3),'DisplayRange',[],'XData',theta,'YData',rho,'InitialMagnification','fit');
xlabel('\theta (degrees)');
ylabel('\rho');

axis(ah(3),'on');
axis(ah(3),'normal');
hold(ah(3),'on');
colormap(ah(3),'jet');

P=houghpeaks(H,5,'threshold',ceil(0.3*max(H(:))));
x=theta(P(:,2));
y=rho(P(:,1));

plot(x,y,'s','color','black');

lines=houghlines(BW,theta,rho,P,'FillGap',5,'MinLength',7);

fh(4)=figure('NumberTitle','off','MenuBar','none','Name','lines image');
ah(4)=axes('Parent',fh(4));
imshow(rotI,'Parent',ah(4),'DisplayRange',[]);

hold(ah(4),'on');
max_len=0;

for k=1:length(lines)
   xy=[lines(k).point1;lines(k).point2];
   plot(xy(:,1),xy(:,2),'LineWidth',2,'Color','green');
   
   plot(xy(1,1),xy(1,2),'x','LineWidth',2,'Color','yellow');
   plot(xy(2,1),xy(2,2),'x','LineWidth',2,'Color','red');
   
   len=norm(line(k).point1-lines(k).point2);
   if(len>max_len)
      max_len=len;
      xy_long=xy;
   end
   plot(xy(:,1),xy(:,2),'LineWidth',2,'Color','red');
end

%plot(xy_long(:,1),xy_long(:,2),'LineWidth',2,'Color','red');