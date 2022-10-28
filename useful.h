/*
 * @Description:
 * @version:
 * @Author: Hubery-Lee
 * @E-mail: hrbeulh@126.com
 * @Date: 2022-10-28 15:22:59
 * @LastEditTime: 2022-10-28 15:49:03
 * @LastEditors: Hubery-Lee
 */
#ifndef USEFUL_h
#define USEFUL_h 1

#include <TStyle.h>
// Set the general style options
void SetSgStyle()
{
    // No Canvas Border
    gStyle->SetCanvasBorderMode(0);
    gStyle->SetCanvasBorderSize(0);
    // White BG
    gStyle->SetCanvasColor(10);
    // Format for axes
    gStyle->SetLabelFont(22, "xyz");
    gStyle->SetLabelSize(0.06, "xyz");
    gStyle->SetLabelOffset(0.01, "xyz");
    gStyle->SetNdivisions(510, "xyz");
    gStyle->SetTitleFont(22, "xyz");
    gStyle->SetTitleColor(1, "xyz");
    gStyle->SetTitleSize(0.06, "xyz");
    gStyle->SetTitleOffset(0.91); //0.91
    gStyle->SetTitleYOffset(1.5);
    // No pad borders
    gStyle-> SetPadBorderMode(0);
    gStyle->SetPadBorderSize(0);
    // White BG
    gStyle->SetPadColor(10);
    // Margins for labels etc.
    gStyle->SetPadLeftMargin(0.15);
    gStyle->SetPadBottomMargin(0.15);
    gStyle->SetPadRightMargin(0.05);
    gStyle->SetPadTopMargin(0.06);
    // No error bars in x direction
    gStyle->SetErrorX(0);
    // Format legend
    gStyle->SetLegendBorderSize(0);
    gStyle->SetFillStyle(0);
}

// 设置Latex放置位置（x0,y0）,直方图，字符串，字体大小
void txtN(Double_t x0, Double_t y0, TH1 *h, Char_t sName[] = "N=%.0f", Double_t sizeTxt = 0.06)
{
    h->SetStats(kFALSE);
    TLatex *ltx = new TLatex();
    ltx->SetNDC(kTRUE);
    ltx->SetTextColor(h->GetLineColor());
    ltx->SetTextFont(22);
    ltx->SetTextSize(sizeTxt);
    ltx->DrawLatex(x0, y0, Form(sName, h->GetEntries()));
    gPad->Modified();
    gPad->Update();
}

#include "TH1F.h"
// hist名称，bin宽度，bin上下限，设置MeV标题，设置Mark样式
TH1F * newTH1F(Char_t name[]="h1",Double_t binw=0.01, Double_t LowBin=0.0,Double_t HighBin=3.0,Bool_t MevTitle=kTRUE,Int_t iMode=-1)
{
    Int_t nbin = TMath::Nint((HighBin-LowBin)/binw);
    HighBin = binw*nbin + LowBin;
    
    TH1F *h = new TH1F(name,"",nbin,LowBin,HighBin);
    if(MevTitle)
        h->GetYaxis()->SetTitle(TString::Format("Events/(%.0fMeV/c^{2})",h->GetBinWidth(1)*1000));
    h->SetMinimum(0.0);
    h->GetYaxis()->SetTitleOffset(1.5);
    if(iMode>=0&&iMode<14){
        Int_t iMarker[] ={20,21,24,25,28,29,30,27,3,5,2,26,22,23};
        Int_t iColor[]={2,4,6,9,1,50,40,31,41,35,44,38,47,12};
        h->SetMarkerStyle(iMarker[iMode]);
        h->SetMarkerColor(iColor[iMode]);
        h->SetLineColor(iColor[iMode]);
    }
    return h;
}

#include "TLine.h"
// LineX1： 线的位置，颜色，宽度
void LineX1(Double_t atX, Int_t iColor=kRed, Int_t iStyle=1,Double_t iWidth=1)
{
    gPad->Modified();
    gPad->Update();
    TLine *l1 = new TLine(atX,gPad->GetUymin(),atX,gPad->GetUymax());
    l1->SetLineColor(iColor);
    l1->SetLineStyle(iStyle);
    l1->SetLineWidth(iWidth);
    l1->Draw();
}

#endif