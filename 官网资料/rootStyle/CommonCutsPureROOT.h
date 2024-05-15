#ifndef COMMONCUTSPUREROOT_H
#define COMMONCUTSPUREROOT_H
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
#include <TLorentzVector.h>
#include <TCanvas.h>
#include <TParticle.h>
#include <TClonesArray.h>
#include <TGraphErrors.h>
#include <TPad.h>
#include <vector>
#include <RooRealVar.h>
#include <TImage.h>
#include <TF1.h>
#include <TCutG.h>
#include <RooDataSet.h>
#include <TMath.h>
#include <TRandom3.h>

using namespace RooFit;

const Double_t PDGmassE = 0.510998928E-3;
const Double_t PDGmassP = 938.272046E-3;
const Double_t PDGmassN = 939.565379E-3;

const Double_t PDGKs0Mass = 0.497614;
const Double_t PDGKPlusMass = 0.493677;
const Double_t PDGPiPlusMass = 0.13957018;
const Double_t PDGKStar892PMMass = 0.89166;
const Double_t PDGKStar8920Mass = 0.896;
const Double_t PDGKChiC0Mass = 3.41476;
const Double_t PDGPi0Mass = 0.1349766;

Bool_t FillTH1F(Double_t fin, TH1 *histtmp,Double_t w=1.0){
  if(histtmp->GetXaxis()->GetXmin()<= fin && fin <histtmp->GetXaxis()->GetXmax()){
    histtmp->Fill(fin,w);
    return true;
  }else return false;
}

Bool_t FillTH1(Double_t fin, TH1 *histtmp,Double_t w=1.0){
  if(histtmp->GetXaxis()->GetXmin()<= fin && fin <histtmp->GetXaxis()->GetXmax()){
    histtmp->Fill(fin,w);
    return true;
  }else return false;
}

Bool_t FillTH1F(Float_t fin, TH1 *histtmp,Float_t w=1.0){
  if(histtmp->GetXaxis()->GetXmin()<= fin && fin <histtmp->GetXaxis()->GetXmax()){
    histtmp->Fill(fin,w);
    return true;
  }else return false;
}


Bool_t FillTH2F(Double_t finx,Double_t finy, TH2F *histtmp){
  if(!(histtmp->GetXaxis()->GetXmin()<= finx && finx <histtmp->GetXaxis()->GetXmax())) return false;
  if(!(histtmp->GetYaxis()->GetXmin()<= finy && finy <histtmp->GetYaxis()->GetXmax())) return false;
  histtmp->Fill(finx,finy);
  return true;
}

Bool_t FillTH3(Double_t finx,Double_t finy,Double_t finz, TH3 *histtmp){
  if(!(histtmp->GetXaxis()->GetXmin()<= finx && finx <histtmp->GetXaxis()->GetXmax())) return false;
  if(!(histtmp->GetYaxis()->GetXmin()<= finy && finy <histtmp->GetYaxis()->GetXmax())) return false;
  if(!(histtmp->GetZaxis()->GetXmin()<= finz && finz <histtmp->GetZaxis()->GetXmax())) return false;
  histtmp->Fill(finx,finy,finz);
  return true;
}

Bool_t FillTH3(Float_t finx,Float_t finy,Float_t finz, TH1 *histtmp){
  Double_t x = finx;
  Double_t y = finy;
  Double_t z = finz;
  return FillTH3(x,y,z,histtmp);
}

TCanvas* prepareCanvas(Char_t const name[]="c1",Int_t xL = 600,Int_t yL=400){
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
  //  Sty->SetStatW(0.5);
  // Sty->SetStatH(0.4);
  Sty->SetStatY(0.99);
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

void  prepareCanvasBigStat(){
  gROOT->SetStyle("Plain"); 
  delete gROOT->FindObject("c1");
  TCanvas *c1 = new TCanvas("c1","");
  c1->SetFillColor(10);
  c1->SetLeftMargin(0.12);
  c1->SetRightMargin(0.099);
  c1->SetTopMargin(0.05);

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
  Sty->SetOptStat(1110);
  Sty->SetStatFont(22);
  Sty->SetStatColor(10);
  Sty->SetCanvasColor(10);
  Sty->SetTitleColor(10,"title");
  Sty->SetFillColor(10);
  Sty->SetStatX(0.99);
  Sty->SetStatW(0.5);
  Sty->SetStatH(0.4);
  Sty->SetStatY(0.99);
  Sty->SetOptDate(11);

  Sty->cd();  
  gROOT->SetStyle("MyStyle");



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
    // gStyle->CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont); //root v.515 or before
  }
  gStyle->SetNumberContours(NCont);

 
  gROOT->ForceStyle();

  
  
}


void prepareCanvasV(){
  gROOT->SetStyle("Plain"); 
  delete gROOT->FindObject("c1");
  TCanvas *c1 = new TCanvas("c1","",0,0,600,720);
  c1->SetFillColor(10);
  c1->SetLeftMargin(0.12);
  c1->SetRightMargin(0.099);
  c1->SetTopMargin(0.05);

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
  Sty->SetOptStat(1110);
  Sty->SetStatFont(22);
  Sty->SetStatColor(10);
  Sty->SetCanvasColor(10);
  Sty->SetTitleColor(10,"title");
  Sty->SetTitleX(0.1);
  Sty->SetFillColor(10);
  Sty->SetStatX(0.99);
  Sty->SetStatW(0.43);
  Sty->SetStatH(0.2);
  Sty->SetStatY(0.99);
  Sty->SetOptDate(11);

  Sty->cd();  
  gROOT->SetStyle("MyStyle");



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
    // gStyle->CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont); //root v.515 or before
  }
  gStyle->SetNumberContours(NCont);

 
  gROOT->ForceStyle();

 
  
}


void prepareCanvasZoom1(){
  gROOT->SetStyle("Plain"); 
  delete gROOT->FindObject("c1");
  TCanvas *c1 = new TCanvas("c1","");
  c1->SetFillColor(0);
  c1->SetLeftMargin(0.12);
  c1->SetRightMargin(0.099);
  c1->SetTopMargin(0.05);
  c1->SetTickx(1);
  c1->SetTicky(1);

  TStyle *Sty = new TStyle("MyStyle","My Style");
  Sty->SetTitleFont(22,"xyz");
  Sty->SetTitleFont(22,"title");
  Sty->SetLabelFont(22,"X");
  Sty->SetLabelFont(22,"Y");
  Sty->SetOptStat(1110);
  Sty->SetStatFont(22);
  Sty->SetStatColor(10);
  Sty->SetCanvasColor(10);
  Sty->SetTitleColor(10,"title");
  Sty->SetFillColor(10);
  Sty->SetStatX(0.99);
  Sty->SetStatY(0.99);
  Sty->SetOptDate(11);

  Sty->SetOptTitle(1);
  Sty->SetOptStat(1);
  Sty->SetOptFit(0);

  // put tick marks on top and RHS of plots
  Sty->SetPadTickX(1);
  Sty->SetPadTickY(1);
  Sty->SetNdivisions(509); // default root value is 510


 
  gROOT->SetStyle("MyStyle");
  // return;

  //for more beautiful
  const Int_t NRGBs = 20;
  const Int_t NCont = 99;
  Double_t red[NRGBs]   = { 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.25,0.50, 0.75, 1.00, 1.00, 1.00, 0.95, 0.85, 0.70, 0.55, 0.30 }; 
  
  Double_t green[NRGBs] = { 0.00, 0.00, 0.00, 0.00, 0.00, 0.25, 0.50, 0.75, 1.00, 1.00,1.00, 1.00, 1.00, 0.85, 0.75, 0.50, 0.10, 0.00, 0.00, 0.00 }; 
  
  Double_t blue[NRGBs]  = { 0.30, 0.55, 0.70, 0.85, 0.95, 1.00, 1.00, 1.00, 1.00, 0.75, 0.25, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00 }; 
  
  Double_t stops[NRGBs] = { 0.00, 0.2, 0.4, 0.6, 0.80, 0.82, 0.84, 0.86, 0.88, 0.90, 0.91, 0.92, 0.93, 0.94, 0.95, 0.96, 0.97, 0.98, 0.99, 1.00 }; 

  /*   Double_t stops[NRGBs] = { 0.00, 0.90, 0.95, 0.98, 1.00 }; */
  /*   Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 }; */
  /*   Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 }; */
  /*   Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 }; */

  if(gROOT->GetVersionDate()>20090000){
    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont); //rootv5.16 or late
  }else{
    // gStyle->CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont); //root v.515 or before
  }
  gStyle->SetNumberContours(NCont);

  gROOT->ForceStyle();

  
}



Bool_t MassInRange(Double_t mass, Double_t LMass, Double_t HMass){
  if(mass<HMass && mass>LMass) return true;
  return false;
}

Bool_t MassInRange(Double_t mass, Double_t LMass[], Double_t HMass[],Int_t n){
  for(Int_t i=0; i<n; i++){
    if(mass<HMass[i] && mass>=LMass[i]) return true;
  }
  return false;
}

void LineY(Double_t atY, Int_t iColor=kRed,Char_t const canvasName[]="c1"){
  TCanvas *ctmp =(TCanvas *)gROOT->GetListOfCanvases()->FindObject(canvasName);
  if(ctmp){
    ctmp->Modified();
    ctmp->Update();
    TLine *l1 = new TLine(gPad->GetUxmin(),atY,gPad->GetUxmax(),atY);
    l1->SetLineColor(iColor);
    l1->Draw();
  }else{
    TLine *l1 = new TLine(gPad->GetUxmin(),atY,gPad->GetUxmax(),atY);
    l1->SetLineColor(iColor);
    l1->Draw();
  } 
}


void LineTH1FX(Double_t atX, Int_t iColor=kRed,Char_t const canvasName[]="c1"){
  TCanvas *ctmp =(TCanvas *)gROOT->GetListOfCanvases()->FindObject(canvasName);
  if(ctmp){
    ctmp->Modified();
    ctmp->Update();
    TLine *l1 = new TLine(atX,gPad->GetUymin(),atX,gPad->GetUymax());
    l1->SetLineColor(iColor);
    l1->Draw();
  }else{
    TLine *l1 = new TLine(atX,gPad->GetUymin(),atX,gPad->GetUymax());
    l1->SetLineColor(iColor);
    l1->Draw();
  } 
}

void LineX1(Double_t atX,Int_t iColor=kRed,Int_t iStyle=1,Double_t iWidth=1){
  gPad->Modified();
  gPad->Update();
  TLine *l1 = new TLine(atX,gPad->GetUymin(),atX,gPad->GetUymax());
  l1->SetLineColor(iColor);
  l1->SetLineStyle(iStyle);
  l1->SetLineWidth((Width_t)iWidth);
  l1->Draw();
  
}

void LineY1(Double_t atY,Int_t iColor=kRed,Int_t iStyle=1,Double_t iWidth=1){
  gPad->Modified();
  gPad->Update();
  TLine *l1 = new TLine(gPad->GetUxmin(),atY,gPad->GetUxmax(),atY);
  l1->SetLineColor(iColor);
  l1->SetLineStyle(iStyle);
  l1->SetLineWidth((Width_t)iWidth);
  l1->Draw();
  
}

void LineX(Double_t atX, Int_t iColor=kRed,Char_t const canvasName[]="c1"){
  TCanvas *ctmp =(TCanvas *)gROOT->GetListOfCanvases()->FindObject(canvasName);
  if(ctmp){
    ctmp->Modified();
    ctmp->Update();
    TLine *l1 = new TLine(atX,gPad->GetUymin(),atX,gPad->GetUymax());
    l1->SetLineColor(iColor);
    l1->Draw();
  }else{
    gPad->Modified();
    gPad->Update();
    TLine *l1 = new TLine(atX,gPad->GetUymin(),atX,gPad->GetUymax());
    l1->SetLineColor(iColor);
    l1->Draw();
  } 
}

void LineX(Double_t atX, Int_t iColor=kRed,Double_t LineW=0.02,Char_t const canvasName[]="c1"){
  TCanvas *ctmp =(TCanvas *)gROOT->GetListOfCanvases()->FindObject(canvasName);
  if(ctmp){
    ctmp->Modified();
    ctmp->Update();
    TLine *l1 = new TLine(atX,gPad->GetUymin(),atX,gPad->GetUymax());
    l1->SetLineColor(iColor);
    l1->SetLineWidth(TMath::Nint(LineW));
    l1->Draw();
  }else{
    TLine *l1 = new TLine(atX,gPad->GetUymin(),atX,gPad->GetUymax());
    l1->SetLineColor(iColor);
    l1->SetLineWidth(TMath::Nint(LineW));
    l1->Draw();
  } 
}

void LineTH1FX(TH1F *hist,Double_t atX, Int_t iColor=kRed,Char_t const canvasName[]="c1"){
  printf("draw Line at %.1f on %s\n",atX,hist->GetName());
  TCanvas *ctmp =(TCanvas *)gROOT->GetListOfCanvases()->FindObject(canvasName);
  if(ctmp){
    ctmp->Modified();
    ctmp->Update();
    TLine *l1 = new TLine(atX,gPad->GetUymin(),atX,gPad->GetUymax());
    l1->SetLineColor(iColor);
    l1->Draw();
  }else{
    TLine *l1 = new TLine(atX,gPad->GetUymin(),atX,gPad->GetUymax());
    l1->SetLineColor(iColor);
    l1->Draw();
  } 
}


void LineTH1FX(TH1F *hist,Double_t atX, Char_t canvasName[]){
  LineTH1FX(hist,atX,kRed,canvasName);
}
void LineTH1FX(TH1F *hist,Double_t atX, TCanvas *c1){
  Char_t str[100];
  sprintf(str,"%s",c1->GetName());
  LineTH1FX(hist,atX,kRed,str);
}

void DrawText(Double_t posX = 0., Double_t posY = 0., const char* text = "",
	      Double_t size=0.08, Int_t col=1
	      //                      Int_t align=0, Double_t angle=0.,
	      //                      Int_t font, Bool_t bNDC=kTRUE
	      )
{
  // Drawing some text

  TLatex* pText=new TLatex(posX,posY,text);
  pText->SetNDC(kTRUE);
  //   pText->SetNDC(bNDC);
  pText->SetTextColor(col); pText->SetTextSize(size);
  //   pText->SetTextAngle(angle);
  //   pText->SetTextFont(font); pText->SetTextAlign(align);
  pText->Draw();
}

void DrawNice2DHisto(TH2* h,const char* opt="",double range = 10.)
{
  // Draw a 2D histo with the rainbow colors and the palette besides
  TString options = "colz"; options += opt;
  if(gPad->GetLogz() == 0 && h->GetMaximum()<range) h->SetAxisRange(0.,range,"Z");
  h->SetStats(kFALSE);
  h->SetTitleOffset(0.8,"T");
  gPad->SetRightMargin(0.16);
  h->DrawCopy(options.Data());
}

void set_nicer_2d_plot_style()
{
  const Int_t NRGBs = 5;
  const Int_t NCont = 255;

  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
  if(gROOT->GetVersionDate()>20090000){
    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont); //rootv5.16 or late
  }else{
    //gStyle->CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont); //root v.515 or before
  }

  //    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  //     gStyle->CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  gStyle->SetNumberContours(NCont);
}

void BetterStatBox( TPad* pad ){
  /// Vorgehensweise:
  /// * Histogramme in ein TPad zeichnen (1. Histogramm: Draw(), ntes Histogramm:
  ///   Draw("sames"))
  /// * die Update() Funktion vom Canvas aufrufen (die Statistikboxen werden erst
  ///   erzeugt, wenn das Histogramm wirklich gezeichnet wird)
  /// * der Funktion das aktuelle TPad uebergeben
  ///   (z.B.: TPad* p=(TPad*)gPad; BetterStatBox(p);)

  int entries  = pad->GetListOfPrimitives()->GetEntries();
  TString name = "";
  TPaveStats *st;
  int obj = 1;

  for(int i=0; i<entries; i++){
    name = pad->GetListOfPrimitives()->At(i)->IsA()->GetName();
    if( name.Contains("TH1") ){
      TH1* hist = (TH1*)pad->GetListOfPrimitives()->At(i);
      st = (TPaveStats*)hist->GetListOfFunctions()->FindObject("stats");
      if(st){
        st->SetOptStat(1);
        st->SetX1NDC(0.80);
        st->SetY1NDC(1-0.16*obj) ;
        st->SetY2NDC( st->GetY1NDC()+0.15 ) ;
        st->SetTextColor( hist->GetLineColor() );
        st->SetLineColor( hist->GetLineColor() );
        st->Draw("same");
        obj++;
      }
    }
  }
}

// TLegend* BuildLegend_THStack( THStack* stack, float x1, float y1, float x2, float y2 ){
//
//   TLegend* legend = new TLegend(x1,y1,x2,y2);
//   TList*   list = stack->GetHists();
//   TIter    next( list );
//   TH1*     hist;
//
//   while ( hist = (TH1*)next() ) legend->AddEntry(hist,"","F");
//
//   return legend;
// }

void LoadPandaStyle(void)
{

  //--------------------------------------------------------------------------
  // File and Version Information:
  //      $Id: PBase.C,v 1.8 2006/09/22 12:04:13 kliemt Exp $
  //
  // Description:
  //      Initialization code executed at the start of a ROOT session.
  //      Set up the Panda style for approved plots.
  //
  // Environment:
  //      Software developed for the PANDA Detector at GSI, Darmstadt
  //
  // Author List:
  //      Sergey Ganzhur                Original Author
  //
  // Copyright Information:
  //     Copyright (C) 2001-2002        Ruhr Universitaet Bochum
  //
  //------------------------------------------------------------------------

  // use the 'plain' style for plots (white backgrounds, etc)
  //cout << "...using style 'Plain'" << endl;
  gROOT->SetStyle("Plain");

  // Create the 'PANDA' style for approved plots. Note that this style may need
  // some fine tuning in your macro depending on what you are plotting, e.g.
  //
  //  gStyle->SetMarkerSize(0.75);  // use smaller markers in a histogram with many bins
  //  gStyle->SetTitleOffset(0.65,"y");  // bring y axis label closer to narrow values


  // Ralf Kliemt:
  // Ok I changed a bit for myself here


  TStyle *pandaStyle= new TStyle("PANDA","PANDA approved plots style");

  // use plain black on white colors
  pandaStyle->SetFrameBorderMode(0);
  pandaStyle->SetCanvasBorderMode(0);
  pandaStyle->SetPadBorderMode(0);
  pandaStyle->SetPadColor(0);
  pandaStyle->SetCanvasColor(0);
  pandaStyle->SetTitleColor(1);
  pandaStyle->SetStatColor(0);
  //   pandaStyle->SetFillColor(0);// conflict with 2D plots
  //   pandaStyle->SetPalette(1);

  // set the paper & margin sizes
  pandaStyle->SetPaperSize(20,26);
  pandaStyle->SetPadTopMargin(0.05);
  pandaStyle->SetPadRightMargin(0.05);
  pandaStyle->SetPadBottomMargin(0.1);
  pandaStyle->SetPadLeftMargin(0.12);

  // use large Times-Roman fonts
  /*   pandaStyle->SetTextFont(132); */
  /*   pandaStyle->SetLabelFont(132,"x"); */
  /*   pandaStyle->SetLabelFont(132,"y"); */
  /*   pandaStyle->SetLabelFont(132,"z"); */
  pandaStyle->SetTextFont(22);//changed to bold (R.K.)
  pandaStyle->SetTextSize(0.08);
  pandaStyle->SetLabelFont(22,"x");//changed to bold (R.K.)
  pandaStyle->SetLabelFont(22,"y");//changed to bold (R.K.)
  pandaStyle->SetLabelFont(22,"z");//changed to bold (R.K.)
  pandaStyle->SetLabelSize(0.05,"x");
  pandaStyle->SetTitleSize(0.06,"x");
  pandaStyle->SetLabelSize(0.05,"y");
  pandaStyle->SetTitleSize(0.06,"y");
  pandaStyle->SetLabelSize(0.05,"z");
  pandaStyle->SetTitleSize(0.06,"z");

  // use bold lines and markers
  pandaStyle->SetMarkerStyle(8);
  pandaStyle->SetHistLineWidth(2);//1.85);
  pandaStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes

  // do not display any of the standard histogram decorations
  pandaStyle->SetOptTitle(1);
  pandaStyle->SetOptStat(1);
  pandaStyle->SetOptFit(0);

  // put tick marks on top and RHS of plots
  pandaStyle->SetPadTickX(1);
  pandaStyle->SetPadTickY(1);

  //R.K. avoid clumsy axis lables
  pandaStyle->SetNdivisions(509); // default root value is 510

  //cout <<"    For approved plots use: gROOT->SetStyle(\"PANDA\");"<< endl;
  //  pandaStyle->SetOptDate(11);
  pandaStyle->cd();
  
  gROOT->ForceStyle();
  set_nicer_2d_plot_style();//[R.K.] use nicer 2D plots

}//void PBase::LoadPandaStyle(void)


Double_t GetVR(TVector3 VTrk, TVector3 VBeamPos){
  Double_t fVRX = VTrk.X() - VBeamPos.X();
  Double_t fVRY = VTrk.Y() - VBeamPos.Y();
  return TMath::Sqrt(fVRX*fVRX + fVRY*fVRY);
}

Double_t GetVZ(TVector3 VTrk, TVector3 VBeamPos){
  return VTrk.Z() - VBeamPos.Z();
}

Bool_t InVR(TVector3 VTrk, TVector3 VBeamPos,Double_t fCut){
  Double_t fR = GetVR(VTrk, VBeamPos);
  if( fR<= fCut) return kTRUE;
  else return kFALSE;
}

Bool_t InVZ(TVector3 VTrk, TVector3 VBeamPos,Double_t fCut){
  Double_t fZ = GetVZ(VTrk, VBeamPos);
  if( TMath::Abs(fZ) <= fCut) return kTRUE;
  else return kFALSE;
}

Double_t GetVR(TVector3 VTrk){
  return VTrk.Pt();
}

Double_t GetVZ(TVector3 VTrk){
  return VTrk.Z();
}

Bool_t InVR(TVector3 VTrk,Double_t fCut){
  Double_t fR = GetVR(VTrk);
  if( fR<= fCut) return kTRUE;
  else return kFALSE;
}

Bool_t InVZ(TVector3 VTrk,Double_t fCut){
  Double_t fZ = GetVZ(VTrk);
  if( TMath::Abs(fZ) <= fCut) return kTRUE;
  else return kFALSE;
}

Bool_t IsInRange(Double_t Val, Double_t RangeL, Double_t RangeH){
  return (Val<RangeH && Val>RangeL)? kTRUE:kFALSE;
}
Bool_t IsInRange(Double_t Val, Double_t fRange){
  return (Val< fRange && Val>-fRange)? kTRUE:kFALSE;
}

Bool_t IsInRange(Double_t Val, Double_t RangeL, Double_t RangeH,Double_t Obs,TH1 *hValAll,TH1 *hValPass,TH1 *hObsAll, TH1 *hObsPass, TH1 *hObsFall){
  Bool_t judge = (Val<RangeH && Val>RangeL)? kTRUE:kFALSE;
  FillTH1F(Val,hValAll);
  FillTH1F(Obs,hObsAll);
  if(judge){
    FillTH1F(Val,hValPass);
    FillTH1F(Obs,hObsPass);
  }else{
    FillTH1F(Obs,hObsFall);
  }
  return judge;
}


Double_t GetMassInClonesArray(Int_t j, TClonesArray *pclone){
  TLorentzVector *pLV = (TLorentzVector *)pclone->At(j);
  return pLV->M();
}
Double_t GetMassInClonesArrayTPartile(Int_t j, TClonesArray *pclone){
  TParticle *part1 = (TParticle *)pclone->At(j);
  TLorentzVector LVtmp;
  part1 -> Momentum(LVtmp);
  return LVtmp.M();
}

Double_t GetRecMassInClonesArrayTPartile(Int_t j, TClonesArray *pclone1,TClonesArray *pclone2){
  TParticle *part1 = (TParticle *)pclone1->At(j);
  TLorentzVector LVtmp1;
  part1 -> Momentum(LVtmp1);

  TParticle *part2 = (TParticle *)pclone2->At(j);
  TLorentzVector LVtmp2;
  part2 -> Momentum(LVtmp2);
  TLorentzVector LVtmp12 = LVtmp1 + LVtmp2;
  return LVtmp12.M();
}


TLorentzVector GetRec4MomentumForceInvMass1InClonesArrayTPartile(Int_t j, TClonesArray *pclone1,Double_t forceMass,TClonesArray *pclone2){
  TParticle *part1 = (TParticle *)pclone1->At(j);
  TLorentzVector LVtmp1;
  part1 -> Momentum(LVtmp1);
  TLorentzVector LVtmp1ChangeMass;
  LVtmp1ChangeMass.SetXYZM(LVtmp1.Px(),LVtmp1.Py(),LVtmp1.Pz(),forceMass);

  TParticle *part2 = (TParticle *)pclone2->At(j);
  TLorentzVector LVtmp2;
  part2 -> Momentum(LVtmp2);
  TLorentzVector LVtmp12 = LVtmp1ChangeMass + LVtmp2;
  return LVtmp12;
}

TLorentzVector GetLVInClonesArrayTPartile(Int_t j, TClonesArray *pclone1){
  TParticle *part1 = (TParticle *)pclone1->At(j);
  TLorentzVector LVtmp1;
  part1 -> Momentum(LVtmp1);
  return LVtmp1;
}


TLorentzVector GetRec4MomentumForceInvMass12InClonesArrayTPartile(Int_t j, TClonesArray *pclone1,Double_t forceMass1,TClonesArray *pclone2,Double_t forceMass2){
  TParticle *part1 = (TParticle *)pclone1->At(j);
  TLorentzVector LVtmp1;
  part1 -> Momentum(LVtmp1);
  TLorentzVector LVtmp1ChangeMass1;
  LVtmp1ChangeMass1.SetXYZM(LVtmp1.Px(),LVtmp1.Py(),LVtmp1.Pz(),forceMass1);

  TParticle *part2 = (TParticle *)pclone2->At(j);
  TLorentzVector LVtmp2;
  part2 -> Momentum(LVtmp2);
  TLorentzVector LVtmp2ChangeMass2;
  LVtmp2ChangeMass2.SetXYZM(LVtmp2.Px(),LVtmp2.Py(),LVtmp2.Pz(),forceMass2);


  TLorentzVector LVtmp12 = LVtmp1ChangeMass1 + LVtmp2ChangeMass2;
  return LVtmp12;
}

Double_t GetRecMassForceInvMass12InClonesArrayTPartile(Int_t j, TClonesArray *pclone1,Double_t forceMass1,TClonesArray *pclone2,Double_t forceMass2){
  TLorentzVector LVtmp = GetRec4MomentumForceInvMass12InClonesArrayTPartile(j,pclone1,forceMass1,pclone2,forceMass2);
  return LVtmp.M();
}


Double_t GetRecMassForceInvMass1InClonesArrayTPartile(Int_t j, TClonesArray *pclone1,Double_t forceMass,TClonesArray *pclone2){
  TLorentzVector LVtmp = GetRec4MomentumForceInvMass1InClonesArrayTPartile(j,pclone1,forceMass,pclone2);
  return LVtmp.M();
}

Int_t GetPdgCodeInClonesArrayTPartile(Int_t j, TClonesArray *pclone){
  if(j>=pclone->GetEntries()) {
    printf("Error: nEntries=%d but you want the idx=%d\n",pclone->GetEntries(),j);
    return -999;
  }
  TParticle *part1 = (TParticle *)pclone->At(j);  
  return part1->GetPdgCode();
}

Double_t GetMassIn2ClonesArray(Int_t j, TClonesArray *pclone1, TClonesArray *pclone2){
  TLorentzVector *pLV1 = (TLorentzVector *)pclone1->At(j);
  TLorentzVector *pLV2 = (TLorentzVector *)pclone2->At(j);
  TLorentzVector pLV12 = (*pLV1) + (*pLV2);
  return pLV12.M();
}

Double_t GetPtInClonesArray(Int_t j, TClonesArray *pclone){
  TLorentzVector *pLV = (TLorentzVector *)pclone->At(j);
  return pLV->Pt();
}
Double_t GetPtInClonesArrayTParticle(Int_t j, TClonesArray *pclone){
  TParticle *part1 = (TParticle *)pclone->At(j);
  return part1->Pt();
}
Double_t GetPzInClonesArrayTParticle(Int_t j, TClonesArray *pclone){
  TParticle *part1 = (TParticle *)pclone->At(j);
  return part1->Pz();
}

TLorentzVector GetTotaMomentumInClonesArrayTParticle(Int_t j, TClonesArray *pclone1,TClonesArray *pclone2,TClonesArray *pclone3){
  TParticle *part1 = (TParticle *)pclone1->At(j);
  TLorentzVector LVtmp1;
  part1->Momentum(LVtmp1);
  TParticle *part2 = (TParticle *)pclone2->At(j);
  TLorentzVector LVtmp2;
  part2->Momentum(LVtmp2);
  TParticle *part3 = (TParticle *)pclone3->At(j);
  TLorentzVector LVtmp3;
  part3->Momentum(LVtmp3);

  return LVtmp1 + LVtmp2 + LVtmp3;
}

TLorentzVector GetTotalMomentumInClonesArrayTParticle(Int_t j, TClonesArray *pclone1,Double_t fMass1,TClonesArray *pclone2,TClonesArray *pclone3){
  TParticle *part1 = (TParticle *)pclone1->At(j);
  TLorentzVector LVtmp1p;
  part1->Momentum(LVtmp1p);
  TLorentzVector LVtmp1;
  LVtmp1.SetXYZM(LVtmp1p.Px(),LVtmp1p.Py(),LVtmp1p.Pz(),fMass1);

  TParticle *part2 = (TParticle *)pclone2->At(j);
  TLorentzVector LVtmp2;
  part2->Momentum(LVtmp2);
  TParticle *part3 = (TParticle *)pclone3->At(j);
  TLorentzVector LVtmp3;
  part3->Momentum(LVtmp3);

  return LVtmp1 + LVtmp2 + LVtmp3;
}

Double_t GetPInClonesArrayTParticle(Int_t j, TClonesArray *pclone){
  TParticle *part1 = (TParticle *)pclone->At(j);
  return part1->P();
}

Double_t GetCosThetaInClonesArray(Int_t j, TClonesArray *pclone){
  if(j<pclone->GetEntries()){
    TLorentzVector *pLV = (TLorentzVector *)pclone->At(j);
    return pLV->CosTheta();
  }else{
    printf("In GetCosThetaInClonesArray Error: Nentry=%d but j=%d\n",pclone->GetEntries(),j);
    return -999;
  }
}
Double_t GetCosThetaInClonesArrayTParticle(Int_t j, TClonesArray *pclone){
  if(j<pclone->GetEntries()){
    TParticle *part1 = (TParticle *)pclone->At(j);
    TLorentzVector LVtmp;
    part1->Momentum(LVtmp);
    //return LVtmp.Pz()/LVtmp.P();
    return LVtmp.CosTheta();
  }else{
    printf("In GetCosThetaInClonesArrayTParticle(Int_t j, TClonesArray *pclone) Error: Nentry=%d but j=%d\n",pclone->GetEntries(),j);
    return -999;
  }
}

Double_t GetCosThetaOf2TrackInClonesArrayTParticle(Int_t j, TClonesArray *pclone1 , TClonesArray *pclone2){
  if(j<pclone1->GetEntries()){
    TParticle *part1 = (TParticle *)pclone1->At(j);
    TLorentzVector LVtmp1;
    part1->Momentum(LVtmp1);

    TParticle *part2 = (TParticle *)pclone2->At(j);
    TLorentzVector LVtmp2;
    part2->Momentum(LVtmp2);
    return TMath::Cos( LVtmp1.Angle(LVtmp2.Vect()));

  }else{
    printf("In GetCosThetaOf2TrackInClonesArrayTParticle(Int_t j, TClonesArray *pclone1 , TClonesArray *pclone2)\n");
    return -999;
  }
}

Double_t GetCosThetaOf2TLorentzVector(TLorentzVector *lv1, TLorentzVector *lv2){
  return TMath::Cos( lv1->Angle(lv2->Vect()));
}


Double_t GetCosThetaOf2TrackInClonesArrayTParticle(Int_t j, TClonesArray *pclone1 , TLorentzVector *LVtmp2){
  if(j<pclone1->GetEntries()){
    TParticle *part1 = (TParticle *)pclone1->At(j);
    TLorentzVector LVtmp1;
    part1->Momentum(LVtmp1);

    return TMath::Cos( LVtmp1.Angle(LVtmp2->Vect()));

  }else{
    printf("In GetCosThetaOf2TrackInClonesArrayTParticle(Int_t j, TClonesArray *pclone1 , TClonesArray *pclone2)\n");
    return -999;
  }
}

Double_t GetRInClonesArray(Int_t j, TClonesArray *pclone){
  TVector3 *pV = (TVector3 *)pclone->At(j);
  return pV->Perp();
}

Double_t GetRInClonesArrayTParticle(Int_t j, TClonesArray *pclone){
  TParticle *part = (TParticle *)pclone->At(j);
  TLorentzVector LVpro;
  part->ProductionVertex(LVpro);
  TVector3 LVpro3 = LVpro.Vect();
  return LVpro3.Perp();
}

Double_t GetVyInClonesArrayTParticle(Int_t j, TClonesArray *pclone){
  TParticle *part = (TParticle *)pclone->At(j);
  TLorentzVector LVpro;
  part->ProductionVertex(LVpro);
  return LVpro.Y();
}

Double_t GetVxInClonesArrayTParticle(Int_t j, TClonesArray *pclone){
  TParticle *part = (TParticle *)pclone->At(j);
  TLorentzVector LVpro;
  part->ProductionVertex(LVpro);
  return LVpro.X();
}

Double_t GetRInClonesArrayTParticle(Int_t j, TClonesArray *pclone,TVector3 BeamV){
  TParticle *part = (TParticle *)pclone->At(j);
  TLorentzVector LVpro;
  part->ProductionVertex(LVpro);
  TVector3 LVpro3 = LVpro.Vect() - BeamV;
  return LVpro3.Perp();
}
Double_t GetZInClonesArrayTParticle(Int_t j, TClonesArray *pclone){
  TParticle *part = (TParticle *)pclone->At(j);
  TLorentzVector LVpro;
  part->ProductionVertex(LVpro);
  TVector3 LVpro3 = LVpro.Vect();
  return LVpro3.Z();
}

Double_t GetZInClonesArrayTParticle(Int_t j, TClonesArray *pclone,TVector3 BeamV){
  TParticle *part = (TParticle *)pclone->At(j);
  TLorentzVector LVpro;
  part->ProductionVertex(LVpro);
  TVector3 LVpro3 = LVpro.Vect() - BeamV;
  return LVpro3.Z();
}

Double_t GetDeltaRInClonesArray(Int_t j, TClonesArray *pclone1,TClonesArray *pclone2){
  TVector3 *pV1 = (TVector3 *)pclone1->At(j);
  TVector3 *pV2 = (TVector3 *)pclone2->At(j);
  Double_t x1 = pV1->X();
  Double_t y1 = pV1->Y();
  Double_t x2 = pV2->X();
  Double_t y2 = pV2->Y();
  Double_t xx12 = x1 - x2;
  Double_t yy12 = y1 - y2;
  return TMath::Sqrt(xx12 * xx12   +  yy12 * yy12);
}

Double_t GetZInClonesArray(Int_t j, TClonesArray *pclone){
  TVector3 *pV = (TVector3 *)pclone->At(j);
  return pV->Z();
}


TH1I * newTH1I(Char_t const name[]="h1",Double_t binw=0.01, Double_t LowBin=0.0, Double_t HighBin=3.0,Bool_t MevTitle = kTRUE,Int_t iMode=-1){
  Int_t nbin = TMath::Nint( (HighBin - LowBin)/binw );
  HighBin = binw*nbin + LowBin;
 
  TH1I *h = new TH1I(name,"",nbin,LowBin,HighBin);
  if(MevTitle) h->GetYaxis()->SetTitle(Form("Events / (%.0fMeV/c^{2})",h->GetBinWidth(1)*1000));
  h->SetMinimum(0.0);
  h->GetYaxis()->SetTitleOffset(1.1);
  if(iMode>=0 && iMode<14){
    Int_t iMarker[] = {20,21,24,25,28,29,30,27,3,  5,2, 26,22,23};
    Int_t iColor[]  = { 2, 4, 6, 9, 1,50,40,31,41,35,44,38,47,12};
    h ->SetMarkerStyle(iMarker[iMode]);
    h ->SetMarkerColor(iColor[iMode]);
    h ->SetLineColor(iColor[iMode]);
  }

  return h;
}
TH1F * newTH1F(Char_t const name[]="h1",Double_t binw=0.01, Double_t LowBin=0.0, Double_t HighBin=3.0,Bool_t MevTitle = kTRUE,Int_t iMode=-1){
  Int_t nbin = TMath::Nint( (HighBin - LowBin)/binw );
  HighBin = binw*nbin + LowBin;
 
  TH1F *h = new TH1F(name,"",nbin,LowBin,HighBin);
  if(MevTitle) h->GetYaxis()->SetTitle(Form("Events / (%.0fMeV/c^{2})",h->GetBinWidth(1)*1000));
  h->SetMinimum(0.0);
  h->GetYaxis()->SetTitleOffset(1.1);
  if(iMode>=0 && iMode<14){
    Int_t iMarker[] = {20,21,24,25,28,29,30,27,3,  5,2, 26,22,23};
    Int_t iColor[]  = { 2, 4, 6, 9, 1,50,40,31,41,35,44,38,47,12};
    h ->SetMarkerStyle(iMarker[iMode]);
    h ->SetMarkerColor(iColor[iMode]);
    h ->SetLineColor(iColor[iMode]);
  }

  return h;
}

TH1D * newTH1D(Char_t const name[]="h1",Double_t binw=0.01, Double_t LowBin=0.0, Double_t HighBin=3.0,Bool_t MevTitle = kTRUE,Int_t iMode=-1){
  Int_t nbin = TMath::Nint( (HighBin - LowBin)/binw );
  HighBin = binw*nbin + LowBin;
 
  TH1D *h = new TH1D(name,"",nbin,LowBin,HighBin);
  if(MevTitle) h->GetYaxis()->SetTitle(Form("Events / (%.0fMeV/c^{2})",h->GetBinWidth(1)*1000));
  h->SetMinimum(0.0);
  h->GetYaxis()->SetTitleOffset(1.1);
  if(iMode>=0 && iMode<14){
    Int_t iMarker[] = {20,21,24,25,28,29,30,27,3,  5,2, 26,22,23};
    Int_t iColor[]  = { 2, 4, 6, 9, 1,50,40,31,41,35,44,38,47,12};
    h ->SetMarkerStyle(iMarker[iMode]);
    h ->SetMarkerColor(iColor[iMode]);
    h ->SetLineColor(iColor[iMode]);
  }

  return h;
}


TH2F * newTH2F(Char_t const name[]="h2",TH1F *hx = 0,TH1F *hy = 0){
  if(hx == NULL){
    printf("TH2F %s not created since hx==NULL\n",name);
    return NULL;
  }
  if(hy == NULL){
    printf("TH2F %s not created since hy==NULL\n",name);
    return NULL;
  }

  Int_t nbinx = hx->GetXaxis()->GetNbins();
  Double_t xLow  = hx->GetXaxis()->GetXmin();
  Double_t xHigh  = hx->GetXaxis()->GetXmax();
  Int_t nbiny = hy->GetXaxis()->GetNbins();
  Double_t yLow  = hy->GetXaxis()->GetXmin();
  Double_t yHigh  = hy->GetXaxis()->GetXmax();

  TH2F *h2 = new TH2F(name,"",nbinx,xLow,xHigh,nbiny,yLow,yHigh);
  h2->SetTitle(Form(";%s;%s",hx->GetName(),hy->GetName()));
  return h2;
}

TH2F * newTH2F(Char_t name[],Double_t binwX,Double_t lbinX,Double_t hbinX,Double_t binwY,Double_t lbinY,Double_t hbinY){

  Int_t nbinx = TMath::Nint( (hbinX-lbinX)/binwX );
  Double_t xLow  = lbinX;
  Double_t xHigh  = xLow + nbinx * binwX;

  Int_t nbiny = TMath::Nint( (hbinY-lbinY)/binwY );
  Double_t yLow  = lbinY;
  Double_t yHigh  = yLow +  nbiny * binwY;

  TH2F *h2 = new TH2F(name,"",nbinx,xLow,xHigh,nbiny,yLow,yHigh);
  return h2;
}





TH2D * newTH2D(Char_t name[],Char_t const title[],Double_t binwX,Double_t binLX,Double_t binHX,Double_t binwY,Double_t binLY,Double_t binHY){
  Int_t nbinX = TMath::Nint( (binHX-binLX)/binwX );
  Double_t xLow  = binLX;
  Double_t xHigh  = xLow + nbinX * binwX;

  Int_t nbinY = TMath::Nint( (binHY-binLY)/binwY );
  Double_t yLow  = binLY;
  Double_t yHigh  = yLow + nbinY * binwY;
  //  printf("%d %.2f %.2f     %d %.2f %.2f\n",nbinX,xLow,xHigh,nbinY,yLow,yHigh);
  TH2D *h2 = new TH2D(name,title,nbinX,xLow,xHigh,nbinY,yLow,yHigh);
  return h2;
}

TH2D * newTH2D(Char_t  name[],Double_t binwX,Double_t binLX,Double_t binHX,Double_t binwY,Double_t binLY,Double_t binHY){
  return newTH2D(name,"",binwX,binLX,binHX,binwY,binLY,binHY);
}


Double_t GetR_VertexToIP(Int_t j, TClonesArray *pclone,TVector3 *IP){
  TParticle *part1 = (TParticle *) pclone->At(j);
  TLorentzVector LVPos;
  part1->ProductionVertex(LVPos);
  TVector3 VDecay(LVPos.X(),LVPos.Y(),LVPos.Z());
  return (VDecay - (*IP)).Pt();
}
Double_t GetZ_VertexToIP(Int_t j, TClonesArray *pclone,TVector3 *IP){
  TParticle *part1 = (TParticle *) pclone->At(j);
  TLorentzVector LVPos;
  part1->ProductionVertex(LVPos);
  TVector3 VDecay(LVPos.X(),LVPos.Y(),LVPos.Z());
  return (VDecay - (*IP)).Z();
}
Double_t GetZ_Vertex(Int_t j, TClonesArray *pclone,Double_t ShiftZ=0){
  TParticle *part1 = (TParticle *) pclone->At(j);
  TLorentzVector LVPos;
  part1->ProductionVertex(LVPos);
  return LVPos.Z() - ShiftZ;
}
Double_t GetX_Vertex(Int_t j, TClonesArray *pclone,Double_t ShiftX=0){
  TParticle *part1 = (TParticle *) pclone->At(j);
  TLorentzVector LVPos;
  part1->ProductionVertex(LVPos);
  return LVPos.X() - ShiftX;
}
Double_t GetY_Vertex(Int_t j, TClonesArray *pclone,Double_t ShiftY=0){
  TParticle *part1 = (TParticle *) pclone->At(j);
  TLorentzVector LVPos;
  part1->ProductionVertex(LVPos);
  return LVPos.Y() - ShiftY;
}

Int_t PdgCode2Num(Int_t pdg){
 
  switch(pdg){
  case 22: return 0; break;
  case -11 : return 1; break;
  case 11 : return -1; break;
  case -13 : return 2; break;
  case 13 : return -2; break;
  case 211 : return 3; break;
  case -211 : return -3; break;
  case 321 : return 4; break;
  case -321 : return -4; break;
  case 2212 : return 5; break;
  case -2212 : return -5; break;
  default: return -999; break; 
  }

}

void txt(Double_t x0=0.3, Double_t y0=0.3,Char_t const txts[]="",Int_t iColor=2,Double_t fSize=0.06,Bool_t IsNDC=kTRUE){
  TLatex *ltx = new TLatex();
  ltx->SetNDC(IsNDC);
  if(!(x0>=0 && x0<=1 && y0>=0 && y0<=1) ) ltx->SetNDC(kFALSE);
  ltx->SetTextColor(iColor);
  ltx -> SetTextFont(22);
  ltx->SetTextSize(fSize);
  ltx->DrawLatex(x0,y0,txts);
}

void tag(Char_t const txts[]="",Double_t x0=0.3, Double_t y0=0.3,Int_t iColor=38,Double_t fSize=0.08,Bool_t IsNDC=kTRUE,Double_t Angle=45){
  TLatex *ltx = new TLatex();
  ltx->SetNDC(IsNDC);
  if(!(x0>=0 && x0<=1 && y0>=0 && y0<=1) ) ltx->SetNDC(kFALSE);
  ltx->SetTextColor(iColor);
  ltx -> SetTextFont(72);
  ltx->SetTextSize(fSize);
  ltx->SetTextAngle(Angle);
  ltx->DrawLatex(x0,y0,txts);
}

/* void txt(Double_t x0=0.3, Double_t y0=0.3,TString txts="",Int_t iColor=2,Double_t fSize=0.05,Double_t fang=0.0,Bool_t IsNDC=kTRUE){ */
/*   TLatex *ltx = new TLatex(); */
/*   ltx->SetNDC(IsNDC); */
/*   if(!(x0>=0 && x0<=1 && y0>=0 && y0<=1) ) ltx->SetNDC(kFALSE); */
/*   ltx->SetTextColor(iColor); */
/*   ltx -> SetTextFont(22); */
/*   ltx->SetTextSize(fSize); */
/*   ltx->SetTextAngle(45.); */
/*   ltx->DrawLatex(x0,y0,txts.Data()); */
/* } */
void txtA(Double_t x0=0.3, Double_t y0=0.3,TString txts="",Int_t iColor=2,Double_t fSize=0.05,Double_t fang=0.0,Bool_t IsNDC=kTRUE){
  TLatex *ltx = new TLatex();
  ltx->SetNDC(IsNDC);
  if(!(x0>=0 && x0<=1 && y0>=0 && y0<=1) ) ltx->SetNDC(kFALSE);
  ltx->SetTextColor(iColor);
  ltx -> SetTextFont(22);
  ltx->SetTextSize(fSize);
  ltx->SetTextAngle(fang);
  ltx->DrawLatex(x0,y0,txts.Data());
}

void txt(TH1F *h,Double_t x0=0.3, Double_t y0=0.3,Char_t const txts[]="",Int_t iColor=2,Double_t fSize=0.05,Bool_t IsNDC=kTRUE){
  txt(x0,y0,txts,iColor,fSize,IsNDC);
}
void txt(TH1F *h,Char_t txts[],Double_t x0=0.3, Double_t y0=0.3,Int_t iColor=2,Double_t fSize=0.05,Bool_t IsNDC=kTRUE){
  txt(h,x0,y0,txts,iColor,fSize,IsNDC);
}

void txtmax(TH1F *h,Char_t const txts[]="",Int_t iColor=2,Double_t fSize=0.1){
  Double_t maxy = h->GetMaximum();
  Int_t imaxy = h->GetMaximumBin();
  Double_t maxx = h->GetBinCenter(imaxy);
  txt(h,maxx,maxy,txts,iColor,fSize,kFALSE);
}


TGraphErrors *newTGraphErrors(Char_t *txtFileName,Int_t iMode=0){
  TGraphErrors *grTmp = new TGraphErrors(txtFileName,"%lg %lg %lg %lg");
  if(iMode>=0 && iMode<14){
    Int_t iMarker[] = {20,21,24,25,28,29,30,27,3,  5,2, 26,22,23};
    Int_t iColor[]  = { 2, 4, 6, 9, 1,50,40,31,41,35,44,38,47,12};
    grTmp ->SetMarkerStyle(iMarker[iMode]);
    grTmp ->SetMarkerColor(iColor[iMode]);
    grTmp ->SetLineColor(iColor[iMode]);
  }
  return grTmp;
}

TGraphErrors *newTGraphErrors(Int_t n,Double_t x[],Double_t y[], Double_t xE[],Double_t yE[],Int_t iMode=0){
  TGraphErrors *grTmp = new TGraphErrors(n,x,y,xE,yE);
  if(iMode>=0 && iMode<14){
    Int_t iMarker[] = {20,21,24,25,28,29,30,27,3,  5,2, 26,22,23};
    Int_t iColor[]  = { 2, 4, 6, 9, 1,50,40,31,41,35,44,38,47,12};
    grTmp ->SetMarkerStyle(iMarker[iMode]);
    grTmp ->SetMarkerColor(iColor[iMode]);
    grTmp ->SetLineColor(iColor[iMode]);
  }
  return grTmp;
}

TGraphErrors *newTGraphErrors(Int_t n,Float_t x[],Float_t y[], Float_t xE[],Float_t yE[],Int_t iMode=0){
  TGraphErrors *grTmp = new TGraphErrors(n,x,y,xE,yE);
  if(iMode>=0 && iMode<14){
    Int_t iMarker[] = {20,21,24,25,28,29,30,27,3,  5,2, 26,22,23};
    Int_t iColor[]  = { 2, 4, 6, 1, 9,50,40,31,41,35,44,38,47,12};
    grTmp ->SetMarkerStyle(iMarker[iMode]);
    grTmp ->SetMarkerColor(iColor[iMode]);
    grTmp ->SetLineColor(iColor[iMode]);
  }
  return grTmp;
}


void draw(TH1F *h,Double_t yOffset = 1.0){
  gPad->SetLeftMargin(yOffset*0.1);
  h->GetYaxis()->SetTitleOffset(yOffset);
  h->Draw();
}

Bool_t IsTrkInRVz_CloneArray_TParticle(Int_t idx, TClonesArray *pclone,Double_t Rin=1.0, Double_t Zin=10.0){
  TParticle *part = (TParticle *)pclone->At(idx);
  TLorentzVector LVtmp;
 
  TLorentzVector LVpro;
  part->ProductionVertex(LVpro);
  TVector3 LVpro3 = LVpro.Vect();
  Double_t R = LVpro3.Perp();

  if(!(R<Rin)) return kFALSE;
  Double_t absZ = TMath::Abs(LVpro3.Z());
  if(!(absZ < Zin)) return kFALSE;
  return kTRUE;
}

Bool_t IsTrkInRVz_CloneArray_TVector2(Int_t idx, TClonesArray *pclone,Double_t Rin=1.0, Double_t Zin=10.0){
  TVector2 *part = (TVector2 *)pclone->At(idx);
  Double_t R = part->X();
  if(!(R<Rin)) return kFALSE;
  Double_t absZ = TMath::Abs(part->Y());
  if(!(absZ < Zin)) return kFALSE;
  return kTRUE;
}


Double_t GetIPR_CloneArray_TVector2(Int_t idx, TClonesArray *pclone){
  TVector2 *part = (TVector2 *)pclone->At(idx);
  return part->X();
}

Double_t GetIPZ_CloneArray_TVector2(Int_t idx, TClonesArray *pclone){
  TVector2 *part = (TVector2 *)pclone->At(idx);
  return part->Y();
}


void SetRooRealVarRange(RooRealVar *pvar,Double_t range = 0.2){
  Double_t val = pvar->getVal();
  Double_t rangeL = TMath::Abs(val * range);
  if(rangeL<0.1) rangeL = 0.1;
  Double_t LeftR = val - rangeL;
  Double_t RightR = val + rangeL;
  pvar->setRange(LeftR,RightR);
}

void draw2H(TH1F *h1,TH1F *h2){
  TPad *pad1 = new TPad("pad1","",0., 0.001, 0.499,0.999,10);
  TPad *pad2 = new TPad("pad2","",0.501, 0.001, 0.999,0.999,10);
  pad1->Draw();
  pad2->Draw();

  pad1->cd();
  h1->Draw();
  pad2->cd();
  h2->Draw();
}

void draw3H(TH1F *h1,TH1F *h2, TH2F *h12,const char* opt=""){

  TString options = "colz"; options += opt;  
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
  //options.Data()
  h12->Draw(options.Data());
  //h12->Draw("BOX");
}

void draw3H(TH1F *h1,TH1F *h2, TH2F *h12,Double_t h1L,Double_t h1R,Double_t h2L, Double_t h2R,Int_t iColor=2){
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
  h12->Draw("BOX");

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

void draw4H(TH1F *h1,TH1F *h2, TH1F *h3,TH1F *h4){
  TPad *pad1 = new TPad("pad1","",0., 0.501, 0.499,0.999,10);
  TPad *pad2 = new TPad("pad2","",0.501, 0.501, 0.999,0.999,10);
  TPad *pad3 = new TPad("pad3","",0.,.001,0.499,0.499,10);
  TPad *pad4 = new TPad("pad4","",0.501,.001,0.999,0.499,10);
  pad1->Draw();
  pad2->Draw();
  pad3->Draw();
  pad4->Draw();

  pad1->cd();
  h1->Draw();
  pad2->cd();
  h2->Draw();
  pad3->cd();
  h3->Draw();
  pad4->cd();
  h4->Draw();
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

void draw6H(TH1F *h1,TH1F *h2, TH1F *h3,TH1F *h4,TH1F *h5,TH1F *h6){

  TPad *pad1 = new TPad("pad1","",0.000, 0.501, 0.333,0.999,10);
  TPad *pad2 = new TPad("pad2","",0.333, 0.501, 0.666,0.999,10);
  TPad *pad3 = new TPad("pad3","",0.666, 0.501, 0.999,0.999,10);

  TPad *pad1d = new TPad("pad1d","",0.000, 0.001, 0.333,0.499,10);
  TPad *pad2d = new TPad("pad2d","",0.333, 0.001, 0.666,0.499,10);
  TPad *pad3d = new TPad("pad3d","",0.666, 0.001, 0.999,0.499,10);

  pad1->Draw();
  pad2->Draw();
  pad3->Draw();

  pad1d->Draw();
  pad2d->Draw();
  pad3d->Draw();


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
  pad3d->cd();
  h6->Draw();

}

void draw3H(TH1F *h1,TH1F *h2, TH1F *h12){
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
  h12->Draw();
}

void draw4H(TH1 *h1,TH1 *h2,TH1 *h3,TH1 *h4){
  TPad *pad1 = new TPad("pad1","",0., 0.501, 0.499,0.999,10);
  TPad *pad2 = new TPad("pad2","",0., 0.001, 0.499,0.499,10);
  TPad *pad3 = new TPad("pad3","",0.501,.501,0.999,0.999,10);
  TPad *pad4 = new TPad("pad4","",0.501,.001,0.999,0.499,10);
  pad1->Draw();
  pad2->Draw();
  pad3->Draw();
  pad4->Draw();

  pad1->cd();
  h1->Draw();
  pad2->cd();
  h2->Draw();
  pad3->cd();
  h3->Draw();
  pad4->cd();
  h4->Draw();
}

void draw4H(TH2 *h1,TH2 *h2,TH2 *h3,TH2 *h4){
  TPad *pad1 = new TPad("pad1","",0., 0.501, 0.499,0.999,10);
  TPad *pad2 = new TPad("pad2","",0., 0.001, 0.499,0.499,10);
  TPad *pad3 = new TPad("pad3","",0.501,.501,0.999,0.999,10);
  TPad *pad4 = new TPad("pad4","",0.501,.001,0.999,0.499,10);
  pad1->Draw();
  pad2->Draw();
  pad3->Draw();
  pad4->Draw();

  pad1->cd();
  h1->Draw();
  pad2->cd();
  h2->Draw();
  pad3->cd();
  h3->Draw();
  pad4->cd();
  h4->Draw();
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
void MoveStat(TCanvas *ctmp,TH2* h,Double_t x0,Double_t y0,Double_t x1, Double_t y1,Int_t icolor=1){
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




/* Bool_t IsJsp_KmKStar2KpPi0(Int_t n, Int_t PidList[], Int_t motherIdx[]){ */
/*   if (!(n==7)) return kFALSE; */

/*   Int_t iJpsi = 0; */
/*   Int_t iKm = 1; */
/*   Int_t iKStar = 2; */
/*   Int_t iKp = 3; */
/*   Int_t iPi0 = 4; */
/*   Int_t iGamma1 = 5; */
/*   Int_t iGamma1 = 6; */
/*   Int_t idx[7]; */
/*   for(Int_t i=0; i<n; i++){ */
/*     idx[i] = -1; */
/*   } */

/*   for(Int_t i=0; i<n; i++){ */
/*     if(PidList[i]== 443) idx[iJpsi] =i; */
/*     if(PidList[i]== -321) idx[iKm] =i; */
/*     if(PidList[i]== 323) idx[iKStar] =i; */
/*     if(PidList[i]== 321) idx[iKp] =i; */
/*     if(PidList[i]== 111) idx[iPi0] =i; */
/*     if(PidList[i]== 22){ */
/*       if(idx[iGamma1]==-1){ */
/* 	idx[iGamma1] =i; */
/*       }else{ */
/* 	idx[iGamma2] =i; */
/*       } */
/*     } */
/*   } */

/*   //To make sure every particles found */
/*   for(Int_t i=0; i<n; i++){ */
/*     if(idx[i]<0) return kFALSE; */
/*   } */

/*   //gamma1 and gamma2 from same mother */
/*   if(!(motherIdx[idx[iGamma1]] == motherIdx[idx[iGamma2]])) return kFALSE; */
/*   Int_t snPi0 = motherIdx[idx[iGamma1]]; */
/*   if(!(snPi0 == idx[iPi0])) return kFALSE; */

/*   //to make sure pi0 and K+ from K*+ */
/*   if(!(motherIdx[idx[iKp]] == motherIdx[idx[iPi0]])) return kFALSE; */
/*   Int_t snKStar = motherIdx[idx[iKp]]; */
/*   if(!(snKStar == idx[iKStar])) return kFALSE; */

/*   //to make sure K- and K* form JPsi */
/*   if(!(motherIdx[idx[iKm]] == motherIdx[idx[iKStar]])) return kFALSE; */
/*   Int_t snJPsi = motherIdx[idx[iJPsi]]; */
/*   if(!(snJPsi == idx[iJPsi])) return kFALSE; */

/*   return kTRUE; */
 
/* } */


//select: J/Psi->K- K*+, K*+->K+ pi0, pi0->g g
Bool_t IsJPsi_KmKStar2KpPi0(Int_t n, Int_t PidList[], Int_t motherIdx[]){
 
  if (!(n==7)) return kFALSE;
 
  Int_t iJPsi = 0;
  Int_t iKm = 1;
  Int_t iKStar = 2;
  Int_t iKp = 3;
  Int_t iPi0 = 4;
  Int_t iGamma1 = 5;
  Int_t iGamma2 = 6;
  Bool_t FindG1 = kFALSE;
  Bool_t FindG2 = kFALSE;

  Int_t idx[7];
  for(Int_t i=0; i<n; i++){
    idx[i] = -99;
  }

  for(Int_t i=0; i<n; i++){
    if(PidList[i]== 443) idx[iJPsi] =i;
    if(PidList[i]== -321) idx[iKm] =i;
    if(PidList[i]== 323) idx[iKStar] =i;
    if(PidList[i]== 321) idx[iKp] =i;
    if(PidList[i]== 111) idx[iPi0] =i;
    if(PidList[i]== 22)  {
      if(! FindG1) {
	idx[iGamma1] = i;
	FindG1 = kTRUE;
      }else{
	if(! FindG2 ){
	  idx[iGamma2] = i;
	  FindG2 = kTRUE;
	}
      }
    }
  }

  //To make sure every particles found
  for(Int_t i=0; i<n; i++){
    if(idx[i]<0) {
      printf("idx[%d] = %d\n",i,idx[i]);
      printf("read from\n");
      for(Int_t m=0; m<n; m++){
	printf("PidList[%d] = %d  idx = %d\n",m,PidList[m],idx[m]);
      }
      return kFALSE;
    }
  }

  //gamma1 and gamma2 from same mother
  if(!(motherIdx[idx[iGamma1]] == motherIdx[idx[iGamma2]])) return kFALSE;
  Int_t snPi0 = motherIdx[idx[iGamma1]];
  if(!(snPi0 == idx[iPi0])) return kFALSE;

  //to make sure pi0 and K+ from K*+
  if(!(motherIdx[idx[iKp]] == motherIdx[idx[iPi0]])) return kFALSE;
  Int_t snKStar = motherIdx[idx[iKp]];
  if(!(snKStar == idx[iKStar])) return kFALSE;

  //to make sure K- and K* form JPsi
  if(!(motherIdx[idx[iKm]] == motherIdx[idx[iKStar]])) return kFALSE;
  Int_t snJPsi = motherIdx[idx[iJPsi]];
  if(!(snJPsi == -1 ))    return kFALSE;
  
  return kTRUE;
 
}

void xtit(TH1 *h,Char_t const title[]="",Double_t offset=1.0){
  h->GetXaxis()->SetTitle(title);
  h->GetXaxis()->SetTitleOffset(offset);
}


//if toSetMass1 and toSetMass2>0, reset the mass of the tracks
Double_t GetCosThOCMS_ClonesArrayTPartile(Int_t j, TClonesArray *pclone1,TClonesArray *pclone2, Double_t toSetMass1=-999,Double_t toSetMass2=-999){
  
  if(j>=pclone1->GetEntries()){
    printf("Error: j=%d >= Entries of ColonesArray1:  %d\n",j,pclone1->GetEntries());
    return -999;
  }
  if(j>=pclone2->GetEntries()){
    printf("Error: j=%d >= Entries of ColonesArray2:  %d\n",j,pclone2->GetEntries());
    return -999;
  }
  TParticle *part1 = (TParticle *)pclone1->At(j);
  TLorentzVector LVtmp1;
  part1 -> Momentum(LVtmp1);
  if(toSetMass1>=0) {
    Double_t x = LVtmp1.Px();
    Double_t y = LVtmp1.Py();
    Double_t z = LVtmp1.Pz();
    LVtmp1.SetXYZM(x,y,z,toSetMass1);
  }

  TParticle *part2 = (TParticle *)pclone2->At(j);
  TLorentzVector LVtmp2;
  part2 -> Momentum(LVtmp2);
  if(toSetMass2>=0) {
    Double_t x = LVtmp2.Px();
    Double_t y = LVtmp2.Py();
    Double_t z = LVtmp2.Pz();
    LVtmp2.SetXYZM(x,y,z,toSetMass2);
  }
  TLorentzVector LVtmp12 = LVtmp1 + LVtmp2;
  TVector3 boostVector3  =-(LVtmp12.BoostVector());

  LVtmp1.Boost(boostVector3);
  return LVtmp1.CosTheta();
}


Double_t GetCosTh_LV1InLV2CMS(TLorentzVector LVtmp1, TLorentzVector LVtmp2){
  TVector3 boostVector3  =-(LVtmp2.BoostVector());
  LVtmp1.Boost(boostVector3);
  return LVtmp1.CosTheta();
}

//functions for get MCTruth Information
Int_t indexMCTruth(Int_t PdgCode,Int_t indexmc,Int_t pdgid[]){
  for(Int_t i=0; i<indexmc; i++){
    if(PdgCode == pdgid[i]) return i;
  }
  return -1;
}

void indexMCTruth(Int_t PdgCode,Int_t indexmc,Int_t pdgid[],vector<Int_t> *vidx){
  vidx->clear(); 
  for(Int_t i=0; i<indexmc; i++){
    if(PdgCode == pdgid[i]) vidx->push_back(i);
  }
}

TLorentzVector *getLV(Int_t idx,TClonesArray *pclon){
  return (TLorentzVector *)pclon->At(idx);
}

TLorentzVector getLVValue(Int_t idx,TClonesArray *pclon){
  TLorentzVector *pLV =  (TLorentzVector *)pclon->At(idx);
  return (*pLV);
}


Bool_t IsAbsInRange(Double_t var,Double_t VarL, Double_t VarH){
  Double_t absVar  = TMath::Abs(var);
  return (absVar> VarL && absVar < VarH) ? kTRUE:kFALSE; 
}


void SetLineColorAsPoint(TGraph *gr){
  gr->SetLineColor(gr->GetMarkerColor());
}


void txtN(Double_t x0, Double_t y0,TH1 *h,Char_t const sName[]="N=%.0f",Double_t sizeTxt=0.06){
  h->SetStats(kFALSE);
  TLatex *ltx = new TLatex();
  ltx->SetNDC(kTRUE);
  ltx->SetTextColor(h->GetLineColor());
  ltx -> SetTextFont(22);
  ltx->SetTextSize(sizeTxt);
  ltx->DrawLatex(x0,y0,Form(sName,h->GetEntries()));
  gPad->Modified();
  gPad->Update();
}


void txtRMS(Double_t x0, Double_t y0,TH1 *h,Char_t const sFormat[]="RMS=%.2f",Double_t fsize = 0.06){
  h->SetStats(kFALSE);
  TLatex *ltx = new TLatex();
  ltx->SetNDC(kTRUE);
  ltx->SetTextColor(h->GetLineColor());
  ltx -> SetTextFont(22);
  ltx->SetTextSize(fsize);
  ltx->DrawLatex(x0,y0,Form(sFormat,h->GetRMS()));
  gPad->Modified();
  gPad->Update();
}



void txtRMSE(Double_t x0, Double_t y0,TH1 *h,Char_t const sFormat[]="RMS=%.2f#pm%.2f",Double_t fsize = 0.06){
  h->SetStats(kFALSE);
  TLatex *ltx = new TLatex();
  ltx->SetNDC(kTRUE);
  ltx->SetTextColor(h->GetLineColor());
  ltx -> SetTextFont(22);
  ltx->SetTextSize(fsize);
  ltx->DrawLatex(x0,y0,Form(sFormat,h->GetRMS(),h->GetRMSError()));
  gPad->Modified();
  gPad->Update();
}



void txtRMSY(Double_t x0, Double_t y0,TH1 *h,Char_t const sFormat[]="RMS=%.2f",Double_t fsize = 0.06){
  h->SetStats(kFALSE);
  TLatex *ltx = new TLatex();
  ltx->SetNDC(kTRUE);
  ltx->SetTextColor(h->GetLineColor());
  ltx -> SetTextFont(22);
  ltx->SetTextSize(fsize);
  ltx->DrawLatex(x0,y0,Form(sFormat,h->GetRMS(2)));
  gPad->Modified();
  gPad->Update();
}


void txtM(Double_t x0, Double_t y0,TH1 *h,Char_t const sFormat[]="Mean=%.2f",Double_t fsize = 0.06){
  h->SetStats(kFALSE);
  TLatex *ltx = new TLatex();
  ltx->SetNDC(kTRUE);
  ltx->SetTextColor(h->GetLineColor());
  ltx -> SetTextFont(22);
  ltx->SetTextSize(fsize);
  ltx->DrawLatex(x0,y0,Form(sFormat,h->GetMean()));
  gPad->Modified();
  gPad->Update();
}
void txtMY(Double_t x0, Double_t y0,TH1 *h,Char_t const sFormat[]="#bar{y}=%.2f",Double_t fsize = 0.06){
  h->SetStats(kFALSE);
  TLatex *ltx = new TLatex();
  ltx->SetNDC(kTRUE);
  ltx->SetTextColor(h->GetLineColor());
  ltx -> SetTextFont(22);
  ltx->SetTextSize(fsize);
  ltx->DrawLatex(x0,y0,Form(sFormat,h->GetMean(2)));
  gPad->Modified();
  gPad->Update();
}
void txtMX(Double_t x0, Double_t y0,TH1 *h,Char_t const sFormat[]="MeanX=%.2f",Double_t fsize = 0.06){
  h->SetStats(kFALSE);
  TLatex *ltx = new TLatex();
  ltx->SetNDC(kTRUE);
  ltx->SetTextColor(h->GetLineColor());
  ltx -> SetTextFont(22);
  ltx->SetTextSize(fsize);
  ltx->DrawLatex(x0,y0,Form(sFormat,h->GetMean(1)));
  gPad->Modified();
  gPad->Update();
}

void txtME(Double_t x0, Double_t y0,TH1 *h,Char_t const sFormat[]="Mean=%.2f#pm%.2f",Double_t fsize=0.06){
  h->SetStats(kFALSE);
  TLatex *ltx = new TLatex();
  ltx->SetNDC(kTRUE);
  ltx->SetTextColor(h->GetLineColor());
  ltx -> SetTextFont(22);
  ltx->SetTextSize(fsize);
  ltx->DrawLatex(x0,y0,Form(sFormat,h->GetMean(),h->GetMeanError()));
  gPad->Modified();
  gPad->Update();
}

void txtMvsRMSE(Double_t x0, Double_t y0,TH1 *h,Char_t const sFormat[]="Mean/RMS=%.2f#pm%.2f",Double_t fsize=0.06){
  h->SetStats(kFALSE);
  TLatex *ltx = new TLatex();
  ltx->SetNDC(kTRUE);
  ltx->SetTextColor(h->GetLineColor());
  ltx -> SetTextFont(22);
  ltx->SetTextSize(fsize);
  Double_t fMean = h->GetMean();
  Double_t fRMS = h->GetRMS();
  Double_t fMeanE = h->GetMeanError();
  Double_t fRMSE = h->GetRMSError();
  Double_t ratio = fMean/fRMS;
  Double_t relMeanE = fMeanE/fMean;
  Double_t relRMSE = fRMSE/fRMS;
  Double_t ratioE = ratio * TMath::Sqrt(relMeanE*relMeanE + relRMSE*relRMSE);
  ratioE = TMath::Abs(ratioE);
  ltx->DrawLatex(x0,y0,Form(sFormat,ratio,ratioE));
  gPad->Modified();
  gPad->Update();
}

void draw2HNorm(TH1 *h1, TH1 *h2){
  if (h1->GetEntries()==0) return;
  if (h2->GetEntries()==0) return;
  h1->SetStats(kFALSE);
  h2->SetStats(kFALSE);
  if(h1->GetMaximum()/h1->GetEntries()>h2->GetMaximum()/h2->GetEntries()){
    h1->DrawNormalized();
    h2->DrawNormalized("SAME");
  }else{
    h2->DrawNormalized();
    h1->DrawNormalized("SAME");
  }

}

void draw2HSame(TH1 *h1, TH1 *h2,Char_t Option1[],Char_t Option2[]){
  if (h1->GetEntries()==0) return;
  if (h2->GetEntries()==0) return;
  h1->SetStats(kFALSE);
  h2->SetStats(kFALSE);
  if(h1->GetMaximum()>h2->GetMaximum()){
    h1->Draw(Option1);
    h2->Draw(Form("SAME,%s",Option2));
  }else{
    h2->Draw(Option2);
    h1->Draw(Form("SAME,%s",Option1));
  }

}


void drawDalitz3Plots(TH1 *h1, TH1 *h2, TH1 *h12, Char_t canvasName[],Double_t mxmy=0.2,vector<Float_t> *linesIn=NULL){
  
  Double_t lowx = mxmy; 
  Double_t lowy = lowx;
  Double_t highx = 0.995;
  Double_t highy = 0.995; 
  Double_t lowy0 = 0.005;
  Double_t highy0 = lowy-0.005;

  vector<Float_t> lines;
  Int_t isize = TMath::Nint(linesIn->size()*1.0);
  if(linesIn != NULL){
    for(Int_t i=0; i<isize; i++){
      lines.push_back( (*linesIn)[i]);
    }
  }

  TPad *pad1 = new TPad("pad1","",lowx,lowy,highx,highy,10,0,0);
  pad1->Draw();
  TPad *pad2 = new TPad("pad2","",lowx,lowy0,highx,highy0,10,0,0);
  pad2->Draw();
  TPad *pad3 = new TPad("pad3","",lowy0,lowy,highy0,highx,10,0,0);
  pad3->Draw();
  pad1->cd();
  h12->GetXaxis()->SetTitle(h1->GetXaxis()->GetTitle());
  h12->GetYaxis()->SetTitle(h2->GetXaxis()->GetTitle());
  h12->Draw("box");
  // h12->Draw("colz");
  txtN(0.7,0.9,h12);
  if(lines.size()>=2){
    LineX(lines[0],2,canvasName);
    LineX(lines[1],2,canvasName);
  }
  if(lines.size()>=4){
    LineY(lines[2],4,canvasName);
    LineY(lines[3],4,canvasName);
  }
  pad2->cd();
  TH1 *h2Tmp = (TH1 *)h2->Clone("h2Tmp");
  h2Tmp->Draw();
  txtN(0.7,0.9,h2Tmp);
  if(lines.size()>=4){
    LineX(lines[2],4,canvasName);
    LineX(lines[3],4,canvasName);
  }
  gPad->Modified();
  gPad->Update();
  TImage *img = TImage::Create();
  img->FromPad(gPad);
  img->Flip(90);
  delete h2Tmp;
  pad3->cd();
  img->Draw("x");

  pad2->cd();
  h1->Draw();
  txtN(0.7,0.9,h1);
  if(lines.size()>=2){
    LineX(lines[0],2,canvasName);
    LineX(lines[1],2,canvasName);
  }
  
}

Double_t angleDau1InMotherCMS(TLorentzVector Dau1,TLorentzVector Dau2){
  TLorentzVector m = Dau1 + Dau2;
  TVector3 bm = m.BoostVector();
  Dau1.Boost(-bm);
  TVector3 vm = m.Vect();
  TVector3 vDau1CMS = Dau1.Vect();
  return vm.Angle(vDau1CMS);
}

Double_t angleOfTwoLV(TLorentzVector LV1,TLorentzVector LV2){
  TVector3 vLV1 = LV1.Vect();
  TVector3 vLV2 = LV2.Vect();
  return vLV1.Angle(vLV2);
}

TVector3 nOfTwoLVPlan(TLorentzVector LV1,TLorentzVector LV2){
  TVector3 vLV1 = LV1.Vect();
  TVector3 vLV2 = LV2.Vect();
  return (vLV1.Cross(vLV2)).Unit();
}

Double_t phiOfDecayPlane(TLorentzVector lvDau1,TLorentzVector lvM1,TLorentzVector lvDau2,TLorentzVector lvM2){
  TVector3 n1 = nOfTwoLVPlan(lvDau1,lvM1);
  TVector3 n2 = nOfTwoLVPlan(lvDau2,lvM2);
  return n1.Angle(n2);
}

TLorentzVector boostToMotherFrame(TLorentzVector DauToBeBoost,TLorentzVector m){
  TVector3 bm = m.BoostVector();
  TLorentzVector newDau = DauToBeBoost;
  newDau.Boost(-bm);
  return newDau;
}

TH1 *readTHinROOT(Char_t rootName[],Char_t histName[]){
  printf("read %s from %s\n",histName,rootName);
  TH1 *htmpTH1F = NULL;
  TFile fin(rootName,"READ");
  htmpTH1F = (TH1 *) fin.Get(histName);
  htmpTH1F->SetDirectory(0);
  fin.Close();
  if(htmpTH1F==NULL){
    printf("Can not find %s in %s\n",histName,rootName);

  }
  return htmpTH1F;
}
// position will have to change depending on the data shape
void MakeLegend(TH1 * datahist,   // Histogram with data
		Char_t * dataname,  // Description of data
		double xlow,      // Left edge of legend 
		                  //(fraction of canavas width)
		double ylow,       // Bottom edge of legend
		//(fraction of canavas height)
		double xhi,       // Right edge of legend 
		                  //(fraction of canavas width)
		double yhi,Char_t const Option[] = "LEP"){       // Top edge of legend  
  //(fraction of canavas height)
  
  TLegend * leg = new TLegend(xlow, ylow, xhi, yhi);
  if(datahist && dataname)
    leg->AddEntry(datahist, dataname, Option);
  
  leg->SetFillColor(0);
  leg->SetFillStyle(4000);
  leg->SetTextFont(22);
  leg->SetBorderSize(0);
  leg->Draw();
}

// position will have to change depending on the data shape
void MakeLegend(TH1 * datahist,   // Histogram with data
		Char_t * dataname,  // Description of data
		TH1 * mc1hist, // Histogram with first MC
		Char_t * mc1name, // Description of first MC

		double xlow,      // Left edge of legend 
		                  //(fraction of canavas width)
		double ylow,       // Bottom edge of legend
		//(fraction of canavas height)
		double xhi,       // Right edge of legend 
		                  //(fraction of canavas width)
		double yhi,Char_t const Option[] = "LEP"){       // Top edge of legend  
  //(fraction of canavas height)
  
  TLegend * leg = new TLegend(xlow, ylow, xhi, yhi);
  if(datahist && dataname)
    leg->AddEntry(datahist, dataname, Option);
  if(mc1hist && mc1name)
    leg->AddEntry(mc1hist, mc1name, Option);
  
  leg->SetFillColor(10);
  leg->SetFillStyle(0);
  leg->SetTextFont(22);
  leg->SetBorderSize(0);
  leg->Draw();
}

// position will have to change depending on the data shape
void MakeLegend(TH1 * datahist,   // Histogram with data
		Char_t * dataname,  // Description of data
		TH1 * mc1hist, // Histogram with first MC
		Char_t * mc1name, // Description of first MC

		double xlow,      // Left edge of legend 
		                  //(fraction of canavas width)
		double ylow,       // Bottom edge of legend
		//(fraction of canavas height)
		double xhi,       // Right edge of legend 
		                  //(fraction of canavas width)
		double yhi,Char_t Option1[],Char_t Option2[]){       // Top edge of legend  
  //(fraction of canavas height)
  
  TLegend * leg = new TLegend(xlow, ylow, xhi, yhi);
  if(datahist && dataname)
    leg->AddEntry(datahist, dataname, Option1);
  if(mc1hist && mc1name)
    leg->AddEntry(mc1hist, mc1name, Option2);
  
  leg->SetFillColor(10);
  leg->SetFillStyle(0);
  leg->SetTextFont(22);
  leg->SetBorderSize(0);
  leg->Draw();
}


// position will have to change depending on the data shape
void MakeLegend(TH1 * datahist,   // Histogram with data
		char * dataname,  // Description of data
		TH1 * mc1hist, // Histogram with first MC
		char * mc1name, // Description of first MC
		TH1 * mc2hist, // Histogram with 2nd MC/BG
		char * mc2name, // Description of second MC/BG
		double xlow,      // Left edge of legend 
		                  //(fraction of canavas width)
		double ylow,       // Bottom edge of legend
		//(fraction of canavas height)
		double xhi,       // Right edge of legend 
		                  //(fraction of canavas width)
		double yhi){       // Top edge of legend
  //(fraction of canavas height)

  TLegend * leg = new TLegend(xlow, ylow, xhi, yhi);
  if(datahist && dataname)
    leg->AddEntry(datahist, dataname, "LEP");
  if(mc1hist && mc1name)
    leg->AddEntry(mc1hist, mc1name, "LEP");
  if(mc2hist && mc2name)
    leg->AddEntry(mc2hist, mc2name, "LEP");
  
  leg->SetFillColor(0);
  leg->SetFillStyle(0);
  leg->SetTextFont(22);
  leg->Draw();
}
// position will have to change depending on the data shape
void MakeLegend(TH1 * datahist,   // Histogram with data
		Char_t * dataname,  // Description of data
		TH1 * mc1hist, // Histogram with first MC
		Char_t * mc1name, // Description of first MC
		TH1 * mc2hist, // Histogram with 2nd MC/BG
		Char_t * mc2name, // Description of second MC/BG
		TH1 * mc3hist, // Histogram with 3
		Char_t * mc3name, // Description of 3
		double xlow,      // Left edge of legend 
		                  //(fraction of canavas width)
		double ylow,       // Bottom edge of legend
		//(fraction of canavas height)
		double xhi,       // Right edge of legend 
		                  //(fraction of canavas width)
		double yhi,Char_t const Option[] = "LEP"){       // Top edge of legend  
  //(fraction of canavas height)
  
  TLegend * leg = new TLegend(xlow, ylow, xhi, yhi);
  if(datahist && dataname)
    leg->AddEntry(datahist, dataname, Option);
  if(mc1hist && mc1name)
    leg->AddEntry(mc1hist, mc1name, Option);

  if(mc2hist && mc2name)
    leg->AddEntry(mc2hist, mc2name, Option);
  if(mc3hist && mc3name)
    leg->AddEntry(mc3hist, mc3name, Option);
  
  leg->SetFillColor(10);
  leg->SetFillStyle(0);
  leg->SetTextFont(22);
  leg->SetBorderSize(0);
  leg->Draw();
}


// position will have to change depending on the data shape
void MakeLegend(TH1 * datahist,   // Histogram with data
		Char_t * dataname,  // Description of data
		TH1 * mc1hist, // Histogram with first MC
		Char_t * mc1name, // Description of first MC
		TH1 * mc2hist, // Histogram with 2nd MC/BG
		Char_t * mc2name, // Description of second MC/BG
		TH1 * mc3hist, // Histogram with 3
		Char_t * mc3name, // Description of 3
		TH1 * mc4hist, // Histogram with 3
		Char_t * mc4name, // Description of 3
		double legXY[],      // Left edge of legend 
		Char_t const Option[] = "LEP"){       // Top edge of legend  
  //(fraction of canavas height)
  
  TLegend * leg = new TLegend(legXY[0],legXY[1], legXY[2], legXY[3]);
  if(datahist && dataname)
    leg->AddEntry(datahist, dataname, Option);
  if(mc1hist && mc1name)
    leg->AddEntry(mc1hist, mc1name, Option);

  if(mc2hist && mc2name)
    leg->AddEntry(mc2hist, mc2name, Option);
  if(mc3hist && mc3name)
    leg->AddEntry(mc3hist, mc3name, Option);
  if(mc4hist && mc4name)
    leg->AddEntry(mc4hist, mc4name, Option);
  
  leg->SetFillColor(10);
  leg->SetFillStyle(0);
  leg->SetTextFont(22);
  leg->SetBorderSize(0);
  leg->Draw();
}

// position will have to change depending on the data shape
void MakeLegend(TH1 * datahist,   // Histogram with data
		Char_t * dataname,  // Description of data
		TH1 * mc1hist, // Histogram with first MC
		Char_t * mc1name, // Description of first MC
		TH1 * mc2hist, // Histogram with 2nd MC/BG
		Char_t * mc2name, // Description of second MC/BG
		TH1 * mc3hist, // Histogram with 3
		Char_t * mc3name, // Description of 3
		TH1 * mc4hist, // Histogram with 3
		Char_t * mc4name, // Description of 3
		TH1 * mc5hist, // Histogram with 3
		Char_t * mc5name, // Description of 3
		double legXY[],      // Left edge of legend 
		Char_t const Option[] = "LEP"){       // Top edge of legend  
  //(fraction of canavas height)
  
  TLegend * leg = new TLegend(legXY[0],legXY[1], legXY[2], legXY[3]);
  if(datahist && dataname)
    leg->AddEntry(datahist, dataname, Option);
  if(mc1hist && mc1name)
    leg->AddEntry(mc1hist, mc1name, Option);

  if(mc2hist && mc2name)
    leg->AddEntry(mc2hist, mc2name, Option);
  if(mc3hist && mc3name)
    leg->AddEntry(mc3hist, mc3name, Option);
  if(mc4hist && mc4name)
    leg->AddEntry(mc4hist, mc4name, Option);
  if(mc5hist && mc5name)
    leg->AddEntry(mc5hist, mc5name, Option);
  
  leg->SetFillColor(10);
  leg->SetFillStyle(0);
  leg->SetTextFont(22);
  leg->SetBorderSize(0);
  leg->Draw();
}



void Add2Hist(THStack *hs,TH1 *h1, TH1* h2,Bool_t norm = kTRUE){
  // *hs = new THStack("hs",Form(";%s;%s",h1->GetXaxis()->GetTitle(),h1->GetYaxis()->GetTitle()));

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


}

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

THStack *Add3Hist(TH1 *h1, TH1* h2, TH1 *h3,Bool_t norm = kTRUE){
  THStack *hs = new THStack("hAll",Form(";%s;%s",h1->GetXaxis()->GetTitle(),h1->GetYaxis()->GetTitle()));

  h1->SetMarkerColor(kRed);
  h1->SetMarkerStyle(21);
  h1->SetLineColor(kRed);

  h2->SetMarkerColor(kBlue);
  h2->SetMarkerStyle(25);
  h2->SetLineColor(kBlue);

  h3->SetMarkerColor(kBlack);
  h3->SetMarkerStyle(20);
  h3->SetLineColor(kBlack);

  if(norm){
    h1->Sumw2();
    h1->Scale(1./h1->GetEntries());
    h2->Sumw2();
    h2->Scale(1./h2->GetEntries());
    h3->Sumw2();
    h3->Scale(1./h3->GetEntries());
  }
  hs->Add(h1);
  hs->Add(h2);
  hs->Add(h3);

  return hs;
}


THStack *Add4Hist(TH1 *h1, TH1* h2, TH1 *h3, TH1 *h4,Bool_t norm = kTRUE){
  THStack *hs = new THStack("hAll",Form(";%s;%s",h1->GetXaxis()->GetTitle(),h1->GetYaxis()->GetTitle()));

  h1->SetMarkerColor(kRed);
  h1->SetMarkerStyle(21);
  h1->SetLineColor(kRed);

  h2->SetMarkerColor(kBlue);
  h2->SetMarkerStyle(25);
  h2->SetLineColor(kBlue);

  h3->SetMarkerColor(kBlack);
  h3->SetMarkerStyle(20);
  h3->SetLineColor(kBlack);

  h4->SetMarkerColor(kPink);
  h4->SetMarkerStyle(4);
  h4->SetLineColor(kPink);
  if(norm){
    h1->Sumw2();
    h1->Scale(1./h1->GetEntries());
    h2->Sumw2();
    h2->Scale(1./h2->GetEntries());
    h3->Sumw2();
    h3->Scale(1./h3->GetEntries());
    h4->Sumw2();
    h4->Scale(1./h4->GetEntries());
  }
  hs->Add(h1);
  hs->Add(h2);
  hs->Add(h3);
  hs->Add(h4);

  return hs;
}


THStack *Add5Hist(TH1 *h1, TH1* h2, TH1 *h3, TH1 *h4,TH1 *h5,Bool_t norm = kTRUE){
  THStack *hs = new THStack("hAll",Form(";%s;%s",h1->GetXaxis()->GetTitle(),h1->GetYaxis()->GetTitle()));

  h1->SetMarkerColor(kRed);
  h1->SetMarkerStyle(21);
  h1->SetLineColor(kRed);

  h2->SetMarkerColor(kBlue);
  h2->SetMarkerStyle(25);
  h2->SetLineColor(kBlue);

  h3->SetMarkerColor(kBlack);
  h3->SetMarkerStyle(20);
  h3->SetLineColor(kBlack);

  h4->SetMarkerColor(kPink);
  h4->SetMarkerStyle(4);
  h4->SetLineColor(kPink);

  h5->SetMarkerColor(kViolet);
  h5->SetMarkerStyle(29);
  h5->SetMarkerSize(1.2);
  h5->SetLineColor(kViolet);

  if(norm){
    h1->Sumw2();
    h1->Scale(1./h1->GetEntries());
    h2->Sumw2();
    h2->Scale(1./h2->GetEntries());
    h3->Sumw2();
    h3->Scale(1./h3->GetEntries());
    h4->Sumw2();
    h4->Scale(1./h4->GetEntries());
    h5->Sumw2();
    h5->Scale(1./h5->GetEntries());
  }
  hs->Add(h1);
  hs->Add(h2);
  hs->Add(h3);
  hs->Add(h4);
  hs->Add(h5);

  return hs;
}


THStack *Add5Hist0(TH1 *h1, TH1* h2, TH1 *h3, TH1 *h4,TH1 *h5,Bool_t norm = kTRUE){
  THStack *hs = new THStack("hAll",Form(";%s;%s",h1->GetXaxis()->GetTitle(),h1->GetYaxis()->GetTitle()));

  //  h1->SetMarkerColor(kRed);
  // h1->SetMarkerStyle(21);
  // h1->SetLineColor(kRed);

/*   h2->SetMarkerColor(kBlue); */
/*   h2->SetMarkerStyle(25); */
/*   h2->SetLineColor(kBlue); */

/*   h3->SetMarkerColor(kBlack); */
/*   h3->SetMarkerStyle(20); */
/*   h3->SetLineColor(kBlack); */

/*   h4->SetMarkerColor(kPink); */
/*   h4->SetMarkerStyle(4); */
/*   h4->SetLineColor(kPink); */

/*   h5->SetMarkerColor(kViolet); */
/*   h5->SetMarkerStyle(29); */
/*   h5->SetMarkerSize(1.2); */
/*   h5->SetLineColor(kViolet); */

  if(norm){
    h1->Sumw2();
    h1->Scale(1./h1->GetEntries());
    h2->Sumw2();
    h2->Scale(1./h2->GetEntries());
    h3->Sumw2();
    h3->Scale(1./h3->GetEntries());
    h4->Sumw2();
    h4->Scale(1./h4->GetEntries());
    h5->Sumw2();
    h5->Scale(1./h5->GetEntries());
  }
  hs->Add(h1);
  hs->Add(h2);
  hs->Add(h3);
  hs->Add(h4);
  hs->Add(h5);

  return hs;
}


THStack *Add6Hist(TH1 *h1, TH1* h2, TH1 *h3, TH1 *h4,TH1 *h5,TH1 *h6,Bool_t norm = kTRUE){
  THStack *hs = new THStack("hAll",Form(";%s;%s",h1->GetXaxis()->GetTitle(),h1->GetYaxis()->GetTitle()));

  h1->SetMarkerColor(kRed);
  h1->SetMarkerStyle(21);
  h1->SetLineColor(kRed);

  h2->SetMarkerColor(kBlue);
  h2->SetMarkerStyle(25);
  h2->SetLineColor(kBlue);

  h3->SetMarkerColor(kBlack);
  h3->SetMarkerStyle(20);
  h3->SetLineColor(kBlack);

  h4->SetMarkerColor(kPink);
  h4->SetMarkerStyle(4);
  h4->SetLineColor(kPink);

  h5->SetMarkerColor(kViolet);
  h5->SetMarkerStyle(29);
  h5->SetMarkerSize(1.2);
  h5->SetLineColor(kViolet);

  h6->SetMarkerColor(kBlue);
  h6->SetMarkerStyle(22);
  h6->SetMarkerSize(1.2);
  h6->SetLineColor(kBlue);

  if(norm){
    h1->Sumw2();
    h1->Scale(1./h1->GetEntries());
    h2->Sumw2();
    h2->Scale(1./h2->GetEntries());
    h3->Sumw2();
    h3->Scale(1./h3->GetEntries());
    h4->Sumw2();
    h4->Scale(1./h4->GetEntries());
    h5->Sumw2();
    h5->Scale(1./h5->GetEntries());
    h6->Sumw2();
    h6->Scale(1./h6->GetEntries());
  }
  hs->Add(h1);
  hs->Add(h2);
  hs->Add(h3);
  hs->Add(h4);
  hs->Add(h5);
  hs->Add(h6);

  return hs;
}

// Set the general style options
void SetSgStyle(){
  // No Canvas Border
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasBorderSize(0);
  // White BG
  //  gStyle->SetCanvasColor(10);
  gStyle->SetCanvasColor(10);
  // Format for axes
  gStyle->SetLabelFont(22,"xyz");
  gStyle->SetLabelSize(0.06,"xyz");
  gStyle->SetLabelOffset(0.01,"xyz");
  gStyle->SetNdivisions(510,"xyz");
  gStyle->SetTitleFont(22,"xyz");
  gStyle->SetTitleColor(1,"xyz");
  gStyle->SetTitleSize(0.06,"xyz");
  gStyle->SetTitleOffset(0.91);
  gStyle->SetTitleYOffset(1.1);
  // No pad borders
  gStyle->SetPadBorderMode(0);
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
  gStyle->SetLegendFont(22);
  gStyle->SetFillStyle(0);
}

Double_t MassInROOT(TH1 *h,Char_t RootFileName[], Char_t TreeName[], Char_t VarName[],Double_t R0=1,Double_t R1=-1){
  Double_t xmin = h->GetXaxis()->GetXmin();
  Double_t xmax = h->GetXaxis()->GetXmax();
  
  TFile *fin = new TFile(RootFileName);
  TTree  *tree = (TTree*)fin->Get(TreeName);
  TLorentzVector *lvTmp = new TLorentzVector();
  tree->SetBranchAddress(VarName,&lvTmp);
  if(R0<R1){
    if(xmin<R0) xmin = R0;
    if(xmax>R1) xmax = R1;
  }
  Long_t nentries = tree->GetEntries();
  for (Long_t i=0; i<nentries;i++) {
    if(i % 10000 == 1) printf("%ld of %ld\n",i, nentries);
    tree->GetEntry(i);
    Double_t mass = lvTmp -> M();
    
    if(xmin <= mass && mass <xmax) h->Fill(mass);
  }
  
  fin->Close();
  printf("%.0f read from root: %s   Tree: %s   BrachName: %s\n",h->GetEntries(),RootFileName,TreeName,VarName);
  return h->GetEntries();
}

Double_t MassInROOT(TH1 *h,vector<Float_t> *vdata, Char_t RootFileName[], Char_t TreeName[], Char_t VarName[],Double_t R0=1,Double_t R1=-1){
  Double_t xmin = h->GetXaxis()->GetXmin();
  Double_t xmax = h->GetXaxis()->GetXmax();
  
  TFile *fin = new TFile(RootFileName);
  if(fin==NULL) {
    printf("%s open error\n",RootFileName);
    return -1;
  }
  TTree  *tree = (TTree*)fin->Get(TreeName);
  if(tree==NULL){
    printf("tree not find with name: %s \n",TreeName);
    return -1;
  }
  TLorentzVector *lvTmp = new TLorentzVector();
  tree->SetBranchAddress(VarName,&lvTmp);
  if(R0<R1){
    if(xmin<R0) xmin = R0;
    if(xmax>R1) xmax = R1;
  }

  Long_t nentries = tree->GetEntries();
  for (Long_t i=0; i<nentries;i++) {
    if(i % 10000 == 1) printf("%ld of %ld\n",i, nentries);
    tree->GetEntry(i);
    Double_t mass = lvTmp -> M();
    
    if(xmin <= mass && mass <xmax) {
      h->Fill(mass);
      vdata->push_back(mass);
    }
  }
  
  fin->Close();
  printf("%.0f read from root: %s   Tree: %s   BrachName: %s\n",h->GetEntries(),RootFileName,TreeName,VarName);
  return h->GetEntries();
}
Double_t E_InROOT(TH1 *h,vector<Float_t> *vdata, Char_t RootFileName[], Char_t TreeName[], Char_t VarName[],Double_t LowMass=1,Double_t HighMass=0,Double_t R0=1,Double_t R1=-1){
  Double_t xmin = h->GetXaxis()->GetXmin();
  Double_t xmax = h->GetXaxis()->GetXmax();
  
  TFile *fin = new TFile(RootFileName);
  TTree  *tree = (TTree*)fin->Get(TreeName);
  TLorentzVector *lvTmp = new TLorentzVector();
  tree->SetBranchAddress(VarName,&lvTmp);
  if(R0<R1){
    if(xmin<R0) xmin = R0;
    if(xmax>R1) xmax = R1;
  }

  Long_t nentries = tree->GetEntries();
  for (Long_t i=0; i<nentries;i++) {
    if(i % 10000 == 1) printf("%ld of %ld\n",i, nentries);
    tree->GetEntry(i);
    Double_t mass = lvTmp -> M();//for cut
    //cut of Jpsi mass==
    if(HighMass>LowMass){
      if(!(mass>LowMass && mass<HighMass)) continue;
    }

    Double_t d1 = lvTmp -> Energy();
     if(xmin <= d1 && d1<xmax) {
      h->Fill(d1);
      vdata->push_back(d1);
    }
  }
  
  fin->Close();
  printf("%.0f read from root: %s   Tree: %s \n",h->GetEntries(),RootFileName,TreeName);
  return h->GetEntries();
}


Double_t PxMassInROOT(TH1 *h,vector<Float_t> *vdata, Char_t RootFileName[], Char_t TreeName[], Char_t VarName[],Double_t LowMass=1,Double_t HighMass=0,Double_t R0=1,Double_t R1=-1){
  Double_t xmin = h->GetXaxis()->GetXmin();
  Double_t xmax = h->GetXaxis()->GetXmax();
  
  TFile *fin = new TFile(RootFileName);
  TTree  *tree = (TTree*)fin->Get(TreeName);
  TLorentzVector *lvTmp = new TLorentzVector();
  tree->SetBranchAddress(VarName,&lvTmp);
  if(R0<R1){
    if(xmin<R0) xmin = R0;
    if(xmax>R1) xmax = R1;
  }

  Long_t nentries = tree->GetEntries();
  for (Long_t i=0; i<nentries;i++) {
    if(i % 10000 == 1) printf("%ld of %ld\n",i, nentries);
    tree->GetEntry(i);
    Double_t mass = lvTmp -> M();//for cut
    Double_t d1 = lvTmp->Px();//only Change this
    //cut of Jpsi mass==
    if(HighMass>LowMass){
      if(!(mass>LowMass && mass<HighMass)) continue;
    }
    if(xmin <= d1 && d1<xmax) {
      h->Fill(d1);
      vdata->push_back(d1);
    }
  }
  
  fin->Close();
  printf("%.0f read from root: %s   Tree: %s   BrachName: %s\n",h->GetEntries(),RootFileName,TreeName,VarName);
  return h->GetEntries();
}

Double_t PyMassInROOT(TH1 *h,vector<Float_t> *vdata, Char_t RootFileName[], Char_t TreeName[], Char_t VarName[],Double_t LowMass=1,Double_t HighMass=0,Double_t R0=1,Double_t R1=-1){
  Double_t xmin = h->GetXaxis()->GetXmin();
  Double_t xmax = h->GetXaxis()->GetXmax();
  
  TFile *fin = new TFile(RootFileName);
  TTree  *tree = (TTree*)fin->Get(TreeName);
  TLorentzVector *lvTmp = new TLorentzVector();
  tree->SetBranchAddress(VarName,&lvTmp);
  if(R0<R1){
    if(xmin<R0) xmin = R0;
    if(xmax>R1) xmax = R1;
  }

  Long_t nentries = tree->GetEntries();
  for (Long_t i=0; i<nentries;i++) {
    if(i % 10000 == 1) printf("%ld of %ld\n",i, nentries);
    tree->GetEntry(i);
    Double_t mass = lvTmp -> M();//for cut
    Double_t d1 = lvTmp->Py();//only Change this
    //cut of Jpsi mass==
    if(HighMass>LowMass){
      if(!(mass>LowMass && mass<HighMass)) continue;
    }
    if(xmin <= d1 && d1<xmax) {
      h->Fill(d1);
      vdata->push_back(d1);
    }
  }
  
  fin->Close();
  printf("%.0f read from root: %s   Tree: %s   BrachName: %s\n",h->GetEntries(),RootFileName,TreeName,VarName);
  return h->GetEntries();
}

Double_t PzMassInROOT(TH1 *h,vector<Float_t> *vdata, Char_t RootFileName[], Char_t TreeName[], Char_t VarName[],Double_t LowMass=1,Double_t HighMass=0,Double_t R0=1,Double_t R1=-1){
  Double_t xmin = h->GetXaxis()->GetXmin();
  Double_t xmax = h->GetXaxis()->GetXmax();
  
  TFile *fin = new TFile(RootFileName);
  TTree  *tree = (TTree*)fin->Get(TreeName);
  TLorentzVector *lvTmp = new TLorentzVector();
  tree->SetBranchAddress(VarName,&lvTmp);
  if(R0<R1){
    if(xmin<R0) xmin = R0;
    if(xmax>R1) xmax = R1;
  }

  Long_t nentries = tree->GetEntries();
  for (Long_t i=0; i<nentries;i++) {
    if(i % 10000 == 1) printf("%ld of %ld\n",i, nentries);
    tree->GetEntry(i);
    Double_t mass = lvTmp -> M();//for cut
    Double_t d1 = lvTmp->Pz();//only Change this
    //cut of Jpsi mass==
    if(HighMass>LowMass){
      if(!(mass>LowMass && mass<HighMass)) continue;
    }
    if(xmin <= d1 && d1<xmax) {
      h->Fill(d1);
      vdata->push_back(d1);
    }
  }
  
  fin->Close();
  printf("%.0f read from root: %s   Tree: %s   BrachName: %s\n",h->GetEntries(),RootFileName,TreeName,VarName);
  return h->GetEntries();
}


Double_t E_MassInROOT(TH1 *h,vector<Float_t> *vdata, Char_t RootFileName[], Char_t TreeName[], Char_t VarName[],Double_t LowMass=1,Double_t HighMass=0,Double_t R0=1,Double_t R1=-1){
  Double_t xmin = h->GetXaxis()->GetXmin();
  Double_t xmax = h->GetXaxis()->GetXmax();
  
  TFile *fin = new TFile(RootFileName);
  TTree  *tree = (TTree*)fin->Get(TreeName);
  TLorentzVector *lvTmp = new TLorentzVector();
  tree->SetBranchAddress(VarName,&lvTmp);
  if(R0<R1){
    if(xmin<R0) xmin = R0;
    if(xmax>R1) xmax = R1;
  }

  Long_t nentries = tree->GetEntries();
  for (Long_t i=0; i<nentries;i++) {
    if(i % 10000 == 1) printf("%ld of %ld\n",i, nentries);
    tree->GetEntry(i);
    Double_t mass = lvTmp -> M();//for cut
    Double_t d1 = lvTmp->E();//only Change this
    //cut of Jpsi mass==
    if(HighMass>LowMass){
      if(!(mass>LowMass && mass<HighMass)) continue;
    }
    if(xmin <= d1 && d1<xmax) {
      h->Fill(d1);
      vdata->push_back(d1);
    }
  }
  
  fin->Close();
  printf("%.0f read from root: %s   Tree: %s   BrachName: %s\n",h->GetEntries(),RootFileName,TreeName,VarName);
  return h->GetEntries();
}

Double_t Chi2_PxPyPz(TLorentzVector *lvJpsi, TLorentzVector *cms,  TLorentzVector *cmsSigma){
  Double_t dPx = (lvJpsi->Px()-cms->Px())/cmsSigma->Px();//cmsSigma Px is the sigma of Px
  Double_t dPy = (lvJpsi->Py()-cms->Py())/cmsSigma->Py();//cmsSigma Py is the sigma of Py
  Double_t dPz = (lvJpsi->Pz()-cms->Pz())/cmsSigma->Pz();//cmsSigma Pz is the sigma of Pz
  return (dPx*dPx + dPy*dPy + dPz*dPz)/3;
}

Double_t Chi2_PxPyPzE(TLorentzVector *lvJpsi, TLorentzVector *cms,  TLorentzVector *cmsSigma){
  Double_t dPx = (lvJpsi->Px()-cms->Px())/cmsSigma->Px();//cmsSigma Px is the sigma of Px
  Double_t dPy = (lvJpsi->Py()-cms->Py())/cmsSigma->Py();//cmsSigma Py is the sigma of Py
  Double_t dPz = (lvJpsi->Pz()-cms->Pz())/cmsSigma->Pz();//cmsSigma Pz is the sigma of Pz
  Double_t dE = (lvJpsi->E()-cms->E())/cmsSigma->E();//cmsSigma Pz is the sigma of Pz
  return (dPx*dPx + dPy*dPy + dPz*dPz + dE*dE)/4;
}


void MakeTH1Style(TH1 *h,Int_t mStyle,Int_t icl,Double_t fsize=1){
  h->SetMarkerStyle(mStyle);
  h->SetMarkerColor(icl);
  h->SetMarkerSize(fsize);
  h->SetLineColor(icl);
}

void writeVect2TxtFile(vector<Float_t> *fromV, Char_t toFile[]){
  FILE *pf09 = fopen(toFile,"wt");
  Int_t n09 = fromV->size();
  for(Int_t i=0; i<n09; i++){
    fprintf(pf09,"%f\n",(*fromV)[i]);
  }
  fclose(pf09);

}
Int_t readTxt2Vect(Char_t filename[],vector <Double_t> *v){
  FILE *pf = fopen(filename,"rt");
  Int_t n=1;
  Double_t d;
  while(n==1){
    n = fscanf(pf,"%lf\n",&d);
    if(n==1){
      v->push_back(d);
    }
  }
  fclose(pf);
  printf("%ld data read from %s\n",(Long_t) v->size(),filename);
  return v->size();
}



Int_t readTxt2Vect(Char_t filename[],vector <Double_t> *v,vector <Double_t> *vY){
  FILE *pf = fopen(filename,"rt");
  Int_t n=2;
  Double_t d,dY;
  while(n==2){
    n = fscanf(pf,"%lf %lf\n",&d,&dY);
    if(n==2){
      v->push_back(d);
      vY->push_back(dY);
    }
  }
  fclose(pf);
  printf("%ld data read from %s\n",v->size(),filename);
  return v->size();
}


void ReadDouble2TH1(TH1 *h,vector<Float_t> *toV,Char_t FileName[], Char_t TreeName[], Char_t BranchName[]){
  TFile f(FileName);
  TTree *pTreeName = (TTree *)f.Get(TreeName);
  Double_t dBran;
  pTreeName -> SetBranchAddress(BranchName,&dBran);
  Long64_t nentries = pTreeName->GetEntries();
/*   if(debug){ */
/*     nentries /=10;  */
/*   } */
  Long64_t nbytes = 0;
  Double_t xmin = h->GetXaxis()->GetXmin();
  Double_t xmax = h->GetXaxis()->GetXmax();
  printf("read %s from tree %s in %s with Entries=%lld\n",BranchName,TreeName,FileName,nentries);
  Double_t nBefore = h->GetEntries();
  Long64_t Step = nentries/10;
  for (Long64_t i=0; i<nentries;i++) {
    nbytes += pTreeName->GetEntry(i);
    if(i % Step == 1) printf("%lld of %lld in %s\n",i,nentries,FileName);
    if(xmin<= dBran && dBran<xmax){
      h->Fill(dBran);
      toV->push_back(dBran);
    }
  }
  Double_t nAfter = h->GetEntries();
  printf("in ReadDouble2TH1: Finish Read in Hist %s with Entries from %.0f to %.0f\n",h->GetName(),nBefore,nAfter);
  f.Close();
  return;
}

void ReadDouble2TH1(TH1 *h,Char_t FileName[], Char_t TreeName[], Char_t BranchName[]){
  TFile f(FileName);
  TTree *pTreeName = (TTree *)f.Get(TreeName);
  Double_t dBran;
  pTreeName -> SetBranchAddress(BranchName,&dBran);
  Long64_t nentries = pTreeName->GetEntries();
/*   if(debug){ */
/*     nentries /=10;  */
/*   } */
  Long64_t nbytes = 0;
  Double_t xmin = h->GetXaxis()->GetXmin();
  Double_t xmax = h->GetXaxis()->GetXmax();
  printf("read %s from tree %s in %s with Entries=%lld\n",BranchName,TreeName,FileName,nentries);
  Double_t nBefore = h->GetEntries();
  Long64_t Step = nentries/10;
  for (Long64_t i=0; i<nentries;i++) {
    nbytes += pTreeName->GetEntry(i);
    if(i % Step == 1) printf("%lld of %lld in %s\n",i,nentries,FileName);
    if(xmin<= dBran && dBran<xmax){
      h->Fill(dBran);
    }
  }
  Double_t nAfter = h->GetEntries();
  printf("in ReadDouble2TH1: Finish Read in Hist %s with Entries from %.0f to %.0f\n",h->GetName(),nBefore,nAfter);
  f.Close();
  return;
}

Double_t PercentInLeft(Double_t Thre, TH1 *h){
  Double_t tot = 0;
  Double_t less = 0;
  Int_t nBin = h->GetNbinsX();
  for(Int_t i=0; i<nBin; i++){
    Double_t d = h->GetBinContent(i+1);
    Double_t x = h->GetBinCenter(i+1);
    tot += d;
    if(x<Thre) less +=d;
  }
  if(tot==0) return 0;
  else return less/tot; 
}

void findTF1MaxDist(TF1 *f1, TF1 *f2,Double_t InRange[],Double_t x0YUpYDn[]){
  Int_t n=1000;

  //first try
  Double_t step0 = (InRange[1] - InRange[0])/n;
  Double_t x = InRange[0];
  Double_t dist0 = 0;
  Double_t xMax = x;
  while(x<InRange[1]){
    x = x+step0;
    Double_t d1 = f1->Eval(x);
    Double_t d2 = f2->Eval(x);
    Double_t dist = TMath::Abs(d1 -d2);
    if(dist>dist0){
      dist0 = dist;
      xMax = x;
    }
  }

  //second try
  Double_t step1 = step0/n; 
  Double_t left = xMax - step0 - 2*step1;
  Double_t right = xMax + step0 + 2*step1;
  x = left;
  while(x<right){
    x = x+step1;
    Double_t d1 = f1->Eval(x);
    Double_t d2 = f2->Eval(x);
    Double_t dist = TMath::Abs(d1 -d2);
    if(dist>dist0){
      dist0 = dist;
      xMax = x;
    }
  }

  x0YUpYDn[0] = xMax;
  x0YUpYDn[1] = f1->Eval(xMax);
  x0YUpYDn[2] = f2->Eval(xMax);
  if(x0YUpYDn[1]<x0YUpYDn[2]){
    x0YUpYDn[2] = f1->Eval(xMax);
    x0YUpYDn[1] = f2->Eval(xMax);
  }
}

void FillCutG(TCutG *cutg,vector<Double_t> x,vector<Double_t> y){
  cutg->Clear();
  Int_t iSize = (Int_t)x.size();
  for(Int_t i=0; i<iSize; i++){
    cutg->SetPoint(i,x[i],y[i]);
    printf("cutG: %d %f %f\n",i,x[i],y[i]);
  }
  return;
}

void WriteVectToDataSet(vector <Double_t> *v,RooRealVar x,RooDataSet *data, Bool_t rangeLim=kTRUE){
  Double_t xmin = x.getMin();
  Double_t xmax = x.getMax();
  Int_t n = v->size();
  Double_t tmp;
  for(Int_t i=0; i<n; i++){
    tmp = (*v)[i];
    x = tmp;
    if(rangeLim){
      if(tmp>=xmin && tmp<xmax)data->add(x);
    }else{
      data->add(x);
    }
  }
} 

void vect2TH1(vector<Double_t> *v,TH1 *h){
  Double_t xmin = h->GetXaxis()->GetXmin();
  Double_t xmax = h->GetXaxis()->GetXmax();
  Int_t n = v->size();
  for(Int_t i=0; i<n; i++){
    if( (*v)[i]>=xmin && (*v)[i]<xmax){
      h->Fill((*v)[i]);
    }
  }
}

void SortArray(Int_t num,Double_t *array_original,Double_t *array_sorted,Bool_t down=kTRUE){
  Int_t *index=new Int_t[num];
  Int_t num64 = num;
  TMath::Sort(num64,array_original,index,down);
  for(Int_t i=0;i<num;i++){
    array_sorted[i]=array_original[ index[i] ];
    // printf("%f\n",array_sorted[i]);
  }

  delete[] index;
  return ;
}
void SortArray(Int_t num,Int_t *array_original,Int_t *array_sorted,Bool_t down=kTRUE){
  Int_t *index=new Int_t[num];
  Int_t num64 = num;
  TMath::Sort(num64,array_original,index,down);
  for(Int_t i=0;i<num;i++){
    array_sorted[i]=array_original[ index[i] ];
    // printf("%f\n",array_sorted[i]);
  }

  delete[] index;
  return ;
}

//_________________________________________________________
//sort array_original to array_sorted WHILE 
//copy array_original2 to array_sorted2 acorrding to the order 
void SortArray(Int_t num,Double_t *array_original,Double_t *array_original2,Double_t *array_sorted,Double_t *array_sorted2,Bool_t down=kTRUE){
  Int_t *index=new Int_t[num];
  Int_t num64 = num;
  TMath::Sort(num64,array_original,index,down);
  for(Int_t i=0;i<num;i++){
    array_sorted[i]=array_original[ index[i] ];
    array_sorted2[i]=array_original2[ index[i] ];
    // printf("%f\n",array_sorted[i]);
  }

  delete[] index;
  return ;
}

//_________________________________________________________
//sort array_original to array_sorted WHILE 
//copy array_original2 to array_sorted2 acorrding to the order 
void SortArray(Int_t num,Float_t *array_original,Int_t *array_original2,Float_t *array_sorted,Int_t *array_sorted2,Bool_t down=kTRUE){
  Int_t *index=new Int_t[num];
  Int_t num64 = num;
  TMath::Sort(num64,array_original,index,down);
  for(Int_t i=0;i<num;i++){
    array_sorted[i]=array_original[ index[i] ];
    array_sorted2[i]=array_original2[ index[i] ];
    // printf("%f\n",array_sorted[i]);
  }

  delete[] index;
  return ;
}

void SortArray(Int_t num,Int_t *array_original,Int_t *array_original2,Int_t *array_sorted,Int_t *array_sorted2,Bool_t down=kTRUE){
  Int_t *index=new Int_t[num];
  Int_t num64 = num;
  TMath::Sort(num64,array_original,index,down);
  for(Int_t i=0;i<num;i++){
    array_sorted[i]=array_original[ index[i] ];
    array_sorted2[i]=array_original2[ index[i] ];
    // printf("%f\n",array_sorted[i]);
  }

  delete[] index;
  return ;
}

void SortArray(Int_t num,Int_t *array_original,Double_t *array_original2,Int_t *array_sorted,Double_t *array_sorted2,Bool_t down=kTRUE, Bool_t bSort2nd=kFALSE){
  Int_t *index=new Int_t[num];
  Int_t num64 = num;
  Int_t *itmp=new Int_t[num];
  Double_t *ftmp = new Double_t[num];
  Double_t *ftmp1 = new Double_t[num];

  TMath::Sort(num64, array_original,index,down);
  for(Int_t i=0;i<num;i++){
    array_sorted[i]=array_original[ index[i] ];
    array_sorted2[i]=array_original2[ index[i] ];
    // printf("%f\n",array_sorted[i]);
  }

  //sort array_sorted2 within same array_sorted[i]
  if(bSort2nd){
    Int_t isame=0;
    Int_t istart =0;
    Bool_t notYetP = kTRUE;//whether sortted
    for(Int_t i=0;i<num;i++){
      if(isame==0){
	itmp[isame]=array_sorted[i];
	ftmp[isame] = array_sorted2[i];
	istart = i;
	notYetP = kTRUE;
	isame++;
      }else{
	if(itmp[isame-1]==array_sorted[i]){//next still same
	  itmp[isame]=array_sorted[i];
	  ftmp[isame] = array_sorted2[i];
	  isame++;
	}else{//next not same
	  if(notYetP){
	    SortArray(isame,ftmp,ftmp1,kFALSE);
	    for(Int_t j=0;j<isame;j++){
	      array_sorted2[istart+j] = ftmp1[j];
	    }
	    notYetP = kFALSE;
	  }

	  isame = 0;
	  istart = i;
	  itmp[isame]=array_sorted[i];
	  ftmp[isame] = array_sorted2[i];
	  notYetP = kTRUE;
	  isame++;
	}
      }
    }//for

    //for last one
    if(notYetP){
      SortArray(isame,ftmp,ftmp1,kFALSE);
      for(Int_t j=0;j<isame;j++){
	array_sorted2[istart+j] = ftmp1[j];
      }
      notYetP = kFALSE;
    }


  }
  delete[] index;
  delete[] itmp;
  delete[] ftmp;
  return ;
}



Int_t  rmSameVal(Int_t nOrg,Double_t nOrgA[],Double_t nNewA[]){
  Int_t n;
  if(nOrg<1) return nOrg;
  nNewA[0] = nOrgA[0];
  n=1;
  for(Int_t i=1; i<nOrg; i++){
    if(nNewA[n-1] ==  nOrgA[i]) continue;
    nNewA[n] = nOrgA[i];
    n++;
  }
  return n;
}

Int_t  rmSameVal(Int_t nOrg,Int_t nOrgA[],Int_t nNewA[]){
  Int_t n;
  if(nOrg<1) return nOrg;
  nNewA[0] = nOrgA[0];
  n=1;
  for(Int_t i=1; i<nOrg; i++){
    if(nNewA[n-1] ==  nOrgA[i]) continue;
    nNewA[n] = nOrgA[i];
    n++;
  }
  return n;
}


Double_t DCA(TVector3 r1, TVector3 s01, TVector3 r2, TVector3 s02, TVector3 *xpos){
  //xpos is the cross position
  //r1 is the decay point of Ks
  //r2 is the proton cross with beam point
  //s01 ans s02 alone the momentum direction of Ks and Proton
  //return Distance of the two line

  TVector3  s1 = s01.Unit();//Ks
  TVector3  s2 =  s02.Unit();//as Proton
  //to judge paralla or not
  TVector3 r12 = r1-r2;
  if(s1.X() == s2.X() && s1.Y() == s2.Y() && s1.Z() == s2.Z()){
    *xpos = r2 + r12*0.5;
    Double_t angle = r12.Angle(s2);
    return r12.Mag()*TMath::Sin(angle);
  }
  //not paralla of the s1 !//  s2

  //ouble_t r12Ds1 = r12.Dot(s1);
  Double_t s1Ds2 = s1.Dot(s2);

  Double_t t1 = r12.Dot(s1)/(1.0-s1Ds2*s1Ds2);
  Double_t t2 = r12.Dot(s2) /(1.0-s1Ds2*s1Ds2);

  TVector3 pos1 = r1 + t1*s1;
  TVector3 pos2 = r2 + t2*s2;
  *xpos = pos1 + (pos2-pos1)*0.5;
  return (pos1 - pos2).Mag();
}



void CopyMkLnStyle(TH1 *horg, TH1 *hStyle){
  horg->SetMarkerStyle(hStyle->GetMarkerStyle());
  horg->SetMarkerColor(hStyle->GetMarkerColor());
  horg->SetMarkerSize(hStyle->GetMarkerSize());
  horg->SetLineColor(hStyle->GetLineColor());
  horg->SetLineStyle(hStyle->GetLineStyle());
  //  horg->SetLineWidth(hStyle->SetLineWidth());

}

Double_t readTxt2TH1(Char_t filename[],TH1 *v,Bool_t clearH=kTRUE){
  if(clearH) v->Clear();
  FILE *pf = fopen(filename,"rt");
  Int_t n=1;
  Double_t d;
  while(n==1){
    n = fscanf(pf,"%lf\n",&d);
    if(n==1){
      FillTH1F(d,v);
    }
  }
  fclose(pf);
  printf("%ld data read from %s\n",(Long_t) v->GetEntries(),filename);
  return v->GetEntries();
}


Double_t CalPT(TLorentzVector lvDau, TLorentzVector lvMother){
  Double_t sinAng = TMath::Sin(angleOfTwoLV(lvDau,lvMother));
  return sinAng*lvDau.P();
}

void ShowContent(TH1 *h, Int_t itxtColor=kRed, Double_t txtSize=0.07, Double_t fangle=45,Bool_t NoZeroBin=kTRUE){
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
  

 void readTxt2Int3Float(Char_t fileName[],Int_t arrID[],Float_t arrX[],Float_t arrY[],Float_t arrZ[]){
  FILE *pf = fopen(fileName,"rt");
  if(pf==NULL){
    printf("%s Open Error\n",fileName);
    return;
  }
  Int_t I;
  Float_t F1,F2,F3;
  Int_t n=4;
  Int_t nn=0;
  while(n==4){
    n = fscanf(pf,"%d %f %f %f\n",&I,&F1,&F2,&F3);
    if(n==4){
      arrID[I] = I;
      arrX[I] = F1;
      arrY[I] = F2;
      arrZ[I] = F3;
      nn++;
    }
  }
  printf("%d read from %s\n",nn,fileName);
}

void SetEntries(TH1 *h){
  Int_t nBin = h->GetNbinsX();
  printf("nBin=%d\n",nBin);
  Double_t tot=0;
  for(Int_t i=0; i<nBin; i++){
    tot = tot + h->GetBinContent(i+1);
  }
  Double_t oldN = h->GetEntries();
  h->SetEntries(tot);
  printf("TH1 %s has been set entries from %.0f to %.0f\n",h->GetName(),oldN,h->GetEntries());
}


void ShowContent(TGraph *gr, Int_t itxtColor=kRed, Double_t txtSize=0.07, Double_t fangle=45,Bool_t NoZeroBin=kTRUE){
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
  

const char *PDG2Name(Int_t PDG){
  TParticle part;
  part.SetPdgCode(PDG);
  return part.GetName();
}

//_____________________________________________
//Read roots in dirName to TChain with treeName
//
TChain *ReadROOTFiles(Char_t dirName[],Char_t treeName[]){
  TChain *chain = new TChain(treeName);
  Char_t fileName[1000];
  Int_t n = 1;
  FILE *pf = fopen(dirName,"rt");
  if(pf==NULL) {
    printf("%s Open Error\n",dirName);
    return NULL;
  }
  Int_t itotal = 0;
  while(n==1){
    n = fscanf(pf,"%s\n",fileName);
    if(n==1){
      chain->Add(fileName);
      printf("%s Added No.%d\n",fileName,itotal);
      itotal++;
    }
  }
  return chain;
}

Int_t getNumDigsFromErr(Double_t num){
  Double_t thr = 4.9999;
  for(Int_t i=0; i<25; i++){
    if(num >= thr) {
      return i;
    }
    else thr *= 0.1;  
  }
  return -1;
}

Char_t *OutVal(Double_t Val,Double_t Err,Double_t factor=1){
  Val= Val*factor;
  Err=Err*factor;
  Int_t ndig = getNumDigsFromErr(Err);

  Char_t sFormat[100];
  sprintf(sFormat,"%%.%df#pm%%.%df",ndig,ndig);
  
  Char_t *VVerr= new Char_t[100];
  sprintf(VVerr,sFormat,Val,Err);
  return VVerr;
}

std::vector<Int_t> RandomReadNint(Char_t rootName[],Char_t treeName[], Char_t branchName[],Int_t ReadN=10){
  TFile pf(rootName,"READ");
  TTree *t = (TTree *)pf.Get(treeName);
  Int_t item;
  t->SetBranchAddress(branchName,&item);
  Int_t nentries = t->GetEntries();
  printf("%d entries in %s with treeName %s and BranchName %s to read %d Entries\n",nentries,rootName,treeName,branchName,ReadN);
  std::vector<Int_t> vrlt;

  //to prepare the idx array
  Int_t *idxArray = new Int_t[ReadN];
  Int_t *idxArray1 = new Int_t[ReadN];

  for(Int_t i=0; i<ReadN; i++){
    Int_t idx = TMath::Nint(gRandom->Rndm()*nentries);
    while(idx>=nentries)  idx = idx - nentries;
    idxArray[i] = idx;
  }

  //sort the index
  Bool_t down= kFALSE;
  SortArray(ReadN,idxArray,idxArray1,down);
  for(Int_t i=0; i<ReadN; i++){
    t->GetEntry(idxArray1[i]);
    vrlt.push_back(item);
  }
  return vrlt;
}


void txtR(Double_t x0, Double_t y0,TH1 *h,Char_t const sName[]="RMS/M=%s",Double_t sizeTxt=0.06){
  h->SetStats(kFALSE);
  TLatex *ltx = new TLatex();
  ltx->SetNDC(kTRUE);
  ltx->SetTextColor(h->GetLineColor());
  ltx -> SetTextFont(22);
  ltx->SetTextSize(sizeTxt);

  Double_t M = h->GetMean();
  Double_t MErr = h->GetMeanError();

  Double_t RMS = h->GetRMS();
  Double_t RMSErr = h->GetRMSError();

  Double_t R = RMS/M;
  Double_t RErr = R*TMath::Sqrt( TMath::Power(MErr/M,2)+ TMath::Power(RMSErr/RMS,2));
  ltx->DrawLatex(x0,y0,Form(sName,OutVal(R,RErr)));
  gPad->Modified();
  gPad->Update();
}

void txtMErr(Double_t x0, Double_t y0,TH1 *h,Char_t const sFormat[]="Mean=%s",Double_t fsize = 0.06){
  h->SetStats(kFALSE);
  TLatex *ltx = new TLatex();
  ltx->SetNDC(kTRUE);
  ltx->SetTextColor(h->GetLineColor());
  ltx -> SetTextFont(22);
  ltx->SetTextSize(fsize);
  ltx->DrawLatex(x0,y0,Form(sFormat,OutVal(h->GetMean(),h->GetMeanError())));
  gPad->Modified();
  gPad->Update();
}

void txtRMSErr(Double_t x0, Double_t y0,TH1 *h,Char_t const sFormat[]="RMS=%s",Double_t fsize = 0.06){
  h->SetStats(kFALSE);
  TLatex *ltx = new TLatex();
  ltx->SetNDC(kTRUE);
  ltx->SetTextColor(h->GetLineColor());
  ltx -> SetTextFont(22);
  ltx->SetTextSize(fsize);
  ltx->DrawLatex(x0,y0,Form(sFormat,OutVal(h->GetRMS(),h->GetRMSError())));
  gPad->Modified();
  gPad->Update();
}

#endif 
