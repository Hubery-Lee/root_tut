'''
Date: 2024-05-15 15:24:46
LastEditors: lihui-wsl2-ubuntu22.04 hrbeulh@126.com
LastEditTime: 2024-05-16 09:24:40
FilePath: /rootWS/rootDraw.py
Description: Do not edit
'''
#! 重点专注RDataFrame
# https://root-forum.cern.ch/t/problem-installing-root-numpy/53625
# The root_numpy and root_pandas packages are not part of ROOT, and they are both deprecated and unmaintained:

# GitHub - scikit-hep/root_numpy: The interface between ROOT and NumPy 2
# GitHub - scikit-hep/root_pandas: A Python module for conveniently loading/saving ROOT files as pandas DataFrames
# Please don’t use them, it’s probably very difficult to get them to compile now.

# If you want to get NumPy arrays out of ROOT files, you should better use directly. You can open the files with RDataFrame 4 and then use AsNumpy() 
# 4 to get your arrays. Alternatively, you can also do your analysis completely in RDataFrame to begin with, or if you don’t want to use ROOT you can
# install the uproot 4 python package that succeeded root_numpy.

# 将ROOT文件转换成python numpy，建议使用
# open the files with RDataFrame 4 and then use AsNumpy() 4 to get your arrays.
# 如何不想使用ROOT
# don’t want to use ROOT you can install the uproot 4 python package that succeeded root_numpy.

# %%
import pythonStyle
import ROOT
import numpy as np
import matplotlib.pyplot as plt

# bin info
# 自定义的 bin 边界数组
xAxis = np.array([
    1.00E-09, 2.15E-09, 4.64E-09, 1.00E-08, 2.15E-08, 4.64E-08, 1.00E-07,
    2.15E-07, 4.64E-07, 1.00E-06, 2.15E-06, 4.64E-06, 1.00E-05, 2.15E-05,
    4.64E-05, 1.00E-04, 2.15E-04, 4.64E-04, 1.00E-03, 2.15E-03, 4.64E-03,
    1.00E-02, 1.26E-02, 1.58E-02, 2.00E-02, 2.51E-02, 3.16E-02, 3.98E-02,
    5.01E-02, 6.31E-02, 7.94E-02, 1.00E-01, 1.26E-01, 1.58E-01, 2.00E-01,
    2.51E-01, 3.16E-01, 3.98E-01, 5.01E-01, 6.31E-01, 7.94E-01, 1.00E+00,
    1.26E+00, 1.58E+00, 2.00E+00, 2.51E+00, 3.16E+00, 3.98E+00, 5.01E+00,
    6.31E+00, 7.94E+00, 1.00E+01, 1.58E+01, 2.51E+01, 3.98E+01, 6.31E+01,
    1.00E+02
])

num = len(xAxis)-1
# 创建数据框
df = ROOT.RDataFrame("Det", "./Moutput_ReactorHall_Graphite/Moderator_5_Radius_25.root")
# 过滤数据并生成直方图
hist = df.Filter("Ekin > 0").Histo1D(("hist", "Kinetic Energy;Ekin (MeV);Counts", num, xAxis),"Ekin")

# 绘制直方图
c = ROOT.TCanvas()
# c = pythonStyle.set_elsevier_canvas()
c.SetLogx()
hist.Draw()

# %% 转换成numpy,采用matplotlib绘图
#
ekin = df.Filter("Ekin > 0").AsNumpy(["Ekin"])["Ekin"]

# 使用 matplotlib 绘制直方图
fig, ax = plt.subplots(figsize=(8, 6))
ax.hist(ekin, bins=xAxis,log=True,fill=False,histtype='step')
ax.set_xlabel('Kinetic Energy (MeV)')
ax.set_ylabel('Density')
ax.set_title('Histogram of Kinetic Energy')
ax.set_xscale('log')
plt.show()
# %%  列的操作与运算
# 将Ekin列数据与PosX列数据相加，生成新的列ekin_posx

hist2 = df.Define("ekin_posx","Ekin+PosX").Filter("ekin_posx > 0").Histo1D(("hist2", "ekin_posx;Ekin (MeV);Counts", num, xAxis),"ekin_posx")
# 绘制直方图
c = ROOT.TCanvas()
# c = pythonStyle.set_elsevier_canvas()
c.SetLogx()
hist2.Draw()