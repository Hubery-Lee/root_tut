'''
Date: 2024-05-15 15:24:46
LastEditors: lihui-wsl2-ubuntu22.04 hrbeulh@126.com
LastEditTime: 2024-05-15 16:07:19
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
