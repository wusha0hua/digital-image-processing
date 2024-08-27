<center><font size=10>数字图像处理</font></center>

<center>姓名：巫少华</center>

<center>学号：2019081307020</center>



1. 将图像的灰度级分辨率调整至 [128,64,32,16,8, 4, 2]

   

   ![](/disk/course/dip/pic/gray-2.png)

   <center>处理后灰度级为2的图像</center>

   

   ![](/disk/course/dip/pic/gray-4.png)

<center>处理后灰度级为4的图像</center>



![](/disk/course/dip/pic/gray-8.png)

<center>处理后灰度级为8的图像</center>



![](/disk/course/dip/pic/gray-16.png)

<center>处理后灰度级为16的图像</center>

![](/disk/course/dip/pic/gray-32.png)

<center>处理后灰度级为32的图像</center>

![](/disk/course/dip/pic/gray-64.png)

<center>处理后灰度级为64的图像</center>



![](/disk/course/dip/pic/gray-128.png)

<center>处理后灰度级为128的图像</center>











2. 往图像中叠加不同类型的噪声，并设计一个频域低通滤波器来去除之



![](/disk/course/dip/pic/guassion.png)

<center>向图像添加高斯噪声</center>

![](/disk/course/dip/pic/sp.png)

<center>向图像添加椒盐噪声</center>

![](/disk/course/dip/pic/filter.png)

<center>经过低通滤波后的图像</center>





3. 举例说明顶帽变换在图像阴影校正方面的应用。



![](/disk/course/dip/pic/tophat-b.png)

<center>原图像</center>

![](/disk/course/dip/pic/tophat-a.png)

<center>顶帽变换后的图像</center>



4. 利用 Hough 变换来检测图像中的直线，与变换过程相关的系列约束条
   件（线段的最小长度等）可自行叠加。

![](/disk/course/dip/pic/hough.png)

<center>直线检测</center>







5. 对图像执行阈值分割操作并统计出每一个区域块的属性，然后，将每个区域的中心和外接矩形给标注出来。

![](/disk/course/dip/pic/otsu.png)

<center>otsu算法进行阈值分割</center>







6. 设计一个简易的 Matlab GUI 界面程序，要求其具有如下的功能：

①打开与保存图像时均打开文件名设置对话框

②当下拉菜单中的条目被选中时，列表框之中实时的记录下当前的选择

③通过编辑框来实现相关参数的交互式输入

④将输入图像及处理后结果显示在相应的坐标轴之上

⑤含有工具栏和菜单栏，当选择其下的组件成分时，要有相应的图像处理行为发生

⑥将 figure 窗口的“Name”属性修改为自己的姓名和学号

⑦将所设计的 GUI 程序编译为“.exe”形式的可执行文件



![](/disk/course/dip/pic/gui-gui.png)

<center>打开gui</center>



![](/disk/course/dip/pic/gui-open.png)

<center>点击open，加载一张图像</center>



![](/disk/course/dip/pic/gui-gray.png)

<center>选择将图像变换成灰度级为2的图像，目标图像将在右边显示</center>



![](/disk/course/dip/pic/gui-mean.png)

<center>选择向图像添加高斯噪声，提示需要输入mean值</center>



![](/disk/course/dip/pic/gui-var.png)

<center>接下来输入var值</center>



![](/disk/course/dip/pic/gui-guassion.png)

<center>输入完成后在下方显示刚才输入的值，右边显示处理后的图像</center>