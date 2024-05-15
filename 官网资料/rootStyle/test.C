#include "MYSTYLE_LEE.h"

void test(){
    // prepareCanvas("c1",1200,800);
    // TH1F* h1 =new TH1F("this a test","",100,0,1);
    // TH1F* h2 =new TH1F("this a test","",100,0,1);
    // TH1F* h3 =new TH1F("this a test","",100,0,1);
    // TH2F* h4 =new TH2F("this a test","",100,0,1,100,0,1);
    // TRandom3 r;

    // for(int i =0;i<1000;i++) 
    //   {
    //     h1->Fill(r.Gaus(0.5, 0.05));
	  //     h2->Fill(r.Gaus(0.5, 0.05));
    //     h3->Fill(r.Gaus(0.5, 0.05));
    //     h4->Fill(r.Gaus(0.5, 0.05),r.Gaus(0.5, 0.05));
    //   }

    // draw3H(h1,h2,h4);
    // ShowContent(h1);

    // TGraph *gr2 = new TGraph("./Point1-6-2.txt", "%lg%lg");
    // //TGraph *gr3 = new TGraph("./Point1-8-4.txt", "%lg%lg");

    // gr2->GetXaxis()->SetTitle(" #theta vol");
    // gr2->GetYaxis()->SetTitle("N/N0");

    // // prepareCanvas("c2");
    // gr2->Draw();
    // ShowContent(gr2);
    //LoadPandaStyle();
    //DrawNice2DHisto(h4,"contz");
    
    // h4->Draw("colz");
    // h4->Draw();
    // LineX(0.2,kBlue,"c1");
    // LineX1(0.5,kRed,2);
    // DrawText(0.5,0.5,"my=x_{0} ^{2}");
    
    //prepareCanvasZoom1();
    //h2->Draw();

    prepareCanvas("c2");
    TH1D *h1 = Create1DDHistogram("loghist","Log Histogram",200,1,1e6,"log");
    TRandom3 r;
    for(int i=0;i<10000;i++)h1->Fill(r.Gaus(1e3,1e3));
    h1->Draw();

}
