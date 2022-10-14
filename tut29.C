/*
 * @Description:
 * @version:
 * @Author: Hubery-Lee
 * @E-mail: hrbeulh@126.com
 * @Date: 2022-10-13 20:48:56
 * @LastEditTime: 2022-10-14 17:20:45
 * @LastEditors: Hubery-Lee
 */
// https://root.cern.ch/doc/master/classTGraph2D.html#G2D021
{

    TCanvas *c1 = new TCanvas("","",1200,800);
    gStyle->SetPalette(kRainBow); //Palette Style 

    TH2F *hist = new TH2F("hist", "Histogram", 100, -1, 1,
                          100, -1, 1);

    hist->SetStats(0);
    TRandom *rand = new TRandom(10);

    for (int i = 0; i < 1e7; i++)

    {
        double x = rand->Gaus();
        double y = rand->Gaus();
        hist->Fill(x, y);
    }

    	
    hist->GetXaxis()->SetTitle("x [cm]");
    hist->GetYaxis()->SetTitle("y [cm]");
    hist->GetZaxis()->SetTitle("Entries");
	
    // hist->Smooth();  //使得图片区域变光滑
    hist->SetContour(1000); //使得palette 变smooth

    hist->Draw("colz"); //colz surf3 cont1 lego2

    c1->Print("colz.png");
}