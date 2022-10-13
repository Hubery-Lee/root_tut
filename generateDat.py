'''
Description: 
version: 
Author: Hubery-Lee
E-mail: hrbeulh@126.com
Date: 2022-10-13 23:43:17
LastEditTime: 2022-10-13 23:51:40
LastEditors: Hubery-Lee
'''
from ROOT import *
fw = open("data3.txt",'w')
for x in range(0,99):
    r = TRandom3()
    errorI=r.Uniform()*5
    y=0.2*x+errorI
    fw.write(str(x)+'\t'+str(y)+'\t'+str(errorI)+str(errorI)+'\n')
    
