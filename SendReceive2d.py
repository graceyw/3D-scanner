#!/usr/local/bin/python

from serial import Serial, SerialException
import numpy as np
#from vpython import *

# The Serial constructor will take a different first argument on 
# Windows. The first argument on Windows will likely be of the form
# 'COMX' where 'X' is a number like 3,4,5 etc.
# Eg.cxn = Serial('COM5', baudrate=9600
#
# NOTE: You won't be able to program your Arduino or run the Serial 
# Monitor while the Python script is running. 
#cxn = Serial('/dev/tty.usbmodem1411', baudrate=9600)
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
fig = plt.figure()
axes = fig.add_axes([0.1, 0.1, 0.8, 0.8]) # left, bottom, width, height (range 0 to 1)
cxn = Serial('/dev/tty.usbmodem1411', baudrate=9600)
coorz = []
coorx = []
coory = []
running = True

while running == True:
# try:
    cxn.write([1])

    result = str(cxn.readline())

    if result[2:-5] == 'done':
        running = False

    else:

        start_pos1 = result.index(';')
        start_pos2 = result.index('/')
        end_pos2 = result.index(':')

        r = int(result[2:start_pos1])
        theta = int(result[start_pos2+1:end_pos2])
        phi = int(result[start_pos1+1:start_pos2])
        #r = 174.2899905809008 - 1.649197414971477*r + 0.006345977472337600*r**2 - 0.000010695716821323956*r**3 + 6.53928759810862*10**(-9)*r**4 
        phi -= 30
        theta -= 30

        x = r*np.cos(theta)*np.sin(phi)
        y = r*np.sin(theta)*np.sin(phi)
        z = r*np.cos(phi)

        coorx.append(theta)
        coory.append(y)
        coorz.append(r)

        #print(x,y,z)
        print(r,theta,phi)


surf = axes.plot(coorx, coorz, 'r-')
plt.xlabel("theta")
plt.ylabel("r")
#plt.axis([-30,30,0,40])

plt.show()


