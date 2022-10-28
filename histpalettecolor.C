/*
 * @Description: 
 * @version: 
 * @Author: Hubery-Lee
 * @E-mail: hrbeulh@126.com
 * @Date: 2022-10-28 20:25:44
 * @LastEditTime: 2022-10-28 20:29:38
 * @LastEditors: Hubery-Lee
 */

void histpalettecolor()
{
   auto C = new TCanvas();

   gStyle->SetOptTitle(kFALSE);
   gStyle->SetOptStat(0);

   auto h1 = new TH1F ("h1","Histogram drawn with full circles",100,-4,4);
   auto h2 = new TH1F ("h2","Histogram drawn with full squares",100,-4,4);
   auto h3 = new TH1F ("h3","Histogram drawn with full triangles up",100,-4,4);
   auto h4 = new TH1F ("h4","Histogram drawn with full triangles down",100,-4,4);
   auto h5 = new TH1F ("h5","Histogram drawn with empty circles",100,-4,4);

   TRandom3 rng;
   Double_t px,py;
   for (Int_t i = 0; i < 25000; i++) {
      rng.Rannor(px,py);
      h1->Fill(px,10.);
      h2->Fill(px, 8.);
      h3->Fill(px, 6.);
      h4->Fill(px, 4.);
      h5->Fill(px, 2.);
   }

   h1->SetMarkerStyle(kFullCircle);
   h2->SetMarkerStyle(kFullSquare);
   h3->SetMarkerStyle(kFullTriangleUp);
   h4->SetMarkerStyle(kFullTriangleDown);
   h5->SetMarkerStyle(kOpenCircle);

   h1->Draw("PLC PMC");  //`PFC` (Palette Fill Color), `PLC` (Palette Line Color) and `PMC` (Palette Marker Color).
   h2->Draw("SAME PLC PMC"); 
   h3->Draw("SAME PLC PMC");
   h4->Draw("SAME PLC PMC");
   h5->Draw("SAME PLC PMC");

   gPad->BuildLegend();
}
