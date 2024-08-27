import matplotlib.pyplot as plt
import numpy as np
import math
x=np.arange(16)
y=[800,650,600,430,300,230,200,170,150,130,110,96,80,70,50,30]

sum=0
for i in range(16):
    sum+=y[i]

p=[]
for i in range(16):
    p.append(y[i]/sum)


t=[]
for i in range(16):
    tmp=0
    for j in range(i+1):
        tmp+=p[j]
    t.append(tmp)

g=[]
for i in range(16):
    tmp=0
    g.append(math.floor(15*t[i]+0.5))

m=[0]*16
for i in range(16):
    for j in range(16):
        if(i==g[j]):
            m[i]+=p[j]

print(m)

s=0
for i in range(16):
    s+=m[i]

print(s)
print(p)
plt.subplot(2,1,1)
plt.bar(x,np.array(p))
plt.subplot(2,1,2)
plt.bar(x,np.array(m))

plt.show()
