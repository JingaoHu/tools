#!/usr/bin/python
import matplotlib.pyplot as plt
import time
import numpy
import random

X = range(0, 400)

Y = range(0, 400)
for i in X : 
	if i<50 or i>350 :
		Y[i]=random.randint(-3,3)
	else :
		Y[i]=random.randint(80,85)

Z = range(15)
for i in Z :
	Z[i]=random.randint(50,350)

for i in Z :
	Y[i]=random.randint(0,150)

Fig = plt.figure(figsize=(4,1))     # Create a `figure' instance
Ax = Fig.add_subplot(111)         # Create a `axes' instance in the figure
Ax.plot(X, Y,'o')                 # Create a Line2D instance in the axes
Fig.show()
wait=raw_input()
Fig.savefig("test.jpg")
