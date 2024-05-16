/*
 * @Description: This file contains functions related to styling and plotting in ROOT.
 * @version: 1.0
 * @Author: Hubery-Lee
 * @E-mail: hrbeulh@126.com
 * @Date: 2023-12-08 21:52:09
 * @LastEditTime: 2024-05-16 10:04:02
 * @LastEditors: lihui-wsl2-ubuntu22.04 hrbeulh@126.com
 */
// python 版可参考 atlas-plots python package
// example 可参考 https://atlas-plots.readthedocs.io/en/latest/examples.html

#include <TLine.h>
#include <TLatex.h>
#include <TColor.h>
#include <TString.h>
#include <TPaveStats.h>
#include <TH1.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TH3F.h>
#include <TLegend.h>
#include <THStack.h>
#include <TList.h>
#include <TStyle.h>
#include <TROOT.h>
#include <TVector3.h>
#include <vector>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TCanvas.h>
#include <TParticle.h>
#include <TGraphErrors.h>
#include <TPad.h>
#include <vector>
#include <TImage.h>
#include <TF1.h>
#include <TCutG.h>
#include <RooDataSet.h>
#include <TMath.h>
#include <TRandom3.h>
#include <TTreeReader.h>
#include <TGraph2D.h>
#include <TMultiGraph.h>

// 在ROOT中，`Draw` 函数可以与多种选项一起使用，以便定制绘图的方式。以下是一些常见的选项：

// 1. **"SAME"**: 将新的图形叠加在已有的图形之上，而不清除之前的图形。
// 2. **"HIST"**: 绘制直方图。
// 3. **"COL"**: 绘制彩色图形。
// 4. **"CONT"**: 绘制等高线图。
// 5. **"P"**: 绘制点。
// 6. **"L"**: 绘制线条。
// 7. **"C"**: 绘制轮廓线（仅在 `TGraph` 中有效）。
// 8. **"PL"**: 绘制点和连接线。
// 9. **"BOX"**: 绘制箱子（仅在 `TH3` 中有效）。
// 10. **"SURF"**: 绘制表面。
// 11. **"ARR"**: 绘制箭头（仅在 `TVector` 中有效）。
// 12. **"ARRS"**: 绘制矢量的箭头（仅在 `TVector` 中有效）。
// 13. **"AXIS"**: 绘制轴线（仅在 `TGraph2D` 中有效）。
// 14. **"B"**: 画条形图。
// 15. **"BAR"**: 绘制条形图。
// 16. **"FUNC"**: 绘制函数。
// 17. **"CYL"**: 绘制圆柱体。
// 18. **"PSR"**: 绘制球面。
// 19. **"LEGO"**: 绘制立体乐高图。
// 20. **"ARRX"**: 绘制 x 方向的箭头（仅在 `TVector` 中有效）。
// 21. **"ARRY"**: 绘制 y 方向的箭头（仅在 `TVector` 中有效）。
// 22. **"LEGO1"**: 绘制 Y-Z 平面上的 2D 直方图（仅在 `TH3` 中有效）。
// 23. **"LEGO2"**: 绘制 X-Z 平面上的 2D 直方图（仅在 `TH3` 中有效）。
// 24. **"LEGO3"**: 绘制 X-Y 平面上的 2D 直方图（仅在 `TH3` 中有效）。
// 25. **"COLZ"**: 绘制彩色的等高线图和直方图。
// 选项 "A Z"。这个选项用于指定绘制三维图形时是否自动调整 z 轴范围。 automatic z
// 当你使用 "A Z" 选项时，ROOT会自动调整 z 轴的范围；而当你不使用该选项时，ROOT会保持 z 轴范围不变，即不会自动调整。

//============================================================================
//   设置颜色
//============================================================================

/// @brief 自定义调色板
void set_nicer_2d_plot_style()
{
    // 设置调色板
    // gStyle->SetPalette() 函数用于设置 ROOT 绘图系统的调色板，以控制绘图中使用的颜色。调色板决定了在绘图中使用的颜色范围和分布方式。
    // 以下是一些基本的使用方法：

    // 使用预定义的调色板：
    // ROOT 提供了许多预定义的调色板，你可以直接使用这些调色板。例如，你可以使用 kRainBow 调色板，它提供了一系列彩虹色：
    // gStyle->SetPalette(kRainBow);
    // 自定义调色板：
    // 你也可以创建自定义的调色板。在 ROOT 中，调色板是一个数组，每个元素是一个颜色索引。你可以根据需要设置数组的大小和颜色索引。

    // 例如，下面是一个示例代码，创建了一个自定义的调色板，将白色、红色、蓝色和黑色依次排列：
    // const Int_t NRGBs = 4;
    // const Int_t NCont = 255;

    // // 颜色数组，分别对应白色、红色、蓝色和黑色
    // Double_t stops[NRGBs] = {0.00, 0.34, 0.61, 1.00};
    // Double_t red[NRGBs]   = {1.00, 1.00, 0.00, 0.00};
    // Double_t green[NRGBs] = {1.00, 0.00, 0.00, 0.00};
    // Double_t blue[NRGBs]  = {1.00, 0.00, 1.00, 0.00};

    // // 创建调色板
    // TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
    // gStyle->SetPalette(kVisibleSpectrum); // 设置调色板
    // 这将创建一个自定义的调色板，并将其设置为当前的调色板。
    const Int_t NRGBs = 5;
    const Int_t NCont = 255;

    Double_t stops[NRGBs] = {0.00, 0.34, 0.61, 0.84, 1.00};
    Double_t red[NRGBs] = {0.00, 0.00, 0.87, 1.00, 0.51};
    Double_t green[NRGBs] = {0.00, 0.81, 1.00, 0.20, 0.00};
    Double_t blue[NRGBs] = {0.51, 1.00, 0.12, 0.00, 0.00};
    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont); // rootv5.16 or late

    //    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
    //     gStyle->CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
    gStyle->SetNumberContours(NCont);
}

//-------------------------------------
// 环境颜色
//  TMarker d  d.DisplayMarkerTypes()
//  TCanvas c c.DrawColorTable()
// set color display, raibow, grayscale...
void set_color_env()
{

    const Int_t NRGBs = 5;
    const Int_t NCont = 99;

    Int_t fcol;

    Double_t stops[NRGBs] = {0.00, 0.34, 0.61, 0.84, 1.00};
    Double_t red[NRGBs] = {0.00, 0.00, 0.87, 1.00, 0.51};
    Double_t green[NRGBs] = {0.00, 0.81, 1.00, 0.20, 0.00};
    Double_t blue[NRGBs] = {0.51, 1.00, 0.12, 0.00, 0.00};
    fcol = TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
    gStyle->SetNumberContours(NCont);
    // SetPalette has been called in the above function, color style will
    // be set according to your own rgb definition if called

    // grayscale
    /*
       double dcol = 1/double(NRGBs);
       double grey = 1;

       for(int j = 0; j < NRGBs; j++){
    // ...... Define color with RGB equal to : gray, gray, gray .......
    stops[j]=double(j)/double(NRGBs-1);
    red[j]=grey;
    blue[j]=grey;
    green[j]=grey;

    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
    */

    TString Red1 = "#FFCC00";
    TString Red2 = "#FF9900";
    TString Red3 = "#FF6600";
    TString Red4 = "#FF3300";
    TString Red5 = "#FF0000";

    TString Blue1 = "#3300FF";
    TString Blue2 = "#0000FF";
    TString Blue3 = "#0033FF";
    TString Blue4 = "#0066FF";
    TString Blue5 = "#0099FF";
    TString Blue6 = "#00CCFF";
    TString Blue7 = "#00FFFF";
    TString Blue8 = "#00FFCC";

    TString Green1 = "#006633";
    TString Green2 = "#006600";
    TString Green3 = "#009933";
    TString Green4 = "#009900";
    TString Green5 = "#339900";
    TString Green6 = "#00CC33";
    TString Green7 = "#00CC00";
    TString Green8 = "#33CC00";
    TString Green9 = "#00FF00";

    TString Oran1 = "#FF3300";
    TString Oran2 = "#FF6600";
    TString Oran3 = "#FF6633";
    TString Oran4 = "#FF9900";
    TString Oran5 = "#FF9933";
    TString Oran6 = "#FF9966";

    TString SkyBlue = "#00CCFF";
    TString SeaBlue = "#0099FF";
    TString SadBlue = "#009999";
    TString LakeBlue = "#0099CC";
    TString DarkBlue = "#000099";

    TString Purp1 = "#CC33CC";
    TString Purp2 = "#9900FF";
    TString Purp3 = "#CC00FF";
    TString Purp4 = "#FF00FF";
    TString Purp5 = "#FF33FF";
    TString Purp6 = "#FF33CC";
    TString Purp7 = "#FF66FF";
    // how to use the color defined above --->  SetLineColor(TColor::GetColor(SkyBlue)) or SetLineColor(TColor::GetColor(SkyBlue.Data()))
}

/// @brief 设置坐标轴科学记数法
void set_axis_digital()
{
    TGaxis::SetMaxDigits(3);
}

/// @brief 设置多线程
void MTOpen()
{
//`TProof` 是 ROOT 中用于多线程计算的类，它提供了一种简单的方式来利用多核 CPU 进行并行计算。下面是一些常用的 `TProof` 方法和参数的说明：
// 1. **构造函数**：`TProof` 类没有公开的构造函数。你可以通过 `TProof::Open` 方法来创建一个 `TProof` 对象并打开一个 ProofLite 会话。
// 2. **Open 方法**：`TProof::Open` 方法用于打开一个 ProofLite 会话，启动多线程计算。它的参数可以是一个字符串，用于指定 ProofLite 会话的设置选项。通常情况下，你可以将参数留空，使用默认设置。
// 3. **Close 方法**：`TProof::Close` 方法用于关闭 ProofLite 会话，停止多线程计算。
// 4. **EnableImplicitMT 方法**：`TProof::EnableImplicitMT` 方法用于启用隐式多线程（Implicit Multi-Threading）模式。在这种模式下，ROOT 会自动在合适的情况下使用多线程。该方法接受一个布尔值参数，如果设置为 true，则启用隐式多线程；如果设置为 false，则禁用隐式多线程。
// 5. **Process 方法**：`TProof::Process` 方法用于在 ProofLite 集群上进行并行计算。它接受一个字符串作为参数，用于指定要在 ProofLite 集群上执行的任务或者分析。任务可以是一个 TSelector 类的子类，也可以是一系列 ROOT 命令。该方法会在 ProofLite 集群上启动一个计算任务，并在计算完成后返回结果。
// 6. **ProcessAsync 方法**：`TProof::ProcessAsync` 方法与 `Process` 方法类似，用于在 ProofLite 集群上进行并行计算。但是与 `Process` 方法不同的是，`ProcessAsync` 方法会立即返回一个 `TProofOutputFile` 对象，而不会等待计算完成。你可以使用这个对象来监控计算的进度，并在需要时获取计算结果。
// 7. **ClearCache 方法**：`TProof::ClearCache` 方法用于清除 ProofLite 集群上的缓存数据。这个方法可以帮助你释放空间并提高计算效率。
// 以上是一些常用的 `TProof` 方法和参数的说明。你可以根据具体的需求选择合适的方法，并根据需要调整参数来进行多线程计算。

    TProof::Open(""); // 开启多线程
}

/// @brief enable implicit multi-threading
void ImplicitMTOpen()
{   using namespace ROOT;
    ROOT::EnableImplicitMT();
}

/// @brief 获取当前文件路径
/// @return dir 文件路径 
TString dir_path()
{
    // get data directories
    TString dir = gSystem->DirName(__FILE__); // 获取当前文件路径
    dir.ReplaceAll("/./", "/");
    std::cout << dir << std::endl;
    gSystem->Setenv("Dir", dir); // 当前文件路径，填绝对路径或相对路径
    return dir;
}
//============================================================================
// TCanvas
//============================================================================
// 在ROOT中，TCanvas类有一些预定义的纸张尺寸可以直接使用。这些尺寸是以像素为单位的，以下是一些常用的尺寸：

// kA4: A4纸张大小 (795x1123像素)
// kA3: A3纸张大小 (1123x1592像素)
// kA2: A2纸张大小 (1592x2256像素)
// kA1: A1纸张大小 (2256x3184像素)
// kA0: A0纸张大小 (3184x4505像素)
// kLetter: Letter纸张大小 (792x612像素)
// kLegal: Legal纸张大小 (1008x612像素)

// 在 ROOT 中，TCanvas 有一些常用的像素尺寸可以直接使用。以下是一些常见的像素尺寸：

// 800x600：常用的标准尺寸，适合一般的绘图需求。
// 1024x768：稍大一些的尺寸，适合显示更多的细节。
// 1280x720：高清电视的分辨率，适合制作视频和演示。
// 1920x1080：全高清电视的分辨率，用于高质量的图形展示。

/// @brief 设置MyStyle，并准备画板
/// @param name 画板名
/// @param cW 宽度
/// @param cH 高度
/// @param defaultStyle 继承的默认Style，可选有 Modern Bold Video Pub ATLAS BELLE2 Default 
/// @param font  字体
/// @return 返回 TCanvas
TCanvas *setElsevierCanvas(const Char_t name[] = "c1", Int_t cW = 800, Int_t cH = 600, const Char_t defaultStyle[] = "Plain",int font = 132)
{
    gROOT->SetStyle(defaultStyle);
    // 创建一个默认的样式
    TStyle *myStyle = new TStyle("MyStyle", "Elsevier Journal Plot Style");
    myStyle->SetFrameBorderMode(0);
    myStyle->SetCanvasBorderMode(0);
    myStyle->SetPadBorderMode(0);
    myStyle->SetPadColor(0);
    myStyle->SetCanvasColor(0);
    myStyle->SetTitleColor(1);
    myStyle->SetStatColor(0);

    // 设置字体
    // int font = 132; // 设置字体为编号132

    // 设置标题对齐方式为居中
    myStyle->SetTitleX(0.5); //X title位于画板区域中心
    myStyle->SetTitleY(0.5); //Y title位于画板区域中心
    myStyle->SetTitleAlign(23); // 23 表示标题在水平和垂直方向上都居中

    // 设置标题大小
    myStyle->SetTitleSize(0.05, "X");
    myStyle->SetTitleSize(0.05, "Y");

    // 设置标签大小
    myStyle->SetLabelSize(0.04, "X");
    myStyle->SetLabelSize(0.04, "Y");

    // 设置标签偏移量
    myStyle->SetLabelOffset(0.02, "X");
    myStyle->SetLabelOffset(0.02, "Y");

    // 设置标题偏移量
    myStyle->SetTitleOffset(1.2, "X");
    myStyle->SetTitleOffset(1.2, "Y");

    // 设置字体
    myStyle->SetTitleFont(font, "X");
    myStyle->SetTitleFont(font, "Y");
    myStyle->SetTitleFont(font, "Z");
    myStyle->SetTitleFont(font, "title");
    myStyle->SetLabelFont(font, "X");
    myStyle->SetLabelFont(font, "Y");
    myStyle->SetLabelFont(font, "X");
    myStyle->SetTextFont(font);

    // 设置统计框
    myStyle->SetOptStat(1110); // 设置统计框中显示的内容，这里设置为显示均值、标准偏差、有效事件数和积分值。
    myStyle->SetStatFont(font);
    myStyle->SetStatColor(10);
    myStyle->SetCanvasColor(10);
    myStyle->SetTitleColor(10, "title");
    myStyle->SetFillColor(10);
    myStyle->SetStatX(0.99); // 设置统计框在 X 轴上的位置为画布的右边缘。
    myStyle->SetStatY(0.99); // 设置统计框在 Y 轴上的位置为画布的顶边缘。

    // myStyle->SetOptDate(1); //第一个数字 1 表示显示日期。第二个数字 1 表示在统计框中显示日期
    myStyle->SetOptTitle(0); // 设置标题的显示选项。在这里，参数为1表示显示标题。如果设置为0，则标题将不会显示。
    // myStyle->SetOptStat(1110); //设置统计框的显示选项。在这里，参数为1表示显示统计框。如果设置为0，则统计框将不会显示。
    // myStyle->SetOptFit(0); //设置拟合框的显示选项。在这里，参数为0表示不显示拟合框。如果设置为1，则拟合框将会显示。

    // 设置右侧和上侧ticks的是否显示
    myStyle->SetPadTickX(0); //
    myStyle->SetPadTickY(0); //

    // 设置标题对齐方式为居中
    myStyle->SetTitleAlign(23); // 23 表示标题在水平和垂直方向上都居中
    // 水平对齐值和垂直对齐值的取值范围为 1 到 3，分别表示左对齐、居中对齐和右对齐。这两个值可以组合在一起，形成一个两位数的整数，表示水平和垂直方向上的对齐方式。
    // 11：左对齐
    // 12：左对齐、垂直居中
    // 13：左对齐、垂直右对齐
    // 21：水平居中、垂直左对齐
    // 22：水平居中、垂直居中
    // 23：水平居中、垂直右对齐
    // 31：右对齐、垂直左对齐
    // 32：右对齐、垂直居中
    // 33：右对齐、垂直右对齐

    set_nicer_2d_plot_style();

    // 切入当前style
    myStyle->cd();

    delete gROOT->FindObject(name);
    // 应用样式
    gROOT->SetStyle("MyStyle");
    gROOT->ForceStyle();

    // 设置边距的大小（单位：画布宽度或高度的比例）
    float leftMargin = 0.15;
    float rightMargin = 0.05;
    float bottomMargin = 0.15;
    float topMargin = 0.05;

    // 创建一个画布，并设置纸张大小和边距大小
    TCanvas *canvas = new TCanvas(name, "", cW, cH);
    // canvas->SetCanvasSize(cW, cH);
    canvas->SetMargin(leftMargin, rightMargin, bottomMargin, topMargin);

    return canvas;
}

//============================================================================
// 全局风格设置  参考 TStyle.cxx
//============================================================================
// default style
// Modern Bold Video Pub ATLAS BELLE2 Default Plain
// gROOT->GetStyle(XXX);
// pip install atlas-plots python package

//============================================================================
//  TGraph 重点关注 TMultiGraph
//============================================================================
// https://root.cern.ch/doc/master/classTMultiGraph.html#a0c61644b83e361c40fee3d2d598fe407
// https://root.cern.ch/doc/master/classTGraph2D.html

// TMultiGraph 类是用于绘制多个图形对象的类，它本身并没有特定的绘图选项，而是继承自 TGraph 类，因此可以使用 TGraph 类的绘图选项。
// 常见的 TGraph 绘图选项包括：
// "AP"：绘制图形并绘制数据点（Markers），数据点将以指定的 Marker 形状显示。
// "AL"：绘制图形并绘制数据点之间的直线。
// "L"：绘制图形，只绘制数据点之间的直线，不绘制数据点。
// "P"：绘制数据点，不绘制图形线条。
// "C"：绘制图形，并对其进行平滑曲线拟合。
// "f"：绘制填充区域。
// "b"：绘制图形边界线。
// "l3d"：绘制三维线框。

/// @brief 绘制MultiGraph
/// @param graph 数组
/// @param numGraphs 数组大小
/// @param titleXY 标题名称及单位
/// @param leg 图例数组
void DrawMultiGraph(TGraph *graph [],int numGraphs,TString titleXY,TString leg []) {
    // 创建画布
    TCanvas *canvas = setElsevierCanvas();
    // canvas->SetLogx(); // 设置 x 轴对数坐标

    // 创建图例
    TLegend *legend = new TLegend(0.6, 0.6, 0.88, 0.88);
    legend->SetFillStyle(0);
    legend->SetBorderSize(0);

    // 创建多图形对象
    TMultiGraph *multiGraph = new TMultiGraph("multiGraph", titleXY);

    // 循环创建图形对象，并添加到多图形对象中
    for (int i = 0; i < numGraphs; ++i) {
        // 设置图形属性
        graph[i]->SetLineColor(50 - 5 * ((i + 1) % 10));
        graph[i]->SetMarkerColor(50 - 5 * ((i + 1) % 10));
        graph[i]->SetMarkerStyle(20 + i);
        graph[i]->SetLineWidth(2);
        // 将图形添加到多图形对象中
        multiGraph->Add(graph[i]);

        // 添加图例条目
        // legend->AddEntry(graph[i], graph[i]->GetName(), "lp");
        legend->AddEntry(graph[i], leg[i], "lp");
    }

    // 绘制多图形对象
    multiGraph->Draw("ALP");

    // 设置标题偏移量
    multiGraph->GetXaxis()->SetTitleOffset(1.2);
    multiGraph->GetYaxis()->SetTitleOffset(1.2);

    // 绘制图例
    legend->Draw();

    // 更新画布
    canvas->Update();
}

/// @brief 绘制MultiGraph
/// @param graph 向量
/// @param titleXY 标题名称及单位
/// @param leg 图例数组
void DrawMultiGraph(const std::vector<TGraph*>& graph, TString titleXY, const std::vector<TString>&leg) {
    
    // 创建画布
    TCanvas *canvas = setElsevierCanvas();
    // canvas->SetLogx(); // 设置 x 轴对数坐标

    // 创建图例
    TLegend *legend = new TLegend(0.6, 0.6, 0.88, 0.88);
    legend->SetFillStyle(0);
    legend->SetBorderSize(0);

    // 创建多图形对象
    TMultiGraph *multiGraph = new TMultiGraph("multiGraph", titleXY);

    int numGraphs = graph.size();
    if (graph.size() != leg.size())
    {
        printf("legend num not match graph num!!!");
        return;
    }
    
     // 循环创建图形对象，并添加到多图形对象中
    for (int i = 0; i < numGraphs; ++i) {
        // 设置图形属性
        graph[i]->SetLineColor(50 - 5 * ((i + 1) % 10));
        graph[i]->SetMarkerColor(50 - 5 * ((i + 1) % 10));
        graph[i]->SetMarkerStyle(20 + i);
        graph[i]->SetLineWidth(2);
        // 将图形添加到多图形对象中
        multiGraph->Add(graph[i]);

        // 添加图例条目
        // legend->AddEntry(graph[i], graph[i]->GetName(), "lp");
        legend->AddEntry(graph[i], leg[i], "lp");
    }

    // 绘制多图形对象
    multiGraph->Draw("ALP");

    // 设置标题偏移量
    multiGraph->GetXaxis()->SetTitleOffset(1.2);
    multiGraph->GetYaxis()->SetTitleOffset(1.2);

    // 绘制图例
    legend->Draw();

    // 更新画布
    canvas->Update();
}

/// @brief 将Grpah2D等高线图转换成hist2d图
/// @param graph3d
/// @param hist2d
void TGraph2D_to_TH2D(const TGraph2D *graph3d, TH2D *hist2d)
{
    int nbinsX = hist2d->GetNbinsX();
    int nbinsY = hist2d->GetNbinsY();

    // 遍历 TGraph2D 中的所有点
    for (int i = 0; i < graph3d->GetN(); ++i)
    {
        double x, y, z;
        graph3d->GetPoint(i, x, y, z);

        // 确定 x 和 y 对应的 bin
        int binX = hist2d->GetXaxis()->FindBin(x);
        int binY = hist2d->GetYaxis()->FindBin(y);

        // 将 z 值填充到对应的 bin 中
        hist2d->SetBinContent(binX, binY, z);
    }
}

/// @brief 将hist2d图转换成等高线图
/// @param graph3d
/// @param hist2d
void TH2D_to_TGraph2D(const TH2D *hist2d, TGraph2D *graph3d)
{
    int nbinsX = hist2d->GetNbinsX();
    int nbinsY = hist2d->GetNbinsY();

    // 遍历二维直方图的所有 bin
    for (int ix = 1; ix <= nbinsX; ++ix)
    {
        for (int iy = 1; iy <= nbinsY; ++iy)
        {
            double x = hist2d->GetXaxis()->GetBinCenter(ix);
            double y = hist2d->GetYaxis()->GetBinCenter(iy);
            double z = hist2d->GetBinContent(ix, iy);
            graph3d->SetPoint(graph3d->GetN(), x, y, z);
        }
    }
}

//============================================================================
// histogram 重点关注THStack
//============================================================================
// https://root.cern.ch/doc/master/classTHStack.html

// THStack继承自TH1和TH2

// 常用的 TH1 绘图选项：
// "hist"：绘制直方图。
// "hist text"：绘制直方图并在直方图上显示条目数。
// "hist text0"：绘制直方图并在直方图上显示条目数（忽略条目数为零的条目）。
// "hist c"：绘制直方图并绘制连接数据点之间的直线。
// "hist same"：在同一画布上绘制多个直方图，直方图将被叠加显示。
// "e"：在直方图上绘制误差条。
// "e1"：在直方图上绘制误差条，但不绘制直方图线条。
// "lego"：以 LEGO 图形方式绘制直方图。
// "col"：以色彩图形方式绘制直方图。
// "box"：以方块图形方式绘制直方图。
// "candle"：以蜡烛图形方式绘制直方图。
// "pie"：以饼图形方式绘制直方图。

// 常用的 TH2 绘图选项：
// "COL"：绘制颜色填充的二维直方图。
// "CONT"：绘制等高线图。
// "CONT0"：绘制不带标签的等高线图。
// "CONT1"：绘制带标签的等高线图。
// "LEGO"：绘制乐高图（三维直方图的一种视图）。
// "LEGO1"：绘制带轮廓的乐高图。
// "LEGO2"：绘制带阴影的乐高图。
// "LEGOE"：绘制带误差条的乐高图。
// "BOX"：绘制箱形图（每个格子用一个长方体表示）。
// "ARR"：绘制箭头图。

// Stack's drawing options
// The specific stack's drawing options are:
// NOSTACK If option "nostack" is specified, histograms are all painted in the same pad as if the option "same" had been specified.
// NOSTACKB If the option "nostackb" is specified histograms are all painted on the same pad next to each other as bar plots.
// PADS if option "pads" is specified, the current pad/canvas is subdivided into a number of pads equal to the number of histograms and each histogram is painted into a separate pad.
// NOCLEAR By default the background of the histograms is erased before drawing the histograms. The option "noclear" avoids this behavior. This is useful when drawing a THStack on top of another plot. If the patterns used to draw the histograms in the stack are transparent, then the plot behind will be visible.


/// @brief 2 histogram 叠加
/// @param h1 
/// @param h2 
/// @param norm 是否需要归一化
/// @return THStack 
THStack * Add2Hist(TH1 *h1, TH1* h2,Bool_t norm = kTRUE){
  THStack *hs = new THStack("hs",Form(";%s;%s",h1->GetXaxis()->GetTitle(),h1->GetYaxis()->GetTitle()));

  h1->SetMarkerColor(kRed);
  h1->SetMarkerStyle(21);
  h1->SetLineColor(kRed);

  h2->SetMarkerColor(kBlue);
  h2->SetMarkerStyle(22);
  h2->SetLineColor(kBlue);

  if(norm){
    h1->Sumw2();
    h1->Scale(1./h1->GetEntries());
    h2->Sumw2();
    h2->Scale(1./h2->GetEntries());
  }
  hs->Add(h1);
  hs->Add(h2);
  return hs;

}

/// @brief 2 histogram 并排放置
/// @param h1 
/// @param h2 
void draw2H(TH1F *h1, TH1F *h2)
{
    TPad *pad1 = new TPad("pad1", "", 0., 0.001, 0.499, 0.999, 10);
    TPad *pad2 = new TPad("pad2", "", 0.501, 0.001, 0.999, 0.999, 10);
    pad1->Draw();
    pad2->Draw();

    pad1->cd();
    h1->Draw();
    pad2->cd();
    h2->Draw();
}

void MoveStat(TH1* h,Double_t x0,Double_t y0,Double_t x1, Double_t y1,Int_t icolor=1){
  gPad->Modified();
  gPad->Update();
  TPaveStats *pstmp = (TPaveStats*)h->GetListOfFunctions()->FindObject("stats");
  pstmp->SetX1NDC(x0);
  pstmp->SetX2NDC(x1);
  pstmp->SetY1NDC(y0); 
  pstmp->SetY2NDC(y1);
  pstmp->SetTextColor(icolor);
  gPad->Modified();
  gPad->Update();
}

void MoveStat(TCanvas *ctmp,TH1* h,Double_t x0,Double_t y0,Double_t x1, Double_t y1,Int_t icolor=1){
  ctmp->Modified();
  ctmp->Update();
  TPaveStats *pstmp = (TPaveStats*)h->GetListOfFunctions()->FindObject("stats");
  pstmp->SetX1NDC(x0);
  pstmp->SetX2NDC(x1);
  pstmp->SetY1NDC(y0); 
  pstmp->SetY2NDC(y1);
  pstmp->SetTextColor(icolor);
  ctmp->Modified();
  ctmp->Update();
}

TH1 *ProjTGraphErrors2TH1(Char_t histname[],TGraphErrors *gr,Double_t binw=-0.01){
  Double_t Ymin = gr->GetYaxis()->GetXmin();
  Double_t Ymax = gr->GetYaxis()->GetXmax();
  if(binw<0){
    binw = (Ymax-Ymin)/100;
  }
  TH1F *newH = newTH1F(histname,binw,Ymin,Ymax);
  Int_t n = gr->GetN();
  Double_t x,y;
  for(Int_t i=0; i<n; i++) {
    gr->GetPoint(i,x,y);
    FillTH1F(y,newH);
  }
  return newH;
}

TH1D *Create1DDHistogram(TString label, TString title, Int_t nbin, Double_t low, Double_t up, TString type = "")
{
  /*
  * label 窗口标签
  * title 绘图标题
  * nbins bin的个数
  * low x最小值
  * up x最大值
  * 绘图类型，可改为log坐标表示
  */
  TString TYPE = type;
  TYPE.ToUpper();
  TH1D *theHisto;

  if (TYPE == "LOG")
  {

    double bins[1000];

    for (int i = 0; i <= nbin; i++)
    {
      double val_bin = low * std::pow(10., i * std::log10(up / low) / nbin);
      double exp_10 = 4. - int(std::log10(val_bin));
      double factor = std::pow(10., exp_10);
      val_bin = int(factor * val_bin) / factor;

      bins[i] = val_bin;
    }

    theHisto = new TH1D(label, title, nbin, bins);
  }
  else
    theHisto = new TH1D(label, title, nbin, low, up);
  return theHisto;
}
//============================================================================
// TLegend 
//============================================================================
// https://root.cern.ch/doc/master/classTLegend.html
// the label associated to this object and an option which a combination of:
// L: draw line associated with TAttLine if obj inherits from TAttLine
// P: draw polymarker associated with TAttMarker if obj inherits from TAttMarker
// F: draw a box with fill associated wit TAttFill if obj inherits TAttFill
// E: draw vertical error bar

//    auto legend = new TLegend(0.1,0.7,0.48,0.9);
//    legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
//    legend->AddEntry(h1,"Histogram filled with random numbers","f"); //fill
//    legend->AddEntry("f1","Function abs(#frac{sin(x)}{x})","l"); // line
//    legend->AddEntry("gr","Graph with error bars","lep"); // line error point
//    legend->Draw();

// 使用空指针
//    auto* legend = new TLegend(0.2, 0.2, .8, .8);
//    auto h = new TH1F("", "", 1, 0, 1);
//    legend->AddEntry(h, "Histogram \"h\"", "l");
//    legend->AddEntry((TObject*)0, "", "");
//    legend->AddEntry((TObject*)0, "Some text", "");
//    legend->AddEntry((TObject*)0, "", "");
//    legend->AddEntry(h, "Histogram \"h\" again", "l");
//    legend->Draw();

//  使用SetNColumns() 设置成多列
//    auto legend = new TLegend(0.2, 0.2, .8, .8);
//    auto h = new TH1F("", "", 1, 0, 1);
//    legend->SetNColumns(2);
//    legend->AddEntry(h, "Column 1 line 1", "l");
//    legend->AddEntry(h, "Column 2 line 1", "l");
//    legend->AddEntry(h, "Column 1 line 2", "l");
//    legend->AddEntry(h, "Column 2 line 2", "l");
//    legend->Draw();

/// @brief 设置图例的列数
/// @param legend 图例
/// @param numColumns 列数
void setLegendColumns(TLegend* legend, int numColumns) {
    legend->SetNColumns(numColumns);
}


//  使用BuildLegend()自动建图例
//    RooPlot::BuildLegend()
//    TVirtualPad::BuildLegend()
//    TPad::BuildLegend() default placement values are such that they trigger
//    the automatic placement.
//    c4->BuildLegend();

/// @brief 自动构建图例
/// @param ctmp Canvas temporary
void autoLegend(TCanvas *ctmp)
{
  ctmp->BuildLegend();
  ctmp->Modified();
  ctmp->Update();
}

/// @brief 自动构建图例
void autoLegend()
{
  gPad->BuildLegend();
  gPad->Modified();
  gPad->Update();
}

//============================================================================
// 9.6.1.4 Setting Text Font
//============================================================================
// https://root.cern.ch/root/htmldoc/guides/users-guide/ROOTUsersGuide.html

// Font ID	X11	True Type name	Is italic	“boldness”
// 1	times-medium-i-normal	“Times New Roman”	Yes	4
// 2	times-bold-r-normal	“Times New Roman”	No	7
// 3	times-bold-i-normal	“Times New Roman”	Yes	7
// 4	helvetica-medium-r-norma l	“Arial”	No	4
// 5	helvetica-medium-o-norma l	“Arial”	Yes	4
// 6	helvetica-bold-r-normal	“Arial”	No	7
// 7	helvetica-bold-o-normal	“Arial”	Yes	7
// 8	courier-medium-r-normal	“Courier New”	No	4
// 9	courier-medium-o-normal	“Courier New”	Yes	4
// 10	courier-bold-r-normal	“Courier New”	No	7
// 11	courier-bold-o-normal	“Courier New”	Yes	7
// 12	symbol-medium-r-normal	“Symbol”	No	6
// 13	times-medium-r-normal	“Times New Roman”	No	4
// 14		“Wingdings”	No	4

//============================================================================
// 9.4.4 Markers
//============================================================================
// https://root.cern.ch/root/htmldoc/guides/users-guide/ROOTUsersGuide.html
// 

//============================================================================
// 9.4.7 Greek Letters
//============================================================================
// https://root.cern.ch/root/htmldoc/guides/users-guide/ROOTUsersGuide.html

// #alpha     #beta    #chi      #delta     #varepsilon  #phi
// #gamma     #eta     #iota     #varphi    #kappa       #lambda
// #mu        #nu      #omicron  #pi        #theta       #rho
// #sigma     #tau     #upsilon  #varomega  #omega       #xi
// #psi       #zeta    #Alpha    #Beta      #Chi         #Delta
// #Epsilon   #Phi     #Gamma    #Eta       #Iota        #Kappa
// #vartheta  #Lambda  #Mu       #Nu        #Omicron     #Pi
// #Theta     #Rho     #Sigma    #Tau       #Upsilon     #Omega
// #varsigma  #Xi      #Psi      #epsilon   #varUpsilon  #Zeta

//============================================================================
// 9.4.8 Mathematical Symbols
//============================================================================
// https://root.cern.ch/root/htmldoc/guides/users-guide/ROOTUsersGuide.html


//============================================================================
// TLine
//============================================================================

/// @brief 在X处画一条直线
/// @param atX 位置
/// @param iColor 颜色
/// @param canvasName 画板名
void LineX(Double_t atX, Int_t iColor = kRed, const Char_t canvasName[] = "c1")
{
    TCanvas *ctmp = (TCanvas *)gROOT->GetListOfCanvases()->FindObject(canvasName);
    if (ctmp)
    {
        ctmp->Modified();
        ctmp->Update();
        TLine *l1 = new TLine(atX, gPad->GetUymin(), atX, gPad->GetUymax());
        l1->SetLineColor(iColor);
        l1->Draw();
    }
    else
    {
        gPad->Modified();
        gPad->Update();
        TLine *l1 = new TLine(atX, gPad->GetUymin(), atX, gPad->GetUymax());
        l1->SetLineColor(iColor);
        l1->Draw();
    }
}

/// @brief 在Y处画一条直线
/// @param atY 位置
/// @param iColor 颜色
/// @param canvasName 画板名
void LineY(Double_t atY, Int_t iColor = kRed, const Char_t canvasName[] = "c1")
{
    TCanvas *ctmp = (TCanvas *)gROOT->GetListOfCanvases()->FindObject(canvasName);
    if (ctmp)
    {
        ctmp->Modified();
        ctmp->Update();
        TLine *l1 = new TLine(gPad->GetUxmin(), atY, gPad->GetUxmax(), atY);
        l1->SetLineColor(iColor);
        l1->Draw();
    }
    else
    {
        gPad->Modified();
        gPad->Update();
        TLine *l1 = new TLine(gPad->GetUxmin(), atY, gPad->GetUxmax(), atY);
        l1->SetLineColor(iColor);
        l1->Draw();
    }
}

//============================================================================
// Draw TLatex
//============================================================================
//***************************************************
// 颜色设置
//***************************************************
// 在 ROOT 中，TLatex 类的 SetTextColor 函数用于设置文本的颜色。这个函数接受一个整数作为参数，这个整数代表 ROOT 的颜色索引。

// ROOT 中的颜色索引是一个从 0 开始的整数，它们对应了 ROOT 预定义的一系列颜色。以下是一些常用颜色的索引：
// 0: 白色
// 1: 黑色
// 2: 红色
// 3: 绿色
// 4: 蓝色
// 5: 黄色
// 6: 紫色
// 7: 青色

void DrawText(Double_t posX = 0., Double_t posY = 0., const char *text = "",
              Double_t size = 0.08, Int_t col = 1)
{
    // Drawing some text
    TLatex *pText = new TLatex(posX, posY, text);
    pText->SetNDC(true);
    pText->SetTextColor(col);
    pText->SetTextSize(size);
    pText->SetTextFont(132);
    pText->Draw();
}

//============================================================================
// 读取文件  重点关注 RDataFrame
//============================================================================
// RDataFrame 
//  https://root.cern/doc/master/classROOT_1_1RDataFrame.html#distrdf
// python uproot package
//  https://root-forum.cern.ch/t/problem-installing-root-numpy/53625
//-------------------------------------
// 1、采用TTreeReader
//
void ReadAndFill(TString fname, TH1D *hist)
{
    // Function to read a file and fill a histogram with the values of a variable using TTreeReader.

    // Parameters:
    // - fname: The name of the file to be read.
    // - hist: Pointer to the histogram to be filled.

    TFile *f = new TFile(fname);

    TTreeReader fReader("Det", f); //! the tree reader
    // Readers to access the data (delete the ones you do not need).
    TTreeReaderArray<Char_t> SDName = {fReader, "SDName"};
    TTreeReaderArray<Char_t> PName = {fReader, "PName"};
    // TTreeReaderArray<Char_t> SDName(fReader, "SDName"); //! 另一种写法
    // TTreeReaderValue<Int_t> CopyNumberID = {fReader, "CopyNumberID"};
    // TTreeReaderValue<Int_t> MotherCopyNumberID = {fReader, "MotherCopyNumberID"};
    TTreeReaderValue<Int_t> EventID = {fReader, "EventID"};
    // TTreeReaderValue<Int_t> ParentID = {fReader, "ParentID"};
    TTreeReaderValue<Int_t> TrackID = {fReader, "TrackID"};
    // TTreeReaderValue<Int_t> StepID = {fReader, "StepID"};
    // TTreeReaderValue<Double_t> Edep = {fReader, "Edep"};
    TTreeReaderValue<Double_t> PosX = {fReader, "PosX"};
    TTreeReaderValue<Double_t> PosY = {fReader, "PosY"};
    TTreeReaderValue<Double_t> PosZ = {fReader, "PosZ"};
    // TTreeReaderValue<Double_t> GlobalT = {fReader, "GlobalT"};
    // TTreeReaderValue<Double_t> LocalT = {fReader, "LocalT"};
    // TTreeReaderValue<Double_t> ProperT = {fReader, "ProperT"};
    TTreeReaderValue<Double_t> Ekin = {fReader, "Ekin"};
    // TTreeReaderValue<Double_t> Velocity = {fReader, "Velocity"};
    TTreeReaderValue<Double_t> MomentX = {fReader, "MomentX"};
    TTreeReaderValue<Double_t> MomentY = {fReader, "MomentY"};
    TTreeReaderValue<Double_t> MomentZ = {fReader, "MomentZ"};
    TTreeReaderArray<Char_t> ProC = {fReader, "ProC"};

    while (fReader.Next())
    {
        hist->Fill(*Ekin);
    }

    f->Close();
}

//-------------------------------------
// 2、采用Branch的
// Branch 可以读取完全的PName
void ReadAndFillB(TString fname, TH1D *hist, TString TreeName, TString VarName)
{
    // Function to read a file and fill a histogram with the values of a variable using TBranch.

    // Parameters:
    // - fname: The name of the file to be read.
    // - hist: Pointer to the histogram to be filled.
    // - TreeName: The name of the tree in the file.
    // - VarName: The name of the variable to be read.

    TFile *f = new TFile(fname);
    TTree *t = (TTree *)f->Get(TreeName);
    // Char_t SDName[32], PName[32];

    // t->SetBranchAddress("SDName", SDName);
    // t->SetBranchAddress("PName", PName);

    Double_t Ekin;
    t->SetBranchAddress(VarName, &Ekin);

    Long64_t nEntries = t->GetEntries();
    for (Long64_t i = 0; i < nEntries; i++)
    {
        t->GetEntry(i);
        hist->Fill(Ekin);
    }

    f->Close();
}

//***************************************************
// 采用RDataFrame
//***************************************************
// https://root.cern/doc/master/classROOT_1_1RDataFrame.html#distrdf
// RDataFrame 在构建时考虑了模块化和灵活的工作流，总结如下：
// 1.通过指定数据集来构造 DataFrame 对象。RDataFrame 支持 TTree 以及 TChain、CSV 文件、SQLite 文件、RNTuples，
//   并且可以扩展到自定义数据格式。在 Python 中，也可以将 NumPy 数组导入到 RDataFrame 中。
// 2.通过以下方式转换数据帧：
//  - 应用过滤器。这将仅选择数据集的特定行。
//  - 创建自定义列。例如，自定义列可以包含必须对数据集的每一行执行的计算结果。
// 3.产生结果。操作用于将数据聚合到结果中。大多数操作都是惰性的，即它们不是当场执行的，而是在 RDataFrame 中注册的，并且仅在首次访问结果时执行。


// TTreeReader	
// ==========================
// TTreeReader reader("myTree", file);
// TTreeReaderValue<A_t> a(reader, "A");
// TTreeReaderValue<B_t> b(reader, "B");
// TTreeReaderValue<C_t> c(reader, "C");
// while(reader.Next()) {
//    if(IsGoodEvent(*a, *b, *c))
//       DoStuff(*a, *b, *c);
// }

// ROOT::RDataFrame
// ==========================
// ROOT::RDataFrame d("myTree", file, {"A", "B", "C"});
// d.Filter(IsGoodEvent).Foreach(DoStuff);

// TTree::Draw	
// ==========================
// auto *tree = file->Get<TTree>("myTree");
// tree->Draw("x", "y > 2");

// ROOT::RDataFrame
// ==========================
// ROOT::RDataFrame df("myTree", file);
// auto h = df.Filter("y > 2").Histo1D("x");
// h->Draw()

// tree->Draw("jet_eta", "weight*(event == 1)");

// df.Filter("event == 1").Histo1D("jet_eta", "weight");
// // or the fully compiled version:
// df.Filter([] (ULong64_t e) { return e == 1; }, {"event"}).Histo1D<RVec<float>>("jet_eta", "weight");

// // object selection: for each event, fill histogram with array of selected pts
// tree->Draw('Muon_pt', 'Muon_pt > 100')

// // with RDF, arrays are read as ROOT::VecOps::RVec objects
// df.Define("good_pt", "Muon_pt[Muon_pt > 100]").Histo1D("good_pt")

// create RDataFrame
// // single file -- all constructors are equivalent
// TFile *f = TFile::Open("file.root");
// TTree *t = f.Get<TTree>("treeName");
 
// RDataFrame d1("treeName", "file.root");
// RDataFrame d2("treeName", f); // same as TTreeReader
// RDataFrame d3(*t);
 
// // multiple files -- all constructors are equivalent
// TChain chain("myTree");
// chain.Add("file1.root");
// chain.Add("file2.root");
 
// RDataFrame d4("myTree", {"file1.root", "file2.root"});
// std::vector<std::string> files = {"file1.root", "file2.root"};
// RDataFrame d5("myTree", files);
// RDataFrame d6("myTree", "file*.root"); // the glob is passed as-is to TChain's constructor
// RDataFrame d7(chain);

// RDataFrame d(10); // a RDF with 10 entries (and no columns/branches, for now)
// d.Foreach([] { static int i = 0; std::cout << i++ << std::endl; }); // silly example usage: count to ten

// auto df = ROOT::RDF::FromCSV("input.csv");
// auto df = ROOT::RDF::FromSqlite("XXX");
// auto df = ROOT::RDF::FromArrow("XXX");
// auto df = ROOT::RDF::FromNumpy("XXX");

// # Read data from NumPy arrays
// # The column names in the RDataFrame are taken from the dictionary keys
// x, y = numpy.array([1, 2, 3]), numpy.array([4, 5, 6])
// df = ROOT.RDF.FromNumpy({"x": x, "y": y}) 
// # Use RDataFrame as usual, e.g. write out a ROOT file
// df.Define("z", "x + y").Snapshot("tree", "file.root")

// AsNumpy()
// df = ROOT.RDataFrame("myTree", "myFile.root")
// cols = df.Filter("x > 10").AsNumpy(["x", "y"]) # retrieve columns "x" and "y" as NumPy arrays
// print(cols["x"], cols["y"]) # the values of the cols dictionary are NumPy arrays


// Fill a TH1D with the "MET" branch
// RDataFrame d("myTree", "file.root");
// auto h = d.Histo1D("MET");
// h->Draw();

