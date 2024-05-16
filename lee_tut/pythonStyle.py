'''
Date: 2024-05-15 22:51:28
LastEditors: lihui-wsl2-ubuntu22.04 hrbeulh@126.com
LastEditTime: 2024-05-16 10:12:17
FilePath: /rootWS/pythonStyle.py
Description: Do not edit
'''
import ROOT
from ROOT import gROOT, gStyle, TCanvas, TStyle
from array import array
import ctypes

def set_elsevier_canvas(name="c1", cW=800, cH=600, default_style="Plain", font=132):
    """_summary_

    Args:
        name (str, optional): _description_. Defaults to "c1".
        cW (int, optional): _description_. Defaults to 800.
        cH (int, optional): _description_. Defaults to 600.
        default_style (str, optional): _description_. Defaults to "Plain".
        font (int, optional): _description_. Defaults to 132.

    Returns:
        _type_: _description_
    """
    gROOT.SetStyle(default_style)
    
    # 创建一个默认的样式
    myStyle = TStyle("MyStyle", "Elsevier Journal Plot Style")
    myStyle.SetFrameBorderMode(0)
    myStyle.SetCanvasBorderMode(0)
    myStyle.SetPadBorderMode(0)
    myStyle.SetPadColor(0)
    myStyle.SetCanvasColor(0)
    myStyle.SetTitleColor(1)
    myStyle.SetStatColor(0)

    # 设置字体
    myStyle.SetTitleFont(font, "X")
    myStyle.SetTitleFont(font, "Y")
    myStyle.SetTitleFont(font, "Z")
    myStyle.SetTitleFont(font, "title")
    myStyle.SetLabelFont(font, "X")
    myStyle.SetLabelFont(font, "Y")
    myStyle.SetLabelFont(font, "Z")
    myStyle.SetTextFont(font)

    # 设置标题对齐方式为居中
    myStyle.SetTitleX(0.5) #X title位于画板区域中心
    myStyle.SetTitleY(0.5) #Y title位于画板区域中心
    myStyle.SetTitleAlign(23) # 23 表示标题在水平和垂直方向上都居中

    # 设置标题和标签大小
    myStyle.SetTitleSize(0.05, "X")
    myStyle.SetTitleSize(0.05, "Y")
    myStyle.SetLabelSize(0.04, "X")
    myStyle.SetLabelSize(0.04, "Y")

    # 设置标签和标题偏移量
    myStyle.SetLabelOffset(0.02, "X")
    myStyle.SetLabelOffset(0.02, "Y")
    myStyle.SetTitleOffset(1.2, "X")
    myStyle.SetTitleOffset(1.2, "Y")

    # 设置统计框
    myStyle.SetOptStat(1110)
    myStyle.SetStatFont(font)
    myStyle.SetStatColor(10)
    myStyle.SetCanvasColor(10)
    myStyle.SetTitleColor(10, "title")
    myStyle.SetFillColor(10)
    myStyle.SetStatX(0.99) # 设置统计框在 X 轴上的位置为画布的右边缘。
    myStyle.SetStatY(0.99) # 设置统计框在 Y 轴上的位置为画布的顶边缘。

    # 设置标题显示选项
    myStyle.SetOptTitle(1)

    # 设置右侧和上侧ticks的是否显示
    myStyle.SetPadTickX(0)
    myStyle.SetPadTickY(0)

    # 切入当前style
    myStyle.cd()

    # 应用样式
    gROOT.SetStyle("MyStyle")
    gROOT.ForceStyle()

    # 设置边距的大小（单位：画布宽度或高度的比例）
    left_margin = 0.15
    right_margin = 0.05
    bottom_margin = 0.15
    top_margin = 0.05

    # 创建一个画布，并设置纸张大小和边距大小
    canvas = TCanvas(name, "", cW, cH)
    canvas.SetMargin(left_margin, right_margin, bottom_margin, top_margin)

    return canvas


def DrawMultiGraph(graphs, titleXY, legends):
    """_summary_

    Args:
        graphs (_type_): _description_
        titleXY (_type_): _description_
        legends (_type_): _description_
    """
    if len(graphs) != len(legends):
        print("The number of legends does not match the number of graphs!")
        return

    # Create canvas
    canvas = ROOT.TCanvas()
    # canvas.SetLogx()  # Set x-axis to logarithmic scale if needed

    # Create legend
    legend = ROOT.TLegend(0.6, 0.6, 0.88, 0.88)
    legend.SetFillStyle(0)
    legend.SetBorderSize(0)

    # Create TMultiGraph object
    multiGraph = ROOT.TMultiGraph()
    multiGraph.SetTitle(titleXY)

    # Loop through the graphs and add them to the TMultiGraph
    for i, graph in enumerate(graphs):
        # Set graph attributes
        color = 50 - 5 * ((i + 1) % 10)
        graph.SetLineColor(color)
        graph.SetMarkerColor(color)
        graph.SetMarkerStyle(20 + i)
        graph.SetLineWidth(2)
        # Add graph to TMultiGraph
        multiGraph.Add(graph)
        # Add entry to legend
        legend.AddEntry(graph, legends[i], "lp")

    # Draw the TMultiGraph
    multiGraph.Draw("ALP")

    # Set title offsets
    multiGraph.GetXaxis().SetTitleOffset(1.2)
    multiGraph.GetYaxis().SetTitleOffset(1.2)

    # Draw the legend
    legend.Draw()

    # Update the canvas
    canvas.Update()
    # Keep the GUI open if running interactively
    input("Press Enter to continue...")

def TGraph2D_to_TH2D(graph3d, hist2d):
    """_summary_

    Args:
        graph3d (_type_): _description_
        hist2d (_type_): _description_
    """
    nbinsX = hist2d.GetNbinsX()
    nbinsY = hist2d.GetNbinsY()

    # Iterate over all points in TGraph2D
    for i in range(graph3d.GetN()):
        x = ctypes.c_double()
        y = ctypes.c_double()
        z = ctypes.c_double()
        graph3d.GetPoint(i, x, y, z)

        # Determine the bins corresponding to x and y
        binX = hist2d.GetXaxis().FindBin(x)
        binY = hist2d.GetYaxis().FindBin(y)

        # Fill the corresponding bin with the z value
        hist2d.SetBinContent(binX, binY, z)

def TH2D_to_TGraph2D(hist2d, graph3d):
    """_summary_

    Args:
        hist2d (_type_): _description_
        graph3d (_type_): _description_
    """
    nbinsX = hist2d.GetNbinsX()
    nbinsY = hist2d.GetNbinsY()

    # Iterate over all bins in the 2D histogram
    for ix in range(1, nbinsX + 1):
        for iy in range(1, nbinsY + 1):
            x = hist2d.GetXaxis().GetBinCenter(ix)
            y = hist2d.GetYaxis().GetBinCenter(iy)
            z = hist2d.GetBinContent(ix, iy)
            graph3d.SetPoint(graph3d.GetN(), x, y, z)

def setLegendColumns(legend, numColumns):
    """
    @brief Set the number of columns in the legend
    @param legend The legend object
    @param numColumns The number of columns
    """
    legend.SetNColumns(numColumns)

def autoLegend(canvas=None):
    """
    @brief Automatically build a legend
    @param canvas The canvas object (optional)
    """
    if canvas:
        canvas.BuildLegend()
        canvas.Modified()
        canvas.Update()
    else:
        ROOT.gPad.BuildLegend()
        ROOT.gPad.Modified()
        ROOT.gPad.Update()


# 使用示例
def my_plot():
    canvas = set_elsevier_canvas("myCanvas", 800, 600)
    # 绘图代码，例如：
    h1 = ROOT.TH1F("h1", "Example Histogram", 100, -3, 3)
    h1.FillRandom("gaus", 1000)
    h1.Draw()
    # canvas.SaveAs("example_plot.png")
    # Keep the GUI open if running interactively
    input("Press Enter to continue...")
    
def mult_grap():
    # Create some example TGraphs
    x = [1, 2, 3, 4, 5]
    y1 = [1, 4, 9, 16, 25]
    y2 = [1, 8, 27, 64, 125]

    graph1 = ROOT.TGraph(len(x), array('d', x), array('d', y1))
    graph2 = ROOT.TGraph(len(x), array('d', x), array('d', y2))

    graphs = [graph1, graph2]
    titleXY = "Example MultiGraph;X axis title;Y axis title"
    legends = ["Graph 1", "Graph 2"]

    DrawMultiGraph(graphs, titleXY, legends)
    
def grap2d():
     # Create example TGraph2D
    graph3d = ROOT.TGraph2D()
    graph3d.SetPoint(0, 1, 1, 10)
    graph3d.SetPoint(1, 2, 2, 20)
    graph3d.SetPoint(2, 3, 3, 30)

    # Create an empty TH2D
    hist2d = ROOT.TH2D("hist2d", "Histogram", 10, 0, 5, 10, 0, 5)

    # Convert TGraph2D to TH2D
    TGraph2D_to_TH2D(graph3d, hist2d)
    hist2d.Draw("COLZ")
    ROOT.gPad.Update()

    # Create an empty TGraph2D
    new_graph3d = ROOT.TGraph2D()

    # Convert TH2D back to TGraph2D
    TH2D_to_TGraph2D(hist2d, new_graph3d)
    new_graph3d.SetMarkerStyle(20)
    new_graph3d.Draw("CONT4")
    ROOT.gPad.Update()
    # Keep the GUI open if running interactively
    input("Press Enter to continue...")

def alegend():
    # Create a canvas
    canvas = ROOT.TCanvas("canvas", "Canvas", 800, 600)

    # Create some example graphs
    x = [1, 2, 3, 4, 5]
    y1 = [1, 4, 9, 16, 25]
    y2 = [1, 8, 27, 64, 125]

    graph1 = ROOT.TGraph(len(x), array('d', x), array('d', y1))
    graph2 = ROOT.TGraph(len(x), array('d', x), array('d', y2))

    graph1.SetLineColor(ROOT.kRed)
    graph2.SetLineColor(ROOT.kBlue)

    graph1.SetTitle("Graph 1")
    graph2.SetTitle("Graph 2")

    graph1.Draw("ALP")
    graph2.Draw("LP SAME")

    # Create and customize legend
    legend = ROOT.TLegend(0.1, 0.7, 0.3, 0.9)
    legend.AddEntry(graph1, "Graph 1", "lp")
    legend.AddEntry(graph2, "Graph 2", "lp")
    setLegendColumns(legend, 2)  # Set number of columns in legend
    legend.Draw()

    # Use the autoLegend function
    autoLegend(canvas)
    # Keep the GUI open if running interactively
    input("Press Enter to continue...")

if __name__ == "__main__":
    # my_plot()
    # mult_grap()
    # grap2d()
    alegend()
    

