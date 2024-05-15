/* MYSTYLE.h --- 
 * 
 * Filename: MYSTYLE.h
 * Description: 
 * Author: Li Hui,李会
 * Maintainer: 
 * Created: 一 8月 31 08:37:08 2020 (+0800)
 * Version: 
 * Package-Requires: ()
 * Last-Updated: 一 8月 31 08:42:36 2020 (+0800)
 *           By: Li Hui,李会
 *     Update #: 1
 * URL: https://github.com/Hubery-Lee
 * Doc URL: 
 * Keywords: 
 * Compatibility: 
 * 
*/

#ifndef MYSTYLE_LEE_h
#define MYSTYLE_LEE_h 1

#include <TLine.h>
#include <TLatex.h>
#include <TColor.h>
#include <TString.h>
// #include <TPaveStats.h>
#include <TH1.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TH1D.h>
#include <TH2D.h>
// #include <TLegend.h>
// #include <THStack.h>
// #include <TList.h>
#include <TStyle.h>
#include <TROOT.h>
#include <TVector3.h>
#include <vector>

#include <TCanvas.h>
#include <TPad.h>
#include <vector>
#include <TF1.h>
#include <TMath.h>
#include <TRandom3.h>


TCanvas* prepareCanvas(Char_t const name[]="c1",Int_t xL = 600,Int_t yL=400){
  /* 建立画布，设置画布字体，上下左右边距，状态栏字体 
  * name 设置画布名称
  * xL X长度
  * yL Y长度
  */
  gROOT->SetStyle("Plain"); 
  TStyle *Sty = new TStyle("MyStyle","My Style");
  Sty->SetFrameBorderMode(0);
  Sty->SetCanvasBorderMode(0);
  Sty->SetPadBorderMode(0);
  Sty->SetPadColor(0);
  Sty->SetCanvasColor(0);
  Sty->SetTitleColor(1);
  Sty->SetStatColor(0);

  Sty->SetTitleFont(22,"X");
  Sty->SetTitleFont(22,"Y");
  Sty->SetTitleFont(22,"Z");
  Sty->SetTitleFont(22,"title");
  Sty->SetLabelFont(22,"X");
  Sty->SetLabelFont(22,"Y");
  Sty->SetLabelFont(22,"X");
  Sty->SetOptStat(1110);
  Sty->SetStatFont(22);
  Sty->SetStatColor(10);
  Sty->SetCanvasColor(10);
  Sty->SetTitleColor(10,"title");
  Sty->SetFillColor(10);
  Sty->SetStatX(0.99);
  Sty->SetStatY(0.99);
  //  Sty->SetStatW(0.5);
  // Sty->SetStatH(0.4);

  // Sty->SetOptDate(11);

  Sty->cd();  
  //  gROOT->SetStyle("MyStyle");
  //  gROOT->ForceStyle();
  // return;

  //for more beautiful
  const Int_t NRGBs = 5;
  const Int_t NCont = 99;

  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
  if(gROOT->GetVersionDate()>20090000){
    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont); //rootv5.16 or late
  }else{
    //gStyle->CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont); //root v.515 or before
  }
  gStyle->SetNumberContours(NCont);

 
  delete gROOT->FindObject(name);
  TCanvas *c1 = new TCanvas(name,"",xL,yL);
  c1->SetFillColor(10);
  c1->SetLeftMargin(0.12);
  c1->SetRightMargin(0.099);
  c1->SetTopMargin(0.05);
  gROOT->SetStyle("MyStyle");
  gROOT->ForceStyle(); 
  return c1; 
}

void lineX(Double_t atX, Int_t iColor=kRed,Char_t const canvasName[]="c1",
          Double_t LineW=0.02, Int_t iStyle=1){
/*在图中垂直X轴画一条线
* atX 在X轴上的坐标
* iColor 颜色
* canvasName 画布名称
* LineW 线条宽度
* iStyle 线条类型
*/
  TCanvas *ctmp =(TCanvas *)gROOT->GetListOfCanvases()->FindObject(canvasName);
  if(ctmp){
    ctmp->Modified();
    ctmp->Update();
    TLine *l1 = new TLine(atX,gPad->GetUymin(),atX,gPad->GetUymax());
    l1->SetLineColor(iColor);
    l1->SetLineWidth((Width_t)LineW);
    l1->SetLineStyle(iStyle);
    l1->Draw();
  }else{
    gPad->Modified();
    gPad->Update();
    TLine *l1 = new TLine(atX,gPad->GetUymin(),atX,gPad->GetUymax());
    l1->SetLineColor(iColor);
    l1->SetLineWidth((Width_t)LineW);
    l1->SetLineStyle(iStyle);
    l1->Draw();
  } 
}

void lineY(Double_t atY, Int_t iColor=kRed,Char_t const canvasName[]="c1",
          Double_t LineW=0.02, Int_t iStyle=1){
/*在图中垂直Y轴画一条线
* atY 在Y轴上的坐标
* iColor 颜色
* canvasName 画布名称
* LineW 线条宽度
* iStyle 线条类型
*/
  TCanvas *ctmp =(TCanvas *)gROOT->GetListOfCanvases()->FindObject(canvasName);
  if(ctmp){
    ctmp->Modified();
    ctmp->Update();
    TLine *l1 = new TLine(atY,gPad->GetUymin(),atY,gPad->GetUymax());
    l1->SetLineColor(iColor);
    l1->SetLineWidth((Width_t)LineW);
    l1->SetLineStyle(iStyle);
    l1->Draw();
  }else{
    gPad->Modified();
    gPad->Update();
    TLine *l1 = new TLine(atY,gPad->GetUymin(),atY,gPad->GetUymax());
    l1->SetLineColor(iColor);
    l1->SetLineWidth((Width_t)LineW);
    l1->SetLineStyle(iStyle);
    l1->Draw();
  } 
}

void drawText(Double_t posX = 0., Double_t posY = 0., const char* text = "",
	      Double_t size=0.08,Int_t col=1
	      //                      Int_t align=0, Double_t angle=0.,
	      //                      Bool_t bNDC=kTRUE
	      )
{
  /* Drawing some text
  * posX X位置
  * posY Y位置
  * text 所画内容
  * size 字体大小 0.08左右为宜
  */
  TLatex* pText=new TLatex(posX,posY,text);
  pText->SetNDC(kTRUE);
  //pText->SetNDC(bNDC);
  pText->SetTextColor(col); pText->SetTextSize(size);
  //pText->SetTextAngle(angle);
  //pText->SetTextFont(fontStyle); 
  //pText->SetTextAlign(align);
  pText->Draw();
}

void drawNice2DHisto(TH2* h,const char* opt="",double range = 10.)
{
  // Draw a 2D histo with the rainbow colors and the palette besides
  /*
  * h 传入直方图
  * opt 选项 colz contz
  */
  TString options = "colz"; options += opt;
  if(gPad->GetLogz() == 0 && h->GetMaximum()<range) h->SetAxisRange(0.,range,"Z");
  h->SetStats(kFALSE);
  h->SetTitleOffset(0.8,"T");
  gPad->SetRightMargin(0.16);
  h->DrawCopy(options.Data());
}

void draw2TH1(TH1F *h1,TH1F *h2){
  /*
  * 传入2直方图 h1,h2
  */
  TPad *pad1 = new TPad("pad1","",0., 0.001, 0.499,0.999,10);
  TPad *pad2 = new TPad("pad2","",0.501, 0.001, 0.999,0.999,10);
  pad1->Draw();
  pad2->Draw();

  pad1->cd();
  h1->Draw();
  pad2->cd();
  h2->Draw();
}

void draw2TH1(TH1D *h1,TH1D *h2){
  /*
  * 传入2直方图 h1,h2
  */
  TPad *pad1 = new TPad("pad1","",0., 0.001, 0.499,0.999,10);
  TPad *pad2 = new TPad("pad2","",0.501, 0.001, 0.999,0.999,10);
  pad1->Draw();
  pad2->Draw();

  pad1->cd();
  h1->Draw();
  pad2->cd();
  h2->Draw();
}

void draw3H(TH1F *h1,TH1F *h2, TH2F *h12){
  /*
  * 输入3个直方图，h12可以是1维或2维
  */
  TPad *pad1 = new TPad("pad1","",0., 0.501, 0.499,0.999,10);
  TPad *pad2 = new TPad("pad2","",0., 0.001,   0.499,0.499,10);
  TPad *pad12 = new TPad("pad12","",0.501,.001,0.999,0.999,10);
  pad1->Draw();
  pad2->Draw();
  pad12->Draw();

  pad1->cd();
  h1->Draw();
  pad2->cd();
  h2->Draw();
  pad12->cd();
  h12->Draw("BOX");
}

void draw3H(TH1F *h1,TH1F *h2, TH2F *h12,Double_t h1L,Double_t h1R,Double_t h2L, Double_t h2R,Int_t iColor=2,const char* opt="Box"){
  /*
  * 输入3个直方图，h12可以是1维或2维, 
  * h1L,h1R 在图h1中画x1Left,x1right
  * h2L,h2R 在图h1中画x2Left,x2right
  * h12 在图h12中画（对应X轴）x1Left,x1right，（对应Y轴）x2Left,x2right
  * iColor 线条颜色
  * opt h12画图选项, 默认Box
  */
  TString options = ""; options += opt;
  TPad *pad1 = new TPad("pad1","",0., 0.501, 0.499,0.999,10);
  TPad *pad2 = new TPad("pad2","",0., 0.001,   0.499,0.499,10);
  TPad *pad12 = new TPad("pad12","",0.501,.001,0.999,0.999,10);
  pad1->Draw();
  pad2->Draw();
  pad12->Draw();

  pad1->cd();
  h1->Draw();
  pad1->Modified();
  pad1->Update();
  TLine *l1L = new TLine(h1L,pad1->GetUymin(),h1L,pad1->GetUymax());
  l1L->SetLineColor(iColor);
  l1L->Draw();
  TLine *l1R = new TLine(h1R,pad1->GetUymin(),h1R,pad1->GetUymax());
  l1R->SetLineColor(iColor);
  l1R->Draw();

  pad2->cd();
  h2->Draw();
  pad2->Modified();
  pad2->Update();
  TLine *l2L = new TLine(h2L,pad2->GetUymin(),h2L,pad2->GetUymax());
  l2L->SetLineColor(iColor);
  l2L->Draw();
  TLine *l2R = new TLine(h2R,pad2->GetUymin(),h2R,pad2->GetUymax());
  l2R->SetLineColor(iColor);
  l2R->Draw();

  pad12->cd();
  h12->Draw(options.Data());

  pad12->Modified();
  pad12->Update();
  TLine *l12L = new TLine(h1L,pad12->GetUymin(),h1L,pad12->GetUymax());
  l12L->SetLineColor(iColor);
  l12L->Draw();
  TLine *l12R = new TLine(h1R,pad12->GetUymin(),h1R,pad12->GetUymax());
  l12R->SetLineColor(iColor);
  l12R->Draw();

  TLine *l12U = new TLine(pad12->GetUxmin(),h2L,pad12->GetUxmax(),h2L);
  l12U->SetLineColor(iColor);
  l12U->Draw();
  TLine *l12D = new TLine(pad12->GetUxmin(),h2R,pad12->GetUxmax(),h2R);
  l12D->SetLineColor(iColor);
  l12D->Draw();
}

void draw3H(TH1D *h1,TH1D *h2, TH2D *h12){
  /*
  * 输入3个直方图，h12可以是1维或2维
  */
  TPad *pad1 = new TPad("pad1","",0., 0.501, 0.499,0.999,10);
  TPad *pad2 = new TPad("pad2","",0., 0.001,   0.499,0.499,10);
  TPad *pad12 = new TPad("pad12","",0.501,.001,0.999,0.999,10);
  pad1->Draw();
  pad2->Draw();
  pad12->Draw();

  pad1->cd();
  h1->Draw();
  pad2->cd();
  h2->Draw();
  pad12->cd();
  h12->Draw("BOX");
}

void draw3H(TH1D *h1,TH1D *h2, TH2D *h12,Double_t h1L,Double_t h1R,Double_t h2L, Double_t h2R,Int_t iColor=2,const char* opt="Box"){
  /*
  * 输入3个直方图，h12可以是1维或2维, 
  * h1L,h1R 在图h1中画x1Left,x1right
  * h2L,h2R 在图h1中画x2Left,x2right
  * h12 在图h12中画（对应X轴）x1Left,x1right，（对应Y轴）x2Left,x2right
  * iColor 线条颜色
  * opt h12画图选项, 默认Box
  */
  TString options = ""; options += opt;
  TPad *pad1 = new TPad("pad1","",0., 0.501, 0.499,0.999,10);
  TPad *pad2 = new TPad("pad2","",0., 0.001,   0.499,0.499,10);
  TPad *pad12 = new TPad("pad12","",0.501,.001,0.999,0.999,10);
  pad1->Draw();
  pad2->Draw();
  pad12->Draw();

  pad1->cd();
  h1->Draw();
  pad1->Modified();
  pad1->Update();
  TLine *l1L = new TLine(h1L,pad1->GetUymin(),h1L,pad1->GetUymax());
  l1L->SetLineColor(iColor);
  l1L->Draw();
  TLine *l1R = new TLine(h1R,pad1->GetUymin(),h1R,pad1->GetUymax());
  l1R->SetLineColor(iColor);
  l1R->Draw();

  pad2->cd();
  h2->Draw();
  pad2->Modified();
  pad2->Update();
  TLine *l2L = new TLine(h2L,pad2->GetUymin(),h2L,pad2->GetUymax());
  l2L->SetLineColor(iColor);
  l2L->Draw();
  TLine *l2R = new TLine(h2R,pad2->GetUymin(),h2R,pad2->GetUymax());
  l2R->SetLineColor(iColor);
  l2R->Draw();

  pad12->cd();
  h12->Draw(options.Data());

  pad12->Modified();
  pad12->Update();
  TLine *l12L = new TLine(h1L,pad12->GetUymin(),h1L,pad12->GetUymax());
  l12L->SetLineColor(iColor);
  l12L->Draw();
  TLine *l12R = new TLine(h1R,pad12->GetUymin(),h1R,pad12->GetUymax());
  l12R->SetLineColor(iColor);
  l12R->Draw();

  TLine *l12U = new TLine(pad12->GetUxmin(),h2L,pad12->GetUxmax(),h2L);
  l12U->SetLineColor(iColor);
  l12U->Draw();
  TLine *l12D = new TLine(pad12->GetUxmin(),h2R,pad12->GetUxmax(),h2R);
  l12D->SetLineColor(iColor);
  l12D->Draw();
}

void draw5H(TH1F *h1,TH1F *h2, TH1F *h3,TH1F *h4,TH1F *h5){

  TPad *pad1 = new TPad("pad1","",0.000, 0.501, 0.333,0.999,10);
  TPad *pad2 = new TPad("pad2","",0.333, 0.501, 0.666,0.999,10);

  //big pad3
  TPad *pad3 = new TPad("pad3","",0.666, 0.001, 0.999,0.999,10);

  TPad *pad1d = new TPad("pad1d","",0.000, 0.001, 0.333,0.499,10);
  TPad *pad2d = new TPad("pad2d","",0.333, 0.001, 0.666,0.499,10);


  pad1->Draw();
  pad2->Draw();
  pad3->Draw();

  pad1d->Draw();
  pad2d->Draw();



  pad1->cd();
  h1->Draw();
  pad2->cd();
  h2->Draw();
  pad3->cd();
  h3->Draw();
  pad1d->cd();
  h4->Draw();
  pad2d->cd();
  h5->Draw();

}

void draw5H(TH1D *h1,TH1D *h2, TH1D *h3,TH1D *h4,TH1D *h5){

  TPad *pad1 = new TPad("pad1","",0.000, 0.501, 0.333,0.999,10);
  TPad *pad2 = new TPad("pad2","",0.333, 0.501, 0.666,0.999,10);

  //big pad3
  TPad *pad3 = new TPad("pad3","",0.666, 0.001, 0.999,0.999,10);

  TPad *pad1d = new TPad("pad1d","",0.000, 0.001, 0.333,0.499,10);
  TPad *pad2d = new TPad("pad2d","",0.333, 0.001, 0.666,0.499,10);


  pad1->Draw();
  pad2->Draw();
  pad3->Draw();

  pad1d->Draw();
  pad2d->Draw();



  pad1->cd();
  h1->Draw();
  pad2->cd();
  h2->Draw();
  pad3->cd();
  h3->Draw();
  pad1d->cd();
  h4->Draw();
  pad2d->cd();
  h5->Draw();

}

void ShowContent(TH1 *h, Int_t itxtColor=kRed, Double_t txtSize=0.07, Double_t fangle=45,Bool_t NoZeroBin=kTRUE){
   // 显示直方图y轴值
   // itextColor 颜色
   // textsize 文字大小
   // fangle 旋转角度
   for(Int_t i=0; i<h->GetNbinsX();i++){
     Double_t x0 = h->GetBinCenter(i+1);
     Double_t y0 = h->GetBinContent(i+1);
    
     TLatex *ltx = new TLatex();
     ltx->SetNDC(kFALSE);
     ltx->SetTextColor(itxtColor);
     ltx -> SetTextFont(22);
     ltx->SetTextSize(txtSize);
     ltx->SetTextAngle(fangle);
     if(NoZeroBin ) {
       if(!(y0==0)) ltx->DrawLatex(x0,y0,Form("%.0f",y0));
     }else{
       if(!(y0==0)) ltx->DrawLatex(x0,y0,Form("%.0f",y0));
     }
   }
}

void ShowContent(TGraph *gr, Int_t itxtColor=kRed, Double_t txtSize=0.07, Double_t fangle=45,Bool_t NoZeroBin=kTRUE){
   // 显示graph的数据点y值
   // itextColor 颜色
   // textsize 文字大小
   // fangle 旋转角度
   for(Int_t i=0; i<gr->GetN();i++){
     Double_t x0,y0; 
     gr->GetPoint(i,x0,y0);
    
     TLatex *ltx = new TLatex();
     ltx->SetNDC(kFALSE);
     ltx->SetTextColor(itxtColor);
     ltx -> SetTextFont(22);
     ltx->SetTextSize(txtSize);
     ltx->SetTextAngle(fangle);
     if(NoZeroBin ) {
       if(!(y0==0)) ltx->DrawLatex(x0,y0,Form("%.2f",y0));
     }else{
       if(!(y0==0)) ltx->DrawLatex(x0,y0,Form("%.2f",y0));
     }
   }
}

TH1F *Create1DFHistogram(TString label, TString title, Int_t nbin, Double_t low, Double_t up, TString type = "")
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
  TH1F *theHisto;

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

    theHisto = new TH1F(label, title, nbin, bins);
  }
  else
    theHisto = new TH1F(label, title, nbin, low, up);
  return theHisto;
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


#endif
/* MYSTYLE.h ends here */
