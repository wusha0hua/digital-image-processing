import matplotlib.pyplot as plt
import numpy as np

#y=3/4x (0<=x<=120)
#y=4/3x (120<=x<=200)

x1=np.arange(0,120,0.1)
x2=np.arange(120,240,0.1)

y1=2/3*x1
y2=x2-40

plt.plot(x1,y1)
plt.plot(x2,y2)

plt.show()
