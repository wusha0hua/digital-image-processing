import matplotlib.pyplot as plt
import numpy as np
pre=np.array([800,650,600,430,300,230,200,170,150,130,110,96,80,70,50,30])

plt.hist(pre,rwidth=2.0,density=True)
plt.show()