import sys
import os
import numpy as np
import cv2 as cv
from PySide6.QtWidgets import *
from PySide6.QtCore import *
from PySide6.QtGui import *
from shutil import copyfile
from skimage import util

def fun():
    print('OK')

#global image_dir
#global image_open_path
#global image_size
#global button_size_width
#global button_size_height
#global image_left
#global image_right
#global menu_size_width
#global menu_size_height

label_image_left=None
label_image_right=None

path_image_left=None
path_image_right=None

image_size=512
button_size_width=80
button_size_height=50
menu_size_width=80
menu_size_height=50

method_n=0
sub_n=0

text_method=['gray level','noise','line detection','morphology']
text_gray=['2','4','8','16','32','64','128']
text_noise=['guassian','salt&pepper']
text_line_detection=['hough']
text_morphology=['uphat']

def Exit():
    for i in range(255):
        if(os.path.exists('./tmp'+str(i)+'.bmp')):
            os.remove('./tmp'+str(i)+'.bmp')
    exit()


def gray_level(img,level):
    image=np.zeros(img.shape,dtype=np.uint8)
    image+=255
    r=image.shape[0]
    c=image.shape[1]
    threshold_up=256//level
    threshold_low=0
    n=threshold_up
    while(threshold_up<256):
        for i in range(r):
            for j in range(c):
                if(threshold_low<=img[i][j]<threshold_up):
                    image[i][j]=threshold_low

        threshold_low=threshold_up
        threshold_up+=n

    return image


def InitImageLabel():
    global label_image_left
    global label_image_right

    label_image_left=QLabel(window)
    label_image_right=QLabel(window)

    label_image_left.resize(image_size,image_size)
    label_image_right.resize(image_size,image_size)

    label_image_left.move(50,50)
    label_image_right.move(638,50)

    label_image_left.setText('no image')
    label_image_right.setText('no image')

    label_image_left.setAlignment(Qt.AlignCenter)
    label_image_right.setAlignment(Qt.AlignCenter)

def InitButton():
    global button_save
    global button_open
    global button_start
    global button_exchange

    button_open=QPushButton('open',window)
    button_save=QPushButton('save',window)
    button_start=QPushButton('start',window)
    button_exchange=QPushButton('exchange',window)


    button_open.resize(button_size_width,button_size_height)
    button_save.resize(button_size_width,button_size_height)
    button_start.resize(button_size_width,button_size_height)
    button_exchange.resize(button_size_width-20,button_size_height)

    button_open.move(281,582)
    button_save.move(638+512//2-button_size_width//2,582)
    button_start.move(1000,582)
    button_exchange.move(600-(button_size_width-20)//2,50+512//2-button_size_height//2)


    button_open.clicked.connect(OpenImage)
    button_exchange.clicked.connect(ExchangeImage)
    button_save.clicked.connect(SaveImage)
    button_start.clicked.connect(GetParaments)

def InitMenu():
    global menu
    menu=QMenuBar(window)

    menu_file=menu.addMenu('file')
    menu_tool=menu.addMenu('tool')

    action_file_open=QAction('open',window)
    action_file_save=QAction('save',window)
    action_file_exit=QAction('exit',window)


    menu_file.addAction(action_file_open)
    menu_file.addAction(action_file_save)
    menu_file.addAction(action_file_exit)

    action_file_open.triggered.connect(OpenImage)
    action_file_save.triggered.connect(SaveImage)
    action_file_exit.triggered.connect(Exit)


def InitComboBox():
    global combox_method
    global combox_sub

    combox_method=QComboBox(window)
    combox_sub=QComboBox(window)

    combox_method.move(100,50+512+50+50)
    combox_sub.move(250,50+512+50+50)

    combox_method.addItems(text_method)

    combox_method.activated[int].connect(Method)
    combox_sub.activated[int].connect(Sub)


def InitLabel():
    global label_text

    label_text=QLabel(window)

    label_text.setAlignment(Qt.AlignCenter)


    label_text.move(300,50+512+50+50)
    
    label_text.resize(700,30)
    
def ShowText(text):
    label_text.setText(text)    


def GetParaments():
    global method_n
    global sub_n
    global label_image_right
    global path_image_right

    arg=[]

    if(method_n==0):
        ShowText('')
        image_np_left=cv.imread(path_image_left,0)
        image_np_right=gray_level(image_np_left,int(text_gray[sub_n]))
        image_np_right=cv.cvtColor(image_np_right,cv.COLOR_GRAY2RGB)
        i=0
        while(1):
            path='./tmp'+str(i)+'.bmp'
            if(not os.path.exists(path)):
                break
            i+=1
        cv.imwrite(path,image_np_right)
        path_image_right=path
        ShowRightImage(path)  

    elif(method_n==1):
        if(sub_n==0):
            mean,ok=QInputDialog.getText(window,'set mean','input mean:')
            if(ok):
                var,ok=QInputDialog.getText(window,'set var','input var')
                if(ok):
                    ShowText('mean:'+mean+' '+'var:'+var)

                    i=0
                    while(1):
                        path='./tmp'+str(i)+'.bmp'
                        if(not os.path.exists(path)):
                            break
                        i+=1
                    image_np_left=cv.imread(path_image_left)
                    image_np_right=util.random_noise(image_np_left,mode='gaussian',mean=float(mean),var=float(var))
                    #image_np_right=cv.cvtColor(image_np_right,cv.COLOR_GRAY2RGB)
                    image_np_right*=255
                    cv.imwrite(path,image_np_right)
                    path_image_right=path
                    ShowRightImage(path)




        if(sub_n==1):
            amount,ok=QInputDialog.getText(window,'set amount','input amount:')
            if(ok):
                salt_vs_pepper,ok=QInputDialog.getText(window,'set salt_vs_pepper','input salt_vs_pepper')
                if(ok):
                    ShowText('amount:'+amount+' '+'salt_vs_pepper:'+salt_vs_pepper)
                    i=0
                    while(1):
                        path='./tmp'+str(i)+'.bmp'
                        if(not os.path.exists(path)):
                            break
                        i+=1
                    image_np_left=cv.imread(path_image_left)
                    image_np_right=util.random_noise(image_np_left,mode='s&p',amount=float(amount),salt_vs_pepper=float(salt_vs_pepper))
                    #image_np_right=cv.cvtColor(image_np_right,cv.COLOR_GRAY2RGB)
                    image_np_right*=255
                    cv.imwrite(path,image_np_right)
                    path_image_right=path
                    ShowRightImage(path)


def ShowRightImage(path):
    global label_image_right
    label_image_right.clear()
    pixmap=QPixmap(path)
    label_image_right.setPixmap(pixmap)


    #if(method_n==1):
    #param,ok=QInputDialog.getText(window,'set paraments','input parament:')
    
    #if(ok):
    #    ShowText('param is :'+param)
    #    param=float(param)
    #    print(param)
    #    print(type(param))

    

def Method(n):
    global method_n
    method_n=n
    combox_sub.clear()
    if(method_n==0):
        combox_sub.addItems(text_gray)
    elif(method_n==1):
        combox_sub.addItems(text_noise)
    elif(method_n==2):
        combox_sub.addItems(text_line_detection)
    elif(method_n==3):
        combox_sub.addItems(text_morphology)
    sub_n=0

def Sub(n):
    global sub_n
    sub_n=n

def ReadImage():
    global path_image_left
    filedialog=QFileDialog(window)
    path_image_left=filedialog.getOpenFileName(window,'selcet a image file')[0]

def ShowImage(labelhandle,path):
    labelhandle.clear()
    pixmap=QPixmap(path)
    labelhandle.setPixmap(pixmap)

def OpenImage():
    global label_image_left
    global path_image_left
    ReadImage()
    ShowImage(label_image_left,path_image_left)

def ShowNoImage(handle):
    handle.setText('no image')
    handle.setAlignment(Qt.AlignCenter)


def ExchangeImage():
    global label_image_left 
    global label_image_right
    global path_image_left
    global path_image_right


    tmp_path=path_image_left
    path_image_left=path_image_right
    path_image_right=tmp_path
    


    if(path_image_left==None):
       ShowNoImage(label_image_left)
    else:
        ShowImage(label_image_left,path_image_left)
    
    if(path_image_right==None):
        ShowNoImage(label_image_right)
    else:
        ShowImage(label_image_right,path_image_right)

#def SelectDir():
#    dirdialog=QFileDialog(window)
#    path=dirdialog.getExistingDirectory(window,'selcet a image file')[0]
#    return path


def SaveImage():
    global label_image_left
    global label_image_right
    global path_image_left
    global path_image_right

    path=QFileDialog.getSaveFileName(window,'select')[0]

    copyfile(path_image_right,path)

if __name__ == '__main__':

    app=QApplication(sys.argv)
    window=QMainWindow()
    window.resize(1200,700)
    window.setWindowTitle('巫少华 2019081307020')

    InitImageLabel() 
    InitButton()
    InitMenu()
    InitComboBox()
    InitLabel()


    window.show()
    app.aboutToQuit.connect(Exit)
    app.exec_()
